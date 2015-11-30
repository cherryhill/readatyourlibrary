<?php


/**
 * @file flexicolor.admin.inc
 * Contains the various interfaces where a site administrator can make changes
 * to the way the flexicolor module functions for the website.
 */


function flexicolor_site_settings($form, &$form_state) {
  $form = array();
  
  if (user_access('administer flexicolor settings')) {
    $form['intro'] = array(
      '#type' => 'item',
      '#value' => t('You may use the tabs manage the selectors and presets that are available.')
    );
  }
  
  $form['flexicolor'] = array(
    '#type' => 'fieldset',
    '#title' => 'Flexible Colors',
    '#description' => t('Flexible Colours allow you to change the look/feel of certain areas of your site.'),
    '#collapsible' => TRUE,
    '#attributes' => array('id' => 'flexicolor-fieldset'),
  );
  
  $options = array(
    '' => t('CUSTOM'),
  );
  
  $presets = flexicolor_get_presets();
  foreach ($presets as $key => $preset) {
    $options[$key] = check_plain($preset->display_name);
  }
  
  $default_preset = variable_get('flexicolor-selected-preset', '');
  $form['flexicolor']['flexicolor-selected-preset'] = array(
    '#type' => 'select',
    '#title' => t('Presets'),
    '#description' => t('Preset configurations that have been created for the available selectors'),
    '#options' => $options,
    '#default_value' => $default_preset,
  );
  
  $selectors = flexicolor_get_selectors();
  foreach ($selectors as $key => $selector) {
    $default_color_value = variable_get("flexicolor-$key", '');
    if (empty($default_color_value)) {
      $check = FALSE;
      if ($default_preset) {
        $possible_color = flexicolor_get_preset_selector(str_replace('preset-', '', $default_preset), $selector->fsid);
        if ($possible_color) {
          $default_color_value = $possible_color->color;
          $check = TRUE;
        }
      }
      if (!$check) {
        $default_color_value = $selector->default_color;
      }
    }
    
    $form['flexicolor']["flexicolor-$key"] = array(
      '#type' => 'textfield',
      '#title' => check_plain($selector->display_name),
      '#description' => '<ul><li>Selectors affected: '. check_plain($selector->selector)
        .'</li><li>Color area: '. check_plain($selector->type == 'color' ? 'text' : $selector->type) .'</li></ul>',
      '#maxlength' => 7,
      '#size' => 7,
      '#default_value' => $default_color_value
    );
  }
  
  $preset_selectors = array();
  foreach ($presets as $preset_key => $preset) {
    $preset_selectors[$preset_key] = array();
    foreach ($selectors as $selector_key => $selector) {
      $preset_selectors[$preset_key][$selector_key] = $selector->default_color;
      $possible_color = flexicolor_get_preset_selector($preset->fpid, $selector->fsid);
      if ($possible_color->color) {
        $preset_selectors[$preset_key][$selector_key] = $possible_color->color;
      }
    }
  }
  
  drupal_add_js(array('flexicolor_preset_selectors' => $preset_selectors), 'setting');
  
  $form['flexicolor']['color-picker'] = array(
    '#markup' => '<div id="flexicolor-color-picker"></div>'
  );

  $form['#submit'][] = 'flexicolor_site_settings_submit';

  return system_settings_form($form);
}

function flexicolor_site_settings_submit($form, &$form_state) {
  ctools_include('css');

  $values = $form_state['values'];
  $css = '';
  $selectors = flexicolor_get_selectors();
  $preset = str_replace('preset-',  '', $values['flexicolor-selected-preset']);
  
  // We have now loaded all the default values. Time to start populating it
  // with values selected by the user.
  foreach ($selectors as $key => $selector) {
    if (!empty($values['flexicolor-'. $key])) {
      $selectors[$key]->default_color = $values['flexicolor-'. $key];
    }
    elseif (!empty($preset)) {
      $temp_color = flexicolor_get_preset_selector($preset, $selector->fsid);
      if ($temp_color) {
        $selectors[$key]->default_color = $temp_color->color;
      }
    }
    // add to the css
    $css .= "/* ". check_plain($selector->display_name) ." */\n{$selector->selector} {\n  {$selector->type}: {$selector->default_color};\n}\n\n";
  }
  ctools_css_store('flexicolor-css', $css);
}

function flexicolor_manage_page() {
  $content = '';
  $content .= '<fieldset><legend>'. t('Selectors') .'</legend>';
  // List the selector rules
  $selector_table_header = array(t('Selector Name'), t('Selector'), t('type'), t('Default Color'), t('Actions'));
  $selector_table = array();
  $selectors = flexicolor_get_selectors();
  foreach ($selectors as $selector) {
    $selector_table[] = array(
      check_plain($selector->display_name),
      $selector->selector,
      $selector->type,
      check_plain($selector->default_color),
      l(t('edit'), 'admin/appearance/flexicolor/update/selector/'. $selector->fsid) .' / '.
      l(t('delete'), 'admin/appearance/flexicolor/delete/selector/'. $selector->fsid),
    );
  }
  $content .= theme('table', array('header' => $selector_table_header, 'rows' => $selector_table));
  $content .= '</fieldset>';
  
  // List the presets
  $content .= '<fieldset><legend>'. t('Presets') .'</legend>';
  $preset_table_header = array(t('Preset Name'), t('Actions'));
  $preset_table = array();
  $presets = flexicolor_get_presets();
  foreach ($presets as $preset) {
    $preset_table[] = array(
      check_plain($preset->display_name),
      l(t('edit'), 'admin/appearance/flexicolor/update/preset/'. $preset->fpid) .' / '.
      l(t('delete'), 'admin/appearance/flexicolor/delete/preset/'. $preset->fpid),
    );
  }
  $content .= theme('table', array('header' => $preset_table_header, 'rows' => $preset_table));
  $content .= '</fieldset>';
  return $content;
}

function flexicolor_admin_update_selector($form, &$form_state, $fsid = NULL) {
  $form = array();
  
  $default_color = '#000000';
  $default_type = 'background';
  $default_display_name = $default_selector = '';
  if ($fsid !== NULL) {
    $selector = flexicolor_get_selectors($fsid);
    if (count($selector) == 1) {
      $form['fsid'] = array(
        '#type' => 'value',
        '#value' => $fsid,
      );
      $selector = array_pop($selector);
      $default_display_name = $selector->display_name;
      $default_selector = $selector->selector;
      $default_color = $selector->default_color;
      $default_type = $selector->type;
    }
  }
  
  $form['display_name'] = array(
    '#type' => 'textfield',
    '#title' => t('Display Name'),
    '#description' => t('The name a site administrator will see to give content to the selector rule'),
    '#size' => 64,
    '#maxlength' => 128,
    '#required' => TRUE,
    '#default_value' => $default_display_name,
  );
  
  $form['selector'] = array(
    '#type' => 'textarea',
    '#title' => t('Selector(s)'),
    '#description' => t('The selectors this setting will apply to.  You may use commas to specify different rules along with : for meta selectors. Refrain from using other selectors.'),
    '#required' => TRUE,
    '#default_value' => $default_selector,
  );
  
  $options = _flexicolor_get_types();
  
  $form['type'] = array(
    '#type' => 'radios',
    '#title' => t('Type of color rule'),
    '#options' => $options,
    '#default_value' => $default_type,
    '#required' => TRUE,
  );

  $form['color'] = array(
    '#type' => 'textfield',
    '#title' => t('Color'),
    '#description' => t('The name a site administrator will see to give content to the selector rule'),
    '#size' => 7,
    '#maxlength' => 7,
    '#required' => TRUE,
    '#default_value' => $default_color,
  );
  
  $form['color-picker'] = array(
    '#markup' => '<div id="flexicolor-color-picker"></div>',
  );
  
  $form['#redirect'] = 'admin/appearance/flexicolor';
  
  return confirm_form($form, t('Save Selector'), 'admin/appearance/flexicolor', '', t('Save'), t('Cancel'));
}

function flexicolor_admin_update_selector_validate($form, &$form_state) {
  $values = $form_state['values'];
  if (!array_key_exists($values['type'], _flexicolor_get_types())) {
    form_set_error('type', 'Defined typed is not one of the selectable options');
  }
}

function flexicolor_admin_update_selector_submit($form, &$form_state) {
  // Filter CSS using CTools
  ctools_include('css');
  $values = $form_state['values'];

  $css = $values['selector'] .'{'. $values['type'] .':'. $values['color'] .';}';
  $filtered_css = ctools_css_filter_css_data(ctools_css_disassemble($css));
  
  $selectors = array();
  foreach($filtered_css as $key => $value) {
    $selectors[] = $key;
  }
  $selectors = implode(', ', $selectors);

  $selector = array(
    'display_name' => $values['display_name'],
    'selector' => $selectors,
    'type' => $values['type'],
    'default_color' => $values['color']
  );
  if (isset($values['fsid'])) {
    $selector['fsid'] = $values['fsid'];
  }
  flexicolor_save_selector($selector);
  drupal_set_message('Flexicolor has now been saved.  Please note that it has been filtered and cleaned for any possible issues.');
}

function flexicolor_admin_delete_selector($form, &$form_state, $fsid) {
  $form = array();
  $form['fsid'] = array(
    '#type' => 'value',
    '#value' => $fsid,
  );
  $form['#redirect'] = 'admin/appearance/flexicolor';
  return confirm_form($form, 'Are you sure you wish to delete the selector', 'admin/appearance/flexicolor');
}

function flexicolor_admin_delete_selector_submit($form, &$form_state) {
  $values = $form_state['values'];
  flexicolor_delete_selector($values['fsid']);
  drupal_set_message(t('Selector has now been deleted'));
}

function flexicolor_admin_update_preset($form, &$form_state, $fpid = NULL) {
  $form = array();
  
  $default_name = '';
  $selectors = flexicolor_get_selectors();
  if ($fpid !== NULL) {
    $preset = flexicolor_get_presets($fpid);
    if (count($preset) == 1) {
      $preset = array_pop($preset);
      $default_name = $preset->display_name;
      $form['fpid'] = array(
        '#type' => 'value',
        '#value' => $fpid,
      );
      foreach ($selectors as $key => $selector) {
        $fsid = str_replace('selector-', '', $key);
        $preset_selector = flexicolor_get_preset_selector($fpid, $fsid);
        if (is_object($preset_selector)) {
          $selectors[$key]->default_color = $preset_selector->color;
        }
      }
    }
  }
  
  $form['display_name'] = array(
    '#type' => 'textfield',
    '#title' => t('Display Name'),
    '#default_value' => $default_name,
    '#maxlength' => 64,
    '#size' => 64,
    '#required' => TRUE,
  );
  
  $form['flexicolor'] = array(
    '#type' => 'fieldset',
    '#title' => 'Flexible Colors',
    '#description' => t('Flexible Colours allow you to change the look/feel of certain areas of your site.'),
    '#collapsible' => TRUE,
    '#attributes' => array('id' => 'flexicolor-fieldset'),
  );
  
  foreach ($selectors as $key => $selector) {
    $form['flexicolor'][$key] = array(
      '#type' => 'textfield',
      '#title' => check_plain($selector->display_name),
      '#description' => '<ul><li>Selectors affected: '. check_plain($selector->selector)
        .'</li><li>Color area: '. check_plain($selector->type == 'color' ? 'text' : $selector->type) .'</li></ul>',
      '#default_value' => $selector->default_color,
      '#required' => TRUE,
      '#maxlength' => 7,
      '#size' => 7,
    );
  }
  
  $form['flexicolor']['color-picker'] = array(
    '#markup' => '<div id="flexicolor-color-picker"></div>'
  );
  
  $form['#redirect'] = 'admin/appearance/flexicolor';
  
  return confirm_form($form, t('Save preset'), 'admin/appearance/flexicolor', '', t('Save'), t('Cancel'));
}

function flexicolor_admin_update_preset_submit($form, &$form_state) {
  $values = $form_state['values'];
  $preset = array(
    'display_name' => $values['display_name']
  );
  $primary_key = array();
  if (isset($values['fpid'])) {
    $preset['fpid'] = $values['fpid'];
  }
  flexicolor_save_preset($preset);
  $fpid = $preset['fpid'];
  foreach ($values as $key => $value) {
    if (strpos($key, 'selector-') === 0) {
      $fsid = str_replace('selector-', '', $key);
      flexicolor_save_preset_selector($fpid, $fsid, $value);
    }
  }
  drupal_set_message(t('Preset has been saved'));
}

function flexicolor_admin_delete_preset($form, &$form_state, $fpid) {
  $form = array();
  $form['fpid'] = array(
    '#type' => 'value',
    '#value' => $fpid,
  );
  $form['#redirect'] = 'admin/appearance/flexicolor';
  return confirm_form($form, 'Are you sure you wish to delete the preset', 'admin/appearance/flexicolor');
}

function flexicolor_admin_delete_preset_submit($form, &$form_state) {
  $values = $form_state['values'];
  flexicolor_delete_preset($values['fpid']);
  drupal_set_message(t('Preset has now been deleted'));
}

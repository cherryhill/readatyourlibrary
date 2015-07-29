<?php

/**
 * @file
 * Contains the various interfaces where a site administrator can make changes
 * to the way the flexicolor module functions for the website.
 */

function flexicolor_site_settings($form, &$form_state) {
  $form = array();

  $presets = flexicolor_get_presets();
  foreach ($presets as $key => $preset) {
    $options[$key] = $preset->display_name;
  }
  $options['custom'] = t('Custom…');

  $default_preset = variable_get('flexicolor-selected-preset', '');

  $form['flexicolor-selected-preset'] = array(
    '#type' => 'select',
    '#title' => t('Available presets'),
    '#description' => t('Preset configurations of rules for colors and selectors.'),
    '#options' => $options,
    '#default_value' => $default_preset,
  );

  $form['customize'] = array(
    '#type' => 'fieldset',
    '#title' => 'Customize colors',
    '#description' => t(''),
    '#collapsible' => TRUE,
    '#collapsed' => TRUE,
    '#attributes' => array('id' => 'flexicolor-fieldset'),
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

    $form['customize']["flexicolor-$key"] = array(
      '#type' => 'textfield',
      '#title' => check_plain($selector->display_name),
      '#description' => '<ul><li>Selectors affected: '. check_plain($selector->selector)
        .'</li><li>Color area: '. check_plain($selector->type == 'color' ? 'text' : $selector->type) .'</li></ul>',
      '#maxlength' => 7,
      '#size' => 7,
      '#attributes' => array('class' => array('form-item-input-flexicolor-selector')),
      '#default_value' => $default_color_value
    );
  }

  $preset_selectors = array();
  foreach ($presets as $preset_key => $preset) {
    $preset_selectors[$preset_key] = array();
    foreach ($selectors as $selector_key => $selector) {
      $preset_selectors[$preset_key][$selector_key] = $selector->default_color;
      $possible_color = flexicolor_get_preset_selector($preset->machine, $selector->machine);
      if (is_object($possible_color) && $possible_color->color) {
        $preset_selectors[$preset_key][$selector_key] = $possible_color->color;
      }
    }
  }

  drupal_add_css(drupal_get_path('module', 'flexicolor') . '/flexicolor.css');
  drupal_add_js(array('flexicolor_preset_selectors' => $preset_selectors), 'setting');

  $form['customize']['color-picker'] = array(
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

function flexicolor_rules_page() {
  $content = '';
  $content .= '<h2>' . t('Rules') . '</h2>';

  $rules_table_header = array(
    array('data' => t('Rule name'), 'field' => 'name', 'sort' => 'asc'),
    array('data' => t('Type'), 'field' => 'type'),
    array('data' => t('Selectors'), 'field' => 'selectors'),
    array('data' => t('Default color'), 'field' => 'color'),
    array('data' => t('Actions'), 'field' => 'actions'),
  );

  $order = tablesort_get_order($rules_table_header);
  $sort = tablesort_get_sort($rules_table_header);
  $sql = $order['sql'];

  $rules = flexicolor_get_selectors();
  $rules_table = array();
  foreach ($rules as $rule) {
    $rules_table[] = array(
      'name' => check_plain($rule->display_name),
      'type' => $rule->type,
      'selectors' => $rule->selector,
      'color' => check_plain($rule->default_color),
      'actions' => l(t('edit'), 'admin/appearance/flexicolor/rules/' . $rule->fsid . '/update') .' / '.
                   l(t('delete'), 'admin/appearance/flexicolor/rules/' .  $rule->fsid . '/delete'),
    );
  }

  foreach ($rules_table as $key => $row) {
    $array[$key] = $row[$sql];
  }

  if ($sort == 'asc') {
    array_multisort($array, SORT_ASC, $rules_table);
  }
  if ($sort == 'desc') {
    array_multisort($array, SORT_DESC, $rules_table);
  }

  $rows = array();
  foreach ($rules_table as $rule) {
    $rows[] = array(
        array('data' => $rule['name']),
        array('data' => $rule['type']),
        array('data' => $rule['selectors']),
        array('data' => $rule['color']),
        array('data' => $rule['actions']),
    );
  }

  $content .= theme('table', array('header' => $rules_table_header, 'rows' => $rows));
  return $content;
}

function flexicolor_admin_update_selector($form, &$form_state, $fsid = NULL) {
  $form = array();

  $default_color = '#000000';
  $default_type = 'background-color';
  $default_display_name = $default_selector = '';

  $form['machine'] = array(
    '#type' => 'value',
    '#value' => '',
  );
  if ($fsid !== NULL) {
    $selector = flexicolor_get_selectors($fsid);
    if (count($selector) == 1) {
      $selector = array_pop($selector);
      $form['fsid'] = array(
        '#type' => 'value',
        '#value' => $fsid,
      );
      $form['machine']['#value'] = $selector->machine;
      $default_display_name = $selector->display_name;
      $default_selector = $selector->selector;
      $default_color = $selector->default_color;
      $default_type = $selector->type;
    }
  }

  $form['display_name'] = array(
    '#type' => 'textfield',
    '#title' => t('Rule name'),
    '#description' => t('The name for the rule that will contain the color property and value for the given selector(s).'),
    '#size' => 64,
    '#maxlength' => 128,
    '#required' => TRUE,
    '#default_value' => $default_display_name,
  );

  $options = _flexicolor_get_types();

  $form['type'] = array(
    '#type' => 'radios',
    '#title' => t('Color property'),
    '#options' => $options,
    '#default_value' => $default_type,
    '#required' => TRUE,
  );

  $form['selector'] = array(
    '#type' => 'textarea',
    '#title' => t('Selector(s)'),
    '#description' => t('The selector(s) for this rule. Use commas to separate selectors. You may use pseudo-classes and pseudo-elements. Certain attribute selectors may not work.'),
    '#required' => TRUE,
    '#rows' => substr_count($default_selector, ',') + 2,
    '#default_value' => str_replace(', ', ",\n", $default_selector),
  );

  $form['color'] = array(
    '#type' => 'textfield',
    '#title' => t('Default color'),
    '#description' => t('Type a hexidecimal color code or select a color using the color picker.'),
    '#size' => 7,
    '#maxlength' => 7,
    '#required' => TRUE,
    '#default_value' => $default_color,
  );

  $form['color-picker'] = array(
    '#markup' => '<div id="flexicolor-color-picker"></div>',
  );

  return confirm_form($form, t('Save rule'), 'admin/appearance/flexicolor/rules', '', t('Save'), t('Cancel'));
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
    'default_color' => $values['color'],
    'machine' => $values['machine'],
  );
  if (isset($values['fsid'])) {
    $selector['fsid'] = $values['fsid'];
  }
  flexicolor_save_selector($selector);
  $form_state['redirect'] = 'admin/appearance/flexicolor/rules';
  drupal_set_message('The rule has been saved. Please note that it has been filtered and cleaned for any possible issues.');
}

function flexicolor_admin_delete_selector($form, &$form_state, $fsid) {
  $form = array();
  $form['fsid'] = array(
    '#type' => 'value',
    '#value' => $fsid,
  );
  $rules = flexicolor_get_selectors($fsid);
  foreach ($rules as $rule) {
    if ($rule->fsid == $fsid) {
      $display_name = $rule->display_name;
      $type = $rule->type;
    }
  }
  return confirm_form($form, t("Are you sure you want to delete the <em>$type</em> rule: $display_name?"), 'admin/appearance/flexicolor/rules', NULL, t('Delete'));
}

function flexicolor_admin_delete_selector_submit($form, &$form_state) {
  $values = $form_state['values'];
  flexicolor_delete_selector($values['fsid']);
  $form_state['redirect'] = 'admin/appearance/flexicolor/rules';
  drupal_set_message(t('The rule has been deleted.'));
}

function flexicolor_presets_page() {
  $content = '';
  // List the presets
  $content .= '<h2>' . t('Presets') . '</h2>';
  $preset_table_header = array(t('Preset name'), t('Actions'));
  $preset_table = array();
  $presets = flexicolor_get_presets();
  foreach ($presets as $preset) {
    $preset_table[] = array(
      check_plain($preset->display_name),
      l(t('edit'), 'admin/appearance/flexicolor/presets/' . $preset->fpid . '/update') .' / '.
      l(t('delete'), 'admin/appearance/flexicolor/presets/' . $preset->fpid . '/delete'),
    );
  }
  $content .= theme('table', array('header' => $preset_table_header, 'rows' => $preset_table));
  return $content;
}

function flexicolor_admin_update_preset($form, &$form_state, $fpid = NULL) {
  $form = array();

  $default_name = '';
  $selectors = flexicolor_get_selectors();
  $form['machine'] = array(
    '#type' => 'value',
    '#value' => '',
  );
  $form['#selectors'] = $selectors;
  if ($fpid !== NULL) {
    $preset = flexicolor_get_presets($fpid);
    if (count($preset) == 1) {
      $preset = array_pop($preset);
      $default_name = $preset->display_name;
      $form['fpid'] = array(
        '#type' => 'value',
        '#value' => $fpid,
      );
      $form['machine']['#value'] = $preset->machine;
      foreach ($selectors as $key => $selector) {
        $fsid = str_replace('selector-', '', $key);
        $preset_selector = flexicolor_get_preset_selector($preset->machine, $selector->machine);
        if (is_object($preset_selector)) {
          $selectors[$key]->default_color = $preset_selector->color;
        }
      }
    }
  }

  $form['display_name'] = array(
    '#type' => 'textfield',
    '#title' => t('Preset name'),
    '#default_value' => $default_name,
    '#maxlength' => 64,
    '#size' => 64,
    '#required' => TRUE,
  );

  $form['flexicolor'] = array(
    '#type' => 'fieldset',
    '#title' => 'Flexible Colors',
    '#description' => t('Flexible Colors allow you to change the look/feel of certain areas of your site.'),
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

  return confirm_form($form, t('Save preset'), 'admin/appearance/flexicolor/presets', '', t('Save'), t('Cancel'));
}

function flexicolor_admin_update_preset_submit($form, &$form_state) {
  $values = $form_state['values'];
  $selectors = $form['#selectors'];
  $preset = array(
    'display_name' => $values['display_name'],
    'machine' => $values['machine'],
  );
  $primary_key = array();
  if (isset($values['fpid'])) {
    $preset['fpid'] = $values['fpid'];
  }
  flexicolor_save_preset($preset);
  foreach ($selectors as $key => $selector) {
    $color = $values[$key];
    flexicolor_save_preset_selector($preset['machine'], $selector->machine, $color);
  }
  $form_state['redirect'] = 'admin/appearance/flexicolor/presets';
  drupal_set_message(t('The preset has been saved.'));
}

function flexicolor_admin_delete_preset($form, &$form_state, $fpid) {
  $form = array();
  $form['fpid'] = array(
    '#type' => 'value',
    '#value' => $fpid,
  );
  $presets = flexicolor_get_presets($fpid);
  foreach ($presets as $preset) {
    if ($preset->fpid == $fpid) {
      $display_name = $preset->display_name;
    }
  }
  return confirm_form($form, t("Are you sure you want to delete the preset: $display_name?"), 'admin/appearance/flexicolor/presets', NULL, t('Delete'));
}

function flexicolor_admin_delete_preset_submit($form, &$form_state) {
  $values = $form_state['values'];
  flexicolor_delete_preset($values['fpid']);
  $form_state['redirect'] = 'admin/appearance/flexicolor/presets';
  drupal_set_message(t('The preset has been deleted.'));
}

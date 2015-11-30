<?php

/**
 * @file
 * Administrative file for abbrfilter module.
 */


/**
 * Query to get the list of abbrs to filter in the
 * filter processing stage. Does not use a pager.
 *
 * @return
 *   a list of abbreviations to filter
 */
function _abbrfilter_list($refresh = 0) {
  static $list = NULL;
  if (is_null($list) || $refresh) {
    $result = db_select('abbrfilter','abbr')
      ->fields('abbr')
      ->orderBy('abbrs')
      ->execute();

    $list = array();
    while ($a = $result->fetchAssoc()) {
      $list[] = $a;
    }
  }
  return $list;
}


/**
 * Helper function: Query to get the list of abbrs to filter.
 *
 * @TODO: add pager back in using DB:TNG
 *
 * @return
 *   a list of abbreviations to filter
 */
function _abbrfilter_admin_list($header) {
  $result = db_select('abbrfilter','abbr')
    ->fields('abbr')
    ->orderBy('abbrs')
    ->execute();

  $list = array();
  while ($a = $result->fetchAssoc()) {
    $list[] = $a;
  }

  return $list;
}


/**
 * Admin settings page callback.
 *
 * @return
 *  A themed table of abbreviations to filter with links to edit and delete operations
 *
 */
function abbrfilter_admin_list() {
  $output = '';
  $header = array(
    array('data' => t('Abbreviation'), 'field' => 'abbrs', 'sort' => 'asc'),
    array('data' => t('Full term'), 'field' => 'replacement'),
    array('data' => t('Operations'), 'colspan' => 2)
  );
  $rows = array();
  $list = _abbrfilter_admin_list($header);
  foreach ($list as $abbr) {
    $rows[] = array(
      check_plain($abbr['abbrs']),
      check_plain($abbr['replacement']),

      l(t('Edit'), 'admin/config/content/abbrfilter/edit/'. $abbr['id']),
      l(t('Delete'), 'admin/config/content/abbrfilter/delete/'. $abbr['id']),
    );
  }

  // options for theme_table
  $options = array(
    'header' => $header,
    'rows' => $rows
  );

  $output .= theme('table', $options);
  $output .= theme('pager');

  return $output;
}


/**
 * Edit abbr filter form.
 *
 * @param $abbr_id
 *   the id of the abbreviation to edit, if not a new abbreviation
 *
 * @return
 *  the form array
 */
function abbrfilter_admin_edit_form($form, $data = NULL) {
  $abbr_id = $data['build_info']['args'][0];

  if (!isset($abbr_id) || !is_numeric($abbr_id)) {
    drupal_set_message(t('The ABBRfilter ID of the abbr or phrase you are trying to edit is missing or is not a number.'), 'error');
    drupal_goto('admin/config/content/abbrfilter');
  }
  $abbr = db_select('abbrfilter','abbr')
    ->fields('abbr')
    ->condition('id',$abbr_id)
    ->execute()
    ->fetchAssoc();

  $form = array();
  $form['id'] = array(
    '#type' => 'hidden',
    '#value' => $abbr['id'],
  );

  $form['abbrs'] = array(
    '#type' => 'textfield',
    '#title' => t('Abbreviation or phrase to filter'),
    '#default_value' => $abbr['abbrs'],
    '#description' => t('Enter the abbreviation you want to filter.'),
    '#size' => 20,
    '#maxlength' => 255,
    '#required' => TRUE,
  );
  $form['replacement'] = array(
    '#type' => 'textfield',
    '#title' => t('Replacement text'),
    '#description' => t('Enter the full, unabbreviated term to which the abbreviation refers.'),
    '#default_value' => $abbr['replacement'],
    '#size' => 70,
    '#maxlength' => 255,
  );
  $form['Save abbr filter'] = array(
    '#type' => 'submit',
    '#value' => t('Save abbr filter'),
  );

  return $form;
}


/**
 * Edit abbr filter form submit handler.
 *
 * writes abbreviation to table and provides a message
 */
function abbrfilter_admin_edit_form_submit($form, &$form_state) {
  $row = new stdClass;
  $row->id       = $form_state['values']['id'];
  $row->abbrs     = trim($form_state['values']['abbrs']);
  $row->replacement = trim($form_state['values']['replacement']);
  
  
  $list = _abbrfilter_list();
  $abbrduplicate='';
  foreach ($list as $abbr) {
    if ($abbr['abbrs'] == $row->abbrs) {
      if ($row->id != $abbr['id']) {
        $abbrduplicate .= 'DUPE';
      }
    }
	}
	
	if ($abbrduplicate!='') {
	  drupal_set_message(t('Cannot add abbreviation. %abbr already exists.', array('%abbr' => $row->abbrs)), 'error');
	  $form_state['redirect'] = FALSE;  
	}
	elseif (preg_match('/^[\w][\w\.~\/\-]+$/', $row->abbrs)==FALSE) {
	  drupal_set_message(t('Cannot add abbreviation. %abbr contains invalid characters.', array('%abbr' => $row->abbrs)), 'error');
	  $form_state['redirect'] = FALSE;
	}
	elseif ($row->replacement) {
      drupal_write_record('abbrfilter', $row, 'id');
      watchdog('abbrfilter', 'Updated filter for: %abbr', array('%abbr' => $row->abbrs));
      drupal_set_message(t('Updated filter for: %abbr', array('%abbr' => $row->abbrs)));
      $form_state['redirect'] = 'admin/config/content/abbrfilter';
      cache_clear_all('*', 'cache_filter', TRUE);
	}
	else {
	  drupal_set_message(t('Cannot add abbreviation.  You must specify the unabbreviated text for: %abbr',  array('%abbr' => $row->abbrs)), 'error');
	  $form_state['redirect'] = FALSE;
	}

}


/**
 * Add abbr filter form.
 *
 * form for adding multiple abbreviations at once
 *
 * @return
 *   the form array
 */
function abbrfilter_admin_add_form() {
  $form = array();

  $form['help'] = array(
    '#type' => 'markup',
    '#value' => t("Enter an abbreviation you want to augment followed by '|' and the full text unabbrevaited term. Example: 'USA|United States of America'. You can enter multiple abbreviation and terms pairs by hitting return and adding more. Abbreviations are 2+ characters, begin with an alphanumeric, are case sensitive, and must be paired with an unabbreviated term. Allowed characters: [ A-Z 0-9 . - / ~ ]"),
  );

  $form['abbrs'] = array(
    '#type' => 'textarea',
    '#title' => t('abbrs'),
    '#description' => t("Enter a abbreviation you want to augment followed by '|' and the full term or phrase. Example: 'USA|United States of America'."),
    '#required' => true
  );
  
  $form['skipdupes'] = array(
    '#type' => 'checkbox',
    '#title' => t('Skip Duplicates'),
    '#description' => t('If checked, this options will ignore any pre-existing abbreviations and add the remaining abbreviations to the master list. Useful when importing an exported list.'),
  );

  $form['Save abbr filter'] = array(
    '#type' => 'submit',
    '#value' => t('Save ABBR filter')
  );

  return $form;
}


/**
 * Add abbr filter form submit handler.
 *
 * Validates submission by checking for duplicate entries, invalid
 * characters, and that there is an abbreviation and phrase pair
 */
function abbrfilter_admin_add_form_submit($form, &$form_state) {
  $pairs = explode("\n", $form_state['values']['abbrs']);
  $pairs = array_map('trim', $pairs);
  $pairs = array_filter($pairs, 'strlen');
  $submissioncheck = '';
  $submissions = '';
  foreach ($pairs as $pair) {
    $row = new stdClass;
    list($row->abbrs, $row->replacement) = explode('|', $pair);
    $row->abbrs = trim($row->abbrs);
    $row->replacement = trim($row->replacement);
	
    $list = _abbrfilter_list();
    $abbrduplicate = '';
    foreach ($list as $abbr) {
      if ($abbr['abbrs'] == $row->abbrs) {
        $abbrduplicate .= 'DUPE';
      }
    }

    if ($abbrduplicate != '' && $form_state['values']['skipdupes'] == 1) {
      drupal_set_message(t('Skipping abbreviation %abbr, already exists.', array('%abbr' => $row->abbrs)));
      // $form_state['redirect'] = 'admin/config/content/abbrfilter';
    } else if ($abbrduplicate != '') {
      drupal_set_message(t('Cannot add abbreviation. %abbr already exists.', array('%abbr' => $row->abbrs)), 'error');
      //$form_state['redirect'] = FALSE;    
      $submissioncheck = 'NO';
    }
    elseif (preg_match('/^[\w][\w\.~\/\-]+$/', $row->abbrs) == FALSE) {
      drupal_set_message(t('Cannot add abbreviation. %abbr contains invalid characters.', array('%abbr' => $row->abbrs)), 'error');
      //$form_state['redirect'] = FALSE;
      $submissioncheck = 'NO';
    }
    elseif ($row->replacement) {
      $submissions[] = $row;
    }
    else {
      drupal_set_message(t('Cannot add abbreviation.  You must specify the unabbreviated text for: %abbr',  array('%abbr' => $row->abbrs)), 'error');
      //$form_state['redirect'] = FALSE;
      $submissioncheck = 'NO';
    }
  }
  
  if ($submissioncheck == '') {
    foreach ($submissions as $row) {
      drupal_write_record('abbrfilter', $row);
      watchdog('abbrfilter', 'Added filter for: %abbr', array('%abbr' => $row->abbrs));
      drupal_set_message(t('Added filter for: %abbr', array('%abbr' => $row->abbrs)));
    }  
    $form_state['redirect'] = 'admin/config/content/abbrfilter';
    cache_clear_all('*', 'cache_filter', TRUE);
  } 
  else {
  	$form_state['redirect'] = FALSE;
  }
  
}


/**
 * Test abbr filter form.
 *
 * A form to let you test a phrase in the admin inteface
 *
 * @return
 *   the form array
 */
function abbrfilter_admin_test_filter_form($form, &$form_state) {
  $form = array();

  $form['test_abbr'] = array(
    '#type' => 'textfield',
    '#title' => t('Abbreviation to test'),
    '#description' => t('Enter an abbreviation or phrase that you want to test your abbrfilters on'),
    '#size' => 50,
    '#maxlength' => 255,
    '#required' => TRUE,
  );

  // @TODO: consider moving this user feedback into drupal_set_message() with status/error based on outcome
  if (isset($form_state['values']['test_abbr'])) {
    $form['text_result'] = array(
      '#type' => 'markup',
      '#markup' => _abbrfilter_test_filter($form_state['values']['test_abbr']),
      '#prefix' => '<div class="abbrfilter-test-filter">',
      '#suffix' => '</div>',
    );
  }

  $form['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Test this Abbreviation'),
  );

  return $form;
}


/**
 * Export abbr filter form.
 *
 * A page that writes out your ABBR filters in the same format they go in as
 *
 * @return
 *   the form array
 */
function abbrfilter_admin_export_filters_form($form_state) {
  $form = array();
  $form['#redirect'] = FALSE;

  $form['export_abbrs'] = array(
    '#type' => 'textarea',
    '#title' => t('abbrs to export'),
    '#description' => t('use copy and paste to save this list of abbreviations or send to another site'),
    '#value' => abbrfilter_generate_export_list(),
  );

  return $form;
}


/**
 * Helper function: generate export list.
 */
function abbrfilter_generate_export_list() {
  $list = _abbrfilter_list();
  $content = '';
  foreach ($list as $abbr) {
    $content .= $abbr['abbrs'] ."|". $abbr['replacement'] ."\n";
  }
  return $content;
}


/**
 * Test abbr filter form submit handler.
 */
function abbrfilter_admin_test_filter_form_submit($form, &$form_state) {
  $form_state['rebuild'] = TRUE;
}


/**
 * Test abbr filter page callback.
 *
 * @param $testphrase
 *   a string to run through the filter as a test
 *
 * @return
 *   a message that shows that the phrase was filtered or not
 *
 */
function _abbrfilter_test_filter($testphrase) {
  $filtered_phrase = _filter_abbrfilter_process($testphrase);
  if ($testphrase == $filtered_phrase) {
    return t("Your test abbreviation '%testphrase' did not match any filters", array('%testphrase' => $testphrase));

  }
  else {
    return t("Your test abbreviation '%testphrase' was filtered to '%filtered_phrase'", array('%testphrase' => $testphrase, '%filtered_phrase' => $filtered_phrase));
  }
}


/**
 * Delete a abbr from the abbr filter list delete confirmation callback
 *
 * @param $abbr_id
 *   The ID of the abbreviation to delete
 *
 * @return
 *  returns a confirmation (are you sure) form
 */
function abbrfilter_admin_form_delete_confirm($form, $abbr_id) {
  $form = array();
  // @TODO: run a select on the id and put the acronym in this confirmation message
  return confirm_form($form, t('Are you sure you want to delete this abbreviation from the ABBR filtering list?'), 'admin/config/content/abbrfilter');
}


/**
 * Delete a abbr from the abbr filter list
 */
function abbrfilter_admin_form_delete_confirm_submit($form, &$form_state) {
  $abbr_id = $form_state['build_info']['args'][0];

  if ($form_state['values']['confirm']) {

    // Collect its data before deleting so we can provide a helpful success message
    $del_abbr = db_select('abbrfilter','abbr')
      ->fields('abbr')
      ->condition('id', $abbr_id)
      ->execute()
      ->fetchAssoc();

    // Delete from DB
    db_delete('abbrfilter')
      ->condition('id', $abbr_id)
      ->execute();

    drupal_set_message(t('The abbreviation <em>!abbr</em> was removed from the ABBR filter list', array('!abbr' => $del_abbr['abbrs'])));
    $form_state['redirect'] = 'admin/config/content/abbrfilter';
    cache_clear_all('*', 'cache_filter', TRUE);
  }
}

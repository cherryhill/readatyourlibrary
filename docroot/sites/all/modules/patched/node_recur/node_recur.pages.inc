<?php

/**
 * The node recur form
 */
function node_recur_node_recur_form($form, $form_state, $node) {
  // Check if the form was already submitted
  if (isset($form_state['values'])) {
    return node_recur_node_recur_confirm($form, $form_state, $node);
  }
  
  // Display this node's date
  $start = node_recur_get_node_date_field_value($node);
  $end = node_recur_get_node_date_field_value($node, FALSE);
  
  $form['node_date'] = array(
    '#type' => 'item',
    '#title' => t('Date'),
    '#markup' => node_recur_format_date($start, $end),
  );
  
  $form = array_merge($form, _node_recur_node_recur_form($node->type));
  
  // Remove the "no repeat" option
  unset($form['option']['#options']['none']);
  
  $form['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Generate'),
  );
  
  $form['#node'] = $node;

  return $form;
}

/**
 * Helper function to provide the basics of the form
 * 
 * This helps make it available for other modules to use when we might
 * not have a full node yet
 * 
 * @param $type
 *   The node type
 */
function _node_recur_node_recur_form($type = NULL) {
  $form = array();
  
  $form['option'] = array(
    '#type' => 'radios',
    '#options' => array(
      'none' => t('Do not repeat'),
      'days' => t('Pick days of the week'),
      'rules' => t('Every day, every 2 weeks, etc...'),
      'monthly' => t('Monthly on a day of the week'),
    ),
    '#default_value' => 'days',
    '#description' => t('Selecting a choice above will reveal more options.'),
  );
    
  $form['days'] = array(
    '#type' => 'checkboxes',
    '#title' => t('Days of the week'),
    '#options' => array(
      'monday' => t('Monday'),
      'tuesday' => t('Tuesday'),
      'wednesday' => t('Wednesday'),
      'thursday' => t('Thursday'),
      'friday' => t('Friday'),
      'saturday' => t('Saturday'),
      'sunday' => t('Sunday'),
    ),
  );
  
  $form['rules'] = array(
    '#type' => 'container',
  );
  
  $options = array();
  for ($i = 1; $i < 11; $i++) {
    $options[$i] = t('Every !i', array('!i' => ($i == 1) ? '' : $i));
  }
  $form['rules']['frequency'] = array(
    '#type' => 'select',
    '#title' => t('Repeat'),
    '#options' => $options,
  );
  
  $form['rules']['period'] = array(
    '#type' => 'select',
    '#options' => array(
      'day' => t('Day(s)'),
      'week' => t('Week(s)'),
      'month' => t('Month(s)'),
    ),
  );
  
  $form['rules']['exclude_weekends'] = array(
    '#type' => 'checkbox',
    '#title' => t('Exclude weekends'),
    '#description' => t('If checked, weekends will not be included.'),
  );
  
  $form['monthly'] = array(
    '#type' => 'container',
  );

  $form['monthly']['occurrence'] = array(
    '#type' => 'select',
    '#title' => t('Repeat monthly on the'),
    '#options' => array(
      'first' => t('1st'),
      'second' => t('2nd'),
      'third' => t('3rd'),
      'fourth' => t('4th'),
      'last' => t('Last'),
    ),
  );

  $form['monthly']['weekday'] = array(
    '#type' => 'select',
    '#options' => array(
      'monday' => t('Monday'),
      'tuesday' => t('Tuesday'),
      'wednesday' => t('Wednesday'),
      'thursday' => t('Thursday'),
      'friday' => t('Friday'),
      'saturday' => t('Saturday'),
      'sunday' => t('Sunday'),
    ),
  );

  $form['until'] = array(
    '#type' => 'textfield',
    '#title' => t('Recur until'),
    '#description' => t('Repeat this class until the specified date.'),
    '#required' => TRUE,
  );
  if ($max = node_recur_max_future_date_span($type)) {
    $form['until']['#description'] .= '&nbsp;' . t('This date can only be up to %max in the future.', array('%max' => $max));
  }
  
  drupal_add_library('system', 'ui.datepicker');
  $form['#attached']['js'][] = drupal_get_path('module', 'node_recur') . '/node_recur.js';
  
  return $form;
}

/**
 * Validate the node recur form
 */
function node_recur_node_recur_form_validate(&$form, &$form_state) {
  // If this is the confirm form, then skip validation
  if (isset($form_state['values']['confirm'])) {
    return;
  }
  
  // If option is set to nothing, then skip validation
  if ($form_state['values']['option'] == 'none') {
    return;
  }
  
  $node = $form['#node'];

  // If days option is selected, make sure we have at least one day
  if ($form_state['values']['option'] == 'days') {
    $days = 0;
    foreach ($form_state['values']['days'] as $day => $value) {
      if ($value) {
        $days++;
      }
    }
    if ($days == 0) {
      form_set_error('days', t('At least one day must be selected.'));
    }
  }
  
  // Check until date format
  $until = strtotime($form_state['values']['until']);
  if (!is_numeric($until)) {
    form_set_error('until', t('You must supply a valid end date.'));
    // Stop here
    return;
  }
  // Make sure until date is in the future
  if (!node_recur_allow_past_dates($node->type) && ($until < REQUEST_TIME)) {
    form_set_error('until', t('The end date must be in the future.'));
  }
  // Check that until date isn't too far in the future, according
  // to node settings (if any)
  if ($max = node_recur_max_future_date_span($node->type)) {
    if ($until > strtotime($max, REQUEST_TIME)) {
      form_set_error('until', t('The end date can only be up to %max in the future.', array('%max' => $max))); 
    }
  }

  // If there were no errors, allow other modules to validate the dates
  if (!form_get_errors()) {
    $errors = module_invoke_all('node_recur_validate_dates', $node, $form_state);
    foreach ($errors as $error) {
      form_set_error($error['field'], $error['message']);
    }
  }
}

/**
 * Submit the node recur form
 */
function node_recur_node_recur_form_submit(&$form, &$form_state) {
  // Rebuild so we can present the confirm form
  $form_state['rebuild'] = TRUE;
}

/**
 * Confirm form for node recur
 */
function node_recur_node_recur_confirm($form, $form_state, $node) {
  $dates = node_recur_generate_dates_from_form($node, $form_state);
  
  // Make sure we have dates to work with
  if (empty($dates['start'])) {
    drupal_set_message(t('No dates were generated with the information you supplied.'), 'warning');
    drupal_goto("node/{$node->nid}/recur");
  }

  // Store the dates
  $form['#start_dates'] = $dates['start'];
  $form['#end_dates'] = $dates['end'];
  
  // Display the dates to the user
  $form['message'] = array(
    '#markup' => t('The following dates will be generated. Please review them before continuing.'),
  );
  $form['dates']['#markup'] = '<ul>';
  foreach ($dates['start'] as $key => $start_date) {
    $end_date = isset($dates['end'][$key]) ? $dates['end'][$key] : NULL;
    $form['dates']['#markup'] .= '<li>' . node_recur_format_date($start_date, $end_date) . '</li>';
  }
  $form['dates']['#markup'] .= '</ul>';
  
  // Store the node
  $form['#node'] = $node;
  
  // Add the submit handler
  $form['#submit'][] = 'node_recur_node_recur_confirm_submit';
  
  // Node type name
  $type = strtolower(node_type_get_name($node));

  // Supply the confirm form
  return confirm_form(
    $form,
    t('Are you sure you want to generate these items?'),
    'node/' . $node->nid,
    '<strong>' . t('This action cannot be undone. Please confirm that the dates above are accurate and that the %type information is correct. Editing this %type afterwards will not edit every %type generated here.', array('%type' => $type, '%type' => $type, '%type' => $type)) . '</strong>',
    t('Submit')
  );
}

/**
 * Submit the node recur confirmation form
 */
function node_recur_node_recur_confirm_submit(&$form, &$form_state) {
  $node = $form['#node'];
  // Log this action
  watchdog('node_recur', 'Recurring the %type "%title" %count times.', array('%type' => $node->type, '%title' => check_plain($node->title), '%count' => count($form['#start_dates'])));
  // Start the batch
  module_load_include('inc', 'node_recur', 'node_recur.batch');
  node_recur_node_batch_start($node, $form['#start_dates'], $form['#end_dates']);
}

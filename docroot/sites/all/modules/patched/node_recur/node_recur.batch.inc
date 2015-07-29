<?php

/**
 * Start the batch to generate recurring nodes
 */
function node_recur_node_batch_start($node, $start_dates, $end_dates = array()) {
  // Generate the batch operations
  $operations = array();
  if ($start_dates) {
    foreach ($start_dates as $key => $start_date) {
      $operations[] = array('node_recur_node_batch_create_node', array($node, $start_date, isset($end_dates[$key]) ? $end_dates[$key] : NULL));
    }
  }
  
  // Generate the batch
  $batch = array(
    'title' => t('Generating items'),
    'operations' => $operations,
    'finished' => 'node_recur_node_batch_finished',
    'file' => drupal_get_path('module', 'node_recur') . '/node_recur.batch.inc',
  );
  
  // @todo: Best way to pass into finished callback?
  $_SESSION['batch_recur_nid'] = $node->nid;
  
  batch_set($batch);
}

/**
 * Create the recurring nodes
 */
function node_recur_node_batch_create_node($node, $start_date, $end_date = NULL, $context) {
  // Set the progress message
  $context['message'] = t('Date: !date', array('!date' => format_date($start_date)));
  
  // Clone the node
  $clone = clone $node;
  unset($clone->nid);
  unset($clone->created);
  unset($clone->changed);
  unset($clone->vid);
  
  // Add some helpful markers
  $clone->is_recurring = TRUE;
  $clone->recurring_node = $node;

  // Inject the new dates
  $field_name = node_recur_get_date_field_name($node->type);
  $date = $clone->$field_name;
  $date[LANGUAGE_NONE][0]['value'] = date(DATE_FORMAT_DATETIME, $start_date);
  if ($end_date) {
    $date[LANGUAGE_NONE][0]['value2'] = date(DATE_FORMAT_DATETIME, $end_date);
  }
  $clone->$field_name = $date;
  
  // Store the start dates
  $context['results'][] = $start_date;

  // Save the new node
  node_save($clone);
}

/**
 * Batch ending
 */
function node_recur_node_batch_finished($success, $results, $operations) {
  if ($success) {
    $count = count($results);
    drupal_set_message(t('%count %items have been generated.', array('%count' => $count, '%items' => format_plural($count, 'item', 'items'))));
  }
  else {
    drupal_set_message(t('An error occurred. Please try again.'), 'error');
  }
  
  // Determine where to redirect to
  $path = NULL;
  $nid = NULL;
  if (isset($_SESSION['batch_recur_nid']) && is_numeric($_SESSION['batch_recur_nid'])) {
    $nid = $_SESSION['batch_recur_nid'];
    $path = 'node/' . $nid;
  }
  // Allow modules to alter the path
  drupal_alter('node_recur_batch_redirect', $path, $nid);
  if ($path) {
    drupal_goto($path);
  }
}

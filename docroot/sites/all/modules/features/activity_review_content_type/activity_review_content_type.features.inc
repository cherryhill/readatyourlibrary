<?php
/**
 * @file
 * activity_review_content_type.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function activity_review_content_type_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_node_info().
 */
function activity_review_content_type_node_info() {
  $items = array(
    'review_activity' => array(
      'name' => t('Activity Review'),
      'base' => 'node_content',
      'description' => t('Use this form to add a review of an activity.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}

<?php
/**
 * @file
 * kids_activity_page_feature.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function kids_activity_page_feature_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_views_api().
 */
function kids_activity_page_feature_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}

/**
 * Implements hook_node_info().
 */
function kids_activity_page_feature_node_info() {
  $items = array(
    'kids_activity_page_' => array(
      'name' => t('Kids Activity page'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}

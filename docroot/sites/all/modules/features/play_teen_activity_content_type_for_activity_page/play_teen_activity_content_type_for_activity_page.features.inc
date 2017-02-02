<?php
/**
 * @file
 * play_teen_activity_content_type_for_activity_page.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function play_teen_activity_content_type_for_activity_page_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_node_info().
 */
function play_teen_activity_content_type_for_activity_page_node_info() {
  $items = array(
    'activity' => array(
      'name' => t('Activity'),
      'base' => 'node_content',
      'description' => t('This content type is used for activity page of teen site.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}

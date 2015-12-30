<?php
/**
 * @file
 * program_and_activities_pages.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function program_and_activities_pages_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_views_api().
 */
function program_and_activities_pages_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}

/**
 * Implements hook_node_info().
 */
function program_and_activities_pages_node_info() {
  $items = array(
    'program' => array(
      'name' => t('Program'),
      'base' => 'node_content',
      'description' => t('This is for site program listing page.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}

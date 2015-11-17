<?php
/**
 * @file
 * librarysite_resources.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function librarysite_resources_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_node_info().
 */
function librarysite_resources_node_info() {
  $items = array(
    'resource' => array(
      'name' => t('Resource'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Resource Name'),
      'help' => '',
    ),
  );
  return $items;
}

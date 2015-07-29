<?php
/**
 * @file
 * librarysite_branches.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function librarysite_branches_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_node_info().
 */
function librarysite_branches_node_info() {
  $items = array(
    'branch' => array(
      'name' => t('Branch'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Branch Name'),
      'help' => '',
    ),
  );
  return $items;
}

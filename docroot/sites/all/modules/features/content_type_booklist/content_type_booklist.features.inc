<?php
/**
 * @file
 * content_type_booklist.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function content_type_booklist_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_node_info().
 */
function content_type_booklist_node_info() {
  $items = array(
    'booklist' => array(
      'name' => t('Booklist'),
      'base' => 'node_content',
      'description' => t('Use this form to add a booklist.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}

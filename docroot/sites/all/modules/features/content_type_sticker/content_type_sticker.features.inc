<?php
/**
 * @file
 * content_type_sticker.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function content_type_sticker_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_node_info().
 */
function content_type_sticker_node_info() {
  $items = array(
    'sticker' => array(
      'name' => t('sticker'),
      'base' => 'node_content',
      'description' => t('This is used for Sticker calendar.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}

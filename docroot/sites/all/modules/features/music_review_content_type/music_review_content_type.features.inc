<?php
/**
 * @file
 * music_review_content_type.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function music_review_content_type_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_node_info().
 */
function music_review_content_type_node_info() {
  $items = array(
    'music_review' => array(
      'name' => t('Music Review'),
      'base' => 'node_content',
      'description' => t('This content type is used for Music Review.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}

<?php
/**
 * @file
 * video_game_review_content_type.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function video_game_review_content_type_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_node_info().
 */
function video_game_review_content_type_node_info() {
  $items = array(
    'video_game_review' => array(
      'name' => t('Video Game Review'),
      'base' => 'node_content',
      'description' => t('This content type is used for Video Game Review.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}
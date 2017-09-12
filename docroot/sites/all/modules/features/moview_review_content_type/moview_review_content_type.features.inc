<?php
/**
 * @file
 * moview_review_content_type.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function moview_review_content_type_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_node_info().
 */
function moview_review_content_type_node_info() {
  $items = array(
    'movie_review' => array(
      'name' => t('Movie Review'),
      'base' => 'node_content',
      'description' => t('This content type is used for Movie Review.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}

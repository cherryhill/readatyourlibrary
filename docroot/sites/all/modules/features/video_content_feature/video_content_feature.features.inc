<?php
/**
 * @file
 * video_content_feature.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function video_content_feature_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_node_info().
 */
function video_content_feature_node_info() {
  $items = array(
    'videos' => array(
      'name' => t('video'),
      'base' => 'node_content',
      'description' => t('This is used for home page video slideshow.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}

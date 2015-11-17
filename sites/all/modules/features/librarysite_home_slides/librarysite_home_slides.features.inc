<?php
/**
 * @file
 * librarysite_home_slides.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function librarysite_home_slides_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_views_api().
 */
function librarysite_home_slides_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}

/**
 * Implements hook_node_info().
 */
function librarysite_home_slides_node_info() {
  $items = array(
    'home_slide' => array(
      'name' => t('Home Slide'),
      'base' => 'node_content',
      'description' => t('Needs an image, caption, title and link. Goes in the slideshow on the home page.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  return $items;
}

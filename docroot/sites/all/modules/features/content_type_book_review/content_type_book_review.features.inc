<?php
/**
 * @file
 * content_type_book_review.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function content_type_book_review_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_node_info().
 */
function content_type_book_review_node_info() {
  $items = array(
    'review_book' => array(
      'name' => t('Book Review'),
      'base' => 'node_content',
      'description' => t('Use this form to add a book review.'),
      'has_title' => '1',
      'title_label' => t('Book title'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}

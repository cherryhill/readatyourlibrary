<?php
/**
 * @file
 * faq_content.features.inc
 */

/**
 * Implements hook_node_info().
 */
function faq_content_node_info() {
  $items = array(
    'faq' => array(
      'name' => t('FAQ'),
      'base' => 'node_content',
      'description' => t('FAQ module 7.x-2.x+ content type for storing faq nodes'),
      'has_title' => '1',
      'title_label' => t('The question'),
      'help' => t('Enter short question here'),
    ),
  );
  return $items;
}

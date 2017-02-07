<?php
/**
 * @file
 * bingo_card_feature.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function bingo_card_feature_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_node_info().
 */
function bingo_card_feature_node_info() {
  $items = array(
    'bingo_card' => array(
      'name' => t('Bingo Card'),
      'base' => 'node_content',
      'description' => t('This content type is to display bingo cards for progress'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}

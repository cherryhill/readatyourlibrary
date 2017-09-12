<?php
/**
 * @file
 * landing_page_for_user.features.inc
 */

/**
 * Implements hook_views_api().
 */
function landing_page_for_user_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}

/**
 * Implements hook_eck_entity_type_info().
 */
function landing_page_for_user_eck_entity_type_info() {
  $items = array(
    'booklist_item' => array(
      'name' => 'booklist_item',
      'label' => 'Booklist item',
      'properties' => array(
        'title' => array(
          'label' => 'Title',
          'type' => 'text',
          'behavior' => 'title',
        ),
      ),
    ),
  );
  return $items;
}

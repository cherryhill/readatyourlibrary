<?php
/**
 * @file
 * booklist_item_entity_type.features.inc
 */

/**
 * Implements hook_eck_bundle_info().
 */
function booklist_item_entity_type_eck_bundle_info() {
  $items = array(
    'booklist_item_booklist_item' => array(
      'machine_name' => 'booklist_item_booklist_item',
      'entity_type' => 'booklist_item',
      'name' => 'booklist_item',
      'label' => 'Booklist item',
      'config' => array(),
    ),
  );
  return $items;
}

/**
 * Implements hook_eck_entity_type_info().
 */
function booklist_item_entity_type_eck_entity_type_info() {
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

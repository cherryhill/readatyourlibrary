<?php
/**
 * @file
 * booklist_item_entity_type.features.inc
 */

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

<?php
/**
 * @file
 * content_type_booklist.features.field_base.inc
 */

/**
 * Implements hook_field_default_field_bases().
 */
function content_type_booklist_field_default_field_bases() {
  $field_bases = array();

  // Exported field_base: 'field_book'.
  $field_bases['field_book'] = array(
    'active' => 1,
    'cardinality' => -1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_book',
    'field_permissions' => array(
      'type' => 0,
    ),
    'indexes' => array(
      'target_id' => array(
        0 => 'target_id',
      ),
    ),
    'locked' => 0,
    'module' => 'entityreference',
    'settings' => array(
      'handler' => 'base',
      'handler_settings' => array(
        'behaviors' => array(
          'views-select-list' => array(
            'status' => 0,
          ),
        ),
        'sort' => array(
          'type' => 'none',
        ),
        'target_bundles' => array(
          'booklist_item' => 'booklist_item',
        ),
      ),
      'profile2_private' => FALSE,
      'target_type' => 'booklist_item',
    ),
    'translatable' => 0,
    'type' => 'entityreference',
  );

  // Exported field_base: 'field_booklist_title'.
  $field_bases['field_booklist_title'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_booklist_title',
    'indexes' => array(
      'format' => array(
        0 => 'format',
      ),
    ),
    'locked' => 0,
    'module' => 'text',
    'settings' => array(
      'max_length' => 1000,
    ),
    'translatable' => 0,
    'type' => 'text',
  );

  return $field_bases;
}

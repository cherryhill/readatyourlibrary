<?php
/**
 * @file
 * play_teen_activity_content_type_for_activity_page.features.field_base.inc
 */

/**
 * Implements hook_field_default_field_bases().
 */
function play_teen_activity_content_type_for_activity_page_field_default_field_bases() {
  $field_bases = array();

  // Exported field_base: 'field_activity_list'.
  $field_bases['field_activity_list'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_activity_list',
    'field_permissions' => array(
      'type' => 0,
    ),
    'indexes' => array(
      'tid' => array(
        0 => 'tid',
      ),
    ),
    'locked' => 0,
    'module' => 'taxonomy',
    'settings' => array(
      'allowed_values' => array(
        0 => array(
          'vocabulary' => 'activity',
          'parent' => 0,
        ),
      ),
      'entity_translation_sync' => FALSE,
      'profile2_private' => FALSE,
    ),
    'translatable' => 0,
    'type' => 'taxonomy_term_reference',
  );

  return $field_bases;
}

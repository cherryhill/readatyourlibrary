<?php
/**
 * @file
 * kids_activity_page_feature.features.field_base.inc
 */

/**
 * Implements hook_field_default_field_bases().
 */
function kids_activity_page_feature_field_default_field_bases() {
  $field_bases = array();

  // Exported field_base: 'field_add_days_of_reading'.
  $field_bases['field_add_days_of_reading'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_add_days_of_reading',
    'field_permissions' => array(
      'type' => 0,
    ),
    'indexes' => array(),
    'locked' => 0,
    'module' => 'link',
    'settings' => array(
      'attributes' => array(
        'class' => '',
        'rel' => '',
        'target' => 'default',
      ),
      'display' => array(
        'url_cutoff' => 80,
      ),
      'enable_tokens' => 1,
      'profile2_private' => FALSE,
      'title' => 'optional',
      'title_maxlength' => 128,
      'title_value' => '',
      'url' => 0,
    ),
    'translatable' => 0,
    'type' => 'link_field',
  );

  return $field_bases;
}

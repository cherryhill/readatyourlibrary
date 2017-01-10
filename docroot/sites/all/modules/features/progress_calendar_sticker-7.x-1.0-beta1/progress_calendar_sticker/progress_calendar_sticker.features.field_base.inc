<?php
/**
 * @file
 * progress_calendar_sticker.features.field_base.inc
 */

/**
 * Implements hook_field_default_field_bases().
 */
function progress_calendar_sticker_field_default_field_bases() {
  $field_bases = array();

  // Exported field_base: 'field_cal_sticker_image'.
  $field_bases['field_cal_sticker_image'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_cal_sticker_image',
    'field_permissions' => array(
      'type' => 0,
    ),
    'indexes' => array(
      'fid' => array(
        0 => 'fid',
      ),
    ),
    'locked' => 0,
    'module' => 'image',
    'settings' => array(
      'default_image' => 54,
      'entity_translation_sync' => array(
        0 => 'fid',
      ),
      'profile2_private' => FALSE,
      'uri_scheme' => 'public',
    ),
    'translatable' => 0,
    'type' => 'image',
  );

  return $field_bases;
}

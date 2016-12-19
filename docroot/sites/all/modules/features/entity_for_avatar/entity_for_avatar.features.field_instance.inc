<?php
/**
 * @file
 * entity_for_avatar.features.field_instance.inc
 */

/**
 * Implements hook_field_default_field_instances().
 */
function entity_for_avatar_field_default_field_instances() {
  $field_instances = array();

  // Exported field_instance: 'avatar-avatar-field_avatar_type'.
  $field_instances['avatar-avatar-field_avatar_type'] = array(
    'bundle' => 'avatar',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'taxonomy',
        'settings' => array(),
        'type' => 'taxonomy_term_reference_link',
        'weight' => 0,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'display_label' => '',
    'entity_type' => 'avatar',
    'field_name' => 'field_avatar_type',
    'label' => 'Avatar type',
    'required' => 0,
    'settings' => array(
      'entity_translation_sync' => FALSE,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'options',
      'settings' => array(
        'apply_chosen' => '',
      ),
      'type' => 'options_select',
      'weight' => 1,
    ),
    'workbench_access_field' => 0,
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('Avatar type');

  return $field_instances;
}

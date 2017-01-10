<?php
/**
 * @file
 * activity_calendar_sticker.features.field_instance.inc
 */

/**
 * Implements hook_field_default_field_instances().
 */
function activity_calendar_sticker_field_default_field_instances() {
  $field_instances = array();

  // Exported field_instance:
  // 'activity-activity_entry-field_calendar_sticker_id'.
  $field_instances['activity-activity_entry-field_calendar_sticker_id'] = array(
    'bundle' => 'activity_entry',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'taxonomy',
        'settings' => array(),
        'type' => 'taxonomy_term_reference_link',
        'weight' => 5,
      ),
      'full' => array(
        'label' => 'above',
        'module' => 'taxonomy',
        'settings' => array(),
        'type' => 'taxonomy_term_reference_link',
        'weight' => 5,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'display_label' => '',
    'entity_type' => 'activity',
    'field_name' => 'field_calendar_sticker_id',
    'label' => 'calendar sticker id',
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
      'weight' => 8,
    ),
    'workbench_access_field' => 0,
  );

  // Exported field_instance:
  // 'taxonomy_term-calendar_sticker-field_cal_sticker_image'.
  $field_instances['taxonomy_term-calendar_sticker-field_cal_sticker_image'] = array(
    'bundle' => 'calendar_sticker',
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'image',
        'settings' => array(
          'image_link' => '',
          'image_style' => '',
        ),
        'type' => 'image',
        'weight' => 0,
      ),
    ),
    'display_label' => '',
    'entity_type' => 'taxonomy_term',
    'field_name' => 'field_cal_sticker_image',
    'label' => 'Sticker Image',
    'required' => 0,
    'settings' => array(
      'alt_field' => 0,
      'default_image' => 0,
      'entity_translation_sync' => FALSE,
      'file_directory' => '',
      'file_extensions' => 'png gif jpg jpeg',
      'max_filesize' => '',
      'max_resolution' => '',
      'min_resolution' => '',
      'title_field' => 0,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'image',
      'settings' => array(
        'filefield_sources' => array(
          'filefield_sources' => array(
            'attach' => 0,
            'clipboard' => 0,
            'imce' => 0,
            'reference' => 0,
            'remote' => 0,
            'upload' => 'upload',
          ),
          'source_attach' => array(
            'absolute' => 0,
            'attach_mode' => 'move',
            'path' => 'file_attach',
          ),
          'source_imce' => array(
            'imce_mode' => 0,
          ),
          'source_reference' => array(
            'autocomplete' => 0,
            'search_all_fields' => 0,
          ),
        ),
        'preview_image_style' => 'thumbnail',
        'progress_indicator' => 'throbber',
      ),
      'type' => 'image_image',
      'weight' => 31,
    ),
    'workbench_access_field' => 0,
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('Sticker Image');
  t('calendar sticker id');

  return $field_instances;
}

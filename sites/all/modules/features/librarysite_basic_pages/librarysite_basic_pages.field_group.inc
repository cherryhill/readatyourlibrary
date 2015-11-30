<?php
/**
 * @file
 * librarysite_basic_pages.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function librarysite_basic_pages_field_group_info() {
  $export = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_slideshow_images|node|page|form';
  $field_group->group_name = 'group_slideshow_images';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'page';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Slideshow Images',
    'weight' => '1',
    'children' => array(
      0 => 'field_page_slideshow_image',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'Slideshow Images',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => '',
        'description' => 'Use either the Slideshow Images or Main Image field for this content. Do not use both.',
      ),
      'formatter' => 'collapsed',
    ),
  );
  $export['group_slideshow_images|node|page|form'] = $field_group;

  return $export;
}

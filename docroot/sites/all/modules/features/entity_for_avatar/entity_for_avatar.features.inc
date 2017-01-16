<?php
/**
 * @file
 * entity_for_avatar.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function entity_for_avatar_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "feeds" && $api == "feeds_importer_default") {
    return array("version" => "1");
  }
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_eck_bundle_info().
 */
function entity_for_avatar_eck_bundle_info() {
  $items = array(
    'avatar_avatar' => array(
      'machine_name' => 'avatar_avatar',
      'entity_type' => 'avatar',
      'name' => 'avatar',
      'label' => 'Avatar',
      'config' => array(),
    ),
  );
  return $items;
}

/**
 * Implements hook_eck_entity_type_info().
 */
function entity_for_avatar_eck_entity_type_info() {
  $items = array(
    'avatar' => array(
      'name' => 'avatar',
      'label' => 'Avatar',
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

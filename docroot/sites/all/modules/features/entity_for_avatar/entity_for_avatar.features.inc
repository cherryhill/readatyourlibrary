<?php
/**
 * @file
 * entity_for_avatar.features.inc
 */

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

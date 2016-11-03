<?php
/**
 * @file
 * feature_for_reward.features.inc
 */

/**
 * Implements hook_eck_bundle_info().
 */
function feature_for_reward_eck_bundle_info() {
  $items = array(
    'reward_reward' => array(
      'machine_name' => 'reward_reward',
      'entity_type' => 'reward',
      'name' => 'reward',
      'label' => 'Reward',
      'config' => array(
        'managed_properties' => array(
          'title' => 'title',
          'uid' => 0,
          'created' => 0,
        ),
      ),
    ),
  );
  return $items;
}

/**
 * Implements hook_eck_entity_type_info().
 */
function feature_for_reward_eck_entity_type_info() {
  $items = array(
    'reward' => array(
      'name' => 'reward',
      'label' => 'Reward',
      'properties' => array(
        'title' => array(
          'label' => 'Title',
          'type' => 'text',
          'behavior' => 'title',
        ),
        'uid' => array(
          'label' => 'Author',
          'type' => 'integer',
          'behavior' => 'author',
        ),
        'created' => array(
          'label' => 'Created',
          'type' => 'integer',
          'behavior' => 'created',
        ),
      ),
    ),
  );
  return $items;
}

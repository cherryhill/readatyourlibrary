<?php
/**
 * @file
 * feature_for_reward.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function feature_for_reward_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_eck_bundle_info().
 */
function feature_for_reward_eck_bundle_info() {
  $items = array(
    'reward_raffle_claim' => array(
      'machine_name' => 'reward_raffle_claim',
      'entity_type' => 'reward',
      'name' => 'raffle_claim',
      'label' => 'Raffle Entry',
      'config' => array(
        'managed_properties' => array(
          'title' => 0,
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

<?php
/**
 * @file
 * play_library_program.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function play_library_program_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "page_manager" && $api == "pages_default") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_views_api().
 */
function play_library_program_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}

/**
 * Implements hook_eck_bundle_info().
 */
function play_library_program_eck_bundle_info() {
  $items = array(
    'activity_activity' => array(
      'machine_name' => 'activity_activity',
      'entity_type' => 'activity',
      'name' => 'activity',
      'label' => 'Activity',
    ),
    'activity_activity_achievement_reward' => array(
      'machine_name' => 'activity_activity_achievement_reward',
      'entity_type' => 'activity',
      'name' => 'activity_achievement_reward',
      'label' => 'Activity Achievement Reward',
    ),
    'activity_activity_entry' => array(
      'machine_name' => 'activity_activity_entry',
      'entity_type' => 'activity',
      'name' => 'activity_entry',
      'label' => 'Activity Entry',
    ),
    'badge_badge' => array(
      'machine_name' => 'badge_badge',
      'entity_type' => 'badge',
      'name' => 'badge',
      'label' => 'Badge',
    ),
    'badge_user_badge' => array(
      'machine_name' => 'badge_user_badge',
      'entity_type' => 'badge',
      'name' => 'user_badge',
      'label' => 'User Badge',
    ),
    'raffle_raffle' => array(
      'machine_name' => 'raffle_raffle',
      'entity_type' => 'raffle',
      'name' => 'raffle',
      'label' => 'Raffle',
    ),
    'raffle_raffle_entry' => array(
      'machine_name' => 'raffle_raffle_entry',
      'entity_type' => 'raffle',
      'name' => 'raffle_entry',
      'label' => 'Raffle Entry',
    ),
    'raffle_raffle_winner' => array(
      'machine_name' => 'raffle_raffle_winner',
      'entity_type' => 'raffle',
      'name' => 'raffle_winner',
      'label' => 'Raffle Winner',
    ),
    'reward_point_driven_reward' => array(
      'machine_name' => 'reward_point_driven_reward',
      'entity_type' => 'reward',
      'name' => 'point_driven_reward',
      'label' => 'Point Driven Reward',
    ),
    'reward_reward' => array(
      'machine_name' => 'reward_reward',
      'entity_type' => 'reward',
      'name' => 'reward',
      'label' => 'Reward',
    ),
    'reward_reward_claim' => array(
      'machine_name' => 'reward_reward_claim',
      'entity_type' => 'reward',
      'name' => 'reward_claim',
      'label' => 'Reward Claim',
    ),
    'reward_reward_criteria' => array(
      'machine_name' => 'reward_reward_criteria',
      'entity_type' => 'reward',
      'name' => 'reward_criteria',
      'label' => 'Reward Criteria',
    ),
  );
  return $items;
}

/**
 * Implements hook_eck_entity_type_info().
 */
function play_library_program_eck_entity_type_info() {
  $items = array(
    'activity' => array(
      'name' => 'activity',
      'label' => 'Activity',
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
    'badge' => array(
      'name' => 'badge',
      'label' => 'Badge',
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
    'raffle' => array(
      'name' => 'raffle',
      'label' => 'Raffle',
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

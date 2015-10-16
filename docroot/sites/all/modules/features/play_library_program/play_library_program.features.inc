<?php
/**
 * @file
 * play_library_program.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function play_library_program_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "ds" && $api == "ds") {
    return array("version" => "1");
  }
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

/**
 * Implements hook_flag_default_flags().
 */
function play_library_program_flag_default_flags() {
  $flags = array();
  // Exported flag: "Reward Claimed".
  $flags['reward_claimed'] = array(
    'entity_type' => 'reward',
    'title' => 'Reward Claimed',
    'global' => 1,
    'types' => array(
      0 => 'reward_claim',
    ),
    'flag_short' => 'Reward not yet claimed',
    'flag_long' => 'Click to claim reward',
    'flag_message' => 'Reward has been claimed by user',
    'unflag_short' => 'Reward Claimed',
    'unflag_long' => 'Click to unclaim reward',
    'unflag_message' => 'Reward not claimed by user',
    'unflag_denied_text' => '',
    'link_type' => 'toggle',
    'weight' => 0,
    'show_in_links' => array(
      'full' => 0,
      'teaser' => 0,
      'diff_standard' => 0,
      'token' => 0,
    ),
    'show_as_field' => 1,
    'show_on_form' => 0,
    'access_author' => '',
    'show_contextual_link' => 0,
    'module' => 'play_library_program',
    'locked' => array(
      0 => 'name',
    ),
    'api_version' => 3,
  );
  return $flags;

}

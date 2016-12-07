<?php
/**
 * @file
 * blocks_for_patron_dashboard_kids.features.inc
 */

/**
 * Implements hook_views_api().
 */
function blocks_for_patron_dashboard_kids_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}

/**
 * Implements hook_flag_default_flags().
 */
function blocks_for_patron_dashboard_kids_flag_default_flags() {
  $flags = array();
  // Exported flag: "Follow".
  $flags['follow'] = array(
    'entity_type' => 'user',
    'title' => 'Follow',
    'global' => 0,
    'types' => array(),
    'flag_short' => 'Follow [user:name]',
    'flag_long' => 'Following a user will enable you to easily see new reviews and booklists from this individual.',
    'flag_message' => 'You are now following [user:name].',
    'unflag_short' => 'Unfollow [user:name]',
    'unflag_long' => 'Click this if you no longer want to see updates from this individual.',
    'unflag_message' => 'You are no longer following [user:name].',
    'unflag_denied_text' => '',
    'link_type' => 'normal',
    'weight' => 0,
    'show_in_links' => array(
      'token' => 'token',
      'full' => 0,
      'diff_standard' => 0,
    ),
    'show_as_field' => 1,
    'show_on_form' => 0,
    'access_author' => '',
    'show_contextual_link' => 0,
    'show_on_profile' => 1,
    'access_uid' => 'others',
    'api_version' => 3,
    'module' => 'blocks_for_patron_dashboard_kids',
    'locked' => array(
      0 => 'name',
    ),
  );
  // Exported flag: "Like".
  $flags['like'] = array(
    'entity_type' => 'node',
    'title' => 'Like',
    'global' => 0,
    'types' => array(
      0 => 'review_book',
      1 => 'booklist',
    ),
    'flag_short' => 'Like',
    'flag_long' => '',
    'flag_message' => '',
    'unflag_short' => 'Unlike',
    'unflag_long' => '',
    'unflag_message' => '',
    'unflag_denied_text' => '',
    'link_type' => 'toggle',
    'weight' => 0,
    'show_in_links' => array(
      'full' => 'full',
      'teaser' => 'teaser',
      'rss' => 0,
      'search_index' => 0,
      'search_result' => 0,
      'diff_standard' => 0,
      'token' => 0,
      'revision' => 0,
    ),
    'show_as_field' => 0,
    'show_on_form' => 0,
    'access_author' => '',
    'show_contextual_link' => 0,
    'i18n' => 0,
    'api_version' => 3,
    'module' => 'blocks_for_patron_dashboard_kids',
    'locked' => array(
      0 => 'name',
    ),
  );
  return $flags;

}

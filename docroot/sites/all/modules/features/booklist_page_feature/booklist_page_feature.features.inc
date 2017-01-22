<?php
/**
 * @file
 * booklist_page_feature.features.inc
 */

/**
 * Implements hook_views_api().
 */
function booklist_page_feature_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}

/**
 * Implements hook_flag_default_flags().
 */
function booklist_page_feature_flag_default_flags() {
  $flags = array();
  // Exported flag: "Primary Booklist".
  $flags['primary_booklist'] = array(
    'entity_type' => 'node',
    'title' => 'Primary Booklist',
    'global' => 0,
    'types' => array(
      0 => 'booklist',
    ),
    'flag_short' => 'Make this the primary booklist for the program',
    'flag_long' => 'This will cause the booklist to display on the program landing page.',
    'flag_message' => 'You have made this the primary booklist for this program.',
    'unflag_short' => 'Remove the primary setting from this booklist',
    'unflag_long' => 'This will cause the booklist to no longer display on the program landing page.',
    'unflag_message' => 'This booklist will no longer display on the landing page for this program.',
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
    'show_as_field' => 1,
    'show_on_form' => 1,
    'access_author' => '',
    'show_contextual_link' => 1,
    'i18n' => 0,
    'api_version' => 3,
    'module' => 'booklist_page_feature',
    'locked' => array(
      0 => 'name',
    ),
  );
  return $flags;

}

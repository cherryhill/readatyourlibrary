<?php
/**
 * @file
 * Implements the display extender to add rows merging.
 */

/**
 * Implements hook_views_plugins().
 */
function views_merge_rows_views_plugins() {
  $path = drupal_get_path('module', 'views_merge_rows');
  $plugins = array();
  $plugins['display_extender']['views_merge_rows'] = array(
    'title' => t('Merge rows'),
    'help' => t('Merges rows with the same values in the specified fields.'),
    'path' => $path,
    'handler' => 'views_merge_rows_plugin_display_extender',
  );
  return $plugins;
}

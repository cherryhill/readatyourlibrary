<?php
/**
 * @file
 * feature_for_activity_page.features.fe_block_settings.inc
 */

/**
 * Implements hook_default_fe_block_settings().
 */
function feature_for_activity_page_default_fe_block_settings() {
  $export = array();

  $export['version'] = '2.0';

  $export['block-create_your_own_booklist_activit'] = array(
    'cache' => -1,
    'css_class' => '',
    'custom' => 0,
    'i18n_block_language' => array(),
    'i18n_mode' => 0,
    'machine_name' => 'create_your_own_booklist_activit',
    'module' => 'block',
    'node_types' => array(),
    'pages' => 'activities',
    'roles' => array(
      'authenticated user' => 2,
    ),
    'themes' => array(
      'kids_programme' => array(
        'region' => 'content',
        'status' => 1,
        'theme' => 'kids_programme',
        'weight' => 0,
      ),
      'seven' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'seven',
        'weight' => 0,
      ),
    ),
    'title' => 'Create your own booklist',
    'visibility' => 1,
  );

  $export['block-program_dashboard_for_staff'] = array(
    'cache' => -1,
    'css_class' => '',
    'custom' => 0,
    'i18n_block_language' => array(),
    'i18n_mode' => 0,
    'machine_name' => 'program_dashboard_for_staff',
    'module' => 'block',
    'node_types' => array(),
    'pages' => '<front>',
    'roles' => array(
      'Lead Staff' => 7,
      'Overall Administrator' => 3,
      'Program administrator' => 8,
      'Staff' => 6,
    ),
    'themes' => array(
      'kids_programme' => array(
        'region' => 'content',
        'status' => 1,
        'theme' => 'kids_programme',
        'weight' => 0,
      ),
      'seven' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'seven',
        'weight' => 0,
      ),
    ),
    'title' => '<none>',
    'visibility' => 0,
  );

  $export['block-progress_myactivity_block'] = array(
    'cache' => -1,
    'css_class' => '',
    'custom' => 0,
    'i18n_block_language' => array(),
    'i18n_mode' => 0,
    'machine_name' => 'progress_myactivity_block',
    'module' => 'block',
    'node_types' => array(),
    'pages' => 'activities',
    'roles' => array(
      'authenticated user' => 2,
    ),
    'themes' => array(
      'kids_programme' => array(
        'region' => 'sidebar_first',
        'status' => 1,
        'theme' => 'kids_programme',
        'weight' => 0,
      ),
      'seven' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'seven',
        'weight' => 0,
      ),
    ),
    'title' => 'My Activities',
    'visibility' => 1,
  );

  $export['block-write_your_own_review_activity'] = array(
    'cache' => -1,
    'css_class' => '',
    'custom' => 0,
    'i18n_block_language' => array(),
    'i18n_mode' => 0,
    'machine_name' => 'write_your_own_review_activity',
    'module' => 'block',
    'node_types' => array(),
    'pages' => 'activities',
    'roles' => array(
      'authenticated user' => 2,
    ),
    'themes' => array(
      'kids_programme' => array(
        'region' => 'content',
        'status' => 1,
        'theme' => 'kids_programme',
        'weight' => 0,
      ),
      'seven' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'seven',
        'weight' => 0,
      ),
    ),
    'title' => 'Write your own review',
    'visibility' => 1,
  );

  return $export;
}

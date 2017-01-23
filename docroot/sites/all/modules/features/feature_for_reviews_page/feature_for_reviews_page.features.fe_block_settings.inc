<?php
/**
 * @file
 * feature_for_reviews_page.features.fe_block_settings.inc
 */

/**
 * Implements hook_default_fe_block_settings().
 */
function feature_for_reviews_page_default_fe_block_settings() {
  $export = array();

  $export['version'] = '2.0';

  $export['block-write_your_own_review_reviews_pa'] = array(
    'cache' => -1,
    'css_class' => '',
    'custom' => 0,
    'i18n_block_language' => array(),
    'i18n_mode' => 0,
    'machine_name' => 'write_your_own_review_reviews_pa',
    'module' => 'block',
    'node_types' => array(),
    'pages' => 'reviews',
    'roles' => array(),
    'themes' => array(
      'kids_programme' => array(
        'region' => 'sidebar_activity',
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
    'title' => 'Write Your Own Review!',
    'visibility' => 1,
  );

  return $export;
}

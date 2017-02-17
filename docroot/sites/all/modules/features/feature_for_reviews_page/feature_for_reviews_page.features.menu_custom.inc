<?php
/**
 * @file
 * feature_for_reviews_page.features.menu_custom.inc
 */

/**
 * Implements hook_menu_default_menu_custom().
 */
function feature_for_reviews_page_menu_default_menu_custom() {
  $menus = array();

  // Exported menu: menu-reviews-menu-for-reviews-pa.
  $menus['menu-reviews-menu-for-reviews-pa'] = array(
    'menu_name' => 'menu-reviews-menu-for-reviews-pa',
    'title' => 'Reviews menu for reviews page',
    'description' => 'This menu is used for book reviews left side bar.',
    'language' => 'und',
    'i18n_mode' => 5,
  );
  // Translatables
  // Included for use with string extractors like potx.
  t('Reviews menu for reviews page');
  t('This menu is used for book reviews left side bar.');

  return $menus;
}

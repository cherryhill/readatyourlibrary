<?php
/**
 * @file
 * book_reviews_page_sidebar_menu_for_teen.features.menu_custom.inc
 */

/**
 * Implements hook_menu_default_menu_custom().
 */
function book_reviews_page_sidebar_menu_for_teen_menu_default_menu_custom() {
  $menus = array();

  // Exported menu: menu-book-reviews-sidebar-menu-f.
  $menus['menu-book-reviews-sidebar-menu-f'] = array(
    'menu_name' => 'menu-book-reviews-sidebar-menu-f',
    'title' => 'Book reviews sidebar menu for teens',
    'description' => 'This menu is used for book reviews sidebar menu.',
    'language' => 'und',
    'i18n_mode' => 5,
  );
  // Translatables
  // Included for use with string extractors like potx.
  t('Book reviews sidebar menu for teens');
  t('This menu is used for book reviews sidebar menu.');

  return $menus;
}

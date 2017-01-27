<?php
/**
 * @file
 * book_reviews_page_sidebar_menu_for_teen.features.menu_links.inc
 */

/**
 * Implements hook_menu_default_menu_links().
 */
function book_reviews_page_sidebar_menu_for_teen_menu_default_menu_links() {
  $menu_links = array();

  // Exported menu link: menu-book-reviews-sidebar-menu-f_activity-reviews:<front>.
  $menu_links['menu-book-reviews-sidebar-menu-f_activity-reviews:<front>'] = array(
    'menu_name' => 'menu-book-reviews-sidebar-menu-f',
    'link_path' => '<front>',
    'router_path' => '',
    'link_title' => 'Activity Reviews',
    'options' => array(
      'attributes' => array(),
      'item_attributes' => array(
        'id' => '',
        'class' => '',
        'style' => '',
      ),
      'alter' => TRUE,
      'identifier' => 'menu-book-reviews-sidebar-menu-f_activity-reviews:<front>',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 1,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 0,
    'customized' => 1,
    'language' => 'und',
    'menu_links_customized' => 1,
  );
  // Exported menu link: menu-book-reviews-sidebar-menu-f_book-reviews:reviews.
  $menu_links['menu-book-reviews-sidebar-menu-f_book-reviews:reviews'] = array(
    'menu_name' => 'menu-book-reviews-sidebar-menu-f',
    'link_path' => 'reviews',
    'router_path' => 'reviews',
    'link_title' => 'Book Reviews',
    'options' => array(
      'attributes' => array(),
      'item_attributes' => array(
        'id' => '',
        'class' => '',
        'style' => '',
      ),
      'alter' => TRUE,
      'identifier' => 'menu-book-reviews-sidebar-menu-f_book-reviews:reviews',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 0,
    'customized' => 1,
    'language' => 'und',
    'menu_links_customized' => 1,
  );
  // Exported menu link: menu-book-reviews-sidebar-menu-f_booklists:booklists.
  $menu_links['menu-book-reviews-sidebar-menu-f_booklists:booklists'] = array(
    'menu_name' => 'menu-book-reviews-sidebar-menu-f',
    'link_path' => 'booklists',
    'router_path' => 'booklists',
    'link_title' => 'Booklists',
    'options' => array(
      'attributes' => array(),
      'item_attributes' => array(
        'id' => '',
        'class' => '',
        'style' => '',
      ),
      'alter' => TRUE,
      'identifier' => 'menu-book-reviews-sidebar-menu-f_booklists:booklists',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 0,
    'customized' => 1,
    'language' => 'und',
    'menu_links_customized' => 1,
  );
  // Exported menu link: menu-book-reviews-sidebar-menu-f_movie-reviews:movie-review.
  $menu_links['menu-book-reviews-sidebar-menu-f_movie-reviews:movie-review'] = array(
    'menu_name' => 'menu-book-reviews-sidebar-menu-f',
    'link_path' => 'movie-review',
    'router_path' => 'movie-review',
    'link_title' => 'Movie Reviews',
    'options' => array(
      'attributes' => array(),
      'item_attributes' => array(
        'id' => '',
        'class' => '',
        'style' => '',
      ),
      'alter' => TRUE,
      'identifier' => 'menu-book-reviews-sidebar-menu-f_movie-reviews:movie-review',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 0,
    'customized' => 1,
    'language' => 'und',
    'menu_links_customized' => 1,
  );
  // Exported menu link: menu-book-reviews-sidebar-menu-f_music-reviews:music-review-listing.
  $menu_links['menu-book-reviews-sidebar-menu-f_music-reviews:music-review-listing'] = array(
    'menu_name' => 'menu-book-reviews-sidebar-menu-f',
    'link_path' => 'music-review-listing',
    'router_path' => 'music-review-listing',
    'link_title' => 'Music Reviews',
    'options' => array(
      'alter' => TRUE,
      'attributes' => array(),
      'item_attributes' => array(
        'id' => '',
        'class' => '',
        'style' => '',
      ),
      'identifier' => 'menu-book-reviews-sidebar-menu-f_music-reviews:music-review-listing',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 0,
    'customized' => 1,
    'language' => 'und',
    'menu_links_customized' => 1,
  );
  // Exported menu link: menu-book-reviews-sidebar-menu-f_video-game-reviews:video-game-review.
  $menu_links['menu-book-reviews-sidebar-menu-f_video-game-reviews:video-game-review'] = array(
    'menu_name' => 'menu-book-reviews-sidebar-menu-f',
    'link_path' => 'video-game-review',
    'router_path' => 'video-game-review',
    'link_title' => 'Video Game Reviews',
    'options' => array(
      'alter' => TRUE,
      'attributes' => array(),
      'item_attributes' => array(
        'id' => '',
        'class' => '',
        'style' => '',
      ),
      'identifier' => 'menu-book-reviews-sidebar-menu-f_video-game-reviews:video-game-review',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 0,
    'customized' => 1,
    'language' => 'und',
    'menu_links_customized' => 1,
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('Activity Reviews');
  t('Book Reviews');
  t('Booklists');
  t('Movie Reviews');
  t('Music Reviews');
  t('Video Game Reviews');

  return $menu_links;
}

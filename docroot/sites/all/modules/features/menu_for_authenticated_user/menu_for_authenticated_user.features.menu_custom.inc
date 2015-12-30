<?php
/**
 * @file
 * menu_for_authenticated_user.features.menu_custom.inc
 */

/**
 * Implements hook_menu_default_menu_custom().
 */
function menu_for_authenticated_user_menu_default_menu_custom() {
  $menus = array();

  // Exported menu: menu-secoundary-menu.
  $menus['menu-secoundary-menu'] = array(
    'menu_name' => 'menu-secoundary-menu',
    'title' => 'Secoundary menu',
    'description' => '',
  );
  // Translatables
  // Included for use with string extractors like potx.
  t('Secoundary menu');

  return $menus;
}

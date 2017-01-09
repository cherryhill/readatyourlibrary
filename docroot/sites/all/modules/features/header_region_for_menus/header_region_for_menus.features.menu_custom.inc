<?php
/**
 * @file
 * header_region_for_menus.features.menu_custom.inc
 */

/**
 * Implements hook_menu_default_menu_custom().
 */
function header_region_for_menus_menu_default_menu_custom() {
  $menus = array();

  // Exported menu: menu-anonymous-header-links.
  $menus['menu-anonymous-header-links'] = array(
    'menu_name' => 'menu-anonymous-header-links',
    'title' => 'Anonymous Header Links',
    'description' => '',
    'language' => 'und',
    'i18n_mode' => 0,
  );
  // Exported menu: menu-secondary-menu.
  $menus['menu-secondary-menu'] = array(
    'menu_name' => 'menu-secondary-menu',
    'title' => 'Secondary menu',
    'description' => '',
    'language' => 'und',
    'i18n_mode' => 0,
  );
  // Translatables
  // Included for use with string extractors like potx.
  t('Anonymous Header Links');
  t('Secondary menu');

  return $menus;
}

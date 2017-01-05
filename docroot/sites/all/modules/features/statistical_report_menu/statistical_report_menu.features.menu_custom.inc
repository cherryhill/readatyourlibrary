<?php
/**
 * @file
 * statistical_report_menu.features.menu_custom.inc
 */

/**
 * Implements hook_menu_default_menu_custom().
 */
function statistical_report_menu_menu_default_menu_custom() {
  $menus = array();

  // Exported menu: menu-reports-for-patron-users.
  $menus['menu-reports-for-patron-users'] = array(
    'menu_name' => 'menu-reports-for-patron-users',
    'title' => ' Statistical Reports',
    'description' => '',
    'language' => 'und',
    'i18n_mode' => 0,
  );
  // Translatables
  // Included for use with string extractors like potx.
  t(' Statistical Reports');

  return $menus;
}

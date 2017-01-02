<?php
/**
 * @file
 * statistical_report_menu_type.features.menu_custom.inc
 */

/**
 * Implements hook_menu_default_menu_custom().
 */
function statistical_report_menu_type_menu_default_menu_custom() {
  $menus = array();

  // Exported menu: menu-statistical-reports.
  $menus['menu-statistical-reports'] = array(
    'menu_name' => 'menu-statistical-reports',
    'title' => 'Statistical Reports',
    'description' => '',
    'language' => 'und',
    'i18n_mode' => 0,
  );
  // Translatables
  // Included for use with string extractors like potx.
  t('Statistical Reports');

  return $menus;
}

<?php
/**
 * @file
 * header_region_for_menus.features.menu_links.inc
 */

/**
 * Implements hook_menu_default_menu_links().
 */
function header_region_for_menus_menu_default_menu_links() {
  $menu_links = array();

  // Exported menu link: menu-secondary-menu_progress:progress.
  $menu_links['menu-secondary-menu_progress:progress'] = array(
    'menu_name' => 'menu-secondary-menu',
    'link_path' => 'progress',
    'router_path' => 'progress',
    'link_title' => 'Progress',
    'options' => array(
      'attributes' => array(
        'class' => array(
          0 => 'progress',
        ),
      ),
      'item_attributes' => array(
        'id' => '',
        'class' => '',
        'style' => '',
      ),
      'alter' => TRUE,
      'identifier' => 'menu-secondary-menu_progress:progress',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -50,
    'customized' => 1,
    'language' => 'und',
    'menu_links_customized' => 1,
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('Progress');

  return $menu_links;
}

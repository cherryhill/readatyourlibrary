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

  // Exported menu link: menu-anonymous-header-links_log-in:user.
  $menu_links['menu-anonymous-header-links_log-in:user'] = array(
    'menu_name' => 'menu-anonymous-header-links',
    'link_path' => 'user',
    'router_path' => 'user',
    'link_title' => 'Log In',
    'options' => array(
      'attributes' => array(),
      'item_attributes' => array(
        'id' => '',
        'class' => '',
        'style' => '',
      ),
      'alter' => TRUE,
      'identifier' => 'menu-anonymous-header-links_log-in:user',
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
  // Exported menu link: menu-anonymous-header-links_sign-up:user/register.
  $menu_links['menu-anonymous-header-links_sign-up:user/register'] = array(
    'menu_name' => 'menu-anonymous-header-links',
    'link_path' => 'user/register',
    'router_path' => 'user/register',
    'link_title' => 'Sign Up',
    'options' => array(
      'attributes' => array(),
      'item_attributes' => array(
        'id' => '',
        'class' => '',
        'style' => '',
      ),
      'alter' => TRUE,
      'identifier' => 'menu-anonymous-header-links_sign-up:user/register',
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
  t('Log In');
  t('Progress');
  t('Sign Up');

  return $menu_links;
}

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

  // Exported menu link: menu-secondary-menu_activities:<front>.
  $menu_links['menu-secondary-menu_activities:<front>'] = array(
    'menu_name' => 'menu-secondary-menu',
    'link_path' => '<front>',
    'router_path' => '',
    'link_title' => 'Activities',
    'options' => array(
      'alter' => TRUE,
      'attributes' => array(
        'class' => array(
          0 => 'activities',
        ),
      ),
      'item_attributes' => array(
        'id' => '',
        'class' => '',
        'style' => '',
      ),
      'identifier' => 'menu-secondary-menu_activities:<front>',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 1,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -49,
    'customized' => 1,
    'language' => 'und',
    'menu_links_customized' => 1,
  );
  // Exported menu link: menu-secondary-menu_current-programs:<front>.
  $menu_links['menu-secondary-menu_current-programs:<front>'] = array(
    'menu_name' => 'menu-secondary-menu',
    'link_path' => '<front>',
    'router_path' => '',
    'link_title' => 'Current Programs',
    'options' => array(
      'alter' => TRUE,
      'attributes' => array(
        'class' => array(
          0 => 'current-program',
        ),
      ),
      'item_attributes' => array(
        'id' => '',
        'class' => '',
        'style' => '',
      ),
      'identifier' => 'menu-secondary-menu_current-programs:<front>',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 1,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -44,
    'customized' => 1,
    'language' => 'und',
    'menu_links_customized' => 1,
  );
  // Exported menu link: menu-secondary-menu_events:<front>.
  $menu_links['menu-secondary-menu_events:<front>'] = array(
    'menu_name' => 'menu-secondary-menu',
    'link_path' => '<front>',
    'router_path' => '',
    'link_title' => 'Events',
    'options' => array(
      'alter' => TRUE,
      'attributes' => array(
        'class' => array(
          0 => 'events',
        ),
      ),
      'item_attributes' => array(
        'id' => '',
        'class' => '',
        'style' => '',
      ),
      'identifier' => 'menu-secondary-menu_events:<front>',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 1,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -47,
    'customized' => 1,
    'language' => 'und',
    'menu_links_customized' => 1,
  );
  // Exported menu link: menu-secondary-menu_photos--videos:<front>.
  $menu_links['menu-secondary-menu_photos--videos:<front>'] = array(
    'menu_name' => 'menu-secondary-menu',
    'link_path' => '<front>',
    'router_path' => '',
    'link_title' => 'Photos & Videos',
    'options' => array(
      'alter' => TRUE,
      'attributes' => array(
        'class' => array(
          0 => 'photos',
        ),
      ),
      'item_attributes' => array(
        'id' => '',
        'class' => '',
        'style' => '',
      ),
      'identifier' => 'menu-secondary-menu_photos--videos:<front>',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 1,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -45,
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
  // Exported menu link: menu-secondary-menu_rewards:<front>.
  $menu_links['menu-secondary-menu_rewards:<front>'] = array(
    'menu_name' => 'menu-secondary-menu',
    'link_path' => '<front>',
    'router_path' => '',
    'link_title' => 'Rewards',
    'options' => array(
      'alter' => TRUE,
      'attributes' => array(
        'class' => array(
          0 => 'rewards',
        ),
      ),
      'item_attributes' => array(
        'id' => '',
        'class' => '',
        'style' => '',
      ),
      'identifier' => 'menu-secondary-menu_rewards:<front>',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 1,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -48,
    'customized' => 1,
    'language' => 'und',
    'menu_links_customized' => 1,
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('Activities');
  t('Current Programs');
  t('Events');
  t('Photos & Videos');
  t('Progress');
  t('Rewards');

  return $menu_links;
}

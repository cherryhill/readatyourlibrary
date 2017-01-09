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
  // Exported menu link: menu-secondary-menu_reviews-and-booklist:<front>.
  $menu_links['menu-secondary-menu_reviews-and-booklist:<front>'] = array(
    'menu_name' => 'menu-secondary-menu',
    'link_path' => '<front>',
    'router_path' => '',
    'link_title' => 'Reviews and Booklist',
    'options' => array(
      'alter' => TRUE,
      'attributes' => array(
        'class' => array(
          0 => 'reviews',
        ),
      ),
      'item_attributes' => array(
        'id' => '',
        'class' => '',
        'style' => '',
      ),
      'identifier' => 'menu-secondary-menu_reviews-and-booklist:<front>',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 1,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -46,
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
  // Exported menu link: menu-social-sharing-icons_facebook:https://www.facebook.com.
  $menu_links['menu-social-sharing-icons_facebook:https://www.facebook.com'] = array(
    'menu_name' => 'menu-social-sharing-icons',
    'link_path' => 'https://www.facebook.com',
    'router_path' => '',
    'link_title' => 'Facebook',
    'options' => array(
      'attributes' => array(
        'class' => array(
          0 => 'fb',
        ),
      ),
      'item_attributes' => array(
        'id' => '',
        'class' => '',
        'style' => '',
      ),
      'alter' => TRUE,
      'identifier' => 'menu-social-sharing-icons_facebook:https://www.facebook.com',
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
  // Exported menu link: menu-social-sharing-icons_pintrest:<front>.
  $menu_links['menu-social-sharing-icons_pintrest:<front>'] = array(
    'menu_name' => 'menu-social-sharing-icons',
    'link_path' => '<front>',
    'router_path' => '',
    'link_title' => 'Pintrest',
    'options' => array(
      'attributes' => array(
        'class' => array(
          0 => 'pntrst',
        ),
      ),
      'item_attributes' => array(
        'id' => '',
        'class' => '',
        'style' => '',
      ),
      'alter' => TRUE,
      'identifier' => 'menu-social-sharing-icons_pintrest:<front>',
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
  // Exported menu link: menu-social-sharing-icons_tumbler:<front>.
  $menu_links['menu-social-sharing-icons_tumbler:<front>'] = array(
    'menu_name' => 'menu-social-sharing-icons',
    'link_path' => '<front>',
    'router_path' => '',
    'link_title' => 'Tumbler',
    'options' => array(
      'attributes' => array(
        'class' => array(
          0 => 'tmblr',
        ),
      ),
      'item_attributes' => array(
        'id' => '',
        'class' => '',
        'style' => '',
      ),
      'alter' => TRUE,
      'identifier' => 'menu-social-sharing-icons_tumbler:<front>',
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
  // Exported menu link: menu-social-sharing-icons_twitter:<front>.
  $menu_links['menu-social-sharing-icons_twitter:<front>'] = array(
    'menu_name' => 'menu-social-sharing-icons',
    'link_path' => '<front>',
    'router_path' => '',
    'link_title' => 'Twitter',
    'options' => array(
      'attributes' => array(
        'class' => array(
          0 => 'twit',
        ),
      ),
      'item_attributes' => array(
        'id' => '',
        'class' => '',
        'style' => '',
      ),
      'alter' => TRUE,
      'identifier' => 'menu-social-sharing-icons_twitter:<front>',
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
  // Exported menu link: navigation_users-by-points:userpoints.
  $menu_links['navigation_users-by-points:userpoints'] = array(
    'menu_name' => 'navigation',
    'link_path' => 'userpoints',
    'router_path' => 'userpoints',
    'link_title' => 'Users by !points',
    'options' => array(
      'alter' => TRUE,
      'identifier' => 'navigation_users-by-points:userpoints',
    ),
    'module' => 'system',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => 0,
    'customized' => 0,
    'language' => 'und',
    'menu_links_customized' => 0,
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('Activities');
  t('Current Programs');
  t('Events');
  t('Facebook');
  t('Photos & Videos');
  t('Pintrest');
  t('Progress');
  t('Reviews and Booklist');
  t('Rewards');
  t('Tumbler');
  t('Twitter');
  t('Users by !points');

  return $menu_links;
}

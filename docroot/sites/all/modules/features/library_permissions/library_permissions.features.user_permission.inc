<?php
/**
 * @file
 * library_permissions.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function library_permissions_user_default_permissions() {
  $permissions = array();

  // Exported permission: 'access administration menu'.
  $permissions['access administration menu'] = array(
    'name' => 'access administration menu',
    'roles' => array(
      'Lead Staff' => 'Lead Staff',
      'Overall Administrator' => 'Overall Administrator',
      'Program administrator' => 'Program administrator',
      'Staff' => 'Staff',
    ),
    'module' => 'admin_menu',
  );

  // Exported permission: 'access administration pages'.
  $permissions['access administration pages'] = array(
    'name' => 'access administration pages',
    'roles' => array(
      'Overall Administrator' => 'Overall Administrator',
      'Program administrator' => 'Program administrator',
    ),
    'module' => 'system',
  );

  // Exported permission: 'access all views'.
  $permissions['access all views'] = array(
    'name' => 'access all views',
    'roles' => array(
      'Overall Administrator' => 'Overall Administrator',
    ),
    'module' => 'views',
  );

  // Exported permission: 'access all webform results'.
  $permissions['access all webform results'] = array(
    'name' => 'access all webform results',
    'roles' => array(
      'Lead Staff' => 'Lead Staff',
      'Overall Administrator' => 'Overall Administrator',
      'Program administrator' => 'Program administrator',
    ),
    'module' => 'webform',
  );

  // Exported permission: 'access backup and migrate'.
  $permissions['access backup and migrate'] = array(
    'name' => 'access backup and migrate',
    'roles' => array(
      'Overall Administrator' => 'Overall Administrator',
    ),
    'module' => 'backup_migrate',
  );

  // Exported permission: 'access backup files'.
  $permissions['access backup files'] = array(
    'name' => 'access backup files',
    'roles' => array(
      'Overall Administrator' => 'Overall Administrator',
    ),
    'module' => 'backup_migrate',
  );

  // Exported permission: 'access content'.
  $permissions['access content'] = array(
    'name' => 'access content',
    'roles' => array(
      'Overall Administrator' => 'Overall Administrator',
      'Program administrator' => 'Program administrator',
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'node',
  );

  // Exported permission: 'access content overview'.
  $permissions['access content overview'] = array(
    'name' => 'access content overview',
    'roles' => array(
      'Lead Staff' => 'Lead Staff',
      'Overall Administrator' => 'Overall Administrator',
      'Program administrator' => 'Program administrator',
      'Staff' => 'Staff',
    ),
    'module' => 'node',
  );

  // Exported permission: 'access contextual links'.
  $permissions['access contextual links'] = array(
    'name' => 'access contextual links',
    'roles' => array(
      'Overall Administrator' => 'Overall Administrator',
    ),
    'module' => 'contextual',
  );

  // Exported permission: 'access dashboard'.
  $permissions['access dashboard'] = array(
    'name' => 'access dashboard',
    'roles' => array(
      'Overall Administrator' => 'Overall Administrator',
    ),
    'module' => 'dashboard',
  );

  // Exported permission: 'access environment indicator'.
  $permissions['access environment indicator'] = array(
    'name' => 'access environment indicator',
    'roles' => array(
      'Overall Administrator' => 'Overall Administrator',
    ),
    'module' => 'environment_indicator',
  );

  // Exported permission: 'access environment indicator default_environment'.
  $permissions['access environment indicator default_environment'] = array(
    'name' => 'access environment indicator default_environment',
    'roles' => array(
      'Overall Administrator' => 'Overall Administrator',
    ),
    'module' => 'environment_indicator',
  );

  // Exported permission: 'access environment indicator overwritten_environment'.
  $permissions['access environment indicator overwritten_environment'] = array(
    'name' => 'access environment indicator overwritten_environment',
    'roles' => array(
      'Overall Administrator' => 'Overall Administrator',
    ),
    'module' => 'environment_indicator',
  );

  // Exported permission: 'access flood unblock'.
  $permissions['access flood unblock'] = array(
    'name' => 'access flood unblock',
    'roles' => array(
      'Overall Administrator' => 'Overall Administrator',
    ),
    'module' => 'flood_unblock',
  );

  // Exported permission: 'access own webform results'.
  $permissions['access own webform results'] = array(
    'name' => 'access own webform results',
    'roles' => array(
      'Overall Administrator' => 'Overall Administrator',
      'Program administrator' => 'Program administrator',
    ),
    'module' => 'webform',
  );

  // Exported permission: 'access own webform submissions'.
  $permissions['access own webform submissions'] = array(
    'name' => 'access own webform submissions',
    'roles' => array(
      'Overall Administrator' => 'Overall Administrator',
      'Program administrator' => 'Program administrator',
    ),
    'module' => 'webform',
  );

  // Exported permission: 'access private fields'.
  $permissions['access private fields'] = array(
    'name' => 'access private fields',
    'roles' => array(
      'Overall Administrator' => 'Overall Administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'access rules debug'.
  $permissions['access rules debug'] = array(
    'name' => 'access rules debug',
    'roles' => array(
      'Overall Administrator' => 'Overall Administrator',
    ),
    'module' => 'rules',
  );

  // Exported permission: 'access site in maintenance mode'.
  $permissions['access site in maintenance mode'] = array(
    'name' => 'access site in maintenance mode',
    'roles' => array(
      'Overall Administrator' => 'Overall Administrator',
    ),
    'module' => 'system',
  );

  // Exported permission: 'access site reports'.
  $permissions['access site reports'] = array(
    'name' => 'access site reports',
    'roles' => array(
      'Overall Administrator' => 'Overall Administrator',
    ),
    'module' => 'system',
  );

  // Exported permission: 'access site-wide contact form'.
  $permissions['access site-wide contact form'] = array(
    'name' => 'access site-wide contact form',
    'roles' => array(
      'Overall Administrator' => 'Overall Administrator',
    ),
    'module' => 'contact',
  );

  // Exported permission: 'access user contact forms'.
  $permissions['access user contact forms'] = array(
    'name' => 'access user contact forms',
    'roles' => array(
      'Overall Administrator' => 'Overall Administrator',
    ),
    'module' => 'contact',
  );

  // Exported permission: 'access user profiles'.
  $permissions['access user profiles'] = array(
    'name' => 'access user profiles',
    'roles' => array(
      'Overall Administrator' => 'Overall Administrator',
      'Program administrator' => 'Program administrator',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'user',
  );

  // Exported permission: 'access users overview'.
  $permissions['access users overview'] = array(
    'name' => 'access users overview',
    'roles' => array(
      'Lead Staff' => 'Lead Staff',
      'Overall Administrator' => 'Overall Administrator',
      'Program administrator' => 'Program administrator',
      'Staff' => 'Staff',
    ),
    'module' => 'administerusersbyrole',
  );

  // Exported permission: 'access workbench'.
  $permissions['access workbench'] = array(
    'name' => 'access workbench',
    'roles' => array(
      'Lead Staff' => 'Lead Staff',
      'Overall Administrator' => 'Overall Administrator',
      'Program administrator' => 'Program administrator',
      'Staff' => 'Staff',
    ),
    'module' => 'workbench',
  );

  // Exported permission: 'access workbench access by role'.
  $permissions['access workbench access by role'] = array(
    'name' => 'access workbench access by role',
    'roles' => array(
      'Overall Administrator' => 'Overall Administrator',
      'Program administrator' => 'Program administrator',
    ),
    'module' => 'workbench_access',
  );

  // Exported permission: 'activity record access'.
  $permissions['activity record access'] = array(
    'name' => 'activity record access',
    'roles' => array(
      'Overall Administrator' => 'Overall Administrator',
      'Program administrator' => 'Program administrator',
    ),
    'module' => 'play_program_raffle',
  );

  // Exported permission: 'add media from remote sources'.
  $permissions['add media from remote sources'] = array(
    'name' => 'add media from remote sources',
    'roles' => array(
      'Overall Administrator' => 'Overall Administrator',
    ),
    'module' => 'media_internet',
  );

  // Exported permission: 'add userpoints'.
  $permissions['add userpoints'] = array(
    'name' => 'add userpoints',
    'roles' => array(
      'Overall Administrator' => 'Overall Administrator',
    ),
    'module' => 'userpoints',
  );

  // Exported permission: 'admin_classes'.
  $permissions['admin_classes'] = array(
    'name' => 'admin_classes',
    'roles' => array(
      'Overall Administrator' => 'Overall Administrator',
    ),
    'module' => 'ds_ui',
  );

  // Exported permission: 'admin_display_suite'.
  $permissions['admin_display_suite'] = array(
    'name' => 'admin_display_suite',
    'roles' => array(
      'Overall Administrator' => 'Overall Administrator',
    ),
    'module' => 'ds',
  );

  // Exported permission: 'admin_fields'.
  $permissions['admin_fields'] = array(
    'name' => 'admin_fields',
    'roles' => array(
      'Overall Administrator' => 'Overall Administrator',
    ),
    'module' => 'ds_ui',
  );

  // Exported permission: 'admin_view_modes'.
  $permissions['admin_view_modes'] = array(
    'name' => 'admin_view_modes',
    'roles' => array(
      'Overall Administrator' => 'Overall Administrator',
    ),
    'module' => 'ds_ui',
  );

  // Exported permission: 'administer @font-your-face'.
  $permissions['administer @font-your-face'] = array(
    'name' => 'administer @font-your-face',
    'roles' => array(
      'Overall Administrator' => 'Overall Administrator',
    ),
    'module' => 'fontyourface',
  );

  // Exported permission: 'administer actions'.
  $permissions['administer actions'] = array(
    'name' => 'administer actions',
    'roles' => array(
      'Overall Administrator' => 'Overall Administrator',
    ),
    'module' => 'system',
  );

  // Exported permission: 'administer add another'.
  $permissions['administer add another'] = array(
    'name' => 'administer add another',
    'roles' => array(
      'Overall Administrator' => 'Overall Administrator',
      'Program administrator' => 'Program administrator',
    ),
    'module' => 'addanother',
  );

  // Exported permission: 'administer addressfield staticmap'.
  $permissions['administer addressfield staticmap'] = array(
    'name' => 'administer addressfield staticmap',
    'roles' => array(
      'Overall Administrator' => 'Overall Administrator',
    ),
    'module' => 'addressfield_staticmap',
  );

  // Exported permission: 'administer addthis'.
  $permissions['administer addthis'] = array(
    'name' => 'administer addthis',
    'roles' => array(
      'Overall Administrator' => 'Overall Administrator',
    ),
    'module' => 'addthis',
  );

  // Exported permission: 'administer advanced addthis'.
  $permissions['administer advanced addthis'] = array(
    'name' => 'administer advanced addthis',
    'roles' => array(
      'Overall Administrator' => 'Overall Administrator',
    ),
    'module' => 'addthis',
  );

  // Exported permission: 'administer advanced pane settings'.
  $permissions['administer advanced pane settings'] = array(
    'name' => 'administer advanced pane settings',
    'roles' => array(
      'Overall Administrator' => 'Overall Administrator',
    ),
    'module' => 'panels',
  );

  // Exported permission: 'administer autoassignrole'.
  $permissions['administer autoassignrole'] = array(
    'name' => 'administer autoassignrole',
    'roles' => array(
      'Overall Administrator' => 'Overall Administrator',
    ),
    'module' => 'autoassignrole',
  );

  // Exported permission: 'administer backup and migrate'.
  $permissions['administer backup and migrate'] = array(
    'name' => 'administer backup and migrate',
    'roles' => array(
      'Overall Administrator' => 'Overall Administrator',
    ),
    'module' => 'backup_migrate',
  );

  // Exported permission: 'administer block classes'.
  $permissions['administer block classes'] = array(
    'name' => 'administer block classes',
    'roles' => array(
      'Overall Administrator' => 'Overall Administrator',
    ),
    'module' => 'block_class',
  );

  // Exported permission: 'administer blocks'.
  $permissions['administer blocks'] = array(
    'name' => 'administer blocks',
    'roles' => array(
      'Overall Administrator' => 'Overall Administrator',
      'Program administrator' => 'Program administrator',
    ),
    'module' => 'block',
  );

  // Exported permission: 'administer contact forms'.
  $permissions['administer contact forms'] = array(
    'name' => 'administer contact forms',
    'roles' => array(
      'Overall Administrator' => 'Overall Administrator',
    ),
    'module' => 'contact',
  );

  // Exported permission: 'administer content translations'.
  $permissions['administer content translations'] = array(
    'name' => 'administer content translations',
    'roles' => array(
      'Overall Administrator' => 'Overall Administrator',
    ),
    'module' => 'i18n_node',
  );

  // Exported permission: 'administer content types'.
  $permissions['administer content types'] = array(
    'name' => 'administer content types',
    'roles' => array(
      'Overall Administrator' => 'Overall Administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'administer custom content'.
  $permissions['administer custom content'] = array(
    'name' => 'administer custom content',
    'roles' => array(
      'Overall Administrator' => 'Overall Administrator',
    ),
    'module' => 'ctools_custom_content',
  );

  // Exported permission: 'administer dependencies'.
  $permissions['administer dependencies'] = array(
    'name' => 'administer dependencies',
    'roles' => array(
      'Overall Administrator' => 'Overall Administrator',
    ),
    'module' => 'conditional_fields',
  );

  // Exported permission: 'administer display cache'.
  $permissions['administer display cache'] = array(
    'name' => 'administer display cache',
    'roles' => array(
      'Overall Administrator' => 'Overall Administrator',
    ),
    'module' => 'display_cache',
  );

  // Exported permission: 'administer entity cache loader'.
  $permissions['administer entity cache loader'] = array(
    'name' => 'administer entity cache loader',
    'roles' => array(
      'Overall Administrator' => 'Overall Administrator',
    ),
    'module' => 'ecl',
  );

  // Exported permission: 'administer entity translation'.
  $permissions['administer entity translation'] = array(
    'name' => 'administer entity translation',
    'roles' => array(
      'Overall Administrator' => 'Overall Administrator',
    ),
    'module' => 'entity_translation',
  );

  // Exported permission: 'administer entityqueue'.
  $permissions['administer entityqueue'] = array(
    'name' => 'administer entityqueue',
    'roles' => array(
      'Overall Administrator' => 'Overall Administrator',
    ),
    'module' => 'entityqueue',
  );

  // Exported permission: 'administer environment indicator settings'.
  $permissions['administer environment indicator settings'] = array(
    'name' => 'administer environment indicator settings',
    'roles' => array(
      'Overall Administrator' => 'Overall Administrator',
    ),
    'module' => 'environment_indicator',
  );

  // Exported permission: 'administer exclude node title'.
  $permissions['administer exclude node title'] = array(
    'name' => 'administer exclude node title',
    'roles' => array(
      'Overall Administrator' => 'Overall Administrator',
    ),
    'module' => 'exclude_node_title',
  );

  // Exported permission: 'administer facets'.
  $permissions['administer facets'] = array(
    'name' => 'administer facets',
    'roles' => array(
      'Overall Administrator' => 'Overall Administrator',
    ),
    'module' => 'facetapi',
  );

  // Exported permission: 'administer features'.
  $permissions['administer features'] = array(
    'name' => 'administer features',
    'roles' => array(
      'Overall Administrator' => 'Overall Administrator',
    ),
    'module' => 'features',
  );

  // Exported permission: 'administer feeds'.
  $permissions['administer feeds'] = array(
    'name' => 'administer feeds',
    'roles' => array(
      'Overall Administrator' => 'Overall Administrator',
    ),
    'module' => 'feeds',
  );

  // Exported permission: 'administer feeds_tamper'.
  $permissions['administer feeds_tamper'] = array(
    'name' => 'administer feeds_tamper',
    'roles' => array(
      'Overall Administrator' => 'Overall Administrator',
      'Program administrator' => 'Program administrator',
    ),
    'module' => 'feeds_tamper',
  );

  // Exported permission: 'administer field collections'.
  $permissions['administer field collections'] = array(
    'name' => 'administer field collections',
    'roles' => array(
      'Overall Administrator' => 'Overall Administrator',
    ),
    'module' => 'field_collection',
  );

  // Exported permission: 'administer field permissions'.
  $permissions['administer field permissions'] = array(
    'name' => 'administer field permissions',
    'roles' => array(
      'Overall Administrator' => 'Overall Administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'administer fieldgroups'.
  $permissions['administer fieldgroups'] = array(
    'name' => 'administer fieldgroups',
    'roles' => array(
      'Overall Administrator' => 'Overall Administrator',
    ),
    'module' => 'field_group',
  );

  // Exported permission: 'administer fields'.
  $permissions['administer fields'] = array(
    'name' => 'administer fields',
    'roles' => array(
      'Overall Administrator' => 'Overall Administrator',
    ),
    'module' => 'field',
  );

  // Exported permission: 'administer filters'.
  $permissions['administer filters'] = array(
    'name' => 'administer filters',
    'roles' => array(
      'Overall Administrator' => 'Overall Administrator',
    ),
    'module' => 'filter',
  );

  // Exported permission: 'administer flags'.
  $permissions['administer flags'] = array(
    'name' => 'administer flags',
    'roles' => array(
      'Overall Administrator' => 'Overall Administrator',
    ),
    'module' => 'flag',
  );

  // Exported permission: 'administer flexicolor settings'.
  $permissions['administer flexicolor settings'] = array(
    'name' => 'administer flexicolor settings',
    'roles' => array(
      'Overall Administrator' => 'Overall Administrator',
    ),
    'module' => 'flexicolor',
  );

  // Exported permission: 'administer flickr'.
  $permissions['administer flickr'] = array(
    'name' => 'administer flickr',
    'roles' => array(
      'Overall Administrator' => 'Overall Administrator',
    ),
    'module' => 'flickr',
  );

  // Exported permission: 'administer homebox'.
  $permissions['administer homebox'] = array(
    'name' => 'administer homebox',
    'roles' => array(
      'Overall Administrator' => 'Overall Administrator',
    ),
    'module' => 'homebox',
  );

  // Exported permission: 'administer honeypot'.
  $permissions['administer honeypot'] = array(
    'name' => 'administer honeypot',
    'roles' => array(
      'Overall Administrator' => 'Overall Administrator',
    ),
    'module' => 'honeypot',
  );

  // Exported permission: 'administer image styles'.
  $permissions['administer image styles'] = array(
    'name' => 'administer image styles',
    'roles' => array(
      'Overall Administrator' => 'Overall Administrator',
    ),
    'module' => 'image',
  );

  // Exported permission: 'administer imce'.
  $permissions['administer imce'] = array(
    'name' => 'administer imce',
    'roles' => array(
      'Overall Administrator' => 'Overall Administrator',
    ),
    'module' => 'imce',
  );

  // Exported permission: 'administer languages'.
  $permissions['administer languages'] = array(
    'name' => 'administer languages',
    'roles' => array(
      'Overall Administrator' => 'Overall Administrator',
    ),
    'module' => 'locale',
  );

  // Exported permission: 'administer linkit'.
  $permissions['administer linkit'] = array(
    'name' => 'administer linkit',
    'roles' => array(
      'Overall Administrator' => 'Overall Administrator',
    ),
    'module' => 'linkit',
  );

  // Exported permission: 'administer login destination settings'.
  $permissions['administer login destination settings'] = array(
    'name' => 'administer login destination settings',
    'roles' => array(
      'Overall Administrator' => 'Overall Administrator',
    ),
    'module' => 'login_destination',
  );

  // Exported permission: 'administer masquerade'.
  $permissions['administer masquerade'] = array(
    'name' => 'administer masquerade',
    'roles' => array(
      'Overall Administrator' => 'Overall Administrator',
      'Program administrator' => 'Program administrator',
    ),
    'module' => 'masquerade',
  );

  // Exported permission: 'administer media'.
  $permissions['administer media'] = array(
    'name' => 'administer media',
    'roles' => array(
      'Overall Administrator' => 'Overall Administrator',
    ),
    'module' => 'media',
  );

  // Exported permission: 'administer menu'.
  $permissions['administer menu'] = array(
    'name' => 'administer menu',
    'roles' => array(
      'Overall Administrator' => 'Overall Administrator',
    ),
    'module' => 'menu',
  );

  // Exported permission: 'administer menu attributes'.
  $permissions['administer menu attributes'] = array(
    'name' => 'administer menu attributes',
    'roles' => array(
      'Overall Administrator' => 'Overall Administrator',
    ),
    'module' => 'menu_attributes',
  );

  // Exported permission: 'administer menu_per_role'.
  $permissions['administer menu_per_role'] = array(
    'name' => 'administer menu_per_role',
    'roles' => array(
      'Overall Administrator' => 'Overall Administrator',
    ),
    'module' => 'menu_per_role',
  );

  // Exported permission: 'administer mini panels'.
  $permissions['administer mini panels'] = array(
    'name' => 'administer mini panels',
    'roles' => array(
      'Overall Administrator' => 'Overall Administrator',
    ),
    'module' => 'panels_mini',
  );

  // Exported permission: 'administer module filter'.
  $permissions['administer module filter'] = array(
    'name' => 'administer module filter',
    'roles' => array(
      'Overall Administrator' => 'Overall Administrator',
    ),
    'module' => 'module_filter',
  );

  // Exported permission: 'administer modules'.
  $permissions['administer modules'] = array(
    'name' => 'administer modules',
    'roles' => array(
      'Overall Administrator' => 'Overall Administrator',
    ),
    'module' => 'system',
  );

  // Exported permission: 'administer nodequeue'.
  $permissions['administer nodequeue'] = array(
    'name' => 'administer nodequeue',
    'roles' => array(
      'Overall Administrator' => 'Overall Administrator',
    ),
    'module' => 'nodequeue',
  );

  // Exported permission: 'administer nodes'.
  $permissions['administer nodes'] = array(
    'name' => 'administer nodes',
    'roles' => array(
      'Overall Administrator' => 'Overall Administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'administer owlcarousel settings'.
  $permissions['administer owlcarousel settings'] = array(
    'name' => 'administer owlcarousel settings',
    'roles' => array(
      'Overall Administrator' => 'Overall Administrator',
    ),
    'module' => 'owlcarousel_ui',
  );

  // Exported permission: 'administer page manager'.
  $permissions['administer page manager'] = array(
    'name' => 'administer page manager',
    'roles' => array(
      'Overall Administrator' => 'Overall Administrator',
    ),
    'module' => 'page_manager',
  );

  // Exported permission: 'administer pane access'.
  $permissions['administer pane access'] = array(
    'name' => 'administer pane access',
    'roles' => array(
      'Overall Administrator' => 'Overall Administrator',
    ),
    'module' => 'panels',
  );

  // Exported permission: 'administer panels display styles'.
  $permissions['administer panels display styles'] = array(
    'name' => 'administer panels display styles',
    'roles' => array(
      'Overall Administrator' => 'Overall Administrator',
    ),
    'module' => 'panels',
  );

  // Exported permission: 'administer panels layouts'.
  $permissions['administer panels layouts'] = array(
    'name' => 'administer panels layouts',
    'roles' => array(
      'Overall Administrator' => 'Overall Administrator',
    ),
    'module' => 'panels',
  );

  // Exported permission: 'administer panels pane styles'.
  $permissions['administer panels pane styles'] = array(
    'name' => 'administer panels pane styles',
    'roles' => array(
      'Overall Administrator' => 'Overall Administrator',
    ),
    'module' => 'panels',
  );

  // Exported permission: 'administer panels region styles'.
  $permissions['administer panels region styles'] = array(
    'name' => 'administer panels region styles',
    'roles' => array(
      'Overall Administrator' => 'Overall Administrator',
    ),
    'module' => 'panels',
  );

  // Exported permission: 'administer panels styles'.
  $permissions['administer panels styles'] = array(
    'name' => 'administer panels styles',
    'roles' => array(
      'Overall Administrator' => 'Overall Administrator',
    ),
    'module' => 'panels',
  );

  // Exported permission: 'administer pathauto'.
  $permissions['administer pathauto'] = array(
    'name' => 'administer pathauto',
    'roles' => array(
      'Overall Administrator' => 'Overall Administrator',
    ),
    'module' => 'pathauto',
  );

  // Exported permission: 'administer permissions'.
  $permissions['administer permissions'] = array(
    'name' => 'administer permissions',
    'roles' => array(
      'Overall Administrator' => 'Overall Administrator',
    ),
    'module' => 'user',
  );

  // Exported permission: 'administer privatemsg settings'.
  $permissions['administer privatemsg settings'] = array(
    'name' => 'administer privatemsg settings',
    'roles' => array(
      'Overall Administrator' => 'Overall Administrator',
    ),
    'module' => 'privatemsg',
  );

  // Exported permission: 'administer profile types'.
  $permissions['administer profile types'] = array(
    'name' => 'administer profile types',
    'roles' => array(
      'Overall Administrator' => 'Overall Administrator',
    ),
    'module' => 'profile2',
  );

  // Exported permission: 'administer profile2_regpath'.
  $permissions['administer profile2_regpath'] = array(
    'name' => 'administer profile2_regpath',
    'roles' => array(
      'Overall Administrator' => 'Overall Administrator',
    ),
    'module' => 'profile2_regpath',
  );

  // Exported permission: 'administer profiles'.
  $permissions['administer profiles'] = array(
    'name' => 'administer profiles',
    'roles' => array(
      'Lead Staff' => 'Lead Staff',
      'Overall Administrator' => 'Overall Administrator',
      'Program administrator' => 'Program administrator',
    ),
    'module' => 'profile2',
  );

  // Exported permission: 'administer quicktabs'.
  $permissions['administer quicktabs'] = array(
    'name' => 'administer quicktabs',
    'roles' => array(
      'Overall Administrator' => 'Overall Administrator',
    ),
    'module' => 'quicktabs',
  );

  // Exported permission: 'administer rules'.
  $permissions['administer rules'] = array(
    'name' => 'administer rules',
    'roles' => array(
      'Overall Administrator' => 'Overall Administrator',
    ),
    'module' => 'rules',
  );

  // Exported permission: 'administer scheduler'.
  $permissions['administer scheduler'] = array(
    'name' => 'administer scheduler',
    'roles' => array(
      'Overall Administrator' => 'Overall Administrator',
    ),
    'module' => 'scheduler',
  );

  // Exported permission: 'administer search'.
  $permissions['administer search'] = array(
    'name' => 'administer search',
    'roles' => array(
      'Overall Administrator' => 'Overall Administrator',
    ),
    'module' => 'search',
  );

  // Exported permission: 'administer search_api'.
  $permissions['administer search_api'] = array(
    'name' => 'administer search_api',
    'roles' => array(
      'Overall Administrator' => 'Overall Administrator',
    ),
    'module' => 'search_api',
  );

  // Exported permission: 'administer sharedemail'.
  $permissions['administer sharedemail'] = array(
    'name' => 'administer sharedemail',
    'roles' => array(
      'Overall Administrator' => 'Overall Administrator',
    ),
    'module' => 'sharedemail',
  );

  // Exported permission: 'administer shortcuts'.
  $permissions['administer shortcuts'] = array(
    'name' => 'administer shortcuts',
    'roles' => array(
      'Overall Administrator' => 'Overall Administrator',
    ),
    'module' => 'shortcut',
  );

  // Exported permission: 'administer site configuration'.
  $permissions['administer site configuration'] = array(
    'name' => 'administer site configuration',
    'roles' => array(
      'Overall Administrator' => 'Overall Administrator',
    ),
    'module' => 'system',
  );

  // Exported permission: 'administer software updates'.
  $permissions['administer software updates'] = array(
    'name' => 'administer software updates',
    'roles' => array(
      'Overall Administrator' => 'Overall Administrator',
    ),
    'module' => 'system',
  );

  // Exported permission: 'administer stage_file_proxy settings'.
  $permissions['administer stage_file_proxy settings'] = array(
    'name' => 'administer stage_file_proxy settings',
    'roles' => array(
      'Overall Administrator' => 'Overall Administrator',
    ),
    'module' => 'stage_file_proxy',
  );

  // Exported permission: 'administer string overrides'.
  $permissions['administer string overrides'] = array(
    'name' => 'administer string overrides',
    'roles' => array(
      'Overall Administrator' => 'Overall Administrator',
    ),
    'module' => 'stringoverrides',
  );

  // Exported permission: 'administer switch'.
  $permissions['administer switch'] = array(
    'name' => 'administer switch',
    'roles' => array(
      'Overall Administrator' => 'Overall Administrator',
    ),
    'module' => 'switchtheme',
  );

  // Exported permission: 'administer taxonomy'.
  $permissions['administer taxonomy'] = array(
    'name' => 'administer taxonomy',
    'roles' => array(
      'Overall Administrator' => 'Overall Administrator',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: 'administer themes'.
  $permissions['administer themes'] = array(
    'name' => 'administer themes',
    'roles' => array(
      'Overall Administrator' => 'Overall Administrator',
    ),
    'module' => 'system',
  );

  // Exported permission: 'administer title overrides'.
  $permissions['administer title overrides'] = array(
    'name' => 'administer title overrides',
    'roles' => array(
      'Overall Administrator' => 'Overall Administrator',
    ),
    'module' => 'title_override',
  );

  // Exported permission: 'administer url aliases'.
  $permissions['administer url aliases'] = array(
    'name' => 'administer url aliases',
    'roles' => array(
      'Overall Administrator' => 'Overall Administrator',
    ),
    'module' => 'path',
  );

  // Exported permission: 'administer userpoints'.
  $permissions['administer userpoints'] = array(
    'name' => 'administer userpoints',
    'roles' => array(
      'Overall Administrator' => 'Overall Administrator',
    ),
    'module' => 'userpoints',
  );

  // Exported permission: 'administer users'.
  $permissions['administer users'] = array(
    'name' => 'administer users',
    'roles' => array(
      'Overall Administrator' => 'Overall Administrator',
      'Program administrator' => 'Program administrator',
    ),
    'module' => 'user',
  );

  // Exported permission: 'administer views'.
  $permissions['administer views'] = array(
    'name' => 'administer views',
    'roles' => array(
      'Overall Administrator' => 'Overall Administrator',
    ),
    'module' => 'views',
  );

  // Exported permission: 'administer workbench'.
  $permissions['administer workbench'] = array(
    'name' => 'administer workbench',
    'roles' => array(
      'Lead Staff' => 'Lead Staff',
      'Overall Administrator' => 'Overall Administrator',
      'Staff' => 'Staff',
    ),
    'module' => 'workbench',
  );

  // Exported permission: 'administer workbench access'.
  $permissions['administer workbench access'] = array(
    'name' => 'administer workbench access',
    'roles' => array(
      'Overall Administrator' => 'Overall Administrator',
    ),
    'module' => 'workbench_access',
  );

  // Exported permission: 'administer workbench moderation'.
  $permissions['administer workbench moderation'] = array(
    'name' => 'administer workbench moderation',
    'roles' => array(
      'Overall Administrator' => 'Overall Administrator',
    ),
    'module' => 'workbench_moderation',
  );

  // Exported permission: 'allow disabling privatemsg'.
  $permissions['allow disabling privatemsg'] = array(
    'name' => 'allow disabling privatemsg',
    'roles' => array(
      'Overall Administrator' => 'Overall Administrator',
    ),
    'module' => 'privatemsg',
  );

  // Exported permission: 'assign Group Lead role'.
  $permissions['assign Group Lead role'] = array(
    'name' => 'assign Group Lead role',
    'roles' => array(
      'Lead Staff' => 'Lead Staff',
      'Program administrator' => 'Program administrator',
    ),
    'module' => 'role_delegation',
  );

  // Exported permission: 'assign Lead Staff role'.
  $permissions['assign Lead Staff role'] = array(
    'name' => 'assign Lead Staff role',
    'roles' => array(
      'Program administrator' => 'Program administrator',
    ),
    'module' => 'role_delegation',
  );

  // Exported permission: 'assign Patron role'.
  $permissions['assign Patron role'] = array(
    'name' => 'assign Patron role',
    'roles' => array(
      'Lead Staff' => 'Lead Staff',
      'Program administrator' => 'Program administrator',
    ),
    'module' => 'role_delegation',
  );

  // Exported permission: 'assign Program administrator role'.
  $permissions['assign Program administrator role'] = array(
    'name' => 'assign Program administrator role',
    'roles' => array(
      'Program administrator' => 'Program administrator',
    ),
    'module' => 'role_delegation',
  );

  // Exported permission: 'assign Staff role'.
  $permissions['assign Staff role'] = array(
    'name' => 'assign Staff role',
    'roles' => array(
      'Lead Staff' => 'Lead Staff',
      'Program administrator' => 'Program administrator',
    ),
    'module' => 'role_delegation',
  );

  // Exported permission: 'assign all roles'.
  $permissions['assign all roles'] = array(
    'name' => 'assign all roles',
    'roles' => array(
      'Overall Administrator' => 'Overall Administrator',
    ),
    'module' => 'role_delegation',
  );

  // Exported permission: 'assign roles'.
  $permissions['assign roles'] = array(
    'name' => 'assign roles',
    'roles' => array(
      'Overall Administrator' => 'Overall Administrator',
    ),
    'module' => 'roleassign',
  );

  // Exported permission: 'assign workbench access'.
  $permissions['assign workbench access'] = array(
    'name' => 'assign workbench access',
    'roles' => array(
      'Overall Administrator' => 'Overall Administrator',
      'Program administrator' => 'Program administrator',
    ),
    'module' => 'workbench_access',
  );

  // Exported permission: 'batch update workbench access'.
  $permissions['batch update workbench access'] = array(
    'name' => 'batch update workbench access',
    'roles' => array(
      'Overall Administrator' => 'Overall Administrator',
    ),
    'module' => 'workbench_access',
  );

  // Exported permission: 'block IP addresses'.
  $permissions['block IP addresses'] = array(
    'name' => 'block IP addresses',
    'roles' => array(
      'Lead Staff' => 'Lead Staff',
      'Overall Administrator' => 'Overall Administrator',
    ),
    'module' => 'system',
  );

  // Exported permission: 'bypass access in place editing'.
  $permissions['bypass access in place editing'] = array(
    'name' => 'bypass access in place editing',
    'roles' => array(),
    'module' => 'panels',
  );

  // Exported permission: 'bypass honeypot protection'.
  $permissions['bypass honeypot protection'] = array(
    'name' => 'bypass honeypot protection',
    'roles' => array(
      'Overall Administrator' => 'Overall Administrator',
    ),
    'module' => 'honeypot',
  );

  // Exported permission: 'bypass node access'.
  $permissions['bypass node access'] = array(
    'name' => 'bypass node access',
    'roles' => array(
      'Overall Administrator' => 'Overall Administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'bypass rules access'.
  $permissions['bypass rules access'] = array(
    'name' => 'bypass rules access',
    'roles' => array(
      'Overall Administrator' => 'Overall Administrator',
    ),
    'module' => 'rules',
  );

  // Exported permission: 'bypass workbench moderation'.
  $permissions['bypass workbench moderation'] = array(
    'name' => 'bypass workbench moderation',
    'roles' => array(
      'Overall Administrator' => 'Overall Administrator',
      'Program administrator' => 'Program administrator',
    ),
    'module' => 'workbench_moderation',
  );

  // Exported permission: 'cancel account'.
  $permissions['cancel account'] = array(
    'name' => 'cancel account',
    'roles' => array(
      'Overall Administrator' => 'Overall Administrator',
      'Program administrator' => 'Program administrator',
    ),
    'module' => 'user',
  );

  // Exported permission: 'cancel own vote'.
  $permissions['cancel own vote'] = array(
    'name' => 'cancel own vote',
    'roles' => array(
      'Overall Administrator' => 'Overall Administrator',
    ),
    'module' => 'poll',
  );

  // Exported permission: 'cancel users with role 2'.
  $permissions['cancel users with role 2'] = array(
    'name' => 'cancel users with role 2',
    'roles' => array(
      'Lead Staff' => 'Lead Staff',
      'Overall Administrator' => 'Overall Administrator',
      'Program administrator' => 'Program administrator',
      'Staff' => 'Staff',
    ),
    'module' => 'administerusersbyrole',
  );

  // Exported permission: 'cancel users with role 4'.
  $permissions['cancel users with role 4'] = array(
    'name' => 'cancel users with role 4',
    'roles' => array(
      'Overall Administrator' => 'Overall Administrator',
      'Program administrator' => 'Program administrator',
    ),
    'module' => 'administerusersbyrole',
  );

  // Exported permission: 'cancel users with role 5'.
  $permissions['cancel users with role 5'] = array(
    'name' => 'cancel users with role 5',
    'roles' => array(
      'Lead Staff' => 'Lead Staff',
      'Overall Administrator' => 'Overall Administrator',
      'Program administrator' => 'Program administrator',
      'Staff' => 'Staff',
    ),
    'module' => 'administerusersbyrole',
  );

  // Exported permission: 'cancel users with role 6'.
  $permissions['cancel users with role 6'] = array(
    'name' => 'cancel users with role 6',
    'roles' => array(
      'Overall Administrator' => 'Overall Administrator',
      'Program administrator' => 'Program administrator',
    ),
    'module' => 'administerusersbyrole',
  );

  // Exported permission: 'cancel users with role 7'.
  $permissions['cancel users with role 7'] = array(
    'name' => 'cancel users with role 7',
    'roles' => array(
      'Overall Administrator' => 'Overall Administrator',
      'Program administrator' => 'Program administrator',
    ),
    'module' => 'administerusersbyrole',
  );

  // Exported permission: 'cancel users with role 8'.
  $permissions['cancel users with role 8'] = array(
    'name' => 'cancel users with role 8',
    'roles' => array(
      'Overall Administrator' => 'Overall Administrator',
      'Program administrator' => 'Program administrator',
    ),
    'module' => 'administerusersbyrole',
  );

  // Exported permission: 'change layouts in place editing'.
  $permissions['change layouts in place editing'] = array(
    'name' => 'change layouts in place editing',
    'roles' => array(
      'Overall Administrator' => 'Overall Administrator',
    ),
    'module' => 'panels',
  );

  // Exported permission: 'change own username'.
  $permissions['change own username'] = array(
    'name' => 'change own username',
    'roles' => array(
      'Overall Administrator' => 'Overall Administrator',
      'Program administrator' => 'Program administrator',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'user',
  );

  // Exported permission: 'clear avatars feeds'.
  $permissions['clear avatars feeds'] = array(
    'name' => 'clear avatars feeds',
    'roles' => array(
      'Program administrator' => 'Program administrator',
    ),
    'module' => 'feeds',
  );

  // Exported permission: 'clear events feeds'.
  $permissions['clear events feeds'] = array(
    'name' => 'clear events feeds',
    'roles' => array(
      'Program administrator' => 'Program administrator',
    ),
    'module' => 'feeds',
  );

  // Exported permission: 'configure table decorations'.
  $permissions['configure table decorations'] = array(
    'name' => 'configure table decorations',
    'roles' => array(
      'Overall Administrator' => 'Overall Administrator',
    ),
    'module' => 'table_trash',
  );

  // Exported permission: 'create _flickr_images content'.
  $permissions['create _flickr_images content'] = array(
    'name' => 'create _flickr_images content',
    'roles' => array(
      'Lead Staff' => 'Lead Staff',
      'Program administrator' => 'Program administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'create article content'.
  $permissions['create article content'] = array(
    'name' => 'create article content',
    'roles' => array(
      'Overall Administrator' => 'Overall Administrator',
      'Program administrator' => 'Program administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'create booklist content'.
  $permissions['create booklist content'] = array(
    'name' => 'create booklist content',
    'roles' => array(
      'Program administrator' => 'Program administrator',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'node',
  );

  // Exported permission: 'create event content'.
  $permissions['create event content'] = array(
    'name' => 'create event content',
    'roles' => array(
      'Program administrator' => 'Program administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'create event_activities content'.
  $permissions['create event_activities content'] = array(
    'name' => 'create event_activities content',
    'roles' => array(
      'Lead Staff' => 'Lead Staff',
      'Program administrator' => 'Program administrator',
      'Staff' => 'Staff',
    ),
    'module' => 'node',
  );

  // Exported permission: 'create field_booklist_cover_image'.
  $permissions['create field_booklist_cover_image'] = array(
    'name' => 'create field_booklist_cover_image',
    'roles' => array(
      'Lead Staff' => 'Lead Staff',
      'Overall Administrator' => 'Overall Administrator',
      'Program administrator' => 'Program administrator',
      'Staff' => 'Staff',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'create field_movie_cover_image_link'.
  $permissions['create field_movie_cover_image_link'] = array(
    'name' => 'create field_movie_cover_image_link',
    'roles' => array(),
    'module' => 'field_permissions',
  );

  // Exported permission: 'create field_music_cover_image_link'.
  $permissions['create field_music_cover_image_link'] = array(
    'name' => 'create field_music_cover_image_link',
    'roles' => array(
      'Lead Staff' => 'Lead Staff',
      'Program administrator' => 'Program administrator',
      'Staff' => 'Staff',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'create field_video_game_cover_image_lin'.
  $permissions['create field_video_game_cover_image_lin'] = array(
    'name' => 'create field_video_game_cover_image_lin',
    'roles' => array(
      'Lead Staff' => 'Lead Staff',
      'Program administrator' => 'Program administrator',
      'Staff' => 'Staff',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'create library_pages content'.
  $permissions['create library_pages content'] = array(
    'name' => 'create library_pages content',
    'roles' => array(
      'Program administrator' => 'Program administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'create mini panels'.
  $permissions['create mini panels'] = array(
    'name' => 'create mini panels',
    'roles' => array(
      'Overall Administrator' => 'Overall Administrator',
    ),
    'module' => 'panels_mini',
  );

  // Exported permission: 'create movie_review content'.
  $permissions['create movie_review content'] = array(
    'name' => 'create movie_review content',
    'roles' => array(
      'Program administrator' => 'Program administrator',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'node',
  );

  // Exported permission: 'create music_review content'.
  $permissions['create music_review content'] = array(
    'name' => 'create music_review content',
    'roles' => array(
      'Program administrator' => 'Program administrator',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'node',
  );

  // Exported permission: 'create page content'.
  $permissions['create page content'] = array(
    'name' => 'create page content',
    'roles' => array(
      'Overall Administrator' => 'Overall Administrator',
      'Program administrator' => 'Program administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'create poll content'.
  $permissions['create poll content'] = array(
    'name' => 'create poll content',
    'roles' => array(
      'Lead Staff' => 'Lead Staff',
      'Program administrator' => 'Program administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'create private message tags'.
  $permissions['create private message tags'] = array(
    'name' => 'create private message tags',
    'roles' => array(
      'Overall Administrator' => 'Overall Administrator',
    ),
    'module' => 'privatemsg_filter',
  );

  // Exported permission: 'create program content'.
  $permissions['create program content'] = array(
    'name' => 'create program content',
    'roles' => array(
      'Lead Staff' => 'Lead Staff',
      'Program administrator' => 'Program administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'create review_activity content'.
  $permissions['create review_activity content'] = array(
    'name' => 'create review_activity content',
    'roles' => array(
      'Overall Administrator' => 'Overall Administrator',
      'Program administrator' => 'Program administrator',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'node',
  );

  // Exported permission: 'create review_book content'.
  $permissions['create review_book content'] = array(
    'name' => 'create review_book content',
    'roles' => array(
      'Program administrator' => 'Program administrator',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'node',
  );

  // Exported permission: 'create sticker content'.
  $permissions['create sticker content'] = array(
    'name' => 'create sticker content',
    'roles' => array(
      'Program administrator' => 'Program administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'create url aliases'.
  $permissions['create url aliases'] = array(
    'name' => 'create url aliases',
    'roles' => array(
      'Overall Administrator' => 'Overall Administrator',
    ),
    'module' => 'path',
  );

  // Exported permission: 'create users'.
  $permissions['create users'] = array(
    'name' => 'create users',
    'roles' => array(
      'Lead Staff' => 'Lead Staff',
      'Overall Administrator' => 'Overall Administrator',
      'Program administrator' => 'Program administrator',
      'Staff' => 'Staff',
    ),
    'module' => 'administerusersbyrole',
  );

  // Exported permission: 'create video_game_review content'.
  $permissions['create video_game_review content'] = array(
    'name' => 'create video_game_review content',
    'roles' => array(
      'Program administrator' => 'Program administrator',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'node',
  );

  // Exported permission: 'create videos content'.
  $permissions['create videos content'] = array(
    'name' => 'create videos content',
    'roles' => array(
      'Lead Staff' => 'Lead Staff',
      'Program administrator' => 'Program administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'create webform content'.
  $permissions['create webform content'] = array(
    'name' => 'create webform content',
    'roles' => array(
      'Lead Staff' => 'Lead Staff',
      'Program administrator' => 'Program administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'customize shortcut links'.
  $permissions['customize shortcut links'] = array(
    'name' => 'customize shortcut links',
    'roles' => array(
      'Overall Administrator' => 'Overall Administrator',
    ),
    'module' => 'shortcut',
  );

  // Exported permission: 'delete all webform submissions'.
  $permissions['delete all webform submissions'] = array(
    'name' => 'delete all webform submissions',
    'roles' => array(
      'Overall Administrator' => 'Overall Administrator',
      'Program administrator' => 'Program administrator',
    ),
    'module' => 'webform',
  );

  // Exported permission: 'delete any _flickr_images content'.
  $permissions['delete any _flickr_images content'] = array(
    'name' => 'delete any _flickr_images content',
    'roles' => array(
      'Program administrator' => 'Program administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete any article content'.
  $permissions['delete any article content'] = array(
    'name' => 'delete any article content',
    'roles' => array(
      'Overall Administrator' => 'Overall Administrator',
      'Program administrator' => 'Program administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete any booklist content'.
  $permissions['delete any booklist content'] = array(
    'name' => 'delete any booklist content',
    'roles' => array(
      'Program administrator' => 'Program administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete any event content'.
  $permissions['delete any event content'] = array(
    'name' => 'delete any event content',
    'roles' => array(
      'Program administrator' => 'Program administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete any event_activities content'.
  $permissions['delete any event_activities content'] = array(
    'name' => 'delete any event_activities content',
    'roles' => array(
      'Lead Staff' => 'Lead Staff',
      'Program administrator' => 'Program administrator',
      'Staff' => 'Staff',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete any library_pages content'.
  $permissions['delete any library_pages content'] = array(
    'name' => 'delete any library_pages content',
    'roles' => array(
      'Program administrator' => 'Program administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete any movie_review content'.
  $permissions['delete any movie_review content'] = array(
    'name' => 'delete any movie_review content',
    'roles' => array(
      'Program administrator' => 'Program administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete any music_review content'.
  $permissions['delete any music_review content'] = array(
    'name' => 'delete any music_review content',
    'roles' => array(
      'Program administrator' => 'Program administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete any page content'.
  $permissions['delete any page content'] = array(
    'name' => 'delete any page content',
    'roles' => array(
      'Overall Administrator' => 'Overall Administrator',
      'Program administrator' => 'Program administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete any poll content'.
  $permissions['delete any poll content'] = array(
    'name' => 'delete any poll content',
    'roles' => array(
      'Program administrator' => 'Program administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete any program content'.
  $permissions['delete any program content'] = array(
    'name' => 'delete any program content',
    'roles' => array(
      'Program administrator' => 'Program administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete any review_activity content'.
  $permissions['delete any review_activity content'] = array(
    'name' => 'delete any review_activity content',
    'roles' => array(
      'Program administrator' => 'Program administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete any review_book content'.
  $permissions['delete any review_book content'] = array(
    'name' => 'delete any review_book content',
    'roles' => array(
      'Program administrator' => 'Program administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete any sticker content'.
  $permissions['delete any sticker content'] = array(
    'name' => 'delete any sticker content',
    'roles' => array(
      'Program administrator' => 'Program administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete any video_game_review content'.
  $permissions['delete any video_game_review content'] = array(
    'name' => 'delete any video_game_review content',
    'roles' => array(
      'Program administrator' => 'Program administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete any videos content'.
  $permissions['delete any videos content'] = array(
    'name' => 'delete any videos content',
    'roles' => array(
      'Program administrator' => 'Program administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete any webform content'.
  $permissions['delete any webform content'] = array(
    'name' => 'delete any webform content',
    'roles' => array(
      'Program administrator' => 'Program administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete backup files'.
  $permissions['delete backup files'] = array(
    'name' => 'delete backup files',
    'roles' => array(
      'Overall Administrator' => 'Overall Administrator',
    ),
    'module' => 'backup_migrate',
  );

  // Exported permission: 'delete own _flickr_images content'.
  $permissions['delete own _flickr_images content'] = array(
    'name' => 'delete own _flickr_images content',
    'roles' => array(
      'Program administrator' => 'Program administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete own article content'.
  $permissions['delete own article content'] = array(
    'name' => 'delete own article content',
    'roles' => array(
      'Overall Administrator' => 'Overall Administrator',
      'Program administrator' => 'Program administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete own booklist content'.
  $permissions['delete own booklist content'] = array(
    'name' => 'delete own booklist content',
    'roles' => array(
      'Program administrator' => 'Program administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete own event content'.
  $permissions['delete own event content'] = array(
    'name' => 'delete own event content',
    'roles' => array(
      'Program administrator' => 'Program administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete own event_activities content'.
  $permissions['delete own event_activities content'] = array(
    'name' => 'delete own event_activities content',
    'roles' => array(
      'Lead Staff' => 'Lead Staff',
      'Program administrator' => 'Program administrator',
      'Staff' => 'Staff',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete own library_pages content'.
  $permissions['delete own library_pages content'] = array(
    'name' => 'delete own library_pages content',
    'roles' => array(
      'Program administrator' => 'Program administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete own movie_review content'.
  $permissions['delete own movie_review content'] = array(
    'name' => 'delete own movie_review content',
    'roles' => array(
      'Program administrator' => 'Program administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete own music_review content'.
  $permissions['delete own music_review content'] = array(
    'name' => 'delete own music_review content',
    'roles' => array(
      'Program administrator' => 'Program administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete own page content'.
  $permissions['delete own page content'] = array(
    'name' => 'delete own page content',
    'roles' => array(
      'Overall Administrator' => 'Overall Administrator',
      'Program administrator' => 'Program administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete own poll content'.
  $permissions['delete own poll content'] = array(
    'name' => 'delete own poll content',
    'roles' => array(
      'Program administrator' => 'Program administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete own program content'.
  $permissions['delete own program content'] = array(
    'name' => 'delete own program content',
    'roles' => array(
      'Program administrator' => 'Program administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete own review_activity content'.
  $permissions['delete own review_activity content'] = array(
    'name' => 'delete own review_activity content',
    'roles' => array(
      'Program administrator' => 'Program administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete own review_book content'.
  $permissions['delete own review_book content'] = array(
    'name' => 'delete own review_book content',
    'roles' => array(
      'Program administrator' => 'Program administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete own sticker content'.
  $permissions['delete own sticker content'] = array(
    'name' => 'delete own sticker content',
    'roles' => array(
      'Program administrator' => 'Program administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete own video_game_review content'.
  $permissions['delete own video_game_review content'] = array(
    'name' => 'delete own video_game_review content',
    'roles' => array(
      'Program administrator' => 'Program administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete own videos content'.
  $permissions['delete own videos content'] = array(
    'name' => 'delete own videos content',
    'roles' => array(
      'Program administrator' => 'Program administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete own webform content'.
  $permissions['delete own webform content'] = array(
    'name' => 'delete own webform content',
    'roles' => array(
      'Program administrator' => 'Program administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete own webform submissions'.
  $permissions['delete own webform submissions'] = array(
    'name' => 'delete own webform submissions',
    'roles' => array(
      'Overall Administrator' => 'Overall Administrator',
      'Program administrator' => 'Program administrator',
    ),
    'module' => 'webform',
  );

  // Exported permission: 'delete privatemsg'.
  $permissions['delete privatemsg'] = array(
    'name' => 'delete privatemsg',
    'roles' => array(
      'Overall Administrator' => 'Overall Administrator',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'privatemsg',
  );

  // Exported permission: 'delete revisions'.
  $permissions['delete revisions'] = array(
    'name' => 'delete revisions',
    'roles' => array(
      'Overall Administrator' => 'Overall Administrator',
      'Program administrator' => 'Program administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete terms in audience'.
  $permissions['delete terms in audience'] = array(
    'name' => 'delete terms in audience',
    'roles' => array(),
    'module' => 'taxonomy',
  );

  // Exported permission: 'delete terms in avatars'.
  $permissions['delete terms in avatars'] = array(
    'name' => 'delete terms in avatars',
    'roles' => array(
      'Program administrator' => 'Program administrator',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: 'delete terms in calendar_sticker'.
  $permissions['delete terms in calendar_sticker'] = array(
    'name' => 'delete terms in calendar_sticker',
    'roles' => array(
      'Program administrator' => 'Program administrator',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: 'delete terms in current_program'.
  $permissions['delete terms in current_program'] = array(
    'name' => 'delete terms in current_program',
    'roles' => array(
      'Program administrator' => 'Program administrator',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: 'delete terms in grade'.
  $permissions['delete terms in grade'] = array(
    'name' => 'delete terms in grade',
    'roles' => array(
      'Program administrator' => 'Program administrator',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: 'delete terms in library_branch'.
  $permissions['delete terms in library_branch'] = array(
    'name' => 'delete terms in library_branch',
    'roles' => array(
      'Program administrator' => 'Program administrator',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: 'delete terms in library_pages'.
  $permissions['delete terms in library_pages'] = array(
    'name' => 'delete terms in library_pages',
    'roles' => array(),
    'module' => 'taxonomy',
  );

  // Exported permission: 'delete terms in organization'.
  $permissions['delete terms in organization'] = array(
    'name' => 'delete terms in organization',
    'roles' => array(
      'Program administrator' => 'Program administrator',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: 'delete terms in program_referrers'.
  $permissions['delete terms in program_referrers'] = array(
    'name' => 'delete terms in program_referrers',
    'roles' => array(
      'Program administrator' => 'Program administrator',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: 'delete terms in schools'.
  $permissions['delete terms in schools'] = array(
    'name' => 'delete terms in schools',
    'roles' => array(
      'Program administrator' => 'Program administrator',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: 'delete terms in tags'.
  $permissions['delete terms in tags'] = array(
    'name' => 'delete terms in tags',
    'roles' => array(
      'Overall Administrator' => 'Overall Administrator',
      'Program administrator' => 'Program administrator',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: 'delete terms in type_of_reward'.
  $permissions['delete terms in type_of_reward'] = array(
    'name' => 'delete terms in type_of_reward',
    'roles' => array(),
    'module' => 'taxonomy',
  );

  // Exported permission: 'delete terms in userpoints'.
  $permissions['delete terms in userpoints'] = array(
    'name' => 'delete terms in userpoints',
    'roles' => array(),
    'module' => 'taxonomy',
  );

  // Exported permission: 'display drupal links'.
  $permissions['display drupal links'] = array(
    'name' => 'display drupal links',
    'roles' => array(
      'Overall Administrator' => 'Overall Administrator',
      'Program administrator' => 'Program administrator',
    ),
    'module' => 'admin_menu',
  );

  // Exported permission: 'eck add activity activity entities'.
  $permissions['eck add activity activity entities'] = array(
    'name' => 'eck add activity activity entities',
    'roles' => array(
      'Program administrator' => 'Program administrator',
    ),
    'module' => 'eck',
  );

  // Exported permission: 'eck add activity activity_entry entities'.
  $permissions['eck add activity activity_entry entities'] = array(
    'name' => 'eck add activity activity_entry entities',
    'roles' => array(
      'Program administrator' => 'Program administrator',
    ),
    'module' => 'eck',
  );

  // Exported permission: 'eck add activity bundles'.
  $permissions['eck add activity bundles'] = array(
    'name' => 'eck add activity bundles',
    'roles' => array(),
    'module' => 'eck',
  );

  // Exported permission: 'eck add avatar avatar entities'.
  $permissions['eck add avatar avatar entities'] = array(
    'name' => 'eck add avatar avatar entities',
    'roles' => array(
      'Program administrator' => 'Program administrator',
    ),
    'module' => 'eck',
  );

  // Exported permission: 'eck add avatar bundles'.
  $permissions['eck add avatar bundles'] = array(
    'name' => 'eck add avatar bundles',
    'roles' => array(
      'Program administrator' => 'Program administrator',
    ),
    'module' => 'eck',
  );

  // Exported permission: 'eck add booklist_item booklist_item entities'.
  $permissions['eck add booklist_item booklist_item entities'] = array(
    'name' => 'eck add booklist_item booklist_item entities',
    'roles' => array(
      'Lead Staff' => 'Lead Staff',
      'Patron' => 'Patron',
      'Program administrator' => 'Program administrator',
      'Staff' => 'Staff',
    ),
    'module' => 'eck',
  );

  // Exported permission: 'eck add booklist_item bundles'.
  $permissions['eck add booklist_item bundles'] = array(
    'name' => 'eck add booklist_item bundles',
    'roles' => array(
      'Program administrator' => 'Program administrator',
    ),
    'module' => 'eck',
  );

  // Exported permission: 'eck add bundles'.
  $permissions['eck add bundles'] = array(
    'name' => 'eck add bundles',
    'roles' => array(
      'Overall Administrator' => 'Overall Administrator',
    ),
    'module' => 'eck',
  );

  // Exported permission: 'eck add entities'.
  $permissions['eck add entities'] = array(
    'name' => 'eck add entities',
    'roles' => array(
      'Overall Administrator' => 'Overall Administrator',
    ),
    'module' => 'eck',
  );

  // Exported permission: 'eck add entity types'.
  $permissions['eck add entity types'] = array(
    'name' => 'eck add entity types',
    'roles' => array(
      'Overall Administrator' => 'Overall Administrator',
    ),
    'module' => 'eck',
  );

  // Exported permission: 'eck add reward bundles'.
  $permissions['eck add reward bundles'] = array(
    'name' => 'eck add reward bundles',
    'roles' => array(
      'Program administrator' => 'Program administrator',
    ),
    'module' => 'eck',
  );

  // Exported permission: 'eck add reward raffle_claim entities'.
  $permissions['eck add reward raffle_claim entities'] = array(
    'name' => 'eck add reward raffle_claim entities',
    'roles' => array(
      'Program administrator' => 'Program administrator',
    ),
    'module' => 'eck',
  );

  // Exported permission: 'eck add reward reward entities'.
  $permissions['eck add reward reward entities'] = array(
    'name' => 'eck add reward reward entities',
    'roles' => array(
      'Program administrator' => 'Program administrator',
    ),
    'module' => 'eck',
  );

  // Exported permission: 'eck add reward reward_claim entities'.
  $permissions['eck add reward reward_claim entities'] = array(
    'name' => 'eck add reward reward_claim entities',
    'roles' => array(
      'Program administrator' => 'Program administrator',
    ),
    'module' => 'eck',
  );

  // Exported permission: 'eck administer activity activity entities'.
  $permissions['eck administer activity activity entities'] = array(
    'name' => 'eck administer activity activity entities',
    'roles' => array(
      'Program administrator' => 'Program administrator',
    ),
    'module' => 'eck',
  );

  // Exported permission: 'eck administer activity activity_entry entities'.
  $permissions['eck administer activity activity_entry entities'] = array(
    'name' => 'eck administer activity activity_entry entities',
    'roles' => array(
      'Program administrator' => 'Program administrator',
    ),
    'module' => 'eck',
  );

  // Exported permission: 'eck administer activity bundles'.
  $permissions['eck administer activity bundles'] = array(
    'name' => 'eck administer activity bundles',
    'roles' => array(),
    'module' => 'eck',
  );

  // Exported permission: 'eck administer avatar avatar entities'.
  $permissions['eck administer avatar avatar entities'] = array(
    'name' => 'eck administer avatar avatar entities',
    'roles' => array(
      'Program administrator' => 'Program administrator',
    ),
    'module' => 'eck',
  );

  // Exported permission: 'eck administer avatar bundles'.
  $permissions['eck administer avatar bundles'] = array(
    'name' => 'eck administer avatar bundles',
    'roles' => array(
      'Program administrator' => 'Program administrator',
    ),
    'module' => 'eck',
  );

  // Exported permission: 'eck administer booklist_item booklist_item entities'.
  $permissions['eck administer booklist_item booklist_item entities'] = array(
    'name' => 'eck administer booklist_item booklist_item entities',
    'roles' => array(
      'Program administrator' => 'Program administrator',
    ),
    'module' => 'eck',
  );

  // Exported permission: 'eck administer booklist_item bundles'.
  $permissions['eck administer booklist_item bundles'] = array(
    'name' => 'eck administer booklist_item bundles',
    'roles' => array(
      'Program administrator' => 'Program administrator',
    ),
    'module' => 'eck',
  );

  // Exported permission: 'eck administer bundles'.
  $permissions['eck administer bundles'] = array(
    'name' => 'eck administer bundles',
    'roles' => array(
      'Overall Administrator' => 'Overall Administrator',
    ),
    'module' => 'eck',
  );

  // Exported permission: 'eck administer entities'.
  $permissions['eck administer entities'] = array(
    'name' => 'eck administer entities',
    'roles' => array(
      'Overall Administrator' => 'Overall Administrator',
    ),
    'module' => 'eck',
  );

  // Exported permission: 'eck administer entity types'.
  $permissions['eck administer entity types'] = array(
    'name' => 'eck administer entity types',
    'roles' => array(
      'Overall Administrator' => 'Overall Administrator',
    ),
    'module' => 'eck',
  );

  // Exported permission: 'eck administer reward bundles'.
  $permissions['eck administer reward bundles'] = array(
    'name' => 'eck administer reward bundles',
    'roles' => array(
      'Program administrator' => 'Program administrator',
    ),
    'module' => 'eck',
  );

  // Exported permission: 'eck administer reward raffle_claim entities'.
  $permissions['eck administer reward raffle_claim entities'] = array(
    'name' => 'eck administer reward raffle_claim entities',
    'roles' => array(
      'Program administrator' => 'Program administrator',
    ),
    'module' => 'eck',
  );

  // Exported permission: 'eck administer reward reward entities'.
  $permissions['eck administer reward reward entities'] = array(
    'name' => 'eck administer reward reward entities',
    'roles' => array(
      'Program administrator' => 'Program administrator',
    ),
    'module' => 'eck',
  );

  // Exported permission: 'eck administer reward reward_claim entities'.
  $permissions['eck administer reward reward_claim entities'] = array(
    'name' => 'eck administer reward reward_claim entities',
    'roles' => array(
      'Program administrator' => 'Program administrator',
    ),
    'module' => 'eck',
  );

  // Exported permission: 'eck delete activity activity entities'.
  $permissions['eck delete activity activity entities'] = array(
    'name' => 'eck delete activity activity entities',
    'roles' => array(
      'Program administrator' => 'Program administrator',
    ),
    'module' => 'eck',
  );

  // Exported permission: 'eck delete activity activity_entry entities'.
  $permissions['eck delete activity activity_entry entities'] = array(
    'name' => 'eck delete activity activity_entry entities',
    'roles' => array(
      'Program administrator' => 'Program administrator',
    ),
    'module' => 'eck',
  );

  // Exported permission: 'eck delete activity bundles'.
  $permissions['eck delete activity bundles'] = array(
    'name' => 'eck delete activity bundles',
    'roles' => array(),
    'module' => 'eck',
  );

  // Exported permission: 'eck delete avatar avatar entities'.
  $permissions['eck delete avatar avatar entities'] = array(
    'name' => 'eck delete avatar avatar entities',
    'roles' => array(
      'Program administrator' => 'Program administrator',
    ),
    'module' => 'eck',
  );

  // Exported permission: 'eck delete avatar bundles'.
  $permissions['eck delete avatar bundles'] = array(
    'name' => 'eck delete avatar bundles',
    'roles' => array(
      'Program administrator' => 'Program administrator',
    ),
    'module' => 'eck',
  );

  // Exported permission: 'eck delete booklist_item booklist_item entities'.
  $permissions['eck delete booklist_item booklist_item entities'] = array(
    'name' => 'eck delete booklist_item booklist_item entities',
    'roles' => array(
      'Lead Staff' => 'Lead Staff',
      'Program administrator' => 'Program administrator',
    ),
    'module' => 'eck',
  );

  // Exported permission: 'eck delete booklist_item bundles'.
  $permissions['eck delete booklist_item bundles'] = array(
    'name' => 'eck delete booklist_item bundles',
    'roles' => array(
      'Program administrator' => 'Program administrator',
    ),
    'module' => 'eck',
  );

  // Exported permission: 'eck delete bundles'.
  $permissions['eck delete bundles'] = array(
    'name' => 'eck delete bundles',
    'roles' => array(
      'Overall Administrator' => 'Overall Administrator',
    ),
    'module' => 'eck',
  );

  // Exported permission: 'eck delete entities'.
  $permissions['eck delete entities'] = array(
    'name' => 'eck delete entities',
    'roles' => array(
      'Overall Administrator' => 'Overall Administrator',
    ),
    'module' => 'eck',
  );

  // Exported permission: 'eck delete entity types'.
  $permissions['eck delete entity types'] = array(
    'name' => 'eck delete entity types',
    'roles' => array(
      'Overall Administrator' => 'Overall Administrator',
    ),
    'module' => 'eck',
  );

  // Exported permission: 'eck delete reward bundles'.
  $permissions['eck delete reward bundles'] = array(
    'name' => 'eck delete reward bundles',
    'roles' => array(
      'Program administrator' => 'Program administrator',
    ),
    'module' => 'eck',
  );

  // Exported permission: 'eck delete reward raffle_claim entities'.
  $permissions['eck delete reward raffle_claim entities'] = array(
    'name' => 'eck delete reward raffle_claim entities',
    'roles' => array(
      'Program administrator' => 'Program administrator',
    ),
    'module' => 'eck',
  );

  // Exported permission: 'eck delete reward reward entities'.
  $permissions['eck delete reward reward entities'] = array(
    'name' => 'eck delete reward reward entities',
    'roles' => array(
      'Program administrator' => 'Program administrator',
    ),
    'module' => 'eck',
  );

  // Exported permission: 'eck delete reward reward_claim entities'.
  $permissions['eck delete reward reward_claim entities'] = array(
    'name' => 'eck delete reward reward_claim entities',
    'roles' => array(
      'Program administrator' => 'Program administrator',
    ),
    'module' => 'eck',
  );

  // Exported permission: 'eck edit activity activity entities'.
  $permissions['eck edit activity activity entities'] = array(
    'name' => 'eck edit activity activity entities',
    'roles' => array(
      'Program administrator' => 'Program administrator',
    ),
    'module' => 'eck',
  );

  // Exported permission: 'eck edit activity activity_entry entities'.
  $permissions['eck edit activity activity_entry entities'] = array(
    'name' => 'eck edit activity activity_entry entities',
    'roles' => array(
      'Program administrator' => 'Program administrator',
    ),
    'module' => 'eck',
  );

  // Exported permission: 'eck edit activity bundles'.
  $permissions['eck edit activity bundles'] = array(
    'name' => 'eck edit activity bundles',
    'roles' => array(),
    'module' => 'eck',
  );

  // Exported permission: 'eck edit avatar avatar entities'.
  $permissions['eck edit avatar avatar entities'] = array(
    'name' => 'eck edit avatar avatar entities',
    'roles' => array(
      'Program administrator' => 'Program administrator',
    ),
    'module' => 'eck',
  );

  // Exported permission: 'eck edit avatar bundles'.
  $permissions['eck edit avatar bundles'] = array(
    'name' => 'eck edit avatar bundles',
    'roles' => array(
      'Program administrator' => 'Program administrator',
    ),
    'module' => 'eck',
  );

  // Exported permission: 'eck edit booklist_item booklist_item entities'.
  $permissions['eck edit booklist_item booklist_item entities'] = array(
    'name' => 'eck edit booklist_item booklist_item entities',
    'roles' => array(
      'Lead Staff' => 'Lead Staff',
      'Program administrator' => 'Program administrator',
    ),
    'module' => 'eck',
  );

  // Exported permission: 'eck edit booklist_item bundles'.
  $permissions['eck edit booklist_item bundles'] = array(
    'name' => 'eck edit booklist_item bundles',
    'roles' => array(
      'Program administrator' => 'Program administrator',
    ),
    'module' => 'eck',
  );

  // Exported permission: 'eck edit bundles'.
  $permissions['eck edit bundles'] = array(
    'name' => 'eck edit bundles',
    'roles' => array(
      'Overall Administrator' => 'Overall Administrator',
    ),
    'module' => 'eck',
  );

  // Exported permission: 'eck edit entities'.
  $permissions['eck edit entities'] = array(
    'name' => 'eck edit entities',
    'roles' => array(
      'Overall Administrator' => 'Overall Administrator',
    ),
    'module' => 'eck',
  );

  // Exported permission: 'eck edit entity types'.
  $permissions['eck edit entity types'] = array(
    'name' => 'eck edit entity types',
    'roles' => array(
      'Overall Administrator' => 'Overall Administrator',
    ),
    'module' => 'eck',
  );

  // Exported permission: 'eck edit reward bundles'.
  $permissions['eck edit reward bundles'] = array(
    'name' => 'eck edit reward bundles',
    'roles' => array(
      'Program administrator' => 'Program administrator',
    ),
    'module' => 'eck',
  );

  // Exported permission: 'eck edit reward raffle_claim entities'.
  $permissions['eck edit reward raffle_claim entities'] = array(
    'name' => 'eck edit reward raffle_claim entities',
    'roles' => array(
      'Program administrator' => 'Program administrator',
    ),
    'module' => 'eck',
  );

  // Exported permission: 'eck edit reward reward entities'.
  $permissions['eck edit reward reward entities'] = array(
    'name' => 'eck edit reward reward entities',
    'roles' => array(
      'Program administrator' => 'Program administrator',
    ),
    'module' => 'eck',
  );

  // Exported permission: 'eck edit reward reward_claim entities'.
  $permissions['eck edit reward reward_claim entities'] = array(
    'name' => 'eck edit reward reward_claim entities',
    'roles' => array(
      'Program administrator' => 'Program administrator',
    ),
    'module' => 'eck',
  );

  // Exported permission: 'eck list activity activity entities'.
  $permissions['eck list activity activity entities'] = array(
    'name' => 'eck list activity activity entities',
    'roles' => array(
      'Lead Staff' => 'Lead Staff',
      'Program administrator' => 'Program administrator',
    ),
    'module' => 'eck',
  );

  // Exported permission: 'eck list activity activity_entry entities'.
  $permissions['eck list activity activity_entry entities'] = array(
    'name' => 'eck list activity activity_entry entities',
    'roles' => array(
      'Lead Staff' => 'Lead Staff',
      'Program administrator' => 'Program administrator',
    ),
    'module' => 'eck',
  );

  // Exported permission: 'eck list activity bundles'.
  $permissions['eck list activity bundles'] = array(
    'name' => 'eck list activity bundles',
    'roles' => array(
      'Program administrator' => 'Program administrator',
    ),
    'module' => 'eck',
  );

  // Exported permission: 'eck list avatar avatar entities'.
  $permissions['eck list avatar avatar entities'] = array(
    'name' => 'eck list avatar avatar entities',
    'roles' => array(
      'Program administrator' => 'Program administrator',
    ),
    'module' => 'eck',
  );

  // Exported permission: 'eck list avatar bundles'.
  $permissions['eck list avatar bundles'] = array(
    'name' => 'eck list avatar bundles',
    'roles' => array(
      'Lead Staff' => 'Lead Staff',
      'Program administrator' => 'Program administrator',
    ),
    'module' => 'eck',
  );

  // Exported permission: 'eck list booklist_item booklist_item entities'.
  $permissions['eck list booklist_item booklist_item entities'] = array(
    'name' => 'eck list booklist_item booklist_item entities',
    'roles' => array(
      'Lead Staff' => 'Lead Staff',
      'Patron' => 'Patron',
      'Program administrator' => 'Program administrator',
      'Staff' => 'Staff',
    ),
    'module' => 'eck',
  );

  // Exported permission: 'eck list booklist_item bundles'.
  $permissions['eck list booklist_item bundles'] = array(
    'name' => 'eck list booklist_item bundles',
    'roles' => array(
      'Lead Staff' => 'Lead Staff',
      'Program administrator' => 'Program administrator',
      'Staff' => 'Staff',
    ),
    'module' => 'eck',
  );

  // Exported permission: 'eck list bundles'.
  $permissions['eck list bundles'] = array(
    'name' => 'eck list bundles',
    'roles' => array(
      'Overall Administrator' => 'Overall Administrator',
    ),
    'module' => 'eck',
  );

  // Exported permission: 'eck list entities'.
  $permissions['eck list entities'] = array(
    'name' => 'eck list entities',
    'roles' => array(
      'Lead Staff' => 'Lead Staff',
      'Overall Administrator' => 'Overall Administrator',
      'Program administrator' => 'Program administrator',
      'Staff' => 'Staff',
    ),
    'module' => 'eck',
  );

  // Exported permission: 'eck list entity types'.
  $permissions['eck list entity types'] = array(
    'name' => 'eck list entity types',
    'roles' => array(
      'Overall Administrator' => 'Overall Administrator',
    ),
    'module' => 'eck',
  );

  // Exported permission: 'eck list reward bundles'.
  $permissions['eck list reward bundles'] = array(
    'name' => 'eck list reward bundles',
    'roles' => array(
      'Lead Staff' => 'Lead Staff',
      'Program administrator' => 'Program administrator',
      'Staff' => 'Staff',
    ),
    'module' => 'eck',
  );

  // Exported permission: 'eck list reward raffle_claim entities'.
  $permissions['eck list reward raffle_claim entities'] = array(
    'name' => 'eck list reward raffle_claim entities',
    'roles' => array(
      'Lead Staff' => 'Lead Staff',
      'Program administrator' => 'Program administrator',
      'Staff' => 'Staff',
    ),
    'module' => 'eck',
  );

  // Exported permission: 'eck list reward reward entities'.
  $permissions['eck list reward reward entities'] = array(
    'name' => 'eck list reward reward entities',
    'roles' => array(
      'Lead Staff' => 'Lead Staff',
      'Program administrator' => 'Program administrator',
      'Staff' => 'Staff',
    ),
    'module' => 'eck',
  );

  // Exported permission: 'eck list reward reward_claim entities'.
  $permissions['eck list reward reward_claim entities'] = array(
    'name' => 'eck list reward reward_claim entities',
    'roles' => array(
      'Lead Staff' => 'Lead Staff',
      'Program administrator' => 'Program administrator',
      'Staff' => 'Staff',
    ),
    'module' => 'eck',
  );

  // Exported permission: 'eck view activity activity entities'.
  $permissions['eck view activity activity entities'] = array(
    'name' => 'eck view activity activity entities',
    'roles' => array(
      'Lead Staff' => 'Lead Staff',
      'Program administrator' => 'Program administrator',
    ),
    'module' => 'eck',
  );

  // Exported permission: 'eck view activity activity_entry entities'.
  $permissions['eck view activity activity_entry entities'] = array(
    'name' => 'eck view activity activity_entry entities',
    'roles' => array(
      'Lead Staff' => 'Lead Staff',
      'Program administrator' => 'Program administrator',
    ),
    'module' => 'eck',
  );

  // Exported permission: 'eck view activity bundles'.
  $permissions['eck view activity bundles'] = array(
    'name' => 'eck view activity bundles',
    'roles' => array(
      'Program administrator' => 'Program administrator',
    ),
    'module' => 'eck',
  );

  // Exported permission: 'eck view avatar avatar entities'.
  $permissions['eck view avatar avatar entities'] = array(
    'name' => 'eck view avatar avatar entities',
    'roles' => array(
      'Program administrator' => 'Program administrator',
    ),
    'module' => 'eck',
  );

  // Exported permission: 'eck view avatar bundles'.
  $permissions['eck view avatar bundles'] = array(
    'name' => 'eck view avatar bundles',
    'roles' => array(
      'Lead Staff' => 'Lead Staff',
      'Program administrator' => 'Program administrator',
    ),
    'module' => 'eck',
  );

  // Exported permission: 'eck view booklist_item booklist_item entities'.
  $permissions['eck view booklist_item booklist_item entities'] = array(
    'name' => 'eck view booklist_item booklist_item entities',
    'roles' => array(
      'Lead Staff' => 'Lead Staff',
      'Program administrator' => 'Program administrator',
      'Staff' => 'Staff',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'eck',
  );

  // Exported permission: 'eck view booklist_item bundles'.
  $permissions['eck view booklist_item bundles'] = array(
    'name' => 'eck view booklist_item bundles',
    'roles' => array(
      'Lead Staff' => 'Lead Staff',
      'Patron' => 'Patron',
      'Program administrator' => 'Program administrator',
      'Staff' => 'Staff',
    ),
    'module' => 'eck',
  );

  // Exported permission: 'eck view entities'.
  $permissions['eck view entities'] = array(
    'name' => 'eck view entities',
    'roles' => array(
      'Lead Staff' => 'Lead Staff',
      'Overall Administrator' => 'Overall Administrator',
      'Patron' => 'Patron',
      'Program administrator' => 'Program administrator',
      'Staff' => 'Staff',
    ),
    'module' => 'eck',
  );

  // Exported permission: 'eck view reward bundles'.
  $permissions['eck view reward bundles'] = array(
    'name' => 'eck view reward bundles',
    'roles' => array(
      'Lead Staff' => 'Lead Staff',
      'Program administrator' => 'Program administrator',
      'Staff' => 'Staff',
    ),
    'module' => 'eck',
  );

  // Exported permission: 'eck view reward raffle_claim entities'.
  $permissions['eck view reward raffle_claim entities'] = array(
    'name' => 'eck view reward raffle_claim entities',
    'roles' => array(
      'Lead Staff' => 'Lead Staff',
      'Program administrator' => 'Program administrator',
      'Staff' => 'Staff',
    ),
    'module' => 'eck',
  );

  // Exported permission: 'eck view reward reward entities'.
  $permissions['eck view reward reward entities'] = array(
    'name' => 'eck view reward reward entities',
    'roles' => array(
      'Lead Staff' => 'Lead Staff',
      'Program administrator' => 'Program administrator',
      'Staff' => 'Staff',
    ),
    'module' => 'eck',
  );

  // Exported permission: 'eck view reward reward_claim entities'.
  $permissions['eck view reward reward_claim entities'] = array(
    'name' => 'eck view reward reward_claim entities',
    'roles' => array(
      'Lead Staff' => 'Lead Staff',
      'Program administrator' => 'Program administrator',
      'Staff' => 'Staff',
    ),
    'module' => 'eck',
  );

  // Exported permission: 'edit all webform submissions'.
  $permissions['edit all webform submissions'] = array(
    'name' => 'edit all webform submissions',
    'roles' => array(
      'Overall Administrator' => 'Overall Administrator',
      'Program administrator' => 'Program administrator',
    ),
    'module' => 'webform',
  );

  // Exported permission: 'edit any _flickr_images content'.
  $permissions['edit any _flickr_images content'] = array(
    'name' => 'edit any _flickr_images content',
    'roles' => array(
      'Lead Staff' => 'Lead Staff',
      'Program administrator' => 'Program administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit any article content'.
  $permissions['edit any article content'] = array(
    'name' => 'edit any article content',
    'roles' => array(
      'Overall Administrator' => 'Overall Administrator',
      'Program administrator' => 'Program administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit any booklist content'.
  $permissions['edit any booklist content'] = array(
    'name' => 'edit any booklist content',
    'roles' => array(
      'Lead Staff' => 'Lead Staff',
      'Program administrator' => 'Program administrator',
      'Staff' => 'Staff',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit any event content'.
  $permissions['edit any event content'] = array(
    'name' => 'edit any event content',
    'roles' => array(
      'Program administrator' => 'Program administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit any event_activities content'.
  $permissions['edit any event_activities content'] = array(
    'name' => 'edit any event_activities content',
    'roles' => array(
      'Lead Staff' => 'Lead Staff',
      'Program administrator' => 'Program administrator',
      'Staff' => 'Staff',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit any library_pages content'.
  $permissions['edit any library_pages content'] = array(
    'name' => 'edit any library_pages content',
    'roles' => array(
      'Program administrator' => 'Program administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit any main profile'.
  $permissions['edit any main profile'] = array(
    'name' => 'edit any main profile',
    'roles' => array(
      'Lead Staff' => 'Lead Staff',
      'Overall Administrator' => 'Overall Administrator',
      'Program administrator' => 'Program administrator',
    ),
    'module' => 'profile2',
  );

  // Exported permission: 'edit any movie_review content'.
  $permissions['edit any movie_review content'] = array(
    'name' => 'edit any movie_review content',
    'roles' => array(
      'Patron' => 'Patron',
      'Program administrator' => 'Program administrator',
      'Staff' => 'Staff',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit any music_review content'.
  $permissions['edit any music_review content'] = array(
    'name' => 'edit any music_review content',
    'roles' => array(
      'Patron' => 'Patron',
      'Program administrator' => 'Program administrator',
      'Staff' => 'Staff',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit any page content'.
  $permissions['edit any page content'] = array(
    'name' => 'edit any page content',
    'roles' => array(
      'Overall Administrator' => 'Overall Administrator',
      'Program administrator' => 'Program administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit any poll content'.
  $permissions['edit any poll content'] = array(
    'name' => 'edit any poll content',
    'roles' => array(
      'Lead Staff' => 'Lead Staff',
      'Program administrator' => 'Program administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit any program content'.
  $permissions['edit any program content'] = array(
    'name' => 'edit any program content',
    'roles' => array(
      'Lead Staff' => 'Lead Staff',
      'Program administrator' => 'Program administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit any review_activity content'.
  $permissions['edit any review_activity content'] = array(
    'name' => 'edit any review_activity content',
    'roles' => array(
      'Overall Administrator' => 'Overall Administrator',
      'Program administrator' => 'Program administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit any review_book content'.
  $permissions['edit any review_book content'] = array(
    'name' => 'edit any review_book content',
    'roles' => array(
      'Lead Staff' => 'Lead Staff',
      'Program administrator' => 'Program administrator',
      'Staff' => 'Staff',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit any sticker content'.
  $permissions['edit any sticker content'] = array(
    'name' => 'edit any sticker content',
    'roles' => array(
      'Program administrator' => 'Program administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit any video_game_review content'.
  $permissions['edit any video_game_review content'] = array(
    'name' => 'edit any video_game_review content',
    'roles' => array(
      'Lead Staff' => 'Lead Staff',
      'Program administrator' => 'Program administrator',
      'Staff' => 'Staff',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit any videos content'.
  $permissions['edit any videos content'] = array(
    'name' => 'edit any videos content',
    'roles' => array(
      'Lead Staff' => 'Lead Staff',
      'Program administrator' => 'Program administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit any webform content'.
  $permissions['edit any webform content'] = array(
    'name' => 'edit any webform content',
    'roles' => array(
      'Lead Staff' => 'Lead Staff',
      'Program administrator' => 'Program administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit field_booklist_cover_image'.
  $permissions['edit field_booklist_cover_image'] = array(
    'name' => 'edit field_booklist_cover_image',
    'roles' => array(
      'Lead Staff' => 'Lead Staff',
      'Overall Administrator' => 'Overall Administrator',
      'Program administrator' => 'Program administrator',
      'Staff' => 'Staff',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit field_movie_cover_image_link'.
  $permissions['edit field_movie_cover_image_link'] = array(
    'name' => 'edit field_movie_cover_image_link',
    'roles' => array(),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit field_music_cover_image_link'.
  $permissions['edit field_music_cover_image_link'] = array(
    'name' => 'edit field_music_cover_image_link',
    'roles' => array(
      'Lead Staff' => 'Lead Staff',
      'Program administrator' => 'Program administrator',
      'Staff' => 'Staff',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit field_video_game_cover_image_lin'.
  $permissions['edit field_video_game_cover_image_lin'] = array(
    'name' => 'edit field_video_game_cover_image_lin',
    'roles' => array(
      'Lead Staff' => 'Lead Staff',
      'Program administrator' => 'Program administrator',
      'Staff' => 'Staff',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit media'.
  $permissions['edit media'] = array(
    'name' => 'edit media',
    'roles' => array(
      'Overall Administrator' => 'Overall Administrator',
    ),
    'module' => 'media',
  );

  // Exported permission: 'edit own _flickr_images content'.
  $permissions['edit own _flickr_images content'] = array(
    'name' => 'edit own _flickr_images content',
    'roles' => array(
      'Lead Staff' => 'Lead Staff',
      'Program administrator' => 'Program administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit own article content'.
  $permissions['edit own article content'] = array(
    'name' => 'edit own article content',
    'roles' => array(
      'Overall Administrator' => 'Overall Administrator',
      'Program administrator' => 'Program administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit own booklist content'.
  $permissions['edit own booklist content'] = array(
    'name' => 'edit own booklist content',
    'roles' => array(
      'Program administrator' => 'Program administrator',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit own event content'.
  $permissions['edit own event content'] = array(
    'name' => 'edit own event content',
    'roles' => array(
      'Program administrator' => 'Program administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit own event_activities content'.
  $permissions['edit own event_activities content'] = array(
    'name' => 'edit own event_activities content',
    'roles' => array(
      'Lead Staff' => 'Lead Staff',
      'Program administrator' => 'Program administrator',
      'Staff' => 'Staff',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit own field_booklist_cover_image'.
  $permissions['edit own field_booklist_cover_image'] = array(
    'name' => 'edit own field_booklist_cover_image',
    'roles' => array(
      'Lead Staff' => 'Lead Staff',
      'Overall Administrator' => 'Overall Administrator',
      'Program administrator' => 'Program administrator',
      'Staff' => 'Staff',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit own field_movie_cover_image_link'.
  $permissions['edit own field_movie_cover_image_link'] = array(
    'name' => 'edit own field_movie_cover_image_link',
    'roles' => array(),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit own field_music_cover_image_link'.
  $permissions['edit own field_music_cover_image_link'] = array(
    'name' => 'edit own field_music_cover_image_link',
    'roles' => array(
      'Lead Staff' => 'Lead Staff',
      'Program administrator' => 'Program administrator',
      'Staff' => 'Staff',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit own field_video_game_cover_image_lin'.
  $permissions['edit own field_video_game_cover_image_lin'] = array(
    'name' => 'edit own field_video_game_cover_image_lin',
    'roles' => array(
      'Lead Staff' => 'Lead Staff',
      'Program administrator' => 'Program administrator',
      'Staff' => 'Staff',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit own library_pages content'.
  $permissions['edit own library_pages content'] = array(
    'name' => 'edit own library_pages content',
    'roles' => array(
      'Program administrator' => 'Program administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit own main profile'.
  $permissions['edit own main profile'] = array(
    'name' => 'edit own main profile',
    'roles' => array(
      'Lead Staff' => 'Lead Staff',
      'Overall Administrator' => 'Overall Administrator',
      'Program administrator' => 'Program administrator',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'profile2',
  );

  // Exported permission: 'edit own movie_review content'.
  $permissions['edit own movie_review content'] = array(
    'name' => 'edit own movie_review content',
    'roles' => array(
      'Program administrator' => 'Program administrator',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit own music_review content'.
  $permissions['edit own music_review content'] = array(
    'name' => 'edit own music_review content',
    'roles' => array(
      'Program administrator' => 'Program administrator',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit own page content'.
  $permissions['edit own page content'] = array(
    'name' => 'edit own page content',
    'roles' => array(
      'Overall Administrator' => 'Overall Administrator',
      'Program administrator' => 'Program administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit own poll content'.
  $permissions['edit own poll content'] = array(
    'name' => 'edit own poll content',
    'roles' => array(
      'Lead Staff' => 'Lead Staff',
      'Program administrator' => 'Program administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit own program content'.
  $permissions['edit own program content'] = array(
    'name' => 'edit own program content',
    'roles' => array(
      'Lead Staff' => 'Lead Staff',
      'Program administrator' => 'Program administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit own review_activity content'.
  $permissions['edit own review_activity content'] = array(
    'name' => 'edit own review_activity content',
    'roles' => array(
      'Overall Administrator' => 'Overall Administrator',
      'Program administrator' => 'Program administrator',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit own review_book content'.
  $permissions['edit own review_book content'] = array(
    'name' => 'edit own review_book content',
    'roles' => array(
      'Program administrator' => 'Program administrator',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit own sticker content'.
  $permissions['edit own sticker content'] = array(
    'name' => 'edit own sticker content',
    'roles' => array(
      'Program administrator' => 'Program administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit own video_game_review content'.
  $permissions['edit own video_game_review content'] = array(
    'name' => 'edit own video_game_review content',
    'roles' => array(
      'Program administrator' => 'Program administrator',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit own videos content'.
  $permissions['edit own videos content'] = array(
    'name' => 'edit own videos content',
    'roles' => array(
      'Lead Staff' => 'Lead Staff',
      'Program administrator' => 'Program administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit own webform content'.
  $permissions['edit own webform content'] = array(
    'name' => 'edit own webform content',
    'roles' => array(
      'Lead Staff' => 'Lead Staff',
      'Program administrator' => 'Program administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit own webform submissions'.
  $permissions['edit own webform submissions'] = array(
    'name' => 'edit own webform submissions',
    'roles' => array(
      'Overall Administrator' => 'Overall Administrator',
      'Program administrator' => 'Program administrator',
    ),
    'module' => 'webform',
  );

  // Exported permission: 'edit terms in audience'.
  $permissions['edit terms in audience'] = array(
    'name' => 'edit terms in audience',
    'roles' => array(),
    'module' => 'taxonomy',
  );

  // Exported permission: 'edit terms in avatars'.
  $permissions['edit terms in avatars'] = array(
    'name' => 'edit terms in avatars',
    'roles' => array(
      'Program administrator' => 'Program administrator',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: 'edit terms in calendar_sticker'.
  $permissions['edit terms in calendar_sticker'] = array(
    'name' => 'edit terms in calendar_sticker',
    'roles' => array(
      'Program administrator' => 'Program administrator',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: 'edit terms in current_program'.
  $permissions['edit terms in current_program'] = array(
    'name' => 'edit terms in current_program',
    'roles' => array(
      'Program administrator' => 'Program administrator',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: 'edit terms in grade'.
  $permissions['edit terms in grade'] = array(
    'name' => 'edit terms in grade',
    'roles' => array(
      'Program administrator' => 'Program administrator',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: 'edit terms in library_branch'.
  $permissions['edit terms in library_branch'] = array(
    'name' => 'edit terms in library_branch',
    'roles' => array(
      'Program administrator' => 'Program administrator',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: 'edit terms in library_pages'.
  $permissions['edit terms in library_pages'] = array(
    'name' => 'edit terms in library_pages',
    'roles' => array(
      'Program administrator' => 'Program administrator',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: 'edit terms in organization'.
  $permissions['edit terms in organization'] = array(
    'name' => 'edit terms in organization',
    'roles' => array(
      'Program administrator' => 'Program administrator',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: 'edit terms in program_referrers'.
  $permissions['edit terms in program_referrers'] = array(
    'name' => 'edit terms in program_referrers',
    'roles' => array(
      'Program administrator' => 'Program administrator',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: 'edit terms in schools'.
  $permissions['edit terms in schools'] = array(
    'name' => 'edit terms in schools',
    'roles' => array(
      'Program administrator' => 'Program administrator',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: 'edit terms in tags'.
  $permissions['edit terms in tags'] = array(
    'name' => 'edit terms in tags',
    'roles' => array(
      'Overall Administrator' => 'Overall Administrator',
      'Program administrator' => 'Program administrator',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: 'edit terms in type_of_reward'.
  $permissions['edit terms in type_of_reward'] = array(
    'name' => 'edit terms in type_of_reward',
    'roles' => array(),
    'module' => 'taxonomy',
  );

  // Exported permission: 'edit terms in userpoints'.
  $permissions['edit terms in userpoints'] = array(
    'name' => 'edit terms in userpoints',
    'roles' => array(),
    'module' => 'taxonomy',
  );

  // Exported permission: 'edit userpoints'.
  $permissions['edit userpoints'] = array(
    'name' => 'edit userpoints',
    'roles' => array(
      'Overall Administrator' => 'Overall Administrator',
    ),
    'module' => 'userpoints',
  );

  // Exported permission: 'edit users with role 2'.
  $permissions['edit users with role 2'] = array(
    'name' => 'edit users with role 2',
    'roles' => array(
      'Lead Staff' => 'Lead Staff',
      'Overall Administrator' => 'Overall Administrator',
      'Program administrator' => 'Program administrator',
      'Staff' => 'Staff',
    ),
    'module' => 'administerusersbyrole',
  );

  // Exported permission: 'edit users with role 4'.
  $permissions['edit users with role 4'] = array(
    'name' => 'edit users with role 4',
    'roles' => array(
      'Lead Staff' => 'Lead Staff',
      'Overall Administrator' => 'Overall Administrator',
      'Program administrator' => 'Program administrator',
      'Staff' => 'Staff',
    ),
    'module' => 'administerusersbyrole',
  );

  // Exported permission: 'edit users with role 5'.
  $permissions['edit users with role 5'] = array(
    'name' => 'edit users with role 5',
    'roles' => array(
      'Lead Staff' => 'Lead Staff',
      'Overall Administrator' => 'Overall Administrator',
      'Program administrator' => 'Program administrator',
      'Staff' => 'Staff',
    ),
    'module' => 'administerusersbyrole',
  );

  // Exported permission: 'edit users with role 6'.
  $permissions['edit users with role 6'] = array(
    'name' => 'edit users with role 6',
    'roles' => array(
      'Overall Administrator' => 'Overall Administrator',
      'Program administrator' => 'Program administrator',
    ),
    'module' => 'administerusersbyrole',
  );

  // Exported permission: 'edit users with role 7'.
  $permissions['edit users with role 7'] = array(
    'name' => 'edit users with role 7',
    'roles' => array(
      'Overall Administrator' => 'Overall Administrator',
      'Program administrator' => 'Program administrator',
    ),
    'module' => 'administerusersbyrole',
  );

  // Exported permission: 'edit users with role 8'.
  $permissions['edit users with role 8'] = array(
    'name' => 'edit users with role 8',
    'roles' => array(
      'Overall Administrator' => 'Overall Administrator',
      'Program administrator' => 'Program administrator',
    ),
    'module' => 'administerusersbyrole',
  );

  // Exported permission: 'edit webform components'.
  $permissions['edit webform components'] = array(
    'name' => 'edit webform components',
    'roles' => array(
      'Overall Administrator' => 'Overall Administrator',
      'Program administrator' => 'Program administrator',
    ),
    'module' => 'webform',
  );

  // Exported permission: 'enter _flickr_images revision log entry'.
  $permissions['enter _flickr_images revision log entry'] = array(
    'name' => 'enter _flickr_images revision log entry',
    'roles' => array(
      'Overall Administrator' => 'Overall Administrator',
    ),
    'module' => 'override_node_options',
  );

  // Exported permission: 'enter article revision log entry'.
  $permissions['enter article revision log entry'] = array(
    'name' => 'enter article revision log entry',
    'roles' => array(
      'Overall Administrator' => 'Overall Administrator',
    ),
    'module' => 'override_node_options',
  );

  // Exported permission: 'enter booklist revision log entry'.
  $permissions['enter booklist revision log entry'] = array(
    'name' => 'enter booklist revision log entry',
    'roles' => array(
      'Overall Administrator' => 'Overall Administrator',
    ),
    'module' => 'override_node_options',
  );

  // Exported permission: 'enter event revision log entry'.
  $permissions['enter event revision log entry'] = array(
    'name' => 'enter event revision log entry',
    'roles' => array(
      'Overall Administrator' => 'Overall Administrator',
    ),
    'module' => 'override_node_options',
  );

  // Exported permission: 'enter event_activities revision log entry'.
  $permissions['enter event_activities revision log entry'] = array(
    'name' => 'enter event_activities revision log entry',
    'roles' => array(
      'Overall Administrator' => 'Overall Administrator',
    ),
    'module' => 'override_node_options',
  );

  // Exported permission: 'enter library_pages revision log entry'.
  $permissions['enter library_pages revision log entry'] = array(
    'name' => 'enter library_pages revision log entry',
    'roles' => array(
      'Overall Administrator' => 'Overall Administrator',
    ),
    'module' => 'override_node_options',
  );

  // Exported permission: 'enter movie_review revision log entry'.
  $permissions['enter movie_review revision log entry'] = array(
    'name' => 'enter movie_review revision log entry',
    'roles' => array(
      'Overall Administrator' => 'Overall Administrator',
    ),
    'module' => 'override_node_options',
  );

  // Exported permission: 'enter music_review revision log entry'.
  $permissions['enter music_review revision log entry'] = array(
    'name' => 'enter music_review revision log entry',
    'roles' => array(
      'Overall Administrator' => 'Overall Administrator',
    ),
    'module' => 'override_node_options',
  );

  // Exported permission: 'enter page revision log entry'.
  $permissions['enter page revision log entry'] = array(
    'name' => 'enter page revision log entry',
    'roles' => array(
      'Overall Administrator' => 'Overall Administrator',
    ),
    'module' => 'override_node_options',
  );

  // Exported permission: 'enter poll revision log entry'.
  $permissions['enter poll revision log entry'] = array(
    'name' => 'enter poll revision log entry',
    'roles' => array(
      'Overall Administrator' => 'Overall Administrator',
    ),
    'module' => 'override_node_options',
  );

  // Exported permission: 'enter program revision log entry'.
  $permissions['enter program revision log entry'] = array(
    'name' => 'enter program revision log entry',
    'roles' => array(
      'Overall Administrator' => 'Overall Administrator',
    ),
    'module' => 'override_node_options',
  );

  // Exported permission: 'enter review_activity revision log entry'.
  $permissions['enter review_activity revision log entry'] = array(
    'name' => 'enter review_activity revision log entry',
    'roles' => array(
      'Overall Administrator' => 'Overall Administrator',
    ),
    'module' => 'override_node_options',
  );

  // Exported permission: 'enter review_book revision log entry'.
  $permissions['enter review_book revision log entry'] = array(
    'name' => 'enter review_book revision log entry',
    'roles' => array(
      'Overall Administrator' => 'Overall Administrator',
    ),
    'module' => 'override_node_options',
  );

  // Exported permission: 'enter sticker revision log entry'.
  $permissions['enter sticker revision log entry'] = array(
    'name' => 'enter sticker revision log entry',
    'roles' => array(
      'Overall Administrator' => 'Overall Administrator',
    ),
    'module' => 'override_node_options',
  );

  // Exported permission: 'enter video_game_review revision log entry'.
  $permissions['enter video_game_review revision log entry'] = array(
    'name' => 'enter video_game_review revision log entry',
    'roles' => array(
      'Overall Administrator' => 'Overall Administrator',
    ),
    'module' => 'override_node_options',
  );

  // Exported permission: 'enter videos revision log entry'.
  $permissions['enter videos revision log entry'] = array(
    'name' => 'enter videos revision log entry',
    'roles' => array(
      'Overall Administrator' => 'Overall Administrator',
    ),
    'module' => 'override_node_options',
  );

  // Exported permission: 'enter webform revision log entry'.
  $permissions['enter webform revision log entry'] = array(
    'name' => 'enter webform revision log entry',
    'roles' => array(
      'Overall Administrator' => 'Overall Administrator',
    ),
    'module' => 'override_node_options',
  );

  // Exported permission: 'exclude any node title'.
  $permissions['exclude any node title'] = array(
    'name' => 'exclude any node title',
    'roles' => array(
      'Overall Administrator' => 'Overall Administrator',
    ),
    'module' => 'exclude_node_title',
  );

  // Exported permission: 'exclude from message filtering'.
  $permissions['exclude from message filtering'] = array(
    'name' => 'exclude from message filtering',
    'roles' => array(
      'Overall Administrator' => 'Overall Administrator',
    ),
    'module' => 'disable_messages',
  );

  // Exported permission: 'exclude own node title'.
  $permissions['exclude own node title'] = array(
    'name' => 'exclude own node title',
    'roles' => array(
      'Overall Administrator' => 'Overall Administrator',
    ),
    'module' => 'exclude_node_title',
  );

  // Exported permission: 'filter private messages'.
  $permissions['filter private messages'] = array(
    'name' => 'filter private messages',
    'roles' => array(
      'Overall Administrator' => 'Overall Administrator',
    ),
    'module' => 'privatemsg_filter',
  );

  // Exported permission: 'flag follow'.
  $permissions['flag follow'] = array(
    'name' => 'flag follow',
    'roles' => array(
      'Overall Administrator' => 'Overall Administrator',
      'Program administrator' => 'Program administrator',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'flag',
  );

  // Exported permission: 'flag like'.
  $permissions['flag like'] = array(
    'name' => 'flag like',
    'roles' => array(
      'Program administrator' => 'Program administrator',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'flag',
  );

  // Exported permission: 'flag primary_booklist'.
  $permissions['flag primary_booklist'] = array(
    'name' => 'flag primary_booklist',
    'roles' => array(
      'Overall Administrator' => 'Overall Administrator',
      'Program administrator' => 'Program administrator',
    ),
    'module' => 'flag',
  );

  // Exported permission: 'flag reward_claimed'.
  $permissions['flag reward_claimed'] = array(
    'name' => 'flag reward_claimed',
    'roles' => array(
      'Lead Staff' => 'Lead Staff',
      'Program administrator' => 'Program administrator',
    ),
    'module' => 'flag',
  );

  // Exported permission: 'flush caches'.
  $permissions['flush caches'] = array(
    'name' => 'flush caches',
    'roles' => array(
      'Overall Administrator' => 'Overall Administrator',
      'Program administrator' => 'Program administrator',
    ),
    'module' => 'admin_menu',
  );

  // Exported permission: 'generate features'.
  $permissions['generate features'] = array(
    'name' => 'generate features',
    'roles' => array(
      'Overall Administrator' => 'Overall Administrator',
    ),
    'module' => 'features',
  );

  // Exported permission: 'import avatars feeds'.
  $permissions['import avatars feeds'] = array(
    'name' => 'import avatars feeds',
    'roles' => array(
      'Program administrator' => 'Program administrator',
    ),
    'module' => 'feeds',
  );

  // Exported permission: 'import events feeds'.
  $permissions['import events feeds'] = array(
    'name' => 'import events feeds',
    'roles' => array(
      'Program administrator' => 'Program administrator',
    ),
    'module' => 'feeds',
  );

  // Exported permission: 'import media'.
  $permissions['import media'] = array(
    'name' => 'import media',
    'roles' => array(
      'Overall Administrator' => 'Overall Administrator',
    ),
    'module' => 'media',
  );

  // Exported permission: 'inspect all votes'.
  $permissions['inspect all votes'] = array(
    'name' => 'inspect all votes',
    'roles' => array(
      'Overall Administrator' => 'Overall Administrator',
    ),
    'module' => 'poll',
  );

  // Exported permission: 'manage activity properties'.
  $permissions['manage activity properties'] = array(
    'name' => 'manage activity properties',
    'roles' => array(),
    'module' => 'eck',
  );

  // Exported permission: 'manage avatar properties'.
  $permissions['manage avatar properties'] = array(
    'name' => 'manage avatar properties',
    'roles' => array(
      'Program administrator' => 'Program administrator',
    ),
    'module' => 'eck',
  );

  // Exported permission: 'manage booklist_item properties'.
  $permissions['manage booklist_item properties'] = array(
    'name' => 'manage booklist_item properties',
    'roles' => array(
      'Program administrator' => 'Program administrator',
    ),
    'module' => 'eck',
  );

  // Exported permission: 'manage en translation overview priorities'.
  $permissions['manage en translation overview priorities'] = array(
    'name' => 'manage en translation overview priorities',
    'roles' => array(
      'Overall Administrator' => 'Overall Administrator',
      'Program administrator' => 'Program administrator',
    ),
    'module' => 'translation_overview',
  );

  // Exported permission: 'manage es translation overview priorities'.
  $permissions['manage es translation overview priorities'] = array(
    'name' => 'manage es translation overview priorities',
    'roles' => array(
      'Overall Administrator' => 'Overall Administrator',
      'Program administrator' => 'Program administrator',
    ),
    'module' => 'translation_overview',
  );

  // Exported permission: 'manage features'.
  $permissions['manage features'] = array(
    'name' => 'manage features',
    'roles' => array(
      'Overall Administrator' => 'Overall Administrator',
    ),
    'module' => 'features',
  );

  // Exported permission: 'manage flexicolor settings'.
  $permissions['manage flexicolor settings'] = array(
    'name' => 'manage flexicolor settings',
    'roles' => array(
      'Overall Administrator' => 'Overall Administrator',
    ),
    'module' => 'flexicolor',
  );

  // Exported permission: 'manage reward properties'.
  $permissions['manage reward properties'] = array(
    'name' => 'manage reward properties',
    'roles' => array(
      'Program administrator' => 'Program administrator',
    ),
    'module' => 'eck',
  );

  // Exported permission: 'manage zh-hant translation overview priorities'.
  $permissions['manage zh-hant translation overview priorities'] = array(
    'name' => 'manage zh-hant translation overview priorities',
    'roles' => array(
      'Overall Administrator' => 'Overall Administrator',
      'Program administrator' => 'Program administrator',
    ),
    'module' => 'translation_overview',
  );

  // Exported permission: 'manipulate all entityqueues'.
  $permissions['manipulate all entityqueues'] = array(
    'name' => 'manipulate all entityqueues',
    'roles' => array(
      'Lead Staff' => 'Lead Staff',
      'Overall Administrator' => 'Overall Administrator',
      'Program administrator' => 'Program administrator',
    ),
    'module' => 'entityqueue',
  );

  // Exported permission: 'manipulate all queues'.
  $permissions['manipulate all queues'] = array(
    'name' => 'manipulate all queues',
    'roles' => array(
      'Overall Administrator' => 'Overall Administrator',
      'Program administrator' => 'Program administrator',
    ),
    'module' => 'nodequeue',
  );

  // Exported permission: 'manipulate entityqueues'.
  $permissions['manipulate entityqueues'] = array(
    'name' => 'manipulate entityqueues',
    'roles' => array(
      'Lead Staff' => 'Lead Staff',
      'Overall Administrator' => 'Overall Administrator',
      'Program administrator' => 'Program administrator',
    ),
    'module' => 'entityqueue',
  );

  // Exported permission: 'manipulate queues'.
  $permissions['manipulate queues'] = array(
    'name' => 'manipulate queues',
    'roles' => array(
      'Overall Administrator' => 'Overall Administrator',
      'Program administrator' => 'Program administrator',
    ),
    'module' => 'nodequeue',
  );

  // Exported permission: 'masquerade as admin'.
  $permissions['masquerade as admin'] = array(
    'name' => 'masquerade as admin',
    'roles' => array(
      'Overall Administrator' => 'Overall Administrator',
      'Program administrator' => 'Program administrator',
    ),
    'module' => 'masquerade',
  );

  // Exported permission: 'masquerade as any user'.
  $permissions['masquerade as any user'] = array(
    'name' => 'masquerade as any user',
    'roles' => array(
      'Overall Administrator' => 'Overall Administrator',
      'Program administrator' => 'Program administrator',
    ),
    'module' => 'masquerade',
  );

  // Exported permission: 'masquerade as user'.
  $permissions['masquerade as user'] = array(
    'name' => 'masquerade as user',
    'roles' => array(
      'Overall Administrator' => 'Overall Administrator',
      'Program administrator' => 'Program administrator',
    ),
    'module' => 'masquerade',
  );

  // Exported permission: 'moderate content from draft to needs_review'.
  $permissions['moderate content from draft to needs_review'] = array(
    'name' => 'moderate content from draft to needs_review',
    'roles' => array(
      'Lead Staff' => 'Lead Staff',
      'Overall Administrator' => 'Overall Administrator',
      'Program administrator' => 'Program administrator',
      'Staff' => 'Staff',
    ),
    'module' => 'workbench_moderation',
  );

  // Exported permission: 'moderate content from needs_review to draft'.
  $permissions['moderate content from needs_review to draft'] = array(
    'name' => 'moderate content from needs_review to draft',
    'roles' => array(
      'Lead Staff' => 'Lead Staff',
      'Overall Administrator' => 'Overall Administrator',
      'Program administrator' => 'Program administrator',
      'Staff' => 'Staff',
    ),
    'module' => 'workbench_moderation',
  );

  // Exported permission: 'moderate content from needs_review to published'.
  $permissions['moderate content from needs_review to published'] = array(
    'name' => 'moderate content from needs_review to published',
    'roles' => array(
      'Lead Staff' => 'Lead Staff',
      'Overall Administrator' => 'Overall Administrator',
      'Program administrator' => 'Program administrator',
    ),
    'module' => 'workbench_moderation',
  );

  // Exported permission: 'moderate userpoints'.
  $permissions['moderate userpoints'] = array(
    'name' => 'moderate userpoints',
    'roles' => array(
      'Overall Administrator' => 'Overall Administrator',
    ),
    'module' => 'userpoints',
  );

  // Exported permission: 'notify of path changes'.
  $permissions['notify of path changes'] = array(
    'name' => 'notify of path changes',
    'roles' => array(
      'Overall Administrator' => 'Overall Administrator',
    ),
    'module' => 'pathauto',
  );

  // Exported permission: 'override _flickr_images authored by option'.
  $permissions['override _flickr_images authored by option'] = array(
    'name' => 'override _flickr_images authored by option',
    'roles' => array(
      'Overall Administrator' => 'Overall Administrator',
    ),
    'module' => 'override_node_options',
  );

  // Exported permission: 'override _flickr_images authored on option'.
  $permissions['override _flickr_images authored on option'] = array(
    'name' => 'override _flickr_images authored on option',
    'roles' => array(
      'Overall Administrator' => 'Overall Administrator',
    ),
    'module' => 'override_node_options',
  );

  // Exported permission: 'override _flickr_images promote to front page option'.
  $permissions['override _flickr_images promote to front page option'] = array(
    'name' => 'override _flickr_images promote to front page option',
    'roles' => array(
      'Overall Administrator' => 'Overall Administrator',
    ),
    'module' => 'override_node_options',
  );

  // Exported permission: 'override _flickr_images published option'.
  $permissions['override _flickr_images published option'] = array(
    'name' => 'override _flickr_images published option',
    'roles' => array(
      'Overall Administrator' => 'Overall Administrator',
    ),
    'module' => 'override_node_options',
  );

  // Exported permission: 'override _flickr_images revision option'.
  $permissions['override _flickr_images revision option'] = array(
    'name' => 'override _flickr_images revision option',
    'roles' => array(
      'Overall Administrator' => 'Overall Administrator',
    ),
    'module' => 'override_node_options',
  );

  // Exported permission: 'override _flickr_images sticky option'.
  $permissions['override _flickr_images sticky option'] = array(
    'name' => 'override _flickr_images sticky option',
    'roles' => array(
      'Overall Administrator' => 'Overall Administrator',
    ),
    'module' => 'override_node_options',
  );

  // Exported permission: 'override article authored by option'.
  $permissions['override article authored by option'] = array(
    'name' => 'override article authored by option',
    'roles' => array(
      'Overall Administrator' => 'Overall Administrator',
    ),
    'module' => 'override_node_options',
  );

  // Exported permission: 'override article authored on option'.
  $permissions['override article authored on option'] = array(
    'name' => 'override article authored on option',
    'roles' => array(
      'Overall Administrator' => 'Overall Administrator',
    ),
    'module' => 'override_node_options',
  );

  // Exported permission: 'override article promote to front page option'.
  $permissions['override article promote to front page option'] = array(
    'name' => 'override article promote to front page option',
    'roles' => array(
      'Overall Administrator' => 'Overall Administrator',
    ),
    'module' => 'override_node_options',
  );

  // Exported permission: 'override article published option'.
  $permissions['override article published option'] = array(
    'name' => 'override article published option',
    'roles' => array(
      'Overall Administrator' => 'Overall Administrator',
    ),
    'module' => 'override_node_options',
  );

  // Exported permission: 'override article revision option'.
  $permissions['override article revision option'] = array(
    'name' => 'override article revision option',
    'roles' => array(
      'Overall Administrator' => 'Overall Administrator',
    ),
    'module' => 'override_node_options',
  );

  // Exported permission: 'override article sticky option'.
  $permissions['override article sticky option'] = array(
    'name' => 'override article sticky option',
    'roles' => array(
      'Overall Administrator' => 'Overall Administrator',
    ),
    'module' => 'override_node_options',
  );

  // Exported permission: 'override booklist authored by option'.
  $permissions['override booklist authored by option'] = array(
    'name' => 'override booklist authored by option',
    'roles' => array(
      'Lead Staff' => 'Lead Staff',
      'Overall Administrator' => 'Overall Administrator',
      'Staff' => 'Staff',
    ),
    'module' => 'override_node_options',
  );

  // Exported permission: 'override booklist authored on option'.
  $permissions['override booklist authored on option'] = array(
    'name' => 'override booklist authored on option',
    'roles' => array(
      'Overall Administrator' => 'Overall Administrator',
    ),
    'module' => 'override_node_options',
  );

  // Exported permission: 'override booklist promote to front page option'.
  $permissions['override booklist promote to front page option'] = array(
    'name' => 'override booklist promote to front page option',
    'roles' => array(
      'Overall Administrator' => 'Overall Administrator',
    ),
    'module' => 'override_node_options',
  );

  // Exported permission: 'override booklist published option'.
  $permissions['override booklist published option'] = array(
    'name' => 'override booklist published option',
    'roles' => array(
      'Lead Staff' => 'Lead Staff',
      'Overall Administrator' => 'Overall Administrator',
      'Program administrator' => 'Program administrator',
    ),
    'module' => 'override_node_options',
  );

  // Exported permission: 'override booklist revision option'.
  $permissions['override booklist revision option'] = array(
    'name' => 'override booklist revision option',
    'roles' => array(
      'Overall Administrator' => 'Overall Administrator',
    ),
    'module' => 'override_node_options',
  );

  // Exported permission: 'override booklist sticky option'.
  $permissions['override booklist sticky option'] = array(
    'name' => 'override booklist sticky option',
    'roles' => array(
      'Overall Administrator' => 'Overall Administrator',
    ),
    'module' => 'override_node_options',
  );

  // Exported permission: 'override event authored by option'.
  $permissions['override event authored by option'] = array(
    'name' => 'override event authored by option',
    'roles' => array(
      'Overall Administrator' => 'Overall Administrator',
    ),
    'module' => 'override_node_options',
  );

  // Exported permission: 'override event authored on option'.
  $permissions['override event authored on option'] = array(
    'name' => 'override event authored on option',
    'roles' => array(
      'Overall Administrator' => 'Overall Administrator',
    ),
    'module' => 'override_node_options',
  );

  // Exported permission: 'override event promote to front page option'.
  $permissions['override event promote to front page option'] = array(
    'name' => 'override event promote to front page option',
    'roles' => array(
      'Overall Administrator' => 'Overall Administrator',
    ),
    'module' => 'override_node_options',
  );

  // Exported permission: 'override event published option'.
  $permissions['override event published option'] = array(
    'name' => 'override event published option',
    'roles' => array(
      'Overall Administrator' => 'Overall Administrator',
    ),
    'module' => 'override_node_options',
  );

  // Exported permission: 'override event revision option'.
  $permissions['override event revision option'] = array(
    'name' => 'override event revision option',
    'roles' => array(
      'Overall Administrator' => 'Overall Administrator',
    ),
    'module' => 'override_node_options',
  );

  // Exported permission: 'override event sticky option'.
  $permissions['override event sticky option'] = array(
    'name' => 'override event sticky option',
    'roles' => array(
      'Overall Administrator' => 'Overall Administrator',
    ),
    'module' => 'override_node_options',
  );

  // Exported permission: 'override event_activities authored by option'.
  $permissions['override event_activities authored by option'] = array(
    'name' => 'override event_activities authored by option',
    'roles' => array(
      'Overall Administrator' => 'Overall Administrator',
    ),
    'module' => 'override_node_options',
  );

  // Exported permission: 'override event_activities authored on option'.
  $permissions['override event_activities authored on option'] = array(
    'name' => 'override event_activities authored on option',
    'roles' => array(
      'Overall Administrator' => 'Overall Administrator',
    ),
    'module' => 'override_node_options',
  );

  // Exported permission: 'override event_activities promote to front page option'.
  $permissions['override event_activities promote to front page option'] = array(
    'name' => 'override event_activities promote to front page option',
    'roles' => array(
      'Overall Administrator' => 'Overall Administrator',
    ),
    'module' => 'override_node_options',
  );

  // Exported permission: 'override event_activities published option'.
  $permissions['override event_activities published option'] = array(
    'name' => 'override event_activities published option',
    'roles' => array(
      'Overall Administrator' => 'Overall Administrator',
    ),
    'module' => 'override_node_options',
  );

  // Exported permission: 'override event_activities revision option'.
  $permissions['override event_activities revision option'] = array(
    'name' => 'override event_activities revision option',
    'roles' => array(
      'Overall Administrator' => 'Overall Administrator',
    ),
    'module' => 'override_node_options',
  );

  // Exported permission: 'override event_activities sticky option'.
  $permissions['override event_activities sticky option'] = array(
    'name' => 'override event_activities sticky option',
    'roles' => array(
      'Overall Administrator' => 'Overall Administrator',
    ),
    'module' => 'override_node_options',
  );

  // Exported permission: 'override library_pages authored by option'.
  $permissions['override library_pages authored by option'] = array(
    'name' => 'override library_pages authored by option',
    'roles' => array(
      'Overall Administrator' => 'Overall Administrator',
    ),
    'module' => 'override_node_options',
  );

  // Exported permission: 'override library_pages authored on option'.
  $permissions['override library_pages authored on option'] = array(
    'name' => 'override library_pages authored on option',
    'roles' => array(
      'Overall Administrator' => 'Overall Administrator',
    ),
    'module' => 'override_node_options',
  );

  // Exported permission: 'override library_pages promote to front page option'.
  $permissions['override library_pages promote to front page option'] = array(
    'name' => 'override library_pages promote to front page option',
    'roles' => array(
      'Overall Administrator' => 'Overall Administrator',
    ),
    'module' => 'override_node_options',
  );

  // Exported permission: 'override library_pages published option'.
  $permissions['override library_pages published option'] = array(
    'name' => 'override library_pages published option',
    'roles' => array(
      'Overall Administrator' => 'Overall Administrator',
    ),
    'module' => 'override_node_options',
  );

  // Exported permission: 'override library_pages revision option'.
  $permissions['override library_pages revision option'] = array(
    'name' => 'override library_pages revision option',
    'roles' => array(
      'Overall Administrator' => 'Overall Administrator',
    ),
    'module' => 'override_node_options',
  );

  // Exported permission: 'override library_pages sticky option'.
  $permissions['override library_pages sticky option'] = array(
    'name' => 'override library_pages sticky option',
    'roles' => array(
      'Overall Administrator' => 'Overall Administrator',
    ),
    'module' => 'override_node_options',
  );

  // Exported permission: 'override movie_review authored by option'.
  $permissions['override movie_review authored by option'] = array(
    'name' => 'override movie_review authored by option',
    'roles' => array(
      'Lead Staff' => 'Lead Staff',
      'Overall Administrator' => 'Overall Administrator',
      'Program administrator' => 'Program administrator',
      'Staff' => 'Staff',
    ),
    'module' => 'override_node_options',
  );

  // Exported permission: 'override movie_review authored on option'.
  $permissions['override movie_review authored on option'] = array(
    'name' => 'override movie_review authored on option',
    'roles' => array(
      'Overall Administrator' => 'Overall Administrator',
    ),
    'module' => 'override_node_options',
  );

  // Exported permission: 'override movie_review promote to front page option'.
  $permissions['override movie_review promote to front page option'] = array(
    'name' => 'override movie_review promote to front page option',
    'roles' => array(
      'Overall Administrator' => 'Overall Administrator',
    ),
    'module' => 'override_node_options',
  );

  // Exported permission: 'override movie_review published option'.
  $permissions['override movie_review published option'] = array(
    'name' => 'override movie_review published option',
    'roles' => array(
      'Lead Staff' => 'Lead Staff',
      'Overall Administrator' => 'Overall Administrator',
      'Program administrator' => 'Program administrator',
    ),
    'module' => 'override_node_options',
  );

  // Exported permission: 'override movie_review revision option'.
  $permissions['override movie_review revision option'] = array(
    'name' => 'override movie_review revision option',
    'roles' => array(
      'Overall Administrator' => 'Overall Administrator',
    ),
    'module' => 'override_node_options',
  );

  // Exported permission: 'override movie_review sticky option'.
  $permissions['override movie_review sticky option'] = array(
    'name' => 'override movie_review sticky option',
    'roles' => array(
      'Overall Administrator' => 'Overall Administrator',
    ),
    'module' => 'override_node_options',
  );

  // Exported permission: 'override music_review authored by option'.
  $permissions['override music_review authored by option'] = array(
    'name' => 'override music_review authored by option',
    'roles' => array(
      'Lead Staff' => 'Lead Staff',
      'Overall Administrator' => 'Overall Administrator',
      'Program administrator' => 'Program administrator',
      'Staff' => 'Staff',
    ),
    'module' => 'override_node_options',
  );

  // Exported permission: 'override music_review authored on option'.
  $permissions['override music_review authored on option'] = array(
    'name' => 'override music_review authored on option',
    'roles' => array(
      'Overall Administrator' => 'Overall Administrator',
    ),
    'module' => 'override_node_options',
  );

  // Exported permission: 'override music_review promote to front page option'.
  $permissions['override music_review promote to front page option'] = array(
    'name' => 'override music_review promote to front page option',
    'roles' => array(
      'Overall Administrator' => 'Overall Administrator',
    ),
    'module' => 'override_node_options',
  );

  // Exported permission: 'override music_review published option'.
  $permissions['override music_review published option'] = array(
    'name' => 'override music_review published option',
    'roles' => array(
      'Lead Staff' => 'Lead Staff',
      'Overall Administrator' => 'Overall Administrator',
    ),
    'module' => 'override_node_options',
  );

  // Exported permission: 'override music_review revision option'.
  $permissions['override music_review revision option'] = array(
    'name' => 'override music_review revision option',
    'roles' => array(
      'Overall Administrator' => 'Overall Administrator',
    ),
    'module' => 'override_node_options',
  );

  // Exported permission: 'override music_review sticky option'.
  $permissions['override music_review sticky option'] = array(
    'name' => 'override music_review sticky option',
    'roles' => array(
      'Overall Administrator' => 'Overall Administrator',
    ),
    'module' => 'override_node_options',
  );

  // Exported permission: 'override page authored by option'.
  $permissions['override page authored by option'] = array(
    'name' => 'override page authored by option',
    'roles' => array(
      'Overall Administrator' => 'Overall Administrator',
    ),
    'module' => 'override_node_options',
  );

  // Exported permission: 'override page authored on option'.
  $permissions['override page authored on option'] = array(
    'name' => 'override page authored on option',
    'roles' => array(
      'Overall Administrator' => 'Overall Administrator',
    ),
    'module' => 'override_node_options',
  );

  // Exported permission: 'override page promote to front page option'.
  $permissions['override page promote to front page option'] = array(
    'name' => 'override page promote to front page option',
    'roles' => array(
      'Overall Administrator' => 'Overall Administrator',
    ),
    'module' => 'override_node_options',
  );

  // Exported permission: 'override page published option'.
  $permissions['override page published option'] = array(
    'name' => 'override page published option',
    'roles' => array(
      'Overall Administrator' => 'Overall Administrator',
    ),
    'module' => 'override_node_options',
  );

  // Exported permission: 'override page revision option'.
  $permissions['override page revision option'] = array(
    'name' => 'override page revision option',
    'roles' => array(
      'Overall Administrator' => 'Overall Administrator',
    ),
    'module' => 'override_node_options',
  );

  // Exported permission: 'override page sticky option'.
  $permissions['override page sticky option'] = array(
    'name' => 'override page sticky option',
    'roles' => array(
      'Overall Administrator' => 'Overall Administrator',
    ),
    'module' => 'override_node_options',
  );

  // Exported permission: 'override poll authored by option'.
  $permissions['override poll authored by option'] = array(
    'name' => 'override poll authored by option',
    'roles' => array(
      'Overall Administrator' => 'Overall Administrator',
    ),
    'module' => 'override_node_options',
  );

  // Exported permission: 'override poll authored on option'.
  $permissions['override poll authored on option'] = array(
    'name' => 'override poll authored on option',
    'roles' => array(
      'Overall Administrator' => 'Overall Administrator',
    ),
    'module' => 'override_node_options',
  );

  // Exported permission: 'override poll promote to front page option'.
  $permissions['override poll promote to front page option'] = array(
    'name' => 'override poll promote to front page option',
    'roles' => array(
      'Overall Administrator' => 'Overall Administrator',
    ),
    'module' => 'override_node_options',
  );

  // Exported permission: 'override poll published option'.
  $permissions['override poll published option'] = array(
    'name' => 'override poll published option',
    'roles' => array(
      'Overall Administrator' => 'Overall Administrator',
    ),
    'module' => 'override_node_options',
  );

  // Exported permission: 'override poll revision option'.
  $permissions['override poll revision option'] = array(
    'name' => 'override poll revision option',
    'roles' => array(
      'Overall Administrator' => 'Overall Administrator',
    ),
    'module' => 'override_node_options',
  );

  // Exported permission: 'override poll sticky option'.
  $permissions['override poll sticky option'] = array(
    'name' => 'override poll sticky option',
    'roles' => array(
      'Overall Administrator' => 'Overall Administrator',
    ),
    'module' => 'override_node_options',
  );

  // Exported permission: 'override program authored by option'.
  $permissions['override program authored by option'] = array(
    'name' => 'override program authored by option',
    'roles' => array(
      'Overall Administrator' => 'Overall Administrator',
    ),
    'module' => 'override_node_options',
  );

  // Exported permission: 'override program authored on option'.
  $permissions['override program authored on option'] = array(
    'name' => 'override program authored on option',
    'roles' => array(
      'Overall Administrator' => 'Overall Administrator',
    ),
    'module' => 'override_node_options',
  );

  // Exported permission: 'override program promote to front page option'.
  $permissions['override program promote to front page option'] = array(
    'name' => 'override program promote to front page option',
    'roles' => array(
      'Overall Administrator' => 'Overall Administrator',
    ),
    'module' => 'override_node_options',
  );

  // Exported permission: 'override program published option'.
  $permissions['override program published option'] = array(
    'name' => 'override program published option',
    'roles' => array(
      'Overall Administrator' => 'Overall Administrator',
    ),
    'module' => 'override_node_options',
  );

  // Exported permission: 'override program revision option'.
  $permissions['override program revision option'] = array(
    'name' => 'override program revision option',
    'roles' => array(
      'Overall Administrator' => 'Overall Administrator',
    ),
    'module' => 'override_node_options',
  );

  // Exported permission: 'override program sticky option'.
  $permissions['override program sticky option'] = array(
    'name' => 'override program sticky option',
    'roles' => array(
      'Overall Administrator' => 'Overall Administrator',
    ),
    'module' => 'override_node_options',
  );

  // Exported permission: 'override review_activity authored by option'.
  $permissions['override review_activity authored by option'] = array(
    'name' => 'override review_activity authored by option',
    'roles' => array(
      'Lead Staff' => 'Lead Staff',
      'Overall Administrator' => 'Overall Administrator',
      'Program administrator' => 'Program administrator',
      'Staff' => 'Staff',
    ),
    'module' => 'override_node_options',
  );

  // Exported permission: 'override review_activity authored on option'.
  $permissions['override review_activity authored on option'] = array(
    'name' => 'override review_activity authored on option',
    'roles' => array(
      'Overall Administrator' => 'Overall Administrator',
    ),
    'module' => 'override_node_options',
  );

  // Exported permission: 'override review_activity promote to front page option'.
  $permissions['override review_activity promote to front page option'] = array(
    'name' => 'override review_activity promote to front page option',
    'roles' => array(
      'Overall Administrator' => 'Overall Administrator',
    ),
    'module' => 'override_node_options',
  );

  // Exported permission: 'override review_activity published option'.
  $permissions['override review_activity published option'] = array(
    'name' => 'override review_activity published option',
    'roles' => array(
      'Lead Staff' => 'Lead Staff',
      'Overall Administrator' => 'Overall Administrator',
      'Program administrator' => 'Program administrator',
    ),
    'module' => 'override_node_options',
  );

  // Exported permission: 'override review_activity revision option'.
  $permissions['override review_activity revision option'] = array(
    'name' => 'override review_activity revision option',
    'roles' => array(
      'Overall Administrator' => 'Overall Administrator',
    ),
    'module' => 'override_node_options',
  );

  // Exported permission: 'override review_activity sticky option'.
  $permissions['override review_activity sticky option'] = array(
    'name' => 'override review_activity sticky option',
    'roles' => array(
      'Overall Administrator' => 'Overall Administrator',
    ),
    'module' => 'override_node_options',
  );

  // Exported permission: 'override review_book authored by option'.
  $permissions['override review_book authored by option'] = array(
    'name' => 'override review_book authored by option',
    'roles' => array(
      'Lead Staff' => 'Lead Staff',
      'Overall Administrator' => 'Overall Administrator',
      'Program administrator' => 'Program administrator',
      'Staff' => 'Staff',
    ),
    'module' => 'override_node_options',
  );

  // Exported permission: 'override review_book authored on option'.
  $permissions['override review_book authored on option'] = array(
    'name' => 'override review_book authored on option',
    'roles' => array(
      'Overall Administrator' => 'Overall Administrator',
    ),
    'module' => 'override_node_options',
  );

  // Exported permission: 'override review_book promote to front page option'.
  $permissions['override review_book promote to front page option'] = array(
    'name' => 'override review_book promote to front page option',
    'roles' => array(
      'Overall Administrator' => 'Overall Administrator',
    ),
    'module' => 'override_node_options',
  );

  // Exported permission: 'override review_book published option'.
  $permissions['override review_book published option'] = array(
    'name' => 'override review_book published option',
    'roles' => array(
      'Lead Staff' => 'Lead Staff',
      'Overall Administrator' => 'Overall Administrator',
      'Program administrator' => 'Program administrator',
    ),
    'module' => 'override_node_options',
  );

  // Exported permission: 'override review_book revision option'.
  $permissions['override review_book revision option'] = array(
    'name' => 'override review_book revision option',
    'roles' => array(
      'Overall Administrator' => 'Overall Administrator',
    ),
    'module' => 'override_node_options',
  );

  // Exported permission: 'override review_book sticky option'.
  $permissions['override review_book sticky option'] = array(
    'name' => 'override review_book sticky option',
    'roles' => array(
      'Overall Administrator' => 'Overall Administrator',
    ),
    'module' => 'override_node_options',
  );

  // Exported permission: 'override sticker authored by option'.
  $permissions['override sticker authored by option'] = array(
    'name' => 'override sticker authored by option',
    'roles' => array(
      'Overall Administrator' => 'Overall Administrator',
    ),
    'module' => 'override_node_options',
  );

  // Exported permission: 'override sticker authored on option'.
  $permissions['override sticker authored on option'] = array(
    'name' => 'override sticker authored on option',
    'roles' => array(
      'Overall Administrator' => 'Overall Administrator',
    ),
    'module' => 'override_node_options',
  );

  // Exported permission: 'override sticker promote to front page option'.
  $permissions['override sticker promote to front page option'] = array(
    'name' => 'override sticker promote to front page option',
    'roles' => array(
      'Overall Administrator' => 'Overall Administrator',
    ),
    'module' => 'override_node_options',
  );

  // Exported permission: 'override sticker published option'.
  $permissions['override sticker published option'] = array(
    'name' => 'override sticker published option',
    'roles' => array(
      'Overall Administrator' => 'Overall Administrator',
    ),
    'module' => 'override_node_options',
  );

  // Exported permission: 'override sticker revision option'.
  $permissions['override sticker revision option'] = array(
    'name' => 'override sticker revision option',
    'roles' => array(
      'Overall Administrator' => 'Overall Administrator',
    ),
    'module' => 'override_node_options',
  );

  // Exported permission: 'override sticker sticky option'.
  $permissions['override sticker sticky option'] = array(
    'name' => 'override sticker sticky option',
    'roles' => array(
      'Overall Administrator' => 'Overall Administrator',
    ),
    'module' => 'override_node_options',
  );

  // Exported permission: 'override video_game_review authored by option'.
  $permissions['override video_game_review authored by option'] = array(
    'name' => 'override video_game_review authored by option',
    'roles' => array(
      'Lead Staff' => 'Lead Staff',
      'Overall Administrator' => 'Overall Administrator',
      'Program administrator' => 'Program administrator',
      'Staff' => 'Staff',
    ),
    'module' => 'override_node_options',
  );

  // Exported permission: 'override video_game_review authored on option'.
  $permissions['override video_game_review authored on option'] = array(
    'name' => 'override video_game_review authored on option',
    'roles' => array(
      'Overall Administrator' => 'Overall Administrator',
    ),
    'module' => 'override_node_options',
  );

  // Exported permission: 'override video_game_review promote to front page option'.
  $permissions['override video_game_review promote to front page option'] = array(
    'name' => 'override video_game_review promote to front page option',
    'roles' => array(
      'Overall Administrator' => 'Overall Administrator',
    ),
    'module' => 'override_node_options',
  );

  // Exported permission: 'override video_game_review published option'.
  $permissions['override video_game_review published option'] = array(
    'name' => 'override video_game_review published option',
    'roles' => array(
      'Lead Staff' => 'Lead Staff',
      'Overall Administrator' => 'Overall Administrator',
      'Program administrator' => 'Program administrator',
    ),
    'module' => 'override_node_options',
  );

  // Exported permission: 'override video_game_review revision option'.
  $permissions['override video_game_review revision option'] = array(
    'name' => 'override video_game_review revision option',
    'roles' => array(
      'Overall Administrator' => 'Overall Administrator',
    ),
    'module' => 'override_node_options',
  );

  // Exported permission: 'override video_game_review sticky option'.
  $permissions['override video_game_review sticky option'] = array(
    'name' => 'override video_game_review sticky option',
    'roles' => array(
      'Overall Administrator' => 'Overall Administrator',
    ),
    'module' => 'override_node_options',
  );

  // Exported permission: 'override videos authored by option'.
  $permissions['override videos authored by option'] = array(
    'name' => 'override videos authored by option',
    'roles' => array(
      'Overall Administrator' => 'Overall Administrator',
    ),
    'module' => 'override_node_options',
  );

  // Exported permission: 'override videos authored on option'.
  $permissions['override videos authored on option'] = array(
    'name' => 'override videos authored on option',
    'roles' => array(
      'Overall Administrator' => 'Overall Administrator',
    ),
    'module' => 'override_node_options',
  );

  // Exported permission: 'override videos promote to front page option'.
  $permissions['override videos promote to front page option'] = array(
    'name' => 'override videos promote to front page option',
    'roles' => array(
      'Overall Administrator' => 'Overall Administrator',
    ),
    'module' => 'override_node_options',
  );

  // Exported permission: 'override videos published option'.
  $permissions['override videos published option'] = array(
    'name' => 'override videos published option',
    'roles' => array(
      'Overall Administrator' => 'Overall Administrator',
    ),
    'module' => 'override_node_options',
  );

  // Exported permission: 'override videos revision option'.
  $permissions['override videos revision option'] = array(
    'name' => 'override videos revision option',
    'roles' => array(
      'Overall Administrator' => 'Overall Administrator',
    ),
    'module' => 'override_node_options',
  );

  // Exported permission: 'override videos sticky option'.
  $permissions['override videos sticky option'] = array(
    'name' => 'override videos sticky option',
    'roles' => array(
      'Overall Administrator' => 'Overall Administrator',
    ),
    'module' => 'override_node_options',
  );

  // Exported permission: 'override webform authored by option'.
  $permissions['override webform authored by option'] = array(
    'name' => 'override webform authored by option',
    'roles' => array(
      'Overall Administrator' => 'Overall Administrator',
    ),
    'module' => 'override_node_options',
  );

  // Exported permission: 'override webform authored on option'.
  $permissions['override webform authored on option'] = array(
    'name' => 'override webform authored on option',
    'roles' => array(
      'Overall Administrator' => 'Overall Administrator',
    ),
    'module' => 'override_node_options',
  );

  // Exported permission: 'override webform promote to front page option'.
  $permissions['override webform promote to front page option'] = array(
    'name' => 'override webform promote to front page option',
    'roles' => array(
      'Overall Administrator' => 'Overall Administrator',
    ),
    'module' => 'override_node_options',
  );

  // Exported permission: 'override webform published option'.
  $permissions['override webform published option'] = array(
    'name' => 'override webform published option',
    'roles' => array(
      'Overall Administrator' => 'Overall Administrator',
    ),
    'module' => 'override_node_options',
  );

  // Exported permission: 'override webform revision option'.
  $permissions['override webform revision option'] = array(
    'name' => 'override webform revision option',
    'roles' => array(
      'Overall Administrator' => 'Overall Administrator',
    ),
    'module' => 'override_node_options',
  );

  // Exported permission: 'override webform sticky option'.
  $permissions['override webform sticky option'] = array(
    'name' => 'override webform sticky option',
    'roles' => array(
      'Overall Administrator' => 'Overall Administrator',
    ),
    'module' => 'override_node_options',
  );

  // Exported permission: 'perform backup'.
  $permissions['perform backup'] = array(
    'name' => 'perform backup',
    'roles' => array(
      'Overall Administrator' => 'Overall Administrator',
    ),
    'module' => 'backup_migrate',
  );

  // Exported permission: 'preview focal point'.
  $permissions['preview focal point'] = array(
    'name' => 'preview focal point',
    'roles' => array(
      'Overall Administrator' => 'Overall Administrator',
    ),
    'module' => 'focal_point',
  );

  // Exported permission: 'raffle_access_permission'.
  $permissions['raffle_access_permission'] = array(
    'name' => 'raffle_access_permission',
    'roles' => array(
      'Overall Administrator' => 'Overall Administrator',
      'Program administrator' => 'Program administrator',
    ),
    'module' => 'play_program_raffle',
  );

  // Exported permission: 'read all private messages'.
  $permissions['read all private messages'] = array(
    'name' => 'read all private messages',
    'roles' => array(
      'Overall Administrator' => 'Overall Administrator',
    ),
    'module' => 'privatemsg',
  );

  // Exported permission: 'read privatemsg'.
  $permissions['read privatemsg'] = array(
    'name' => 'read privatemsg',
    'roles' => array(
      'Overall Administrator' => 'Overall Administrator',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'privatemsg',
  );

  // Exported permission: 'recur all nodes'.
  $permissions['recur all nodes'] = array(
    'name' => 'recur all nodes',
    'roles' => array(
      'Overall Administrator' => 'Overall Administrator',
    ),
    'module' => 'node_recur',
  );

  // Exported permission: 'recur own nodes'.
  $permissions['recur own nodes'] = array(
    'name' => 'recur own nodes',
    'roles' => array(
      'Overall Administrator' => 'Overall Administrator',
    ),
    'module' => 'node_recur',
  );

  // Exported permission: 'rename features'.
  $permissions['rename features'] = array(
    'name' => 'rename features',
    'roles' => array(
      'Overall Administrator' => 'Overall Administrator',
    ),
    'module' => 'features',
  );

  // Exported permission: 'reply only privatemsg'.
  $permissions['reply only privatemsg'] = array(
    'name' => 'reply only privatemsg',
    'roles' => array(
      'Overall Administrator' => 'Overall Administrator',
      'Patron' => 'Patron',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'privatemsg',
  );

  // Exported permission: 'restore from backup'.
  $permissions['restore from backup'] = array(
    'name' => 'restore from backup',
    'roles' => array(
      'Overall Administrator' => 'Overall Administrator',
    ),
    'module' => 'backup_migrate',
  );

  // Exported permission: 'revert revisions'.
  $permissions['revert revisions'] = array(
    'name' => 'revert revisions',
    'roles' => array(
      'Overall Administrator' => 'Overall Administrator',
      'Program administrator' => 'Program administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'schedule publishing of nodes'.
  $permissions['schedule publishing of nodes'] = array(
    'name' => 'schedule publishing of nodes',
    'roles' => array(
      'Overall Administrator' => 'Overall Administrator',
    ),
    'module' => 'scheduler',
  );

  // Exported permission: 'search content'.
  $permissions['search content'] = array(
    'name' => 'search content',
    'roles' => array(
      'Overall Administrator' => 'Overall Administrator',
      'anonymous user' => 'anonymous user',
    ),
    'module' => 'search',
  );

  // Exported permission: 'select account cancellation method'.
  $permissions['select account cancellation method'] = array(
    'name' => 'select account cancellation method',
    'roles' => array(
      'Overall Administrator' => 'Overall Administrator',
      'Program administrator' => 'Program administrator',
    ),
    'module' => 'user',
  );

  // Exported permission: 'select different theme'.
  $permissions['select different theme'] = array(
    'name' => 'select different theme',
    'roles' => array(
      'Overall Administrator' => 'Overall Administrator',
    ),
    'module' => 'switchtheme',
  );

  // Exported permission: 'select text format for privatemsg'.
  $permissions['select text format for privatemsg'] = array(
    'name' => 'select text format for privatemsg',
    'roles' => array(
      'Overall Administrator' => 'Overall Administrator',
    ),
    'module' => 'privatemsg',
  );

  // Exported permission: 'set default user_dashboard blocks'.
  $permissions['set default user_dashboard blocks'] = array(
    'name' => 'set default user_dashboard blocks',
    'roles' => array(
      'Overall Administrator' => 'Overall Administrator',
    ),
    'module' => 'user_dashboard',
  );

  // Exported permission: 'show format selection for activity'.
  $permissions['show format selection for activity'] = array(
    'name' => 'show format selection for activity',
    'roles' => array(
      'Overall Administrator' => 'Overall Administrator',
    ),
    'module' => 'better_formats',
  );

  // Exported permission: 'show format selection for avatar'.
  $permissions['show format selection for avatar'] = array(
    'name' => 'show format selection for avatar',
    'roles' => array(
      'Overall Administrator' => 'Overall Administrator',
    ),
    'module' => 'better_formats',
  );

  // Exported permission: 'show format selection for booklist_item'.
  $permissions['show format selection for booklist_item'] = array(
    'name' => 'show format selection for booklist_item',
    'roles' => array(
      'Overall Administrator' => 'Overall Administrator',
    ),
    'module' => 'better_formats',
  );

  // Exported permission: 'show format selection for entityqueue_subqueue'.
  $permissions['show format selection for entityqueue_subqueue'] = array(
    'name' => 'show format selection for entityqueue_subqueue',
    'roles' => array(
      'Overall Administrator' => 'Overall Administrator',
    ),
    'module' => 'better_formats',
  );

  // Exported permission: 'show format selection for field_collection_item'.
  $permissions['show format selection for field_collection_item'] = array(
    'name' => 'show format selection for field_collection_item',
    'roles' => array(
      'Overall Administrator' => 'Overall Administrator',
    ),
    'module' => 'better_formats',
  );

  // Exported permission: 'show format selection for file'.
  $permissions['show format selection for file'] = array(
    'name' => 'show format selection for file',
    'roles' => array(
      'Overall Administrator' => 'Overall Administrator',
    ),
    'module' => 'better_formats',
  );

  // Exported permission: 'show format selection for flagging'.
  $permissions['show format selection for flagging'] = array(
    'name' => 'show format selection for flagging',
    'roles' => array(
      'Overall Administrator' => 'Overall Administrator',
    ),
    'module' => 'better_formats',
  );

  // Exported permission: 'show format selection for node'.
  $permissions['show format selection for node'] = array(
    'name' => 'show format selection for node',
    'roles' => array(
      'Overall Administrator' => 'Overall Administrator',
    ),
    'module' => 'better_formats',
  );

  // Exported permission: 'show format selection for privatemsg_message'.
  $permissions['show format selection for privatemsg_message'] = array(
    'name' => 'show format selection for privatemsg_message',
    'roles' => array(
      'Overall Administrator' => 'Overall Administrator',
    ),
    'module' => 'better_formats',
  );

  // Exported permission: 'show format selection for profile2'.
  $permissions['show format selection for profile2'] = array(
    'name' => 'show format selection for profile2',
    'roles' => array(
      'Overall Administrator' => 'Overall Administrator',
    ),
    'module' => 'better_formats',
  );

  // Exported permission: 'show format selection for reward'.
  $permissions['show format selection for reward'] = array(
    'name' => 'show format selection for reward',
    'roles' => array(
      'Overall Administrator' => 'Overall Administrator',
    ),
    'module' => 'better_formats',
  );

  // Exported permission: 'show format selection for rules_config'.
  $permissions['show format selection for rules_config'] = array(
    'name' => 'show format selection for rules_config',
    'roles' => array(
      'Overall Administrator' => 'Overall Administrator',
    ),
    'module' => 'better_formats',
  );

  // Exported permission: 'show format selection for taxonomy_term'.
  $permissions['show format selection for taxonomy_term'] = array(
    'name' => 'show format selection for taxonomy_term',
    'roles' => array(
      'Overall Administrator' => 'Overall Administrator',
    ),
    'module' => 'better_formats',
  );

  // Exported permission: 'show format selection for user'.
  $permissions['show format selection for user'] = array(
    'name' => 'show format selection for user',
    'roles' => array(
      'Overall Administrator' => 'Overall Administrator',
    ),
    'module' => 'better_formats',
  );

  // Exported permission: 'show format tips'.
  $permissions['show format tips'] = array(
    'name' => 'show format tips',
    'roles' => array(
      'Overall Administrator' => 'Overall Administrator',
    ),
    'module' => 'better_formats',
  );

  // Exported permission: 'show more format tips link'.
  $permissions['show more format tips link'] = array(
    'name' => 'show more format tips link',
    'roles' => array(
      'Overall Administrator' => 'Overall Administrator',
    ),
    'module' => 'better_formats',
  );

  // Exported permission: 'show warning text'.
  $permissions['show warning text'] = array(
    'name' => 'show warning text',
    'roles' => array(
      'Overall Administrator' => 'Overall Administrator',
    ),
    'module' => 'sharedemail',
  );

  // Exported permission: 'switch shortcut sets'.
  $permissions['switch shortcut sets'] = array(
    'name' => 'switch shortcut sets',
    'roles' => array(
      'Overall Administrator' => 'Overall Administrator',
    ),
    'module' => 'shortcut',
  );

  // Exported permission: 'switch theme'.
  $permissions['switch theme'] = array(
    'name' => 'switch theme',
    'roles' => array(
      'Overall Administrator' => 'Overall Administrator',
      'Program administrator' => 'Program administrator',
    ),
    'module' => 'switchtheme',
  );

  // Exported permission: 'tag private messages'.
  $permissions['tag private messages'] = array(
    'name' => 'tag private messages',
    'roles' => array(
      'Overall Administrator' => 'Overall Administrator',
    ),
    'module' => 'privatemsg_filter',
  );

  // Exported permission: 'tamper avatars'.
  $permissions['tamper avatars'] = array(
    'name' => 'tamper avatars',
    'roles' => array(
      'Overall Administrator' => 'Overall Administrator',
      'Program administrator' => 'Program administrator',
    ),
    'module' => 'feeds_tamper',
  );

  // Exported permission: 'tamper events'.
  $permissions['tamper events'] = array(
    'name' => 'tamper events',
    'roles' => array(
      'Overall Administrator' => 'Overall Administrator',
      'Program administrator' => 'Program administrator',
    ),
    'module' => 'feeds_tamper',
  );

  // Exported permission: 'toggle field translatability'.
  $permissions['toggle field translatability'] = array(
    'name' => 'toggle field translatability',
    'roles' => array(
      'Overall Administrator' => 'Overall Administrator',
    ),
    'module' => 'entity_translation',
  );

  // Exported permission: 'translate activity entities'.
  $permissions['translate activity entities'] = array(
    'name' => 'translate activity entities',
    'roles' => array(
      'Overall Administrator' => 'Overall Administrator',
    ),
    'module' => 'entity_translation',
  );

  // Exported permission: 'translate admin strings'.
  $permissions['translate admin strings'] = array(
    'name' => 'translate admin strings',
    'roles' => array(
      'Overall Administrator' => 'Overall Administrator',
    ),
    'module' => 'i18n_string',
  );

  // Exported permission: 'translate any entity'.
  $permissions['translate any entity'] = array(
    'name' => 'translate any entity',
    'roles' => array(
      'Overall Administrator' => 'Overall Administrator',
    ),
    'module' => 'entity_translation',
  );

  // Exported permission: 'translate content'.
  $permissions['translate content'] = array(
    'name' => 'translate content',
    'roles' => array(
      'Lead Staff' => 'Lead Staff',
      'Overall Administrator' => 'Overall Administrator',
      'Program administrator' => 'Program administrator',
      'Staff' => 'Staff',
    ),
    'module' => 'translation',
  );

  // Exported permission: 'translate interface'.
  $permissions['translate interface'] = array(
    'name' => 'translate interface',
    'roles' => array(
      'Overall Administrator' => 'Overall Administrator',
    ),
    'module' => 'locale',
  );

  // Exported permission: 'translate node entities'.
  $permissions['translate node entities'] = array(
    'name' => 'translate node entities',
    'roles' => array(
      'Overall Administrator' => 'Overall Administrator',
    ),
    'module' => 'entity_translation',
  );

  // Exported permission: 'translate reward entities'.
  $permissions['translate reward entities'] = array(
    'name' => 'translate reward entities',
    'roles' => array(
      'Overall Administrator' => 'Overall Administrator',
    ),
    'module' => 'entity_translation',
  );

  // Exported permission: 'translate user-defined strings'.
  $permissions['translate user-defined strings'] = array(
    'name' => 'translate user-defined strings',
    'roles' => array(
      'Overall Administrator' => 'Overall Administrator',
    ),
    'module' => 'i18n_string',
  );

  // Exported permission: 'unflag follow'.
  $permissions['unflag follow'] = array(
    'name' => 'unflag follow',
    'roles' => array(
      'Overall Administrator' => 'Overall Administrator',
      'Program administrator' => 'Program administrator',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'flag',
  );

  // Exported permission: 'unflag like'.
  $permissions['unflag like'] = array(
    'name' => 'unflag like',
    'roles' => array(
      'Program administrator' => 'Program administrator',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'flag',
  );

  // Exported permission: 'unflag primary_booklist'.
  $permissions['unflag primary_booklist'] = array(
    'name' => 'unflag primary_booklist',
    'roles' => array(
      'Overall Administrator' => 'Overall Administrator',
      'Program administrator' => 'Program administrator',
    ),
    'module' => 'flag',
  );

  // Exported permission: 'unflag reward_claimed'.
  $permissions['unflag reward_claimed'] = array(
    'name' => 'unflag reward_claimed',
    'roles' => array(
      'Program administrator' => 'Program administrator',
    ),
    'module' => 'flag',
  );

  // Exported permission: 'unlock avatars feeds'.
  $permissions['unlock avatars feeds'] = array(
    'name' => 'unlock avatars feeds',
    'roles' => array(
      'Program administrator' => 'Program administrator',
    ),
    'module' => 'feeds',
  );

  // Exported permission: 'unlock events feeds'.
  $permissions['unlock events feeds'] = array(
    'name' => 'unlock events feeds',
    'roles' => array(
      'Program administrator' => 'Program administrator',
    ),
    'module' => 'feeds',
  );

  // Exported permission: 'update badges_for_booklists entityqueue'.
  $permissions['update badges_for_booklists entityqueue'] = array(
    'name' => 'update badges_for_booklists entityqueue',
    'roles' => array(
      'Lead Staff' => 'Lead Staff',
      'Overall Administrator' => 'Overall Administrator',
      'Program administrator' => 'Program administrator',
    ),
    'module' => 'entityqueue',
  );

  // Exported permission: 'update badges_for_reading entityqueue'.
  $permissions['update badges_for_reading entityqueue'] = array(
    'name' => 'update badges_for_reading entityqueue',
    'roles' => array(
      'Lead Staff' => 'Lead Staff',
      'Overall Administrator' => 'Overall Administrator',
      'Program administrator' => 'Program administrator',
    ),
    'module' => 'entityqueue',
  );

  // Exported permission: 'update badges_for_reviews entityqueue'.
  $permissions['update badges_for_reviews entityqueue'] = array(
    'name' => 'update badges_for_reviews entityqueue',
    'roles' => array(
      'Lead Staff' => 'Lead Staff',
      'Overall Administrator' => 'Overall Administrator',
      'Program administrator' => 'Program administrator',
    ),
    'module' => 'entityqueue',
  );

  // Exported permission: 'update other_badges entityqueue'.
  $permissions['update other_badges entityqueue'] = array(
    'name' => 'update other_badges entityqueue',
    'roles' => array(
      'Lead Staff' => 'Lead Staff',
      'Overall Administrator' => 'Overall Administrator',
      'Program administrator' => 'Program administrator',
    ),
    'module' => 'entityqueue',
  );

  // Exported permission: 'use PHP for settings'.
  $permissions['use PHP for settings'] = array(
    'name' => 'use PHP for settings',
    'roles' => array(
      'Overall Administrator' => 'Overall Administrator',
    ),
    'module' => 'php',
  );

  // Exported permission: 'use PHP for title patterns'.
  $permissions['use PHP for title patterns'] = array(
    'name' => 'use PHP for title patterns',
    'roles' => array(
      'Overall Administrator' => 'Overall Administrator',
    ),
    'module' => 'auto_nodetitle',
  );

  // Exported permission: 'use add another'.
  $permissions['use add another'] = array(
    'name' => 'use add another',
    'roles' => array(
      'Overall Administrator' => 'Overall Administrator',
      'Program administrator' => 'Program administrator',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'addanother',
  );

  // Exported permission: 'use advanced search'.
  $permissions['use advanced search'] = array(
    'name' => 'use advanced search',
    'roles' => array(
      'Overall Administrator' => 'Overall Administrator',
    ),
    'module' => 'search',
  );

  // Exported permission: 'use ctools import'.
  $permissions['use ctools import'] = array(
    'name' => 'use ctools import',
    'roles' => array(
      'Overall Administrator' => 'Overall Administrator',
    ),
    'module' => 'ctools',
  );

  // Exported permission: 'use exclude node title'.
  $permissions['use exclude node title'] = array(
    'name' => 'use exclude node title',
    'roles' => array(
      'Overall Administrator' => 'Overall Administrator',
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'exclude_node_title',
  );

  // Exported permission: 'use flag import'.
  $permissions['use flag import'] = array(
    'name' => 'use flag import',
    'roles' => array(
      'Overall Administrator' => 'Overall Administrator',
      'Program administrator' => 'Program administrator',
    ),
    'module' => 'flag',
  );

  // Exported permission: 'use ipe with page manager'.
  $permissions['use ipe with page manager'] = array(
    'name' => 'use ipe with page manager',
    'roles' => array(
      'Overall Administrator' => 'Overall Administrator',
    ),
    'module' => 'panels',
  );

  // Exported permission: 'use page manager'.
  $permissions['use page manager'] = array(
    'name' => 'use page manager',
    'roles' => array(
      'Overall Administrator' => 'Overall Administrator',
    ),
    'module' => 'page_manager',
  );

  // Exported permission: 'use panels caching features'.
  $permissions['use panels caching features'] = array(
    'name' => 'use panels caching features',
    'roles' => array(
      'Overall Administrator' => 'Overall Administrator',
    ),
    'module' => 'panels',
  );

  // Exported permission: 'use panels dashboard'.
  $permissions['use panels dashboard'] = array(
    'name' => 'use panels dashboard',
    'roles' => array(
      'Overall Administrator' => 'Overall Administrator',
    ),
    'module' => 'panels',
  );

  // Exported permission: 'use panels in place editing'.
  $permissions['use panels in place editing'] = array(
    'name' => 'use panels in place editing',
    'roles' => array(
      'Overall Administrator' => 'Overall Administrator',
    ),
    'module' => 'panels',
  );

  // Exported permission: 'use panels locks'.
  $permissions['use panels locks'] = array(
    'name' => 'use panels locks',
    'roles' => array(
      'Overall Administrator' => 'Overall Administrator',
    ),
    'module' => 'panels',
  );

  // Exported permission: 'use text format filtered_html'.
  $permissions['use text format filtered_html'] = array(
    'name' => 'use text format filtered_html',
    'roles' => array(
      'Group Lead' => 'Group Lead',
      'Overall Administrator' => 'Overall Administrator',
    ),
    'module' => 'filter',
  );

  // Exported permission: 'use text format full_html'.
  $permissions['use text format full_html'] = array(
    'name' => 'use text format full_html',
    'roles' => array(
      'Group Lead' => 'Group Lead',
      'Overall Administrator' => 'Overall Administrator',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'filter',
  );

  // Exported permission: 'use text format php_code'.
  $permissions['use text format php_code'] = array(
    'name' => 'use text format php_code',
    'roles' => array(
      'Overall Administrator' => 'Overall Administrator',
    ),
    'module' => 'filter',
  );

  // Exported permission: 'use tokens in privatemsg'.
  $permissions['use tokens in privatemsg'] = array(
    'name' => 'use tokens in privatemsg',
    'roles' => array(
      'Overall Administrator' => 'Overall Administrator',
    ),
    'module' => 'privatemsg',
  );

  // Exported permission: 'use workbench_moderation my drafts tab'.
  $permissions['use workbench_moderation my drafts tab'] = array(
    'name' => 'use workbench_moderation my drafts tab',
    'roles' => array(
      'Overall Administrator' => 'Overall Administrator',
      'Program administrator' => 'Program administrator',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'workbench_moderation',
  );

  // Exported permission: 'use workbench_moderation needs review tab'.
  $permissions['use workbench_moderation needs review tab'] = array(
    'name' => 'use workbench_moderation needs review tab',
    'roles' => array(
      'Lead Staff' => 'Lead Staff',
      'Overall Administrator' => 'Overall Administrator',
      'Program administrator' => 'Program administrator',
      'Staff' => 'Staff',
    ),
    'module' => 'workbench_moderation',
  );

  // Exported permission: 'view all flickr photos'.
  $permissions['view all flickr photos'] = array(
    'name' => 'view all flickr photos',
    'roles' => array(
      'Overall Administrator' => 'Overall Administrator',
    ),
    'module' => 'flickr',
  );

  // Exported permission: 'view all unpublished content'.
  $permissions['view all unpublished content'] = array(
    'name' => 'view all unpublished content',
    'roles' => array(
      'Lead Staff' => 'Lead Staff',
      'Overall Administrator' => 'Overall Administrator',
      'Program administrator' => 'Program administrator',
      'Staff' => 'Staff',
    ),
    'module' => 'workbench_moderation',
  );

  // Exported permission: 'view all users\' dashboards'.
  $permissions['view all users\' dashboards'] = array(
    'name' => 'view all users\' dashboards',
    'roles' => array(
      'Overall Administrator' => 'Overall Administrator',
    ),
    'module' => 'user_dashboard',
  );

  // Exported permission: 'view any main profile'.
  $permissions['view any main profile'] = array(
    'name' => 'view any main profile',
    'roles' => array(
      'Lead Staff' => 'Lead Staff',
      'Overall Administrator' => 'Overall Administrator',
      'Program administrator' => 'Program administrator',
    ),
    'module' => 'profile2',
  );

  // Exported permission: 'view error messages'.
  $permissions['view error messages'] = array(
    'name' => 'view error messages',
    'roles' => array(
      'Overall Administrator' => 'Overall Administrator',
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'disable_messages',
  );

  // Exported permission: 'view field_booklist_cover_image'.
  $permissions['view field_booklist_cover_image'] = array(
    'name' => 'view field_booklist_cover_image',
    'roles' => array(
      'Overall Administrator' => 'Overall Administrator',
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view field_movie_cover_image_link'.
  $permissions['view field_movie_cover_image_link'] = array(
    'name' => 'view field_movie_cover_image_link',
    'roles' => array(
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view field_music_cover_image_link'.
  $permissions['view field_music_cover_image_link'] = array(
    'name' => 'view field_music_cover_image_link',
    'roles' => array(
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view field_video_game_cover_image_lin'.
  $permissions['view field_video_game_cover_image_lin'] = array(
    'name' => 'view field_video_game_cover_image_lin',
    'roles' => array(
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view media'.
  $permissions['view media'] = array(
    'name' => 'view media',
    'roles' => array(
      'Overall Administrator' => 'Overall Administrator',
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'media',
  );

  // Exported permission: 'view moderation history'.
  $permissions['view moderation history'] = array(
    'name' => 'view moderation history',
    'roles' => array(
      'Lead Staff' => 'Lead Staff',
      'Overall Administrator' => 'Overall Administrator',
      'Program administrator' => 'Program administrator',
      'Staff' => 'Staff',
    ),
    'module' => 'workbench_moderation',
  );

  // Exported permission: 'view moderation messages'.
  $permissions['view moderation messages'] = array(
    'name' => 'view moderation messages',
    'roles' => array(
      'Lead Staff' => 'Lead Staff',
      'Overall Administrator' => 'Overall Administrator',
      'Program administrator' => 'Program administrator',
      'Staff' => 'Staff',
    ),
    'module' => 'workbench_moderation',
  );

  // Exported permission: 'view own field_booklist_cover_image'.
  $permissions['view own field_booklist_cover_image'] = array(
    'name' => 'view own field_booklist_cover_image',
    'roles' => array(
      'Overall Administrator' => 'Overall Administrator',
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view own field_movie_cover_image_link'.
  $permissions['view own field_movie_cover_image_link'] = array(
    'name' => 'view own field_movie_cover_image_link',
    'roles' => array(
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view own field_music_cover_image_link'.
  $permissions['view own field_music_cover_image_link'] = array(
    'name' => 'view own field_music_cover_image_link',
    'roles' => array(
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view own field_video_game_cover_image_lin'.
  $permissions['view own field_video_game_cover_image_lin'] = array(
    'name' => 'view own field_video_game_cover_image_lin',
    'roles' => array(
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view own flickr photos'.
  $permissions['view own flickr photos'] = array(
    'name' => 'view own flickr photos',
    'roles' => array(
      'Overall Administrator' => 'Overall Administrator',
    ),
    'module' => 'flickr',
  );

  // Exported permission: 'view own main profile'.
  $permissions['view own main profile'] = array(
    'name' => 'view own main profile',
    'roles' => array(
      'Lead Staff' => 'Lead Staff',
      'Overall Administrator' => 'Overall Administrator',
      'Program administrator' => 'Program administrator',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'profile2',
  );

  // Exported permission: 'view own unpublished content'.
  $permissions['view own unpublished content'] = array(
    'name' => 'view own unpublished content',
    'roles' => array(
      'Overall Administrator' => 'Overall Administrator',
      'Program administrator' => 'Program administrator',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'node',
  );

  // Exported permission: 'view own userpoints'.
  $permissions['view own userpoints'] = array(
    'name' => 'view own userpoints',
    'roles' => array(
      'Overall Administrator' => 'Overall Administrator',
      'Program administrator' => 'Program administrator',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'userpoints',
  );

  // Exported permission: 'view pane admin links'.
  $permissions['view pane admin links'] = array(
    'name' => 'view pane admin links',
    'roles' => array(
      'Overall Administrator' => 'Overall Administrator',
    ),
    'module' => 'panels',
  );

  // Exported permission: 'view progress page'.
  $permissions['view progress page'] = array(
    'name' => 'view progress page',
    'roles' => array(
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'play_progress_calendar',
  );

  // Exported permission: 'view revisions'.
  $permissions['view revisions'] = array(
    'name' => 'view revisions',
    'roles' => array(
      'Overall Administrator' => 'Overall Administrator',
      'Program administrator' => 'Program administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: 'view roles recipients'.
  $permissions['view roles recipients'] = array(
    'name' => 'view roles recipients',
    'roles' => array(
      'Overall Administrator' => 'Overall Administrator',
    ),
    'module' => 'privatemsg_roles',
  );

  // Exported permission: 'view scheduled content'.
  $permissions['view scheduled content'] = array(
    'name' => 'view scheduled content',
    'roles' => array(
      'Overall Administrator' => 'Overall Administrator',
    ),
    'module' => 'scheduler',
  );

  // Exported permission: 'view status messages'.
  $permissions['view status messages'] = array(
    'name' => 'view status messages',
    'roles' => array(
      'Overall Administrator' => 'Overall Administrator',
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'disable_messages',
  );

  // Exported permission: 'view the administration theme'.
  $permissions['view the administration theme'] = array(
    'name' => 'view the administration theme',
    'roles' => array(
      'Overall Administrator' => 'Overall Administrator',
    ),
    'module' => 'system',
  );

  // Exported permission: 'view translation overview assignments'.
  $permissions['view translation overview assignments'] = array(
    'name' => 'view translation overview assignments',
    'roles' => array(
      'Overall Administrator' => 'Overall Administrator',
    ),
    'module' => 'translation_overview',
  );

  // Exported permission: 'view userpoints'.
  $permissions['view userpoints'] = array(
    'name' => 'view userpoints',
    'roles' => array(
      'Overall Administrator' => 'Overall Administrator',
      'Program administrator' => 'Program administrator',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'userpoints',
  );

  // Exported permission: 'view warning messages'.
  $permissions['view warning messages'] = array(
    'name' => 'view warning messages',
    'roles' => array(
      'Overall Administrator' => 'Overall Administrator',
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'disable_messages',
  );

  // Exported permission: 'view workbench access information'.
  $permissions['view workbench access information'] = array(
    'name' => 'view workbench access information',
    'roles' => array(
      'Overall Administrator' => 'Overall Administrator',
      'Program administrator' => 'Program administrator',
    ),
    'module' => 'workbench_access',
  );

  // Exported permission: 'view workbench taxonomy pages'.
  $permissions['view workbench taxonomy pages'] = array(
    'name' => 'view workbench taxonomy pages',
    'roles' => array(
      'Overall Administrator' => 'Overall Administrator',
      'Program administrator' => 'Program administrator',
    ),
    'module' => 'workbench_access',
  );

  // Exported permission: 'vote on polls'.
  $permissions['vote on polls'] = array(
    'name' => 'vote on polls',
    'roles' => array(
      'Overall Administrator' => 'Overall Administrator',
    ),
    'module' => 'poll',
  );

  // Exported permission: 'write privatemsg'.
  $permissions['write privatemsg'] = array(
    'name' => 'write privatemsg',
    'roles' => array(
      'Overall Administrator' => 'Overall Administrator',
    ),
    'module' => 'privatemsg',
  );

  // Exported permission: 'write privatemsg to roles'.
  $permissions['write privatemsg to roles'] = array(
    'name' => 'write privatemsg to roles',
    'roles' => array(
      'Overall Administrator' => 'Overall Administrator',
    ),
    'module' => 'privatemsg_roles',
  );

  return $permissions;
}

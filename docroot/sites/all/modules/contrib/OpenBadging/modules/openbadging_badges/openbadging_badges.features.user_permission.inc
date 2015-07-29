<?php

/**
 * @file
 * openbadging_badges.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function openbadging_badges_user_default_permissions() {
  $permissions = array();

  // Exported permission: administer openbadging.
  $permissions['administer openbadging'] = array(
    'name' => 'administer openbadging',
    'roles' => array(
      0 => 'administrator',
    ),
    'module' => 'openbadging',
  );

  // Exported permission: administer openbadging types.
  $permissions['administer openbadging types'] = array(
    'name' => 'administer openbadging types',
    'roles' => array(
      0 => 'administrator',
    ),
    'module' => 'openbadging',
  );

  // Exported permission: create badges openbadging.
  $permissions['create badges openbadging'] = array(
    'name' => 'create badges openbadging',
    'roles' => array(
      0 => 'administrator',
    ),
    'module' => 'openbadging',
  );

  // Exported permission: delete any badges openbadging.
  $permissions['delete any badges openbadging'] = array(
    'name' => 'delete any badges openbadging',
    'roles' => array(
      0 => 'administrator',
    ),
    'module' => 'openbadging',
  );

  // Exported permission: delete own badges openbadging.
  $permissions['delete own badges openbadging'] = array(
    'name' => 'delete own badges openbadging',
    'roles' => array(
      0 => 'administrator',
    ),
    'module' => 'openbadging',
  );

  // Exported permission: edit any badges openbadging
  $permissions['edit any badges openbadging'] = array(
    'name' => 'edit any badges openbadging',
    'roles' => array(
      0 => 'administrator',
    ),
    'module' => 'openbadging',
  );

  // Exported permission: edit own badges openbadging.
  $permissions['edit own badges openbadging'] = array(
    'name' => 'edit own badges openbadging',
    'roles' => array(
      0 => 'administrator',
    ),
    'module' => 'openbadging',
  );

  // Exported permission: view badges openbadging.
  $permissions['view badges openbadging'] = array(
    'name' => 'view badges openbadging',
    'roles' => array(
      0 => 'anonymous user',
      1 => 'authenticated user',
    ),
    'module' => 'openbadging',
  );

  return $permissions;
}

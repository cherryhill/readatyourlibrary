<?php

/**
 * @file
 * openbadging_issuer.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function openbadging_issuer_user_default_permissions() {
  $permissions = array();

  // Exported permission: create issuer_information openbadging.
  $permissions['create issuer_information openbadging'] = array(
    'name' => 'create issuer_information openbadging',
    'roles' => array(
      0 => 'administrator',
    ),
    'module' => 'openbadging',
  );

  // Exported permission: delete any issuer_information openbadging.
  $permissions['delete any issuer_information openbadging'] = array(
    'name' => 'delete any issuer_information openbadging',
    'roles' => array(
      0 => 'administrator',
    ),
    'module' => 'openbadging',
  );

  // Exported permission: delete own issuer_information openbadging.
  $permissions['delete own issuer_information openbadging'] = array(
    'name' => 'delete own issuer_information openbadging',
    'roles' => array(
      0 => 'administrator',
    ),
    'module' => 'openbadging',
  );

  // Exported permission: edit any issuer_information openbadging.
  $permissions['edit any issuer_information openbadging'] = array(
    'name' => 'edit any issuer_information openbadging',
    'roles' => array(
      0 => 'administrator',
    ),
    'module' => 'openbadging',
  );

  // Exported permission: edit own issuer_information openbadging.
  $permissions['edit own issuer_information openbadging'] = array(
    'name' => 'edit own issuer_information openbadging',
    'roles' => array(
      0 => 'administrator',
    ),
    'module' => 'openbadging',
  );

  // Exported permission: view issuer_information openbadging.
  $permissions['view issuer_information openbadging'] = array(
    'name' => 'view issuer_information openbadging',
    'roles' => array(
      0 => 'anonymous user',
      1 => 'authenticated user',
    ),
    'module' => 'openbadging',
  );

  return $permissions;
}

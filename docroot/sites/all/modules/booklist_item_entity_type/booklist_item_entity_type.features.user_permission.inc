<?php
/**
 * @file
 * booklist_item_entity_type.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function booklist_item_entity_type_user_default_permissions() {
  $permissions = array();

  // Exported permission: 'create field_booklist_cover_image'.
  $permissions['create field_booklist_cover_image'] = array(
    'name' => 'create field_booklist_cover_image',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit field_booklist_cover_image'.
  $permissions['edit field_booklist_cover_image'] = array(
    'name' => 'edit field_booklist_cover_image',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit own field_booklist_cover_image'.
  $permissions['edit own field_booklist_cover_image'] = array(
    'name' => 'edit own field_booklist_cover_image',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view field_booklist_cover_image'.
  $permissions['view field_booklist_cover_image'] = array(
    'name' => 'view field_booklist_cover_image',
    'roles' => array(
      'administrator' => 'administrator',
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view own field_booklist_cover_image'.
  $permissions['view own field_booklist_cover_image'] = array(
    'name' => 'view own field_booklist_cover_image',
    'roles' => array(
      'administrator' => 'administrator',
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'field_permissions',
  );

  return $permissions;
}

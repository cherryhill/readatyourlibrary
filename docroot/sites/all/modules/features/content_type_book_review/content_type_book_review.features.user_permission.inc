<?php
/**
 * @file
 * content_type_book_review.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function content_type_book_review_user_default_permissions() {
  $permissions = array();

  // Exported permission: 'create field_book_cover_image_link'.
  $permissions['create field_book_cover_image_link'] = array(
    'name' => 'create field_book_cover_image_link',
    'roles' => array(),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit field_book_cover_image_link'.
  $permissions['edit field_book_cover_image_link'] = array(
    'name' => 'edit field_book_cover_image_link',
    'roles' => array(),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit own field_book_cover_image_link'.
  $permissions['edit own field_book_cover_image_link'] = array(
    'name' => 'edit own field_book_cover_image_link',
    'roles' => array(),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view field_book_cover_image_link'.
  $permissions['view field_book_cover_image_link'] = array(
    'name' => 'view field_book_cover_image_link',
    'roles' => array(),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view own field_book_cover_image_link'.
  $permissions['view own field_book_cover_image_link'] = array(
    'name' => 'view own field_book_cover_image_link',
    'roles' => array(),
    'module' => 'field_permissions',
  );

  return $permissions;
}

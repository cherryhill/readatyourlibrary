<?php
/**
 * @file
 * faq_expert.features.user_role.inc
 */

/**
 * Implements hook_user_default_roles().
 */
function faq_expert_user_default_roles() {
  $roles = array();

  // Exported role: expert.
  $roles['expert'] = array(
    'name' => 'expert',
    'weight' => 2,
  );

  return $roles;
}

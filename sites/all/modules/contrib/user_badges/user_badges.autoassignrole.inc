<?php
/**
 * @file
 * Actions for User Badges module.
 */

/**
 * Implements hook_cron().
 * Enables User Badges to work along with Auto Assign Role.
 * Notes: - this is a quite fast solution in order to solve Auto Assign Role issue.
 *   - do not forget to set up your cron
 */
function user_badges_cron() {
  $results = db_query('SELECT * FROM {user_badges_roles}');

  $roles = array();
  foreach ($results as $result) {
    $roles[$result->rid] = $result->bid;
  }

  user_badges_save_roles($roles); // Yuck!
}

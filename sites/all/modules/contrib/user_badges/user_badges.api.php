<?php
/**
 * @file
 * Document API.
 */

/**
 * Allows modules to react to the deletion of a user_badge.
 * This is invoked before the badge is deleted.
 *
 * @param $badge
 *   The badge object.
 */
function hook_user_badges_delete($badge) {

}

/**
 * Allows to modules to react to the editing or adding of a user_badge.
 * This is invoked before the badge is added. The called function may
 * alter the form values.
 *
 * @param $badge
 *   The form's returned values array ($form_state['values').
 *   If $edit['bid'] is empty, then this is an add operation.
 */
function hook_user_badges_edit_badge($badge) {

}

/**
 * Deletes a user_badge from all the tables.
 * It is the caller's responsibilty to let the user know this has been done.
 * The caller must have 'manage badges' permission.
 *
 * @param $bid
 *   The badge ID.
 */
function user_badges_delete_badge($bid) {
  if (user_access('manage badges')) {
    db_delete('user_badges_badges')
      ->condition('bid', $bid)
      ->execute();

    db_delete('user_badges_user')
      ->condition('bid', $bid)
      ->execute();

    db_delete('user_badges_roles')
      ->condition('bid', $bid)
      ->execute();
  }
}


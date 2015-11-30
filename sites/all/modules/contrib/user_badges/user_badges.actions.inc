<?php
/**
 * @file
 * Actions for User Badges module.
 */

/**
 * Implements hook_action_info().
 */
function user_badges_action_info() {
  return array(
    'user_badges_add_badge_action' => array(
      'label' => t('Add badge'),
      'type' => 'user',
      'configurable' => TRUE,
      'triggers' => array('any' => TRUE),
    ),
    'user_badges_remove_badge_action' => array(
      'label' => t('Remove badge'),
      'type' => 'user',
      'configurable' => TRUE,
      'triggers' => array('any' => TRUE),
    ),
  );
}

/**
 * Implementsa Drupal action.
 * Adds a badge to the current user.
 */
function user_badges_add_badge_action(&$account, $context = array()) {
  if (isset($account->uid)) {
    $uid = $account->uid;
  }
  elseif (isset($context['uid'])) {
    $uid = $context['uid'];
  }
  else {
    global $user;
    $uid = $user->uid;
  }
  $success = TRUE;
  $badges = user_badges_get_badges('all');

  foreach ($context['badges'] as $bid) {
    $success = (boolean) user_badges_user_add_badge($uid, $bid, 'uid');
    if ($success) {
      watchdog('action', 'Added user badge %badge to user %name.', array('%name' => check_plain($user->name), '%badge' => check_plain($badges[$bid]->name)));
    }
    else {
      watchdog('action', 'Unable to add user badge %badge to user %name.', array('%name' => check_plain($user->name), '%badge' => check_plain($badges[$bid]->name)), WATCHDOG_WARNING);
    }
  }
}

/**
 * @todo Please document this function.
 * @see http://drupal.org/node/1354
 */
function user_badges_add_badge_action_form($context) {
  $form['badges'] = array('#tree' => TRUE);

  $badges = user_badges_get_badges('all');
  $context['badges'] = isset($context['badges']) ? $context['badges'] : array();

  foreach ($badges as $badge) {
    $form['badges'][$badge->bid] = array(
      '#type' => 'checkbox',
      '#title' => theme('user_badge', array('badge' => $badge)),
      '#return_value' => 1,
      '#default_value' => (isset($context['badges'][$badge->bid])) ? $context['badges'][$badge->bid] : FALSE,
      '#description' => check_plain($badge->name),
    );
  }

  return $form;
}

/**
 * Submit handler for user_badges_add_badge_action.
 * @see http://drupal.org/node/1354
 */
function user_badges_add_badge_action_submit($form, $form_state) {
  $badges = array();
  foreach ($form_state['values']['badges'] as $badge => $set) {
    if ($set) {
      $badges[$badge] = $badge;
    }
  }
  return array('badges' => $badges);
}

/**
 * Implementsa Drupal action.
 * Removes a badge to the current user.
 */
function user_badges_remove_badge_action(&$account, $context = array()) {
  if (isset($account->uid)) {
    $uid = $account->uid;
  }
  elseif (isset($context['uid'])) {
    $uid = $context['uid'];
  }
  else {
    global $user;
    $uid = $user->uid;
  }
  $success = TRUE;
  $badges = user_badges_get_badges('all');

  foreach ($context['badges'] as $bid) {
    $success = (boolean) user_badges_user_remove_badge($uid, $bid, 'uid');
    if ($success) {
      watchdog('action', 'Removed user badge %badge to user %name.', array('%name' => check_plain($user->name), '%badge' => check_plain($badges[$bid]->name)));
    }
    else {
      watchdog('action', 'Unable to remove user badge %badge to user %name.', array('%name' => check_plain($user->name), '%badge' => check_plain($badges[$bid]->name)), WATCHDOG_WARNING);
    }
  }
}

/**
 * @todo Please document this function.
 * @see http://drupal.org/node/1354
 */
function user_badges_remove_badge_action_form($context) {
  $form['badges'] = array('#tree' => TRUE);

  $badges = user_badges_get_badges('all');
  $context['badges'] = is_array($context['badges']) ? $context['badges'] : array();

  foreach ($badges as $badge) {
    $form['badges'][$badge->bid] = array(
      '#type' => 'checkbox',
      '#title' => theme('user_badge', array('badge' => $badge)),
      '#return_value' => 1,
      '#default_value' => $context['badges'][$badge->bid],
      '#description' => check_plain($badge->name),
    );
  }

  return $form;
}

/**
 * @todo Please document this function.
 * @see http://drupal.org/node/1354
 */
function user_badges_remove_badge_action_submit($form, $form_state) {
  $badges = array();
  foreach ($form_state['values']['badges'] as $badge => $set) {
    if ($set) {
      $badges[$badge] = $badge;
    }
  }
  return array('badges' => $badges);
}

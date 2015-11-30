<?php

/**
* Implements hook_rules_action_info() on behalf of the user_badges module.
*
*/
function user_badges_rules_action_info() {
  $items = array(
    'add_badge_by_name' => array(
      'label' => t('Add badge by name'),
      'base' => 'user_badges_rules_action_add_badge_by_name',
      'parameter' => array(
        'badge' =>  array(
          'type' => 'text',
          'label' => t('Badge name'),
          'options list' => 'user_badges_rules_get_badge_names',
          'restriction' => 'input',
        ),
        'user' => array(
          'type' => 'user',
          'label' => t('User on whose behalf to add the badge'),
        ),
      ),
      'group' => t('User'),
      'access_callback' => 'user_badges_rules_integration_access',
    ),
    'remove_badge_by_name' => array(
      'label' => t('Remove badge by name'),
      'base' => 'user_badges_rules_action_remove_badge_by_name',
      'parameter' => array(
        'badge' =>  array(
          'type' => 'text',
          'label' => t('Badge name'),
          'options list' => 'user_badges_rules_get_badge_names',
          'restriction' => 'input',
        ),
        'user' => array(
          'type' => 'user',
          'label' => t('User on whose behalf to add the badge'),
        ),
      ),
      'group' => t('User'),
      'access_callback' => 'user_badges_rules_integration_access',
    ),
  );
  
  return $items;
}

/**
 * Implements hook_rules_event_info().
 */
function user_badges_rules_event_info() {
  $variables = array(
    'user' => array(
      'type' => 'user',
      'label' => t('User before receiving badge'),
    ),
    'badge_id' => array(
      'type' => 'text',
      'label' => t('The given Badge\'s ID'),
    ),
  );

  $items = array(
    'user_badges_badge_given' => array(
      'group' => t('User'),
      'label' => t('User was given a badge'),
      'variables' => $variables,
      'access callback' => 'user_badges_rules_integration_access'
    ),
    'user_badges_badge_removed' => array(
      'group' => t('User'),
      'label' => t('User was removed a badge'),
      'variables' => $variables,
      'access callback' => 'user_badges_rules_integration_access'
    ),
  );
  return $items;
}

/**
* Implementation of hook_rules_condition_info().
*/
function user_badges_rules_condition_info() { 
  $items = array(
    'user_badges_has_badge' => array(
     'label' => t('User has badge'),
     'base' => 'user_badges_rules_condition_has_badge',
     'parameter' => array(
        'badge_id' => array(
          'type' => 'text',
          'label' => t('Badge'),
          'options list' => 'user_badges_rules_get_badge_names',
          'restriction' => 'input',
        ),
        'user' => array(
          'type' => 'user',
          'label' => t('User'),
        ),
      ),
      'group' => t('User'),
   ),
    'user_badges_badge_count' => array(
      'label' => t('User badge count'),
      'base' => 'user_badges_rules_condition_badge_count',
      'parameter' => array(
        'user' => array(
          'type' => 'user',
          'label' => t('User')
        ),
        'operator' => array(
          'type' => 'text',
          'label' => t('User\'s number of badges is: '),
          'default value' => '=',
          'options list' => 'user_badges_rules_condition_operator_options',
          'restriction' => 'input',
        ),
        'number' => array(
          'type' => 'number',
          'label' => t('Number')
        ),
      ),
      'group' => t('User')
   ),
  );
  return $items;
}

/**
 *Function to load badges for options list
 *
 *@return
 *  An array of badge names
 */
function user_badges_rules_get_badge_names() {
  //Load the badges by calling this function
  $result = user_badges_load_badges();
  if ($result->rowCount()) {
    $badges = array();
    foreach ($result as $badge) {
      $badges[$badge->bid] = $badge->name . ' ' . '(Badge ID:' . ' ' . $badge->bid . ')';
    }
  }
  
  return $badges;
}

/**
* Base action implementation: user_badges.
*/
function user_badges_rules_action_add_badge_by_name($badge, $user) {
  user_badges_user_add_badge($user->uid, $badge, 'user');
}

/**
* Base action implementation: user_badges.
*/
function user_badges_rules_action_remove_badge_by_name($badge, $user) {
  user_badges_user_remove_badge($user->uid, $badge, 'user');
}

/**
 * Condition: User has badge.
 */
function user_badges_rules_condition_has_badge($badge_id, $user) {
  $has_badge = FALSE;
  $badges = user_badges_get_badges($user->uid);
  if (isset($badges[$badge_id])) {
    $has_badge = TRUE;
  }
  return $has_badge;
}

/**
 * Options list callback for the operator parameter of the user badges badge count condition.
 */
function user_badges_rules_condition_operator_options() {
  return array(
    '>'  => t('Greater than'),
    '>=' => t('Greater than or equal'),
    '='  => t('Equal to'),
    '<=' => t('Less than or equal'),
    '<'  => t('Less than'),
  );
}

/**
 * Condition: User badge count.
 */
function user_badges_rules_condition_badge_count($user, $operator, $number) {
  $badges = user_badges_get_badges($user->uid);
  $badges_count = count($badges);
  switch ($operator) {
    case '>' : return $badges_count >  $number;
    case '>=': return $badges_count >= $number;
    case '=' : return $badges_count == $number;
    case '<' : return $badges_count <  $number;
    case '<=': return $badges_count <= $number;
  }
}

/**
* Rules integration access callback.
*/
function user_badges_rules_integration_access($type, $name) {
  return user_access('manage badges');
}
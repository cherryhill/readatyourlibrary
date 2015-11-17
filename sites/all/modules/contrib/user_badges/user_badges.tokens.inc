<?php
/**
 * @file
 * Tokens functions for User Badges.
 */

/**
 * Implements hook_tokens().
 * @TODO: Add tokens for Submitted By module?
 */
function user_badges_tokens($type, $tokens, array $data = array(), array $options = array()) {
  $url_options = array('absolute' => TRUE);
  if (isset($options['language'])) {
    $url_options['language'] = $options['language'];
    $language_code = $options['language']->language;
  }
  else {
    $language_code = NULL;
  }

  $replacements = array();

  if ($type == 'userbadge') {
    $badge = $data['userbadge'];

    foreach ($tokens as $name => $original) {
      switch ($name) {
        case 'userbadge-name':
          $replacements[$original] = check_plain($badge->name);
          break;

        case 'userbadge-bid':
          $replacements[$original] = $badge->bid;
          break;
        
        case 'userbadge-uid':
          if (isset($badge->uid)) {
            $replacements[$original] = $badge->uid;
          }
          else {
            $replacements[$original] = 'no-uid-found';
          }
          break;
      }
    }
  }

  return $replacements;
}

/**
 * Implements hook_token_info().
 */
function user_badges_token_info() {
  $type = array(
    'name' => t('User Badges'),
    'description' => t('Tokens related to user badges.'),
    'needs-data' => 'userbadge',
  );

  $userbadge['userbadge-name'] = array(
    'name' => t('Badge Name'),
    'description' => t('The badge name.'),
  );

  $userbadge['userbadge-bid'] = array(
    'name' => t('Badge ID'),
    'description' => t('The badge id number (bid).'),
  );
  
  $userbadge['userbadge-uid'] = array(
    'name' => t('Badge UID'),
    'description' => t('The uid of the badge owner.'),
  );

  return array(
    'types' => array('userbadge' => $type),
    'tokens' => array('userbadge' => $userbadge),
  );
}

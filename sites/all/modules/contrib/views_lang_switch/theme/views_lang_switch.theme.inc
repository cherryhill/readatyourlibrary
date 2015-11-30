<?php

/**
 * @file
 * Theme include for the Views Language Switcher module.
 */

/**
 * Implements hook_theme().
 *
 * Sets template suggestions to allow themes to override output.
 */
function views_lang_switch_theme() {
  $registry['views_lang_switch_results'] = array(
    'render element' => 'elements',
    'template' => 'views-lang-switch-results',
    'path' => drupal_get_path('module', 'views_lang_switch') . '/theme',
  );
  $registry['views_lang_switch_result'] = array(
    'render element' => 'elements',
    'template' => 'views-lang-switch-result',
    'path' => drupal_get_path('module', 'views_lang_switch') . '/theme',
  );

  return $registry;
}

/**
 * Preprocess for our custom theme function: views_lang_switch_results
 *
 * Outputs an internationalized list of language links.
 */
function template_preprocess_views_lang_switch_results(&$vars) {
  global $language;
  $current_lang = $language->language;

  $language_list = _views_lang_switch_get_language_list();
  $path = check_plain($_GET['q']);
  $counts = $vars['counts'];
  $vars['views_lang_switch_output'] = '';

  foreach ($language_list as $code => $lang) {
    // First, set the language/path. We need these regardless of the count.
    $vars['views_lang_switch'][$code]['language'] = array(
      'name' => $lang->name,
      'native' => $lang->native,
      'code' => $code,
      'is_current' => ($code == $current_lang) ? 'vls-active' : '',
    );
    $vars['views_lang_switch'][$code]['path'] = '/'. $code .'/'. $path;

    // If the count of the number of nodes for this language is not set, then
    // we set it to be 1, as we can't be sure if there's content so we err on
    // the safe side and show the link.
    if (!isset($counts[$code])) {
      $counts[$code] = 1;
    }
    $vars['views_lang_switch'][$code]['count'] = $counts[$code];

    // Theme the data
    $vars['views_lang_switch_output'] .= theme('views_lang_switch_result',
      array(
        'vls_data' => $vars['views_lang_switch'][$code],
      )
    );
  }
}

/**
 * Preprocess for our custom theme function: views_lang_switch_result
 *
 * Outputs a single internationalized language link.
 */
function template_preprocess_views_lang_switch_result(&$vars) {
  // No preprocessing by default
}

<?php

/**
 * @file
 * Miscellaneous functions for auto_username.
 *
 * This also contains some constants giving human readable names to some numeric
 * settings; they're included here as they're only rarely used outside this file
 * anyway. Use module_load_include('inc', 'auto_username') if the constants need to
 * be available.
 *
 * These functions are borrowed from pathauto.
 */

/**
 * Case should be left as is in the generated username.
 */
define('AUN_CASE_LEAVE_ASIS', 0);

/**
 * Case should be lowercased in the generated username.
 */
define('AUN_CASE_LOWER', 1);

/**
 * Remove the punctuation from the username.
 */
define('AUN_PUNCTUATION_REMOVE', 0);

/**
 * Replace the punctuation with the separator in the username.
 */
define('AUN_PUNCTUATION_REPLACE', 1);

/**
 * Leave the punctuation as it is in the username.
 */
define('AUN_PUNCTUATION_DO_NOTHING', 2);

/**
 * Clean up a string segment to be used in a username.
 *
 * Performs the following possible alterations:
 * - Remove all HTML tags.
 * - Process the string through the transliteration module.
 * - Replace or remove punctuation with the separator character.
 * - Remove back-slashes.
 * - Replace non-ascii and non-numeric characters with the separator.
 * - Remove common words.
 * - Replace whitespace with the separator character.
 * - Trim duplicate, leading, and trailing separators.
 * - Convert to lower-case.
 * - Shorten to a desired length and logical position based on word boundaries.
 *
 * @param $string
 *   A string to clean.
 * @return
 *   The cleaned string.
 */
function auto_username_cleanstring($string) {
  // Use the advanced drupal_static() pattern, since this is called very often.
  static $drupal_static_fast;
  if (!isset($drupal_static_fast)) {
    $drupal_static_fast['cache'] = &drupal_static(__FUNCTION__);
  }
  $cache = &$drupal_static_fast['cache'];

  // Generate and cache variables used in this function so that on the second
  // call to auto_username_cleanstring() we focus on processing.
  if (!isset($cache)) {
    $cache = array(
      'separator' => variable_get('aun_separator', '-'),
      'transliterate' => variable_get('aun_transliterate', FALSE) && module_exists('transliteration'),
      'punctuation' => array(),
      'reduce_ascii' => (bool) variable_get('aun_reduce_ascii', FALSE),
      'ignore_words_regex' => FALSE,
      'replace_whitespace' => (bool) variable_get('aun_replace_whitespace', FALSE),
      'lowercase' => (bool) variable_get('aun_case', AUN_CASE_LOWER),
      'maxlength' => min(variable_get('aun_max_component_length', 60), _auto_username_get_schema_name_maxlength()),
    );

    // Generate and cache the punctuation replacements for strtr().
    $punctuation = auto_username_punctuation_chars();
    foreach ($punctuation as $name => $details) {
      $action = variable_get('aun_punctuation_' . $name, AUN_PUNCTUATION_REMOVE);
      switch ($action) {
        case AUN_PUNCTUATION_REMOVE:
          $cache['punctuation'][$details['value']] = '';
          break;
        case AUN_PUNCTUATION_REPLACE:
          $cache['punctuation'][$details['value']] = $cache['separator'];
          break;
        case AUN_PUNCTUATION_DO_NOTHING:
          // Literally do nothing.
          break;
      }
    }

    // Generate and cache the ignored words regular expression.
    $ignore_words = variable_get('aun_ignore_words', '');
    $ignore_words_regex = preg_replace(array('/^[,\s]+|[,\s]+$/', '/[,\s]+/'), array('', '\b|\b'), $ignore_words);
    if ($ignore_words_regex) {
      $cache['ignore_words_regex'] = '\b' . $ignore_words_regex . '\b';
      if (function_exists('mb_eregi_replace')) {
        $cache['ignore_words_callback'] = 'mb_eregi_replace';
      }
      else {
        $cache['ignore_words_callback'] = 'preg_replace';
        $cache['ignore_words_regex'] = '/' . $cache['ignore_words_regex'] . '/i';
      }
    }
  }

  // Empty strings do not need any proccessing.
  if ($string === '' || $string === NULL) {
    return '';
  }

  // Remove all HTML tags from the string.
  $output = strip_tags(decode_entities($string));

  // Optionally transliterate (by running through the Transliteration module)
  if ($cache['transliterate']) {
    $output = transliteration_get($output);
  }

  // Replace or drop punctuation based on user settings
  $output = strtr($output, $cache['punctuation']);

  // Reduce strings to letters and numbers
  if ($cache['reduce_ascii']) {
    $output = preg_replace('/[^a-zA-Z0-9\/]+/', $cache['separator'], $output);
  }

  // Get rid of words that are on the ignore list
  if ($cache['ignore_words_regex']) {
    $words_removed = $cache['ignore_words_callback']($cache['ignore_words_regex'], '', $output);
    if (drupal_strlen(trim($words_removed)) > 0) {
      $output = $words_removed;
    }
  }

  // Replace whitespace with the separator.
  if ($cache['replace_whitespace']) {
    $output = preg_replace('/\s+/', $cache['separator'], $output);
  }

  // Trim duplicates and remove trailing and leading separators.
  $output = _auto_username_clean_separators($output, $cache['separator']);

  // Optionally convert to lower case.
  if ($cache['lowercase']) {
    $output = drupal_strtolower($output);
  }

  // Shorten to a logical place based on word boundaries.
  $output = truncate_utf8($output, $cache['maxlength'], TRUE);

  return $output;
}

/**
 * Trims duplicate, leading, and trailing separators from a string.
 *
 * @param $string
 *   The string to clean separators from.
 * @param $separator
 *   The separator to use when cleaning.
 * @return
 *   The cleaned version of the string.
 *
 * @see auto_username_cleanstring()
 */
function _auto_username_clean_separators($string, $separator = NULL) {
  static $default_separator;

  if (!isset($separator)) {
    if (!isset($default_separator)) {
      $default_separator = variable_get('aun_separator', '-');
    }
    $separator = $default_separator;
  }

  $output = $string;

  // Clean duplicate or trailing separators.
  if (strlen($separator)) {
    // Escape the separator.
    $seppattern = preg_quote($separator, '/');

    // Trim any leading or trailing separators.
    $output = preg_replace("/^$seppattern+|$seppattern+$/", '', $output);

    // Replace trailing separators around slashes.
    if ($separator !== '/') {
      $output = preg_replace("/$seppattern+\/|\/$seppattern+/", "/", $output);
    }

    // Replace multiple separators with a single one.
    $output = preg_replace("/$seppattern+/", $separator, $output);
  }

  return $output;
}

/**
 * Return an array of arrays for punctuation values.
 *
 * Returns an array of arrays for punctuation values keyed by a name, including
 * the value and a textual description.
 * Can and should be expanded to include "all" non text punctuation values.
 *
 * @return
 *   An array of arrays for punctuation values keyed by a name, including the
 *   value and a textual description.
 */
function auto_username_punctuation_chars() {
  $punctuation = &drupal_static(__FUNCTION__);

  if (!isset($punctuation)) {
    $cid = 'auto_username:punctuation:' . $GLOBALS['language']->language;
    if ($cache = cache_get($cid)) {
      $punctuation = $cache->data;
    }
    else {
      $punctuation = array();
      $punctuation['double_quotes']      = array('value' => '"', 'name' => t('Double quotation marks'));
      $punctuation['quotes']             = array('value' => '\'', 'name' => t("Single quotation marks (apostrophe)"));
      $punctuation['backtick']           = array('value' => '`', 'name' => t('Back tick'));
      $punctuation['comma']              = array('value' => ',', 'name' => t('Comma'));
      $punctuation['period']             = array('value' => '.', 'name' => t('Period'));
      $punctuation['hyphen']             = array('value' => '-', 'name' => t('Hyphen'));
      $punctuation['underscore']         = array('value' => '_', 'name' => t('Underscore'));
      $punctuation['colon']              = array('value' => ':', 'name' => t('Colon'));
      $punctuation['semicolon']          = array('value' => ';', 'name' => t('Semicolon'));
      $punctuation['pipe']               = array('value' => '|', 'name' => t('Vertical bar (pipe)'));
      $punctuation['left_curly']         = array('value' => '{', 'name' => t('Left curly bracket'));
      $punctuation['left_square']        = array('value' => '[', 'name' => t('Left square bracket'));
      $punctuation['right_curly']        = array('value' => '}', 'name' => t('Right curly bracket'));
      $punctuation['right_square']       = array('value' => ']', 'name' => t('Right square bracket'));
      $punctuation['plus']               = array('value' => '+', 'name' => t('Plus sign'));
      $punctuation['equal']              = array('value' => '=', 'name' => t('Equal sign'));
      $punctuation['asterisk']           = array('value' => '*', 'name' => t('Asterisk'));
      $punctuation['ampersand']          = array('value' => '&', 'name' => t('Ampersand'));
      $punctuation['percent']            = array('value' => '%', 'name' => t('Percent sign'));
      $punctuation['caret']              = array('value' => '^', 'name' => t('Caret'));
      $punctuation['dollar']             = array('value' => '$', 'name' => t('Dollar sign'));
      $punctuation['hash']               = array('value' => '#', 'name' => t('Number sign (pound sign, hash)'));
      $punctuation['at']                 = array('value' => '@', 'name' => t('At sign'));
      $punctuation['exclamation']        = array('value' => '!', 'name' => t('Exclamation mark'));
      $punctuation['tilde']              = array('value' => '~', 'name' => t('Tilde'));
      $punctuation['left_parenthesis']   = array('value' => '(', 'name' => t('Left parenthesis'));
      $punctuation['right_parenthesis']  = array('value' => ')', 'name' => t('Right parenthesis'));
      $punctuation['question_mark']      = array('value' => '?', 'name' => t('Question mark'));
      $punctuation['less_than']          = array('value' => '<', 'name' => t('Less-than sign'));
      $punctuation['greater_than']       = array('value' => '>', 'name' => t('Greater-than sign'));
      $punctuation['slash']              = array('value' => '/', 'name' => t('Slash'));
      $punctuation['back_slash']         = array('value' => '\\', 'name' => t('Backslash'));

      // Allow modules to alter the punctuation list and cache the result.
      drupal_alter('auto_username_punctuation_chars', $punctuation);
      cache_set($cid, $punctuation);
    }
  }

  return $punctuation;
}

/**
 * Fetch the maximum length of the {users}.name field from the schema.
 *
 * @return
 *   An integer of the maximum username length allowed by the database.
 */
function _auto_username_get_schema_name_maxlength() {
  $maxlength = &drupal_static(__FUNCTION__);
  if (!isset($maxlength)) {
    $schema = drupal_get_schema('users');
    $maxlength = $schema['fields']['name']['length'];
  }
  return $maxlength;
}

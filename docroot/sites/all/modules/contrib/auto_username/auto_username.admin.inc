<?php

/**
 * @file
 * Form builder; displays the auto_username settings form.
 */

function auto_username_settings_form($form, &$form_state) {
  module_load_include('inc', 'auto_username');

  $form['aun_general_settings'] = array(
    '#type' => 'fieldset',
    '#title' => t('General settings'),
    '#collapsible' => TRUE,
    '#collapsed' => FALSE,
  );

  $form['aun_general_settings']['aun_pattern'] = array(
    '#type' => 'textarea',
    '#title' => t('Pattern for username'),
    '#description' => t('Enter the pattern for usernames.  You may use any of the tokens listed below.'),
    '#default_value' => variable_get('aun_pattern', ''),
  );

  $form['aun_general_settings']['token_help'] = array(
    '#title' => t('Replacement patterns'),
    '#type' => 'fieldset',
    '#collapsible' => TRUE,
    '#collapsed' => TRUE,
    '#description' => t('Note that fields that are not present in the user registration form will get replaced with an empty string when the account is created.  That is rarely desirable.'),
  );

  $form['aun_general_settings']['token_help']['help'] = array(
    '#theme' => 'token_tree',
    '#token_types' => array('user'),
    '#global_types' => FALSE,
  );

  // Other module configuration.
  $form['aun_other_settings'] = array(
    '#type' => 'fieldset',
    '#title' => t('Other settings'),
    '#collapsible' => TRUE,
    '#collapsed' => FALSE,
  );

  if (user_access('use PHP for username patterns')) {
    $form['aun_other_settings']['aun_php'] = array(
      '#type' => 'checkbox',
      '#title' => t('Evaluate PHP in pattern.'),
      '#description' => t('If this box is checked, the pattern will be executed as PHP code after token substitution has taken place.  You must surround the PHP code in &lt;?php and ?&gt; tags.  Token replacement will take place before PHP code execution.  Note that $account is available and can be used by your code.'),
      '#default_value' => variable_get('aun_php', FALSE),
    );
  }

  $form['aun_other_settings']['aun_update_on_edit'] = array(
    '#type' => 'checkbox',
    '#title' => t('Update on user edit'),
    '#description' => t('If this box is checked, the username will be reset any time the user\'s profile is updated.  That can help to enforce a username format, but may result in a user\'s login name changing unexpectedly.  It is best used in conjunction with an alternative login mechanism, such as OpenID or an e-mail address.'),
    '#default_value' => variable_get('aun_update_on_edit', TRUE),
  );

  $form['aun_other_settings']['aun_separator'] = array(
    '#type' => 'textfield',
    '#title' => t('Separator'),
    '#size' => 1,
    '#maxlength' => 1,
    '#default_value' => variable_get('aun_separator', '-'),
    '#description' => t('Character used to separate words in titles. This will replace any spaces and punctuation characters.'),
  );

  $form['aun_other_settings']['aun_case'] = array(
    '#type' => 'radios',
    '#title' => t('Character case'),
    '#default_value' => variable_get('aun_case', AUN_CASE_LEAVE_ASIS),
    '#options' => array(
      AUN_CASE_LEAVE_ASIS => t('Leave case the same as source token values.'),
      AUN_CASE_LOWER => t('Change to lower case'),
    ),
  );

  $max_length = _auto_username_get_schema_name_maxlength();

  $form['aun_other_settings']['aun_max_length'] = array(
    '#type' => 'textfield',
    '#title' => t('Maximum alias length'),
    '#size' => 3,
    '#maxlength' => 3,
    '#default_value' => variable_get('aun_max_length', 60),
    '#min_value' => 1,
    '#max_value' => $max_length,
    '#description' => t('Maximum length of aliases to generate. @max is the maximum possible length.', array('@max' => $max_length)),
    '#element_validate' => array('_auto_username_validate_numeric_element'),
  );
  $form['aun_other_settings']['aun_max_component_length'] = array(
    '#type' => 'textfield',
    '#title' => t('Maximum component length'),
    '#size' => 3,
    '#maxlength' => 3,
    '#default_value' => variable_get('aun_max_component_length', 60),
    '#min_value' => 1,
    '#max_value' => $max_length,
    '#description' => t('Maximum text length of any component in the username (e.g., [user:mail]). @max is the maximum possible length.', array('@max' => $max_length)),
    '#element_validate' => array('_auto_username_validate_numeric_element'),
  );

  $form['aun_other_settings']['aun_transliterate'] = array(
    '#type' => 'checkbox',
    '#title' => t('Transliterate prior to creating username'),
    '#default_value' => variable_get('aun_transliterate', FALSE) && module_exists('transliteration'),
    '#description' => t('When a pattern includes certain characters (such as those with accents) should auto_username attempt to transliterate them into the ASCII-96 alphabet? Transliteration is handled by the Transliteration module.'),
    '#access' => module_exists('transliteration'),
  );

  $form['aun_other_settings']['aun_reduce_ascii'] = array(
    '#type' => 'checkbox',
    '#title' => t('Reduce strings to letters and numbers'),
    '#default_value' => variable_get('aun_reduce_ascii', FALSE),
    '#description' => t('Filters the new username to only letters and numbers found in the ASCII-96 set.'),
  );

  $form['aun_other_settings']['aun_replace_whitespace'] = array(
    '#type' => 'checkbox',
    '#title' => t('Replace whitespace with separator.'),
    '#default_value' => variable_get('aun_replace_whitespace', FALSE),
    '#description' => t('Replace all whitespace in tokens with the separator character specified below.  Note that this will affect the tokens themselves, not the pattern specified above.  To avoid spaces entirely, ensure that the pattern above contains no spaces.'),
  );

  $form['aun_other_settings']['aun_ignore_words'] = array(
    '#type' => 'textarea',
    '#title' => t('Strings to Remove'),
    '#default_value' => variable_get('aun_ignore_words', ''),
    '#description' => t('Words to strip out of the username, separated by commas. Do not use this to remove punctuation.'),
    '#wysiwyg' => FALSE,
  );

  $form['punctuation'] = array(
    '#type' => 'fieldset',
    '#title' => t('Punctuation'),
    '#collapsible' => TRUE,
    '#collapsed' => TRUE,
  );

  $punctuation = auto_username_punctuation_chars();
  foreach ($punctuation as $name => $details) {
    $details['default'] = AUN_PUNCTUATION_REMOVE;
    if ($details['value'] == variable_get('aun_separator', '-')) {
      $details['default'] = AUN_PUNCTUATION_REPLACE;
    }
    $form['punctuation']['aun_punctuation_' . $name] = array(
      '#type' => 'select',
      '#title' => $details['name'] . ' (<code>' . check_plain($details['value']) . '</code>)',
      '#default_value' => variable_get('aun_punctuation_' . $name, $details['default']),
      '#options' => array(
        AUN_PUNCTUATION_REMOVE => t('Remove'),
        AUN_PUNCTUATION_REPLACE => t('Replace by separator'),
        AUN_PUNCTUATION_DO_NOTHING => t('No action (do not replace)'),
      ),
    );
  }

  return system_settings_form($form);
}

/**
 * Validate a form element that should have an numeric value.
 */
function _auto_username_validate_numeric_element($element, &$form_state) {
  $value = $element['#value'];

  if (!is_numeric($value)) {
    form_error($element, t('The field %name is not a valid number.', array('%name' => $element['#title'])));
  }
  elseif (isset($element['#max_value']) && $value > $element['#max_value']) {
    form_error($element, t('The field %name cannot be greater than @max.', array('%name' => $element['#title'], '@max' => $element['#max_value'])));
  }
  elseif (isset($element['#min_value']) && $value < $element['#min_value']) {
    form_error($element, t('The field %name cannot be less than @min.', array('%name' => $element['#title'], '@min' => $element['#min_value'])));
  }
}

/**
 * Validate auto_username_settings_form form submissions.
 */
function auto_username_settings_form_validate($form, &$form_state) {
  module_load_include('inc', 'auto_username');

  // Perform a basic check for HTML characters in the strings to remove field.
  if (strip_tags($form_state['values']['aun_ignore_words']) != $form_state['values']['aun_ignore_words']) {
    form_set_error('aun_ignore_words', t('The <em>Strings to remove</em> field must not contain HTML. Make sure to disable any WYSIWYG editors for this field.'));
  }

  // Validate that the separator is not set to be removed.
  // This isn't really all that bad so warn, but still allow them to save the value.
  $separator = $form_state['values']['aun_separator'];
  $punctuation = auto_username_punctuation_chars();
  foreach ($punctuation as $name => $details) {
    if ($details['value'] == $separator) {
      $action = $form_state['values']['aun_punctuation_' . $name];
      if ($action == AUN_PUNCTUATION_REMOVE) {
        drupal_set_message(t('You have configured the @name to be the separator and to be removed when encountered in strings. You should probably set the action for @name to be "replace by separator".', array('@name' => $details['name'])), 'error');
      }
    }
  }
}

<?php

/**
 * @file
 * Hooks for field_placeholder module.
 */

/**
 * Define field placeholder supported widgets.
 *
 * @return array
 *   An array whose keys are the widget names and whose value are the widget
 *   item where the placeholder will be attached.
 */
function hook_field_placeholder_info() {
  return array(
    'text_textfield' => 'value',
    'number' => 'value',
    'email_textfield' => 'email',
  );
}

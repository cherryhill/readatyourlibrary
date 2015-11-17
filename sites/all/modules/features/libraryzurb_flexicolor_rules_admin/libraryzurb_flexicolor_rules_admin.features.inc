<?php
/**
 * @file
 * libraryzurb_flexicolor_rules_admin.features.inc
 */

/**
 * Implements hook_flexicolor_features_default_selectors().
 */
function libraryzurb_flexicolor_rules_admin_flexicolor_features_default_selectors() {
  return array(
    '55831234eb908' => array(
      'machine' => '55831234eb908',
      'display_name' => 'ADMIN: Primary & Secondary Tabs',
      'selector' => '.primary-tabs .button, .primary-tabs .button.secondary, .secondary-tabs .button, .secondary-tabs .button.secondary',
      'type' => 'background-color',
      'default_color' => '#e9e9e9',
    ),
    '55831285944d4' => array(
      'machine' => '55831285944d4',
      'display_name' => 'ADMIN: Primary & Secondary Tabs',
      'selector' => '.primary-tabs .button, .primary-tabs .button.secondary, .secondary-tabs .button, .secondary-tabs .button.secondary',
      'type' => 'border-color',
      'default_color' => '#d0d0d0',
    ),
    '5583129d07e10' => array(
      'machine' => '5583129d07e10',
      'display_name' => 'ADMIN: Primary & Secondary Tabs',
      'selector' => '.primary-tabs .button, .primary-tabs .button.secondary, .secondary-tabs .button, .secondary-tabs .button.secondary',
      'type' => 'color',
      'default_color' => '#333',
    ),
    '55831369e041e' => array(
      'machine' => '55831369e041e',
      'display_name' => 'ADMIN: Primary & Secondary Tabs Hover',
      'selector' => '.primary-tabs .button:focus, .primary-tabs .button:hover, .primary-tabs .button.secondary:focus, .primary-tabs .button.secondary:hover, .secondary-tabs .button:focus, .secondary-tabs .button:hover, .secondary-tabs .button.secondary:focus, .secondary-tabs .button.secondary:hover',
      'type' => 'background-color',
      'default_color' => '#d0d0d0',
    ),
  );
}

<?php
/**
 * @file
 * play_library_program.ds.inc
 */

/**
 * Implements hook_ds_field_settings_info().
 */
function play_library_program_ds_field_settings_info() {
  $export = array();

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'raffle|raffle|default';
  $ds_fieldsetting->entity_type = 'raffle';
  $ds_fieldsetting->bundle = 'raffle';
  $ds_fieldsetting->view_mode = 'default';
  $ds_fieldsetting->settings = array(
    'raffle_entries' => array(
      'weight' => '3',
      'label' => 'hidden',
      'format' => 'default',
      'formatter_settings' => array(
        'show_title' => 1,
        'title_wrapper' => 'h3',
        'ctools' => 'a:3:{s:4:"conf";a:16:{s:23:"override_pager_settings";i:0;s:9:"use_pager";i:0;s:14:"nodes_per_page";s:1:"0";s:8:"pager_id";s:1:"0";s:6:"offset";s:1:"0";s:9:"more_link";i:0;s:10:"feed_icons";i:0;s:10:"panel_args";i:0;s:12:"link_to_view";i:0;s:4:"args";s:0:"";s:3:"url";s:0:"";s:7:"display";s:7:"default";s:7:"context";a:1:{i:0;s:30:"argument_entity_id:raffle_1.id";}s:14:"override_title";i:0;s:19:"override_title_text";s:0:"";s:22:"override_title_heading";s:2:"h2";}s:4:"type";s:5:"views";s:7:"subtype";s:15:"raffle_entrants";}',
        'load_terms' => 0,
      ),
    ),
    'raffle_winners' => array(
      'weight' => '2',
      'label' => 'hidden',
      'format' => 'default',
      'formatter_settings' => array(
        'show_title' => 1,
        'title_wrapper' => 'h3',
        'ctools' => 'a:3:{s:4:"conf";a:16:{s:23:"override_pager_settings";i:0;s:9:"use_pager";i:1;s:14:"nodes_per_page";s:2:"10";s:8:"pager_id";s:1:"0";s:6:"offset";s:1:"0";s:9:"more_link";i:0;s:10:"feed_icons";i:0;s:10:"panel_args";i:0;s:12:"link_to_view";i:0;s:4:"args";s:0:"";s:3:"url";s:0:"";s:7:"display";s:7:"default";s:7:"context";a:1:{i:0;s:30:"argument_entity_id:raffle_1.id";}s:14:"override_title";i:0;s:19:"override_title_text";s:0:"";s:22:"override_title_heading";s:2:"h2";}s:4:"type";s:5:"views";s:7:"subtype";s:13:"raffle_winner";}',
        'load_terms' => 0,
      ),
    ),
  );
  $export['raffle|raffle|default'] = $ds_fieldsetting;

  return $export;
}

/**
 * Implements hook_ds_custom_fields_info().
 */
function play_library_program_ds_custom_fields_info() {
  $export = array();

  $ds_field = new stdClass();
  $ds_field->api_version = 1;
  $ds_field->field = 'raffle_entries';
  $ds_field->label = 'Raffle Entries';
  $ds_field->field_type = 7;
  $ds_field->entities = array(
    'raffle' => 'raffle',
  );
  $ds_field->ui_limit = 'raffle|*';
  $ds_field->properties = array(
    'default' => array(),
    'settings' => array(
      'show_title' => array(
        'type' => 'checkbox',
      ),
      'title_wrapper' => array(
        'type' => 'textfield',
        'description' => 'Eg: h1, h2, p',
      ),
      'ctools' => array(
        'type' => 'ctools',
      ),
    ),
  );
  $export['raffle_entries'] = $ds_field;

  $ds_field = new stdClass();
  $ds_field->api_version = 1;
  $ds_field->field = 'raffle_winners';
  $ds_field->label = 'Raffle Winners';
  $ds_field->field_type = 7;
  $ds_field->entities = array(
    'raffle' => 'raffle',
  );
  $ds_field->ui_limit = 'raffle|*';
  $ds_field->properties = array(
    'default' => array(),
    'settings' => array(
      'show_title' => array(
        'type' => 'checkbox',
      ),
      'title_wrapper' => array(
        'type' => 'textfield',
        'description' => 'Eg: h1, h2, p',
      ),
      'ctools' => array(
        'type' => 'ctools',
      ),
    ),
  );
  $export['raffle_winners'] = $ds_field;

  return $export;
}

/**
 * Implements hook_ds_layout_settings_info().
 */
function play_library_program_ds_layout_settings_info() {
  $export = array();

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'raffle|raffle|default';
  $ds_layout->entity_type = 'raffle';
  $ds_layout->bundle = 'raffle';
  $ds_layout->view_mode = 'default';
  $ds_layout->layout = 'ds_1col';
  $ds_layout->settings = array(
    'regions' => array(
      'ds_content' => array(
        0 => 'field_raffle_reward',
        1 => 'field_raffle_message',
        2 => 'raffle_winners',
        3 => 'raffle_entries',
      ),
    ),
    'fields' => array(
      'field_raffle_reward' => 'ds_content',
      'field_raffle_message' => 'ds_content',
      'raffle_winners' => 'ds_content',
      'raffle_entries' => 'ds_content',
    ),
    'classes' => array(),
    'wrappers' => array(
      'ds_content' => 'div',
    ),
    'layout_wrapper' => 'div',
    'layout_attributes' => '',
    'layout_attributes_merge' => 1,
    'layout_link_attribute' => '',
    'layout_link_custom' => '',
  );
  $export['raffle|raffle|default'] = $ds_layout;

  return $export;
}

<?php
/**
 * @file
 * feature_for_reward.features.field_instance.inc
 */

/**
 * Implements hook_field_default_field_instances().
 */
function feature_for_reward_field_default_field_instances() {
  $field_instances = array();

  // Exported field_instance:
  // 'field_collection_item-field_raffle_notification-field_message_reward_winner'.
  $field_instances['field_collection_item-field_raffle_notification-field_message_reward_winner'] = array(
    'bundle' => 'field_raffle_notification',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(
          'field_delimiter' => '',
        ),
        'type' => 'text_default',
        'weight' => 0,
      ),
    ),
    'display_label' => '',
    'entity_type' => 'field_collection_item',
    'field_name' => 'field_message_reward_winner',
    'label' => 'Message to be sent to reward winner',
    'required' => 0,
    'settings' => array(
      'better_formats' => array(
        'allowed_formats' => array(
          'filtered_html' => 'filtered_html',
          'full_html' => 'full_html',
          'php_code' => 'php_code',
          'plain_text' => 'plain_text',
        ),
        'allowed_formats_toggle' => 0,
        'default_order_toggle' => 0,
        'default_order_wrapper' => array(
          'formats' => array(
            'filtered_html' => array(
              'weight' => 0,
            ),
            'full_html' => array(
              'weight' => 1,
            ),
            'php_code' => array(
              'weight' => 11,
            ),
            'plain_text' => array(
              'weight' => 10,
            ),
          ),
        ),
      ),
      'linkit' => array(
        'enable' => 0,
        'insert_plugin' => '',
      ),
      'text_processing' => 0,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'text',
      'settings' => array(
        'rows' => 5,
      ),
      'type' => 'text_textarea',
      'weight' => 1,
    ),
    'workbench_access_field' => 0,
  );

  // Exported field_instance:
  // 'field_collection_item-field_raffle_notification-field_onscreen_reward'.
  $field_instances['field_collection_item-field_raffle_notification-field_onscreen_reward'] = array(
    'bundle' => 'field_raffle_notification',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(
          'field_delimiter' => '',
        ),
        'type' => 'text_default',
        'weight' => 1,
      ),
    ),
    'display_label' => '',
    'entity_type' => 'field_collection_item',
    'field_name' => 'field_onscreen_reward',
    'label' => 'Onscreen alert on winning this reward',
    'required' => 0,
    'settings' => array(
      'better_formats' => array(
        'allowed_formats' => array(
          'filtered_html' => 'filtered_html',
          'full_html' => 'full_html',
          'php_code' => 'php_code',
          'plain_text' => 'plain_text',
        ),
        'allowed_formats_toggle' => 0,
        'default_order_toggle' => 0,
        'default_order_wrapper' => array(
          'formats' => array(
            'filtered_html' => array(
              'weight' => 0,
            ),
            'full_html' => array(
              'weight' => 1,
            ),
            'php_code' => array(
              'weight' => 11,
            ),
            'plain_text' => array(
              'weight' => 10,
            ),
          ),
        ),
      ),
      'linkit' => array(
        'enable' => 0,
        'insert_plugin' => '',
      ),
      'text_processing' => 0,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'text',
      'settings' => array(
        'rows' => 5,
      ),
      'type' => 'text_textarea',
      'weight' => 2,
    ),
    'workbench_access_field' => 0,
  );

  // Exported field_instance:
  // 'field_collection_item-field_raffle_notification-field_raffle_description'.
  $field_instances['field_collection_item-field_raffle_notification-field_raffle_description'] = array(
    'bundle' => 'field_raffle_notification',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(
          'field_delimiter' => '',
        ),
        'type' => 'text_default',
        'weight' => 2,
      ),
    ),
    'display_label' => '',
    'entity_type' => 'field_collection_item',
    'field_name' => 'field_raffle_description',
    'label' => 'Raffle ticket description',
    'required' => 0,
    'settings' => array(
      'better_formats' => array(
        'allowed_formats' => array(
          'filtered_html' => 'filtered_html',
          'full_html' => 'full_html',
          'php_code' => 'php_code',
          'plain_text' => 'plain_text',
        ),
        'allowed_formats_toggle' => 0,
        'default_order_toggle' => 0,
        'default_order_wrapper' => array(
          'formats' => array(
            'filtered_html' => array(
              'weight' => 0,
            ),
            'full_html' => array(
              'weight' => 1,
            ),
            'php_code' => array(
              'weight' => 11,
            ),
            'plain_text' => array(
              'weight' => 10,
            ),
          ),
        ),
      ),
      'linkit' => array(
        'enable' => 0,
        'insert_plugin' => '',
      ),
      'text_processing' => 0,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'text',
      'settings' => array(
        'rows' => 5,
      ),
      'type' => 'text_textarea',
      'weight' => 3,
    ),
    'workbench_access_field' => 0,
  );

  // Exported field_instance:
  // 'field_collection_item-field_raffle_reward_noti-field_message_prize_winner'.
  $field_instances['field_collection_item-field_raffle_reward_noti-field_message_prize_winner'] = array(
    'bundle' => 'field_raffle_reward_noti',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(
          'field_delimiter' => '',
        ),
        'type' => 'text_default',
        'weight' => 0,
      ),
    ),
    'display_label' => '',
    'entity_type' => 'field_collection_item',
    'field_name' => 'field_message_prize_winner',
    'label' => 'Message to be sent to reward winner',
    'required' => 0,
    'settings' => array(
      'better_formats' => array(
        'allowed_formats' => array(
          'filtered_html' => 'filtered_html',
          'full_html' => 'full_html',
          'php_code' => 'php_code',
          'plain_text' => 'plain_text',
        ),
        'allowed_formats_toggle' => 0,
        'default_order_toggle' => 0,
        'default_order_wrapper' => array(
          'formats' => array(
            'filtered_html' => array(
              'weight' => 0,
            ),
            'full_html' => array(
              'weight' => 1,
            ),
            'php_code' => array(
              'weight' => 11,
            ),
            'plain_text' => array(
              'weight' => 10,
            ),
          ),
        ),
      ),
      'linkit' => array(
        'enable' => 0,
        'insert_plugin' => '',
      ),
      'text_processing' => 0,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'text',
      'settings' => array(
        'rows' => 5,
      ),
      'type' => 'text_textarea',
      'weight' => 1,
    ),
    'workbench_access_field' => 0,
  );

  // Exported field_instance:
  // 'field_collection_item-field_raffle_reward_noti-field_onscreen_prize'.
  $field_instances['field_collection_item-field_raffle_reward_noti-field_onscreen_prize'] = array(
    'bundle' => 'field_raffle_reward_noti',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(
          'field_delimiter' => '',
        ),
        'type' => 'text_default',
        'weight' => 1,
      ),
    ),
    'display_label' => '',
    'entity_type' => 'field_collection_item',
    'field_name' => 'field_onscreen_prize',
    'label' => 'Onscreen alert on winning this reward',
    'required' => 0,
    'settings' => array(
      'better_formats' => array(
        'allowed_formats' => array(
          'filtered_html' => 'filtered_html',
          'full_html' => 'full_html',
          'php_code' => 'php_code',
          'plain_text' => 'plain_text',
        ),
        'allowed_formats_toggle' => 0,
        'default_order_toggle' => 0,
        'default_order_wrapper' => array(
          'formats' => array(
            'filtered_html' => array(
              'weight' => 0,
            ),
            'full_html' => array(
              'weight' => 1,
            ),
            'php_code' => array(
              'weight' => 11,
            ),
            'plain_text' => array(
              'weight' => 10,
            ),
          ),
        ),
      ),
      'linkit' => array(
        'enable' => 0,
        'insert_plugin' => '',
      ),
      'text_processing' => 0,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'text',
      'settings' => array(
        'rows' => 5,
      ),
      'type' => 'text_textarea',
      'weight' => 2,
    ),
    'workbench_access_field' => 0,
  );

  // Exported field_instance:
  // 'field_collection_item-field_raffle_reward_noti-field_raffle_prize_desc'.
  $field_instances['field_collection_item-field_raffle_reward_noti-field_raffle_prize_desc'] = array(
    'bundle' => 'field_raffle_reward_noti',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(
          'field_delimiter' => '',
        ),
        'type' => 'text_default',
        'weight' => 2,
      ),
    ),
    'display_label' => '',
    'entity_type' => 'field_collection_item',
    'field_name' => 'field_raffle_prize_desc',
    'label' => 'Raffle prize description',
    'required' => 0,
    'settings' => array(
      'better_formats' => array(
        'allowed_formats' => array(
          'filtered_html' => 'filtered_html',
          'full_html' => 'full_html',
          'php_code' => 'php_code',
          'plain_text' => 'plain_text',
        ),
        'allowed_formats_toggle' => 0,
        'default_order_toggle' => 0,
        'default_order_wrapper' => array(
          'formats' => array(
            'filtered_html' => array(
              'weight' => 0,
            ),
            'full_html' => array(
              'weight' => 1,
            ),
            'php_code' => array(
              'weight' => 11,
            ),
            'plain_text' => array(
              'weight' => 10,
            ),
          ),
        ),
      ),
      'linkit' => array(
        'enable' => 0,
        'insert_plugin' => '',
      ),
      'text_processing' => 0,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'text',
      'settings' => array(
        'rows' => 5,
      ),
      'type' => 'text_textarea',
      'weight' => 3,
    ),
    'workbench_access_field' => 0,
  );

  // Exported field_instance: 'reward-raffle_claim-field_raffle_claim_id'.
  $field_instances['reward-raffle_claim-field_raffle_claim_id'] = array(
    'bundle' => 'raffle_claim',
    'default_value' => NULL,
    'default_value_function' => '',
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'entityreference',
        'settings' => array(
          'link' => FALSE,
        ),
        'type' => 'entityreference_label',
        'weight' => 0,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'display_label' => '',
    'entity_type' => 'reward',
    'field_name' => 'field_raffle_claim_id',
    'label' => 'Raffle Claim ID',
    'required' => 0,
    'settings' => array(
      'behaviors' => array(
        'prepopulate' => array(
          'status' => 0,
        ),
      ),
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'options',
      'settings' => array(
        'apply_chosen' => '',
      ),
      'type' => 'options_select',
      'weight' => 1,
    ),
    'workbench_access_field' => 0,
  );

  // Exported field_instance: 'reward-raffle_claim-field_raffle_drawing_name'.
  $field_instances['reward-raffle_claim-field_raffle_drawing_name'] = array(
    'bundle' => 'raffle_claim',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 2,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'display_label' => '',
    'entity_type' => 'reward',
    'field_name' => 'field_raffle_drawing_name',
    'label' => 'Raffle Drawing Name',
    'required' => 0,
    'settings' => array(
      'better_formats' => array(
        'allowed_formats' => array(
          'filtered_html' => 'filtered_html',
          'full_html' => 'full_html',
          'php_code' => 'php_code',
          'plain_text' => 'plain_text',
        ),
        'allowed_formats_toggle' => 0,
        'default_order_toggle' => 0,
        'default_order_wrapper' => array(
          'formats' => array(
            'filtered_html' => array(
              'weight' => 0,
            ),
            'full_html' => array(
              'weight' => 1,
            ),
            'php_code' => array(
              'weight' => 11,
            ),
            'plain_text' => array(
              'weight' => 10,
            ),
          ),
        ),
      ),
      'linkit' => array(
        'enable' => 0,
        'insert_plugin' => '',
      ),
      'text_processing' => 0,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'text',
      'settings' => array(
        'size' => 60,
      ),
      'type' => 'text_textfield',
      'weight' => 3,
    ),
    'workbench_access_field' => 0,
  );

  // Exported field_instance: 'reward-raffle_claim-field_rf_receieved_reward'.
  $field_instances['reward-raffle_claim-field_rf_receieved_reward'] = array(
    'bundle' => 'raffle_claim',
    'default_value' => array(
      0 => array(
        'value' => 0,
      ),
    ),
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'number',
        'settings' => array(
          'decimal_separator' => '.',
          'prefix_suffix' => TRUE,
          'scale' => 0,
          'thousand_separator' => '',
        ),
        'type' => 'number_integer',
        'weight' => 1,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'display_label' => '',
    'entity_type' => 'reward',
    'field_name' => 'field_rf_receieved_reward',
    'label' => 'receieved_reward',
    'required' => 0,
    'settings' => array(
      'max' => '',
      'min' => '',
      'prefix' => '',
      'suffix' => '',
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 0,
      'module' => 'number',
      'settings' => array(),
      'type' => 'number',
      'weight' => 2,
    ),
    'workbench_access_field' => 0,
  );

  // Exported field_instance: 'reward-reward-field_activities_reward'.
  $field_instances['reward-reward-field_activities_reward'] = array(
    'bundle' => 'reward',
    'default_value' => NULL,
    'default_value_function' => '',
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'entityreference',
        'settings' => array(
          'field_delimiter' => '',
          'link' => FALSE,
        ),
        'type' => 'entityreference_label',
        'weight' => 14,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'display_label' => '',
    'entity_type' => 'reward',
    'field_name' => 'field_activities_reward',
    'label' => 'Activities from which user can get this reward/raffle ticket',
    'required' => 1,
    'settings' => array(
      'behaviors' => array(
        'prepopulate' => array(
          'status' => 0,
        ),
      ),
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'entityreference',
      'settings' => array(
        'apply_chosen' => '',
        'fields' => array(),
        'match_operator' => 'CONTAINS',
        'path' => '',
        'size' => 60,
        'type_settings' => array(),
      ),
      'type' => 'entityreference_autocomplete_tags',
      'weight' => 11,
    ),
    'workbench_access_field' => 0,
  );

  // Exported field_instance: 'reward-reward-field_age_group'.
  $field_instances['reward-reward-field_age_group'] = array(
    'bundle' => 'reward',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '(0 or blank represents no limit)',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'range',
        'settings' => array(
          'combined_prefix_suffix' => FALSE,
          'decimal_separator' => '.',
          'field_delimiter' => '',
          'field_prefix_suffix' => TRUE,
          'from_prefix_suffix' => TRUE,
          'range_combine' => FALSE,
          'range_separator' => '-',
          'scale' => 0,
          'thousand_separator' => ' ',
          'to_prefix_suffix' => TRUE,
        ),
        'type' => 'range_integer',
        'weight' => 13,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'display_label' => '',
    'entity_type' => 'reward',
    'field_name' => 'field_age_group',
    'label' => 'Age group',
    'required' => 0,
    'settings' => array(
      'combined' => array(
        'prefix' => '',
        'suffix' => '',
      ),
      'field' => array(
        'prefix' => '',
        'suffix' => '',
      ),
      'from' => array(
        'label' => 'From',
        'prefix' => '',
        'suffix' => '',
      ),
      'max' => '',
      'min' => '',
      'to' => array(
        'label' => 'to',
        'prefix' => '',
        'suffix' => '',
      ),
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 0,
      'module' => 'range',
      'settings' => array(),
      'type' => 'range',
      'weight' => 10,
    ),
    'workbench_access_field' => 0,
  );

  // Exported field_instance: 'reward-reward-field_category'.
  $field_instances['reward-reward-field_category'] = array(
    'bundle' => 'reward',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'list',
        'settings' => array(
          'field_delimiter' => '',
        ),
        'type' => 'list_default',
        'weight' => 4,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'display_label' => '',
    'entity_type' => 'reward',
    'field_name' => 'field_category',
    'label' => 'Category',
    'required' => 1,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'options',
      'settings' => array(
        'apply_chosen' => '',
      ),
      'type' => 'options_select',
      'weight' => 0,
    ),
    'workbench_access_field' => 0,
  );

  // Exported field_instance: 'reward-reward-field_dates_reward'.
  $field_instances['reward-reward-field_dates_reward'] = array(
    'bundle' => 'reward',
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'date',
        'settings' => array(
          'field_delimiter' => '',
          'format_type' => 'long',
          'fromto' => 'both',
          'multiple_from' => '',
          'multiple_number' => '',
          'multiple_to' => '',
          'show_remaining_days' => FALSE,
        ),
        'type' => 'date_default',
        'weight' => 11,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'display_label' => '',
    'entity_type' => 'reward',
    'field_name' => 'field_dates_reward',
    'label' => 'Dates between which this reward/raffle ticket can be earned',
    'required' => 1,
    'settings' => array(
      'default_value' => 'now',
      'default_value2' => 'same',
      'default_value_code' => '',
      'default_value_code2' => '',
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'date',
      'settings' => array(
        'increment' => 15,
        'input_format' => 'm/d/Y - H:i:s',
        'input_format_custom' => '',
        'label_position' => 'above',
        'no_fieldset' => 0,
        'text_parts' => array(),
        'year_range' => '-3:+3',
      ),
      'type' => 'date_popup',
      'weight' => 8,
    ),
    'workbench_access_field' => 0,
  );

  // Exported field_instance: 'reward-reward-field_maximum_num_reward'.
  $field_instances['reward-reward-field_maximum_num_reward'] = array(
    'bundle' => 'reward',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '(0 or blank represents no limit)',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'number',
        'settings' => array(
          'decimal_separator' => '.',
          'field_delimiter' => '',
          'prefix_suffix' => TRUE,
          'scale' => 0,
          'thousand_separator' => '',
        ),
        'type' => 'number_integer',
        'weight' => 10,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'display_label' => '',
    'entity_type' => 'reward',
    'field_name' => 'field_maximum_num_reward',
    'label' => 'If yes, maximum number of times a user can get this reward',
    'required' => 0,
    'settings' => array(
      'max' => '',
      'min' => '',
      'prefix' => '',
      'suffix' => '',
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 0,
      'module' => 'number',
      'settings' => array(),
      'type' => 'number',
      'weight' => 7,
    ),
    'workbench_access_field' => 0,
  );

  // Exported field_instance: 'reward-reward-field_points'.
  $field_instances['reward-reward-field_points'] = array(
    'bundle' => 'reward',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'number',
        'settings' => array(
          'decimal_separator' => '.',
          'field_delimiter' => '',
          'prefix_suffix' => TRUE,
          'scale' => 0,
          'thousand_separator' => '',
        ),
        'type' => 'number_integer',
        'weight' => 8,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'display_label' => '',
    'entity_type' => 'reward',
    'field_name' => 'field_points',
    'label' => 'Points to get reward or raffle ticket',
    'required' => 1,
    'settings' => array(
      'max' => '',
      'min' => '',
      'prefix' => '',
      'suffix' => '',
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 0,
      'module' => 'number',
      'settings' => array(),
      'type' => 'number',
      'weight' => 5,
    ),
    'workbench_access_field' => 0,
  );

  // Exported field_instance: 'reward-reward-field_raffle_notification'.
  $field_instances['reward-reward-field_raffle_notification'] = array(
    'bundle' => 'reward',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'If no automatic notifications should be sent, leave these fields blank.',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'field_collection',
        'settings' => array(
          'add' => 'Add',
          'delete' => 'Delete',
          'description' => TRUE,
          'edit' => 'Edit',
          'field_delimiter' => '',
          'view_mode' => 'full',
        ),
        'type' => 'field_collection_view',
        'weight' => 16,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'display_label' => '',
    'entity_type' => 'reward',
    'field_name' => 'field_raffle_notification',
    'label' => 'Raffle Ticket Notifications',
    'required' => 0,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 0,
      'module' => 'field_collection',
      'settings' => array(),
      'type' => 'field_collection_embed',
      'weight' => 13,
    ),
    'workbench_access_field' => 0,
  );

  // Exported field_instance: 'reward-reward-field_raffle_prize_or_reward_ima'.
  $field_instances['reward-reward-field_raffle_prize_or_reward_ima'] = array(
    'bundle' => 'reward',
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'image',
        'settings' => array(
          'field_delimiter' => '',
          'image_link' => '',
          'image_style' => '',
        ),
        'type' => 'image',
        'weight' => 7,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'display_label' => '',
    'entity_type' => 'reward',
    'field_name' => 'field_raffle_prize_or_reward_ima',
    'label' => 'Raffle prize or reward image',
    'required' => 0,
    'settings' => array(
      'alt_field' => 0,
      'default_image' => 0,
      'file_directory' => '',
      'file_extensions' => 'png gif jpg jpeg',
      'max_filesize' => '',
      'max_resolution' => '',
      'min_resolution' => '',
      'title_field' => 0,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'image',
      'settings' => array(
        'filefield_sources' => array(
          'filefield_sources' => array(
            'attach' => 0,
            'clipboard' => 0,
            'imce' => 0,
            'reference' => 0,
            'remote' => 0,
            'upload' => 'upload',
          ),
          'source_attach' => array(
            'absolute' => 0,
            'attach_mode' => 'move',
            'path' => 'file_attach',
          ),
          'source_imce' => array(
            'imce_mode' => 0,
          ),
          'source_reference' => array(
            'autocomplete' => 0,
            'search_all_fields' => 0,
          ),
        ),
        'preview_image_style' => 'thumbnail',
        'progress_indicator' => 'throbber',
      ),
      'type' => 'image_image',
      'weight' => 4,
    ),
    'workbench_access_field' => 0,
  );

  // Exported field_instance: 'reward-reward-field_raffle_reward_noti'.
  $field_instances['reward-reward-field_raffle_reward_noti'] = array(
    'bundle' => 'reward',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'If no automatic notifications should be sent, leave these fields blank.',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'field_collection',
        'settings' => array(
          'add' => 'Add',
          'delete' => 'Delete',
          'description' => TRUE,
          'edit' => 'Edit',
          'field_delimiter' => '',
          'view_mode' => 'full',
        ),
        'type' => 'field_collection_view',
        'weight' => 17,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'display_label' => '',
    'entity_type' => 'reward',
    'field_name' => 'field_raffle_reward_noti',
    'label' => 'Raffle Prize or Reward Notifications',
    'required' => 0,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 0,
      'module' => 'field_collection',
      'settings' => array(),
      'type' => 'field_collection_embed',
      'weight' => 14,
    ),
    'workbench_access_field' => 0,
  );

  // Exported field_instance: 'reward-reward-field_raffle_ticket_image'.
  $field_instances['reward-reward-field_raffle_ticket_image'] = array(
    'bundle' => 'reward',
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'image',
        'settings' => array(
          'field_delimiter' => '',
          'image_link' => '',
          'image_style' => '',
        ),
        'type' => 'image',
        'weight' => 6,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'display_label' => '',
    'entity_type' => 'reward',
    'field_name' => 'field_raffle_ticket_image',
    'label' => 'Raffle Ticket Image',
    'required' => 0,
    'settings' => array(
      'alt_field' => 0,
      'default_image' => 0,
      'file_directory' => '',
      'file_extensions' => 'png gif jpg jpeg',
      'max_filesize' => '',
      'max_resolution' => '',
      'min_resolution' => '',
      'title_field' => 0,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'image',
      'settings' => array(
        'filefield_sources' => array(
          'filefield_sources' => array(
            'attach' => 0,
            'clipboard' => 0,
            'imce' => 0,
            'reference' => 0,
            'remote' => 0,
            'upload' => 'upload',
          ),
          'source_attach' => array(
            'absolute' => 0,
            'attach_mode' => 'move',
            'path' => 'file_attach',
          ),
          'source_imce' => array(
            'imce_mode' => 0,
          ),
          'source_reference' => array(
            'autocomplete' => 0,
            'search_all_fields' => 0,
          ),
        ),
        'preview_image_style' => 'thumbnail',
        'progress_indicator' => 'throbber',
      ),
      'type' => 'image_image',
      'weight' => 3,
    ),
    'workbench_access_field' => 0,
  );

  // Exported field_instance: 'reward-reward-field_repeatable'.
  $field_instances['reward-reward-field_repeatable'] = array(
    'bundle' => 'reward',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'list',
        'settings' => array(
          'field_delimiter' => '',
        ),
        'type' => 'list_default',
        'weight' => 9,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'display_label' => '',
    'entity_type' => 'reward',
    'field_name' => 'field_repeatable',
    'label' => 'Repeatable',
    'required' => 1,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'options',
      'settings' => array(),
      'type' => 'options_buttons',
      'weight' => 6,
    ),
    'workbench_access_field' => 0,
  );

  // Exported field_instance: 'reward-reward-field_roles_reward'.
  $field_instances['reward-reward-field_roles_reward'] = array(
    'bundle' => 'reward',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'role_field',
        'settings' => array(
          'field_delimiter' => '',
        ),
        'type' => 'role_field_formatter',
        'weight' => 12,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'display_label' => '',
    'entity_type' => 'reward',
    'field_name' => 'field_roles_reward',
    'instance_cardinality' => 0,
    'label' => 'Roles which can receive this reward or raffle ticket',
    'required' => 1,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'options',
      'settings' => array(),
      'type' => 'options_buttons',
      'weight' => 9,
    ),
    'workbench_access_field' => 0,
  );

  // Exported field_instance: 'reward-reward-field_status_reward'.
  $field_instances['reward-reward-field_status_reward'] = array(
    'bundle' => 'reward',
    'default_value' => array(
      0 => array(
        'value' => 'active',
      ),
    ),
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'list',
        'settings' => array(
          'field_delimiter' => '',
        ),
        'type' => 'list_default',
        'weight' => 15,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'display_label' => '',
    'entity_type' => 'reward',
    'field_name' => 'field_status_reward',
    'label' => 'Status of reward or raffle',
    'required' => 0,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'options',
      'settings' => array(),
      'type' => 'options_buttons',
      'weight' => 12,
    ),
    'workbench_access_field' => 0,
  );

  // Exported field_instance: 'reward-reward-field_type_of_reward_raffle_priz'.
  $field_instances['reward-reward-field_type_of_reward_raffle_priz'] = array(
    'bundle' => 'reward',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'taxonomy',
        'settings' => array(
          'field_delimiter' => '',
        ),
        'type' => 'taxonomy_term_reference_link',
        'weight' => 5,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'display_label' => '',
    'entity_type' => 'reward',
    'field_name' => 'field_type_of_reward_raffle_priz',
    'label' => 'Type of reward/raffle prize',
    'required' => 1,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'options',
      'settings' => array(
        'apply_chosen' => '',
      ),
      'type' => 'options_select',
      'weight' => 2,
    ),
    'workbench_access_field' => 0,
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('(0 or blank represents no limit)');
  t('Activities from which user can get this reward/raffle ticket');
  t('Age group');
  t('Category');
  t('Dates between which this reward/raffle ticket can be earned');
  t('If no automatic notifications should be sent, leave these fields blank.');
  t('If yes, maximum number of times a user can get this reward');
  t('Message to be sent to reward winner');
  t('Onscreen alert on winning this reward');
  t('Points to get reward or raffle ticket');
  t('Raffle Claim ID');
  t('Raffle Drawing Name');
  t('Raffle Prize or Reward Notifications');
  t('Raffle Ticket Image');
  t('Raffle Ticket Notifications');
  t('Raffle prize description');
  t('Raffle prize or reward image');
  t('Raffle ticket description');
  t('Repeatable');
  t('Roles which can receive this reward or raffle ticket');
  t('Status of reward or raffle');
  t('Type of reward/raffle prize');
  t('receieved_reward');

  return $field_instances;
}

<?php
/**
 * @file
 * video_game_review_content_type.features.field_instance.inc
 */

/**
 * Implements hook_field_default_field_instances().
 */
function video_game_review_content_type_field_default_field_instances() {
  $field_instances = array();

  // Exported field_instance: 'node-video_game_review-body'.
  $field_instances['node-video_game_review-body'] = array(
    'bundle' => 'video_game_review',
    'default_value' => array(
      0 => array(
        'summary' => '',
        'value' => '',
        'format' => 'simple_html',
      ),
    ),
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 0,
      ),
      'teaser' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(
          'trim_length' => 600,
        ),
        'type' => 'text_summary_or_trimmed',
        'weight' => 0,
      ),
    ),
    'display_label' => '',
    'entity_type' => 'node',
    'field_name' => 'body',
    'label' => 'Write Your Review',
    'placeholder' => '',
    'required' => 1,
    'settings' => array(
      'better_formats' => array(
        'allowed_formats' => array(
          'filtered_html' => 'filtered_html',
          'filtered_html_with_tables' => 'filtered_html_with_tables',
          'full_html' => 'full_html',
          'php_code' => 'php_code',
          'plain_text' => 'plain_text',
          'simple_html' => 'simple_html',
        ),
        'allowed_formats_toggle' => 0,
        'default_order_toggle' => 0,
        'default_order_wrapper' => array(
          'formats' => array(
            'filtered_html' => array(
              'weight' => -9,
            ),
            'filtered_html_with_tables' => array(
              'weight' => -7,
            ),
            'full_html' => array(
              'weight' => -6,
            ),
            'php_code' => array(
              'weight' => -4,
            ),
            'plain_text' => array(
              'weight' => -5,
            ),
            'simple_html' => array(
              'weight' => -10,
            ),
          ),
        ),
      ),
      'display_summary' => 1,
      'text_processing' => 1,
      'user_register_form' => FALSE,
    ),
    'use_title_as_placeholder' => 0,
    'widget' => array(
      'active' => 1,
      'module' => 'text',
      'settings' => array(
        'rows' => 20,
        'summary_rows' => 5,
      ),
      'type' => 'text_textarea_with_summary',
      'weight' => 6,
    ),
    'workbench_access_field' => 0,
  );

  // Exported field_instance: 'node-video_game_review-field_age_rating_of_game'.
  $field_instances['node-video_game_review-field_age_rating_of_game'] = array(
    'bundle' => 'video_game_review',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'list',
        'settings' => array(),
        'type' => 'list_default',
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
    'entity_type' => 'node',
    'field_name' => 'field_age_rating_of_game',
    'label' => 'Age Rating Of Game',
    'required' => 0,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'options',
      'settings' => array(),
      'type' => 'options_buttons',
      'weight' => 4,
    ),
    'workbench_access_field' => 0,
  );

  // Exported field_instance:
  // 'node-video_game_review-field_catalog_link_video_game'.
  $field_instances['node-video_game_review-field_catalog_link_video_game'] = array(
    'bundle' => 'video_game_review',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'link',
        'settings' => array(),
        'type' => 'link_default',
        'weight' => 3,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'display_label' => '',
    'entity_type' => 'node',
    'field_name' => 'field_catalog_link_video_game',
    'label' => 'Catalog Link',
    'required' => 0,
    'settings' => array(
      'absolute_url' => 1,
      'attributes' => array(
        'class' => '',
        'configurable_class' => 0,
        'configurable_title' => 0,
        'rel' => '',
        'target' => 'default',
        'title' => '',
      ),
      'display' => array(
        'url_cutoff' => 80,
      ),
      'enable_tokens' => 1,
      'linkit' => array(
        'enable' => 0,
        'insert_plugin' => '',
      ),
      'rel_remove' => 'default',
      'title' => 'none',
      'title_label_use_field_label' => 0,
      'title_maxlength' => 128,
      'title_value' => '',
      'url' => 0,
      'user_register_form' => FALSE,
      'validate_url' => 1,
    ),
    'widget' => array(
      'active' => 0,
      'module' => 'link',
      'settings' => array(),
      'type' => 'link_field',
      'weight' => 5,
    ),
    'workbench_access_field' => 0,
  );

  // Exported field_instance: 'node-video_game_review-field_platform'.
  $field_instances['node-video_game_review-field_platform'] = array(
    'bundle' => 'video_game_review',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'list',
        'settings' => array(),
        'type' => 'list_default',
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
    'entity_type' => 'node',
    'field_name' => 'field_platform',
    'label' => 'Platform',
    'required' => 1,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'options',
      'settings' => array(),
      'type' => 'options_buttons',
      'weight' => 2,
    ),
    'workbench_access_field' => 0,
  );

  // Exported field_instance:
  // 'node-video_game_review-field_platform_other_option'.
  $field_instances['node-video_game_review-field_platform_other_option'] = array(
    'bundle' => 'video_game_review',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
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
    'entity_type' => 'node',
    'field_name' => 'field_platform_other_option',
    'label' => 'Platform other option',
    'placeholder' => 'Please Enter Platform',
    'required' => 0,
    'settings' => array(
      'better_formats' => array(
        'allowed_formats' => array(
          'filtered_html' => 'filtered_html',
          'filtered_html_with_tables' => 'filtered_html_with_tables',
          'full_html' => 'full_html',
          'php_code' => 'php_code',
          'plain_text' => 'plain_text',
          'simple_html' => 'simple_html',
        ),
        'allowed_formats_toggle' => 0,
        'default_order_toggle' => 0,
        'default_order_wrapper' => array(
          'formats' => array(
            'filtered_html' => array(
              'weight' => -9,
            ),
            'filtered_html_with_tables' => array(
              'weight' => -7,
            ),
            'full_html' => array(
              'weight' => -6,
            ),
            'php_code' => array(
              'weight' => -4,
            ),
            'plain_text' => array(
              'weight' => -5,
            ),
            'simple_html' => array(
              'weight' => -10,
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
    'use_title_as_placeholder' => 0,
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

  // Exported field_instance:
  // 'node-video_game_review-field_please_select_videogame'.
  $field_instances['node-video_game_review-field_please_select_videogame'] = array(
    'bundle' => 'video_game_review',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'list',
        'settings' => array(),
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
    'entity_type' => 'node',
    'field_name' => 'field_please_select_videogame',
    'label' => 'Please select one',
    'required' => 0,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'options',
      'settings' => array(),
      'type' => 'options_buttons',
      'weight' => 7,
    ),
    'workbench_access_field' => 0,
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('Age Rating Of Game');
  t('Catalog Link');
  t('Platform');
  t('Platform other option');
  t('Please select one');
  t('Write Your Review');

  return $field_instances;
}

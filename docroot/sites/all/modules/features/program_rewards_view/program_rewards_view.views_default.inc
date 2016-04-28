<?php
/**
 * @file
 * program_rewards_view.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function program_rewards_view_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'program_rewards';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'eck_reward';
  $view->human_name = 'Program rewards';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Program rewards';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'none';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '10';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Field: Reward: Id */
  $handler->display->display_options['fields']['id']['id'] = 'id';
  $handler->display->display_options['fields']['id']['table'] = 'eck_reward';
  $handler->display->display_options['fields']['id']['field'] = 'id';

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Reward: Image upload */
  $handler->display->display_options['fields']['field_image_upload']['id'] = 'field_image_upload';
  $handler->display->display_options['fields']['field_image_upload']['table'] = 'field_data_field_image_upload';
  $handler->display->display_options['fields']['field_image_upload']['field'] = 'field_image_upload';
  $handler->display->display_options['fields']['field_image_upload']['label'] = '';
  $handler->display->display_options['fields']['field_image_upload']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_image_upload']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_image_upload']['settings'] = array(
    'image_style' => '',
    'image_link' => '',
  );
  /* Field: Reward: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'eck_reward';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  /* Field: Reward: Description */
  $handler->display->display_options['fields']['field_physical_description']['id'] = 'field_physical_description';
  $handler->display->display_options['fields']['field_physical_description']['table'] = 'field_data_field_physical_description';
  $handler->display->display_options['fields']['field_physical_description']['field'] = 'field_physical_description';
  $handler->display->display_options['fields']['field_physical_description']['label'] = '';
  $handler->display->display_options['fields']['field_physical_description']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_physical_description']['type'] = 'text_trimmed';
  $handler->display->display_options['fields']['field_physical_description']['settings'] = array(
    'trim_length' => '125',
  );
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Reward: reward type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'eck_reward';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'physical_reward' => 'physical_reward',
  );
  $handler->display->display_options['path'] = 'program-rewards';

  /* Display: Block */
  $handler = $view->new_display('block', 'Block', 'block_1');
  $handler->display->display_options['defaults']['header'] = FALSE;
  /* Header: Global: Text area */
  $handler->display->display_options['header']['area']['id'] = 'area';
  $handler->display->display_options['header']['area']['table'] = 'views';
  $handler->display->display_options['header']['area']['field'] = 'area';
  $handler->display->display_options['header']['area']['content'] = '<h2>Rewards You Can Earn!</h2>
<p>Lorem ipsum dolor sit amet, consectetuer adipiscing elit. Aenean commodo ligula eget dolor. Aenean massa. Cum sociis natoque penatibus </p>';
  $handler->display->display_options['header']['area']['format'] = 'full_html';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Reward: Image upload */
  $handler->display->display_options['fields']['field_image_upload']['id'] = 'field_image_upload';
  $handler->display->display_options['fields']['field_image_upload']['table'] = 'field_data_field_image_upload';
  $handler->display->display_options['fields']['field_image_upload']['field'] = 'field_image_upload';
  $handler->display->display_options['fields']['field_image_upload']['label'] = '';
  $handler->display->display_options['fields']['field_image_upload']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_image_upload']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_image_upload']['settings'] = array(
    'image_style' => '',
    'image_link' => '',
  );
  /* Field: Reward: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'eck_reward';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  /* Field: Reward: Description */
  $handler->display->display_options['fields']['field_physical_description']['id'] = 'field_physical_description';
  $handler->display->display_options['fields']['field_physical_description']['table'] = 'field_data_field_physical_description';
  $handler->display->display_options['fields']['field_physical_description']['field'] = 'field_physical_description';
  $handler->display->display_options['fields']['field_physical_description']['label'] = '';
  $handler->display->display_options['fields']['field_physical_description']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_physical_description']['type'] = 'text_trimmed';
  $handler->display->display_options['fields']['field_physical_description']['settings'] = array(
    'trim_length' => '125',
  );
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Reward: reward type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'eck_reward';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'physical_reward' => 'physical_reward',
  );
  $handler->display->display_options['block_description'] = 'Program rewards block';
  $export['program_rewards'] = $view;

  return $export;
}

<?php
/**
 * @file
 * program_reward_raffle_view.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function program_reward_raffle_view_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'program_rewards_raffle';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'eck_raffle';
  $view->human_name = 'Program rewards raffle';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Program rewards raffle';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'none';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '10';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Field: Raffle: Id */
  $handler->display->display_options['fields']['id']['id'] = 'id';
  $handler->display->display_options['fields']['id']['table'] = 'eck_raffle';
  $handler->display->display_options['fields']['id']['field'] = 'id';

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Raffle: Raffle Image */
  $handler->display->display_options['fields']['field_raffle_image']['id'] = 'field_raffle_image';
  $handler->display->display_options['fields']['field_raffle_image']['table'] = 'field_data_field_raffle_image';
  $handler->display->display_options['fields']['field_raffle_image']['field'] = 'field_raffle_image';
  $handler->display->display_options['fields']['field_raffle_image']['label'] = '';
  $handler->display->display_options['fields']['field_raffle_image']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_raffle_image']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_raffle_image']['settings'] = array(
    'image_style' => '',
    'image_link' => '',
  );
  /* Field: Raffle: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'eck_raffle';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  /* Field: Raffle: Raffle description */
  $handler->display->display_options['fields']['field_raffle_description']['id'] = 'field_raffle_description';
  $handler->display->display_options['fields']['field_raffle_description']['table'] = 'field_data_field_raffle_description';
  $handler->display->display_options['fields']['field_raffle_description']['field'] = 'field_raffle_description';
  $handler->display->display_options['fields']['field_raffle_description']['label'] = '';
  $handler->display->display_options['fields']['field_raffle_description']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_raffle_description']['type'] = 'text_trimmed';
  $handler->display->display_options['fields']['field_raffle_description']['settings'] = array(
    'trim_length' => '125',
  );
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Raffle: raffle type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'eck_raffle';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'raffle' => 'raffle',
  );
  $handler->display->display_options['path'] = 'program-rewards-raffle';

  /* Display: Block */
  $handler = $view->new_display('block', 'Block', 'block_1');
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Raffle: Raffle Image */
  $handler->display->display_options['fields']['field_raffle_image']['id'] = 'field_raffle_image';
  $handler->display->display_options['fields']['field_raffle_image']['table'] = 'field_data_field_raffle_image';
  $handler->display->display_options['fields']['field_raffle_image']['field'] = 'field_raffle_image';
  $handler->display->display_options['fields']['field_raffle_image']['label'] = '';
  $handler->display->display_options['fields']['field_raffle_image']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_raffle_image']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_raffle_image']['settings'] = array(
    'image_style' => '',
    'image_link' => '',
  );
  /* Field: Raffle: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'eck_raffle';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  /* Field: Raffle: Raffle description */
  $handler->display->display_options['fields']['field_raffle_description']['id'] = 'field_raffle_description';
  $handler->display->display_options['fields']['field_raffle_description']['table'] = 'field_data_field_raffle_description';
  $handler->display->display_options['fields']['field_raffle_description']['field'] = 'field_raffle_description';
  $handler->display->display_options['fields']['field_raffle_description']['label'] = '';
  $handler->display->display_options['fields']['field_raffle_description']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_raffle_description']['type'] = 'text_trimmed';
  $handler->display->display_options['fields']['field_raffle_description']['settings'] = array(
    'trim_length' => '125',
  );
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Raffle: raffle type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'eck_raffle';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'raffle' => 'raffle',
  );
  $handler->display->display_options['block_description'] = 'Program rewards raffle block';
  $export['program_rewards_raffle'] = $view;

  return $export;
}

<?php
/**
 * @file
 * program_and_activities_pages.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function program_and_activities_pages_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'program_listing_page';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'program listing page';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'program listing page';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '1';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['quantity'] = '9';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Field: Content: Image */
  $handler->display->display_options['fields']['field_program_image']['id'] = 'field_program_image';
  $handler->display->display_options['fields']['field_program_image']['table'] = 'field_data_field_program_image';
  $handler->display->display_options['fields']['field_program_image']['field'] = 'field_program_image';
  $handler->display->display_options['fields']['field_program_image']['label'] = '';
  $handler->display->display_options['fields']['field_program_image']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_program_image']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_program_image']['settings'] = array(
    'image_style' => 'thumbnail',
    'image_link' => '',
  );
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  /* Field: Content: Body */
  $handler->display->display_options['fields']['body']['id'] = 'body';
  $handler->display->display_options['fields']['body']['table'] = 'field_data_body';
  $handler->display->display_options['fields']['body']['field'] = 'body';
  $handler->display->display_options['fields']['body']['label'] = '';
  $handler->display->display_options['fields']['body']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['body']['type'] = 'text_plain';
  /* Sort criterion: Content: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'program' => 'program',
  );
  /* Filter criterion: Content: Current Programs (field_current_programs) */
  $handler->display->display_options['filters']['field_current_programs_tid']['id'] = 'field_current_programs_tid';
  $handler->display->display_options['filters']['field_current_programs_tid']['table'] = 'field_data_field_current_programs';
  $handler->display->display_options['filters']['field_current_programs_tid']['field'] = 'field_current_programs_tid';
  $handler->display->display_options['filters']['field_current_programs_tid']['value'] = array(
    56 => '56',
  );
  $handler->display->display_options['filters']['field_current_programs_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_current_programs_tid']['vocabulary'] = 'current_program';
  $handler->display->display_options['filters']['field_current_programs_tid']['hierarchy'] = 1;

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '10';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['quantity'] = '9';
  $handler->display->display_options['defaults']['header'] = FALSE;
  /* Header: Global: Text area */
  $handler->display->display_options['header']['area']['id'] = 'area';
  $handler->display->display_options['header']['area']['table'] = 'views';
  $handler->display->display_options['header']['area']['field'] = 'area';
  $handler->display->display_options['header']['area']['content'] = '<h2>Other Programs</h2>';
  $handler->display->display_options['header']['area']['format'] = 'simple_html';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Image */
  $handler->display->display_options['fields']['field_program_image']['id'] = 'field_program_image';
  $handler->display->display_options['fields']['field_program_image']['table'] = 'field_data_field_program_image';
  $handler->display->display_options['fields']['field_program_image']['field'] = 'field_program_image';
  $handler->display->display_options['fields']['field_program_image']['label'] = '';
  $handler->display->display_options['fields']['field_program_image']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_program_image']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_program_image']['settings'] = array(
    'image_style' => 'thumbnail',
    'image_link' => '',
  );
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  /* Field: Content: Body */
  $handler->display->display_options['fields']['body']['id'] = 'body';
  $handler->display->display_options['fields']['body']['table'] = 'field_data_body';
  $handler->display->display_options['fields']['body']['field'] = 'body';
  $handler->display->display_options['fields']['body']['label'] = '';
  $handler->display->display_options['fields']['body']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['body']['type'] = 'text_plain';
  /* Field: Content: Sign Up */
  $handler->display->display_options['fields']['field_sign_up']['id'] = 'field_sign_up';
  $handler->display->display_options['fields']['field_sign_up']['table'] = 'field_data_field_sign_up';
  $handler->display->display_options['fields']['field_sign_up']['field'] = 'field_sign_up';
  $handler->display->display_options['fields']['field_sign_up']['label'] = '';
  $handler->display->display_options['fields']['field_sign_up']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_sign_up']['click_sort_column'] = 'url';
  $handler->display->display_options['path'] = 'program';

  /* Display: Current Program */
  $handler = $view->new_display('block', 'Current Program', 'block_1');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Current Programs';
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '1';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['quantity'] = '9';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Image */
  $handler->display->display_options['fields']['field_program_image']['id'] = 'field_program_image';
  $handler->display->display_options['fields']['field_program_image']['table'] = 'field_data_field_program_image';
  $handler->display->display_options['fields']['field_program_image']['field'] = 'field_program_image';
  $handler->display->display_options['fields']['field_program_image']['label'] = '';
  $handler->display->display_options['fields']['field_program_image']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_program_image']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_program_image']['settings'] = array(
    'image_style' => 'thumbnail',
    'image_link' => '',
  );
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  /* Field: Content: Body */
  $handler->display->display_options['fields']['body']['id'] = 'body';
  $handler->display->display_options['fields']['body']['table'] = 'field_data_body';
  $handler->display->display_options['fields']['body']['field'] = 'body';
  $handler->display->display_options['fields']['body']['label'] = '';
  $handler->display->display_options['fields']['body']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['body']['type'] = 'text_plain';
  /* Field: Content: Sign Up */
  $handler->display->display_options['fields']['field_sign_up']['id'] = 'field_sign_up';
  $handler->display->display_options['fields']['field_sign_up']['table'] = 'field_data_field_sign_up';
  $handler->display->display_options['fields']['field_sign_up']['field'] = 'field_sign_up';
  $handler->display->display_options['fields']['field_sign_up']['label'] = '';
  $handler->display->display_options['fields']['field_sign_up']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_sign_up']['click_sort_column'] = 'url';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'program' => 'program',
  );
  /* Filter criterion: Content: Current Programs (field_current_programs) */
  $handler->display->display_options['filters']['field_current_programs_tid']['id'] = 'field_current_programs_tid';
  $handler->display->display_options['filters']['field_current_programs_tid']['table'] = 'field_data_field_current_programs';
  $handler->display->display_options['filters']['field_current_programs_tid']['field'] = 'field_current_programs_tid';
  $handler->display->display_options['filters']['field_current_programs_tid']['value'] = array(
    55 => '55',
  );
  $handler->display->display_options['filters']['field_current_programs_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_current_programs_tid']['vocabulary'] = 'current_program';
  $handler->display->display_options['filters']['field_current_programs_tid']['hierarchy'] = 1;
  $export['program_listing_page'] = $view;

  return $export;
}

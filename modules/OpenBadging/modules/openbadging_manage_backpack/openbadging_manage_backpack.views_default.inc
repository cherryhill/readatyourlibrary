<?php

/**
 * @file
 * achievement_manage_backpack.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function openbadging_manage_backpack_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'my_groups';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'openbadging';
  $view->human_name = 'my groups';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'my groups';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'none';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '25';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['quantity'] = '9';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* No results behavior: Global: Text area */
  $handler->display->display_options['empty']['area']['id'] = 'area';
  $handler->display->display_options['empty']['area']['table'] = 'views';
  $handler->display->display_options['empty']['area']['field'] = 'area';
  $handler->display->display_options['empty']['area']['empty'] = TRUE;
  $handler->display->display_options['empty']['area']['content'] = 'If you have badges you have been awarded, you can group them here and change their privacy setting.';
  $handler->display->display_options['empty']['area']['format'] = 'filtered_html';
  /* Relationship: Achievement: Author */
  $handler->display->display_options['relationships']['uid']['id'] = 'uid';
  $handler->display->display_options['relationships']['uid']['table'] = 'openbadging';
  $handler->display->display_options['relationships']['uid']['field'] = 'uid';
  /* Field: Achievement: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'openbadging';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  /* Field: Achievement: Assign to this group */
  $handler->display->display_options['fields']['field_badge_entity_reference_1']['id'] = 'field_badge_entity_reference_1';
  $handler->display->display_options['fields']['field_badge_entity_reference_1']['table'] = 'field_data_field_badge_entity_reference_1';
  $handler->display->display_options['fields']['field_badge_entity_reference_1']['field'] = 'field_badge_entity_reference_1';
  $handler->display->display_options['fields']['field_badge_entity_reference_1']['label'] = '';
  $handler->display->display_options['fields']['field_badge_entity_reference_1']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_badge_entity_reference_1']['settings'] = array(
    'link' => 0,
  );
  $handler->display->display_options['fields']['field_badge_entity_reference_1']['delta_offset'] = '0';
  /* Contextual filter: User: Uid */
  $handler->display->display_options['arguments']['uid']['id'] = 'uid';
  $handler->display->display_options['arguments']['uid']['table'] = 'users';
  $handler->display->display_options['arguments']['uid']['field'] = 'uid';
  $handler->display->display_options['arguments']['uid']['relationship'] = 'uid';
  $handler->display->display_options['arguments']['uid']['default_action'] = 'default';
  $handler->display->display_options['arguments']['uid']['default_argument_type'] = 'current_user';
  $handler->display->display_options['arguments']['uid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['uid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['uid']['summary_options']['items_per_page'] = '25';
  /* Contextual filter: Achievement: Keep this group (field_user_group_private) */
  $handler->display->display_options['arguments']['field_user_group_private_value']['id'] = 'field_user_group_private_value';
  $handler->display->display_options['arguments']['field_user_group_private_value']['table'] = 'field_data_field_user_group_private';
  $handler->display->display_options['arguments']['field_user_group_private_value']['field'] = 'field_user_group_private_value';
  $handler->display->display_options['arguments']['field_user_group_private_value']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['field_user_group_private_value']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_user_group_private_value']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_user_group_private_value']['summary_options']['items_per_page'] = '25';
  /* Filter criterion: Achievement: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'openbadging';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'user_groups' => 'user_groups',
  );

  /* Display: Block */
  $handler = $view->new_display('block', 'Block', 'block');
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
  $export['my_groups'] = $view;

  return $export;
}

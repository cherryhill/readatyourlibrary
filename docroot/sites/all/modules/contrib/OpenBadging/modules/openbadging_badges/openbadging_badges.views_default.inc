<?php

/**
 * @file
 * achievement_badges.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function openbadging_badges_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'awarded_users';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'achievement_unlocks';
  $view->human_name = 'Awarded Users';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Awarded Users';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'none';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '4';
  $handler->display->display_options['style_plugin'] = 'grid';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* No results behavior: Global: Text area */
  $handler->display->display_options['empty']['area']['id'] = 'area';
  $handler->display->display_options['empty']['area']['table'] = 'views';
  $handler->display->display_options['empty']['area']['field'] = 'area';
  $handler->display->display_options['empty']['area']['empty'] = TRUE;
  $handler->display->display_options['empty']['area']['content'] = 'No user earned this badge';
  $handler->display->display_options['empty']['area']['format'] = 'filtered_html';
  /* Relationship: Achievement Badges: Achievement User */
  $handler->display->display_options['relationships']['uid']['id'] = 'uid';
  $handler->display->display_options['relationships']['uid']['table'] = 'achievement_unlocks';
  $handler->display->display_options['relationships']['uid']['field'] = 'uid';
  /* Field: User: Name */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'users';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['relationship'] = 'uid';
  $handler->display->display_options['fields']['name']['label'] = '';
  $handler->display->display_options['fields']['name']['element_label_colon'] = FALSE;
  /* Contextual filter: Achievement Badges: Achievement ID */
  $handler->display->display_options['arguments']['achievement_id']['id'] = 'achievement_id';
  $handler->display->display_options['arguments']['achievement_id']['table'] = 'achievement_unlocks';
  $handler->display->display_options['arguments']['achievement_id']['field'] = 'achievement_id';
  $handler->display->display_options['arguments']['achievement_id']['default_action'] = 'default';
  $handler->display->display_options['arguments']['achievement_id']['default_argument_type'] = 'node';
  $handler->display->display_options['arguments']['achievement_id']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['achievement_id']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['achievement_id']['summary_options']['items_per_page'] = '25';

  /* Display: Block */
  $handler = $view->new_display('block', 'Block', 'block');
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
  $export['awarded_users'] = $view;

  $view = new view();
  $view->name = 'earned_badges';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'achievement_unlocks';
  $view->human_name = 'Earned Badges';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Earned Badges';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'none';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '5';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['quantity'] = '9';
  $handler->display->display_options['style_plugin'] = 'grid';
  $handler->display->display_options['style_options']['columns'] = '5';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* No results behavior: Global: Text area */
  $handler->display->display_options['empty']['area']['id'] = 'area';
  $handler->display->display_options['empty']['area']['table'] = 'views';
  $handler->display->display_options['empty']['area']['field'] = 'area';
  $handler->display->display_options['empty']['area']['empty'] = TRUE;
  $handler->display->display_options['empty']['area']['content'] = 'User has no badge to display';
  $handler->display->display_options['empty']['area']['format'] = 'filtered_html';
  /* Relationship: Achievement Badges: Achievement Badge */
  $handler->display->display_options['relationships']['achievement_id']['id'] = 'achievement_id';
  $handler->display->display_options['relationships']['achievement_id']['table'] = 'achievement_unlocks';
  $handler->display->display_options['relationships']['achievement_id']['field'] = 'achievement_id';
  $handler->display->display_options['relationships']['achievement_id']['bundle_types'] = array(
    'badges' => 'badges',
  );
  /* Field: Achievement: URL */
  $handler->display->display_options['fields']['url']['id'] = 'url';
  $handler->display->display_options['fields']['url']['table'] = 'views_entity_openbadging';
  $handler->display->display_options['fields']['url']['field'] = 'url';
  $handler->display->display_options['fields']['url']['relationship'] = 'achievement_id';
  $handler->display->display_options['fields']['url']['label'] = '';
  $handler->display->display_options['fields']['url']['exclude'] = TRUE;
  $handler->display->display_options['fields']['url']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['url']['display_as_link'] = FALSE;
  $handler->display->display_options['fields']['url']['link_to_entity'] = 0;
  /* Field: Achievement: Unlocked image */
  $handler->display->display_options['fields']['field_badge_entity_unlock_image']['id'] = 'field_badge_entity_unlock_image';
  $handler->display->display_options['fields']['field_badge_entity_unlock_image']['table'] = 'field_data_field_badge_entity_unlock_image';
  $handler->display->display_options['fields']['field_badge_entity_unlock_image']['field'] = 'field_badge_entity_unlock_image';
  $handler->display->display_options['fields']['field_badge_entity_unlock_image']['relationship'] = 'achievement_id';
  $handler->display->display_options['fields']['field_badge_entity_unlock_image']['label'] = '';
  $handler->display->display_options['fields']['field_badge_entity_unlock_image']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['field_badge_entity_unlock_image']['alter']['path'] = '[url]';
  $handler->display->display_options['fields']['field_badge_entity_unlock_image']['alter']['absolute'] = TRUE;
  $handler->display->display_options['fields']['field_badge_entity_unlock_image']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_badge_entity_unlock_image']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_badge_entity_unlock_image']['settings'] = array(
    'image_style' => '110_110',
    'image_link' => 'content',
  );
  /* Contextual filter: Achievement Badges: Achievement uid */
  $handler->display->display_options['arguments']['uid']['id'] = 'uid';
  $handler->display->display_options['arguments']['uid']['table'] = 'achievement_unlocks';
  $handler->display->display_options['arguments']['uid']['field'] = 'uid';
  $handler->display->display_options['arguments']['uid']['default_action'] = 'default';
  $handler->display->display_options['arguments']['uid']['default_argument_type'] = 'user';
  $handler->display->display_options['arguments']['uid']['default_argument_options']['user'] = FALSE;
  $handler->display->display_options['arguments']['uid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['uid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['uid']['summary_options']['items_per_page'] = '25';

  /* Display: Block */
  $handler = $view->new_display('block', 'Block', 'block');
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
  $export['earned_badges'] = $view;

  return $export;
}

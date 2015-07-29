<?php
/**
 * @file
 * librarysite_events.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function librarysite_events_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'events';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Events';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Upcoming Library Events';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '10';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['row_options']['hide_empty'] = TRUE;
  $handler->display->display_options['row_options']['default_field_elements'] = FALSE;
  /* Footer: Global: Text area */
  $handler->display->display_options['footer']['area']['id'] = 'area';
  $handler->display->display_options['footer']['area']['table'] = 'views';
  $handler->display->display_options['footer']['area']['field'] = 'area';
  $handler->display->display_options['footer']['area']['content'] = '<ul><li class="rsslink"><a href="/events/feed">Subscribe to RSS  »</a></li></ul>';
  $handler->display->display_options['footer']['area']['format'] = 'full_html';
  /* Field: Content: Main Image */
  $handler->display->display_options['fields']['field_image']['id'] = 'field_image';
  $handler->display->display_options['fields']['field_image']['table'] = 'field_data_field_image';
  $handler->display->display_options['fields']['field_image']['field'] = 'field_image';
  $handler->display->display_options['fields']['field_image']['label'] = '';
  $handler->display->display_options['fields']['field_image']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_image']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_image']['settings'] = array(
    'image_style' => 'thumbnail',
    'image_link' => 'content',
  );
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_type'] = 'h3';
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  /* Field: Content: Date and Time */
  $handler->display->display_options['fields']['field_event_date_and_time']['id'] = 'field_event_date_and_time';
  $handler->display->display_options['fields']['field_event_date_and_time']['table'] = 'field_data_field_event_date_and_time';
  $handler->display->display_options['fields']['field_event_date_and_time']['field'] = 'field_event_date_and_time';
  $handler->display->display_options['fields']['field_event_date_and_time']['label'] = '';
  $handler->display->display_options['fields']['field_event_date_and_time']['element_type'] = 'div';
  $handler->display->display_options['fields']['field_event_date_and_time']['element_class'] = 'datetime';
  $handler->display->display_options['fields']['field_event_date_and_time']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_event_date_and_time']['settings'] = array(
    'format_type' => 'long',
    'fromto' => 'value',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
  );
  /* Field: Content: Description */
  $handler->display->display_options['fields']['field_description']['id'] = 'field_description';
  $handler->display->display_options['fields']['field_description']['table'] = 'field_data_field_description';
  $handler->display->display_options['fields']['field_description']['field'] = 'field_description';
  $handler->display->display_options['fields']['field_description']['label'] = '';
  $handler->display->display_options['fields']['field_description']['alter']['max_length'] = '200';
  $handler->display->display_options['fields']['field_description']['alter']['strip_tags'] = TRUE;
  $handler->display->display_options['fields']['field_description']['alter']['trim'] = TRUE;
  $handler->display->display_options['fields']['field_description']['alter']['preserve_tags'] = '<strong> <em> <a>';
  $handler->display->display_options['fields']['field_description']['alter']['html'] = TRUE;
  $handler->display->display_options['fields']['field_description']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_description']['type'] = 'text_summary_or_trimmed';
  $handler->display->display_options['fields']['field_description']['settings'] = array(
    'trim_length' => '200',
  );
  /* Field: Content: Link */
  $handler->display->display_options['fields']['view_node']['id'] = 'view_node';
  $handler->display->display_options['fields']['view_node']['table'] = 'views_entity_node';
  $handler->display->display_options['fields']['view_node']['field'] = 'view_node';
  $handler->display->display_options['fields']['view_node']['label'] = '';
  $handler->display->display_options['fields']['view_node']['element_type'] = 'div';
  $handler->display->display_options['fields']['view_node']['element_class'] = 'readmore';
  $handler->display->display_options['fields']['view_node']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['view_node']['text'] = 'More information';
  /* Field: Content: Registration */
  $handler->display->display_options['fields']['field_event_registration']['id'] = 'field_event_registration';
  $handler->display->display_options['fields']['field_event_registration']['table'] = 'field_data_field_event_registration';
  $handler->display->display_options['fields']['field_event_registration']['field'] = 'field_event_registration';
  $handler->display->display_options['fields']['field_event_registration']['label'] = '';
  $handler->display->display_options['fields']['field_event_registration']['element_type'] = 'div';
  $handler->display->display_options['fields']['field_event_registration']['element_class'] = 'registrationlink';
  $handler->display->display_options['fields']['field_event_registration']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_event_registration']['click_sort_column'] = 'url';
  /* Sort criterion: Content: Date and Time -  start date (field_event_date_and_time) */
  $handler->display->display_options['sorts']['field_event_date_and_time_value']['id'] = 'field_event_date_and_time_value';
  $handler->display->display_options['sorts']['field_event_date_and_time_value']['table'] = 'field_data_field_event_date_and_time';
  $handler->display->display_options['sorts']['field_event_date_and_time_value']['field'] = 'field_event_date_and_time_value';
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
    'event' => 'event',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;
  /* Filter criterion: Content: Date and Time -  start date (field_event_date_and_time) */
  $handler->display->display_options['filters']['field_event_date_and_time_value']['id'] = 'field_event_date_and_time_value';
  $handler->display->display_options['filters']['field_event_date_and_time_value']['table'] = 'field_data_field_event_date_and_time';
  $handler->display->display_options['filters']['field_event_date_and_time_value']['field'] = 'field_event_date_and_time_value';
  $handler->display->display_options['filters']['field_event_date_and_time_value']['operator'] = '>=';
  $handler->display->display_options['filters']['field_event_date_and_time_value']['expose']['operator_id'] = 'field_event_date_and_time_value_op';
  $handler->display->display_options['filters']['field_event_date_and_time_value']['expose']['label'] = 'Date and Time -  start date (field_event_date_and_time)';
  $handler->display->display_options['filters']['field_event_date_and_time_value']['expose']['operator'] = 'field_event_date_and_time_value_op';
  $handler->display->display_options['filters']['field_event_date_and_time_value']['expose']['identifier'] = 'field_event_date_and_time_value';
  $handler->display->display_options['filters']['field_event_date_and_time_value']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    4 => 0,
    3 => 0,
  );
  $handler->display->display_options['filters']['field_event_date_and_time_value']['default_date'] = 'now';

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
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
    'event' => 'event',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;
  /* Filter criterion: Content: Date and Time -  start date (field_event_date_and_time) */
  $handler->display->display_options['filters']['field_event_date_and_time_value']['id'] = 'field_event_date_and_time_value';
  $handler->display->display_options['filters']['field_event_date_and_time_value']['table'] = 'field_data_field_event_date_and_time';
  $handler->display->display_options['filters']['field_event_date_and_time_value']['field'] = 'field_event_date_and_time_value';
  $handler->display->display_options['filters']['field_event_date_and_time_value']['operator'] = '>=';
  $handler->display->display_options['filters']['field_event_date_and_time_value']['expose']['operator_id'] = 'field_event_date_and_time_value_op';
  $handler->display->display_options['filters']['field_event_date_and_time_value']['expose']['label'] = 'Date and Time -  start date (field_event_date_and_time)';
  $handler->display->display_options['filters']['field_event_date_and_time_value']['expose']['operator'] = 'field_event_date_and_time_value_op';
  $handler->display->display_options['filters']['field_event_date_and_time_value']['expose']['identifier'] = 'field_event_date_and_time_value';
  $handler->display->display_options['filters']['field_event_date_and_time_value']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    4 => 0,
    3 => 0,
  );
  $handler->display->display_options['filters']['field_event_date_and_time_value']['default_date'] = 'now';
  /* Filter criterion: Content: Audience (field_audience_term) */
  $handler->display->display_options['filters']['field_audience_term_tid']['id'] = 'field_audience_term_tid';
  $handler->display->display_options['filters']['field_audience_term_tid']['table'] = 'field_data_field_audience_term';
  $handler->display->display_options['filters']['field_audience_term_tid']['field'] = 'field_audience_term_tid';
  $handler->display->display_options['filters']['field_audience_term_tid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_audience_term_tid']['expose']['operator_id'] = 'field_audience_term_tid_op';
  $handler->display->display_options['filters']['field_audience_term_tid']['expose']['label'] = 'Audience';
  $handler->display->display_options['filters']['field_audience_term_tid']['expose']['operator'] = 'field_audience_term_tid_op';
  $handler->display->display_options['filters']['field_audience_term_tid']['expose']['identifier'] = 'field_audience_term_tid';
  $handler->display->display_options['filters']['field_audience_term_tid']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    4 => 0,
    3 => 0,
  );
  $handler->display->display_options['filters']['field_audience_term_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_audience_term_tid']['vocabulary'] = 'audience';
  $handler->display->display_options['path'] = 'events';
  $handler->display->display_options['menu']['type'] = 'normal';
  $handler->display->display_options['menu']['title'] = 'Library Events';
  $handler->display->display_options['menu']['name'] = 'main-menu';

  /* Display: Feed */
  $handler = $view->new_display('feed', 'Feed', 'feed');
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['style_plugin'] = 'rss';
  $handler->display->display_options['row_plugin'] = 'node_rss';
  $handler->display->display_options['path'] = 'events/feed';
  $handler->display->display_options['displays'] = array(
    'default' => 'default',
    'page' => 'page',
  );

  /* Display: Home */
  $handler = $view->new_display('block', 'Home', 'block');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Upcoming Events';
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '4';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['footer'] = FALSE;
  /* Footer: Global: Text area */
  $handler->display->display_options['footer']['area']['id'] = 'area';
  $handler->display->display_options['footer']['area']['table'] = 'views';
  $handler->display->display_options['footer']['area']['field'] = 'area';
  $handler->display->display_options['footer']['area']['content'] = '<ul><li class="rsslink"><a href="/events/feed">Subscribe to RSS »</a></li>
<li class="calendarlink"><a href="/events">All Library Events »</a></li></ul>';
  $handler->display->display_options['footer']['area']['format'] = 'full_html';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  /* Field: Content: Date and Time */
  $handler->display->display_options['fields']['field_event_date_and_time']['id'] = 'field_event_date_and_time';
  $handler->display->display_options['fields']['field_event_date_and_time']['table'] = 'field_data_field_event_date_and_time';
  $handler->display->display_options['fields']['field_event_date_and_time']['field'] = 'field_event_date_and_time';
  $handler->display->display_options['fields']['field_event_date_and_time']['label'] = '';
  $handler->display->display_options['fields']['field_event_date_and_time']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_event_date_and_time']['settings'] = array(
    'format_type' => 'long',
    'fromto' => 'value',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
  );
  $handler->display->display_options['block_description'] = 'Home Upcoming Events Callout';

  /* Display: Kids */
  $handler = $view->new_display('block', 'Kids', 'block_events_kids');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Upcoming Kids Events';
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '4';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['footer'] = FALSE;
  /* Footer: Global: Text area */
  $handler->display->display_options['footer']['area']['id'] = 'area';
  $handler->display->display_options['footer']['area']['table'] = 'views';
  $handler->display->display_options['footer']['area']['field'] = 'area';
  $handler->display->display_options['footer']['area']['content'] = '<ul><li class="rsslink"><a href="/events/feed">Subscribe to RSS »</a></li>
<li class="calendarlink"><a href="/events">All Library Events »</a></li></ul>';
  $handler->display->display_options['footer']['area']['format'] = 'full_html';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  /* Field: Content: Date and Time */
  $handler->display->display_options['fields']['field_event_date_and_time']['id'] = 'field_event_date_and_time';
  $handler->display->display_options['fields']['field_event_date_and_time']['table'] = 'field_data_field_event_date_and_time';
  $handler->display->display_options['fields']['field_event_date_and_time']['field'] = 'field_event_date_and_time';
  $handler->display->display_options['fields']['field_event_date_and_time']['label'] = '';
  $handler->display->display_options['fields']['field_event_date_and_time']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_event_date_and_time']['settings'] = array(
    'format_type' => 'long',
    'fromto' => 'value',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
  );
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
    'event' => 'event',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;
  /* Filter criterion: Content: Date and Time -  start date (field_event_date_and_time) */
  $handler->display->display_options['filters']['field_event_date_and_time_value']['id'] = 'field_event_date_and_time_value';
  $handler->display->display_options['filters']['field_event_date_and_time_value']['table'] = 'field_data_field_event_date_and_time';
  $handler->display->display_options['filters']['field_event_date_and_time_value']['field'] = 'field_event_date_and_time_value';
  $handler->display->display_options['filters']['field_event_date_and_time_value']['operator'] = '>=';
  $handler->display->display_options['filters']['field_event_date_and_time_value']['expose']['operator_id'] = 'field_event_date_and_time_value_op';
  $handler->display->display_options['filters']['field_event_date_and_time_value']['expose']['label'] = 'Date and Time -  start date (field_event_date_and_time)';
  $handler->display->display_options['filters']['field_event_date_and_time_value']['expose']['operator'] = 'field_event_date_and_time_value_op';
  $handler->display->display_options['filters']['field_event_date_and_time_value']['expose']['identifier'] = 'field_event_date_and_time_value';
  $handler->display->display_options['filters']['field_event_date_and_time_value']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    4 => 0,
    3 => 0,
  );
  $handler->display->display_options['filters']['field_event_date_and_time_value']['default_date'] = 'now';
  /* Filter criterion: Content: Audience (field_audience_term) */
  $handler->display->display_options['filters']['field_audience_term_tid']['id'] = 'field_audience_term_tid';
  $handler->display->display_options['filters']['field_audience_term_tid']['table'] = 'field_data_field_audience_term';
  $handler->display->display_options['filters']['field_audience_term_tid']['field'] = 'field_audience_term_tid';
  $handler->display->display_options['filters']['field_audience_term_tid']['value'] = array(
    4 => '4',
  );
  $handler->display->display_options['filters']['field_audience_term_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_audience_term_tid']['vocabulary'] = 'audience';
  $handler->display->display_options['block_description'] = 'Kids Upcoming Events Callout';

  /* Display: Teens */
  $handler = $view->new_display('block', 'Teens', 'block_events_teens');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Upcoming Teens Events';
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '4';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['footer'] = FALSE;
  /* Footer: Global: Text area */
  $handler->display->display_options['footer']['area']['id'] = 'area';
  $handler->display->display_options['footer']['area']['table'] = 'views';
  $handler->display->display_options['footer']['area']['field'] = 'area';
  $handler->display->display_options['footer']['area']['content'] = '<ul><li class="rsslink"><a href="/events/feed">Subscribe to RSS »</a></li>
<li class="calendarlink"><a href="/events">All Library Events »</a></li></ul>';
  $handler->display->display_options['footer']['area']['format'] = 'full_html';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  /* Field: Content: Date and Time */
  $handler->display->display_options['fields']['field_event_date_and_time']['id'] = 'field_event_date_and_time';
  $handler->display->display_options['fields']['field_event_date_and_time']['table'] = 'field_data_field_event_date_and_time';
  $handler->display->display_options['fields']['field_event_date_and_time']['field'] = 'field_event_date_and_time';
  $handler->display->display_options['fields']['field_event_date_and_time']['label'] = '';
  $handler->display->display_options['fields']['field_event_date_and_time']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_event_date_and_time']['settings'] = array(
    'format_type' => 'long',
    'fromto' => 'value',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
  );
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
    'event' => 'event',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;
  /* Filter criterion: Content: Date and Time -  start date (field_event_date_and_time) */
  $handler->display->display_options['filters']['field_event_date_and_time_value']['id'] = 'field_event_date_and_time_value';
  $handler->display->display_options['filters']['field_event_date_and_time_value']['table'] = 'field_data_field_event_date_and_time';
  $handler->display->display_options['filters']['field_event_date_and_time_value']['field'] = 'field_event_date_and_time_value';
  $handler->display->display_options['filters']['field_event_date_and_time_value']['operator'] = '>=';
  $handler->display->display_options['filters']['field_event_date_and_time_value']['expose']['operator_id'] = 'field_event_date_and_time_value_op';
  $handler->display->display_options['filters']['field_event_date_and_time_value']['expose']['label'] = 'Date and Time -  start date (field_event_date_and_time)';
  $handler->display->display_options['filters']['field_event_date_and_time_value']['expose']['operator'] = 'field_event_date_and_time_value_op';
  $handler->display->display_options['filters']['field_event_date_and_time_value']['expose']['identifier'] = 'field_event_date_and_time_value';
  $handler->display->display_options['filters']['field_event_date_and_time_value']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    4 => 0,
    3 => 0,
  );
  $handler->display->display_options['filters']['field_event_date_and_time_value']['default_date'] = 'now';
  /* Filter criterion: Content: Audience (field_audience_term) */
  $handler->display->display_options['filters']['field_audience_term_tid']['id'] = 'field_audience_term_tid';
  $handler->display->display_options['filters']['field_audience_term_tid']['table'] = 'field_data_field_audience_term';
  $handler->display->display_options['filters']['field_audience_term_tid']['field'] = 'field_audience_term_tid';
  $handler->display->display_options['filters']['field_audience_term_tid']['value'] = array(
    5 => '5',
  );
  $handler->display->display_options['filters']['field_audience_term_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_audience_term_tid']['vocabulary'] = 'audience';
  $handler->display->display_options['block_description'] = 'Teens Upcoming Events Callout';

  /* Display: Event Address */
  $handler = $view->new_display('panel_pane', 'Event Address', 'address_pane');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['footer'] = FALSE;
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  /* Relationship: Entity Reference: Referenced Entity */
  $handler->display->display_options['relationships']['field_event_branch_ref_target_id']['id'] = 'field_event_branch_ref_target_id';
  $handler->display->display_options['relationships']['field_event_branch_ref_target_id']['table'] = 'field_data_field_event_branch_ref';
  $handler->display->display_options['relationships']['field_event_branch_ref_target_id']['field'] = 'field_event_branch_ref_target_id';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['relationship'] = 'field_event_branch_ref_target_id';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['exclude'] = TRUE;
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  /* Field: Content: Branch Address */
  $handler->display->display_options['fields']['field_branch_address']['id'] = 'field_branch_address';
  $handler->display->display_options['fields']['field_branch_address']['table'] = 'field_data_field_branch_address';
  $handler->display->display_options['fields']['field_branch_address']['field'] = 'field_branch_address';
  $handler->display->display_options['fields']['field_branch_address']['relationship'] = 'field_event_branch_ref_target_id';
  $handler->display->display_options['fields']['field_branch_address']['label'] = '';
  $handler->display->display_options['fields']['field_branch_address']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_branch_address']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_branch_address']['click_sort_column'] = 'country';
  $handler->display->display_options['fields']['field_branch_address']['settings'] = array(
    'use_widget_handlers' => 1,
    'format_handlers' => array(
      'address' => 'address',
    ),
  );
  /* Field: Content: Location */
  $handler->display->display_options['fields']['field_event_location']['id'] = 'field_event_location';
  $handler->display->display_options['fields']['field_event_location']['table'] = 'field_data_field_event_location';
  $handler->display->display_options['fields']['field_event_location']['field'] = 'field_event_location';
  $handler->display->display_options['fields']['field_event_location']['label'] = '';
  $handler->display->display_options['fields']['field_event_location']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_event_location']['empty'] = '[title]
[field_branch_address]';
  $handler->display->display_options['fields']['field_event_location']['click_sort_column'] = 'country';
  $handler->display->display_options['fields']['field_event_location']['settings'] = array(
    'use_widget_handlers' => 1,
    'format_handlers' => array(
      'address' => 'address',
    ),
  );
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Content: Nid */
  $handler->display->display_options['arguments']['nid']['id'] = 'nid';
  $handler->display->display_options['arguments']['nid']['table'] = 'node';
  $handler->display->display_options['arguments']['nid']['field'] = 'nid';
  $handler->display->display_options['arguments']['nid']['default_action'] = 'default';
  $handler->display->display_options['arguments']['nid']['default_argument_type'] = 'node';
  $handler->display->display_options['arguments']['nid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['nid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['nid']['summary_options']['items_per_page'] = '25';
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
    'event' => 'event',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;
  $handler->display->display_options['argument_input'] = array(
    'nid' => array(
      'type' => 'context',
      'context' => 'entity:node.nid',
      'context_optional' => 0,
      'panel' => '0',
      'fixed' => '',
      'label' => 'Content: Nid',
    ),
  );

  /* Display: Event Map */
  $handler = $view->new_display('block', 'Event Map', 'map_block');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Map to Event';
  $handler->display->display_options['defaults']['footer'] = FALSE;
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  /* Relationship: Entity Reference: Referenced Entity */
  $handler->display->display_options['relationships']['field_event_branch_ref_target_id']['id'] = 'field_event_branch_ref_target_id';
  $handler->display->display_options['relationships']['field_event_branch_ref_target_id']['table'] = 'field_data_field_event_branch_ref';
  $handler->display->display_options['relationships']['field_event_branch_ref_target_id']['field'] = 'field_event_branch_ref_target_id';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Branch Address */
  $handler->display->display_options['fields']['field_branch_address']['id'] = 'field_branch_address';
  $handler->display->display_options['fields']['field_branch_address']['table'] = 'field_data_field_branch_address';
  $handler->display->display_options['fields']['field_branch_address']['field'] = 'field_branch_address';
  $handler->display->display_options['fields']['field_branch_address']['relationship'] = 'field_event_branch_ref_target_id';
  $handler->display->display_options['fields']['field_branch_address']['label'] = '';
  $handler->display->display_options['fields']['field_branch_address']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_branch_address']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_branch_address']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['field_branch_address']['empty_zero'] = TRUE;
  $handler->display->display_options['fields']['field_branch_address']['click_sort_column'] = 'country';
  $handler->display->display_options['fields']['field_branch_address']['type'] = 'addressfield_staticmap';
  $handler->display->display_options['fields']['field_branch_address']['settings'] = array(
    'zoom_level' => '13',
    'map_size' => '189x189',
    'info_window' => 0,
    'text_address' => 0,
    'map_style' => 'roadmap',
    'advanced_settings_index' => '0',
  );
  /* Field: Content: Location */
  $handler->display->display_options['fields']['field_event_location']['id'] = 'field_event_location';
  $handler->display->display_options['fields']['field_event_location']['table'] = 'field_data_field_event_location';
  $handler->display->display_options['fields']['field_event_location']['field'] = 'field_event_location';
  $handler->display->display_options['fields']['field_event_location']['label'] = '';
  $handler->display->display_options['fields']['field_event_location']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_event_location']['empty'] = '[field_branch_address]';
  $handler->display->display_options['fields']['field_event_location']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['field_event_location']['empty_zero'] = TRUE;
  $handler->display->display_options['fields']['field_event_location']['click_sort_column'] = 'country';
  $handler->display->display_options['fields']['field_event_location']['type'] = 'addressfield_staticmap';
  $handler->display->display_options['fields']['field_event_location']['settings'] = array(
    'zoom_level' => '13',
    'map_size' => '189x189',
    'info_window' => 0,
    'text_address' => 0,
    'map_style' => 'roadmap',
    'advanced_settings_index' => '0',
  );
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Content: Nid */
  $handler->display->display_options['arguments']['nid']['id'] = 'nid';
  $handler->display->display_options['arguments']['nid']['table'] = 'node';
  $handler->display->display_options['arguments']['nid']['field'] = 'nid';
  $handler->display->display_options['arguments']['nid']['default_action'] = 'default';
  $handler->display->display_options['arguments']['nid']['default_argument_type'] = 'node';
  $handler->display->display_options['arguments']['nid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['nid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['nid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['nid']['validate']['type'] = 'node';
  $handler->display->display_options['arguments']['nid']['validate_options']['types'] = array(
    'event' => 'event',
  );
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
    'event' => 'event',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;
  $export['events'] = $view;

  return $export;
}

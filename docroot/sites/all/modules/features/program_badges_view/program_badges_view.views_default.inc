<?php
/**
 * @file
 * program_badges_view.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function program_badges_view_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'program_badges';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'eck_badge';
  $view->human_name = 'Program badges';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Program badges';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'none';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '5';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Field: Badge: Id */
  $handler->display->display_options['fields']['id']['id'] = 'id';
  $handler->display->display_options['fields']['id']['table'] = 'eck_badge';
  $handler->display->display_options['fields']['id']['field'] = 'id';

  /* Display: Block */
  $handler = $view->new_display('block', 'Block', 'block');
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['header'] = FALSE;
  /* Header: Global: Text area */
  $handler->display->display_options['header']['area']['id'] = 'area';
  $handler->display->display_options['header']['area']['table'] = 'views';
  $handler->display->display_options['header']['area']['field'] = 'area';
  $handler->display->display_options['header']['area']['content'] = '<h2>Badges You Can Earn!</h2>
<p>Lorem ipsum dolor sit amet, consectetuer adipiscing elit. Aenean commodo ligula eget dolor. Aenean massa. Cum sociis natoque penatibus</p>';
  $handler->display->display_options['header']['area']['format'] = 'full_html';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Badge: Badge Image */
  $handler->display->display_options['fields']['field_badge_image']['id'] = 'field_badge_image';
  $handler->display->display_options['fields']['field_badge_image']['table'] = 'field_data_field_badge_image';
  $handler->display->display_options['fields']['field_badge_image']['field'] = 'field_badge_image';
  $handler->display->display_options['fields']['field_badge_image']['label'] = '';
  $handler->display->display_options['fields']['field_badge_image']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_badge_image']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_badge_image']['settings'] = array(
    'image_style' => '',
    'image_link' => '',
  );
  /* Field: Badge: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'eck_badge';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  /* Field: Badge: Badge Description */
  $handler->display->display_options['fields']['field_badge_description']['id'] = 'field_badge_description';
  $handler->display->display_options['fields']['field_badge_description']['table'] = 'field_data_field_badge_description';
  $handler->display->display_options['fields']['field_badge_description']['field'] = 'field_badge_description';
  $handler->display->display_options['fields']['field_badge_description']['label'] = '';
  $handler->display->display_options['fields']['field_badge_description']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_badge_description']['type'] = 'text_trimmed';
  $handler->display->display_options['fields']['field_badge_description']['settings'] = array(
    'trim_length' => '125',
  );
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Badge: badge type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'eck_badge';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'badge' => 'badge',
  );
  $handler->display->display_options['block_description'] = 'Program badges block';
  $export['program_badges'] = $view;

  return $export;
}

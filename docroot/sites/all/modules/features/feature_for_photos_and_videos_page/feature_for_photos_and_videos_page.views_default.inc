<?php
/**
 * @file
 * feature_for_photos_and_videos_page.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function feature_for_photos_and_videos_page_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'media';
  $view->description = 'Photos and videos';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Media';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Media';
  $handler->display->display_options['css_class'] = 'photos-block';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '6';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
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
    '_flickr_images' => '_flickr_images',
  );

  /* Display: Photo block for photo video page */
  $handler = $view->new_display('block', 'Photo block for photo video page', 'block');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Photos & Videos';
  $handler->display->display_options['defaults']['css_class'] = FALSE;
  $handler->display->display_options['css_class'] = 'photos-block';
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '6';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['quantity'] = '9';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Flickr Album */
  $handler->display->display_options['fields']['field_flicker_images']['id'] = 'field_flicker_images';
  $handler->display->display_options['fields']['field_flicker_images']['table'] = 'field_data_field_flicker_images';
  $handler->display->display_options['fields']['field_flicker_images']['field'] = 'field_flicker_images';
  $handler->display->display_options['fields']['field_flicker_images']['label'] = '';
  $handler->display->display_options['fields']['field_flicker_images']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_flicker_images']['type'] = 'photoset_primaryphoto_sizeb_linkflickrcomset';
  $handler->display->display_options['fields']['field_flicker_images']['group_rows'] = FALSE;
  $handler->display->display_options['fields']['field_flicker_images']['delta_offset'] = '0';
  $handler->display->display_options['block_description'] = 'photo block for photo video page';

  /* Display: Video block for photo video page */
  $handler = $view->new_display('block', 'Video block for photo video page', 'block_1');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Photos & Videos';
  $handler->display->display_options['defaults']['css_class'] = FALSE;
  $handler->display->display_options['css_class'] = 'video-block';
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '8';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['quantity'] = '9';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['exclude'] = TRUE;
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  /* Field: Content: video link */
  $handler->display->display_options['fields']['field_video_link']['id'] = 'field_video_link';
  $handler->display->display_options['fields']['field_video_link']['table'] = 'field_data_field_video_link';
  $handler->display->display_options['fields']['field_video_link']['field'] = 'field_video_link';
  $handler->display->display_options['fields']['field_video_link']['label'] = '';
  $handler->display->display_options['fields']['field_video_link']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_video_link']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_video_link']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_video_link']['type'] = 'media';
  $handler->display->display_options['fields']['field_video_link']['settings'] = array(
    'file_view_mode' => 'default',
  );
  $handler->display->display_options['fields']['field_video_link']['delta_offset'] = '0';
  /* Field: Content: Body */
  $handler->display->display_options['fields']['body']['id'] = 'body';
  $handler->display->display_options['fields']['body']['table'] = 'field_data_body';
  $handler->display->display_options['fields']['body']['field'] = 'body';
  $handler->display->display_options['fields']['body']['label'] = '';
  $handler->display->display_options['fields']['body']['exclude'] = TRUE;
  $handler->display->display_options['fields']['body']['element_label_colon'] = FALSE;
  /* Field: Content: Video description */
  $handler->display->display_options['fields']['field_video_description']['id'] = 'field_video_description';
  $handler->display->display_options['fields']['field_video_description']['table'] = 'field_data_field_video_description';
  $handler->display->display_options['fields']['field_video_description']['field'] = 'field_video_description';
  $handler->display->display_options['fields']['field_video_description']['label'] = '';
  $handler->display->display_options['fields']['field_video_description']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_video_description']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_video_description']['type'] = 'text_trimmed';
  $handler->display->display_options['fields']['field_video_description']['settings'] = array(
    'trim_length' => '150',
  );
  /* Field: Global: Custom text */
  $handler->display->display_options['fields']['nothing']['id'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['table'] = 'views';
  $handler->display->display_options['fields']['nothing']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['label'] = '';
  $handler->display->display_options['fields']['nothing']['alter']['text'] = '<div class = "vedio-wrapper">[field_video_link]</div>
<div class="description"><div>[body]</div><div>[field_video_description]</div></div>';
  $handler->display->display_options['fields']['nothing']['element_label_colon'] = FALSE;
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = '1';
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'videos' => 'videos',
  );
  $handler->display->display_options['block_description'] = 'Video block for photo video page';
  $export['media'] = $view;

  return $export;
}

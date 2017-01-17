<?php
/**
 * @file
 * feature_for_activity_page.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function feature_for_activity_page_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'views_for_all_pages';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'eck_activity';
  $view->human_name = 'Views for activity page';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Views for all pages';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'none';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '1';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Field: Activity: Id */
  $handler->display->display_options['fields']['id']['id'] = 'id';
  $handler->display->display_options['fields']['id']['table'] = 'eck_activity';
  $handler->display->display_options['fields']['id']['field'] = 'id';
  /* Filter criterion: Activity: activity type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'eck_activity';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'activity' => 'activity',
  );

  /* Display: Activities */
  $handler = $view->new_display('page', 'Activities', 'page');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Activities';
  $handler->display->display_options['defaults']['header'] = FALSE;
  /* Header: Global: Text area */
  $handler->display->display_options['header']['area']['id'] = 'area';
  $handler->display->display_options['header']['area']['table'] = 'views';
  $handler->display->display_options['header']['area']['field'] = 'area';
  $handler->display->display_options['header']['area']['content'] = '<div>
<h2>Activities for Kids Summer Reading</h2>
 <p>Here are the activites you can do in Play @ Your Library. Also check out <a href="events">events</a> for all sorts of programs happening at your library!</p>
</div>';
  $handler->display->display_options['header']['area']['format'] = 'full_html';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Activity: Id */
  $handler->display->display_options['fields']['id']['id'] = 'id';
  $handler->display->display_options['fields']['id']['table'] = 'eck_activity';
  $handler->display->display_options['fields']['id']['field'] = 'id';
  $handler->display->display_options['fields']['id']['exclude'] = TRUE;
  /* Field: Global: Custom text */
  $handler->display->display_options['fields']['nothing']['id'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['table'] = 'views';
  $handler->display->display_options['fields']['nothing']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['label'] = '';
  $handler->display->display_options['fields']['nothing']['alter']['text'] = '<h2> Reading </h2>
<p>Read anything, anywhere, anytime; or listen as someone reads to you.  Put one sticker on your progress page every day you read or are read to.  It doesn\'t matter how long you read each day, but we suggest 15 minutes or more. </p> 
<p>You can read whatever you want. Read for fun! It\'s all good. </p> 
<p>Parents, read to your child, baby, or toddler.  Just sign them up!  Let your baby play with a book, read the same book over and over,  skip over words and pages. Have fun. These are all good reading activities for babies and young children! </p> 
<div><a href = "progress" class = "button">Add Days of Reading</a></div>';
  $handler->display->display_options['fields']['nothing']['element_label_colon'] = FALSE;
  $handler->display->display_options['path'] = 'activities';
  $export['views_for_all_pages'] = $view;

  return $export;
}

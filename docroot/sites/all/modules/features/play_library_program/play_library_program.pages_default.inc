<?php
/**
 * @file
 * play_library_program.pages_default.inc
 */

/**
 * Implements hook_default_page_manager_pages().
 */
function play_library_program_default_page_manager_pages() {
  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'admin_dashboard';
  $page->task = 'page';
  $page->admin_title = 'Admin Dashboard';
  $page->admin_description = '';
  $page->path = 'admin/content/dashboard';
  $page->access = array(
    'plugins' => array(
      0 => array(
        'name' => 'perm',
        'settings' => array(
          'perm' => 'administer nodes',
        ),
        'context' => 'logged-in-user',
        'not' => FALSE,
      ),
    ),
    'logic' => 'and',
  );
  $page->menu = array(
    'type' => 'tab',
    'title' => 'Program Dashboard',
    'name' => 'navigation',
    'weight' => '0',
    'parent' => array(
      'type' => 'none',
      'title' => '',
      'name' => 'navigation',
      'weight' => '0',
    ),
  );
  $page->arguments = array();
  $page->conf = array(
    'admin_paths' => FALSE,
  );
  $page->default_handlers = array();
  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'page_admin_dashboard__panel';
  $handler->task = 'page';
  $handler->subtask = 'admin_dashboard';
  $handler->handler = 'panel_context';
  $handler->weight = 0;
  $handler->conf = array(
    'title' => 'Panel',
    'no_blocks' => 0,
    'pipeline' => 'standard',
    'body_classes_to_remove' => '',
    'body_classes_to_add' => '',
    'css_id' => '',
    'css' => '',
    'contexts' => array(),
    'relationships' => array(),
    'name' => 'panel',
  );
  $display = new panels_display();
  $display->layout = 'twocol_bricks';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'top' => NULL,
      'left_above' => NULL,
      'right_above' => NULL,
      'middle' => NULL,
      'left_below' => NULL,
      'right_below' => NULL,
      'bottom' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = '';
  $display->uuid = 'f8f9231d-9298-4100-99fa-c14c7d434a6a';
  $display->storage_type = 'page_manager';
  $display->storage_id = 'page_admin_dashboard__panel';
  $display->content = array();
  $display->panels = array();
  $pane = new stdClass();
  $pane->pid = 'new-a3e2754c-f682-4f1c-8bb2-be883bc45cb1';
  $pane->panel = 'middle';
  $pane->type = 'views_panes';
  $pane->subtype = 'activity_dashboard-panel_pane_1';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array();
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 0;
  $pane->locks = array();
  $pane->uuid = 'a3e2754c-f682-4f1c-8bb2-be883bc45cb1';
  $display->content['new-a3e2754c-f682-4f1c-8bb2-be883bc45cb1'] = $pane;
  $display->panels['middle'][0] = 'new-a3e2754c-f682-4f1c-8bb2-be883bc45cb1';
  $pane = new stdClass();
  $pane->pid = 'new-2140e4ba-1829-4482-81b6-347f38cb0eb2';
  $pane->panel = 'middle';
  $pane->type = 'views_panes';
  $pane->subtype = 'reward_dashboard-panel_pane_1';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array();
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 1;
  $pane->locks = array();
  $pane->uuid = '2140e4ba-1829-4482-81b6-347f38cb0eb2';
  $display->content['new-2140e4ba-1829-4482-81b6-347f38cb0eb2'] = $pane;
  $display->panels['middle'][1] = 'new-2140e4ba-1829-4482-81b6-347f38cb0eb2';
  $pane = new stdClass();
  $pane->pid = 'new-dc78b710-2d34-40cf-b083-15ea6f62acb3';
  $pane->panel = 'middle';
  $pane->type = 'views';
  $pane->subtype = 'reviews';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'override_pager_settings' => 0,
    'use_pager' => 0,
    'nodes_per_page' => '20',
    'pager_id' => '0',
    'offset' => '0',
    'more_link' => 0,
    'feed_icons' => 0,
    'panel_args' => 0,
    'link_to_view' => 0,
    'args' => '',
    'url' => '',
    'display' => 'block',
    'override_title' => 0,
    'override_title_text' => '',
    'override_title_heading' => 'h2',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 2;
  $pane->locks = array();
  $pane->uuid = 'dc78b710-2d34-40cf-b083-15ea6f62acb3';
  $display->content['new-dc78b710-2d34-40cf-b083-15ea6f62acb3'] = $pane;
  $display->panels['middle'][2] = 'new-dc78b710-2d34-40cf-b083-15ea6f62acb3';
  $pane = new stdClass();
  $pane->pid = 'new-7e5f67e9-70fe-4ff0-9cab-51a7b7a4cfa7';
  $pane->panel = 'top';
  $pane->type = 'block';
  $pane->subtype = 'system-navigation';
  $pane->shown = TRUE;
  $pane->access = array(
    'plugins' => array(),
  );
  $pane->configuration = array(
    'override_title' => 0,
    'override_title_text' => '',
    'override_title_heading' => 'h2',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 0;
  $pane->locks = array();
  $pane->uuid = '7e5f67e9-70fe-4ff0-9cab-51a7b7a4cfa7';
  $display->content['new-7e5f67e9-70fe-4ff0-9cab-51a7b7a4cfa7'] = $pane;
  $display->panels['top'][0] = 'new-7e5f67e9-70fe-4ff0-9cab-51a7b7a4cfa7';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = 'new-7e5f67e9-70fe-4ff0-9cab-51a7b7a4cfa7';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['admin_dashboard'] = $page;

  return $pages;

}

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
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-a3e2754c-f682-4f1c-8bb2-be883bc45cb1';
    $pane->panel = 'left_above';
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
    $display->panels['left_above'][0] = 'new-a3e2754c-f682-4f1c-8bb2-be883bc45cb1';
    $pane = new stdClass();
    $pane->pid = 'new-4fc5fd1d-35a8-4922-a872-66120a15b7b9';
    $pane->panel = 'left_above';
    $pane->type = 'views_panes';
    $pane->subtype = 'global_reward_dashboard-panel_pane_1';
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
    $pane->uuid = '4fc5fd1d-35a8-4922-a872-66120a15b7b9';
    $display->content['new-4fc5fd1d-35a8-4922-a872-66120a15b7b9'] = $pane;
    $display->panels['left_above'][1] = 'new-4fc5fd1d-35a8-4922-a872-66120a15b7b9';
    $pane = new stdClass();
    $pane->pid = 'new-2140e4ba-1829-4482-81b6-347f38cb0eb2';
    $pane->panel = 'left_above';
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
    $pane->position = 2;
    $pane->locks = array();
    $pane->uuid = '2140e4ba-1829-4482-81b6-347f38cb0eb2';
    $display->content['new-2140e4ba-1829-4482-81b6-347f38cb0eb2'] = $pane;
    $display->panels['left_above'][2] = 'new-2140e4ba-1829-4482-81b6-347f38cb0eb2';
    $pane = new stdClass();
    $pane->pid = 'new-6a7a85a9-be5a-4f6c-9c7b-cb709dfb268b';
    $pane->panel = 'right_above';
    $pane->type = 'views_panes';
    $pane->subtype = 'raffle_dashboard-panel_pane_1';
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
    $pane->uuid = '6a7a85a9-be5a-4f6c-9c7b-cb709dfb268b';
    $display->content['new-6a7a85a9-be5a-4f6c-9c7b-cb709dfb268b'] = $pane;
    $display->panels['right_above'][0] = 'new-6a7a85a9-be5a-4f6c-9c7b-cb709dfb268b';
    $pane = new stdClass();
    $pane->pid = 'new-e68fbb1c-4a00-481d-84a3-9313fa21b9c1';
    $pane->panel = 'right_above';
    $pane->type = 'views_panes';
    $pane->subtype = 'badges_dashboard-panel_pane_1';
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
    $pane->uuid = 'e68fbb1c-4a00-481d-84a3-9313fa21b9c1';
    $display->content['new-e68fbb1c-4a00-481d-84a3-9313fa21b9c1'] = $pane;
    $display->panels['right_above'][1] = 'new-e68fbb1c-4a00-481d-84a3-9313fa21b9c1';
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

<?php
/**
 * @file
 * children_s_statistical_reports.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function children_s_statistical_reports_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'stat_reports';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'users';
  $view->human_name = 'Children\'s Statistical Reports';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Statistical Reports - By Home Library';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['access']['perm'] = 'access user profiles';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['distinct'] = TRUE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'views_aggregator';
  $handler->display->display_options['style_options']['columns'] = array(
    'field_library_branch' => 'field_library_branch',
  );
  $handler->display->display_options['style_options']['default'] = '-1';
  $handler->display->display_options['style_options']['info'] = array(
    'field_library_branch' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
      'has_aggr' => 1,
      'aggr' => array(
        'views_aggregator_group_and_compress' => 'views_aggregator_group_and_compress',
      ),
      'aggr_par' => '',
      'has_aggr_column' => 0,
      'aggr_column' => 'views_aggregator_count',
      'aggr_par_column' => '',
    ),
  );
  $handler->display->display_options['style_options']['column_aggregation']['totals_per_page'] = '0';
  $handler->display->display_options['style_options']['column_aggregation']['totals_row_position'] = array(
    1 => 0,
    2 => '2',
  );
  $handler->display->display_options['style_options']['column_aggregation']['precision'] = '2';
  /* Relationship: User: Activity */
  $handler->display->display_options['relationships']['eck_activity']['id'] = 'eck_activity';
  $handler->display->display_options['relationships']['eck_activity']['table'] = 'users';
  $handler->display->display_options['relationships']['eck_activity']['field'] = 'eck_activity';
  /* Relationship: User: Badge */
  $handler->display->display_options['relationships']['eck_badge']['id'] = 'eck_badge';
  $handler->display->display_options['relationships']['eck_badge']['table'] = 'users';
  $handler->display->display_options['relationships']['eck_badge']['field'] = 'eck_badge';
  /* Relationship: User: Profile */
  $handler->display->display_options['relationships']['profile']['id'] = 'profile';
  $handler->display->display_options['relationships']['profile']['table'] = 'users';
  $handler->display->display_options['relationships']['profile']['field'] = 'profile';
  $handler->display->display_options['relationships']['profile']['bundle_types'] = array(
    'main' => 'main',
  );
  /* Relationship: User: Raffle */
  $handler->display->display_options['relationships']['eck_raffle']['id'] = 'eck_raffle';
  $handler->display->display_options['relationships']['eck_raffle']['table'] = 'users';
  $handler->display->display_options['relationships']['eck_raffle']['field'] = 'eck_raffle';
  /* Relationship: User: Reward */
  $handler->display->display_options['relationships']['eck_reward']['id'] = 'eck_reward';
  $handler->display->display_options['relationships']['eck_reward']['table'] = 'users';
  $handler->display->display_options['relationships']['eck_reward']['field'] = 'eck_reward';
  /* Relationship: Profile: Library branch (field_library_branch) */
  $handler->display->display_options['relationships']['field_library_branch_tid']['id'] = 'field_library_branch_tid';
  $handler->display->display_options['relationships']['field_library_branch_tid']['table'] = 'field_data_field_library_branch';
  $handler->display->display_options['relationships']['field_library_branch_tid']['field'] = 'field_library_branch_tid';
  $handler->display->display_options['relationships']['field_library_branch_tid']['relationship'] = 'profile';
  /* Field: Profile: Library branch */
  $handler->display->display_options['fields']['field_library_branch']['id'] = 'field_library_branch';
  $handler->display->display_options['fields']['field_library_branch']['table'] = 'field_data_field_library_branch';
  $handler->display->display_options['fields']['field_library_branch']['field'] = 'field_library_branch';
  $handler->display->display_options['fields']['field_library_branch']['relationship'] = 'profile';
  $handler->display->display_options['fields']['field_library_branch']['empty'] = 'No Library';
  /* Filter criterion: User: Active */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'users';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = '1';
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: User: Roles */
  $handler->display->display_options['filters']['rid']['id'] = 'rid';
  $handler->display->display_options['filters']['rid']['table'] = 'users_roles';
  $handler->display->display_options['filters']['rid']['field'] = 'rid';
  $handler->display->display_options['filters']['rid']['value'] = array(
    6 => '6',
  );

  /* Display: Registrations By Age */
  $handler = $view->new_display('page', 'Registrations By Age', 'page');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Registrations by Age';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'views_aggregator';
  $handler->display->display_options['style_options']['columns'] = array(
    'field_library_branch' => 'field_library_branch',
    'field_user_birthday' => 'field_user_birthday',
  );
  $handler->display->display_options['style_options']['default'] = '-1';
  $handler->display->display_options['style_options']['info'] = array(
    'field_library_branch' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
      'has_aggr' => 1,
      'aggr' => array(
        'views_aggregator_group_and_compress' => 'views_aggregator_group_and_compress',
      ),
      'aggr_par' => '',
      'has_aggr_column' => 0,
      'aggr_column' => 'views_aggregator_enumerate',
      'aggr_par_column' => '',
    ),
    'field_user_birthday' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
      'has_aggr' => 1,
      'aggr' => array(
        'views_aggregator_enumerate_raw' => 'views_aggregator_enumerate_raw',
      ),
      'aggr_par' => '',
      'has_aggr_column' => 1,
      'aggr_column' => 'views_aggregator_range',
      'aggr_par_column' => '',
    ),
  );
  $handler->display->display_options['style_options']['column_aggregation']['totals_per_page'] = '0';
  $handler->display->display_options['style_options']['column_aggregation']['totals_row_position'] = array(
    1 => 0,
    2 => '2',
  );
  $handler->display->display_options['style_options']['column_aggregation']['precision'] = '2';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Profile: Library branch */
  $handler->display->display_options['fields']['field_library_branch']['id'] = 'field_library_branch';
  $handler->display->display_options['fields']['field_library_branch']['table'] = 'field_data_field_library_branch';
  $handler->display->display_options['fields']['field_library_branch']['field'] = 'field_library_branch';
  $handler->display->display_options['fields']['field_library_branch']['relationship'] = 'profile';
  $handler->display->display_options['fields']['field_library_branch']['empty'] = 'No Library';
  /* Field: Profile: Date of Birth */
  $handler->display->display_options['fields']['field_user_birthday']['id'] = 'field_user_birthday';
  $handler->display->display_options['fields']['field_user_birthday']['table'] = 'field_data_field_user_birthday';
  $handler->display->display_options['fields']['field_user_birthday']['field'] = 'field_user_birthday';
  $handler->display->display_options['fields']['field_user_birthday']['relationship'] = 'profile';
  $handler->display->display_options['fields']['field_user_birthday']['type'] = 'format_interval';
  $handler->display->display_options['fields']['field_user_birthday']['settings'] = array(
    'interval' => '2',
    'interval_display' => 'raw time ago',
  );
  $handler->display->display_options['path'] = 'statistical-reports/registrations-by-age';

  /* Display: Registrations By Home Library */
  $handler = $view->new_display('page', 'Registrations By Home Library', 'page_2');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Registrations by Home Library';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'views_aggregator';
  $handler->display->display_options['style_options']['columns'] = array(
    'field_library_branch' => 'field_library_branch',
    'field_user_first_name' => 'field_user_first_name',
    'field_user_last_name' => 'field_user_last_name',
  );
  $handler->display->display_options['style_options']['default'] = '-1';
  $handler->display->display_options['style_options']['info'] = array(
    'field_library_branch' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
      'has_aggr' => 1,
      'aggr' => array(
        'views_aggregator_group_and_compress' => 'views_aggregator_group_and_compress',
      ),
      'aggr_par' => '',
      'has_aggr_column' => 0,
      'aggr_column' => 'views_aggregator_count',
      'aggr_par_column' => '',
    ),
    'field_user_first_name' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
      'has_aggr' => 0,
      'aggr' => array(
        'views_aggregator_first' => 'views_aggregator_first',
      ),
      'aggr_par' => '',
      'has_aggr_column' => 0,
      'aggr_column' => 'views_aggregator_sum',
      'aggr_par_column' => '',
    ),
    'field_user_last_name' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
      'has_aggr' => 1,
      'aggr' => array(
        'views_aggregator_count' => 'views_aggregator_count',
      ),
      'aggr_par' => '',
      'has_aggr_column' => 1,
      'aggr_column' => 'views_aggregator_count',
      'aggr_par_column' => '',
    ),
  );
  $handler->display->display_options['style_options']['column_aggregation']['totals_per_page'] = '0';
  $handler->display->display_options['style_options']['column_aggregation']['totals_row_position'] = array(
    1 => 0,
    2 => '2',
  );
  $handler->display->display_options['style_options']['column_aggregation']['precision'] = '2';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Profile: Library branch */
  $handler->display->display_options['fields']['field_library_branch']['id'] = 'field_library_branch';
  $handler->display->display_options['fields']['field_library_branch']['table'] = 'field_data_field_library_branch';
  $handler->display->display_options['fields']['field_library_branch']['field'] = 'field_library_branch';
  $handler->display->display_options['fields']['field_library_branch']['relationship'] = 'profile';
  $handler->display->display_options['fields']['field_library_branch']['empty'] = 'No Library';
  /* Field: Profile: First name */
  $handler->display->display_options['fields']['field_user_first_name']['id'] = 'field_user_first_name';
  $handler->display->display_options['fields']['field_user_first_name']['table'] = 'field_data_field_user_first_name';
  $handler->display->display_options['fields']['field_user_first_name']['field'] = 'field_user_first_name';
  $handler->display->display_options['fields']['field_user_first_name']['relationship'] = 'profile';
  $handler->display->display_options['fields']['field_user_first_name']['exclude'] = TRUE;
  /* Field: Profile: Last name */
  $handler->display->display_options['fields']['field_user_last_name']['id'] = 'field_user_last_name';
  $handler->display->display_options['fields']['field_user_last_name']['table'] = 'field_data_field_user_last_name';
  $handler->display->display_options['fields']['field_user_last_name']['field'] = 'field_user_last_name';
  $handler->display->display_options['fields']['field_user_last_name']['relationship'] = 'profile';
  $handler->display->display_options['fields']['field_user_last_name']['label'] = '# of Registrations';
  $handler->display->display_options['fields']['field_user_last_name']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_user_last_name']['alter']['text'] = '[field_user_first_name] [field_user_last_name]';
  $handler->display->display_options['path'] = 'admin/statistical-reports/registrations-by-home-library';
  $handler->display->display_options['menu']['type'] = 'normal';
  $handler->display->display_options['menu']['title'] = 'Registrations By Home Library';
  $handler->display->display_options['menu']['weight'] = '0';
  $handler->display->display_options['menu']['name'] = 'menu-statistical-reports';
  $handler->display->display_options['menu']['context'] = 0;
  $handler->display->display_options['menu']['context_only_inline'] = 0;

  /* Display: 10 Days Home Library Completions */
  $handler = $view->new_display('page', '10 Days Home Library Completions', 'page_1');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Home Library Completions, 10 Days';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'views_aggregator';
  $handler->display->display_options['style_options']['columns'] = array(
    'field_library_branch' => 'field_library_branch',
    'field_badge_image' => 'field_badge_image',
    'title' => 'title',
  );
  $handler->display->display_options['style_options']['default'] = '-1';
  $handler->display->display_options['style_options']['info'] = array(
    'field_library_branch' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
      'has_aggr' => 1,
      'aggr' => array(
        'views_aggregator_group_and_compress' => 'views_aggregator_group_and_compress',
      ),
      'aggr_par' => '',
      'has_aggr_column' => 0,
      'aggr_column' => 'views_aggregator_count',
      'aggr_par_column' => '',
    ),
    'field_badge_image' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
      'has_aggr' => 0,
      'aggr' => array(
        'views_aggregator_enumerate_raw' => 'views_aggregator_enumerate_raw',
      ),
      'aggr_par' => '',
      'has_aggr_column' => 0,
      'aggr_column' => 'views_aggregator_enumerate',
      'aggr_par_column' => '',
    ),
    'title' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
      'has_aggr' => 1,
      'aggr' => array(
        'views_aggregator_count' => 'views_aggregator_count',
      ),
      'aggr_par' => '',
      'has_aggr_column' => 1,
      'aggr_column' => 'views_aggregator_count',
      'aggr_par_column' => '',
    ),
  );
  $handler->display->display_options['style_options']['column_aggregation']['totals_per_page'] = '0';
  $handler->display->display_options['style_options']['column_aggregation']['totals_row_position'] = array(
    1 => 0,
    2 => '2',
  );
  $handler->display->display_options['style_options']['column_aggregation']['precision'] = '2';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  /* Relationship: User: Activity */
  $handler->display->display_options['relationships']['eck_activity']['id'] = 'eck_activity';
  $handler->display->display_options['relationships']['eck_activity']['table'] = 'users';
  $handler->display->display_options['relationships']['eck_activity']['field'] = 'eck_activity';
  /* Relationship: User: Profile */
  $handler->display->display_options['relationships']['profile']['id'] = 'profile';
  $handler->display->display_options['relationships']['profile']['table'] = 'users';
  $handler->display->display_options['relationships']['profile']['field'] = 'profile';
  $handler->display->display_options['relationships']['profile']['bundle_types'] = array(
    'main' => 'main',
  );
  /* Relationship: Profile: Library branch (field_library_branch) */
  $handler->display->display_options['relationships']['field_library_branch_tid']['id'] = 'field_library_branch_tid';
  $handler->display->display_options['relationships']['field_library_branch_tid']['table'] = 'field_data_field_library_branch';
  $handler->display->display_options['relationships']['field_library_branch_tid']['field'] = 'field_library_branch_tid';
  $handler->display->display_options['relationships']['field_library_branch_tid']['relationship'] = 'profile';
  /* Relationship: User: Reward */
  $handler->display->display_options['relationships']['eck_reward']['id'] = 'eck_reward';
  $handler->display->display_options['relationships']['eck_reward']['table'] = 'users';
  $handler->display->display_options['relationships']['eck_reward']['field'] = 'eck_reward';
  /* Relationship: Entity Reference: Referenced Entity */
  $handler->display->display_options['relationships']['field_reward_claim_id_target_id']['id'] = 'field_reward_claim_id_target_id';
  $handler->display->display_options['relationships']['field_reward_claim_id_target_id']['table'] = 'field_data_field_reward_claim_id';
  $handler->display->display_options['relationships']['field_reward_claim_id_target_id']['field'] = 'field_reward_claim_id_target_id';
  $handler->display->display_options['relationships']['field_reward_claim_id_target_id']['relationship'] = 'eck_reward';
  /* Relationship: Entity Reference: Referenced Entity */
  $handler->display->display_options['relationships']['field_reward_badge_target_id']['id'] = 'field_reward_badge_target_id';
  $handler->display->display_options['relationships']['field_reward_badge_target_id']['table'] = 'field_data_field_reward_badge';
  $handler->display->display_options['relationships']['field_reward_badge_target_id']['field'] = 'field_reward_badge_target_id';
  $handler->display->display_options['relationships']['field_reward_badge_target_id']['relationship'] = 'field_reward_claim_id_target_id';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Profile: Library branch */
  $handler->display->display_options['fields']['field_library_branch']['id'] = 'field_library_branch';
  $handler->display->display_options['fields']['field_library_branch']['table'] = 'field_data_field_library_branch';
  $handler->display->display_options['fields']['field_library_branch']['field'] = 'field_library_branch';
  $handler->display->display_options['fields']['field_library_branch']['relationship'] = 'profile';
  $handler->display->display_options['fields']['field_library_branch']['empty'] = 'No Library';
  /* Field: Badge: Badge Image */
  $handler->display->display_options['fields']['field_badge_image']['id'] = 'field_badge_image';
  $handler->display->display_options['fields']['field_badge_image']['table'] = 'field_data_field_badge_image';
  $handler->display->display_options['fields']['field_badge_image']['field'] = 'field_badge_image';
  $handler->display->display_options['fields']['field_badge_image']['relationship'] = 'field_reward_badge_target_id';
  $handler->display->display_options['fields']['field_badge_image']['label'] = '';
  $handler->display->display_options['fields']['field_badge_image']['exclude'] = TRUE;
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
  $handler->display->display_options['fields']['title']['relationship'] = 'field_reward_badge_target_id';
  $handler->display->display_options['fields']['title']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['title']['alter']['text'] = '[field_badge_image]</br>
[title]';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: User: Active */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'users';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = '1';
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: User: Roles */
  $handler->display->display_options['filters']['rid']['id'] = 'rid';
  $handler->display->display_options['filters']['rid']['table'] = 'users_roles';
  $handler->display->display_options['filters']['rid']['field'] = 'rid';
  $handler->display->display_options['filters']['rid']['value'] = array(
    6 => '6',
  );
  /* Filter criterion: Badge: Title */
  $handler->display->display_options['filters']['title']['id'] = 'title';
  $handler->display->display_options['filters']['title']['table'] = 'eck_badge';
  $handler->display->display_options['filters']['title']['field'] = 'title';
  $handler->display->display_options['filters']['title']['relationship'] = 'field_reward_badge_target_id';
  $handler->display->display_options['filters']['title']['value'] = '10 days of reading badge';
  $handler->display->display_options['path'] = 'admin/statistical-reports/home-library-completion-10';
  $handler->display->display_options['menu']['type'] = 'normal';
  $handler->display->display_options['menu']['title'] = '10 Day Completed By Home Library';
  $handler->display->display_options['menu']['weight'] = '0';
  $handler->display->display_options['menu']['name'] = 'menu-statistical-reports';
  $handler->display->display_options['menu']['context'] = 0;
  $handler->display->display_options['menu']['context_only_inline'] = 0;

  /* Display: 20 Days Home Library Completions */
  $handler = $view->new_display('page', '20 Days Home Library Completions', 'page_3');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Home Library Completions, 20 Days';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'views_aggregator';
  $handler->display->display_options['style_options']['columns'] = array(
    'field_library_branch' => 'field_library_branch',
    'field_badge_image' => 'field_badge_image',
    'title' => 'title',
  );
  $handler->display->display_options['style_options']['default'] = '-1';
  $handler->display->display_options['style_options']['info'] = array(
    'field_library_branch' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
      'has_aggr' => 1,
      'aggr' => array(
        'views_aggregator_group_and_compress' => 'views_aggregator_group_and_compress',
      ),
      'aggr_par' => '',
      'has_aggr_column' => 0,
      'aggr_column' => 'views_aggregator_count',
      'aggr_par_column' => '',
    ),
    'field_badge_image' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
      'has_aggr' => 0,
      'aggr' => array(
        'views_aggregator_enumerate_raw' => 'views_aggregator_enumerate_raw',
      ),
      'aggr_par' => '',
      'has_aggr_column' => 0,
      'aggr_column' => 'views_aggregator_enumerate',
      'aggr_par_column' => '',
    ),
    'title' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
      'has_aggr' => 1,
      'aggr' => array(
        'views_aggregator_count' => 'views_aggregator_count',
      ),
      'aggr_par' => '',
      'has_aggr_column' => 1,
      'aggr_column' => 'views_aggregator_count',
      'aggr_par_column' => '',
    ),
  );
  $handler->display->display_options['style_options']['column_aggregation']['totals_per_page'] = '0';
  $handler->display->display_options['style_options']['column_aggregation']['totals_row_position'] = array(
    1 => 0,
    2 => '2',
  );
  $handler->display->display_options['style_options']['column_aggregation']['precision'] = '2';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  /* Relationship: User: Activity */
  $handler->display->display_options['relationships']['eck_activity']['id'] = 'eck_activity';
  $handler->display->display_options['relationships']['eck_activity']['table'] = 'users';
  $handler->display->display_options['relationships']['eck_activity']['field'] = 'eck_activity';
  /* Relationship: User: Profile */
  $handler->display->display_options['relationships']['profile']['id'] = 'profile';
  $handler->display->display_options['relationships']['profile']['table'] = 'users';
  $handler->display->display_options['relationships']['profile']['field'] = 'profile';
  $handler->display->display_options['relationships']['profile']['bundle_types'] = array(
    'main' => 'main',
  );
  /* Relationship: Profile: Library branch (field_library_branch) */
  $handler->display->display_options['relationships']['field_library_branch_tid']['id'] = 'field_library_branch_tid';
  $handler->display->display_options['relationships']['field_library_branch_tid']['table'] = 'field_data_field_library_branch';
  $handler->display->display_options['relationships']['field_library_branch_tid']['field'] = 'field_library_branch_tid';
  $handler->display->display_options['relationships']['field_library_branch_tid']['relationship'] = 'profile';
  /* Relationship: User: Reward */
  $handler->display->display_options['relationships']['eck_reward']['id'] = 'eck_reward';
  $handler->display->display_options['relationships']['eck_reward']['table'] = 'users';
  $handler->display->display_options['relationships']['eck_reward']['field'] = 'eck_reward';
  /* Relationship: Entity Reference: Referenced Entity */
  $handler->display->display_options['relationships']['field_reward_claim_id_target_id']['id'] = 'field_reward_claim_id_target_id';
  $handler->display->display_options['relationships']['field_reward_claim_id_target_id']['table'] = 'field_data_field_reward_claim_id';
  $handler->display->display_options['relationships']['field_reward_claim_id_target_id']['field'] = 'field_reward_claim_id_target_id';
  $handler->display->display_options['relationships']['field_reward_claim_id_target_id']['relationship'] = 'eck_reward';
  /* Relationship: Entity Reference: Referenced Entity */
  $handler->display->display_options['relationships']['field_reward_badge_target_id']['id'] = 'field_reward_badge_target_id';
  $handler->display->display_options['relationships']['field_reward_badge_target_id']['table'] = 'field_data_field_reward_badge';
  $handler->display->display_options['relationships']['field_reward_badge_target_id']['field'] = 'field_reward_badge_target_id';
  $handler->display->display_options['relationships']['field_reward_badge_target_id']['relationship'] = 'field_reward_claim_id_target_id';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Profile: Library branch */
  $handler->display->display_options['fields']['field_library_branch']['id'] = 'field_library_branch';
  $handler->display->display_options['fields']['field_library_branch']['table'] = 'field_data_field_library_branch';
  $handler->display->display_options['fields']['field_library_branch']['field'] = 'field_library_branch';
  $handler->display->display_options['fields']['field_library_branch']['relationship'] = 'profile';
  $handler->display->display_options['fields']['field_library_branch']['empty'] = 'No Library';
  /* Field: Badge: Badge Image */
  $handler->display->display_options['fields']['field_badge_image']['id'] = 'field_badge_image';
  $handler->display->display_options['fields']['field_badge_image']['table'] = 'field_data_field_badge_image';
  $handler->display->display_options['fields']['field_badge_image']['field'] = 'field_badge_image';
  $handler->display->display_options['fields']['field_badge_image']['relationship'] = 'field_reward_badge_target_id';
  $handler->display->display_options['fields']['field_badge_image']['label'] = '';
  $handler->display->display_options['fields']['field_badge_image']['exclude'] = TRUE;
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
  $handler->display->display_options['fields']['title']['relationship'] = 'field_reward_badge_target_id';
  $handler->display->display_options['fields']['title']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['title']['alter']['text'] = '[field_badge_image]</br>
[title]';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: User: Active */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'users';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = '1';
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: User: Roles */
  $handler->display->display_options['filters']['rid']['id'] = 'rid';
  $handler->display->display_options['filters']['rid']['table'] = 'users_roles';
  $handler->display->display_options['filters']['rid']['field'] = 'rid';
  $handler->display->display_options['filters']['rid']['value'] = array(
    6 => '6',
  );
  /* Filter criterion: Badge: Title */
  $handler->display->display_options['filters']['title']['id'] = 'title';
  $handler->display->display_options['filters']['title']['table'] = 'eck_badge';
  $handler->display->display_options['filters']['title']['field'] = 'title';
  $handler->display->display_options['filters']['title']['relationship'] = 'field_reward_badge_target_id';
  $handler->display->display_options['filters']['title']['value'] = '20 days of reading badge';
  $handler->display->display_options['path'] = 'admin/statistical-reports/home-library-completion-20';
  $handler->display->display_options['menu']['type'] = 'normal';
  $handler->display->display_options['menu']['title'] = '20 Day Completed By Home Library';
  $handler->display->display_options['menu']['weight'] = '0';
  $handler->display->display_options['menu']['name'] = 'menu-statistical-reports';
  $handler->display->display_options['menu']['context'] = 0;
  $handler->display->display_options['menu']['context_only_inline'] = 0;

  /* Display: 30 Days Home Library Completions */
  $handler = $view->new_display('page', '30 Days Home Library Completions', 'page_4');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Home Library Completions, 30 Days';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'views_aggregator';
  $handler->display->display_options['style_options']['columns'] = array(
    'field_library_branch' => 'field_library_branch',
    'field_badge_image' => 'field_badge_image',
    'title' => 'title',
  );
  $handler->display->display_options['style_options']['default'] = '-1';
  $handler->display->display_options['style_options']['info'] = array(
    'field_library_branch' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
      'has_aggr' => 1,
      'aggr' => array(
        'views_aggregator_group_and_compress' => 'views_aggregator_group_and_compress',
      ),
      'aggr_par' => '',
      'has_aggr_column' => 0,
      'aggr_column' => 'views_aggregator_count',
      'aggr_par_column' => '',
    ),
    'field_badge_image' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
      'has_aggr' => 0,
      'aggr' => array(
        'views_aggregator_enumerate_raw' => 'views_aggregator_enumerate_raw',
      ),
      'aggr_par' => '',
      'has_aggr_column' => 0,
      'aggr_column' => 'views_aggregator_enumerate',
      'aggr_par_column' => '',
    ),
    'title' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
      'has_aggr' => 1,
      'aggr' => array(
        'views_aggregator_count' => 'views_aggregator_count',
      ),
      'aggr_par' => '',
      'has_aggr_column' => 1,
      'aggr_column' => 'views_aggregator_count',
      'aggr_par_column' => '',
    ),
  );
  $handler->display->display_options['style_options']['column_aggregation']['totals_per_page'] = '0';
  $handler->display->display_options['style_options']['column_aggregation']['totals_row_position'] = array(
    1 => 0,
    2 => '2',
  );
  $handler->display->display_options['style_options']['column_aggregation']['precision'] = '2';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  /* Relationship: User: Activity */
  $handler->display->display_options['relationships']['eck_activity']['id'] = 'eck_activity';
  $handler->display->display_options['relationships']['eck_activity']['table'] = 'users';
  $handler->display->display_options['relationships']['eck_activity']['field'] = 'eck_activity';
  /* Relationship: User: Profile */
  $handler->display->display_options['relationships']['profile']['id'] = 'profile';
  $handler->display->display_options['relationships']['profile']['table'] = 'users';
  $handler->display->display_options['relationships']['profile']['field'] = 'profile';
  $handler->display->display_options['relationships']['profile']['bundle_types'] = array(
    'main' => 'main',
  );
  /* Relationship: Profile: Library branch (field_library_branch) */
  $handler->display->display_options['relationships']['field_library_branch_tid']['id'] = 'field_library_branch_tid';
  $handler->display->display_options['relationships']['field_library_branch_tid']['table'] = 'field_data_field_library_branch';
  $handler->display->display_options['relationships']['field_library_branch_tid']['field'] = 'field_library_branch_tid';
  $handler->display->display_options['relationships']['field_library_branch_tid']['relationship'] = 'profile';
  /* Relationship: User: Reward */
  $handler->display->display_options['relationships']['eck_reward']['id'] = 'eck_reward';
  $handler->display->display_options['relationships']['eck_reward']['table'] = 'users';
  $handler->display->display_options['relationships']['eck_reward']['field'] = 'eck_reward';
  /* Relationship: Entity Reference: Referenced Entity */
  $handler->display->display_options['relationships']['field_reward_claim_id_target_id']['id'] = 'field_reward_claim_id_target_id';
  $handler->display->display_options['relationships']['field_reward_claim_id_target_id']['table'] = 'field_data_field_reward_claim_id';
  $handler->display->display_options['relationships']['field_reward_claim_id_target_id']['field'] = 'field_reward_claim_id_target_id';
  $handler->display->display_options['relationships']['field_reward_claim_id_target_id']['relationship'] = 'eck_reward';
  /* Relationship: Entity Reference: Referenced Entity */
  $handler->display->display_options['relationships']['field_reward_badge_target_id']['id'] = 'field_reward_badge_target_id';
  $handler->display->display_options['relationships']['field_reward_badge_target_id']['table'] = 'field_data_field_reward_badge';
  $handler->display->display_options['relationships']['field_reward_badge_target_id']['field'] = 'field_reward_badge_target_id';
  $handler->display->display_options['relationships']['field_reward_badge_target_id']['relationship'] = 'field_reward_claim_id_target_id';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Profile: Library branch */
  $handler->display->display_options['fields']['field_library_branch']['id'] = 'field_library_branch';
  $handler->display->display_options['fields']['field_library_branch']['table'] = 'field_data_field_library_branch';
  $handler->display->display_options['fields']['field_library_branch']['field'] = 'field_library_branch';
  $handler->display->display_options['fields']['field_library_branch']['relationship'] = 'profile';
  $handler->display->display_options['fields']['field_library_branch']['empty'] = 'No Library';
  /* Field: Badge: Badge Image */
  $handler->display->display_options['fields']['field_badge_image']['id'] = 'field_badge_image';
  $handler->display->display_options['fields']['field_badge_image']['table'] = 'field_data_field_badge_image';
  $handler->display->display_options['fields']['field_badge_image']['field'] = 'field_badge_image';
  $handler->display->display_options['fields']['field_badge_image']['relationship'] = 'field_reward_badge_target_id';
  $handler->display->display_options['fields']['field_badge_image']['label'] = '';
  $handler->display->display_options['fields']['field_badge_image']['exclude'] = TRUE;
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
  $handler->display->display_options['fields']['title']['relationship'] = 'field_reward_badge_target_id';
  $handler->display->display_options['fields']['title']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['title']['alter']['text'] = '[field_badge_image]</br>
[title]';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: User: Active */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'users';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = '1';
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: User: Roles */
  $handler->display->display_options['filters']['rid']['id'] = 'rid';
  $handler->display->display_options['filters']['rid']['table'] = 'users_roles';
  $handler->display->display_options['filters']['rid']['field'] = 'rid';
  $handler->display->display_options['filters']['rid']['value'] = array(
    6 => '6',
  );
  /* Filter criterion: Badge: Title */
  $handler->display->display_options['filters']['title']['id'] = 'title';
  $handler->display->display_options['filters']['title']['table'] = 'eck_badge';
  $handler->display->display_options['filters']['title']['field'] = 'title';
  $handler->display->display_options['filters']['title']['relationship'] = 'field_reward_badge_target_id';
  $handler->display->display_options['filters']['title']['value'] = '30 days of reading badge';
  $handler->display->display_options['path'] = 'admin/statistical-reports/home-library-completion-30';
  $handler->display->display_options['menu']['type'] = 'normal';
  $handler->display->display_options['menu']['title'] = '30 Day Completed By Home Library';
  $handler->display->display_options['menu']['weight'] = '0';
  $handler->display->display_options['menu']['name'] = 'menu-statistical-reports';
  $handler->display->display_options['menu']['context'] = 0;
  $handler->display->display_options['menu']['context_only_inline'] = 0;

  /* Display: 40 Days Home Library Completions */
  $handler = $view->new_display('page', '40 Days Home Library Completions', 'page_5');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Home Library Completions, 40 Days';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'views_aggregator';
  $handler->display->display_options['style_options']['columns'] = array(
    'field_library_branch' => 'field_library_branch',
    'field_badge_image' => 'field_badge_image',
    'title' => 'title',
  );
  $handler->display->display_options['style_options']['default'] = '-1';
  $handler->display->display_options['style_options']['info'] = array(
    'field_library_branch' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
      'has_aggr' => 1,
      'aggr' => array(
        'views_aggregator_group_and_compress' => 'views_aggregator_group_and_compress',
      ),
      'aggr_par' => '',
      'has_aggr_column' => 0,
      'aggr_column' => 'views_aggregator_count',
      'aggr_par_column' => '',
    ),
    'field_badge_image' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
      'has_aggr' => 0,
      'aggr' => array(
        'views_aggregator_enumerate_raw' => 'views_aggregator_enumerate_raw',
      ),
      'aggr_par' => '',
      'has_aggr_column' => 0,
      'aggr_column' => 'views_aggregator_enumerate',
      'aggr_par_column' => '',
    ),
    'title' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
      'has_aggr' => 1,
      'aggr' => array(
        'views_aggregator_count' => 'views_aggregator_count',
      ),
      'aggr_par' => '',
      'has_aggr_column' => 1,
      'aggr_column' => 'views_aggregator_count',
      'aggr_par_column' => '',
    ),
  );
  $handler->display->display_options['style_options']['column_aggregation']['totals_per_page'] = '0';
  $handler->display->display_options['style_options']['column_aggregation']['totals_row_position'] = array(
    1 => 0,
    2 => '2',
  );
  $handler->display->display_options['style_options']['column_aggregation']['precision'] = '2';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  /* Relationship: User: Activity */
  $handler->display->display_options['relationships']['eck_activity']['id'] = 'eck_activity';
  $handler->display->display_options['relationships']['eck_activity']['table'] = 'users';
  $handler->display->display_options['relationships']['eck_activity']['field'] = 'eck_activity';
  /* Relationship: User: Profile */
  $handler->display->display_options['relationships']['profile']['id'] = 'profile';
  $handler->display->display_options['relationships']['profile']['table'] = 'users';
  $handler->display->display_options['relationships']['profile']['field'] = 'profile';
  $handler->display->display_options['relationships']['profile']['bundle_types'] = array(
    'main' => 'main',
  );
  /* Relationship: Profile: Library branch (field_library_branch) */
  $handler->display->display_options['relationships']['field_library_branch_tid']['id'] = 'field_library_branch_tid';
  $handler->display->display_options['relationships']['field_library_branch_tid']['table'] = 'field_data_field_library_branch';
  $handler->display->display_options['relationships']['field_library_branch_tid']['field'] = 'field_library_branch_tid';
  $handler->display->display_options['relationships']['field_library_branch_tid']['relationship'] = 'profile';
  /* Relationship: User: Reward */
  $handler->display->display_options['relationships']['eck_reward']['id'] = 'eck_reward';
  $handler->display->display_options['relationships']['eck_reward']['table'] = 'users';
  $handler->display->display_options['relationships']['eck_reward']['field'] = 'eck_reward';
  /* Relationship: Entity Reference: Referenced Entity */
  $handler->display->display_options['relationships']['field_reward_claim_id_target_id']['id'] = 'field_reward_claim_id_target_id';
  $handler->display->display_options['relationships']['field_reward_claim_id_target_id']['table'] = 'field_data_field_reward_claim_id';
  $handler->display->display_options['relationships']['field_reward_claim_id_target_id']['field'] = 'field_reward_claim_id_target_id';
  $handler->display->display_options['relationships']['field_reward_claim_id_target_id']['relationship'] = 'eck_reward';
  /* Relationship: Entity Reference: Referenced Entity */
  $handler->display->display_options['relationships']['field_reward_badge_target_id']['id'] = 'field_reward_badge_target_id';
  $handler->display->display_options['relationships']['field_reward_badge_target_id']['table'] = 'field_data_field_reward_badge';
  $handler->display->display_options['relationships']['field_reward_badge_target_id']['field'] = 'field_reward_badge_target_id';
  $handler->display->display_options['relationships']['field_reward_badge_target_id']['relationship'] = 'field_reward_claim_id_target_id';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Profile: Library branch */
  $handler->display->display_options['fields']['field_library_branch']['id'] = 'field_library_branch';
  $handler->display->display_options['fields']['field_library_branch']['table'] = 'field_data_field_library_branch';
  $handler->display->display_options['fields']['field_library_branch']['field'] = 'field_library_branch';
  $handler->display->display_options['fields']['field_library_branch']['relationship'] = 'profile';
  $handler->display->display_options['fields']['field_library_branch']['empty'] = 'No Library';
  /* Field: Badge: Badge Image */
  $handler->display->display_options['fields']['field_badge_image']['id'] = 'field_badge_image';
  $handler->display->display_options['fields']['field_badge_image']['table'] = 'field_data_field_badge_image';
  $handler->display->display_options['fields']['field_badge_image']['field'] = 'field_badge_image';
  $handler->display->display_options['fields']['field_badge_image']['relationship'] = 'field_reward_badge_target_id';
  $handler->display->display_options['fields']['field_badge_image']['label'] = '';
  $handler->display->display_options['fields']['field_badge_image']['exclude'] = TRUE;
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
  $handler->display->display_options['fields']['title']['relationship'] = 'field_reward_badge_target_id';
  $handler->display->display_options['fields']['title']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['title']['alter']['text'] = '[field_badge_image]</br>
[title]';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: User: Active */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'users';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = '1';
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: User: Roles */
  $handler->display->display_options['filters']['rid']['id'] = 'rid';
  $handler->display->display_options['filters']['rid']['table'] = 'users_roles';
  $handler->display->display_options['filters']['rid']['field'] = 'rid';
  $handler->display->display_options['filters']['rid']['value'] = array(
    6 => '6',
  );
  /* Filter criterion: Badge: Title */
  $handler->display->display_options['filters']['title']['id'] = 'title';
  $handler->display->display_options['filters']['title']['table'] = 'eck_badge';
  $handler->display->display_options['filters']['title']['field'] = 'title';
  $handler->display->display_options['filters']['title']['relationship'] = 'field_reward_badge_target_id';
  $handler->display->display_options['filters']['title']['value'] = '40 days of reading badge';
  $handler->display->display_options['path'] = 'admin/statistical-reports/home-library-completion-40';
  $handler->display->display_options['menu']['type'] = 'normal';
  $handler->display->display_options['menu']['title'] = '40 Day Completed By Home Library';
  $handler->display->display_options['menu']['weight'] = '0';
  $handler->display->display_options['menu']['name'] = 'menu-statistical-reports';
  $handler->display->display_options['menu']['context'] = 0;
  $handler->display->display_options['menu']['context_only_inline'] = 0;

  /* Display: 50 Days Home Library Completions */
  $handler = $view->new_display('page', '50 Days Home Library Completions', 'page_6');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Home Library Completions, 50 Days';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'views_aggregator';
  $handler->display->display_options['style_options']['columns'] = array(
    'field_library_branch' => 'field_library_branch',
    'field_badge_image' => 'field_badge_image',
    'title' => 'title',
  );
  $handler->display->display_options['style_options']['default'] = '-1';
  $handler->display->display_options['style_options']['info'] = array(
    'field_library_branch' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
      'has_aggr' => 1,
      'aggr' => array(
        'views_aggregator_group_and_compress' => 'views_aggregator_group_and_compress',
      ),
      'aggr_par' => '',
      'has_aggr_column' => 0,
      'aggr_column' => 'views_aggregator_count',
      'aggr_par_column' => '',
    ),
    'field_badge_image' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
      'has_aggr' => 0,
      'aggr' => array(
        'views_aggregator_enumerate_raw' => 'views_aggregator_enumerate_raw',
      ),
      'aggr_par' => '',
      'has_aggr_column' => 0,
      'aggr_column' => 'views_aggregator_enumerate',
      'aggr_par_column' => '',
    ),
    'title' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
      'has_aggr' => 1,
      'aggr' => array(
        'views_aggregator_count' => 'views_aggregator_count',
      ),
      'aggr_par' => '',
      'has_aggr_column' => 1,
      'aggr_column' => 'views_aggregator_count',
      'aggr_par_column' => '',
    ),
  );
  $handler->display->display_options['style_options']['column_aggregation']['totals_per_page'] = '0';
  $handler->display->display_options['style_options']['column_aggregation']['totals_row_position'] = array(
    1 => 0,
    2 => '2',
  );
  $handler->display->display_options['style_options']['column_aggregation']['precision'] = '2';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  /* Relationship: User: Activity */
  $handler->display->display_options['relationships']['eck_activity']['id'] = 'eck_activity';
  $handler->display->display_options['relationships']['eck_activity']['table'] = 'users';
  $handler->display->display_options['relationships']['eck_activity']['field'] = 'eck_activity';
  /* Relationship: User: Profile */
  $handler->display->display_options['relationships']['profile']['id'] = 'profile';
  $handler->display->display_options['relationships']['profile']['table'] = 'users';
  $handler->display->display_options['relationships']['profile']['field'] = 'profile';
  $handler->display->display_options['relationships']['profile']['bundle_types'] = array(
    'main' => 'main',
  );
  /* Relationship: Profile: Library branch (field_library_branch) */
  $handler->display->display_options['relationships']['field_library_branch_tid']['id'] = 'field_library_branch_tid';
  $handler->display->display_options['relationships']['field_library_branch_tid']['table'] = 'field_data_field_library_branch';
  $handler->display->display_options['relationships']['field_library_branch_tid']['field'] = 'field_library_branch_tid';
  $handler->display->display_options['relationships']['field_library_branch_tid']['relationship'] = 'profile';
  /* Relationship: User: Reward */
  $handler->display->display_options['relationships']['eck_reward']['id'] = 'eck_reward';
  $handler->display->display_options['relationships']['eck_reward']['table'] = 'users';
  $handler->display->display_options['relationships']['eck_reward']['field'] = 'eck_reward';
  /* Relationship: Entity Reference: Referenced Entity */
  $handler->display->display_options['relationships']['field_reward_claim_id_target_id']['id'] = 'field_reward_claim_id_target_id';
  $handler->display->display_options['relationships']['field_reward_claim_id_target_id']['table'] = 'field_data_field_reward_claim_id';
  $handler->display->display_options['relationships']['field_reward_claim_id_target_id']['field'] = 'field_reward_claim_id_target_id';
  $handler->display->display_options['relationships']['field_reward_claim_id_target_id']['relationship'] = 'eck_reward';
  /* Relationship: Entity Reference: Referenced Entity */
  $handler->display->display_options['relationships']['field_reward_badge_target_id']['id'] = 'field_reward_badge_target_id';
  $handler->display->display_options['relationships']['field_reward_badge_target_id']['table'] = 'field_data_field_reward_badge';
  $handler->display->display_options['relationships']['field_reward_badge_target_id']['field'] = 'field_reward_badge_target_id';
  $handler->display->display_options['relationships']['field_reward_badge_target_id']['relationship'] = 'field_reward_claim_id_target_id';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Profile: Library branch */
  $handler->display->display_options['fields']['field_library_branch']['id'] = 'field_library_branch';
  $handler->display->display_options['fields']['field_library_branch']['table'] = 'field_data_field_library_branch';
  $handler->display->display_options['fields']['field_library_branch']['field'] = 'field_library_branch';
  $handler->display->display_options['fields']['field_library_branch']['relationship'] = 'profile';
  $handler->display->display_options['fields']['field_library_branch']['empty'] = 'No Library';
  /* Field: Badge: Badge Image */
  $handler->display->display_options['fields']['field_badge_image']['id'] = 'field_badge_image';
  $handler->display->display_options['fields']['field_badge_image']['table'] = 'field_data_field_badge_image';
  $handler->display->display_options['fields']['field_badge_image']['field'] = 'field_badge_image';
  $handler->display->display_options['fields']['field_badge_image']['relationship'] = 'field_reward_badge_target_id';
  $handler->display->display_options['fields']['field_badge_image']['label'] = '';
  $handler->display->display_options['fields']['field_badge_image']['exclude'] = TRUE;
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
  $handler->display->display_options['fields']['title']['relationship'] = 'field_reward_badge_target_id';
  $handler->display->display_options['fields']['title']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['title']['alter']['text'] = '[field_badge_image]</br>
[title]';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: User: Active */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'users';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = '1';
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: User: Roles */
  $handler->display->display_options['filters']['rid']['id'] = 'rid';
  $handler->display->display_options['filters']['rid']['table'] = 'users_roles';
  $handler->display->display_options['filters']['rid']['field'] = 'rid';
  $handler->display->display_options['filters']['rid']['value'] = array(
    6 => '6',
  );
  /* Filter criterion: Badge: Title */
  $handler->display->display_options['filters']['title']['id'] = 'title';
  $handler->display->display_options['filters']['title']['table'] = 'eck_badge';
  $handler->display->display_options['filters']['title']['field'] = 'title';
  $handler->display->display_options['filters']['title']['relationship'] = 'field_reward_badge_target_id';
  $handler->display->display_options['filters']['title']['value'] = '50 days of reading badge';
  $handler->display->display_options['path'] = 'admin/statistical-reports/home-library-completion-50';
  $handler->display->display_options['menu']['type'] = 'normal';
  $handler->display->display_options['menu']['title'] = '50 Day Completed By Home Library';
  $handler->display->display_options['menu']['weight'] = '0';
  $handler->display->display_options['menu']['name'] = 'menu-statistical-reports';
  $handler->display->display_options['menu']['context'] = 0;
  $handler->display->display_options['menu']['context_only_inline'] = 0;

  /* Display: Registrations By School */
  $handler = $view->new_display('page', 'Registrations By School', 'page_7');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Registrations by School';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'views_aggregator';
  $handler->display->display_options['style_options']['columns'] = array(
    'field_school' => 'field_school',
    'name' => 'name',
  );
  $handler->display->display_options['style_options']['default'] = '-1';
  $handler->display->display_options['style_options']['info'] = array(
    'field_school' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
      'has_aggr' => 1,
      'aggr' => array(
        'views_aggregator_group_and_compress' => 'views_aggregator_group_and_compress',
      ),
      'aggr_par' => '',
      'has_aggr_column' => 0,
      'aggr_column' => 'views_aggregator_sum',
      'aggr_par_column' => '',
    ),
    'name' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
      'has_aggr' => 1,
      'aggr' => array(
        'views_aggregator_count' => 'views_aggregator_count',
      ),
      'aggr_par' => '',
      'has_aggr_column' => 1,
      'aggr_column' => 'views_aggregator_count',
      'aggr_par_column' => '',
    ),
  );
  $handler->display->display_options['style_options']['column_aggregation']['totals_per_page'] = '0';
  $handler->display->display_options['style_options']['column_aggregation']['totals_row_position'] = array(
    1 => 0,
    2 => '2',
  );
  $handler->display->display_options['style_options']['column_aggregation']['precision'] = '2';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Profile: School */
  $handler->display->display_options['fields']['field_school']['id'] = 'field_school';
  $handler->display->display_options['fields']['field_school']['table'] = 'field_data_field_school';
  $handler->display->display_options['fields']['field_school']['field'] = 'field_school';
  $handler->display->display_options['fields']['field_school']['relationship'] = 'profile';
  $handler->display->display_options['fields']['field_school']['empty'] = 'No School';
  /* Field: User: Name */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'users';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['path'] = 'admin/statistical-reports/registrations-by-school';
  $handler->display->display_options['menu']['type'] = 'normal';
  $handler->display->display_options['menu']['title'] = 'Registrations By School';
  $handler->display->display_options['menu']['weight'] = '0';
  $handler->display->display_options['menu']['name'] = 'menu-statistical-reports';
  $handler->display->display_options['menu']['context'] = 0;
  $handler->display->display_options['menu']['context_only_inline'] = 0;

  /* Display: 10 Days School Completions */
  $handler = $view->new_display('page', '10 Days School Completions', 'page_8');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'School Completions, 10 Days';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'views_aggregator';
  $handler->display->display_options['style_options']['columns'] = array(
    'field_school' => 'field_school',
    'field_badge_image' => 'field_badge_image',
    'title' => 'title',
  );
  $handler->display->display_options['style_options']['default'] = '-1';
  $handler->display->display_options['style_options']['info'] = array(
    'field_school' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
      'has_aggr' => 1,
      'aggr' => array(
        'views_aggregator_group_and_compress' => 'views_aggregator_group_and_compress',
      ),
      'aggr_par' => '',
      'has_aggr_column' => 0,
      'aggr_column' => 'views_aggregator_sum',
      'aggr_par_column' => '',
    ),
    'field_badge_image' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
      'has_aggr' => 0,
      'aggr' => array(
        'views_aggregator_enumerate_raw' => 'views_aggregator_enumerate_raw',
      ),
      'aggr_par' => '',
      'has_aggr_column' => 0,
      'aggr_column' => 'views_aggregator_enumerate',
      'aggr_par_column' => '',
    ),
    'title' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
      'has_aggr' => 1,
      'aggr' => array(
        'views_aggregator_count' => 'views_aggregator_count',
      ),
      'aggr_par' => '',
      'has_aggr_column' => 1,
      'aggr_column' => 'views_aggregator_count',
      'aggr_par_column' => '',
    ),
  );
  $handler->display->display_options['style_options']['column_aggregation']['totals_per_page'] = '0';
  $handler->display->display_options['style_options']['column_aggregation']['totals_row_position'] = array(
    1 => 0,
    2 => '2',
  );
  $handler->display->display_options['style_options']['column_aggregation']['precision'] = '2';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  /* Relationship: User: Activity */
  $handler->display->display_options['relationships']['eck_activity']['id'] = 'eck_activity';
  $handler->display->display_options['relationships']['eck_activity']['table'] = 'users';
  $handler->display->display_options['relationships']['eck_activity']['field'] = 'eck_activity';
  /* Relationship: User: Profile */
  $handler->display->display_options['relationships']['profile']['id'] = 'profile';
  $handler->display->display_options['relationships']['profile']['table'] = 'users';
  $handler->display->display_options['relationships']['profile']['field'] = 'profile';
  $handler->display->display_options['relationships']['profile']['bundle_types'] = array(
    'main' => 'main',
  );
  /* Relationship: Profile: Library branch (field_library_branch) */
  $handler->display->display_options['relationships']['field_library_branch_tid']['id'] = 'field_library_branch_tid';
  $handler->display->display_options['relationships']['field_library_branch_tid']['table'] = 'field_data_field_library_branch';
  $handler->display->display_options['relationships']['field_library_branch_tid']['field'] = 'field_library_branch_tid';
  $handler->display->display_options['relationships']['field_library_branch_tid']['relationship'] = 'profile';
  /* Relationship: User: Reward */
  $handler->display->display_options['relationships']['eck_reward']['id'] = 'eck_reward';
  $handler->display->display_options['relationships']['eck_reward']['table'] = 'users';
  $handler->display->display_options['relationships']['eck_reward']['field'] = 'eck_reward';
  /* Relationship: Entity Reference: Referenced Entity */
  $handler->display->display_options['relationships']['field_reward_claim_id_target_id']['id'] = 'field_reward_claim_id_target_id';
  $handler->display->display_options['relationships']['field_reward_claim_id_target_id']['table'] = 'field_data_field_reward_claim_id';
  $handler->display->display_options['relationships']['field_reward_claim_id_target_id']['field'] = 'field_reward_claim_id_target_id';
  $handler->display->display_options['relationships']['field_reward_claim_id_target_id']['relationship'] = 'eck_reward';
  /* Relationship: Entity Reference: Referenced Entity */
  $handler->display->display_options['relationships']['field_reward_badge_target_id']['id'] = 'field_reward_badge_target_id';
  $handler->display->display_options['relationships']['field_reward_badge_target_id']['table'] = 'field_data_field_reward_badge';
  $handler->display->display_options['relationships']['field_reward_badge_target_id']['field'] = 'field_reward_badge_target_id';
  $handler->display->display_options['relationships']['field_reward_badge_target_id']['relationship'] = 'field_reward_claim_id_target_id';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Profile: School */
  $handler->display->display_options['fields']['field_school']['id'] = 'field_school';
  $handler->display->display_options['fields']['field_school']['table'] = 'field_data_field_school';
  $handler->display->display_options['fields']['field_school']['field'] = 'field_school';
  $handler->display->display_options['fields']['field_school']['relationship'] = 'profile';
  $handler->display->display_options['fields']['field_school']['empty'] = 'No School';
  /* Field: Badge: Badge Image */
  $handler->display->display_options['fields']['field_badge_image']['id'] = 'field_badge_image';
  $handler->display->display_options['fields']['field_badge_image']['table'] = 'field_data_field_badge_image';
  $handler->display->display_options['fields']['field_badge_image']['field'] = 'field_badge_image';
  $handler->display->display_options['fields']['field_badge_image']['relationship'] = 'field_reward_badge_target_id';
  $handler->display->display_options['fields']['field_badge_image']['label'] = '';
  $handler->display->display_options['fields']['field_badge_image']['exclude'] = TRUE;
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
  $handler->display->display_options['fields']['title']['relationship'] = 'field_reward_badge_target_id';
  $handler->display->display_options['fields']['title']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['title']['alter']['text'] = '[field_badge_image]</br>
[title]';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: User: Active */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'users';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = '1';
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: User: Roles */
  $handler->display->display_options['filters']['rid']['id'] = 'rid';
  $handler->display->display_options['filters']['rid']['table'] = 'users_roles';
  $handler->display->display_options['filters']['rid']['field'] = 'rid';
  $handler->display->display_options['filters']['rid']['value'] = array(
    6 => '6',
  );
  /* Filter criterion: Badge: Title */
  $handler->display->display_options['filters']['title']['id'] = 'title';
  $handler->display->display_options['filters']['title']['table'] = 'eck_badge';
  $handler->display->display_options['filters']['title']['field'] = 'title';
  $handler->display->display_options['filters']['title']['relationship'] = 'field_reward_badge_target_id';
  $handler->display->display_options['filters']['title']['value'] = '10 days of reading badge';
  $handler->display->display_options['path'] = 'admin/statistical-reports/school-completion-10';
  $handler->display->display_options['menu']['type'] = 'normal';
  $handler->display->display_options['menu']['title'] = '10 Day Completed By School';
  $handler->display->display_options['menu']['weight'] = '0';
  $handler->display->display_options['menu']['name'] = 'menu-statistical-reports';
  $handler->display->display_options['menu']['context'] = 0;
  $handler->display->display_options['menu']['context_only_inline'] = 0;

  /* Display: 20 Days School Completions */
  $handler = $view->new_display('page', '20 Days School Completions', 'page_9');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'School Completions, 20 Days';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'views_aggregator';
  $handler->display->display_options['style_options']['columns'] = array(
    'field_school' => 'field_school',
    'field_badge_image' => 'field_badge_image',
    'title' => 'title',
  );
  $handler->display->display_options['style_options']['default'] = '-1';
  $handler->display->display_options['style_options']['info'] = array(
    'field_school' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
      'has_aggr' => 1,
      'aggr' => array(
        'views_aggregator_group_and_compress' => 'views_aggregator_group_and_compress',
      ),
      'aggr_par' => '',
      'has_aggr_column' => 0,
      'aggr_column' => 'views_aggregator_sum',
      'aggr_par_column' => '',
    ),
    'field_badge_image' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
      'has_aggr' => 0,
      'aggr' => array(
        'views_aggregator_enumerate_raw' => 'views_aggregator_enumerate_raw',
      ),
      'aggr_par' => '',
      'has_aggr_column' => 0,
      'aggr_column' => 'views_aggregator_enumerate',
      'aggr_par_column' => '',
    ),
    'title' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
      'has_aggr' => 1,
      'aggr' => array(
        'views_aggregator_count' => 'views_aggregator_count',
      ),
      'aggr_par' => '',
      'has_aggr_column' => 1,
      'aggr_column' => 'views_aggregator_count',
      'aggr_par_column' => '',
    ),
  );
  $handler->display->display_options['style_options']['column_aggregation']['totals_per_page'] = '0';
  $handler->display->display_options['style_options']['column_aggregation']['totals_row_position'] = array(
    1 => 0,
    2 => '2',
  );
  $handler->display->display_options['style_options']['column_aggregation']['precision'] = '2';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  /* Relationship: User: Activity */
  $handler->display->display_options['relationships']['eck_activity']['id'] = 'eck_activity';
  $handler->display->display_options['relationships']['eck_activity']['table'] = 'users';
  $handler->display->display_options['relationships']['eck_activity']['field'] = 'eck_activity';
  /* Relationship: User: Profile */
  $handler->display->display_options['relationships']['profile']['id'] = 'profile';
  $handler->display->display_options['relationships']['profile']['table'] = 'users';
  $handler->display->display_options['relationships']['profile']['field'] = 'profile';
  $handler->display->display_options['relationships']['profile']['bundle_types'] = array(
    'main' => 'main',
  );
  /* Relationship: Profile: Library branch (field_library_branch) */
  $handler->display->display_options['relationships']['field_library_branch_tid']['id'] = 'field_library_branch_tid';
  $handler->display->display_options['relationships']['field_library_branch_tid']['table'] = 'field_data_field_library_branch';
  $handler->display->display_options['relationships']['field_library_branch_tid']['field'] = 'field_library_branch_tid';
  $handler->display->display_options['relationships']['field_library_branch_tid']['relationship'] = 'profile';
  /* Relationship: User: Reward */
  $handler->display->display_options['relationships']['eck_reward']['id'] = 'eck_reward';
  $handler->display->display_options['relationships']['eck_reward']['table'] = 'users';
  $handler->display->display_options['relationships']['eck_reward']['field'] = 'eck_reward';
  /* Relationship: Entity Reference: Referenced Entity */
  $handler->display->display_options['relationships']['field_reward_claim_id_target_id']['id'] = 'field_reward_claim_id_target_id';
  $handler->display->display_options['relationships']['field_reward_claim_id_target_id']['table'] = 'field_data_field_reward_claim_id';
  $handler->display->display_options['relationships']['field_reward_claim_id_target_id']['field'] = 'field_reward_claim_id_target_id';
  $handler->display->display_options['relationships']['field_reward_claim_id_target_id']['relationship'] = 'eck_reward';
  /* Relationship: Entity Reference: Referenced Entity */
  $handler->display->display_options['relationships']['field_reward_badge_target_id']['id'] = 'field_reward_badge_target_id';
  $handler->display->display_options['relationships']['field_reward_badge_target_id']['table'] = 'field_data_field_reward_badge';
  $handler->display->display_options['relationships']['field_reward_badge_target_id']['field'] = 'field_reward_badge_target_id';
  $handler->display->display_options['relationships']['field_reward_badge_target_id']['relationship'] = 'field_reward_claim_id_target_id';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Profile: School */
  $handler->display->display_options['fields']['field_school']['id'] = 'field_school';
  $handler->display->display_options['fields']['field_school']['table'] = 'field_data_field_school';
  $handler->display->display_options['fields']['field_school']['field'] = 'field_school';
  $handler->display->display_options['fields']['field_school']['relationship'] = 'profile';
  $handler->display->display_options['fields']['field_school']['empty'] = 'No School';
  /* Field: Badge: Badge Image */
  $handler->display->display_options['fields']['field_badge_image']['id'] = 'field_badge_image';
  $handler->display->display_options['fields']['field_badge_image']['table'] = 'field_data_field_badge_image';
  $handler->display->display_options['fields']['field_badge_image']['field'] = 'field_badge_image';
  $handler->display->display_options['fields']['field_badge_image']['relationship'] = 'field_reward_badge_target_id';
  $handler->display->display_options['fields']['field_badge_image']['label'] = '';
  $handler->display->display_options['fields']['field_badge_image']['exclude'] = TRUE;
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
  $handler->display->display_options['fields']['title']['relationship'] = 'field_reward_badge_target_id';
  $handler->display->display_options['fields']['title']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['title']['alter']['text'] = '[field_badge_image]</br>
[title]';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: User: Active */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'users';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = '1';
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: User: Roles */
  $handler->display->display_options['filters']['rid']['id'] = 'rid';
  $handler->display->display_options['filters']['rid']['table'] = 'users_roles';
  $handler->display->display_options['filters']['rid']['field'] = 'rid';
  $handler->display->display_options['filters']['rid']['value'] = array(
    6 => '6',
  );
  /* Filter criterion: Badge: Title */
  $handler->display->display_options['filters']['title']['id'] = 'title';
  $handler->display->display_options['filters']['title']['table'] = 'eck_badge';
  $handler->display->display_options['filters']['title']['field'] = 'title';
  $handler->display->display_options['filters']['title']['relationship'] = 'field_reward_badge_target_id';
  $handler->display->display_options['filters']['title']['value'] = '20 days of reading badge';
  $handler->display->display_options['path'] = 'admin/statistical-reports/school-completion-20';
  $handler->display->display_options['menu']['type'] = 'normal';
  $handler->display->display_options['menu']['title'] = '20 Day Completed By School';
  $handler->display->display_options['menu']['weight'] = '0';
  $handler->display->display_options['menu']['name'] = 'menu-statistical-reports';
  $handler->display->display_options['menu']['context'] = 0;
  $handler->display->display_options['menu']['context_only_inline'] = 0;

  /* Display: 30 Days School Completions */
  $handler = $view->new_display('page', '30 Days School Completions', 'page_10');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'School Completions, 30 Days';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'views_aggregator';
  $handler->display->display_options['style_options']['columns'] = array(
    'field_school' => 'field_school',
    'field_badge_image' => 'field_badge_image',
    'title' => 'title',
  );
  $handler->display->display_options['style_options']['default'] = '-1';
  $handler->display->display_options['style_options']['info'] = array(
    'field_school' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
      'has_aggr' => 1,
      'aggr' => array(
        'views_aggregator_group_and_compress' => 'views_aggregator_group_and_compress',
      ),
      'aggr_par' => '',
      'has_aggr_column' => 0,
      'aggr_column' => 'views_aggregator_sum',
      'aggr_par_column' => '',
    ),
    'field_badge_image' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
      'has_aggr' => 0,
      'aggr' => array(
        'views_aggregator_enumerate_raw' => 'views_aggregator_enumerate_raw',
      ),
      'aggr_par' => '',
      'has_aggr_column' => 0,
      'aggr_column' => 'views_aggregator_enumerate',
      'aggr_par_column' => '',
    ),
    'title' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
      'has_aggr' => 1,
      'aggr' => array(
        'views_aggregator_count' => 'views_aggregator_count',
      ),
      'aggr_par' => '',
      'has_aggr_column' => 1,
      'aggr_column' => 'views_aggregator_count',
      'aggr_par_column' => '',
    ),
  );
  $handler->display->display_options['style_options']['column_aggregation']['totals_per_page'] = '0';
  $handler->display->display_options['style_options']['column_aggregation']['totals_row_position'] = array(
    1 => 0,
    2 => '2',
  );
  $handler->display->display_options['style_options']['column_aggregation']['precision'] = '2';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  /* Relationship: User: Activity */
  $handler->display->display_options['relationships']['eck_activity']['id'] = 'eck_activity';
  $handler->display->display_options['relationships']['eck_activity']['table'] = 'users';
  $handler->display->display_options['relationships']['eck_activity']['field'] = 'eck_activity';
  /* Relationship: User: Profile */
  $handler->display->display_options['relationships']['profile']['id'] = 'profile';
  $handler->display->display_options['relationships']['profile']['table'] = 'users';
  $handler->display->display_options['relationships']['profile']['field'] = 'profile';
  $handler->display->display_options['relationships']['profile']['bundle_types'] = array(
    'main' => 'main',
  );
  /* Relationship: Profile: Library branch (field_library_branch) */
  $handler->display->display_options['relationships']['field_library_branch_tid']['id'] = 'field_library_branch_tid';
  $handler->display->display_options['relationships']['field_library_branch_tid']['table'] = 'field_data_field_library_branch';
  $handler->display->display_options['relationships']['field_library_branch_tid']['field'] = 'field_library_branch_tid';
  $handler->display->display_options['relationships']['field_library_branch_tid']['relationship'] = 'profile';
  /* Relationship: User: Reward */
  $handler->display->display_options['relationships']['eck_reward']['id'] = 'eck_reward';
  $handler->display->display_options['relationships']['eck_reward']['table'] = 'users';
  $handler->display->display_options['relationships']['eck_reward']['field'] = 'eck_reward';
  /* Relationship: Entity Reference: Referenced Entity */
  $handler->display->display_options['relationships']['field_reward_claim_id_target_id']['id'] = 'field_reward_claim_id_target_id';
  $handler->display->display_options['relationships']['field_reward_claim_id_target_id']['table'] = 'field_data_field_reward_claim_id';
  $handler->display->display_options['relationships']['field_reward_claim_id_target_id']['field'] = 'field_reward_claim_id_target_id';
  $handler->display->display_options['relationships']['field_reward_claim_id_target_id']['relationship'] = 'eck_reward';
  /* Relationship: Entity Reference: Referenced Entity */
  $handler->display->display_options['relationships']['field_reward_badge_target_id']['id'] = 'field_reward_badge_target_id';
  $handler->display->display_options['relationships']['field_reward_badge_target_id']['table'] = 'field_data_field_reward_badge';
  $handler->display->display_options['relationships']['field_reward_badge_target_id']['field'] = 'field_reward_badge_target_id';
  $handler->display->display_options['relationships']['field_reward_badge_target_id']['relationship'] = 'field_reward_claim_id_target_id';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Profile: School */
  $handler->display->display_options['fields']['field_school']['id'] = 'field_school';
  $handler->display->display_options['fields']['field_school']['table'] = 'field_data_field_school';
  $handler->display->display_options['fields']['field_school']['field'] = 'field_school';
  $handler->display->display_options['fields']['field_school']['relationship'] = 'profile';
  $handler->display->display_options['fields']['field_school']['empty'] = 'No School';
  /* Field: Badge: Badge Image */
  $handler->display->display_options['fields']['field_badge_image']['id'] = 'field_badge_image';
  $handler->display->display_options['fields']['field_badge_image']['table'] = 'field_data_field_badge_image';
  $handler->display->display_options['fields']['field_badge_image']['field'] = 'field_badge_image';
  $handler->display->display_options['fields']['field_badge_image']['relationship'] = 'field_reward_badge_target_id';
  $handler->display->display_options['fields']['field_badge_image']['label'] = '';
  $handler->display->display_options['fields']['field_badge_image']['exclude'] = TRUE;
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
  $handler->display->display_options['fields']['title']['relationship'] = 'field_reward_badge_target_id';
  $handler->display->display_options['fields']['title']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['title']['alter']['text'] = '[field_badge_image]</br>
[title]';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: User: Active */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'users';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = '1';
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: User: Roles */
  $handler->display->display_options['filters']['rid']['id'] = 'rid';
  $handler->display->display_options['filters']['rid']['table'] = 'users_roles';
  $handler->display->display_options['filters']['rid']['field'] = 'rid';
  $handler->display->display_options['filters']['rid']['value'] = array(
    6 => '6',
  );
  /* Filter criterion: Badge: Title */
  $handler->display->display_options['filters']['title']['id'] = 'title';
  $handler->display->display_options['filters']['title']['table'] = 'eck_badge';
  $handler->display->display_options['filters']['title']['field'] = 'title';
  $handler->display->display_options['filters']['title']['relationship'] = 'field_reward_badge_target_id';
  $handler->display->display_options['filters']['title']['value'] = '30 days of reading badge';
  $handler->display->display_options['path'] = 'admin/statistical-reports/school-completion-30';
  $handler->display->display_options['menu']['type'] = 'normal';
  $handler->display->display_options['menu']['title'] = '30 Day Completed By School';
  $handler->display->display_options['menu']['weight'] = '0';
  $handler->display->display_options['menu']['name'] = 'menu-statistical-reports';
  $handler->display->display_options['menu']['context'] = 0;
  $handler->display->display_options['menu']['context_only_inline'] = 0;

  /* Display: 40 Days School Completions */
  $handler = $view->new_display('page', '40 Days School Completions', 'page_11');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'School Completions, 40 Days';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'views_aggregator';
  $handler->display->display_options['style_options']['columns'] = array(
    'field_school' => 'field_school',
    'field_badge_image' => 'field_badge_image',
    'title' => 'title',
  );
  $handler->display->display_options['style_options']['default'] = '-1';
  $handler->display->display_options['style_options']['info'] = array(
    'field_school' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
      'has_aggr' => 1,
      'aggr' => array(
        'views_aggregator_group_and_compress' => 'views_aggregator_group_and_compress',
      ),
      'aggr_par' => '',
      'has_aggr_column' => 0,
      'aggr_column' => 'views_aggregator_sum',
      'aggr_par_column' => '',
    ),
    'field_badge_image' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
      'has_aggr' => 0,
      'aggr' => array(
        'views_aggregator_enumerate_raw' => 'views_aggregator_enumerate_raw',
      ),
      'aggr_par' => '',
      'has_aggr_column' => 0,
      'aggr_column' => 'views_aggregator_enumerate',
      'aggr_par_column' => '',
    ),
    'title' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
      'has_aggr' => 1,
      'aggr' => array(
        'views_aggregator_count' => 'views_aggregator_count',
      ),
      'aggr_par' => '',
      'has_aggr_column' => 1,
      'aggr_column' => 'views_aggregator_count',
      'aggr_par_column' => '',
    ),
  );
  $handler->display->display_options['style_options']['column_aggregation']['totals_per_page'] = '0';
  $handler->display->display_options['style_options']['column_aggregation']['totals_row_position'] = array(
    1 => 0,
    2 => '2',
  );
  $handler->display->display_options['style_options']['column_aggregation']['precision'] = '2';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  /* Relationship: User: Activity */
  $handler->display->display_options['relationships']['eck_activity']['id'] = 'eck_activity';
  $handler->display->display_options['relationships']['eck_activity']['table'] = 'users';
  $handler->display->display_options['relationships']['eck_activity']['field'] = 'eck_activity';
  /* Relationship: User: Profile */
  $handler->display->display_options['relationships']['profile']['id'] = 'profile';
  $handler->display->display_options['relationships']['profile']['table'] = 'users';
  $handler->display->display_options['relationships']['profile']['field'] = 'profile';
  $handler->display->display_options['relationships']['profile']['bundle_types'] = array(
    'main' => 'main',
  );
  /* Relationship: Profile: Library branch (field_library_branch) */
  $handler->display->display_options['relationships']['field_library_branch_tid']['id'] = 'field_library_branch_tid';
  $handler->display->display_options['relationships']['field_library_branch_tid']['table'] = 'field_data_field_library_branch';
  $handler->display->display_options['relationships']['field_library_branch_tid']['field'] = 'field_library_branch_tid';
  $handler->display->display_options['relationships']['field_library_branch_tid']['relationship'] = 'profile';
  /* Relationship: User: Reward */
  $handler->display->display_options['relationships']['eck_reward']['id'] = 'eck_reward';
  $handler->display->display_options['relationships']['eck_reward']['table'] = 'users';
  $handler->display->display_options['relationships']['eck_reward']['field'] = 'eck_reward';
  /* Relationship: Entity Reference: Referenced Entity */
  $handler->display->display_options['relationships']['field_reward_claim_id_target_id']['id'] = 'field_reward_claim_id_target_id';
  $handler->display->display_options['relationships']['field_reward_claim_id_target_id']['table'] = 'field_data_field_reward_claim_id';
  $handler->display->display_options['relationships']['field_reward_claim_id_target_id']['field'] = 'field_reward_claim_id_target_id';
  $handler->display->display_options['relationships']['field_reward_claim_id_target_id']['relationship'] = 'eck_reward';
  /* Relationship: Entity Reference: Referenced Entity */
  $handler->display->display_options['relationships']['field_reward_badge_target_id']['id'] = 'field_reward_badge_target_id';
  $handler->display->display_options['relationships']['field_reward_badge_target_id']['table'] = 'field_data_field_reward_badge';
  $handler->display->display_options['relationships']['field_reward_badge_target_id']['field'] = 'field_reward_badge_target_id';
  $handler->display->display_options['relationships']['field_reward_badge_target_id']['relationship'] = 'field_reward_claim_id_target_id';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Profile: School */
  $handler->display->display_options['fields']['field_school']['id'] = 'field_school';
  $handler->display->display_options['fields']['field_school']['table'] = 'field_data_field_school';
  $handler->display->display_options['fields']['field_school']['field'] = 'field_school';
  $handler->display->display_options['fields']['field_school']['relationship'] = 'profile';
  $handler->display->display_options['fields']['field_school']['empty'] = 'No School';
  /* Field: Badge: Badge Image */
  $handler->display->display_options['fields']['field_badge_image']['id'] = 'field_badge_image';
  $handler->display->display_options['fields']['field_badge_image']['table'] = 'field_data_field_badge_image';
  $handler->display->display_options['fields']['field_badge_image']['field'] = 'field_badge_image';
  $handler->display->display_options['fields']['field_badge_image']['relationship'] = 'field_reward_badge_target_id';
  $handler->display->display_options['fields']['field_badge_image']['label'] = '';
  $handler->display->display_options['fields']['field_badge_image']['exclude'] = TRUE;
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
  $handler->display->display_options['fields']['title']['relationship'] = 'field_reward_badge_target_id';
  $handler->display->display_options['fields']['title']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['title']['alter']['text'] = '[field_badge_image]</br>
[title]';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: User: Active */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'users';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = '1';
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: User: Roles */
  $handler->display->display_options['filters']['rid']['id'] = 'rid';
  $handler->display->display_options['filters']['rid']['table'] = 'users_roles';
  $handler->display->display_options['filters']['rid']['field'] = 'rid';
  $handler->display->display_options['filters']['rid']['value'] = array(
    6 => '6',
  );
  /* Filter criterion: Badge: Title */
  $handler->display->display_options['filters']['title']['id'] = 'title';
  $handler->display->display_options['filters']['title']['table'] = 'eck_badge';
  $handler->display->display_options['filters']['title']['field'] = 'title';
  $handler->display->display_options['filters']['title']['relationship'] = 'field_reward_badge_target_id';
  $handler->display->display_options['filters']['title']['value'] = '40 days of reading badge';
  $handler->display->display_options['path'] = 'admin/statistical-reports/school-completion-40';
  $handler->display->display_options['menu']['type'] = 'normal';
  $handler->display->display_options['menu']['title'] = '40 Day Completed By School';
  $handler->display->display_options['menu']['weight'] = '0';
  $handler->display->display_options['menu']['name'] = 'menu-statistical-reports';
  $handler->display->display_options['menu']['context'] = 0;
  $handler->display->display_options['menu']['context_only_inline'] = 0;

  /* Display: 50 Days School Completions */
  $handler = $view->new_display('page', '50 Days School Completions', 'page_12');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'School Completions, 50 Days';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'views_aggregator';
  $handler->display->display_options['style_options']['columns'] = array(
    'field_school' => 'field_school',
    'field_badge_image' => 'field_badge_image',
    'title' => 'title',
  );
  $handler->display->display_options['style_options']['default'] = '-1';
  $handler->display->display_options['style_options']['info'] = array(
    'field_school' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
      'has_aggr' => 1,
      'aggr' => array(
        'views_aggregator_group_and_compress' => 'views_aggregator_group_and_compress',
      ),
      'aggr_par' => '',
      'has_aggr_column' => 0,
      'aggr_column' => 'views_aggregator_sum',
      'aggr_par_column' => '',
    ),
    'field_badge_image' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
      'has_aggr' => 0,
      'aggr' => array(
        'views_aggregator_enumerate_raw' => 'views_aggregator_enumerate_raw',
      ),
      'aggr_par' => '',
      'has_aggr_column' => 0,
      'aggr_column' => 'views_aggregator_enumerate',
      'aggr_par_column' => '',
    ),
    'title' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
      'has_aggr' => 1,
      'aggr' => array(
        'views_aggregator_count' => 'views_aggregator_count',
      ),
      'aggr_par' => '',
      'has_aggr_column' => 1,
      'aggr_column' => 'views_aggregator_count',
      'aggr_par_column' => '',
    ),
  );
  $handler->display->display_options['style_options']['column_aggregation']['totals_per_page'] = '0';
  $handler->display->display_options['style_options']['column_aggregation']['totals_row_position'] = array(
    1 => 0,
    2 => '2',
  );
  $handler->display->display_options['style_options']['column_aggregation']['precision'] = '2';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  /* Relationship: User: Activity */
  $handler->display->display_options['relationships']['eck_activity']['id'] = 'eck_activity';
  $handler->display->display_options['relationships']['eck_activity']['table'] = 'users';
  $handler->display->display_options['relationships']['eck_activity']['field'] = 'eck_activity';
  /* Relationship: User: Profile */
  $handler->display->display_options['relationships']['profile']['id'] = 'profile';
  $handler->display->display_options['relationships']['profile']['table'] = 'users';
  $handler->display->display_options['relationships']['profile']['field'] = 'profile';
  $handler->display->display_options['relationships']['profile']['bundle_types'] = array(
    'main' => 'main',
  );
  /* Relationship: Profile: Library branch (field_library_branch) */
  $handler->display->display_options['relationships']['field_library_branch_tid']['id'] = 'field_library_branch_tid';
  $handler->display->display_options['relationships']['field_library_branch_tid']['table'] = 'field_data_field_library_branch';
  $handler->display->display_options['relationships']['field_library_branch_tid']['field'] = 'field_library_branch_tid';
  $handler->display->display_options['relationships']['field_library_branch_tid']['relationship'] = 'profile';
  /* Relationship: User: Reward */
  $handler->display->display_options['relationships']['eck_reward']['id'] = 'eck_reward';
  $handler->display->display_options['relationships']['eck_reward']['table'] = 'users';
  $handler->display->display_options['relationships']['eck_reward']['field'] = 'eck_reward';
  /* Relationship: Entity Reference: Referenced Entity */
  $handler->display->display_options['relationships']['field_reward_claim_id_target_id']['id'] = 'field_reward_claim_id_target_id';
  $handler->display->display_options['relationships']['field_reward_claim_id_target_id']['table'] = 'field_data_field_reward_claim_id';
  $handler->display->display_options['relationships']['field_reward_claim_id_target_id']['field'] = 'field_reward_claim_id_target_id';
  $handler->display->display_options['relationships']['field_reward_claim_id_target_id']['relationship'] = 'eck_reward';
  /* Relationship: Entity Reference: Referenced Entity */
  $handler->display->display_options['relationships']['field_reward_badge_target_id']['id'] = 'field_reward_badge_target_id';
  $handler->display->display_options['relationships']['field_reward_badge_target_id']['table'] = 'field_data_field_reward_badge';
  $handler->display->display_options['relationships']['field_reward_badge_target_id']['field'] = 'field_reward_badge_target_id';
  $handler->display->display_options['relationships']['field_reward_badge_target_id']['relationship'] = 'field_reward_claim_id_target_id';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Profile: School */
  $handler->display->display_options['fields']['field_school']['id'] = 'field_school';
  $handler->display->display_options['fields']['field_school']['table'] = 'field_data_field_school';
  $handler->display->display_options['fields']['field_school']['field'] = 'field_school';
  $handler->display->display_options['fields']['field_school']['relationship'] = 'profile';
  $handler->display->display_options['fields']['field_school']['empty'] = 'No School';
  /* Field: Badge: Badge Image */
  $handler->display->display_options['fields']['field_badge_image']['id'] = 'field_badge_image';
  $handler->display->display_options['fields']['field_badge_image']['table'] = 'field_data_field_badge_image';
  $handler->display->display_options['fields']['field_badge_image']['field'] = 'field_badge_image';
  $handler->display->display_options['fields']['field_badge_image']['relationship'] = 'field_reward_badge_target_id';
  $handler->display->display_options['fields']['field_badge_image']['label'] = '';
  $handler->display->display_options['fields']['field_badge_image']['exclude'] = TRUE;
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
  $handler->display->display_options['fields']['title']['relationship'] = 'field_reward_badge_target_id';
  $handler->display->display_options['fields']['title']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['title']['alter']['text'] = '[field_badge_image]</br>
[title]';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: User: Active */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'users';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = '1';
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: User: Roles */
  $handler->display->display_options['filters']['rid']['id'] = 'rid';
  $handler->display->display_options['filters']['rid']['table'] = 'users_roles';
  $handler->display->display_options['filters']['rid']['field'] = 'rid';
  $handler->display->display_options['filters']['rid']['value'] = array(
    6 => '6',
  );
  /* Filter criterion: Badge: Title */
  $handler->display->display_options['filters']['title']['id'] = 'title';
  $handler->display->display_options['filters']['title']['table'] = 'eck_badge';
  $handler->display->display_options['filters']['title']['field'] = 'title';
  $handler->display->display_options['filters']['title']['relationship'] = 'field_reward_badge_target_id';
  $handler->display->display_options['filters']['title']['value'] = '50 days of reading badge';
  $handler->display->display_options['path'] = 'admin/statistical-reports/school-completion-50';
  $handler->display->display_options['menu']['type'] = 'normal';
  $handler->display->display_options['menu']['title'] = '50 Day Completed By School';
  $handler->display->display_options['menu']['weight'] = '0';
  $handler->display->display_options['menu']['name'] = 'menu-statistical-reports';
  $handler->display->display_options['menu']['context'] = 0;
  $handler->display->display_options['menu']['context_only_inline'] = 0;

  /* Display: Users By School */
  $handler = $view->new_display('page', 'Users By School', 'page_13');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Users By School';
  $handler->display->display_options['defaults']['group_by'] = FALSE;
  $handler->display->display_options['defaults']['query'] = FALSE;
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['distinct'] = TRUE;
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['grouping'] = array(
    0 => array(
      'field' => 'field_school',
      'rendered' => 1,
      'rendered_strip' => 0,
    ),
  );
  $handler->display->display_options['style_options']['columns'] = array(
    'field_school' => 'field_school',
    'field_user_first_name' => 'field_user_first_name',
    'field_user_middle_initial' => 'field_user_middle_initial',
    'field_user_last_name' => 'field_user_last_name',
    'field_user_birthday' => 'field_user_birthday',
    'mail' => 'mail',
    'field_library_card_number' => 'field_library_card_number',
    'field_library_branch' => 'field_library_branch',
    'title' => 'title',
  );
  $handler->display->display_options['style_options']['default'] = 'field_user_last_name';
  $handler->display->display_options['style_options']['info'] = array(
    'field_school' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => 'views-align-left',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_user_first_name' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_user_middle_initial' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_user_last_name' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_user_birthday' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'mail' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_library_card_number' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_library_branch' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'title' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  /* Relationship: User: Activity */
  $handler->display->display_options['relationships']['eck_activity']['id'] = 'eck_activity';
  $handler->display->display_options['relationships']['eck_activity']['table'] = 'users';
  $handler->display->display_options['relationships']['eck_activity']['field'] = 'eck_activity';
  /* Relationship: User: Badge */
  $handler->display->display_options['relationships']['eck_badge']['id'] = 'eck_badge';
  $handler->display->display_options['relationships']['eck_badge']['table'] = 'users';
  $handler->display->display_options['relationships']['eck_badge']['field'] = 'eck_badge';
  /* Relationship: User: Profile */
  $handler->display->display_options['relationships']['profile']['id'] = 'profile';
  $handler->display->display_options['relationships']['profile']['table'] = 'users';
  $handler->display->display_options['relationships']['profile']['field'] = 'profile';
  $handler->display->display_options['relationships']['profile']['bundle_types'] = array(
    'main' => 'main',
  );
  /* Relationship: User: Raffle */
  $handler->display->display_options['relationships']['eck_raffle']['id'] = 'eck_raffle';
  $handler->display->display_options['relationships']['eck_raffle']['table'] = 'users';
  $handler->display->display_options['relationships']['eck_raffle']['field'] = 'eck_raffle';
  /* Relationship: User: Reward */
  $handler->display->display_options['relationships']['eck_reward']['id'] = 'eck_reward';
  $handler->display->display_options['relationships']['eck_reward']['table'] = 'users';
  $handler->display->display_options['relationships']['eck_reward']['field'] = 'eck_reward';
  /* Relationship: Profile: Library branch (field_library_branch) */
  $handler->display->display_options['relationships']['field_library_branch_tid']['id'] = 'field_library_branch_tid';
  $handler->display->display_options['relationships']['field_library_branch_tid']['table'] = 'field_data_field_library_branch';
  $handler->display->display_options['relationships']['field_library_branch_tid']['field'] = 'field_library_branch_tid';
  $handler->display->display_options['relationships']['field_library_branch_tid']['relationship'] = 'profile';
  /* Relationship: Entity Reference: Referenced Entity */
  $handler->display->display_options['relationships']['field_reward_claim_id_target_id']['id'] = 'field_reward_claim_id_target_id';
  $handler->display->display_options['relationships']['field_reward_claim_id_target_id']['table'] = 'field_data_field_reward_claim_id';
  $handler->display->display_options['relationships']['field_reward_claim_id_target_id']['field'] = 'field_reward_claim_id_target_id';
  $handler->display->display_options['relationships']['field_reward_claim_id_target_id']['relationship'] = 'eck_reward';
  /* Relationship: Entity Reference: Referenced Entity */
  $handler->display->display_options['relationships']['field_reward_badge_target_id']['id'] = 'field_reward_badge_target_id';
  $handler->display->display_options['relationships']['field_reward_badge_target_id']['table'] = 'field_data_field_reward_badge';
  $handler->display->display_options['relationships']['field_reward_badge_target_id']['field'] = 'field_reward_badge_target_id';
  $handler->display->display_options['relationships']['field_reward_badge_target_id']['relationship'] = 'eck_reward';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Profile: School */
  $handler->display->display_options['fields']['field_school']['id'] = 'field_school';
  $handler->display->display_options['fields']['field_school']['table'] = 'field_data_field_school';
  $handler->display->display_options['fields']['field_school']['field'] = 'field_school';
  $handler->display->display_options['fields']['field_school']['relationship'] = 'profile';
  $handler->display->display_options['fields']['field_school']['label'] = '';
  $handler->display->display_options['fields']['field_school']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_school']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_school']['empty'] = 'No School';
  /* Field: User: Uid */
  $handler->display->display_options['fields']['uid']['id'] = 'uid';
  $handler->display->display_options['fields']['uid']['table'] = 'users';
  $handler->display->display_options['fields']['uid']['field'] = 'uid';
  $handler->display->display_options['fields']['uid']['exclude'] = TRUE;
  /* Field: Profile: First name */
  $handler->display->display_options['fields']['field_user_first_name']['id'] = 'field_user_first_name';
  $handler->display->display_options['fields']['field_user_first_name']['table'] = 'field_data_field_user_first_name';
  $handler->display->display_options['fields']['field_user_first_name']['field'] = 'field_user_first_name';
  $handler->display->display_options['fields']['field_user_first_name']['relationship'] = 'profile';
  $handler->display->display_options['fields']['field_user_first_name']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_user_first_name']['hide_empty'] = TRUE;
  /* Field: Profile: Middle initial */
  $handler->display->display_options['fields']['field_user_middle_initial']['id'] = 'field_user_middle_initial';
  $handler->display->display_options['fields']['field_user_middle_initial']['table'] = 'field_data_field_user_middle_initial';
  $handler->display->display_options['fields']['field_user_middle_initial']['field'] = 'field_user_middle_initial';
  $handler->display->display_options['fields']['field_user_middle_initial']['relationship'] = 'profile';
  $handler->display->display_options['fields']['field_user_middle_initial']['exclude'] = TRUE;
  /* Field: Profile: Last name */
  $handler->display->display_options['fields']['field_user_last_name']['id'] = 'field_user_last_name';
  $handler->display->display_options['fields']['field_user_last_name']['table'] = 'field_data_field_user_last_name';
  $handler->display->display_options['fields']['field_user_last_name']['field'] = 'field_user_last_name';
  $handler->display->display_options['fields']['field_user_last_name']['relationship'] = 'profile';
  $handler->display->display_options['fields']['field_user_last_name']['label'] = 'Name';
  $handler->display->display_options['fields']['field_user_last_name']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_user_last_name']['alter']['text'] = '[field_user_last_name], [field_user_first_name] [field_user_middle_initial]';
  $handler->display->display_options['fields']['field_user_last_name']['hide_empty'] = TRUE;
  /* Field: Profile: Date of Birth */
  $handler->display->display_options['fields']['field_user_birthday']['id'] = 'field_user_birthday';
  $handler->display->display_options['fields']['field_user_birthday']['table'] = 'field_data_field_user_birthday';
  $handler->display->display_options['fields']['field_user_birthday']['field'] = 'field_user_birthday';
  $handler->display->display_options['fields']['field_user_birthday']['relationship'] = 'profile';
  $handler->display->display_options['fields']['field_user_birthday']['settings'] = array(
    'format_type' => 'privatemsg_years',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
    'show_remaining_days' => 0,
  );
  /* Field: User: E-mail */
  $handler->display->display_options['fields']['mail']['id'] = 'mail';
  $handler->display->display_options['fields']['mail']['table'] = 'users';
  $handler->display->display_options['fields']['mail']['field'] = 'mail';
  $handler->display->display_options['fields']['mail']['link_to_user'] = '0';
  /* Field: User: Name */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'users';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  /* Field: Profile: Library card number */
  $handler->display->display_options['fields']['field_library_card_number']['id'] = 'field_library_card_number';
  $handler->display->display_options['fields']['field_library_card_number']['table'] = 'field_data_field_library_card_number';
  $handler->display->display_options['fields']['field_library_card_number']['field'] = 'field_library_card_number';
  $handler->display->display_options['fields']['field_library_card_number']['relationship'] = 'profile';
  $handler->display->display_options['fields']['field_library_card_number']['type'] = 'text_plain';
  /* Field: Profile: Library branch */
  $handler->display->display_options['fields']['field_library_branch']['id'] = 'field_library_branch';
  $handler->display->display_options['fields']['field_library_branch']['table'] = 'field_data_field_library_branch';
  $handler->display->display_options['fields']['field_library_branch']['field'] = 'field_library_branch';
  $handler->display->display_options['fields']['field_library_branch']['relationship'] = 'profile';
  /* Field: Badge: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'eck_badge';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['relationship'] = 'eck_badge';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: User: Active */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'users';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = '1';
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: User: Roles */
  $handler->display->display_options['filters']['rid']['id'] = 'rid';
  $handler->display->display_options['filters']['rid']['table'] = 'users_roles';
  $handler->display->display_options['filters']['rid']['field'] = 'rid';
  $handler->display->display_options['filters']['rid']['value'] = array(
    6 => '6',
  );
  /* Filter criterion: Profile: First name (field_user_first_name) */
  $handler->display->display_options['filters']['field_user_first_name_value']['id'] = 'field_user_first_name_value';
  $handler->display->display_options['filters']['field_user_first_name_value']['table'] = 'field_data_field_user_first_name';
  $handler->display->display_options['filters']['field_user_first_name_value']['field'] = 'field_user_first_name_value';
  $handler->display->display_options['filters']['field_user_first_name_value']['relationship'] = 'profile';
  $handler->display->display_options['filters']['field_user_first_name_value']['operator'] = 'not empty';
  /* Filter criterion: Profile: Last name (field_user_last_name) */
  $handler->display->display_options['filters']['field_user_last_name_value']['id'] = 'field_user_last_name_value';
  $handler->display->display_options['filters']['field_user_last_name_value']['table'] = 'field_data_field_user_last_name';
  $handler->display->display_options['filters']['field_user_last_name_value']['field'] = 'field_user_last_name_value';
  $handler->display->display_options['filters']['field_user_last_name_value']['relationship'] = 'profile';
  $handler->display->display_options['filters']['field_user_last_name_value']['operator'] = 'not empty';
  /* Filter criterion: Profile: School (field_school) */
  $handler->display->display_options['filters']['field_school_tid']['id'] = 'field_school_tid';
  $handler->display->display_options['filters']['field_school_tid']['table'] = 'field_data_field_school';
  $handler->display->display_options['filters']['field_school_tid']['field'] = 'field_school_tid';
  $handler->display->display_options['filters']['field_school_tid']['relationship'] = 'profile';
  $handler->display->display_options['filters']['field_school_tid']['value'] = '';
  $handler->display->display_options['filters']['field_school_tid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_school_tid']['expose']['operator_id'] = 'field_school_tid_op';
  $handler->display->display_options['filters']['field_school_tid']['expose']['label'] = 'School';
  $handler->display->display_options['filters']['field_school_tid']['expose']['operator'] = 'field_school_tid_op';
  $handler->display->display_options['filters']['field_school_tid']['expose']['identifier'] = 'field_school_tid';
  $handler->display->display_options['filters']['field_school_tid']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    6 => 0,
    10 => 0,
    11 => 0,
    4 => 0,
    3 => 0,
    12 => 0,
  );
  $handler->display->display_options['filters']['field_school_tid']['vocabulary'] = 'schools';
  $handler->display->display_options['path'] = 'admin/statistical-reports/users-school';
  $handler->display->display_options['menu']['type'] = 'normal';
  $handler->display->display_options['menu']['title'] = 'Users By School';
  $handler->display->display_options['menu']['weight'] = '0';
  $handler->display->display_options['menu']['name'] = 'menu-statistical-reports';
  $handler->display->display_options['menu']['context'] = 0;
  $handler->display->display_options['menu']['context_only_inline'] = 0;

  /* Display: Home Library Responders */
  $handler = $view->new_display('page', 'Home Library Responders', 'page_14');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Home Library , Responders';
  $handler->display->display_options['enabled'] = FALSE;
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'views_aggregator';
  $handler->display->display_options['style_options']['columns'] = array(
    'field_library_branch' => 'field_library_branch',
  );
  $handler->display->display_options['style_options']['default'] = '-1';
  $handler->display->display_options['style_options']['info'] = array(
    'field_library_branch' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
      'has_aggr' => 0,
      'aggr' => array(
        'views_aggregator_group_and_compress' => 'views_aggregator_group_and_compress',
      ),
      'aggr_par' => '',
      'has_aggr_column' => 0,
      'aggr_column' => 'views_aggregator_count',
      'aggr_par_column' => '',
    ),
  );
  $handler->display->display_options['style_options']['column_aggregation']['totals_per_page'] = '0';
  $handler->display->display_options['style_options']['column_aggregation']['totals_row_position'] = array(
    1 => 0,
    2 => '2',
  );
  $handler->display->display_options['style_options']['column_aggregation']['precision'] = '2';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  /* Relationship: User: Activity */
  $handler->display->display_options['relationships']['eck_activity']['id'] = 'eck_activity';
  $handler->display->display_options['relationships']['eck_activity']['table'] = 'users';
  $handler->display->display_options['relationships']['eck_activity']['field'] = 'eck_activity';
  /* Relationship: User: Profile */
  $handler->display->display_options['relationships']['profile']['id'] = 'profile';
  $handler->display->display_options['relationships']['profile']['table'] = 'users';
  $handler->display->display_options['relationships']['profile']['field'] = 'profile';
  $handler->display->display_options['relationships']['profile']['bundle_types'] = array(
    'main' => 'main',
  );
  /* Relationship: Profile: Library branch (field_library_branch) */
  $handler->display->display_options['relationships']['field_library_branch_tid']['id'] = 'field_library_branch_tid';
  $handler->display->display_options['relationships']['field_library_branch_tid']['table'] = 'field_data_field_library_branch';
  $handler->display->display_options['relationships']['field_library_branch_tid']['field'] = 'field_library_branch_tid';
  $handler->display->display_options['relationships']['field_library_branch_tid']['relationship'] = 'profile';
  /* Relationship: User: Reward */
  $handler->display->display_options['relationships']['eck_reward']['id'] = 'eck_reward';
  $handler->display->display_options['relationships']['eck_reward']['table'] = 'users';
  $handler->display->display_options['relationships']['eck_reward']['field'] = 'eck_reward';
  /* Relationship: Entity Reference: Referenced Entity */
  $handler->display->display_options['relationships']['field_reward_claim_id_target_id']['id'] = 'field_reward_claim_id_target_id';
  $handler->display->display_options['relationships']['field_reward_claim_id_target_id']['table'] = 'field_data_field_reward_claim_id';
  $handler->display->display_options['relationships']['field_reward_claim_id_target_id']['field'] = 'field_reward_claim_id_target_id';
  $handler->display->display_options['relationships']['field_reward_claim_id_target_id']['relationship'] = 'eck_reward';
  /* Relationship: Entity Reference: Referenced Entity */
  $handler->display->display_options['relationships']['field_reward_badge_target_id']['id'] = 'field_reward_badge_target_id';
  $handler->display->display_options['relationships']['field_reward_badge_target_id']['table'] = 'field_data_field_reward_badge';
  $handler->display->display_options['relationships']['field_reward_badge_target_id']['field'] = 'field_reward_badge_target_id';
  $handler->display->display_options['relationships']['field_reward_badge_target_id']['relationship'] = 'field_reward_claim_id_target_id';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Profile: Library branch */
  $handler->display->display_options['fields']['field_library_branch']['id'] = 'field_library_branch';
  $handler->display->display_options['fields']['field_library_branch']['table'] = 'field_data_field_library_branch';
  $handler->display->display_options['fields']['field_library_branch']['field'] = 'field_library_branch';
  $handler->display->display_options['fields']['field_library_branch']['relationship'] = 'profile';
  $handler->display->display_options['fields']['field_library_branch']['empty'] = 'No Library';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: User: Active */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'users';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = '1';
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: User: Roles */
  $handler->display->display_options['filters']['rid']['id'] = 'rid';
  $handler->display->display_options['filters']['rid']['table'] = 'users_roles';
  $handler->display->display_options['filters']['rid']['field'] = 'rid';
  $handler->display->display_options['filters']['rid']['value'] = array(
    6 => '6',
  );
  $handler->display->display_options['path'] = 'statistical-reports/home-library-responders';

  /* Display: Users By Library Branch */
  $handler = $view->new_display('page', 'Users By Library Branch', 'page_15');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Users By Library Branch';
  $handler->display->display_options['defaults']['group_by'] = FALSE;
  $handler->display->display_options['defaults']['query'] = FALSE;
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['distinct'] = TRUE;
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['grouping'] = array(
    0 => array(
      'field' => 'field_library_branch',
      'rendered' => 1,
      'rendered_strip' => 0,
    ),
  );
  $handler->display->display_options['style_options']['columns'] = array(
    'field_library_branch' => 'field_library_branch',
    'uid' => 'uid',
    'field_user_first_name' => 'field_user_first_name',
    'field_user_middle_initial' => 'field_user_middle_initial',
    'field_user_last_name' => 'field_user_last_name',
    'field_user_birthday' => 'field_user_birthday',
    'mail' => 'mail',
    'name' => 'name',
    'field_school' => 'field_school',
    'field_library_card_number' => 'field_library_card_number',
    'title' => 'title',
  );
  $handler->display->display_options['style_options']['default'] = 'field_user_last_name';
  $handler->display->display_options['style_options']['info'] = array(
    'field_library_branch' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'uid' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_user_first_name' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_user_middle_initial' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_user_last_name' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_user_birthday' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'mail' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'name' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_school' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => 'views-align-left',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_library_card_number' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'title' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  /* Relationship: User: Activity */
  $handler->display->display_options['relationships']['eck_activity']['id'] = 'eck_activity';
  $handler->display->display_options['relationships']['eck_activity']['table'] = 'users';
  $handler->display->display_options['relationships']['eck_activity']['field'] = 'eck_activity';
  /* Relationship: User: Badge */
  $handler->display->display_options['relationships']['eck_badge']['id'] = 'eck_badge';
  $handler->display->display_options['relationships']['eck_badge']['table'] = 'users';
  $handler->display->display_options['relationships']['eck_badge']['field'] = 'eck_badge';
  /* Relationship: User: Profile */
  $handler->display->display_options['relationships']['profile']['id'] = 'profile';
  $handler->display->display_options['relationships']['profile']['table'] = 'users';
  $handler->display->display_options['relationships']['profile']['field'] = 'profile';
  $handler->display->display_options['relationships']['profile']['bundle_types'] = array(
    'main' => 'main',
  );
  /* Relationship: User: Raffle */
  $handler->display->display_options['relationships']['eck_raffle']['id'] = 'eck_raffle';
  $handler->display->display_options['relationships']['eck_raffle']['table'] = 'users';
  $handler->display->display_options['relationships']['eck_raffle']['field'] = 'eck_raffle';
  /* Relationship: User: Reward */
  $handler->display->display_options['relationships']['eck_reward']['id'] = 'eck_reward';
  $handler->display->display_options['relationships']['eck_reward']['table'] = 'users';
  $handler->display->display_options['relationships']['eck_reward']['field'] = 'eck_reward';
  /* Relationship: Profile: Library branch (field_library_branch) */
  $handler->display->display_options['relationships']['field_library_branch_tid']['id'] = 'field_library_branch_tid';
  $handler->display->display_options['relationships']['field_library_branch_tid']['table'] = 'field_data_field_library_branch';
  $handler->display->display_options['relationships']['field_library_branch_tid']['field'] = 'field_library_branch_tid';
  $handler->display->display_options['relationships']['field_library_branch_tid']['relationship'] = 'profile';
  /* Relationship: Entity Reference: Referenced Entity */
  $handler->display->display_options['relationships']['field_reward_claim_id_target_id']['id'] = 'field_reward_claim_id_target_id';
  $handler->display->display_options['relationships']['field_reward_claim_id_target_id']['table'] = 'field_data_field_reward_claim_id';
  $handler->display->display_options['relationships']['field_reward_claim_id_target_id']['field'] = 'field_reward_claim_id_target_id';
  $handler->display->display_options['relationships']['field_reward_claim_id_target_id']['relationship'] = 'eck_reward';
  /* Relationship: Entity Reference: Referenced Entity */
  $handler->display->display_options['relationships']['field_reward_badge_target_id']['id'] = 'field_reward_badge_target_id';
  $handler->display->display_options['relationships']['field_reward_badge_target_id']['table'] = 'field_data_field_reward_badge';
  $handler->display->display_options['relationships']['field_reward_badge_target_id']['field'] = 'field_reward_badge_target_id';
  $handler->display->display_options['relationships']['field_reward_badge_target_id']['relationship'] = 'eck_reward';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Profile: Library branch */
  $handler->display->display_options['fields']['field_library_branch']['id'] = 'field_library_branch';
  $handler->display->display_options['fields']['field_library_branch']['table'] = 'field_data_field_library_branch';
  $handler->display->display_options['fields']['field_library_branch']['field'] = 'field_library_branch';
  $handler->display->display_options['fields']['field_library_branch']['relationship'] = 'profile';
  $handler->display->display_options['fields']['field_library_branch']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_library_branch']['empty'] = 'No Library';
  /* Field: User: Uid */
  $handler->display->display_options['fields']['uid']['id'] = 'uid';
  $handler->display->display_options['fields']['uid']['table'] = 'users';
  $handler->display->display_options['fields']['uid']['field'] = 'uid';
  $handler->display->display_options['fields']['uid']['exclude'] = TRUE;
  /* Field: Profile: First name */
  $handler->display->display_options['fields']['field_user_first_name']['id'] = 'field_user_first_name';
  $handler->display->display_options['fields']['field_user_first_name']['table'] = 'field_data_field_user_first_name';
  $handler->display->display_options['fields']['field_user_first_name']['field'] = 'field_user_first_name';
  $handler->display->display_options['fields']['field_user_first_name']['relationship'] = 'profile';
  $handler->display->display_options['fields']['field_user_first_name']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_user_first_name']['hide_empty'] = TRUE;
  /* Field: Profile: Middle initial */
  $handler->display->display_options['fields']['field_user_middle_initial']['id'] = 'field_user_middle_initial';
  $handler->display->display_options['fields']['field_user_middle_initial']['table'] = 'field_data_field_user_middle_initial';
  $handler->display->display_options['fields']['field_user_middle_initial']['field'] = 'field_user_middle_initial';
  $handler->display->display_options['fields']['field_user_middle_initial']['relationship'] = 'profile';
  $handler->display->display_options['fields']['field_user_middle_initial']['exclude'] = TRUE;
  /* Field: Profile: Last name */
  $handler->display->display_options['fields']['field_user_last_name']['id'] = 'field_user_last_name';
  $handler->display->display_options['fields']['field_user_last_name']['table'] = 'field_data_field_user_last_name';
  $handler->display->display_options['fields']['field_user_last_name']['field'] = 'field_user_last_name';
  $handler->display->display_options['fields']['field_user_last_name']['relationship'] = 'profile';
  $handler->display->display_options['fields']['field_user_last_name']['label'] = 'Name';
  $handler->display->display_options['fields']['field_user_last_name']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_user_last_name']['alter']['text'] = '[field_user_last_name], [field_user_first_name] [field_user_middle_initial]';
  $handler->display->display_options['fields']['field_user_last_name']['hide_empty'] = TRUE;
  /* Field: Profile: Date of Birth */
  $handler->display->display_options['fields']['field_user_birthday']['id'] = 'field_user_birthday';
  $handler->display->display_options['fields']['field_user_birthday']['table'] = 'field_data_field_user_birthday';
  $handler->display->display_options['fields']['field_user_birthday']['field'] = 'field_user_birthday';
  $handler->display->display_options['fields']['field_user_birthday']['relationship'] = 'profile';
  $handler->display->display_options['fields']['field_user_birthday']['settings'] = array(
    'format_type' => 'privatemsg_years',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
    'show_remaining_days' => 0,
  );
  /* Field: User: E-mail */
  $handler->display->display_options['fields']['mail']['id'] = 'mail';
  $handler->display->display_options['fields']['mail']['table'] = 'users';
  $handler->display->display_options['fields']['mail']['field'] = 'mail';
  $handler->display->display_options['fields']['mail']['link_to_user'] = '0';
  /* Field: User: Name */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'users';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  /* Field: Profile: School */
  $handler->display->display_options['fields']['field_school']['id'] = 'field_school';
  $handler->display->display_options['fields']['field_school']['table'] = 'field_data_field_school';
  $handler->display->display_options['fields']['field_school']['field'] = 'field_school';
  $handler->display->display_options['fields']['field_school']['relationship'] = 'profile';
  $handler->display->display_options['fields']['field_school']['label'] = '';
  $handler->display->display_options['fields']['field_school']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_school']['empty'] = 'No School';
  /* Field: Profile: Library card number */
  $handler->display->display_options['fields']['field_library_card_number']['id'] = 'field_library_card_number';
  $handler->display->display_options['fields']['field_library_card_number']['table'] = 'field_data_field_library_card_number';
  $handler->display->display_options['fields']['field_library_card_number']['field'] = 'field_library_card_number';
  $handler->display->display_options['fields']['field_library_card_number']['relationship'] = 'profile';
  $handler->display->display_options['fields']['field_library_card_number']['type'] = 'text_plain';
  /* Field: Badge: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'eck_badge';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['relationship'] = 'eck_badge';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: User: Active */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'users';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = '1';
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: User: Roles */
  $handler->display->display_options['filters']['rid']['id'] = 'rid';
  $handler->display->display_options['filters']['rid']['table'] = 'users_roles';
  $handler->display->display_options['filters']['rid']['field'] = 'rid';
  $handler->display->display_options['filters']['rid']['value'] = array(
    6 => '6',
  );
  /* Filter criterion: Profile: First name (field_user_first_name) */
  $handler->display->display_options['filters']['field_user_first_name_value']['id'] = 'field_user_first_name_value';
  $handler->display->display_options['filters']['field_user_first_name_value']['table'] = 'field_data_field_user_first_name';
  $handler->display->display_options['filters']['field_user_first_name_value']['field'] = 'field_user_first_name_value';
  $handler->display->display_options['filters']['field_user_first_name_value']['relationship'] = 'profile';
  $handler->display->display_options['filters']['field_user_first_name_value']['operator'] = 'not empty';
  /* Filter criterion: Profile: Last name (field_user_last_name) */
  $handler->display->display_options['filters']['field_user_last_name_value']['id'] = 'field_user_last_name_value';
  $handler->display->display_options['filters']['field_user_last_name_value']['table'] = 'field_data_field_user_last_name';
  $handler->display->display_options['filters']['field_user_last_name_value']['field'] = 'field_user_last_name_value';
  $handler->display->display_options['filters']['field_user_last_name_value']['relationship'] = 'profile';
  $handler->display->display_options['filters']['field_user_last_name_value']['operator'] = 'not empty';
  /* Filter criterion: Profile: Library branch (field_library_branch) */
  $handler->display->display_options['filters']['field_library_branch_tid']['id'] = 'field_library_branch_tid';
  $handler->display->display_options['filters']['field_library_branch_tid']['table'] = 'field_data_field_library_branch';
  $handler->display->display_options['filters']['field_library_branch_tid']['field'] = 'field_library_branch_tid';
  $handler->display->display_options['filters']['field_library_branch_tid']['relationship'] = 'profile';
  $handler->display->display_options['filters']['field_library_branch_tid']['value'] = '';
  $handler->display->display_options['filters']['field_library_branch_tid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_library_branch_tid']['expose']['operator_id'] = 'field_library_branch_tid_op';
  $handler->display->display_options['filters']['field_library_branch_tid']['expose']['label'] = 'Library branch (field_library_branch)';
  $handler->display->display_options['filters']['field_library_branch_tid']['expose']['operator'] = 'field_library_branch_tid_op';
  $handler->display->display_options['filters']['field_library_branch_tid']['expose']['identifier'] = 'field_library_branch_tid';
  $handler->display->display_options['filters']['field_library_branch_tid']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    6 => 0,
    10 => 0,
    11 => 0,
    4 => 0,
    3 => 0,
    12 => 0,
  );
  $handler->display->display_options['filters']['field_library_branch_tid']['vocabulary'] = 'library_branches';
  $handler->display->display_options['path'] = 'admin/statistical-reports/users-library';
  $handler->display->display_options['menu']['type'] = 'normal';
  $handler->display->display_options['menu']['title'] = 'Users By Home Library';
  $handler->display->display_options['menu']['weight'] = '0';
  $handler->display->display_options['menu']['name'] = 'menu-statistical-reports';
  $handler->display->display_options['menu']['context'] = 0;
  $handler->display->display_options['menu']['context_only_inline'] = 0;
  $export['stat_reports'] = $view;

  return $export;
}

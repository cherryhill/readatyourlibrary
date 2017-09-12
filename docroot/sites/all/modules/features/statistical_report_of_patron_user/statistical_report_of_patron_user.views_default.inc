<?php
/**
 * @file
 * statistical_report_of_patron_user.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function statistical_report_of_patron_user_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'by_home_library_school_of_users';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'users';
  $view->human_name = 'By home library - number of registration';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'By home library - school of users';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['access']['perm'] = 'access user profiles';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['style_plugin'] = 'views_aggregator';
  $handler->display->display_options['style_options']['columns'] = array(
    'field_school' => 'field_school',
    'name' => 'name',
    'php' => 'php',
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
    'php' => array(
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
  );
  $handler->display->display_options['style_options']['column_aggregation']['totals_per_page'] = '1';
  $handler->display->display_options['style_options']['column_aggregation']['totals_row_position'] = array(
    1 => 0,
    2 => '2',
  );
  $handler->display->display_options['style_options']['column_aggregation']['precision'] = '2';
  /* No results behavior: Global: Text area */
  $handler->display->display_options['empty']['area']['id'] = 'area';
  $handler->display->display_options['empty']['area']['table'] = 'views';
  $handler->display->display_options['empty']['area']['field'] = 'area';
  $handler->display->display_options['empty']['area']['empty'] = TRUE;
  $handler->display->display_options['empty']['area']['content'] = 'No result';
  $handler->display->display_options['empty']['area']['format'] = 'filtered_html';
  /* Relationship: User: Profile */
  $handler->display->display_options['relationships']['profile']['id'] = 'profile';
  $handler->display->display_options['relationships']['profile']['table'] = 'users';
  $handler->display->display_options['relationships']['profile']['field'] = 'profile';
  $handler->display->display_options['relationships']['profile']['bundle_types'] = array(
    'main' => 'main',
  );
  /* Field: User: Name */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'users';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['label'] = '';
  $handler->display->display_options['fields']['name']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['name']['alter']['ellipsis'] = FALSE;
  /* Sort criterion: Profile: Date of Birth (field_user_birthday) */
  $handler->display->display_options['sorts']['field_user_birthday_value']['id'] = 'field_user_birthday_value';
  $handler->display->display_options['sorts']['field_user_birthday_value']['table'] = 'field_data_field_user_birthday';
  $handler->display->display_options['sorts']['field_user_birthday_value']['field'] = 'field_user_birthday_value';
  $handler->display->display_options['sorts']['field_user_birthday_value']['relationship'] = 'profile';
  $handler->display->display_options['sorts']['field_user_birthday_value']['order'] = 'DESC';
  /* Filter criterion: User: Active */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'users';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = '1';
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Profile: Date of Birth (field_user_birthday) */
  $handler->display->display_options['filters']['field_user_birthday_value']['id'] = 'field_user_birthday_value';
  $handler->display->display_options['filters']['field_user_birthday_value']['table'] = 'field_data_field_user_birthday';
  $handler->display->display_options['filters']['field_user_birthday_value']['field'] = 'field_user_birthday_value';
  $handler->display->display_options['filters']['field_user_birthday_value']['relationship'] = 'profile';
  $handler->display->display_options['filters']['field_user_birthday_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_user_birthday_value']['expose']['operator_id'] = 'field_user_birthday_value_op';
  $handler->display->display_options['filters']['field_user_birthday_value']['expose']['label'] = 'DOB Date Range';
  $handler->display->display_options['filters']['field_user_birthday_value']['expose']['use_operator'] = TRUE;
  $handler->display->display_options['filters']['field_user_birthday_value']['expose']['operator'] = 'field_user_birthday_value_op';
  $handler->display->display_options['filters']['field_user_birthday_value']['expose']['identifier'] = 'field_user_birthday_value';
  $handler->display->display_options['filters']['field_user_birthday_value']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
    6 => 0,
    7 => 0,
  );
  $handler->display->display_options['filters']['field_user_birthday_value']['granularity'] = 'year';
  $handler->display->display_options['filters']['field_user_birthday_value']['year_range'] = '1990:+3';
  /* Filter criterion: User: Roles */
  $handler->display->display_options['filters']['rid']['id'] = 'rid';
  $handler->display->display_options['filters']['rid']['table'] = 'users_roles';
  $handler->display->display_options['filters']['rid']['field'] = 'rid';
  $handler->display->display_options['filters']['rid']['operator'] = 'not';
  $handler->display->display_options['filters']['rid']['value'] = array(
    3 => '3',
    6 => '6',
    7 => '7',
  );
  /* Filter criterion: Profile: School (field_school) */
  $handler->display->display_options['filters']['field_school_tid']['id'] = 'field_school_tid';
  $handler->display->display_options['filters']['field_school_tid']['table'] = 'field_data_field_school';
  $handler->display->display_options['filters']['field_school_tid']['field'] = 'field_school_tid';
  $handler->display->display_options['filters']['field_school_tid']['relationship'] = 'profile';
  $handler->display->display_options['filters']['field_school_tid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_school_tid']['expose']['operator_id'] = 'field_school_tid_op';
  $handler->display->display_options['filters']['field_school_tid']['expose']['label'] = 'School';
  $handler->display->display_options['filters']['field_school_tid']['expose']['operator'] = 'field_school_tid_op';
  $handler->display->display_options['filters']['field_school_tid']['expose']['identifier'] = 'field_school_tid';
  $handler->display->display_options['filters']['field_school_tid']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
    6 => 0,
    7 => 0,
  );
  $handler->display->display_options['filters']['field_school_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_school_tid']['vocabulary'] = 'schools';
  $handler->display->display_options['filters']['field_school_tid']['hierarchy'] = 1;
  /* Filter criterion: Profile: Library branch (field_library_branch) */
  $handler->display->display_options['filters']['field_library_branch_tid']['id'] = 'field_library_branch_tid';
  $handler->display->display_options['filters']['field_library_branch_tid']['table'] = 'field_data_field_library_branch';
  $handler->display->display_options['filters']['field_library_branch_tid']['field'] = 'field_library_branch_tid';
  $handler->display->display_options['filters']['field_library_branch_tid']['relationship'] = 'profile';
  $handler->display->display_options['filters']['field_library_branch_tid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_library_branch_tid']['expose']['operator_id'] = 'field_library_branch_tid_op';
  $handler->display->display_options['filters']['field_library_branch_tid']['expose']['label'] = 'Library branch';
  $handler->display->display_options['filters']['field_library_branch_tid']['expose']['operator'] = 'field_library_branch_tid_op';
  $handler->display->display_options['filters']['field_library_branch_tid']['expose']['identifier'] = 'field_library_branch_tid';
  $handler->display->display_options['filters']['field_library_branch_tid']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
    6 => 0,
    7 => 0,
  );
  $handler->display->display_options['filters']['field_library_branch_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_library_branch_tid']['vocabulary'] = 'library_branch';
  $handler->display->display_options['filters']['field_library_branch_tid']['hierarchy'] = 1;

  /* Display: By Library Branch - number of registration */
  $handler = $view->new_display('page', 'By Library Branch - number of registration', 'page');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'By Library Branch - number of registration';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'views_aggregator';
  $handler->display->display_options['style_options']['columns'] = array(
    'field_school' => 'field_school',
    'field_library_branch' => 'field_library_branch',
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
      'has_aggr' => 0,
      'aggr' => array(
        'views_aggregator_group_and_compress' => 'views_aggregator_group_and_compress',
      ),
      'aggr_par' => '',
      'has_aggr_column' => 0,
      'aggr_column' => 'views_aggregator_sum',
      'aggr_par_column' => '',
    ),
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
  $handler->display->display_options['style_options']['column_aggregation']['totals_per_page'] = '1';
  $handler->display->display_options['style_options']['column_aggregation']['totals_row_position'] = array(
    1 => 0,
    2 => '2',
  );
  $handler->display->display_options['style_options']['column_aggregation']['precision'] = '2';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['header'] = FALSE;
  $handler->display->display_options['defaults']['empty'] = FALSE;
  /* No results behavior: Global: Text area */
  $handler->display->display_options['empty']['area']['id'] = 'area';
  $handler->display->display_options['empty']['area']['table'] = 'views';
  $handler->display->display_options['empty']['area']['field'] = 'area';
  $handler->display->display_options['empty']['area']['empty'] = TRUE;
  $handler->display->display_options['empty']['area']['content'] = 'No result';
  $handler->display->display_options['empty']['area']['format'] = 'filtered_html';
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  /* Relationship: User: Profile */
  $handler->display->display_options['relationships']['profile']['id'] = 'profile';
  $handler->display->display_options['relationships']['profile']['table'] = 'users';
  $handler->display->display_options['relationships']['profile']['field'] = 'profile';
  $handler->display->display_options['relationships']['profile']['bundle_types'] = array(
    'main' => 'main',
  );
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Profile: Library branch */
  $handler->display->display_options['fields']['field_library_branch']['id'] = 'field_library_branch';
  $handler->display->display_options['fields']['field_library_branch']['table'] = 'field_data_field_library_branch';
  $handler->display->display_options['fields']['field_library_branch']['field'] = 'field_library_branch';
  $handler->display->display_options['fields']['field_library_branch']['relationship'] = 'profile';
  $handler->display->display_options['fields']['field_library_branch']['type'] = 'taxonomy_term_reference_plain';
  /* Field: User: Name */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'users';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['label'] = 'No of users';
  $handler->display->display_options['fields']['name']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['name']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['name']['link_to_user'] = FALSE;
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
  $handler->display->display_options['filters']['rid']['operator'] = 'not';
  $handler->display->display_options['filters']['rid']['value'] = array(
    3 => '3',
    6 => '6',
    7 => '7',
  );
  /* Filter criterion: Profile: Date of Birth (field_user_birthday) */
  $handler->display->display_options['filters']['field_user_birthday_value']['id'] = 'field_user_birthday_value';
  $handler->display->display_options['filters']['field_user_birthday_value']['table'] = 'field_data_field_user_birthday';
  $handler->display->display_options['filters']['field_user_birthday_value']['field'] = 'field_user_birthday_value';
  $handler->display->display_options['filters']['field_user_birthday_value']['relationship'] = 'profile';
  $handler->display->display_options['filters']['field_user_birthday_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_user_birthday_value']['expose']['operator_id'] = 'field_user_birthday_value_op';
  $handler->display->display_options['filters']['field_user_birthday_value']['expose']['label'] = 'DOB Date Range';
  $handler->display->display_options['filters']['field_user_birthday_value']['expose']['use_operator'] = TRUE;
  $handler->display->display_options['filters']['field_user_birthday_value']['expose']['operator'] = 'field_user_birthday_value_op';
  $handler->display->display_options['filters']['field_user_birthday_value']['expose']['identifier'] = 'field_user_birthday_value';
  $handler->display->display_options['filters']['field_user_birthday_value']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
    6 => 0,
    7 => 0,
  );
  $handler->display->display_options['filters']['field_user_birthday_value']['granularity'] = 'year';
  $handler->display->display_options['filters']['field_user_birthday_value']['year_range'] = '1990:+10';
  /* Filter criterion: Profile: Library branch (field_library_branch) */
  $handler->display->display_options['filters']['field_library_branch_tid']['id'] = 'field_library_branch_tid';
  $handler->display->display_options['filters']['field_library_branch_tid']['table'] = 'field_data_field_library_branch';
  $handler->display->display_options['filters']['field_library_branch_tid']['field'] = 'field_library_branch_tid';
  $handler->display->display_options['filters']['field_library_branch_tid']['relationship'] = 'profile';
  $handler->display->display_options['filters']['field_library_branch_tid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_library_branch_tid']['expose']['operator_id'] = 'field_library_branch_tid_op';
  $handler->display->display_options['filters']['field_library_branch_tid']['expose']['label'] = 'Library branch';
  $handler->display->display_options['filters']['field_library_branch_tid']['expose']['use_operator'] = TRUE;
  $handler->display->display_options['filters']['field_library_branch_tid']['expose']['operator'] = 'field_library_branch_tid_op';
  $handler->display->display_options['filters']['field_library_branch_tid']['expose']['identifier'] = 'field_library_branch_tid';
  $handler->display->display_options['filters']['field_library_branch_tid']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
    6 => 0,
    7 => 0,
  );
  $handler->display->display_options['filters']['field_library_branch_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_library_branch_tid']['vocabulary'] = 'library_branch';
  $handler->display->display_options['filters']['field_library_branch_tid']['hierarchy'] = 1;
  /* Filter criterion: Profile: School (field_school) */
  $handler->display->display_options['filters']['field_school_tid']['id'] = 'field_school_tid';
  $handler->display->display_options['filters']['field_school_tid']['table'] = 'field_data_field_school';
  $handler->display->display_options['filters']['field_school_tid']['field'] = 'field_school_tid';
  $handler->display->display_options['filters']['field_school_tid']['relationship'] = 'profile';
  $handler->display->display_options['filters']['field_school_tid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_school_tid']['expose']['operator_id'] = 'field_school_tid_op';
  $handler->display->display_options['filters']['field_school_tid']['expose']['label'] = 'School';
  $handler->display->display_options['filters']['field_school_tid']['expose']['use_operator'] = TRUE;
  $handler->display->display_options['filters']['field_school_tid']['expose']['operator'] = 'field_school_tid_op';
  $handler->display->display_options['filters']['field_school_tid']['expose']['identifier'] = 'field_school_tid';
  $handler->display->display_options['filters']['field_school_tid']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
    6 => 0,
    7 => 0,
  );
  $handler->display->display_options['filters']['field_school_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_school_tid']['vocabulary'] = 'schools';
  $handler->display->display_options['filters']['field_school_tid']['hierarchy'] = 1;
  $handler->display->display_options['path'] = 'admin/statistical-reports/registrations-by-branch';

  /* Display: By school - number of registration */
  $handler = $view->new_display('page', 'By school - number of registration', 'page_1');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'By school - number of registration';
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
  $handler->display->display_options['style_options']['column_aggregation']['totals_per_page'] = '1';
  $handler->display->display_options['style_options']['column_aggregation']['totals_row_position'] = array(
    1 => 0,
    2 => '2',
  );
  $handler->display->display_options['style_options']['column_aggregation']['precision'] = '2';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  /* Relationship: User: Profile */
  $handler->display->display_options['relationships']['profile']['id'] = 'profile';
  $handler->display->display_options['relationships']['profile']['table'] = 'users';
  $handler->display->display_options['relationships']['profile']['field'] = 'profile';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Profile: School */
  $handler->display->display_options['fields']['field_school']['id'] = 'field_school';
  $handler->display->display_options['fields']['field_school']['table'] = 'field_data_field_school';
  $handler->display->display_options['fields']['field_school']['field'] = 'field_school';
  $handler->display->display_options['fields']['field_school']['relationship'] = 'profile';
  $handler->display->display_options['fields']['field_school']['type'] = 'taxonomy_term_reference_plain';
  /* Field: User: Name */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'users';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['label'] = 'No of users';
  $handler->display->display_options['fields']['name']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['name']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['path'] = 'admin/statistical-reports/registrations-by-school';

  /* Display: By Age - number of registration */
  $handler = $view->new_display('page', 'By Age - number of registration', 'page_2');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'By Age - number of registration';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'views_aggregator';
  $handler->display->display_options['style_options']['columns'] = array(
    'field_user_birthday' => 'field_user_birthday',
    'name' => 'name',
  );
  $handler->display->display_options['style_options']['default'] = '-1';
  $handler->display->display_options['style_options']['info'] = array(
    'field_user_birthday' => array(
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
  $handler->display->display_options['style_options']['column_aggregation']['totals_per_page'] = '1';
  $handler->display->display_options['style_options']['column_aggregation']['totals_row_position'] = array(
    1 => 0,
    2 => '2',
  );
  $handler->display->display_options['style_options']['column_aggregation']['precision'] = '2';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Profile: Date of Birth */
  $handler->display->display_options['fields']['field_user_birthday']['id'] = 'field_user_birthday';
  $handler->display->display_options['fields']['field_user_birthday']['table'] = 'field_data_field_user_birthday';
  $handler->display->display_options['fields']['field_user_birthday']['field'] = 'field_user_birthday';
  $handler->display->display_options['fields']['field_user_birthday']['relationship'] = 'profile';
  $handler->display->display_options['fields']['field_user_birthday']['label'] = 'Age in years';
  $handler->display->display_options['fields']['field_user_birthday']['type'] = 'format_interval';
  $handler->display->display_options['fields']['field_user_birthday']['settings'] = array(
    'interval' => '1',
    'interval_display' => 'raw time ago',
  );
  /* Field: User: Name */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'users';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['label'] = 'No of users';
  $handler->display->display_options['fields']['name']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['name']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['path'] = 'admin/statistical-reports/registrations-by-age';

  /* Display: User Data */
  $handler = $view->new_display('page', 'User Data', 'page_4');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'User Data';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'name' => 'name',
  );
  $handler->display->display_options['style_options']['default'] = '-1';
  $handler->display->display_options['style_options']['info'] = array(
    'name' => array(
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
  /* Relationship: User: Profile */
  $handler->display->display_options['relationships']['profile']['id'] = 'profile';
  $handler->display->display_options['relationships']['profile']['table'] = 'users';
  $handler->display->display_options['relationships']['profile']['field'] = 'profile';
  $handler->display->display_options['relationships']['profile']['bundle_types'] = array(
    'main' => 'main',
  );
  /* Relationship: User: Reward */
  $handler->display->display_options['relationships']['eck_reward']['id'] = 'eck_reward';
  $handler->display->display_options['relationships']['eck_reward']['table'] = 'users';
  $handler->display->display_options['relationships']['eck_reward']['field'] = 'eck_reward';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: User: Name */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'users';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['label'] = 'Username';
  $handler->display->display_options['fields']['name']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['name']['alter']['ellipsis'] = FALSE;
  /* Field: Profile: First Name */
  $handler->display->display_options['fields']['field_first_name']['id'] = 'field_first_name';
  $handler->display->display_options['fields']['field_first_name']['table'] = 'field_data_field_first_name';
  $handler->display->display_options['fields']['field_first_name']['field'] = 'field_first_name';
  $handler->display->display_options['fields']['field_first_name']['relationship'] = 'profile';
  /* Field: Profile: Middle initial */
  $handler->display->display_options['fields']['field_middle_initial']['id'] = 'field_middle_initial';
  $handler->display->display_options['fields']['field_middle_initial']['table'] = 'field_data_field_middle_initial';
  $handler->display->display_options['fields']['field_middle_initial']['field'] = 'field_middle_initial';
  $handler->display->display_options['fields']['field_middle_initial']['relationship'] = 'profile';
  /* Field: Profile: Last name */
  $handler->display->display_options['fields']['field_last_name']['id'] = 'field_last_name';
  $handler->display->display_options['fields']['field_last_name']['table'] = 'field_data_field_last_name';
  $handler->display->display_options['fields']['field_last_name']['field'] = 'field_last_name';
  $handler->display->display_options['fields']['field_last_name']['relationship'] = 'profile';
  /* Field: Profile: Date of Birth */
  $handler->display->display_options['fields']['field_user_birthday']['id'] = 'field_user_birthday';
  $handler->display->display_options['fields']['field_user_birthday']['table'] = 'field_data_field_user_birthday';
  $handler->display->display_options['fields']['field_user_birthday']['field'] = 'field_user_birthday';
  $handler->display->display_options['fields']['field_user_birthday']['relationship'] = 'profile';
  $handler->display->display_options['fields']['field_user_birthday']['settings'] = array(
    'format_type' => 'short',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
    'show_remaining_days' => 0,
  );
  /* Field: Profile: Library branch */
  $handler->display->display_options['fields']['field_library_branch']['id'] = 'field_library_branch';
  $handler->display->display_options['fields']['field_library_branch']['table'] = 'field_data_field_library_branch';
  $handler->display->display_options['fields']['field_library_branch']['field'] = 'field_library_branch';
  $handler->display->display_options['fields']['field_library_branch']['relationship'] = 'profile';
  $handler->display->display_options['fields']['field_library_branch']['type'] = 'taxonomy_term_reference_plain';
  /* Field: Profile: Phone number */
  $handler->display->display_options['fields']['field_phone_number']['id'] = 'field_phone_number';
  $handler->display->display_options['fields']['field_phone_number']['table'] = 'field_data_field_phone_number';
  $handler->display->display_options['fields']['field_phone_number']['field'] = 'field_phone_number';
  $handler->display->display_options['fields']['field_phone_number']['relationship'] = 'profile';
  $handler->display->display_options['fields']['field_phone_number']['settings'] = array(
    'phone_link' => 0,
  );
  /* Field: Profile: School */
  $handler->display->display_options['fields']['field_school']['id'] = 'field_school';
  $handler->display->display_options['fields']['field_school']['table'] = 'field_data_field_school';
  $handler->display->display_options['fields']['field_school']['field'] = 'field_school';
  $handler->display->display_options['fields']['field_school']['relationship'] = 'profile';
  $handler->display->display_options['fields']['field_school']['type'] = 'taxonomy_term_reference_plain';
  /* Field: Reward: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'eck_reward';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['relationship'] = 'eck_reward';
  $handler->display->display_options['fields']['title']['label'] = 'User Rewards';
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
  $handler->display->display_options['filters']['rid']['operator'] = 'not';
  $handler->display->display_options['filters']['rid']['value'] = array(
    3 => '3',
    6 => '6',
    7 => '7',
  );
  $handler->display->display_options['filters']['rid']['group'] = 1;
  /* Filter criterion: Reward: Title */
  $handler->display->display_options['filters']['title']['id'] = 'title';
  $handler->display->display_options['filters']['title']['table'] = 'eck_reward';
  $handler->display->display_options['filters']['title']['field'] = 'title';
  $handler->display->display_options['filters']['title']['relationship'] = 'eck_reward';
  $handler->display->display_options['filters']['title']['operator'] = 'contains';
  $handler->display->display_options['filters']['title']['group'] = 1;
  $handler->display->display_options['filters']['title']['exposed'] = TRUE;
  $handler->display->display_options['filters']['title']['expose']['operator_id'] = 'title_op';
  $handler->display->display_options['filters']['title']['expose']['label'] = 'Reward Title Contains';
  $handler->display->display_options['filters']['title']['expose']['operator'] = 'title_op';
  $handler->display->display_options['filters']['title']['expose']['identifier'] = 'title';
  $handler->display->display_options['filters']['title']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
    6 => 0,
    7 => 0,
  );
  /* Filter criterion: User: Name */
  $handler->display->display_options['filters']['uid']['id'] = 'uid';
  $handler->display->display_options['filters']['uid']['table'] = 'users';
  $handler->display->display_options['filters']['uid']['field'] = 'uid';
  $handler->display->display_options['filters']['uid']['value'] = '';
  $handler->display->display_options['filters']['uid']['group'] = 1;
  $handler->display->display_options['filters']['uid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['uid']['expose']['operator_id'] = 'uid_op';
  $handler->display->display_options['filters']['uid']['expose']['label'] = 'Username';
  $handler->display->display_options['filters']['uid']['expose']['operator'] = 'uid_op';
  $handler->display->display_options['filters']['uid']['expose']['identifier'] = 'uid';
  $handler->display->display_options['filters']['uid']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
    6 => 0,
    7 => 0,
  );
  /* Filter criterion: Profile: First Name (field_first_name) */
  $handler->display->display_options['filters']['field_first_name_value']['id'] = 'field_first_name_value';
  $handler->display->display_options['filters']['field_first_name_value']['table'] = 'field_data_field_first_name';
  $handler->display->display_options['filters']['field_first_name_value']['field'] = 'field_first_name_value';
  $handler->display->display_options['filters']['field_first_name_value']['relationship'] = 'profile';
  $handler->display->display_options['filters']['field_first_name_value']['operator'] = 'contains';
  $handler->display->display_options['filters']['field_first_name_value']['group'] = 1;
  $handler->display->display_options['filters']['field_first_name_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_first_name_value']['expose']['operator_id'] = 'field_first_name_value_op';
  $handler->display->display_options['filters']['field_first_name_value']['expose']['label'] = 'User First Name';
  $handler->display->display_options['filters']['field_first_name_value']['expose']['operator'] = 'field_first_name_value_op';
  $handler->display->display_options['filters']['field_first_name_value']['expose']['identifier'] = 'field_first_name_value';
  $handler->display->display_options['filters']['field_first_name_value']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
    6 => 0,
    7 => 0,
  );
  /* Filter criterion: Profile: Last name (field_last_name) */
  $handler->display->display_options['filters']['field_last_name_value']['id'] = 'field_last_name_value';
  $handler->display->display_options['filters']['field_last_name_value']['table'] = 'field_data_field_last_name';
  $handler->display->display_options['filters']['field_last_name_value']['field'] = 'field_last_name_value';
  $handler->display->display_options['filters']['field_last_name_value']['relationship'] = 'profile';
  $handler->display->display_options['filters']['field_last_name_value']['operator'] = 'contains';
  $handler->display->display_options['filters']['field_last_name_value']['group'] = 1;
  $handler->display->display_options['filters']['field_last_name_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_last_name_value']['expose']['operator_id'] = 'field_last_name_value_op';
  $handler->display->display_options['filters']['field_last_name_value']['expose']['label'] = 'User Last Name';
  $handler->display->display_options['filters']['field_last_name_value']['expose']['operator'] = 'field_last_name_value_op';
  $handler->display->display_options['filters']['field_last_name_value']['expose']['identifier'] = 'field_last_name_value';
  $handler->display->display_options['filters']['field_last_name_value']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
    6 => 0,
    7 => 0,
  );
  /* Filter criterion: Profile: Library branch (field_library_branch) */
  $handler->display->display_options['filters']['field_library_branch_tid']['id'] = 'field_library_branch_tid';
  $handler->display->display_options['filters']['field_library_branch_tid']['table'] = 'field_data_field_library_branch';
  $handler->display->display_options['filters']['field_library_branch_tid']['field'] = 'field_library_branch_tid';
  $handler->display->display_options['filters']['field_library_branch_tid']['relationship'] = 'profile';
  $handler->display->display_options['filters']['field_library_branch_tid']['group'] = 1;
  $handler->display->display_options['filters']['field_library_branch_tid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_library_branch_tid']['expose']['operator_id'] = 'field_library_branch_tid_op';
  $handler->display->display_options['filters']['field_library_branch_tid']['expose']['label'] = 'Library branch';
  $handler->display->display_options['filters']['field_library_branch_tid']['expose']['operator'] = 'field_library_branch_tid_op';
  $handler->display->display_options['filters']['field_library_branch_tid']['expose']['identifier'] = 'field_library_branch_tid';
  $handler->display->display_options['filters']['field_library_branch_tid']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
    6 => 0,
    7 => 0,
  );
  $handler->display->display_options['filters']['field_library_branch_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_library_branch_tid']['vocabulary'] = 'library_branch';
  $handler->display->display_options['filters']['field_library_branch_tid']['hierarchy'] = 1;
  /* Filter criterion: Profile: Date of Birth (field_user_birthday) */
  $handler->display->display_options['filters']['field_user_birthday_value']['id'] = 'field_user_birthday_value';
  $handler->display->display_options['filters']['field_user_birthday_value']['table'] = 'field_data_field_user_birthday';
  $handler->display->display_options['filters']['field_user_birthday_value']['field'] = 'field_user_birthday_value';
  $handler->display->display_options['filters']['field_user_birthday_value']['relationship'] = 'profile';
  $handler->display->display_options['filters']['field_user_birthday_value']['group'] = 1;
  $handler->display->display_options['filters']['field_user_birthday_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_user_birthday_value']['expose']['operator_id'] = 'field_user_birthday_value_op';
  $handler->display->display_options['filters']['field_user_birthday_value']['expose']['label'] = 'DOB Date Range';
  $handler->display->display_options['filters']['field_user_birthday_value']['expose']['use_operator'] = TRUE;
  $handler->display->display_options['filters']['field_user_birthday_value']['expose']['operator'] = 'field_user_birthday_value_op';
  $handler->display->display_options['filters']['field_user_birthday_value']['expose']['identifier'] = 'field_user_birthday_value';
  $handler->display->display_options['filters']['field_user_birthday_value']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
    6 => 0,
    7 => 0,
  );
  $handler->display->display_options['filters']['field_user_birthday_value']['granularity'] = 'year';
  $handler->display->display_options['filters']['field_user_birthday_value']['year_range'] = '1990:+3';
  /* Filter criterion: Profile: School (field_school) */
  $handler->display->display_options['filters']['field_school_tid']['id'] = 'field_school_tid';
  $handler->display->display_options['filters']['field_school_tid']['table'] = 'field_data_field_school';
  $handler->display->display_options['filters']['field_school_tid']['field'] = 'field_school_tid';
  $handler->display->display_options['filters']['field_school_tid']['relationship'] = 'profile';
  $handler->display->display_options['filters']['field_school_tid']['group'] = 1;
  $handler->display->display_options['filters']['field_school_tid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_school_tid']['expose']['operator_id'] = 'field_school_tid_op';
  $handler->display->display_options['filters']['field_school_tid']['expose']['label'] = 'School';
  $handler->display->display_options['filters']['field_school_tid']['expose']['operator'] = 'field_school_tid_op';
  $handler->display->display_options['filters']['field_school_tid']['expose']['identifier'] = 'field_school_tid';
  $handler->display->display_options['filters']['field_school_tid']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
    6 => 0,
    7 => 0,
  );
  $handler->display->display_options['filters']['field_school_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_school_tid']['vocabulary'] = 'schools';
  $handler->display->display_options['filters']['field_school_tid']['hierarchy'] = 1;
  $handler->display->display_options['path'] = 'admin/statistical-reports/full-user-data';
  $export['by_home_library_school_of_users'] = $view;

  $view = new view();
  $view->name = 'registrations_by_home_library';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'users';
  $view->human_name = 'Registrations by Home Library';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Registrations by Home Library';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['access']['perm'] = 'access user profiles';
  $handler->display->display_options['cache']['type'] = 'time';
  $handler->display->display_options['cache']['results_lifespan'] = '518400';
  $handler->display->display_options['cache']['results_lifespan_custom'] = '0';
  $handler->display->display_options['cache']['output_lifespan'] = '518400';
  $handler->display->display_options['cache']['output_lifespan_custom'] = '0';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['style_plugin'] = 'views_aggregator';
  $handler->display->display_options['style_options']['columns'] = array(
    'field_library_branch' => 'field_library_branch',
    'name' => 'name',
    'php' => 'php',
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
      'aggr_par' => 'No Library',
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
    'php' => array(
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
  );
  $handler->display->display_options['style_options']['column_aggregation']['totals_per_page'] = '1';
  $handler->display->display_options['style_options']['column_aggregation']['totals_row_position'] = array(
    1 => 0,
    2 => '2',
  );
  $handler->display->display_options['style_options']['column_aggregation']['precision'] = '2';
  /* Header: Global: PHP */
  $handler->display->display_options['header']['php']['id'] = 'php';
  $handler->display->display_options['header']['php']['table'] = 'views';
  $handler->display->display_options['header']['php']['field'] = 'php';
  $handler->display->display_options['header']['php']['empty'] = TRUE;
  $handler->display->display_options['header']['php']['php_output'] = '<?php
$query = db_select(\'cache_bootstrap\',\'cache\')
->fields(\'cache\', array(\'created\'))
->condition(\'cid\',\'hook_info\')
->execute()
->fetchAll();

$time = $query[0]->created;

echo \'Report last generated on :- \'.date(\'m/d/Y H:i:s\', $time);
?>

';
  /* No results behavior: Global: Text area */
  $handler->display->display_options['empty']['area']['id'] = 'area';
  $handler->display->display_options['empty']['area']['table'] = 'views';
  $handler->display->display_options['empty']['area']['field'] = 'area';
  $handler->display->display_options['empty']['area']['empty'] = TRUE;
  $handler->display->display_options['empty']['area']['content'] = 'No result';
  $handler->display->display_options['empty']['area']['format'] = 'filtered_html';
  /* Field: Profile: Library branch */
  $handler->display->display_options['fields']['field_library_branch']['id'] = 'field_library_branch';
  $handler->display->display_options['fields']['field_library_branch']['table'] = 'field_data_field_library_branch';
  $handler->display->display_options['fields']['field_library_branch']['field'] = 'field_library_branch';
  $handler->display->display_options['fields']['field_library_branch']['relationship'] = 'profile';
  $handler->display->display_options['fields']['field_library_branch']['type'] = 'taxonomy_term_reference_plain';
  /* Field: User: Name */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'users';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['label'] = 'No of users';
  $handler->display->display_options['fields']['name']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['name']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['name']['link_to_user'] = FALSE;
  /* Field: Global: PHP */
  $handler->display->display_options['fields']['php']['id'] = 'php';
  $handler->display->display_options['fields']['php']['table'] = 'views';
  $handler->display->display_options['fields']['php']['field'] = 'php';
  $handler->display->display_options['fields']['php']['label'] = 'Date Report';
  $handler->display->display_options['fields']['php']['use_php_setup'] = 0;
  $handler->display->display_options['fields']['php']['php_output'] = '<?php
$row_index = $view->row_index;
if($row_index == 1){
$query = db_select(\'cache_bootstrap\',\'cache\')
->fields(\'cache\', array(\'created\'))
->condition(\'cid\',\'hook_info\')
->execute()
->fetchAll();

$time = $query[0]->created;
echo \'Report last generated on :- \' . format_date($time, \'custom\', \'D j M Y, H:i:s \');}


?>';
  $handler->display->display_options['fields']['php']['use_php_click_sortable'] = '0';
  $handler->display->display_options['fields']['php']['php_click_sortable'] = '';
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
  $handler->display->display_options['filters']['rid']['operator'] = 'not';
  $handler->display->display_options['filters']['rid']['value'] = array(
    3 => '3',
    6 => '6',
    7 => '7',
  );
  /* Filter criterion: Profile: Date of Birth (field_user_birthday) */
  $handler->display->display_options['filters']['field_user_birthday_value']['id'] = 'field_user_birthday_value';
  $handler->display->display_options['filters']['field_user_birthday_value']['table'] = 'field_data_field_user_birthday';
  $handler->display->display_options['filters']['field_user_birthday_value']['field'] = 'field_user_birthday_value';
  $handler->display->display_options['filters']['field_user_birthday_value']['relationship'] = 'profile';
  $handler->display->display_options['filters']['field_user_birthday_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_user_birthday_value']['expose']['operator_id'] = 'field_user_birthday_value_op';
  $handler->display->display_options['filters']['field_user_birthday_value']['expose']['label'] = 'Date of Birth';
  $handler->display->display_options['filters']['field_user_birthday_value']['expose']['use_operator'] = TRUE;
  $handler->display->display_options['filters']['field_user_birthday_value']['expose']['operator'] = 'field_user_birthday_value_op';
  $handler->display->display_options['filters']['field_user_birthday_value']['expose']['identifier'] = 'field_user_birthday_value';
  $handler->display->display_options['filters']['field_user_birthday_value']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
    6 => 0,
    7 => 0,
  );
  $handler->display->display_options['filters']['field_user_birthday_value']['granularity'] = 'year';
  $handler->display->display_options['filters']['field_user_birthday_value']['year_range'] = '1990:+0';
  /* Filter criterion: Profile: Library branch (field_library_branch) */
  $handler->display->display_options['filters']['field_library_branch_tid']['id'] = 'field_library_branch_tid';
  $handler->display->display_options['filters']['field_library_branch_tid']['table'] = 'field_data_field_library_branch';
  $handler->display->display_options['filters']['field_library_branch_tid']['field'] = 'field_library_branch_tid';
  $handler->display->display_options['filters']['field_library_branch_tid']['relationship'] = 'profile';
  $handler->display->display_options['filters']['field_library_branch_tid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_library_branch_tid']['expose']['operator_id'] = 'field_library_branch_tid_op';
  $handler->display->display_options['filters']['field_library_branch_tid']['expose']['label'] = 'Library branch';
  $handler->display->display_options['filters']['field_library_branch_tid']['expose']['use_operator'] = TRUE;
  $handler->display->display_options['filters']['field_library_branch_tid']['expose']['operator'] = 'field_library_branch_tid_op';
  $handler->display->display_options['filters']['field_library_branch_tid']['expose']['identifier'] = 'field_library_branch_tid';
  $handler->display->display_options['filters']['field_library_branch_tid']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
    6 => 0,
    7 => 0,
  );
  $handler->display->display_options['filters']['field_library_branch_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_library_branch_tid']['vocabulary'] = 'library_branch';
  $handler->display->display_options['filters']['field_library_branch_tid']['hierarchy'] = 1;
  /* Filter criterion: Profile: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'profile';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['relationship'] = 'profile';
  $handler->display->display_options['filters']['type']['value'] = array(
    'main' => 'main',
  );
  /* Filter criterion: Profile: School (field_school) */
  $handler->display->display_options['filters']['field_school_tid']['id'] = 'field_school_tid';
  $handler->display->display_options['filters']['field_school_tid']['table'] = 'field_data_field_school';
  $handler->display->display_options['filters']['field_school_tid']['field'] = 'field_school_tid';
  $handler->display->display_options['filters']['field_school_tid']['relationship'] = 'profile';
  $handler->display->display_options['filters']['field_school_tid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_school_tid']['expose']['operator_id'] = 'field_school_tid_op';
  $handler->display->display_options['filters']['field_school_tid']['expose']['label'] = 'School Filter';
  $handler->display->display_options['filters']['field_school_tid']['expose']['use_operator'] = TRUE;
  $handler->display->display_options['filters']['field_school_tid']['expose']['operator'] = 'field_school_tid_op';
  $handler->display->display_options['filters']['field_school_tid']['expose']['identifier'] = 'field_school_tid';
  $handler->display->display_options['filters']['field_school_tid']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
    6 => 0,
    7 => 0,
  );
  $handler->display->display_options['filters']['field_school_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_school_tid']['vocabulary'] = 'schools';
  $handler->display->display_options['filters']['field_school_tid']['hierarchy'] = 1;

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  /* Relationship: User: Profile */
  $handler->display->display_options['relationships']['profile']['id'] = 'profile';
  $handler->display->display_options['relationships']['profile']['table'] = 'users';
  $handler->display->display_options['relationships']['profile']['field'] = 'profile';
  $handler->display->display_options['relationships']['profile']['bundle_types'] = array(
    'main' => 'main',
  );
  $handler->display->display_options['path'] = 'admin/statistical-reports/registrations-by-home-library';
  $export['registrations_by_home_library'] = $view;

  $view = new view();
  $view->name = 'statistical_reports';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'users';
  $view->human_name = 'Statistical Reports';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Statistical Reports';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['access']['perm'] = 'access user profiles';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['style_plugin'] = 'views_aggregator';
  $handler->display->display_options['style_options']['columns'] = array(
    'field_user_birthday' => 'field_user_birthday',
    'name' => 'name',
    'php' => 'php',
  );
  $handler->display->display_options['style_options']['default'] = '-1';
  $handler->display->display_options['style_options']['info'] = array(
    'field_user_birthday' => array(
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
    'php' => array(
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
  );
  $handler->display->display_options['style_options']['column_aggregation']['totals_per_page'] = '0';
  $handler->display->display_options['style_options']['column_aggregation']['totals_row_position'] = array(
    1 => 0,
    2 => '2',
  );
  $handler->display->display_options['style_options']['column_aggregation']['precision'] = '2';
  /* Field: User: Name */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'users';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['label'] = '';
  $handler->display->display_options['fields']['name']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['name']['alter']['ellipsis'] = FALSE;
  /* Filter criterion: User: Active */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'users';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = '1';
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;

  /* Display: Registrations By Age */
  $handler = $view->new_display('page', 'Registrations By Age', 'page');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Registrations By Age';
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  /* Relationship: User: Profile */
  $handler->display->display_options['relationships']['profile']['id'] = 'profile';
  $handler->display->display_options['relationships']['profile']['table'] = 'users';
  $handler->display->display_options['relationships']['profile']['field'] = 'profile';
  $handler->display->display_options['relationships']['profile']['bundle_types'] = array(
    'main' => 'main',
  );
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Profile: Date of Birth */
  $handler->display->display_options['fields']['field_user_birthday']['id'] = 'field_user_birthday';
  $handler->display->display_options['fields']['field_user_birthday']['table'] = 'field_data_field_user_birthday';
  $handler->display->display_options['fields']['field_user_birthday']['field'] = 'field_user_birthday';
  $handler->display->display_options['fields']['field_user_birthday']['relationship'] = 'profile';
  $handler->display->display_options['fields']['field_user_birthday']['label'] = 'Date of Birth(Age)';
  $handler->display->display_options['fields']['field_user_birthday']['type'] = 'format_interval';
  $handler->display->display_options['fields']['field_user_birthday']['settings'] = array(
    'interval' => '1',
    'interval_display' => 'raw time ago',
  );
  /* Field: User: Name */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'users';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['label'] = 'No of users';
  $handler->display->display_options['fields']['name']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['name']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['name']['link_to_user'] = FALSE;
  /* Field: Global: PHP */
  $handler->display->display_options['fields']['php']['id'] = 'php';
  $handler->display->display_options['fields']['php']['table'] = 'views';
  $handler->display->display_options['fields']['php']['field'] = 'php';
  $handler->display->display_options['fields']['php']['label'] = 'Date Report';
  $handler->display->display_options['fields']['php']['use_php_setup'] = 0;
  $handler->display->display_options['fields']['php']['php_output'] = '<?php
$row_index = $view->row_index;
if($row_index == 1){
$query = db_select(\'cache_bootstrap\',\'cache\')
->fields(\'cache\', array(\'created\'))
->condition(\'cid\',\'hook_info\')
->execute()
->fetchAll();

$time = $query[0]->created;
echo \'Report last generated on :- \' . format_date($time, \'custom\', \'D j M Y, H:i:s \');}


?>';
  $handler->display->display_options['fields']['php']['use_php_click_sortable'] = '0';
  $handler->display->display_options['fields']['php']['php_click_sortable'] = '';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Profile: Date of Birth (field_user_birthday) */
  $handler->display->display_options['filters']['field_user_birthday_value']['id'] = 'field_user_birthday_value';
  $handler->display->display_options['filters']['field_user_birthday_value']['table'] = 'field_data_field_user_birthday';
  $handler->display->display_options['filters']['field_user_birthday_value']['field'] = 'field_user_birthday_value';
  $handler->display->display_options['filters']['field_user_birthday_value']['relationship'] = 'profile';
  $handler->display->display_options['filters']['field_user_birthday_value']['group'] = 1;
  $handler->display->display_options['filters']['field_user_birthday_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_user_birthday_value']['expose']['operator_id'] = 'field_user_birthday_value_op';
  $handler->display->display_options['filters']['field_user_birthday_value']['expose']['label'] = 'Date of Birth';
  $handler->display->display_options['filters']['field_user_birthday_value']['expose']['use_operator'] = TRUE;
  $handler->display->display_options['filters']['field_user_birthday_value']['expose']['operator'] = 'field_user_birthday_value_op';
  $handler->display->display_options['filters']['field_user_birthday_value']['expose']['identifier'] = 'field_user_birthday_value';
  $handler->display->display_options['filters']['field_user_birthday_value']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
    6 => 0,
    7 => 0,
  );
  $handler->display->display_options['filters']['field_user_birthday_value']['granularity'] = 'year';
  $handler->display->display_options['filters']['field_user_birthday_value']['year_range'] = '1990:+10';
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
  $handler->display->display_options['filters']['rid']['operator'] = 'not';
  $handler->display->display_options['filters']['rid']['value'] = array(
    3 => '3',
    6 => '6',
    7 => '7',
  );
  /* Filter criterion: Profile: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'profile';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['relationship'] = 'profile';
  $handler->display->display_options['filters']['type']['value'] = array(
    'main' => 'main',
  );
  /* Filter criterion: Profile: Library branch (field_library_branch) */
  $handler->display->display_options['filters']['field_library_branch_tid']['id'] = 'field_library_branch_tid';
  $handler->display->display_options['filters']['field_library_branch_tid']['table'] = 'field_data_field_library_branch';
  $handler->display->display_options['filters']['field_library_branch_tid']['field'] = 'field_library_branch_tid';
  $handler->display->display_options['filters']['field_library_branch_tid']['relationship'] = 'profile';
  $handler->display->display_options['filters']['field_library_branch_tid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_library_branch_tid']['expose']['operator_id'] = 'field_library_branch_tid_op';
  $handler->display->display_options['filters']['field_library_branch_tid']['expose']['label'] = 'Library branch';
  $handler->display->display_options['filters']['field_library_branch_tid']['expose']['use_operator'] = TRUE;
  $handler->display->display_options['filters']['field_library_branch_tid']['expose']['operator'] = 'field_library_branch_tid_op';
  $handler->display->display_options['filters']['field_library_branch_tid']['expose']['identifier'] = 'field_library_branch_tid';
  $handler->display->display_options['filters']['field_library_branch_tid']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
    6 => 0,
    7 => 0,
  );
  $handler->display->display_options['filters']['field_library_branch_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_library_branch_tid']['vocabulary'] = 'library_branch';
  $handler->display->display_options['filters']['field_library_branch_tid']['hierarchy'] = 1;
  /* Filter criterion: Profile: School (field_school) */
  $handler->display->display_options['filters']['field_school_tid']['id'] = 'field_school_tid';
  $handler->display->display_options['filters']['field_school_tid']['table'] = 'field_data_field_school';
  $handler->display->display_options['filters']['field_school_tid']['field'] = 'field_school_tid';
  $handler->display->display_options['filters']['field_school_tid']['relationship'] = 'profile';
  $handler->display->display_options['filters']['field_school_tid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_school_tid']['expose']['operator_id'] = 'field_school_tid_op';
  $handler->display->display_options['filters']['field_school_tid']['expose']['label'] = 'School Filter';
  $handler->display->display_options['filters']['field_school_tid']['expose']['use_operator'] = TRUE;
  $handler->display->display_options['filters']['field_school_tid']['expose']['operator'] = 'field_school_tid_op';
  $handler->display->display_options['filters']['field_school_tid']['expose']['identifier'] = 'field_school_tid';
  $handler->display->display_options['filters']['field_school_tid']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
    6 => 0,
    7 => 0,
  );
  $handler->display->display_options['filters']['field_school_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_school_tid']['vocabulary'] = 'schools';
  $handler->display->display_options['filters']['field_school_tid']['hierarchy'] = 1;
  $handler->display->display_options['path'] = 'statistical-reports/registrations-by-age';
  $export['statistical_reports'] = $view;

  return $export;
}

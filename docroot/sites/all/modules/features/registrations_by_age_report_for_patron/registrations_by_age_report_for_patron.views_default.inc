<?php
/**
 * @file
 * registrations_by_age_report_for_patron.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function registrations_by_age_report_for_patron_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'registrations_by_age';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'users';
  $view->human_name = 'Registrations By Age';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Registrations By Age';
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
  /* Relationship: User: Profile */
  $handler->display->display_options['relationships']['profile']['id'] = 'profile';
  $handler->display->display_options['relationships']['profile']['table'] = 'users';
  $handler->display->display_options['relationships']['profile']['field'] = 'profile';
  $handler->display->display_options['relationships']['profile']['bundle_types'] = array(
    'main' => 'main',
  );
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
  /* Sort criterion: User: Created date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'users';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
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

  /* Display: Registrations By Age */
  $handler = $view->new_display('page', 'Registrations By Age', 'page');
  $handler->display->display_options['path'] = 'registrations-by-age';
  $export['registrations_by_age'] = $view;

  return $export;
}

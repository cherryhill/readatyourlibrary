<?php
/**
 * @file
 * feature_for_raffle_winners_list.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function feature_for_raffle_winners_list_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'raffle_winners';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'eck_reward';
  $view->human_name = 'Raffle Winners';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Reward Winners';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'none';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '10';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Field: Reward: Id */
  $handler->display->display_options['fields']['id']['id'] = 'id';
  $handler->display->display_options['fields']['id']['table'] = 'eck_reward';
  $handler->display->display_options['fields']['id']['field'] = 'id';
  /* Filter criterion: Reward: reward type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'eck_reward';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'reward_claim' => 'reward_claim',
  );

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'uid' => 'uid',
  );
  $handler->display->display_options['style_options']['default'] = '-1';
  $handler->display->display_options['style_options']['info'] = array(
    'uid' => array(
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
  /* Relationship: Reward: Author */
  $handler->display->display_options['relationships']['uid']['id'] = 'uid';
  $handler->display->display_options['relationships']['uid']['table'] = 'eck_reward';
  $handler->display->display_options['relationships']['uid']['field'] = 'uid';
  /* Relationship: User: Profile */
  $handler->display->display_options['relationships']['profile']['id'] = 'profile';
  $handler->display->display_options['relationships']['profile']['table'] = 'users';
  $handler->display->display_options['relationships']['profile']['field'] = 'profile';
  $handler->display->display_options['relationships']['profile']['relationship'] = 'uid';
  /* Relationship: Entity Reference: Referenced Entity */
  $handler->display->display_options['relationships']['field_reward_claim_id_target_id']['id'] = 'field_reward_claim_id_target_id';
  $handler->display->display_options['relationships']['field_reward_claim_id_target_id']['table'] = 'field_data_field_reward_claim_id';
  $handler->display->display_options['relationships']['field_reward_claim_id_target_id']['field'] = 'field_reward_claim_id_target_id';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Reward: Id */
  $handler->display->display_options['fields']['id']['id'] = 'id';
  $handler->display->display_options['fields']['id']['table'] = 'eck_reward';
  $handler->display->display_options['fields']['id']['field'] = 'id';
  $handler->display->display_options['fields']['id']['exclude'] = TRUE;
  /* Field: Profile: Last name */
  $handler->display->display_options['fields']['field_last_name']['id'] = 'field_last_name';
  $handler->display->display_options['fields']['field_last_name']['table'] = 'field_data_field_last_name';
  $handler->display->display_options['fields']['field_last_name']['field'] = 'field_last_name';
  $handler->display->display_options['fields']['field_last_name']['relationship'] = 'profile';
  /* Field: Profile: First Name */
  $handler->display->display_options['fields']['field_first_name']['id'] = 'field_first_name';
  $handler->display->display_options['fields']['field_first_name']['table'] = 'field_data_field_first_name';
  $handler->display->display_options['fields']['field_first_name']['field'] = 'field_first_name';
  $handler->display->display_options['fields']['field_first_name']['relationship'] = 'profile';
  /* Field: User: Name */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'users';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['relationship'] = 'uid';
  $handler->display->display_options['fields']['name']['label'] = 'UserName';
  /* Field: User: Roles */
  $handler->display->display_options['fields']['rid']['id'] = 'rid';
  $handler->display->display_options['fields']['rid']['table'] = 'users_roles';
  $handler->display->display_options['fields']['rid']['field'] = 'rid';
  $handler->display->display_options['fields']['rid']['relationship'] = 'uid';
  /* Field: Profile: Phone number */
  $handler->display->display_options['fields']['field_phone_number']['id'] = 'field_phone_number';
  $handler->display->display_options['fields']['field_phone_number']['table'] = 'field_data_field_phone_number';
  $handler->display->display_options['fields']['field_phone_number']['field'] = 'field_phone_number';
  $handler->display->display_options['fields']['field_phone_number']['relationship'] = 'profile';
  $handler->display->display_options['fields']['field_phone_number']['settings'] = array(
    'phone_link' => 0,
  );
  /* Field: Reward: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'eck_reward';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = 'Name of Reward';
  /* Field: Reward: Raffle Drawing Name */
  $handler->display->display_options['fields']['field_rf_drawing_name']['id'] = 'field_rf_drawing_name';
  $handler->display->display_options['fields']['field_rf_drawing_name']['table'] = 'field_data_field_rf_drawing_name';
  $handler->display->display_options['fields']['field_rf_drawing_name']['field'] = 'field_rf_drawing_name';
  /* Field: Reward: Filters Used */
  $handler->display->display_options['fields']['field_filters_used']['id'] = 'field_filters_used';
  $handler->display->display_options['fields']['field_filters_used']['table'] = 'field_data_field_filters_used';
  $handler->display->display_options['fields']['field_filters_used']['field'] = 'field_filters_used';
  /* Field: Global: PHP */
  $handler->display->display_options['fields']['php_4']['id'] = 'php_4';
  $handler->display->display_options['fields']['php_4']['table'] = 'views';
  $handler->display->display_options['fields']['php_4']['field'] = 'php';
  $handler->display->display_options['fields']['php_4']['label'] = 'Staff User';
  $handler->display->display_options['fields']['php_4']['use_php_setup'] = 0;
  $handler->display->display_options['fields']['php_4']['php_output'] = '<?php
$query = db_select(\'field_data_field_staff_user\',\'notes\')
->fields(\'notes\', array(\'field_staff_user_value\'))
->condition(\'entity_id\',$row->id)
->execute()
->fetchAssoc();

echo $query[\'field_staff_user_value\'];


?>';
  $handler->display->display_options['fields']['php_4']['use_php_click_sortable'] = '0';
  $handler->display->display_options['fields']['php_4']['php_click_sortable'] = '';
  /* Field: Global: PHP */
  $handler->display->display_options['fields']['php_2']['id'] = 'php_2';
  $handler->display->display_options['fields']['php_2']['table'] = 'views';
  $handler->display->display_options['fields']['php_2']['field'] = 'php';
  $handler->display->display_options['fields']['php_2']['label'] = 'Receieving Status';
  $handler->display->display_options['fields']['php_2']['use_php_setup'] = 0;
  $handler->display->display_options['fields']['php_2']['php_output'] = '<?php
$query = db_select(\'field_data_field_receieving_status\',\'status\')
->fields(\'status\', array(\'field_receieving_status_value\'))
->condition(\'entity_id\',$row->id)
->execute()
->fetchAssoc();

$status = $query[\'field_receieving_status_value\'];

if ($status == 1) {
echo \'Receieved\';
}

?>';
  $handler->display->display_options['fields']['php_2']['use_php_click_sortable'] = '0';
  $handler->display->display_options['fields']['php_2']['php_click_sortable'] = '';
  /* Field: Global: PHP */
  $handler->display->display_options['fields']['php_1']['id'] = 'php_1';
  $handler->display->display_options['fields']['php_1']['table'] = 'views';
  $handler->display->display_options['fields']['php_1']['field'] = 'php';
  $handler->display->display_options['fields']['php_1']['label'] = 'reward pickup date';
  $handler->display->display_options['fields']['php_1']['use_php_setup'] = 0;
  $handler->display->display_options['fields']['php_1']['php_output'] = '<?php
$query = db_select(\'field_data_field_rf_pickup_date\',\'date\')
->fields(\'date\', array(\'field_rf_pickup_date_value\'))
->condition(\'entity_id\',$row->id)
->execute()
->fetchAssoc();

$date = $query[\'field_rf_pickup_date_value\'];

echo substr($date, 0, -8);
?>';
  $handler->display->display_options['fields']['php_1']['use_php_click_sortable'] = '0';
  $handler->display->display_options['fields']['php_1']['php_click_sortable'] = '';
  /* Field: Global: PHP */
  $handler->display->display_options['fields']['php']['id'] = 'php';
  $handler->display->display_options['fields']['php']['table'] = 'views';
  $handler->display->display_options['fields']['php']['field'] = 'php';
  $handler->display->display_options['fields']['php']['label'] = 'Staff Notes';
  $handler->display->display_options['fields']['php']['use_php_setup'] = 0;
  $handler->display->display_options['fields']['php']['php_output'] = '<?php
$query = db_select(\'field_data_field_staff_notes\',\'notes\')
->fields(\'notes\', array(\'field_staff_notes_value\'))
->condition(\'entity_id\',$row->id)
->execute()
->fetchAssoc();

echo $query[\'field_staff_notes_value\'];


?>';
  $handler->display->display_options['fields']['php']['use_php_click_sortable'] = '0';
  $handler->display->display_options['fields']['php']['php_click_sortable'] = '';
  /* Field: Global: PHP */
  $handler->display->display_options['fields']['php_3']['id'] = 'php_3';
  $handler->display->display_options['fields']['php_3']['table'] = 'views';
  $handler->display->display_options['fields']['php_3']['field'] = 'php';
  $handler->display->display_options['fields']['php_3']['label'] = 'Action';
  $handler->display->display_options['fields']['php_3']['use_php_setup'] = 0;
  $handler->display->display_options['fields']['php_3']['php_output'] = '<?php
echo \'<a href =\'.\'receive-reward/\'.$row->id.\'>edit</a>\';
?>';
  $handler->display->display_options['fields']['php_3']['use_php_click_sortable'] = '0';
  $handler->display->display_options['fields']['php_3']['php_click_sortable'] = '';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['filter_groups']['groups'] = array(
    1 => 'AND',
    2 => 'OR',
  );
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Reward: reward type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'eck_reward';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'reward_claim' => 'reward_claim',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;
  /* Filter criterion: Reward: Type of reward/raffle prize (field_type_of_reward_raffle_priz) */
  $handler->display->display_options['filters']['field_type_of_reward_raffle_priz_tid']['id'] = 'field_type_of_reward_raffle_priz_tid';
  $handler->display->display_options['filters']['field_type_of_reward_raffle_priz_tid']['table'] = 'field_data_field_type_of_reward_raffle_priz';
  $handler->display->display_options['filters']['field_type_of_reward_raffle_priz_tid']['field'] = 'field_type_of_reward_raffle_priz_tid';
  $handler->display->display_options['filters']['field_type_of_reward_raffle_priz_tid']['relationship'] = 'field_reward_claim_id_target_id';
  $handler->display->display_options['filters']['field_type_of_reward_raffle_priz_tid']['value'] = array(
    1 => '1',
  );
  $handler->display->display_options['filters']['field_type_of_reward_raffle_priz_tid']['group'] = 2;
  $handler->display->display_options['filters']['field_type_of_reward_raffle_priz_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_type_of_reward_raffle_priz_tid']['vocabulary'] = 'type_of_reward';
  $handler->display->display_options['filters']['field_type_of_reward_raffle_priz_tid']['hierarchy'] = 1;
  /* Filter criterion: Reward: Raffle Claim (field_raffle_claim) */
  $handler->display->display_options['filters']['field_raffle_claim_value']['id'] = 'field_raffle_claim_value';
  $handler->display->display_options['filters']['field_raffle_claim_value']['table'] = 'field_data_field_raffle_claim';
  $handler->display->display_options['filters']['field_raffle_claim_value']['field'] = 'field_raffle_claim_value';
  $handler->display->display_options['filters']['field_raffle_claim_value']['value']['value'] = '1';
  $handler->display->display_options['filters']['field_raffle_claim_value']['group'] = 2;
  $handler->display->display_options['path'] = 'reward-winners';
  $export['raffle_winners'] = $view;

  return $export;
}

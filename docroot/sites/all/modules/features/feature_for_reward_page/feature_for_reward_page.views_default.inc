<?php
/**
 * @file
 * feature_for_reward_page.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function feature_for_reward_page_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'my_reward_blocks_on_reward_page_sidebar';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'eck_reward';
  $view->human_name = 'My reward blocks on reward page sidebar';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'My reward blocks on reward page sidebar';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'none';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '8';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Field: Reward: Id */
  $handler->display->display_options['fields']['id']['id'] = 'id';
  $handler->display->display_options['fields']['id']['table'] = 'eck_reward';
  $handler->display->display_options['fields']['id']['field'] = 'id';
  /* Sort criterion: Reward: Created */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'eck_reward';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  /* Contextual filter: Reward: Author */
  $handler->display->display_options['arguments']['uid']['id'] = 'uid';
  $handler->display->display_options['arguments']['uid']['table'] = 'eck_reward';
  $handler->display->display_options['arguments']['uid']['field'] = 'uid';
  $handler->display->display_options['arguments']['uid']['default_action'] = 'default';
  $handler->display->display_options['arguments']['uid']['default_argument_type'] = 'current_user';
  $handler->display->display_options['arguments']['uid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['uid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['uid']['summary_options']['items_per_page'] = '25';
  /* Filter criterion: Reward: reward type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'eck_reward';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'reward' => 'reward',
  );

  /* Display: My Rewards */
  $handler = $view->new_display('block', 'My Rewards', 'block');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'My Rewards';
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  /* Relationship: Reward: Type of reward/raffle prize (field_type_of_reward_raffle_priz) */
  $handler->display->display_options['relationships']['field_type_of_reward_raffle_priz_tid']['id'] = 'field_type_of_reward_raffle_priz_tid';
  $handler->display->display_options['relationships']['field_type_of_reward_raffle_priz_tid']['table'] = 'field_data_field_type_of_reward_raffle_priz';
  $handler->display->display_options['relationships']['field_type_of_reward_raffle_priz_tid']['field'] = 'field_type_of_reward_raffle_priz_tid';
  /* Relationship: Entity Reference: Referenced Entity */
  $handler->display->display_options['relationships']['field_reward_claim_id_target_id']['id'] = 'field_reward_claim_id_target_id';
  $handler->display->display_options['relationships']['field_reward_claim_id_target_id']['table'] = 'field_data_field_reward_claim_id';
  $handler->display->display_options['relationships']['field_reward_claim_id_target_id']['field'] = 'field_reward_claim_id_target_id';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Reward: Raffle prize or reward image */
  $handler->display->display_options['fields']['field_raffle_prize_or_reward_ima']['id'] = 'field_raffle_prize_or_reward_ima';
  $handler->display->display_options['fields']['field_raffle_prize_or_reward_ima']['table'] = 'field_data_field_raffle_prize_or_reward_ima';
  $handler->display->display_options['fields']['field_raffle_prize_or_reward_ima']['field'] = 'field_raffle_prize_or_reward_ima';
  $handler->display->display_options['fields']['field_raffle_prize_or_reward_ima']['relationship'] = 'field_reward_claim_id_target_id';
  $handler->display->display_options['fields']['field_raffle_prize_or_reward_ima']['label'] = '';
  $handler->display->display_options['fields']['field_raffle_prize_or_reward_ima']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_raffle_prize_or_reward_ima']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_raffle_prize_or_reward_ima']['settings'] = array(
    'image_style' => 'thumbnail',
    'image_link' => '',
  );
  /* Field: Reward: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'eck_reward';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['exclude'] = TRUE;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  /* Field: Global: PHP */
  $handler->display->display_options['fields']['php']['id'] = 'php';
  $handler->display->display_options['fields']['php']['table'] = 'views';
  $handler->display->display_options['fields']['php']['field'] = 'php';
  $handler->display->display_options['fields']['php']['label'] = '';
  $handler->display->display_options['fields']['php']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['php']['use_php_setup'] = 0;
  $handler->display->display_options['fields']['php']['php_output'] = '<?php 
echo substr($row->title ,0,-20);
?>';
  $handler->display->display_options['fields']['php']['use_php_click_sortable'] = '0';
  $handler->display->display_options['fields']['php']['php_click_sortable'] = '';
  /* Field: Reward: Created */
  $handler->display->display_options['fields']['created']['id'] = 'created';
  $handler->display->display_options['fields']['created']['table'] = 'eck_reward';
  $handler->display->display_options['fields']['created']['field'] = 'created';
  $handler->display->display_options['fields']['created']['label'] = '';
  $handler->display->display_options['fields']['created']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['created']['alter']['text'] = 'Picked up on [created] ';
  $handler->display->display_options['fields']['created']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['created']['date_format'] = 'privatemsg_years';
  $handler->display->display_options['fields']['created']['second_date_format'] = 'privatemsg_current_day';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Reward: reward type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'eck_reward';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'reward_claim' => 'reward_claim',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;
  $handler->display->display_options['block_description'] = 'My Rewards block for reward page';

  /* Display: My Badges */
  $handler = $view->new_display('block', 'My Badges', 'block_1');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'My Badges';
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  /* Relationship: Reward: Type of reward/raffle prize (field_type_of_reward_raffle_priz) */
  $handler->display->display_options['relationships']['field_type_of_reward_raffle_priz_tid']['id'] = 'field_type_of_reward_raffle_priz_tid';
  $handler->display->display_options['relationships']['field_type_of_reward_raffle_priz_tid']['table'] = 'field_data_field_type_of_reward_raffle_priz';
  $handler->display->display_options['relationships']['field_type_of_reward_raffle_priz_tid']['field'] = 'field_type_of_reward_raffle_priz_tid';
  /* Relationship: Entity Reference: Referenced Entity */
  $handler->display->display_options['relationships']['field_reward_claim_id_target_id']['id'] = 'field_reward_claim_id_target_id';
  $handler->display->display_options['relationships']['field_reward_claim_id_target_id']['table'] = 'field_data_field_reward_claim_id';
  $handler->display->display_options['relationships']['field_reward_claim_id_target_id']['field'] = 'field_reward_claim_id_target_id';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Reward: Raffle prize or reward image */
  $handler->display->display_options['fields']['field_raffle_prize_or_reward_ima']['id'] = 'field_raffle_prize_or_reward_ima';
  $handler->display->display_options['fields']['field_raffle_prize_or_reward_ima']['table'] = 'field_data_field_raffle_prize_or_reward_ima';
  $handler->display->display_options['fields']['field_raffle_prize_or_reward_ima']['field'] = 'field_raffle_prize_or_reward_ima';
  $handler->display->display_options['fields']['field_raffle_prize_or_reward_ima']['relationship'] = 'field_reward_claim_id_target_id';
  $handler->display->display_options['fields']['field_raffle_prize_or_reward_ima']['label'] = '';
  $handler->display->display_options['fields']['field_raffle_prize_or_reward_ima']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_raffle_prize_or_reward_ima']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_raffle_prize_or_reward_ima']['settings'] = array(
    'image_style' => 'thumbnail',
    'image_link' => '',
  );
  /* Field: Reward: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'eck_reward';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['exclude'] = TRUE;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  /* Field: Global: PHP */
  $handler->display->display_options['fields']['php']['id'] = 'php';
  $handler->display->display_options['fields']['php']['table'] = 'views';
  $handler->display->display_options['fields']['php']['field'] = 'php';
  $handler->display->display_options['fields']['php']['label'] = '';
  $handler->display->display_options['fields']['php']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['php']['use_php_setup'] = 0;
  $handler->display->display_options['fields']['php']['php_output'] = '<?php 
echo substr($row->title ,0,-20);
?>';
  $handler->display->display_options['fields']['php']['use_php_click_sortable'] = '0';
  $handler->display->display_options['fields']['php']['php_click_sortable'] = '';
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Reward: Author */
  $handler->display->display_options['arguments']['uid']['id'] = 'uid';
  $handler->display->display_options['arguments']['uid']['table'] = 'eck_reward';
  $handler->display->display_options['arguments']['uid']['field'] = 'uid';
  $handler->display->display_options['arguments']['uid']['default_action'] = 'default';
  $handler->display->display_options['arguments']['uid']['default_argument_type'] = 'current_user';
  $handler->display->display_options['arguments']['uid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['uid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['uid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
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
    2 => '2',
  );
  $handler->display->display_options['filters']['field_type_of_reward_raffle_priz_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_type_of_reward_raffle_priz_tid']['vocabulary'] = 'type_of_reward';
  $handler->display->display_options['filters']['field_type_of_reward_raffle_priz_tid']['hierarchy'] = 1;
  $handler->display->display_options['block_description'] = 'My Badges for rewrad page';
  $export['my_reward_blocks_on_reward_page_sidebar'] = $view;

  $view = new view();
  $view->name = 'reading_badge_views';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'eck_reward';
  $view->human_name = 'Reward page badges views';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'reading badge views';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'none';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Relationship: Entityqueue: Reward Queue */
  $handler->display->display_options['relationships']['entityqueue_relationship']['id'] = 'entityqueue_relationship';
  $handler->display->display_options['relationships']['entityqueue_relationship']['table'] = 'eck_reward';
  $handler->display->display_options['relationships']['entityqueue_relationship']['field'] = 'entityqueue_relationship';
  $handler->display->display_options['relationships']['entityqueue_relationship']['limit'] = 1;
  $handler->display->display_options['relationships']['entityqueue_relationship']['queues'] = array(
    'badges_for_reading' => 'badges_for_reading',
    'other_badges' => 0,
  );
  /* Field: Reward: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'eck_reward';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  /* Field: Reward: Raffle prize or reward image */
  $handler->display->display_options['fields']['field_raffle_prize_or_reward_ima']['id'] = 'field_raffle_prize_or_reward_ima';
  $handler->display->display_options['fields']['field_raffle_prize_or_reward_ima']['table'] = 'field_data_field_raffle_prize_or_reward_ima';
  $handler->display->display_options['fields']['field_raffle_prize_or_reward_ima']['field'] = 'field_raffle_prize_or_reward_ima';
  $handler->display->display_options['fields']['field_raffle_prize_or_reward_ima']['label'] = '';
  $handler->display->display_options['fields']['field_raffle_prize_or_reward_ima']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_raffle_prize_or_reward_ima']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_raffle_prize_or_reward_ima']['settings'] = array(
    'image_style' => 'thumbnail',
    'image_link' => '',
  );
  /* Filter criterion: Reward: reward type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'eck_reward';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'reward' => 'reward',
  );
  /* Filter criterion: Entityqueue: Reward In Queue */
  $handler->display->display_options['filters']['entityqueue_relationship']['id'] = 'entityqueue_relationship';
  $handler->display->display_options['filters']['entityqueue_relationship']['table'] = 'eck_reward';
  $handler->display->display_options['filters']['entityqueue_relationship']['field'] = 'entityqueue_relationship';
  $handler->display->display_options['filters']['entityqueue_relationship']['value'] = '1';

  /* Display: Badges for Reading */
  $handler = $view->new_display('block', 'Badges for Reading', 'block');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Badges for Reading';
  $handler->display->display_options['defaults']['header'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Reward: Raffle prize or reward image */
  $handler->display->display_options['fields']['field_raffle_prize_or_reward_ima']['id'] = 'field_raffle_prize_or_reward_ima';
  $handler->display->display_options['fields']['field_raffle_prize_or_reward_ima']['table'] = 'field_data_field_raffle_prize_or_reward_ima';
  $handler->display->display_options['fields']['field_raffle_prize_or_reward_ima']['field'] = 'field_raffle_prize_or_reward_ima';
  $handler->display->display_options['fields']['field_raffle_prize_or_reward_ima']['label'] = '';
  $handler->display->display_options['fields']['field_raffle_prize_or_reward_ima']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_raffle_prize_or_reward_ima']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_raffle_prize_or_reward_ima']['settings'] = array(
    'image_style' => 'thumbnail',
    'image_link' => '',
  );
  /* Field: Reward: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'eck_reward';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['block_description'] = 'Badges for Reading';

  /* Display: Other badges */
  $handler = $view->new_display('block', 'Other badges', 'block_1');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Other badges';
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  /* Relationship: Entityqueue: Reward Queue */
  $handler->display->display_options['relationships']['entityqueue_relationship']['id'] = 'entityqueue_relationship';
  $handler->display->display_options['relationships']['entityqueue_relationship']['table'] = 'eck_reward';
  $handler->display->display_options['relationships']['entityqueue_relationship']['field'] = 'entityqueue_relationship';
  $handler->display->display_options['relationships']['entityqueue_relationship']['limit'] = 1;
  $handler->display->display_options['relationships']['entityqueue_relationship']['queues'] = array(
    'other_badges' => 'other_badges',
    'badges_for_reading' => 0,
  );
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Reward: Raffle prize or reward image */
  $handler->display->display_options['fields']['field_raffle_prize_or_reward_ima']['id'] = 'field_raffle_prize_or_reward_ima';
  $handler->display->display_options['fields']['field_raffle_prize_or_reward_ima']['table'] = 'field_data_field_raffle_prize_or_reward_ima';
  $handler->display->display_options['fields']['field_raffle_prize_or_reward_ima']['field'] = 'field_raffle_prize_or_reward_ima';
  $handler->display->display_options['fields']['field_raffle_prize_or_reward_ima']['label'] = '';
  $handler->display->display_options['fields']['field_raffle_prize_or_reward_ima']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_raffle_prize_or_reward_ima']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_raffle_prize_or_reward_ima']['settings'] = array(
    'image_style' => 'thumbnail',
    'image_link' => '',
  );
  /* Field: Reward: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'eck_reward';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['block_description'] = 'Other badges';

  /* Display: Badges for Reviews */
  $handler = $view->new_display('block', 'Badges for Reviews', 'block_2');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Badges for Reviews';
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  /* Relationship: Entityqueue: Reward Queue */
  $handler->display->display_options['relationships']['entityqueue_relationship']['id'] = 'entityqueue_relationship';
  $handler->display->display_options['relationships']['entityqueue_relationship']['table'] = 'eck_reward';
  $handler->display->display_options['relationships']['entityqueue_relationship']['field'] = 'entityqueue_relationship';
  $handler->display->display_options['relationships']['entityqueue_relationship']['limit'] = 1;
  $handler->display->display_options['relationships']['entityqueue_relationship']['queues'] = array(
    'badges_for_reviews' => 'badges_for_reviews',
    'badges_for_reading' => 0,
    'other_badges' => 0,
    'badges_for_booklists' => 0,
  );
  $handler->display->display_options['block_description'] = 'Badges for Reviews';

  /* Display: Badges for Booklists */
  $handler = $view->new_display('block', 'Badges for Booklists', 'block_3');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Badges for Booklists';
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  /* Relationship: Entityqueue: Reward Queue */
  $handler->display->display_options['relationships']['entityqueue_relationship']['id'] = 'entityqueue_relationship';
  $handler->display->display_options['relationships']['entityqueue_relationship']['table'] = 'eck_reward';
  $handler->display->display_options['relationships']['entityqueue_relationship']['field'] = 'entityqueue_relationship';
  $handler->display->display_options['relationships']['entityqueue_relationship']['limit'] = 1;
  $handler->display->display_options['relationships']['entityqueue_relationship']['queues'] = array(
    'badges_for_booklists' => 'badges_for_booklists',
    'badges_for_reading' => 0,
    'other_badges' => 0,
    'badges_for_reviews' => 0,
  );
  $handler->display->display_options['block_description'] = 'Badges for Booklists';
  $export['reading_badge_views'] = $view;

  $view = new view();
  $view->name = 'reward_page_views';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'eck_reward';
  $view->human_name = 'Reward page views';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Reward page views';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'none';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Header: Global: Text area */
  $handler->display->display_options['header']['area']['id'] = 'area';
  $handler->display->display_options['header']['area']['table'] = 'views';
  $handler->display->display_options['header']['area']['field'] = 'area';
  $handler->display->display_options['header']['area']['content'] = '<h2>Rewards for Kids Summer Reading</h2>
You will get online badges for reading this summer, and actual prizes that you can pick up at any Oakland Public Library';
  $handler->display->display_options['header']['area']['format'] = 'filtered_html';
  /* Relationship: Reward: Raffle Ticket Notifications (field_raffle_notification) */
  $handler->display->display_options['relationships']['field_raffle_notification_value']['id'] = 'field_raffle_notification_value';
  $handler->display->display_options['relationships']['field_raffle_notification_value']['table'] = 'field_data_field_raffle_notification';
  $handler->display->display_options['relationships']['field_raffle_notification_value']['field'] = 'field_raffle_notification_value';
  $handler->display->display_options['relationships']['field_raffle_notification_value']['delta'] = '-1';
  /* Relationship: Reward: Raffle Prize or Reward Notifications (field_raffle_reward_noti) */
  $handler->display->display_options['relationships']['field_raffle_reward_noti_value']['id'] = 'field_raffle_reward_noti_value';
  $handler->display->display_options['relationships']['field_raffle_reward_noti_value']['table'] = 'field_data_field_raffle_reward_noti';
  $handler->display->display_options['relationships']['field_raffle_reward_noti_value']['field'] = 'field_raffle_reward_noti_value';
  $handler->display->display_options['relationships']['field_raffle_reward_noti_value']['delta'] = '-1';
  /* Field: Reward: Id */
  $handler->display->display_options['fields']['id']['id'] = 'id';
  $handler->display->display_options['fields']['id']['table'] = 'eck_reward';
  $handler->display->display_options['fields']['id']['field'] = 'id';
  $handler->display->display_options['fields']['id']['exclude'] = TRUE;
  /* Field: Reward: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'eck_reward';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  /* Field: Field collection item: Raffle ticket description */
  $handler->display->display_options['fields']['field_raffle_description']['id'] = 'field_raffle_description';
  $handler->display->display_options['fields']['field_raffle_description']['table'] = 'field_data_field_raffle_description';
  $handler->display->display_options['fields']['field_raffle_description']['field'] = 'field_raffle_description';
  $handler->display->display_options['fields']['field_raffle_description']['relationship'] = 'field_raffle_notification_value';
  $handler->display->display_options['fields']['field_raffle_description']['label'] = '';
  $handler->display->display_options['fields']['field_raffle_description']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_raffle_description']['hide_empty'] = TRUE;
  /* Field: Field collection item: Raffle prize description */
  $handler->display->display_options['fields']['field_raffle_prize_desc']['id'] = 'field_raffle_prize_desc';
  $handler->display->display_options['fields']['field_raffle_prize_desc']['table'] = 'field_data_field_raffle_prize_desc';
  $handler->display->display_options['fields']['field_raffle_prize_desc']['field'] = 'field_raffle_prize_desc';
  $handler->display->display_options['fields']['field_raffle_prize_desc']['relationship'] = 'field_raffle_notification_value';
  $handler->display->display_options['fields']['field_raffle_prize_desc']['label'] = '';
  $handler->display->display_options['fields']['field_raffle_prize_desc']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_raffle_prize_desc']['hide_empty'] = TRUE;
  /* Filter criterion: Reward: reward type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'eck_reward';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'reward' => 'reward',
  );
  /* Filter criterion: Reward: Type of reward/raffle prize (field_type_of_reward_raffle_priz) */
  $handler->display->display_options['filters']['field_type_of_reward_raffle_priz_tid']['id'] = 'field_type_of_reward_raffle_priz_tid';
  $handler->display->display_options['filters']['field_type_of_reward_raffle_priz_tid']['table'] = 'field_data_field_type_of_reward_raffle_priz';
  $handler->display->display_options['filters']['field_type_of_reward_raffle_priz_tid']['field'] = 'field_type_of_reward_raffle_priz_tid';
  $handler->display->display_options['filters']['field_type_of_reward_raffle_priz_tid']['value'] = array(
    1 => '1',
  );
  $handler->display->display_options['filters']['field_type_of_reward_raffle_priz_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_type_of_reward_raffle_priz_tid']['vocabulary'] = 'type_of_reward';
  $handler->display->display_options['filters']['field_type_of_reward_raffle_priz_tid']['hierarchy'] = 1;

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['defaults']['footer'] = FALSE;
  /* Footer: Global: Text area */
  $handler->display->display_options['footer']['area']['id'] = 'area';
  $handler->display->display_options['footer']['area']['table'] = 'views';
  $handler->display->display_options['footer']['area']['field'] = 'area';
  $handler->display->display_options['footer']['area']['content'] = '<h1>Badges You Can Earn </h1>';
  $handler->display->display_options['footer']['area']['format'] = 'filtered_html';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Reward: Id */
  $handler->display->display_options['fields']['id']['id'] = 'id';
  $handler->display->display_options['fields']['id']['table'] = 'eck_reward';
  $handler->display->display_options['fields']['id']['field'] = 'id';
  $handler->display->display_options['fields']['id']['exclude'] = TRUE;
  /* Field: Reward: Raffle prize or reward image */
  $handler->display->display_options['fields']['field_raffle_prize_or_reward_ima']['id'] = 'field_raffle_prize_or_reward_ima';
  $handler->display->display_options['fields']['field_raffle_prize_or_reward_ima']['table'] = 'field_data_field_raffle_prize_or_reward_ima';
  $handler->display->display_options['fields']['field_raffle_prize_or_reward_ima']['field'] = 'field_raffle_prize_or_reward_ima';
  $handler->display->display_options['fields']['field_raffle_prize_or_reward_ima']['label'] = '';
  $handler->display->display_options['fields']['field_raffle_prize_or_reward_ima']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_raffle_prize_or_reward_ima']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_raffle_prize_or_reward_ima']['settings'] = array(
    'image_style' => 'thumbnail',
    'image_link' => '',
  );
  /* Field: Reward: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'eck_reward';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  /* Field: Field collection item: Raffle ticket description */
  $handler->display->display_options['fields']['field_raffle_description']['id'] = 'field_raffle_description';
  $handler->display->display_options['fields']['field_raffle_description']['table'] = 'field_data_field_raffle_description';
  $handler->display->display_options['fields']['field_raffle_description']['field'] = 'field_raffle_description';
  $handler->display->display_options['fields']['field_raffle_description']['relationship'] = 'field_raffle_notification_value';
  $handler->display->display_options['fields']['field_raffle_description']['label'] = '';
  $handler->display->display_options['fields']['field_raffle_description']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_raffle_description']['hide_empty'] = TRUE;
  /* Field: Field collection item: Raffle prize description */
  $handler->display->display_options['fields']['field_raffle_prize_desc']['id'] = 'field_raffle_prize_desc';
  $handler->display->display_options['fields']['field_raffle_prize_desc']['table'] = 'field_data_field_raffle_prize_desc';
  $handler->display->display_options['fields']['field_raffle_prize_desc']['field'] = 'field_raffle_prize_desc';
  $handler->display->display_options['fields']['field_raffle_prize_desc']['relationship'] = 'field_raffle_notification_value';
  $handler->display->display_options['fields']['field_raffle_prize_desc']['label'] = '';
  $handler->display->display_options['fields']['field_raffle_prize_desc']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_raffle_prize_desc']['hide_empty'] = TRUE;
  $handler->display->display_options['path'] = 'rewards';
  $export['reward_page_views'] = $view;

  return $export;
}

<?php
/**
 * @file
 * rewards_progress_feature.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function rewards_progress_feature_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'Rewards_Progress';
  $view->description = 'Rewards block for Progress Page';
  $view->tag = 'default';
  $view->base_table = 'eck_reward';
  $view->human_name = 'Rewards Progress Page';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Rewards Dashboard';
  $handler->display->display_options['use_ajax'] = TRUE;
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'none';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '5';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Relationship: Entity Reference: Referenced Entity */
  $handler->display->display_options['relationships']['field_reward_claim_id_target_id']['id'] = 'field_reward_claim_id_target_id';
  $handler->display->display_options['relationships']['field_reward_claim_id_target_id']['table'] = 'field_data_field_reward_claim_id';
  $handler->display->display_options['relationships']['field_reward_claim_id_target_id']['field'] = 'field_reward_claim_id_target_id';
  /* Relationship: Entity Reference: Referenced Entity */
  $handler->display->display_options['relationships']['field_raffle_claim_id_target_id']['id'] = 'field_raffle_claim_id_target_id';
  $handler->display->display_options['relationships']['field_raffle_claim_id_target_id']['table'] = 'field_data_field_raffle_claim_id';
  $handler->display->display_options['relationships']['field_raffle_claim_id_target_id']['field'] = 'field_raffle_claim_id_target_id';
  /* Field: Reward: Id */
  $handler->display->display_options['fields']['id']['id'] = 'id';
  $handler->display->display_options['fields']['id']['table'] = 'eck_reward';
  $handler->display->display_options['fields']['id']['field'] = 'id';
  /* Sort criterion: Reward: Created */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'eck_reward';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  /* Filter criterion: Reward: reward type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'eck_reward';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'reward_claim' => 'reward_claim',
  );

  /* Display: Rewards Progress Page */
  $handler = $view->new_display('block', 'Rewards Progress Page', 'block');
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '5';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['quantity'] = '0';
  $handler->display->display_options['pager']['options']['tags']['first'] = '';
  $handler->display->display_options['pager']['options']['tags']['last'] = '';
  $handler->display->display_options['defaults']['header'] = FALSE;
  /* Header: Global: PHP */
  $handler->display->display_options['header']['php']['id'] = 'php';
  $handler->display->display_options['header']['php']['table'] = 'views';
  $handler->display->display_options['header']['php']['field'] = 'php';
  $handler->display->display_options['header']['php']['php_output'] = '<?php 
global $user;
print($user->name);
?>';
  $handler->display->display_options['defaults']['footer'] = FALSE;
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
$reward_title = $row->title;
$leng = strlen($reward_title);
$title_leng = $leng - 17; 

$reward_date = substr($reward_title, -17);
$reward_date_time = substr($reward_date, 0, 12); 
$reward_title = substr($reward_title, 0 , $title_leng - 2);

echo \'<div>\'.$reward_title.\'</div><span>\'.$reward_date_time.\'</span>\';// . \'<div><span>Received <div>\'.$reward_date_time.\'</div>\';


?>';
  $handler->display->display_options['fields']['php']['use_php_click_sortable'] = '0';
  $handler->display->display_options['fields']['php']['php_click_sortable'] = '';
  /* Field: Reward: Raffle Ticket Image */
  $handler->display->display_options['fields']['field_raffle_ticket_image']['id'] = 'field_raffle_ticket_image';
  $handler->display->display_options['fields']['field_raffle_ticket_image']['table'] = 'field_data_field_raffle_ticket_image';
  $handler->display->display_options['fields']['field_raffle_ticket_image']['field'] = 'field_raffle_ticket_image';
  $handler->display->display_options['fields']['field_raffle_ticket_image']['relationship'] = 'field_raffle_claim_id_target_id';
  $handler->display->display_options['fields']['field_raffle_ticket_image']['label'] = '';
  $handler->display->display_options['fields']['field_raffle_ticket_image']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_raffle_ticket_image']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_raffle_ticket_image']['settings'] = array(
    'image_style' => 'thumbnail',
    'image_link' => '',
  );
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
    'raffle_claim' => 'raffle_claim',
  );
  $handler->display->display_options['block_description'] = 'Rewards - Progress Page';
  $export['Rewards_Progress'] = $view;

  return $export;
}

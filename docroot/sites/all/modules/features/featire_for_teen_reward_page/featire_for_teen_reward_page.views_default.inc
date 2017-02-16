<?php
/**
 * @file
 * featire_for_teen_reward_page.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function featire_for_teen_reward_page_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'teen_reward_page';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'eck_reward';
  $view->human_name = 'teen reward page';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'teen reward page';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'none';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Relationship: Reward: Type of reward/raffle prize (field_type_of_reward_raffle_priz) */
  $handler->display->display_options['relationships']['field_type_of_reward_raffle_priz_tid']['id'] = 'field_type_of_reward_raffle_priz_tid';
  $handler->display->display_options['relationships']['field_type_of_reward_raffle_priz_tid']['table'] = 'field_data_field_type_of_reward_raffle_priz';
  $handler->display->display_options['relationships']['field_type_of_reward_raffle_priz_tid']['field'] = 'field_type_of_reward_raffle_priz_tid';
  /* Relationship: Reward: Raffle Prize or Reward Notifications (field_raffle_reward_noti) */
  $handler->display->display_options['relationships']['field_raffle_reward_noti_value']['id'] = 'field_raffle_reward_noti_value';
  $handler->display->display_options['relationships']['field_raffle_reward_noti_value']['table'] = 'field_data_field_raffle_reward_noti';
  $handler->display->display_options['relationships']['field_raffle_reward_noti_value']['field'] = 'field_raffle_reward_noti_value';
  $handler->display->display_options['relationships']['field_raffle_reward_noti_value']['delta'] = '-1';
  /* Field: Global: View result counter */
  $handler->display->display_options['fields']['counter']['id'] = 'counter';
  $handler->display->display_options['fields']['counter']['table'] = 'views';
  $handler->display->display_options['fields']['counter']['field'] = 'counter';
  $handler->display->display_options['fields']['counter']['label'] = '';
  $handler->display->display_options['fields']['counter']['exclude'] = TRUE;
  $handler->display->display_options['fields']['counter']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['counter']['counter_start'] = '1';
  $handler->display->display_options['fields']['counter']['reverse'] = 0;
  /* Field: Reward: Raffle prize or reward image */
  $handler->display->display_options['fields']['field_raffle_prize_or_reward_ima']['id'] = 'field_raffle_prize_or_reward_ima';
  $handler->display->display_options['fields']['field_raffle_prize_or_reward_ima']['table'] = 'field_data_field_raffle_prize_or_reward_ima';
  $handler->display->display_options['fields']['field_raffle_prize_or_reward_ima']['field'] = 'field_raffle_prize_or_reward_ima';
  $handler->display->display_options['fields']['field_raffle_prize_or_reward_ima']['label'] = '';
  $handler->display->display_options['fields']['field_raffle_prize_or_reward_ima']['exclude'] = TRUE;
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
  /* Field: Field collection item: Raffle prize description */
  $handler->display->display_options['fields']['field_raffle_prize_desc']['id'] = 'field_raffle_prize_desc';
  $handler->display->display_options['fields']['field_raffle_prize_desc']['table'] = 'field_data_field_raffle_prize_desc';
  $handler->display->display_options['fields']['field_raffle_prize_desc']['field'] = 'field_raffle_prize_desc';
  $handler->display->display_options['fields']['field_raffle_prize_desc']['relationship'] = 'field_raffle_reward_noti_value';
  $handler->display->display_options['fields']['field_raffle_prize_desc']['label'] = '';
  $handler->display->display_options['fields']['field_raffle_prize_desc']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_raffle_prize_desc']['element_label_colon'] = FALSE;
  /* Field: Global: Custom text */
  $handler->display->display_options['fields']['nothing']['id'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['table'] = 'views';
  $handler->display->display_options['fields']['nothing']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['label'] = '';
  $handler->display->display_options['fields']['nothing']['alter']['text'] = '<div class="reward-wrapp">
<div class="reward-image">[field_raffle_prize_or_reward_ima]</div>
<div class="reward-body-wrapp">
  <div class="reward-tit">[counter]. [title]</div>
  <div class="reward-des">[field_raffle_prize_desc]</div>
</div>
</div>';
  $handler->display->display_options['fields']['nothing']['element_label_colon'] = FALSE;
  /* Filter criterion: Reward: reward type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'eck_reward';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'reward' => 'reward',
  );

  /* Display: Rewards You Can Earn! */
  $handler = $view->new_display('block', 'Rewards You Can Earn!', 'block');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Rewards You Can Earn!';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
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
  $handler->display->display_options['filters']['field_type_of_reward_raffle_priz_tid']['operator'] = 'not';
  $handler->display->display_options['filters']['field_type_of_reward_raffle_priz_tid']['value'] = array(
    2 => '2',
  );
  $handler->display->display_options['filters']['field_type_of_reward_raffle_priz_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_type_of_reward_raffle_priz_tid']['vocabulary'] = 'type_of_reward';
  $handler->display->display_options['filters']['field_type_of_reward_raffle_priz_tid']['hierarchy'] = 1;
  $handler->display->display_options['block_description'] = 'Rewards You Can Earn! for teen reward page';

  /* Display: Badges You Can Earn! */
  $handler = $view->new_display('block', 'Badges You Can Earn!', 'block_1');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Badges You Can Earn!';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
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
    2 => '2',
  );
  $handler->display->display_options['filters']['field_type_of_reward_raffle_priz_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_type_of_reward_raffle_priz_tid']['vocabulary'] = 'type_of_reward';
  $handler->display->display_options['filters']['field_type_of_reward_raffle_priz_tid']['hierarchy'] = 1;
  $handler->display->display_options['block_description'] = 'Badges You Can Earn! for teen reward page';
  $export['teen_reward_page'] = $view;

  return $export;
}

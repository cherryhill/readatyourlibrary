<?php
/**
 * @file
 * feature_for_my_raffle_block.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function feature_for_my_raffle_block_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'my_raffle_ticket';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'eck_reward';
  $view->human_name = 'My raffle ticket';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'My raffle ticket';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'none';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Relationship: Entity Reference: Referenced Entity */
  $handler->display->display_options['relationships']['field_raffle_claim_id_target_id']['id'] = 'field_raffle_claim_id_target_id';
  $handler->display->display_options['relationships']['field_raffle_claim_id_target_id']['table'] = 'field_data_field_raffle_claim_id';
  $handler->display->display_options['relationships']['field_raffle_claim_id_target_id']['field'] = 'field_raffle_claim_id_target_id';
  /* Field: Reward: Id */
  $handler->display->display_options['fields']['id']['id'] = 'id';
  $handler->display->display_options['fields']['id']['table'] = 'eck_reward';
  $handler->display->display_options['fields']['id']['field'] = 'id';
  $handler->display->display_options['fields']['id']['exclude'] = TRUE;
  /* Field: Reward: Raffle Ticket Image */
  $handler->display->display_options['fields']['field_raffle_ticket_image']['id'] = 'field_raffle_ticket_image';
  $handler->display->display_options['fields']['field_raffle_ticket_image']['table'] = 'field_data_field_raffle_ticket_image';
  $handler->display->display_options['fields']['field_raffle_ticket_image']['field'] = 'field_raffle_ticket_image';
  $handler->display->display_options['fields']['field_raffle_ticket_image']['relationship'] = 'field_raffle_claim_id_target_id';
  $handler->display->display_options['fields']['field_raffle_ticket_image']['label'] = '';
  $handler->display->display_options['fields']['field_raffle_ticket_image']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_raffle_ticket_image']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_raffle_ticket_image']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_raffle_ticket_image']['settings'] = array(
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
  $handler->display->display_options['fields']['php']['exclude'] = TRUE;
  $handler->display->display_options['fields']['php']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['php']['use_php_setup'] = 0;
  $handler->display->display_options['fields']['php']['php_output'] = '<?php 
echo substr($row->title ,0,-20);
?>';
  $handler->display->display_options['fields']['php']['use_php_click_sortable'] = '0';
  $handler->display->display_options['fields']['php']['php_click_sortable'] = '';
  /* Field: Global: PHP */
  $handler->display->display_options['fields']['php_1']['id'] = 'php_1';
  $handler->display->display_options['fields']['php_1']['table'] = 'views';
  $handler->display->display_options['fields']['php_1']['field'] = 'php';
  $handler->display->display_options['fields']['php_1']['label'] = 'Picked up date :';
  $handler->display->display_options['fields']['php_1']['exclude'] = TRUE;
  $handler->display->display_options['fields']['php_1']['use_php_setup'] = 0;
  $handler->display->display_options['fields']['php_1']['php_output'] = '<?php
$query = db_select(\'field_data_field_rf_pickup_date\',\'date\')
->fields(\'date\', array(\'field_rf_pickup_date_value\'))
->condition(\'entity_id\',$row->id)
->execute()
->fetchAssoc();

$date = $query[\'field_rf_pickup_date_value\'];
if(isset($date)) {
  echo \'Picked up date\' .substr($date, 0, -8);
}
?>';
  $handler->display->display_options['fields']['php_1']['use_php_click_sortable'] = '0';
  $handler->display->display_options['fields']['php_1']['php_click_sortable'] = '';
  /* Field: Global: Custom text */
  $handler->display->display_options['fields']['nothing']['id'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['table'] = 'views';
  $handler->display->display_options['fields']['nothing']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['label'] = '';
  $handler->display->display_options['fields']['nothing']['alter']['text'] = '<div class="reward-sidebar-block-reward-page">
<div class="image">[field_raffle_ticket_image]</div>
<div class="description"><div>[php] </div><div>[php_1]</div></div>
</div>';
  $handler->display->display_options['fields']['nothing']['element_label_colon'] = FALSE;
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
    'raffle_claim' => 'raffle_claim',
  );

  /* Display: My Raffles */
  $handler = $view->new_display('block', 'My Raffles', 'block');
  $export['my_raffle_ticket'] = $view;

  return $export;
}

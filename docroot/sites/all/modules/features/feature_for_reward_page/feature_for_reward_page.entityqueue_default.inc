<?php
/**
 * @file
 * feature_for_reward_page.entityqueue_default.inc
 */

/**
 * Implements hook_entityqueue_default_queues().
 */
function feature_for_reward_page_entityqueue_default_queues() {
  $export = array();

  $queue = new EntityQueue();
  $queue->disabled = FALSE; /* Edit this to true to make a default queue disabled initially */
  $queue->api_version = 1;
  $queue->name = 'badges_for_reading';
  $queue->label = 'Badges for Reading';
  $queue->language = 'en';
  $queue->handler = 'simple';
  $queue->target_type = 'reward';
  $queue->settings = array(
    'target_bundles' => array(
      'reward' => 'reward',
    ),
    'min_size' => '0',
    'max_size' => '0',
    'act_as_queue' => 0,
  );
  $export['badges_for_reading'] = $queue;

  $queue = new EntityQueue();
  $queue->disabled = FALSE; /* Edit this to true to make a default queue disabled initially */
  $queue->api_version = 1;
  $queue->name = 'other_badges';
  $queue->label = 'Other Badges';
  $queue->language = 'en';
  $queue->handler = 'simple';
  $queue->target_type = 'reward';
  $queue->settings = array(
    'target_bundles' => array(
      'reward' => 'reward',
    ),
    'min_size' => '0',
    'max_size' => '0',
    'act_as_queue' => 0,
  );
  $export['other_badges'] = $queue;

  return $export;
}

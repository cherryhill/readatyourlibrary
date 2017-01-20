<?php
/**
 * @file
 * feature_for_reward_page.features.inc
 */

/**
 * Implements hook_entityqueue_api().
 */
function feature_for_reward_page_entityqueue_api($module = NULL, $api = NULL) {
  if ($module == "entityqueue" && $api == "entityqueue_default") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_views_api().
 */
function feature_for_reward_page_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}

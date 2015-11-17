<?php

/**
 * @file
 * openbadging_badges.features.inc
 */

/**
 * Implements hook_default_openbadging_types().
 */
function openbadging_badges_default_openbadging_types() {
  $items = array();
  $items['badges'] = entity_import('openbadging_types', '{
    "type" : "badges",
    "label" : "Badges",
    "weight" : 0,
    "description" : "Add badges",
    "rdf_mapping" : []
  }');
  return $items;
}

/**
 * Implements hook_views_api().
 */
function openbadging_badges_views_api() {
  return array("version" => "3.0");
}

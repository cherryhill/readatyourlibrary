<?php

/**
 * @file
 * openbadging_manage_backpack.features.inc
 */

/**
 * Implements hook_default_openbadging_types().
 */
function openbadging_manage_backpack_default_openbadging_types() {
  $items = array();
  $items['user_groups'] = entity_import('openbadging_types', '{
    "type" : "user_groups",
    "label" : "Badges Group",
    "weight" : 0,
    "description" : "Entity type for creating user groups and define privacy of badges earned.",
    "rdf_mapping" : []
  }');
  return $items;
}

/**
 * Implements hook_views_api().
 */
function openbadging_manage_backpack_views_api() {
  return array("version" => "3.0");
}

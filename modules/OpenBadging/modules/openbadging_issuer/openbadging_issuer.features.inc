<?php

/**
 * @file
 * openbadging_issuer.features.inc
 */

/**
 * Implements hook_default_openbadging_types().
 */
function openbadging_issuer_default_openbadging_types() {
  $items = array();
  $items['issuer_information'] = entity_import('openbadging_types', '{
    "type" : "issuer_information",
    "label" : "Issuer Information",
    "weight" : 0,
    "description" : "add Issuer Information",
    "rdf_mapping" : []
  }');
  return $items;
}

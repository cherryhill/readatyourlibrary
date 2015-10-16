<?php
/**
 * @file
 * play_library_program.rules_defaults.inc
 */

/**
 * Implements hook_default_rules_configuration().
 */
function play_library_program_default_rules_configuration() {
  $items = array();
  $items['rules_reward_physical_won'] = entity_import('rules_config', '{ "rules_reward_physical_won" : {
      "LABEL" : "reward physical won",
      "PLUGIN" : "reaction rule",
      "OWNER" : "rules",
      "TAGS" : [ "reward" ],
      "REQUIRES" : [ "rules", "eck" ],
      "ON" : { "reward_insert" : [] },
      "IF" : [
        { "entity_is_of_bundle" : {
            "entity" : [ "reward" ],
            "type" : "reward",
            "bundle" : { "value" : { "reward_claim" : "reward_claim" } }
          }
        },
        { "entity_is_of_bundle" : {
            "entity" : [ "reward:field-reward-claim-id" ],
            "type" : "reward",
            "bundle" : { "value" : { "physical_reward" : "physical_reward" } }
          }
        }
      ],
      "DO" : [
        { "drupal_message" : { "message" : [ "reward:field-reward-claim-id:field-reward-message" ] } }
      ]
    }
  }');
  return $items;
}

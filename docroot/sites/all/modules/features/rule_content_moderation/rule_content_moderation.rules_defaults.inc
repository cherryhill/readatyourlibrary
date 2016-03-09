<?php
/**
 * @file
 * rule_content_moderation.rules_defaults.inc
 */

/**
 * Implements hook_default_rules_configuration().
 */
function rule_content_moderation_default_rules_configuration() {
  $items = array();
  $items['rules_content_moderation'] = entity_import('rules_config', '{ "rules_content_moderation" : {
      "LABEL" : "Content moderation",
      "PLUGIN" : "reaction rule",
      "OWNER" : "rules",
      "REQUIRES" : [ "rules" ],
      "ON" : {
        "node_view--booklist" : { "bundle" : "booklist" },
        "node_view--review_book" : { "bundle" : "review_book" }
      },
      "IF" : [
        { "entity_has_field" : { "entity" : [ "node" ], "field" : "field_privacy_settings" } },
        { "data_is" : { "data" : [ "node:field-privacy-settings" ], "value" : "private" } },
        { "NOT data_is" : { "data" : [ "site:current-user" ], "value" : [ "node:author" ] } },
        { "NOT user_has_role" : {
            "account" : [ "site:current-user" ],
            "roles" : { "value" : { "10" : "10", "3" : "3" } },
            "operation" : "OR"
          }
        }
      ],
      "DO" : [ { "redirect" : { "url" : [ "site:url" ] } } ]
    }
  }');
  return $items;
}

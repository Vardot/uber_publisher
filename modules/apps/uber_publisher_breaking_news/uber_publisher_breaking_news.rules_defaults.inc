<?php
/**
 * @file
 * uber_publisher_breaking_news.rules_defaults.inc
 */

/**
 * Implements hook_default_rules_configuration().
 */
function uber_publisher_breaking_news_default_rules_configuration() {
  $items = array();
  $items['rules_node_edit_redirect_back_to_edit'] = entity_import('rules_config', '{ "rules_node_edit_redirect_back_to_edit" : {
      "LABEL" : "Breaking news node edit redirect back to edit",
      "PLUGIN" : "reaction rule",
      "OWNER" : "rules",
      "TAGS" : [ "Node", "Redirect" ],
      "REQUIRES" : [ "rules" ],
      "ON" : {
        "node_update--breaking_news" : { "bundle" : "breaking_news" },
        "node_insert--breaking_news" : { "bundle" : "breaking_news" }
      },
      "DO" : [ { "redirect" : { "url" : "[node:edit-url]", "force" : 0 } } ]
    }
  }');
  return $items;
}

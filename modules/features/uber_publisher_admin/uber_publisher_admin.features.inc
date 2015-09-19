<?php
/**
 * @file
 * uber_publisher_admin.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function uber_publisher_admin_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "config_perms" && $api == "config_perms") {
    return array("version" => "1");
  }
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

<?php
/**
 * @file
 * uber_publisher_varbarse_overrides.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function uber_publisher_varbarse_overrides_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "field_group" && $api == "field_group") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_views_api().
 */
function uber_publisher_varbarse_overrides_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}

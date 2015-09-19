<?php
/**
 * @file
 * uber_publisher_newsletter.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function uber_publisher_newsletter_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

<?php
/**
 * @file
 * uber_publisher_disqus.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function uber_publisher_disqus_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

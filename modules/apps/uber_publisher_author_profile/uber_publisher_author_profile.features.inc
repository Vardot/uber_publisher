<?php
/**
 * @file
 * uber_publisher_author_profile.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function uber_publisher_author_profile_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "ds" && $api == "ds") {
    return array("version" => "1");
  }
  if ($module == "field_group" && $api == "field_group") {
    return array("version" => "1");
  }
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_views_api().
 */
function uber_publisher_author_profile_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}

/**
 * Implements hook_node_info().
 */
function uber_publisher_author_profile_node_info() {
  $items = array(
    'uber_publisher_author' => array(
      'name' => t('Author Profile'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Author name'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}

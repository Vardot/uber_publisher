<?php
/**
 * @file
 * uber_publisher_admin.strongarm.inc
 */

/**
 * Implements hook_strongarm().
 */
function uber_publisher_admin_strongarm() {
  $export = array();

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'admin_theme';
  $strongarm->value = 'uber_admin';
  $export['admin_theme'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'less_autoprefixer';
  $strongarm->value = FALSE;
  $export['less_autoprefixer'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'less_devel';
  $strongarm->value = 0;
  $export['less_devel'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'less_engine';
  $strongarm->value = 'less.js';
  $export['less_engine'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'less_source_maps';
  $strongarm->value = 0;
  $export['less_source_maps'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'less_watch';
  $strongarm->value = 0;
  $export['less_watch'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_admin_theme';
  $strongarm->value = 1;
  $export['node_admin_theme'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'shortcutperrole';
  $strongarm->value = array(
    1 => 'shortcut-set-1',
    2 => 'shortcut-set-1',
    4 => 'shortcut-set-1',
    3 => 'shortcut-set-1',
    5 => 'shortcut-set-2',
    6 => 'shortcut-set-2',
  );
  $export['shortcutperrole'] = $strongarm;

  return $export;
}

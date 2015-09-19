<?php
/**
 * @file
 * uber_publisher_admin.config_perms.inc
 */

/**
 * Implements hook_config_perms().
 */
function uber_publisher_admin_config_perms() {
  $export = array();

  $config_perms = new stdClass();
  $config_perms->disabled = FALSE; /* Edit this to true to make a default config_perms disabled initially */
  $config_perms->api_version = 1;
  $config_perms->machine_name = 'display_site_building_menu';
  $config_perms->status = TRUE;
  $config_perms->name = 'display site building menu';
  $config_perms->path = array(
    0 => 'admin/structure',
  );
  $export['display_site_building_menu'] = $config_perms;

  return $export;
}

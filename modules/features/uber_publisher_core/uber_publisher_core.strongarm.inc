<?php
/**
 * @file
 * uber_publisher_core.strongarm.inc
 */

/**
 * Implements hook_strongarm().
 */
function uber_publisher_core_strongarm() {
  $export = array();

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'apps_allow_voting';
  $strongarm->value = 0;
  $export['apps_allow_voting'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'apps_enable_dev_console';
  $strongarm->value = 0;
  $export['apps_enable_dev_console'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'apps_grouping_mode';
  $strongarm->value = 0;
  $export['apps_grouping_mode'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'apps_grouping_vertical';
  $strongarm->value = 1;
  $export['apps_grouping_vertical'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'apps_install_path';
  $strongarm->value = 'profiles/uber_publisher/modules/apps';
  $export['apps_install_path'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'apps_offline_mode';
  $strongarm->value = 1;
  $export['apps_offline_mode'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'page_manager_node_view_disabled';
  $strongarm->value = '0';
  $export['page_manager_node_view_disabled'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'page_manager_term_view_disabled';
  $strongarm->value = FALSE;
  $export['page_manager_term_view_disabled'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'page_manager_user_view_disabled';
  $strongarm->value = FALSE;
  $export['page_manager_user_view_disabled'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'panels_page_allowed_layouts';
  $strongarm->value = 'O:22:"panels_allowed_layouts":4:{s:9:"allow_new";b:1;s:11:"module_name";s:11:"panels_page";s:23:"allowed_layout_settings";a:21:{s:8:"flexible";b:0;s:14:"twocol_stacked";b:0;s:13:"twocol_bricks";b:0;s:25:"threecol_25_50_25_stacked";b:0;s:17:"threecol_25_50_25";b:0;s:6:"onecol";b:0;s:17:"threecol_33_34_33";b:0;s:6:"twocol";b:0;s:25:"threecol_33_34_33_stacked";b:0;s:26:"bootstrap_threecol_stacked";b:0;s:24:"bootstrap_twocol_stacked";b:0;s:8:"upstairs";b:1;s:10:"downstairs";b:1;s:10:"two_halves";b:1;s:13:"right_sidebar";b:1;s:12:"three_thirds";b:1;s:12:"left_sidebar";b:1;s:12:"jose_flipped";b:1;s:4:"jose";b:1;s:13:"four_quarters";b:1;s:10:"one_column";b:1;}s:10:"form_state";N;}';
  $export['panels_page_allowed_layouts'] = $strongarm;

  return $export;
}

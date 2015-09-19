<?php
/**
 * @file
 * bundle_starter.strongarm.inc
 */

/**
 * Implements hook_strongarm().
 */
function bundle_starter_strongarm() {
  $export = array();

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'default_theme';
  $strongarm->value = 'uber_sparkle';
  $export['default_theme'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'panelizer_taxonomy_term:up_category_allowed_layouts';
  $strongarm->value = 'O:22:"panels_allowed_layouts":4:{s:9:"allow_new";b:1;s:11:"module_name";s:35:"panelizer_taxonomy_term:up_category";s:23:"allowed_layout_settings";a:21:{s:8:"flexible";b:1;s:17:"threecol_25_50_25";b:1;s:17:"threecol_33_34_33";b:1;s:14:"twocol_stacked";b:1;s:25:"threecol_25_50_25_stacked";b:1;s:6:"onecol";b:1;s:6:"twocol";b:1;s:13:"twocol_bricks";b:1;s:25:"threecol_33_34_33_stacked";b:1;s:26:"bootstrap_threecol_stacked";b:1;s:24:"bootstrap_twocol_stacked";b:1;s:12:"jose_flipped";b:1;s:4:"jose";b:1;s:10:"one_column";b:1;s:10:"two_halves";b:1;s:12:"three_thirds";b:1;s:8:"upstairs";b:1;s:13:"four_quarters";b:1;s:13:"right_sidebar";b:1;s:12:"left_sidebar";b:1;s:10:"downstairs";b:1;}s:10:"form_state";N;}';
  $export['panelizer_taxonomy_term:up_category_allowed_layouts'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'panelizer_taxonomy_term:up_category_allowed_layouts_default';
  $strongarm->value = 0;
  $export['panelizer_taxonomy_term:up_category_allowed_layouts_default'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'panelizer_taxonomy_term:up_category_allowed_types_default';
  $strongarm->value = 0;
  $export['panelizer_taxonomy_term:up_category_allowed_types_default'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'panelizer_taxonomy_term:up_category_default';
  $strongarm->value = array(
    'entity_form_field' => 'entity_form_field',
    'token' => 'token',
    'custom' => 'custom',
    'block' => 'block',
    'entity_field' => 'entity_field',
    'entity_field_extra' => 'entity_field_extra',
    'entity_view' => 'entity_view',
    'fieldable_panels_pane' => 'fieldable_panels_pane',
    'menu_tree' => 'menu_tree',
    'panels_mini' => 'panels_mini',
    'uber_publisher_follow_widget' => 'uber_publisher_follow_widget',
    'views_panes' => 'views_panes',
    'views' => 'views',
    'other' => 'other',
  );
  $export['panelizer_taxonomy_term:up_category_default'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'site_frontpage';
  $strongarm->value = 'front';
  $export['site_frontpage'] = $strongarm;

  return $export;
}

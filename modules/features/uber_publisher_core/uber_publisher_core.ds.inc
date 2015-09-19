<?php
/**
 * @file
 * uber_publisher_core.ds.inc
 */

/**
 * Implements hook_ds_view_modes_info().
 */
function uber_publisher_core_ds_view_modes_info() {
  $export = array();

  $ds_view_mode = new stdClass();
  $ds_view_mode->api_version = 1;
  $ds_view_mode->view_mode = 'mini_teaser';
  $ds_view_mode->label = 'Mini Teaser';
  $ds_view_mode->entities = array(
    'node' => 'node',
  );
  $export['mini_teaser'] = $ds_view_mode;

  $ds_view_mode = new stdClass();
  $ds_view_mode->api_version = 1;
  $ds_view_mode->view_mode = 'vertical_teaser';
  $ds_view_mode->label = 'Vertical Teaser';
  $ds_view_mode->entities = array(
    'node' => 'node',
  );
  $export['vertical_teaser'] = $ds_view_mode;

  return $export;
}

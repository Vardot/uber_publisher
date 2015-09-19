<?php

/**
 * @file
 * Plugin to handle the 'page' content type which allows the standard page
 * template variables to be embedded into a panel.
 */

$plugin = array(
  'title' => t('Latest Article Bar'),
  'description' => t('Get Latest Article Bar as a news ticker, Marquee, etc ...'),
  'single' => TRUE,
  'content_types' => array('uber_publisher_latest_bar_content_type'),
  'render callback' => 'uber_publisher_latest_bar_content_type_render',
  'edit form' => 'uber_publisher_latest_bar_content_type_edit_form',
  'category' => t('Content Listing'),
  'admin title' => 'uber_publisher_latest_bar_content_type_admin_title',
);

/**
 * Output function for the 'region_pane' content type.
 *
 */
function uber_publisher_latest_bar_content_type_render($subtype, $conf, $panel_args) {
  $views_diplay = $conf['config_item_selected_views'];

  $block = new stdClass();
  $block->content = views_embed_view('uber_publisher_latest_bar', $views_diplay);
  return $block;
}

/**
 * 'Edit form' callback for the content type.
 *
 */
function uber_publisher_latest_bar_content_type_edit_form($form, &$form_state) {
  $settings = $form_state['conf'];

  // Get the view code for uber_publisher_latest_bar view
  $views_diplay = _varbase_magic_get_views_display('uber_publisher_latest_bar');
  
  $form['config_item_selected_views'] = array(
    '#type' => 'select',
    '#default_value' => (isset($settings['config_item_selected_views'])) ? $settings['config_item_selected_views'] : '',
    '#title' => t('View Type'),
    '#options' => $views_diplay,
  );
  return $form;
}

/**
 * Submit function, note anything in the formstate[conf] automatically gets saved 
 */
function uber_publisher_latest_bar_content_type_edit_form_submit(&$form, &$form_state) {
  $form_state['conf']['config_item_selected_views'] = $form_state['values']['config_item_selected_views'];
}

/**
 * Callback to provide the administrative title of region_pane content type.
 */
function uber_publisher_latest_bar_content_type_admin_title($subtype, $conf) {
  $output = t('Latest Article Bar');
  if (!empty($conf['config_item_selected_views'])) {
    $output .= ' : ' . t($conf['config_item_selected_views']);
  }
  return $output;
}

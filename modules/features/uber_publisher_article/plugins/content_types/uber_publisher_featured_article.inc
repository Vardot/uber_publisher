<?php

/**
 * @file
 * Plugin to handle the 'page' content type which allows the standard page
 * template variables to be embedded into a panel.
 */

$plugin = array(
  'title' => t('Featured article'),
  'description' => t('Featured article Description.'),
  'single' => TRUE,
  'content_types' => array('uber_publisher_featured_article_content_type'),
  'render callback' => 'uber_publisher_featured_article_content_type_render',
  'edit form' => 'uber_publisher_featured_article_content_type_edit_form',
  'category' => t('Listing'),
  'admin title' => 'uber_publisher_featured_article_content_type_admin_title',
);

/**
 * Output function for the 'region_pane' content type.
 */
function uber_publisher_featured_article_content_type_render($subtype, $conf, $panel_args) {
  $views_diplay = $conf['views_display'];

  $block = new stdClass();
  $block->content = views_embed_view('featured_article', $views_diplay);
  return $block;
}

/**
 * 'Edit form' callback for the content type.
 */
function uber_publisher_featured_article_content_type_edit_form($form, &$form_state) {
  $settings = $form_state['conf'];
  module_load_include('inc', 'varbase_magic', 'includes/common');

  // Get the view code for uber_publisher_featured_article view
  $views_diplay = _varbase_magic_get_views_display('featured_article');

  $form['views_display'] = array(
    '#type' => 'select',
    '#default_value' => (isset($settings['views_display'])) ? $settings['views_display'] : '',
    '#title' => t('View Type'),
    '#options' => $views_diplay,
  );
  return $form;
}

/**
 * Submit function, note anything in the formstate[conf] automatically gets saved
 */
function uber_publisher_featured_article_content_type_edit_form_submit(&$form, &$form_state) {
  $form_state['conf']['views_display'] = $form_state['values']['views_display'];
}

/**
 * Callback to provide the administrative title of region_pane content type.
 */
function uber_publisher_featured_article_content_type_admin_title($subtype, $conf) {
  $output = t('Featured Article');
  if (!empty($conf['views_display'])) {
    $output .= ' : ' . t($conf['views_display']);
  }
  return $output;
}

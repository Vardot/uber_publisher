<?php

/**
 * @file
 * Defines the uber publisher follow widget for panels.
 */

$plugin = array(
  'title' => t('Uber publisher follow'),
  'description' => t('Create a uber publisher follow widget.'),
  'category' => array('widgets', 0),
  'single' => FALSE,
  'admin info' => 'uber_publisher_follow_widget_admin_info',
  'edit form' => 'uber_publisher_follow_widget_form',
  'render callback' => 'uber_publisher_follow_widget_render',
);

/**
 * Callback to provide administrative info (the preview in panels when building a panel).
 */
function uber_publisher_follow_widget_admin_info($subtype, $conf, $context = NULL) {
  if (!empty($conf)) {
    $platform_infos = uber_publisher_follow_platforms();

    $active_platforms = array();
    foreach ($conf['platforms'] as $name => $platform) {
      if (!empty($platform['platform_value'])) {
        $active_platforms[] = $platform_infos[$name]['title'];
      }
    }

    $content = t('Activated Platforms: @platforms', array('@platforms' => implode(', ', $active_platforms)));
    $content .= '<br />' . t('Iconset: @iconset', array('@iconset' => $conf['icon_style']));

    $block = new stdClass();
    $block->title = $conf['override_title'] ? $conf['override_title_text'] : t('Follow Us');
    $block->content = $content;

    return $block;
  }
}

/**
 * Callback for the edit form.
*/
function uber_publisher_follow_widget_form($form, &$form_state) {
  $form += uber_publisher_follow_form($form_state['conf']);

  return $form;
}

/**
 * Submit callback for the edit form.
 */
function uber_publisher_follow_widget_form_submit($form, &$form_state) {
  foreach (element_children($form) as $key) {
    if (isset($form_state['values'][$key])) {
      $form_state['conf'][$key] = $form_state['values'][$key];
    }
  }
  if (isset($form_state['values']['icon_style'])) {
    $form_state['conf']['icon_style'] = $form_state['values']['icon_style'];
  }
}

function uber_publisher_follow_widget_render($subtype, $conf, $panel_args) {
  $block = new stdClass();
  $platforms_values = variable_get('follow_platforms', array());
  $platforms = _uber_publisher_follow_cleanup_platforms($platforms_values);
  $content = array(
    '#theme' => 'uber_publisher_follow_platforms',
    '#platform_values' => $platforms,
    '#icon_style' => $conf['icon_style'],
    '#appearance' => $conf['appearance'],
    '#link_attributes' => array('target' => '_blank'),
    '#attributes' => array(
      'class' => array('uber-publisher-follow', 'platforms'),
    ),
  );

  // Add css to the block.
  $content['#attached']['css'][] = drupal_get_path('module', 'uber_publisher_follow') . '/uber_publisher_follow.css';

  $block->title = $conf['override_title'] ? $conf['override_title_text'] : t('Follow Us');
  $block->content = $content;

  return $block;
}
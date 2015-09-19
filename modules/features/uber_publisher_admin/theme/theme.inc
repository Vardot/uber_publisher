<?php

/**
 * Implements template_preprocess_uber_publisher_bundle_teaser().
 */
function template_preprocess_uber_publisher_bundle_teaser(&$vars) {
  // Default values not to cause the template to fail.
  $bundle_defaults = array(
    'description' => '',
  );
  $vars['bundle'] = $bundle_defaults + $vars['bundle'];

  $vars['title'] = $vars['bundle']['name'];
  if (!empty($vars['bundle']['screenshot'])) {
    $screenshot_path = drupal_get_path('module', $vars['machine_name']) . '/' . $vars['bundle']['screenshot'];
  }
  else {
    $screenshot_path = drupal_get_path('module', 'uber_publisher_admin') . '/images/screenshot-default.jpg';
  }
  $screenshot = array(
    'path' => $screenshot_path,
    'width' => '590',
    'height' => '370'
  );
  // we cant use theme_image_style since this will be used in installation and will cause use problems.
  $vars['bundle']['screenshot'] = theme('image', $screenshot);
}

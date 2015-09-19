<?php

/**
 * Implements hook_preprocess_html().
 */
function uber_theme_preprocess_html(&$variables) {
  global $theme;
  // Get Uber Publisher Appearance settings.
  $uber_publisher_appearance = variable_get("uber_publisher_appearance", array());

  $file_less_settings = array(
    'group' => CSS_THEME,
    'every_page' => TRUE,
    'preprocess' => TRUE,
  );
  if (module_exists('less') && variable_get('less_engine', '') == 'less.js') {
    if (isset($uber_publisher_appearance['less']['variable'])) {
      // Include all theme less variables to overrride the defaults.
      foreach ($uber_publisher_appearance['less']['variable'] as  $variable => $value) {
        if (!empty($value)) {
          $file_less_settings['less']['variables'][$variable] = $uber_publisher_appearance['less']['variable'][$variable];
        }
      }
    }
    // Every sub theme should have all his less imports in style.less.
    drupal_add_css(drupal_get_path('theme', $theme) . '/less/style.less', $file_less_settings);
  }
  else {
    // if there is no less compiler on the server sub theme should load default style.css.
    drupal_add_css(drupal_get_path('theme', $theme) . '/css/style.css', $file_less_settings);
  }
}
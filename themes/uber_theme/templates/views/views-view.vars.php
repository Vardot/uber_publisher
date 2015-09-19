<?php

/**
 * Implements hook_preprocess_views_view().
 *
 */
function uber_theme_preprocess_views_view__varbase_fpp_slideshow__highlighted_slides(&$variables) {
  $path = drupal_get_path('theme', 'uber_theme') . '/js/views-view.js';
  drupal_add_js($path, array('group' => JS_THEME));
}

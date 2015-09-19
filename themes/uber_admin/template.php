<?php

/**
 * @file
 * This file contains the main theme functions hooks and overrides.
 */

/**
 * Include functions used through out theme.
 */
include_once dirname(__FILE__) . '/includes/form.alter.inc';

/**
 * Override or insert variables into the maintenance page template.
 */
function uber_admin_preprocess_maintenance_page(&$vars, $hook) {
  if (isset($GLOBALS['install_state']) && !empty($GLOBALS['install_state'])) {
    $vars['theme_hook_suggestion'] = 'maintenance_page__install';
    $uber_admin_path = drupal_get_path('theme', 'uber_admin');
    drupal_add_css($uber_admin_path . '/css/uber_admin_install.css', array('group' => CSS_THEME, 'media' => 'all', 'weight' => 9999));
    drupal_add_js($uber_admin_path . '/js/uber_admin_install.js', array('group' => JS_THEME, 'weight' => 9999));
  }
  // While markup for normal pages is split into page.tpl.php and html.tpl.php,
  // the markup for the maintenance page is all in the single
  // maintenance-page.tpl.php template. So, to have what's done in
  // adminimal_preprocess_html() also happen on the maintenance page, it has to be
  // called here.
  vartheme_admin_preprocess_html($vars, $hook);
}

/**
 * Override or insert variables into the html template.
 */
function uber_admin_preprocess_html(&$vars, $hook) {
  $uber_admin_path = drupal_get_path('theme', 'uber_admin');
  drupal_add_css($uber_admin_path . '/css/uber_admin.css', array('group' => CSS_THEME, 'media' => 'all', 'weight' => 9999));

  // Return early, so the maintenance page does not call any of the code below.
  if ($hook != 'html') {
    return;
  }
}

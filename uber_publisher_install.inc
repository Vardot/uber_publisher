<?php

/**
 * Force-set a theme at any point during the execution of the request.
 *
 * Drupal doesn't give us the option to set the theme during the installation
 * process and forces enable the maintenance theme too early in the request
 * for us to modify it in a clean way.
 */
function _uber_publisher_set_theme($target_theme) {
  if ($GLOBALS['theme'] != $target_theme) {
    unset($GLOBALS['theme']);

    drupal_static_reset();
    $GLOBALS['conf']['maintenance_theme'] = $target_theme;
    _drupal_maintenance_theme();
  }
}

/**
 * Site config form build.
 * @see install_configure_form().
 */
function _uber_publisher_install_configure_form($form, &$form_state, &$install_state) {
  include_once DRUPAL_ROOT . '/includes/locale.inc';

  drupal_set_title(st('Configure site'));

  // Remove any messages set by enabled modules.
  drupal_get_messages(NULL, TRUE);

  // Build menu to allow clean URL check.
  menu_rebuild();

  //Set the installation profile for next steps to help Drupal find modules locations.
  variable_set('install_profile', drupal_get_profile());

  drupal_add_js(drupal_get_path('module', 'system') . '/system.js');
  drupal_add_js('misc/timezone.js');
  drupal_add_js(array('copyFieldValue' => array('edit-site-mail' => array('edit-account-mail'))), 'setting');
  drupal_add_js('jQuery(function () { Drupal.cleanURLsInstallCheck(); });', 'inline');

  // Cache a fully-built schema, to enable clean URL check.
  drupal_get_schema(NULL, TRUE);

  $form['site_information'] = array(
    '#type' => 'fieldset',
    '#title' => st('Site information'),
    '#collapsible' => FALSE,
  );
  $form['site_information']['site_name'] = array(
    '#type' => 'textfield',
    '#title' => st('Site name'),
    '#required' => TRUE,
    '#weight' => -20,
    // Lock the option if it is already provided.
    '#default_value' => variable_get('site_name', ''),
    '#disabled' => !empty(variable_get('site_name', '')),
  );
  $form['admin_account'] = array(
    '#type' => 'fieldset',
    '#title' => st('Site maintenance account'),
    '#collapsible' => FALSE,
  );

  $form['admin_account']['account']['#tree'] = TRUE;
  $form['admin_account']['account']['name'] = array(
    '#type' => 'textfield',
    '#title' => st('Username'),
    '#maxlength' => USERNAME_MAX_LENGTH,
    '#description' => st('Spaces are allowed; punctuation is not allowed except for periods, hyphens, and underscores.'),
    '#required' => TRUE,
    '#weight' => -10,
    '#default_value' => 'admin',
    '#attributes' => array('class' => array('username')),
  );

  $form['admin_account']['account']['mail'] = array(
    '#type' => 'textfield',
    '#title' => st('E-mail address'),
    '#maxlength' => EMAIL_MAX_LENGTH,
    '#required' => TRUE,
    '#weight' => -5,
  );
  $form['admin_account']['account']['pass'] = array(
    '#type' => 'password_confirm',
    '#required' => TRUE,
    '#size' => 25,
    '#weight' => 0,
  );

  $form['server_settings'] = array(
    '#type' => 'fieldset',
    '#title' => st('Server settings'),
    '#collapsible' => FALSE,
  );

  $countries = country_get_list();
  $form['server_settings']['site_default_country'] = array(
    '#type' => 'select',
    '#title' => st('Default country'),
    '#empty_value' => '',
    '#default_value' => variable_get('site_default_country', NULL),
    '#options' => $countries,
    '#description' => st('Select the default country for the site.'),
    '#weight' => 0,
  );

  $form['server_settings']['date_default_timezone'] = array(
    '#type' => 'select',
    '#title' => st('Default time zone'),
    '#default_value' => date_default_timezone_get(),
    '#options' => system_time_zones(),
    '#description' => st('By default, dates in this site will be displayed in the chosen time zone.'),
    '#weight' => 5,
    '#attributes' => array('class' => array('timezone-detect')),
  );

  $form['actions'] = array('#type' => 'actions');
  $form['actions']['submit'] = array(
    '#type' => 'submit',
    '#value' => st('Save and continue'),
    '#weight' => 15,
  );

  return $form;
}

function _uber_publisher_install_configure_form_validate($form, $form_state) {
  if ($error = user_validate_name($form_state['values']['account']['name'])) {
    form_error($form['admin_account']['account']['name'], $error);
  }
  if ($error = user_validate_mail($form_state['values']['account']['mail'])) {
    form_error($form['admin_account']['account']['mail'], $error);
  }
}

function _uber_publisher_install_configure_form_submit($form, &$form_state) {
  global $user, $base_url;

  $url_parsed = parse_url($base_url);
  $user_roles = user_roles();
  $super_admin_rid = array_search('Super Admin', $user_roles);
  $site_admin_rid = array_search('Site Admin', $user_roles);

  variable_set('site_mail', 'noreply@' . $url_parsed['host']);
  variable_set('update_notify_emails', array());
  variable_set('install_time', $_SERVER['REQUEST_TIME']);
  variable_set('clean_url', 1);

  variable_set('site_name', $form_state['values']['site_name']);
  variable_set('date_default_timezone', $form_state['values']['date_default_timezone']);
  variable_set('site_default_country', $form_state['values']['site_default_country']);

  $super_user = user_load(1);
  $user_data = array(
    'name' => 'vardot',
    'init' => 'uber_publisher@vardot.com',
    'mail' => 'uber_publisher@vardot.com',
    'pass' => 'vardot',
    'status' => 1,
    'timezone' => 'Asia/Amman',
    'roles' => array($super_admin_rid => 'Super Admin', $site_admin_rid => 'Site Admin'),
  );
  $super_user = user_save($super_user, $user_data);

  $site_admin = array(
    'init' => $form_state['values']['account']['mail'],
    'roles' => array($site_admin_rid => 'Site Admin'),
    'status' => 1,
    'timezone' => $form_state['values']['date_default_timezone'],
  );
  $account = user_save('', array_merge($form_state['values']['account'], $site_admin));
  $user = user_load($account->uid);
  user_login_finalize();
}

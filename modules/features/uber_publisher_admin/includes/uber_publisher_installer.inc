<?php

function _uber_publisher_installer(array $modules = array()) {
  $files = system_rebuild_module_data();

  $required = array();
  $non_required = array();

  // Add modules that other modules depend on.
  foreach ($modules as $module) {
    if ($files[$module]->requires) {
      $modules = array_merge($modules, array_keys($files[$module]->requires));
    }
  }
  $modules = array_unique($modules);
  foreach ($modules as $module) {
    if (!empty($files[$module]->info['required'])) {
      $required[$module] = $files[$module]->sort;
    }
    else {
      $non_required[$module] = $files[$module]->sort;
    }
  }

  arsort($required);
  arsort($non_required);

  $operations = array();
  foreach ($required + $non_required as $module => $weight) {
    $op_info = array($module, $files[$module]->info['name']);
    $operations[] = array('_uber_publisher_installer_install', $op_info);
    $operations[] = array('_uber_publisher_installer_rebuild_feature_defaultconfig', $op_info);
    $operations[] = array('_uber_publisher_installer_revert_feature', $op_info);
  }

  $batch = array(
    'operations' => $operations,
    'title' => st('Installing @drupal', array('@drupal' => drupal_install_profile_distribution_name())),
    'error_message' => st('The installation has encountered an error.'),
    'finished' => '_install_profile_modules_finished',
    'file' => drupal_get_path('module', 'uber_publisher_admin') .'/includes/uber_publisher_installer.inc',
  );

  return $batch;
}

function _uber_publisher_installer_install($module, $module_name, &$context) {
  module_enable(array($module), FALSE);
  $context['message'] = st('Installed %module module.', array('%module' => $module_name));
}

function _uber_publisher_installer_rebuild_feature_defaultconfig($module, $module_name, &$context) {
  features_include();
  $components = defaultconfig_get_components(TRUE);
  foreach ($components as $component) {
    defaultconfig_component_include($component, $module);
    if (module_hook($module, $component['hook'])) {
      defaultconfig_component_rebuild($component, $module);
      $context['message'] = st('Rebuilding default configuration for %module module.', array('%module' => $module_name));
    }
  }
}

function _uber_publisher_installer_revert_feature($module, $module_name, &$context) {
  // Rebuild features to check missing or overriden config is detected.
  features_rebuild();

  features_revert($module);
  $context['message'] = st('Rebuilding default configuration for %module module.', array('%module' => $module_name));
}


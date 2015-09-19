<?php
/**
 * @file
 * uber_publisher_admin.features.defaultconfig.inc
 */

/**
 * Implements hook_defaultconfig_features().
 */
function uber_publisher_admin_defaultconfig_features() {
  return array(
    'uber_publisher_admin' => array(
      'user_default_permissions' => 'user_default_permissions',
    ),
  );
}

/**
 * Implements hook_defaultconfig_user_default_permissions().
 */
function uber_publisher_admin_defaultconfig_user_default_permissions() {
  $permissions = array();

  // Exported permission: 'access up navbar'.
  $permissions['access up navbar'] = array(
    'name' => 'access up navbar',
    'roles' => array(
      'Content Admin' => 'Content Admin',
      'Editor' => 'Editor',
      'Site Admin' => 'Site Admin',
      'Super Admin' => 'Super Admin',
    ),
    'module' => 'up_navbar',
  );

  // Exported permission: 'administer shortcut per role'.
  $permissions['administer shortcut per role'] = array(
    'name' => 'administer shortcut per role',
    'roles' => array(
      'Site Admin' => 'Site Admin',
      'Super Admin' => 'Super Admin',
    ),
    'module' => 'shortcutperrole',
  );

  // Exported permission: 'administer shortcuts'.
  $permissions['administer shortcuts'] = array(
    'name' => 'administer shortcuts',
    'roles' => array(
      'Super Admin' => 'Super Admin',
    ),
    'module' => 'shortcut',
  );

  // Exported permission: 'administer uber_publisher bundle'.
  $permissions['administer uber_publisher bundle'] = array(
    'name' => 'administer uber_publisher bundle',
    'roles' => array(
      'Site Admin' => 'Site Admin',
      'Super Admin' => 'Super Admin',
    ),
    'module' => 'uber_publisher_admin',
  );

  // Exported permission: 'administer uber_publisher settings'.
  $permissions['administer uber_publisher settings'] = array(
    'name' => 'administer uber_publisher settings',
    'roles' => array(
      'Site Admin' => 'Site Admin',
      'Super Admin' => 'Super Admin',
    ),
    'module' => 'uber_publisher_admin',
  );

  // Exported permission: 'customize shortcut links'.
  $permissions['customize shortcut links'] = array(
    'name' => 'customize shortcut links',
    'roles' => array(
      'Site Admin' => 'Site Admin',
      'Super Admin' => 'Super Admin',
    ),
    'module' => 'shortcut',
  );

  // Exported permission: 'display site building menu'.
  $permissions['display site building menu'] = array(
    'name' => 'display site building menu',
    'roles' => array(
      'Content Admin' => 'Content Admin',
      'Editor' => 'Editor',
      'Site Admin' => 'Site Admin',
      'Super Admin' => 'Super Admin',
    ),
    'module' => 'config_perms',
  );

  // Exported permission: 'switch shortcut sets'.
  $permissions['switch shortcut sets'] = array(
    'name' => 'switch shortcut sets',
    'roles' => array(
      'Super Admin' => 'Super Admin',
    ),
    'module' => 'shortcut',
  );

  return $permissions;
}

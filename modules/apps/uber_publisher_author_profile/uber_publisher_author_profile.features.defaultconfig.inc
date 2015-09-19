<?php
/**
 * @file
 * uber_publisher_author_profile.features.defaultconfig.inc
 */

/**
 * Implements hook_defaultconfig_features().
 */
function uber_publisher_author_profile_defaultconfig_features() {
  return array(
    'uber_publisher_author_profile' => array(
      'user_default_permissions' => 'user_default_permissions',
    ),
  );
}

/**
 * Implements hook_defaultconfig_user_default_permissions().
 */
function uber_publisher_author_profile_defaultconfig_user_default_permissions() {
  $permissions = array();

  // Exported permission: 'administer panelizer node uber_publisher_author choice'.
  $permissions['administer panelizer node uber_publisher_author choice'] = array(
    'name' => 'administer panelizer node uber_publisher_author choice',
    'roles' => array(),
    'module' => 'panelizer',
  );

  // Exported permission: 'administer panelizer node uber_publisher_author content'.
  $permissions['administer panelizer node uber_publisher_author content'] = array(
    'name' => 'administer panelizer node uber_publisher_author content',
    'roles' => array(),
    'module' => 'panelizer',
  );

  // Exported permission: 'administer panelizer node uber_publisher_author context'.
  $permissions['administer panelizer node uber_publisher_author context'] = array(
    'name' => 'administer panelizer node uber_publisher_author context',
    'roles' => array(),
    'module' => 'panelizer',
  );

  // Exported permission: 'administer panelizer node uber_publisher_author defaults'.
  $permissions['administer panelizer node uber_publisher_author defaults'] = array(
    'name' => 'administer panelizer node uber_publisher_author defaults',
    'roles' => array(),
    'module' => 'panelizer',
  );

  // Exported permission: 'administer panelizer node uber_publisher_author layout'.
  $permissions['administer panelizer node uber_publisher_author layout'] = array(
    'name' => 'administer panelizer node uber_publisher_author layout',
    'roles' => array(),
    'module' => 'panelizer',
  );

  // Exported permission: 'administer panelizer node uber_publisher_author overview'.
  $permissions['administer panelizer node uber_publisher_author overview'] = array(
    'name' => 'administer panelizer node uber_publisher_author overview',
    'roles' => array(),
    'module' => 'panelizer',
  );

  // Exported permission: 'administer panelizer node uber_publisher_author settings'.
  $permissions['administer panelizer node uber_publisher_author settings'] = array(
    'name' => 'administer panelizer node uber_publisher_author settings',
    'roles' => array(),
    'module' => 'panelizer',
  );

  // Exported permission: 'create uber_publisher_author content'.
  $permissions['create uber_publisher_author content'] = array(
    'name' => 'create uber_publisher_author content',
    'roles' => array(
      'Content Admin' => 'Content Admin',
      'Editor' => 'Editor',
      'Site Admin' => 'Site Admin',
      'Super Admin' => 'Super Admin',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete any uber_publisher_author content'.
  $permissions['delete any uber_publisher_author content'] = array(
    'name' => 'delete any uber_publisher_author content',
    'roles' => array(
      'Content Admin' => 'Content Admin',
      'Site Admin' => 'Site Admin',
      'Super Admin' => 'Super Admin',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete own uber_publisher_author content'.
  $permissions['delete own uber_publisher_author content'] = array(
    'name' => 'delete own uber_publisher_author content',
    'roles' => array(
      'Content Admin' => 'Content Admin',
      'Site Admin' => 'Site Admin',
      'Super Admin' => 'Super Admin',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit any uber_publisher_author content'.
  $permissions['edit any uber_publisher_author content'] = array(
    'name' => 'edit any uber_publisher_author content',
    'roles' => array(
      'Content Admin' => 'Content Admin',
      'Site Admin' => 'Site Admin',
      'Super Admin' => 'Super Admin',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit own uber_publisher_author content'.
  $permissions['edit own uber_publisher_author content'] = array(
    'name' => 'edit own uber_publisher_author content',
    'roles' => array(
      'Content Admin' => 'Content Admin',
      'Editor' => 'Editor',
      'Site Admin' => 'Site Admin',
      'Super Admin' => 'Super Admin',
    ),
    'module' => 'node',
  );

  // Exported permission: 'enter uber_publisher_author revision log entry'.
  $permissions['enter uber_publisher_author revision log entry'] = array(
    'name' => 'enter uber_publisher_author revision log entry',
    'roles' => array(
      'Content Admin' => 'Content Admin',
      'Editor' => 'Editor',
      'Site Admin' => 'Site Admin',
      'Super Admin' => 'Super Admin',
    ),
    'module' => 'override_node_options',
  );

  // Exported permission: 'override uber_publisher_author authored by option'.
  $permissions['override uber_publisher_author authored by option'] = array(
    'name' => 'override uber_publisher_author authored by option',
    'roles' => array(),
    'module' => 'override_node_options',
  );

  // Exported permission: 'override uber_publisher_author authored on option'.
  $permissions['override uber_publisher_author authored on option'] = array(
    'name' => 'override uber_publisher_author authored on option',
    'roles' => array(),
    'module' => 'override_node_options',
  );

  // Exported permission: 'override uber_publisher_author promote to front page option'.
  $permissions['override uber_publisher_author promote to front page option'] = array(
    'name' => 'override uber_publisher_author promote to front page option',
    'roles' => array(),
    'module' => 'override_node_options',
  );

  // Exported permission: 'override uber_publisher_author published option'.
  $permissions['override uber_publisher_author published option'] = array(
    'name' => 'override uber_publisher_author published option',
    'roles' => array(),
    'module' => 'override_node_options',
  );

  // Exported permission: 'override uber_publisher_author revision option'.
  $permissions['override uber_publisher_author revision option'] = array(
    'name' => 'override uber_publisher_author revision option',
    'roles' => array(
      'Content Admin' => 'Content Admin',
      'Site Admin' => 'Site Admin',
      'Super Admin' => 'Super Admin',
    ),
    'module' => 'override_node_options',
  );

  // Exported permission: 'override uber_publisher_author sticky option'.
  $permissions['override uber_publisher_author sticky option'] = array(
    'name' => 'override uber_publisher_author sticky option',
    'roles' => array(),
    'module' => 'override_node_options',
  );

  return $permissions;
}

<?php
/**
 * @file
 * uber_publisher_taxonomy.features.defaultconfig.inc
 */

/**
 * Implements hook_defaultconfig_features().
 */
function uber_publisher_taxonomy_defaultconfig_features() {
  return array(
    'uber_publisher_taxonomy' => array(
      'user_default_permissions' => 'user_default_permissions',
    ),
  );
}

/**
 * Implements hook_defaultconfig_user_default_permissions().
 */
function uber_publisher_taxonomy_defaultconfig_user_default_permissions() {
  $permissions = array();

  // Exported permission: 'add terms in dossier'.
  $permissions['add terms in dossier'] = array(
    'name' => 'add terms in dossier',
    'roles' => array(
      'Content Admin' => 'Content Admin',
      'Site Admin' => 'Site Admin',
      'Super Admin' => 'Super Admin',
    ),
    'module' => 'taxonomy_access_fix',
  );

  // Exported permission: 'add terms in tags'.
  $permissions['add terms in tags'] = array(
    'name' => 'add terms in tags',
    'roles' => array(
      'Content Admin' => 'Content Admin',
      'Editor' => 'Editor',
      'Site Admin' => 'Site Admin',
      'Super Admin' => 'Super Admin',
    ),
    'module' => 'taxonomy_access_fix',
  );

  // Exported permission: 'add terms in up_category'.
  $permissions['add terms in up_category'] = array(
    'name' => 'add terms in up_category',
    'roles' => array(
      'Content Admin' => 'Content Admin',
      'Site Admin' => 'Site Admin',
      'Super Admin' => 'Super Admin',
    ),
    'module' => 'taxonomy_access_fix',
  );

  // Exported permission: 'administer panelizer taxonomy_term up_category content'.
  $permissions['administer panelizer taxonomy_term up_category content'] = array(
    'name' => 'administer panelizer taxonomy_term up_category content',
    'roles' => array(),
    'module' => 'panelizer',
  );

  // Exported permission: 'administer panelizer taxonomy_term up_category context'.
  $permissions['administer panelizer taxonomy_term up_category context'] = array(
    'name' => 'administer panelizer taxonomy_term up_category context',
    'roles' => array(),
    'module' => 'panelizer',
  );

  // Exported permission: 'administer panelizer taxonomy_term up_category defaults'.
  $permissions['administer panelizer taxonomy_term up_category defaults'] = array(
    'name' => 'administer panelizer taxonomy_term up_category defaults',
    'roles' => array(),
    'module' => 'panelizer',
  );

  // Exported permission: 'administer panelizer taxonomy_term up_category layout'.
  $permissions['administer panelizer taxonomy_term up_category layout'] = array(
    'name' => 'administer panelizer taxonomy_term up_category layout',
    'roles' => array(),
    'module' => 'panelizer',
  );

  // Exported permission: 'administer panelizer taxonomy_term up_category overview'.
  $permissions['administer panelizer taxonomy_term up_category overview'] = array(
    'name' => 'administer panelizer taxonomy_term up_category overview',
    'roles' => array(),
    'module' => 'panelizer',
  );

  // Exported permission: 'administer panelizer taxonomy_term up_category settings'.
  $permissions['administer panelizer taxonomy_term up_category settings'] = array(
    'name' => 'administer panelizer taxonomy_term up_category settings',
    'roles' => array(),
    'module' => 'panelizer',
  );

  // Exported permission: 'delete terms in dossier'.
  $permissions['delete terms in dossier'] = array(
    'name' => 'delete terms in dossier',
    'roles' => array(
      'Content Admin' => 'Content Admin',
      'Site Admin' => 'Site Admin',
      'Super Admin' => 'Super Admin',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: 'delete terms in tags'.
  $permissions['delete terms in tags'] = array(
    'name' => 'delete terms in tags',
    'roles' => array(
      'Content Admin' => 'Content Admin',
      'Site Admin' => 'Site Admin',
      'Super Admin' => 'Super Admin',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: 'delete terms in up_category'.
  $permissions['delete terms in up_category'] = array(
    'name' => 'delete terms in up_category',
    'roles' => array(
      'Site Admin' => 'Site Admin',
      'Super Admin' => 'Super Admin',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: 'edit terms in dossier'.
  $permissions['edit terms in dossier'] = array(
    'name' => 'edit terms in dossier',
    'roles' => array(
      'Content Admin' => 'Content Admin',
      'Site Admin' => 'Site Admin',
      'Super Admin' => 'Super Admin',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: 'edit terms in tags'.
  $permissions['edit terms in tags'] = array(
    'name' => 'edit terms in tags',
    'roles' => array(
      'Content Admin' => 'Content Admin',
      'Editor' => 'Editor',
      'Site Admin' => 'Site Admin',
      'Super Admin' => 'Super Admin',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: 'edit terms in up_category'.
  $permissions['edit terms in up_category'] = array(
    'name' => 'edit terms in up_category',
    'roles' => array(
      'Content Admin' => 'Content Admin',
      'Site Admin' => 'Site Admin',
      'Super Admin' => 'Super Admin',
    ),
    'module' => 'taxonomy',
  );

  return $permissions;
}

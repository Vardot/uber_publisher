<?php
/**
 * @file
 * uber_publisher_article.features.defaultconfig.inc
 */

/**
 * Implements hook_defaultconfig_features().
 */
function uber_publisher_article_defaultconfig_features() {
  return array(
    'uber_publisher_article' => array(
      'user_default_permissions' => 'user_default_permissions',
    ),
  );
}

/**
 * Implements hook_defaultconfig_user_default_permissions().
 */
function uber_publisher_article_defaultconfig_user_default_permissions() {
  $permissions = array();

  // Exported permission: 'add terms in article_type'.
  $permissions['add terms in article_type'] = array(
    'name' => 'add terms in article_type',
    'roles' => array(
      'Super Admin' => 'Super Admin',
    ),
    'module' => 'taxonomy_access_fix',
  );

  // Exported permission: 'administer panelizer node uber_publisher_article choice'.
  $permissions['administer panelizer node uber_publisher_article choice'] = array(
    'name' => 'administer panelizer node uber_publisher_article choice',
    'roles' => array(),
    'module' => 'panelizer',
  );

  // Exported permission: 'administer panelizer node uber_publisher_article content'.
  $permissions['administer panelizer node uber_publisher_article content'] = array(
    'name' => 'administer panelizer node uber_publisher_article content',
    'roles' => array(),
    'module' => 'panelizer',
  );

  // Exported permission: 'administer panelizer node uber_publisher_article context'.
  $permissions['administer panelizer node uber_publisher_article context'] = array(
    'name' => 'administer panelizer node uber_publisher_article context',
    'roles' => array(),
    'module' => 'panelizer',
  );

  // Exported permission: 'administer panelizer node uber_publisher_article defaults'.
  $permissions['administer panelizer node uber_publisher_article defaults'] = array(
    'name' => 'administer panelizer node uber_publisher_article defaults',
    'roles' => array(),
    'module' => 'panelizer',
  );

  // Exported permission: 'administer panelizer node uber_publisher_article layout'.
  $permissions['administer panelizer node uber_publisher_article layout'] = array(
    'name' => 'administer panelizer node uber_publisher_article layout',
    'roles' => array(),
    'module' => 'panelizer',
  );

  // Exported permission: 'administer panelizer node uber_publisher_article overview'.
  $permissions['administer panelizer node uber_publisher_article overview'] = array(
    'name' => 'administer panelizer node uber_publisher_article overview',
    'roles' => array(),
    'module' => 'panelizer',
  );

  // Exported permission: 'administer panelizer node uber_publisher_article settings'.
  $permissions['administer panelizer node uber_publisher_article settings'] = array(
    'name' => 'administer panelizer node uber_publisher_article settings',
    'roles' => array(),
    'module' => 'panelizer',
  );

  // Exported permission: 'administer panelizer taxonomy_term article_type content'.
  $permissions['administer panelizer taxonomy_term article_type content'] = array(
    'name' => 'administer panelizer taxonomy_term article_type content',
    'roles' => array(),
    'module' => 'panelizer',
  );

  // Exported permission: 'administer panelizer taxonomy_term article_type context'.
  $permissions['administer panelizer taxonomy_term article_type context'] = array(
    'name' => 'administer panelizer taxonomy_term article_type context',
    'roles' => array(),
    'module' => 'panelizer',
  );

  // Exported permission: 'administer panelizer taxonomy_term article_type defaults'.
  $permissions['administer panelizer taxonomy_term article_type defaults'] = array(
    'name' => 'administer panelizer taxonomy_term article_type defaults',
    'roles' => array(
      'Super Admin' => 'Super Admin',
    ),
    'module' => 'panelizer',
  );

  // Exported permission: 'administer panelizer taxonomy_term article_type layout'.
  $permissions['administer panelizer taxonomy_term article_type layout'] = array(
    'name' => 'administer panelizer taxonomy_term article_type layout',
    'roles' => array(),
    'module' => 'panelizer',
  );

  // Exported permission: 'administer panelizer taxonomy_term article_type overview'.
  $permissions['administer panelizer taxonomy_term article_type overview'] = array(
    'name' => 'administer panelizer taxonomy_term article_type overview',
    'roles' => array(),
    'module' => 'panelizer',
  );

  // Exported permission: 'administer panelizer taxonomy_term article_type settings'.
  $permissions['administer panelizer taxonomy_term article_type settings'] = array(
    'name' => 'administer panelizer taxonomy_term article_type settings',
    'roles' => array(),
    'module' => 'panelizer',
  );

  // Exported permission: 'create uber_publisher_article content'.
  $permissions['create uber_publisher_article content'] = array(
    'name' => 'create uber_publisher_article content',
    'roles' => array(
      'Content Admin' => 'Content Admin',
      'Editor' => 'Editor',
      'Site Admin' => 'Site Admin',
      'Super Admin' => 'Super Admin',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete any uber_publisher_article content'.
  $permissions['delete any uber_publisher_article content'] = array(
    'name' => 'delete any uber_publisher_article content',
    'roles' => array(
      'Content Admin' => 'Content Admin',
      'Site Admin' => 'Site Admin',
      'Super Admin' => 'Super Admin',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete own uber_publisher_article content'.
  $permissions['delete own uber_publisher_article content'] = array(
    'name' => 'delete own uber_publisher_article content',
    'roles' => array(
      'Content Admin' => 'Content Admin',
      'Site Admin' => 'Site Admin',
      'Super Admin' => 'Super Admin',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete terms in article_type'.
  $permissions['delete terms in article_type'] = array(
    'name' => 'delete terms in article_type',
    'roles' => array(
      'Super Admin' => 'Super Admin',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: 'edit any uber_publisher_article content'.
  $permissions['edit any uber_publisher_article content'] = array(
    'name' => 'edit any uber_publisher_article content',
    'roles' => array(
      'Content Admin' => 'Content Admin',
      'Site Admin' => 'Site Admin',
      'Super Admin' => 'Super Admin',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit own uber_publisher_article content'.
  $permissions['edit own uber_publisher_article content'] = array(
    'name' => 'edit own uber_publisher_article content',
    'roles' => array(
      'Content Admin' => 'Content Admin',
      'Editor' => 'Editor',
      'Site Admin' => 'Site Admin',
      'Super Admin' => 'Super Admin',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit terms in article_type'.
  $permissions['edit terms in article_type'] = array(
    'name' => 'edit terms in article_type',
    'roles' => array(
      'Super Admin' => 'Super Admin',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: 'enter uber_publisher_article revision log entry'.
  $permissions['enter uber_publisher_article revision log entry'] = array(
    'name' => 'enter uber_publisher_article revision log entry',
    'roles' => array(
      'Content Admin' => 'Content Admin',
      'Editor' => 'Editor',
      'Site Admin' => 'Site Admin',
      'Super Admin' => 'Super Admin',
    ),
    'module' => 'override_node_options',
  );

  // Exported permission: 'override uber_publisher_article authored by option'.
  $permissions['override uber_publisher_article authored by option'] = array(
    'name' => 'override uber_publisher_article authored by option',
    'roles' => array(),
    'module' => 'override_node_options',
  );

  // Exported permission: 'override uber_publisher_article authored on option'.
  $permissions['override uber_publisher_article authored on option'] = array(
    'name' => 'override uber_publisher_article authored on option',
    'roles' => array(),
    'module' => 'override_node_options',
  );

  // Exported permission: 'override uber_publisher_article promote to front page option'.
  $permissions['override uber_publisher_article promote to front page option'] = array(
    'name' => 'override uber_publisher_article promote to front page option',
    'roles' => array(),
    'module' => 'override_node_options',
  );

  // Exported permission: 'override uber_publisher_article published option'.
  $permissions['override uber_publisher_article published option'] = array(
    'name' => 'override uber_publisher_article published option',
    'roles' => array(),
    'module' => 'override_node_options',
  );

  // Exported permission: 'override uber_publisher_article revision option'.
  $permissions['override uber_publisher_article revision option'] = array(
    'name' => 'override uber_publisher_article revision option',
    'roles' => array(
      'Content Admin' => 'Content Admin',
      'Site Admin' => 'Site Admin',
      'Super Admin' => 'Super Admin',
    ),
    'module' => 'override_node_options',
  );

  // Exported permission: 'override uber_publisher_article sticky option'.
  $permissions['override uber_publisher_article sticky option'] = array(
    'name' => 'override uber_publisher_article sticky option',
    'roles' => array(),
    'module' => 'override_node_options',
  );

  return $permissions;
}

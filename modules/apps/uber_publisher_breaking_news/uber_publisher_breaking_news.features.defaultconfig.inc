<?php
/**
 * @file
 * uber_publisher_breaking_news.features.defaultconfig.inc
 */

/**
 * Implements hook_defaultconfig_features().
 */
function uber_publisher_breaking_news_defaultconfig_features() {
  return array(
    'uber_publisher_breaking_news' => array(
      'ds_field_settings_info' => 'ds_field_settings_info',
      'ds_layout_settings_info' => 'ds_layout_settings_info',
      'field_default_fields' => 'field_default_fields',
      'strongarm' => 'strongarm',
      'user_default_permissions' => 'user_default_permissions',
    ),
  );
}

/**
 * Implements hook_defaultconfig_ds_field_settings_info().
 */
function uber_publisher_breaking_news_defaultconfig_ds_field_settings_info() {
  $export = array();

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'node|breaking_news|teaser';
  $ds_fieldsetting->entity_type = 'node';
  $ds_fieldsetting->bundle = 'breaking_news';
  $ds_fieldsetting->view_mode = 'teaser';
  $ds_fieldsetting->settings = array(
    'body' => array(
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_expert',
          'lb' => 'Breaking News',
          'lb-el' => 'h4',
          'lb-cl' => 'title',
          'lb-col' => TRUE,
        ),
      ),
    ),
  );
  $export['node|breaking_news|teaser'] = $ds_fieldsetting;

  return $export;
}

/**
 * Implements hook_defaultconfig_ds_layout_settings_info().
 */
function uber_publisher_breaking_news_defaultconfig_ds_layout_settings_info() {
  $export = array();

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|breaking_news|teaser';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'breaking_news';
  $ds_layout->view_mode = 'teaser';
  $ds_layout->layout = 'ds_1col_wrapper';
  $ds_layout->settings = array(
    'regions' => array(
      'ds_content' => array(
        0 => 'body',
      ),
    ),
    'fields' => array(
      'body' => 'ds_content',
    ),
    'classes' => array(),
    'wrappers' => array(
      'ds_content' => 'div',
    ),
    'layout_wrapper' => 'div',
    'layout_attributes' => '',
    'layout_attributes_merge' => 1,
    'layout_link_attribute' => '',
    'layout_link_custom' => '',
  );
  $export['node|breaking_news|teaser'] = $ds_layout;

  return $export;
}

/**
 * Implements hook_defaultconfig_field_default_fields().
 */
function uber_publisher_breaking_news_defaultconfig_field_default_fields() {
  $fields = array();

  // Exported field: 'node-breaking_news-body'.
  $fields['node-breaking_news-body'] = array(
    'field_config' => array(
      'active' => 1,
      'cardinality' => 1,
      'deleted' => 0,
      'entity_types' => array(
        0 => 'node',
      ),
      'field_name' => 'body',
      'foreign keys' => array(
        'format' => array(
          'columns' => array(
            'format' => 'format',
          ),
          'table' => 'filter_format',
        ),
      ),
      'indexes' => array(
        'format' => array(
          0 => 'format',
        ),
      ),
      'locked' => 0,
      'module' => 'text',
      'settings' => array(),
      'translatable' => 0,
      'type' => 'text_with_summary',
    ),
    'field_instance' => array(
      'bundle' => 'breaking_news',
      'default_value' => NULL,
      'deleted' => 0,
      'description' => '',
      'display' => array(
        'default' => array(
          'label' => 'hidden',
          'module' => 'text',
          'settings' => array(),
          'type' => 'text_default',
          'weight' => 0,
        ),
        'teaser' => array(
          'label' => 'hidden',
          'module' => 'text',
          'settings' => array(),
          'type' => 'text_default',
          'weight' => 0,
        ),
      ),
      'ds_extras_field_template' => '',
      'entity_type' => 'node',
      'field_name' => 'body',
      'label' => 'Body',
      'required' => 1,
      'settings' => array(
        'better_formats' => array(
          'allowed_formats' => array(
            'basic_editor' => 'basic_editor',
            'html_editor' => 'html_editor',
            'plain_text' => 'plain_text',
            'visual_editor' => 'visual_editor',
          ),
          'allowed_formats_toggle' => 0,
          'default_order_toggle' => 0,
          'default_order_wrapper' => array(
            'formats' => array(
              'basic_editor' => array(
                'weight' => -9,
              ),
              'html_editor' => array(
                'weight' => -7,
              ),
              'plain_text' => array(
                'weight' => -8,
              ),
              'visual_editor' => array(
                'weight' => -10,
              ),
            ),
          ),
        ),
        'display_summary' => 0,
        'linkit' => array(
          'button_text' => 'Search',
          'enable' => 0,
          'profile' => '',
        ),
        'text_processing' => 0,
        'user_register_form' => FALSE,
      ),
      'widget' => array(
        'active' => 1,
        'module' => 'text',
        'settings' => array(
          'maxlength_js' => 100,
          'maxlength_js_enforce' => 1,
          'maxlength_js_label' => 'Content limited to @limit characters, remaining: <strong>@remaining</strong>',
          'maxlength_js_label_summary' => 'Content limited to @limit characters, remaining: <strong>@remaining</strong>',
          'maxlength_js_summary' => '',
          'maxlength_js_truncate_html' => 0,
          'rows' => 5,
          'summary_rows' => 5,
        ),
        'type' => 'text_textarea_with_summary',
        'weight' => 6,
      ),
    ),
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('Body');

  return $fields;
}

/**
 * Implements hook_defaultconfig_strongarm().
 */
function uber_publisher_breaking_news_defaultconfig_strongarm() {
  $export = array();

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'additional_settings__active_tab_breaking_news';
  $strongarm->value = 'edit-submission';
  $export['additional_settings__active_tab_breaking_news'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'diff_enable_revisions_page_node_breaking_news';
  $strongarm->value = 1;
  $export['diff_enable_revisions_page_node_breaking_news'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'diff_show_preview_changes_node_breaking_news';
  $strongarm->value = 1;
  $export['diff_show_preview_changes_node_breaking_news'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'diff_view_mode_preview_node_breaking_news';
  $strongarm->value = 'full';
  $export['diff_view_mode_preview_node_breaking_news'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'field_bundle_settings_node__breaking_news';
  $strongarm->value = array(
    'view_modes' => array(),
    'extra_fields' => array(
      'form' => array(
        'language' => array(
          'weight' => '2',
        ),
        'metatags' => array(
          'weight' => '5',
        ),
        'title' => array(
          'weight' => '1',
        ),
        'path' => array(
          'weight' => '3',
        ),
        'redirect' => array(
          'weight' => '4',
        ),
      ),
      'display' => array(
        'language' => array(
          'teaser' => array(
            'weight' => '8',
            'visible' => FALSE,
          ),
        ),
      ),
    ),
  );
  $export['field_bundle_settings_node__breaking_news'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'i18n_node_extended_breaking_news';
  $strongarm->value = '1';
  $export['i18n_node_extended_breaking_news'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'i18n_node_options_breaking_news';
  $strongarm->value = array(
    0 => 'current',
    1 => 'required',
  );
  $export['i18n_node_options_breaking_news'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'i18n_sync_node_type_breaking_news';
  $strongarm->value = array();
  $export['i18n_sync_node_type_breaking_news'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'language_content_type_breaking_news';
  $strongarm->value = '2';
  $export['language_content_type_breaking_news'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'maxlength_js_breaking_news';
  $strongarm->value = '';
  $export['maxlength_js_breaking_news'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'maxlength_js_label_breaking_news';
  $strongarm->value = 'Content limited to @limit characters, remaining: <strong>@remaining</strong>';
  $export['maxlength_js_label_breaking_news'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'menu_options_breaking_news';
  $strongarm->value = array();
  $export['menu_options_breaking_news'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'menu_parent_breaking_news';
  $strongarm->value = 'main-menu:0';
  $export['menu_parent_breaking_news'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_options_breaking_news';
  $strongarm->value = array(
    0 => 'status',
  );
  $export['node_options_breaking_news'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_preview_breaking_news';
  $strongarm->value = '0';
  $export['node_preview_breaking_news'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_submitted_breaking_news';
  $strongarm->value = 0;
  $export['node_submitted_breaking_news'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'panelizer_defaults_node_breaking_news';
  $strongarm->value = array(
    'status' => 0,
    'view modes' => array(
      'page_manager' => array(
        'status' => 0,
        'default' => 0,
        'choice' => 0,
      ),
      'default' => array(
        'status' => 0,
        'default' => 0,
        'choice' => 0,
      ),
      'teaser' => array(
        'status' => 0,
        'default' => 0,
        'choice' => 0,
      ),
    ),
  );
  $export['panelizer_defaults_node_breaking_news'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'save_continue_breaking_news';
  $strongarm->value = 'Save and add fields';
  $export['save_continue_breaking_news'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'scheduler_expand_fieldset_breaking_news';
  $strongarm->value = '0';
  $export['scheduler_expand_fieldset_breaking_news'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'scheduler_publish_enable_breaking_news';
  $strongarm->value = 0;
  $export['scheduler_publish_enable_breaking_news'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'scheduler_publish_past_date_breaking_news';
  $strongarm->value = 'error';
  $export['scheduler_publish_past_date_breaking_news'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'scheduler_publish_required_breaking_news';
  $strongarm->value = 0;
  $export['scheduler_publish_required_breaking_news'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'scheduler_publish_revision_breaking_news';
  $strongarm->value = 0;
  $export['scheduler_publish_revision_breaking_news'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'scheduler_publish_touch_breaking_news';
  $strongarm->value = 0;
  $export['scheduler_publish_touch_breaking_news'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'scheduler_unpublish_enable_breaking_news';
  $strongarm->value = 0;
  $export['scheduler_unpublish_enable_breaking_news'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'scheduler_unpublish_required_breaking_news';
  $strongarm->value = 0;
  $export['scheduler_unpublish_required_breaking_news'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'scheduler_unpublish_revision_breaking_news';
  $strongarm->value = 0;
  $export['scheduler_unpublish_revision_breaking_news'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'scheduler_use_vertical_tabs_breaking_news';
  $strongarm->value = '1';
  $export['scheduler_use_vertical_tabs_breaking_news'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'workbench_moderation_default_state_breaking_news';
  $strongarm->value = 'draft';
  $export['workbench_moderation_default_state_breaking_news'] = $strongarm;

  return $export;
}

/**
 * Implements hook_defaultconfig_user_default_permissions().
 */
function uber_publisher_breaking_news_defaultconfig_user_default_permissions() {
  $permissions = array();

  // Exported permission: 'administer panelizer node breaking_news defaults'.
  $permissions['administer panelizer node breaking_news defaults'] = array(
    'name' => 'administer panelizer node breaking_news defaults',
    'roles' => array(),
    'module' => 'panelizer',
  );

  // Exported permission: 'create breaking_news content'.
  $permissions['create breaking_news content'] = array(
    'name' => 'create breaking_news content',
    'roles' => array(
      'Content Admin' => 'Content Admin',
      'Site Admin' => 'Site Admin',
      'Super Admin' => 'Super Admin',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete any breaking_news content'.
  $permissions['delete any breaking_news content'] = array(
    'name' => 'delete any breaking_news content',
    'roles' => array(
      'Content Admin' => 'Content Admin',
      'Site Admin' => 'Site Admin',
      'Super Admin' => 'Super Admin',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete own breaking_news content'.
  $permissions['delete own breaking_news content'] = array(
    'name' => 'delete own breaking_news content',
    'roles' => array(
      'Content Admin' => 'Content Admin',
      'Site Admin' => 'Site Admin',
      'Super Admin' => 'Super Admin',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit any breaking_news content'.
  $permissions['edit any breaking_news content'] = array(
    'name' => 'edit any breaking_news content',
    'roles' => array(
      'Content Admin' => 'Content Admin',
      'Site Admin' => 'Site Admin',
      'Super Admin' => 'Super Admin',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit own breaking_news content'.
  $permissions['edit own breaking_news content'] = array(
    'name' => 'edit own breaking_news content',
    'roles' => array(
      'Content Admin' => 'Content Admin',
      'Site Admin' => 'Site Admin',
      'Super Admin' => 'Super Admin',
    ),
    'module' => 'node',
  );

  // Exported permission: 'enter breaking_news revision log entry'.
  $permissions['enter breaking_news revision log entry'] = array(
    'name' => 'enter breaking_news revision log entry',
    'roles' => array(),
    'module' => 'override_node_options',
  );

  // Exported permission: 'override breaking_news authored by option'.
  $permissions['override breaking_news authored by option'] = array(
    'name' => 'override breaking_news authored by option',
    'roles' => array(),
    'module' => 'override_node_options',
  );

  // Exported permission: 'override breaking_news authored on option'.
  $permissions['override breaking_news authored on option'] = array(
    'name' => 'override breaking_news authored on option',
    'roles' => array(),
    'module' => 'override_node_options',
  );

  // Exported permission: 'override breaking_news promote to front page option'.
  $permissions['override breaking_news promote to front page option'] = array(
    'name' => 'override breaking_news promote to front page option',
    'roles' => array(),
    'module' => 'override_node_options',
  );

  // Exported permission: 'override breaking_news published option'.
  $permissions['override breaking_news published option'] = array(
    'name' => 'override breaking_news published option',
    'roles' => array(),
    'module' => 'override_node_options',
  );

  // Exported permission: 'override breaking_news revision option'.
  $permissions['override breaking_news revision option'] = array(
    'name' => 'override breaking_news revision option',
    'roles' => array(),
    'module' => 'override_node_options',
  );

  // Exported permission: 'override breaking_news sticky option'.
  $permissions['override breaking_news sticky option'] = array(
    'name' => 'override breaking_news sticky option',
    'roles' => array(),
    'module' => 'override_node_options',
  );

  return $permissions;
}

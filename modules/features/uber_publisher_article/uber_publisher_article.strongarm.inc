<?php
/**
 * @file
 * uber_publisher_article.strongarm.inc
 */

/**
 * Implements hook_strongarm().
 */
function uber_publisher_article_strongarm() {
  $export = array();

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'diff_enable_revisions_page_node_uber_publisher_article';
  $strongarm->value = 1;
  $export['diff_enable_revisions_page_node_uber_publisher_article'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'diff_show_preview_changes_node_uber_publisher_article';
  $strongarm->value = 1;
  $export['diff_show_preview_changes_node_uber_publisher_article'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'diff_view_mode_preview_node_uber_publisher_article';
  $strongarm->value = 'full';
  $export['diff_view_mode_preview_node_uber_publisher_article'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'field_bundle_settings_node__uber_publisher_article';
  $strongarm->value = array(
    'view_modes' => array(
      'full' => array(
        'custom_settings' => TRUE,
      ),
      'teaser' => array(
        'custom_settings' => TRUE,
      ),
      'rss' => array(
        'custom_settings' => FALSE,
      ),
      'diff_standard' => array(
        'custom_settings' => FALSE,
      ),
      'token' => array(
        'custom_settings' => FALSE,
      ),
      'revision' => array(
        'custom_settings' => FALSE,
      ),
      'vertical_teaser' => array(
        'custom_settings' => TRUE,
      ),
      'mini_teaser' => array(
        'custom_settings' => TRUE,
      ),
      'title_only' => array(
        'custom_settings' => TRUE,
      ),
    ),
    'extra_fields' => array(
      'form' => array(
        'language' => array(
          'weight' => '2',
        ),
        'title' => array(
          'weight' => '3',
        ),
        'path' => array(
          'weight' => '4',
        ),
        'redirect' => array(
          'weight' => '5',
        ),
        'scheduler_settings' => array(
          'weight' => '3',
        ),
        'metatags' => array(
          'weight' => '6',
        ),
      ),
      'display' => array(
        'language' => array(
          'default' => array(
            'weight' => '0',
            'visible' => TRUE,
          ),
          'full' => array(
            'weight' => '10',
            'visible' => FALSE,
          ),
          'vertical_teaser' => array(
            'weight' => '14',
            'visible' => FALSE,
          ),
          'mini_teaser' => array(
            'weight' => '9',
            'visible' => FALSE,
          ),
          'teaser' => array(
            'weight' => '14',
            'visible' => FALSE,
          ),
          'title_only' => array(
            'weight' => '0',
            'visible' => FALSE,
          ),
        ),
      ),
    ),
  );
  $export['field_bundle_settings_node__uber_publisher_article'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'field_bundle_settings_taxonomy_term__article_type';
  $strongarm->value = array(
    'view_modes' => array(
      'full' => array(
        'custom_settings' => FALSE,
      ),
      'diff_standard' => array(
        'custom_settings' => FALSE,
      ),
      'token' => array(
        'custom_settings' => FALSE,
      ),
    ),
    'extra_fields' => array(
      'form' => array(
        'metatags' => array(
          'weight' => '5',
        ),
        'path' => array(
          'weight' => '4',
        ),
        'redirect' => array(
          'weight' => '3',
        ),
        'name' => array(
          'weight' => '0',
        ),
        'description' => array(
          'weight' => '2',
        ),
      ),
      'display' => array(
        'description' => array(
          'default' => array(
            'weight' => '0',
            'visible' => TRUE,
          ),
        ),
      ),
    ),
  );
  $export['field_bundle_settings_taxonomy_term__article_type'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'hs_config_taxonomy-field_up_category';
  $strongarm->value = array(
    'config_id' => 'taxonomy-field_up_category',
    'save_lineage' => '1',
    'enforce_deepest' => '1',
    'resizable' => '0',
    'level_labels' => array(
      'status' => 0,
      'labels' => array(
        0 => '',
      ),
    ),
    'dropbox' => array(
      'status' => 1,
      'title' => 'All selections',
      'limit' => '0',
      'reset_hs' => '1',
    ),
    'editability' => array(
      'status' => 0,
      'item_types' => array(
        0 => '',
      ),
      'allowed_levels' => array(
        0 => 1,
      ),
      'allow_new_levels' => 0,
      'max_levels' => '0',
    ),
  );
  $export['hs_config_taxonomy-field_up_category'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'i18n_node_extended_uber_publisher_article';
  $strongarm->value = '1';
  $export['i18n_node_extended_uber_publisher_article'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'i18n_node_options_uber_publisher_article';
  $strongarm->value = array(
    0 => 'current',
    1 => 'required',
  );
  $export['i18n_node_options_uber_publisher_article'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'i18n_sync_node_type_uber_publisher_article';
  $strongarm->value = array(
    0 => 'field_article_type',
  );
  $export['i18n_sync_node_type_uber_publisher_article'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'language_content_type_uber_publisher_article';
  $strongarm->value = '2';
  $export['language_content_type_uber_publisher_article'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'maxlength_js_label_uber_publisher_article';
  $strongarm->value = 'Content limited to @limit characters, remaining: <strong>@remaining</strong>';
  $export['maxlength_js_label_uber_publisher_article'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'maxlength_js_uber_publisher_article';
  $strongarm->value = '';
  $export['maxlength_js_uber_publisher_article'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'menu_options_uber_publisher_article';
  $strongarm->value = array();
  $export['menu_options_uber_publisher_article'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'menu_parent_uber_publisher_article';
  $strongarm->value = 'main-menu:0';
  $export['menu_parent_uber_publisher_article'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_options_uber_publisher_article';
  $strongarm->value = array(
    0 => 'moderation',
    1 => 'revision',
  );
  $export['node_options_uber_publisher_article'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_preview_uber_publisher_article';
  $strongarm->value = '0';
  $export['node_preview_uber_publisher_article'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_submitted_uber_publisher_article';
  $strongarm->value = 0;
  $export['node_submitted_uber_publisher_article'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'panelizer_defaults_node_uber_publisher_article';
  $strongarm->value = array(
    'status' => 1,
    'view modes' => array(
      'page_manager' => array(
        'status' => 1,
        'default' => 1,
        'choice' => 1,
      ),
      'default' => array(
        'status' => 0,
        'default' => 0,
        'choice' => 0,
      ),
      'full' => array(
        'status' => 0,
        'default' => 0,
        'choice' => 0,
      ),
      'teaser' => array(
        'status' => 0,
        'default' => 0,
        'choice' => 0,
      ),
      'vertical_teaser' => array(
        'status' => 0,
        'default' => 0,
        'choice' => 0,
      ),
    ),
  );
  $export['panelizer_defaults_node_uber_publisher_article'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'panelizer_defaults_taxonomy_term_article_type';
  $strongarm->value = array(
    'status' => 1,
    'view modes' => array(
      'page_manager' => array(
        'status' => 1,
        'substitute' => '',
        'default' => 1,
        'choice' => 0,
      ),
      'default' => array(
        'status' => 0,
        'substitute' => 0,
        'default' => 0,
        'choice' => 0,
      ),
    ),
  );
  $export['panelizer_defaults_taxonomy_term_article_type'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'panelizer_node:uber_publisher_article_allowed_layouts';
  $strongarm->value = 'O:22:"panels_allowed_layouts":4:{s:9:"allow_new";b:1;s:11:"module_name";s:37:"panelizer_node:uber_publisher_article";s:23:"allowed_layout_settings";a:21:{s:8:"flexible";b:0;s:17:"threecol_25_50_25";b:0;s:13:"twocol_bricks";b:0;s:17:"threecol_33_34_33";b:0;s:6:"twocol";b:0;s:6:"onecol";b:1;s:25:"threecol_25_50_25_stacked";b:0;s:25:"threecol_33_34_33_stacked";b:0;s:14:"twocol_stacked";b:0;s:26:"bootstrap_threecol_stacked";b:0;s:24:"bootstrap_twocol_stacked";b:0;s:8:"upstairs";b:0;s:10:"downstairs";b:0;s:12:"jose_flipped";b:1;s:4:"jose";b:1;s:10:"two_halves";b:1;s:13:"four_quarters";b:1;s:13:"right_sidebar";b:1;s:10:"one_column";b:1;s:12:"three_thirds";b:1;s:12:"left_sidebar";b:1;}s:10:"form_state";N;}';
  $export['panelizer_node:uber_publisher_article_allowed_layouts'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'panelizer_node:uber_publisher_article_allowed_layouts_default';
  $strongarm->value = 0;
  $export['panelizer_node:uber_publisher_article_allowed_layouts_default'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'panelizer_node:uber_publisher_article_allowed_types';
  $strongarm->value = array(
    'node-node' => 0,
    'node_links-node_links' => 0,
    'node_content-node_content' => 0,
    'node_title-node_title' => 0,
    'node_body-node_body' => 0,
    'node_terms-node_terms' => 0,
    'node_author-node_author' => 0,
    'node_type_desc-node_type_desc' => 0,
    'node_created-node_created' => 0,
    'node_attachments-node_attachments' => 0,
    'node_updated-node_updated' => 0,
    'user_signature-user_signature' => 0,
    'user_links-user_links' => 0,
    'user_profile-user_profile' => 0,
    'user_picture-user_picture' => 0,
    'vocabulary_terms-vocabulary_terms' => 0,
    'page_breadcrumb-page_breadcrumb' => 0,
    'page_logo-page_logo' => 0,
    'page_feed_icons-page_feed_icons' => 0,
    'page_primary_links-page_primary_links' => 0,
    'page_title-page_title' => 0,
    'page_slogan-page_slogan' => 0,
    'page_actions-page_actions' => 0,
    'page_messages-page_messages' => 0,
    'page_secondary_links-page_secondary_links' => 0,
    'page_tabs-page_tabs' => 0,
    'page_site_name-page_site_name' => 0,
    'page_help-page_help' => 0,
    'term_list-term_list' => 0,
    'term_name-term_name' => 0,
    'term_description-term_description' => 0,
    'comment_links-comment_links' => 0,
    'node_form_menu-node_form_menu' => 0,
    'node_form_path-node_form_path' => 0,
    'node_form_log-node_form_log' => 0,
    'node_form_language-node_form_language' => 0,
    'node_form_title-node_form_title' => 0,
    'node_form_author-node_form_author' => 0,
    'node_form_publishing-node_form_publishing' => 0,
    'node_form_buttons-node_form_buttons' => 0,
    'form-form' => 0,
    'file_content-file_content' => 0,
    'file_display-file_display' => 0,
    'scheduler_form_pane-scheduler_form_pane' => 0,
    'uber_publisher_latest_bar-uber_publisher_latest_bar' => 0,
    'uber_publisher_featured_article-uber_publisher_featured_article' => 0,
    'views_exposed-views_exposed' => 0,
    'views_row-views_row' => 0,
    'views_view-views_view' => 0,
    'views_footer-views_footer' => 0,
    'views_attachments-views_attachments' => 0,
    'views_feed-views_feed' => 0,
    'views_empty-views_empty' => 0,
    'views_pager-views_pager' => 0,
    'views_header-views_header' => 0,
    'dsc-dsc' => 0,
    'panelizer_form_default-panelizer_form_default' => 0,
    'entity_field_extra-node:language' => 0,
    'entity_field_extra-file:file' => 0,
    'entity_field_extra-taxonomy_term:description' => 0,
    'entity_field_extra-taxonomy_term:language' => 0,
    'entity_field_extra-user:masquerade' => 0,
    'entity_field_extra-user:summary' => 0,
    'entity_field-node:body' => 0,
    'entity_field-node:field_up_category' => 0,
    'entity_field-node:field_up_dossier' => 0,
    'entity_field-node:field_up_tags' => 0,
    'entity_field-node:field_up_thumbnail' => 0,
    'entity_field-node:field_author' => 0,
    'entity_field-node:field_real_user' => 0,
    'entity_field-node:field_social_links' => 0,
    'entity_field-file:field_file_image_alt_text' => 0,
    'entity_field-file:field_file_image_title_text' => 0,
    'custom-custom' => 0,
    'block-masquerade-masquerade' => 0,
    'block-apps-manage_apps__uber_publisher' => 0,
    'block-context_ui-editor' => 0,
    'block-context_ui-devel' => 0,
    'block-diff-inline' => 0,
    'block-locale-language' => 0,
    'block-menu-add-content' => 0,
    'block-menu-devel' => 0,
    'block-menu-menu-secondary-menu' => 0,
    'block-menu_block-secondary-menu-block' => 0,
    'block-node-syndicate' => 0,
    'block-node-recent' => 0,
    'block-responsive_preview-controls' => 0,
    'block-shortcut-shortcuts' => 0,
    'block-system-powered-by' => 0,
    'block-system-help' => 0,
    'block-system-navigation' => 0,
    'block-system-management' => 0,
    'block-system-user-menu' => 0,
    'block-system-main-menu' => 0,
    'block-uber_publisher_follow-uber-publisher-follow' => 0,
    'block-user-login' => 0,
    'block-user-new' => 0,
    'block-user-online' => 0,
    'block-workbench-block' => 0,
    'block-devel-execute_php' => 0,
    'block-devel-switch_user' => 0,
    'token-node:source' => 0,
    'token-node:log' => 0,
    'token-node:content-type' => 0,
    'token-node:diff' => 0,
    'token-node:diff-markdown' => 0,
    'token-node:menu-link' => 0,
    'token-node:metatag' => 0,
    'token-node:nid' => 0,
    'token-node:vid' => 0,
    'token-node:title' => 0,
    'token-node:body' => 0,
    'token-node:summary' => 0,
    'token-node:language' => 0,
    'token-node:url' => 0,
    'token-node:edit-url' => 0,
    'token-node:created' => 0,
    'token-node:changed' => 0,
    'token-node:author' => 0,
    'token-node:scheduler-publish' => 0,
    'token-node:scheduler-unpublish' => 0,
    'token-node:original' => 0,
    'token-node:is-new' => 0,
    'token-node:status' => 0,
    'token-node:promote' => 0,
    'token-node:sticky' => 0,
    'token-node:revision' => 0,
    'token-node:field-up-thumbnail' => 0,
    'token-node:field-up-category' => 0,
    'token-node:field-up-dossier' => 0,
    'token-node:field-up-tags' => 0,
    'token-node:field-author' => 0,
    'token-node:field-real-user' => 0,
    'token-node:field_up_thumbnail' => 0,
    'token-node:field_up_category' => 0,
    'token-node:field_up_dossier' => 0,
    'token-node:field_up_tags' => 0,
    'token-node:field_author' => 0,
    'token-node:field_real_user' => 0,
    'token-node:field_social_links' => 0,
    'token-content-type:name' => 0,
    'token-content-type:machine-name' => 0,
    'token-content-type:description' => 0,
    'token-content-type:node-count' => 0,
    'token-content-type:edit-url' => 0,
    'token-content-type:i18n-name' => 0,
    'token-content-type:i18n-description' => 0,
    'token-term:edit-url' => 0,
    'token-term:parents' => 0,
    'token-term:root' => 0,
    'token-term:metatag' => 0,
    'token-term:tid' => 0,
    'token-term:name' => 0,
    'token-term:description' => 0,
    'token-term:node-count' => 0,
    'token-term:url' => 0,
    'token-term:vocabulary' => 0,
    'token-term:parent' => 0,
    'token-term:i18n-name' => 0,
    'token-term:i18n-description' => 0,
    'token-term:i18n-vocabulary' => 0,
    'token-term:i18n-parent' => 0,
    'token-term:original' => 0,
    'token-term:weight' => 0,
    'token-term:parents-all' => 0,
    'token-vocabulary:machine-name' => 0,
    'token-vocabulary:edit-url' => 0,
    'token-vocabulary:vid' => 0,
    'token-vocabulary:name' => 0,
    'token-vocabulary:description' => 0,
    'token-vocabulary:node-count' => 0,
    'token-vocabulary:term-count' => 0,
    'token-vocabulary:i18n-name' => 0,
    'token-vocabulary:i18n-description' => 0,
    'token-vocabulary:original' => 0,
    'token-file:basename' => 0,
    'token-file:extension' => 0,
    'token-file:size-raw' => 0,
    'token-file:ffp-name-only' => 0,
    'token-file:ffp-name-only-original' => 0,
    'token-file:ffp-extension-original' => 0,
    'token-file:type' => 0,
    'token-file:download-url' => 0,
    'token-file:fid' => 0,
    'token-file:name' => 0,
    'token-file:path' => 0,
    'token-file:mime' => 0,
    'token-file:size' => 0,
    'token-file:url' => 0,
    'token-file:timestamp' => 0,
    'token-file:owner' => 0,
    'token-file:original' => 0,
    'token-file:field-file-image-alt-text' => 0,
    'token-file:field-file-image-title-text' => 0,
    'token-file:field_file_image_alt_text' => 0,
    'token-file:field_file_image_title_text' => 0,
    'token-user:cancel-url' => 0,
    'token-user:one-time-login-url' => 0,
    'token-user:roles' => 0,
    'token-user:uid' => 0,
    'token-user:name' => 0,
    'token-user:mail' => 0,
    'token-user:url' => 0,
    'token-user:edit-url' => 0,
    'token-user:last-login' => 0,
    'token-user:created' => 0,
    'token-user:original' => 0,
    'token-user:last-access' => 0,
    'token-user:status' => 0,
    'token-user:theme' => 0,
    'token-current-user:ip-address' => 0,
    'token-menu-link:mlid' => 0,
    'token-menu-link:title' => 0,
    'token-menu-link:url' => 0,
    'token-menu-link:parent' => 0,
    'token-menu-link:parents' => 0,
    'token-menu-link:root' => 0,
    'token-menu-link:menu' => 0,
    'token-menu-link:edit-url' => 0,
    'token-current-page:title' => 0,
    'token-current-page:url' => 0,
    'token-current-page:page-number' => 0,
    'token-current-page:query' => 0,
    'token-url:path' => 0,
    'token-url:relative' => 0,
    'token-url:absolute' => 0,
    'token-url:brief' => 0,
    'token-url:unaliased' => 0,
    'token-url:args' => 0,
    'token-array:first' => 0,
    'token-array:last' => 0,
    'token-array:count' => 0,
    'token-array:reversed' => 0,
    'token-array:keys' => 0,
    'token-array:join' => 0,
    'token-array:value' => 0,
    'token-array:join-path' => 0,
    'token-random:number' => 0,
    'token-random:hash' => 0,
    'token-date-field-value:date' => 0,
    'token-date-field-value:to-date' => 0,
    'token-file-type:name' => 0,
    'token-file-type:machine-name' => 0,
    'token-file-type:count' => 0,
    'token-file-type:edit-url' => 0,
    'token-menu:name' => 0,
    'token-menu:machine-name' => 0,
    'token-menu:description' => 0,
    'token-menu:menu-link-count' => 0,
    'token-menu:edit-url' => 0,
    'token-metatag:title' => 0,
    'token-metatag:description' => 0,
    'token-metatag:abstract' => 0,
    'token-metatag:keywords' => 0,
    'token-metatag:robots' => 0,
    'token-metatag:news_keywords' => 0,
    'token-metatag:standout' => 0,
    'token-metatag:generator' => 0,
    'token-metatag:rights' => 0,
    'token-metatag:image_src' => 0,
    'token-metatag:canonical' => 0,
    'token-metatag:shortlink' => 0,
    'token-metatag:publisher' => 0,
    'token-metatag:author' => 0,
    'token-metatag:original-source' => 0,
    'token-metatag:revisit-after' => 0,
    'token-metatag:content-language' => 0,
    'token-metatag:og:site_name' => 0,
    'token-metatag:og:type' => 0,
    'token-metatag:og:url' => 0,
    'token-metatag:og:title' => 0,
    'token-metatag:og:determiner' => 0,
    'token-metatag:og:description' => 0,
    'token-metatag:og:updated_time' => 0,
    'token-metatag:og:see_also' => 0,
    'token-metatag:og:image' => 0,
    'token-metatag:og:image:secure_url' => 0,
    'token-metatag:og:image:type' => 0,
    'token-metatag:og:image:width' => 0,
    'token-metatag:og:image:height' => 0,
    'token-metatag:og:latitude' => 0,
    'token-metatag:og:longitude' => 0,
    'token-metatag:og:street-address' => 0,
    'token-metatag:og:locality' => 0,
    'token-metatag:og:region' => 0,
    'token-metatag:og:postal-code' => 0,
    'token-metatag:og:country-name' => 0,
    'token-metatag:og:email' => 0,
    'token-metatag:og:phone_number' => 0,
    'token-metatag:og:fax_number' => 0,
    'token-metatag:og:locale' => 0,
    'token-metatag:og:locale:alternate' => 0,
    'token-metatag:article:author' => 0,
    'token-metatag:article:publisher' => 0,
    'token-metatag:article:section' => 0,
    'token-metatag:article:tag' => 0,
    'token-metatag:article:published_time' => 0,
    'token-metatag:article:modified_time' => 0,
    'token-metatag:article:expiration_time' => 0,
    'token-metatag:profile:first_name' => 0,
    'token-metatag:profile:last_name' => 0,
    'token-metatag:profile:username' => 0,
    'token-metatag:profile:gender' => 0,
    'token-metatag:og:audio' => 0,
    'token-metatag:og:audio:secure_url' => 0,
    'token-metatag:og:audio:type' => 0,
    'token-metatag:book:author' => 0,
    'token-metatag:book:isbn' => 0,
    'token-metatag:book:release_date' => 0,
    'token-metatag:book:tag' => 0,
    'token-metatag:og:video' => 0,
    'token-metatag:og:video:secure_url' => 0,
    'token-metatag:og:video:width' => 0,
    'token-metatag:og:video:height' => 0,
    'token-metatag:og:video:type' => 0,
    'token-metatag:video:actor' => 0,
    'token-metatag:video:actor:role' => 0,
    'token-metatag:video:director' => 0,
    'token-metatag:video:writer' => 0,
    'token-metatag:video:duration' => 0,
    'token-metatag:video:release_date' => 0,
    'token-metatag:video:tag' => 0,
    'token-metatag:video:series' => 0,
    'token-site:name' => 0,
    'token-site:slogan' => 0,
    'token-site:mail' => 0,
    'token-site:url' => 0,
    'token-site:url-brief' => 0,
    'token-site:login-url' => 0,
    'token-site:root_url' => 0,
    'token-site:current-user' => 0,
    'token-site:current-date' => 0,
    'token-site:current-page' => 0,
    'token-date:short' => 0,
    'token-date:medium' => 0,
    'token-date:long' => 0,
    'token-date:custom' => 0,
    'token-date:since' => 0,
    'token-date:raw' => 0,
    'token-date:varbase_date_and_time' => 0,
    'token-date:varbase_time' => 0,
    'token-variable:i18n_select_page_list' => 0,
    'token-variable:i18n_select_skip_tags' => 0,
    'token-variable:media_wysiwyg_wysiwyg_title' => 0,
    'token-variable:media_wysiwyg_wysiwyg_icon_title' => 0,
    'token-variable:site_name' => 0,
    'token-variable:site_mail' => 0,
    'token-variable:site_slogan' => 0,
    'token-variable:anonymous' => 0,
    'token-variable:feed_description' => 0,
    'token-variable:maintenance_mode_message' => 0,
    'token-variable:user_registration_help' => 0,
    'token-variable:user_picture_default' => 0,
    'token-variable:user_picture_dimensions' => 0,
    'token-variable:user_picture_file_size' => 0,
    'token-variable:user_picture_guidelines' => 0,
    'token-view:name' => 0,
    'token-view:description' => 0,
    'token-view:machine-name' => 0,
    'token-view:title' => 0,
    'token-view:url' => 0,
    'token-rules_text:value' => 0,
    'token-rules_integer:value' => 0,
    'token-rules_uri:value' => 0,
    'token-rules_token:value' => 0,
    'token-rules_decimal:value' => 0,
    'token-rules_date:value' => 0,
    'token-rules_duration:value' => 0,
    'token-workbench_moderation_transition:id' => 0,
    'token-workbench_moderation_transition:name' => 0,
    'token-workbench_moderation_transition:from-name' => 0,
    'token-workbench_moderation_transition:to-name' => 0,
    'token-rules_config:id' => 0,
    'token-rules_config:label' => 0,
    'token-rules_config:plugin' => 0,
    'token-rules_config:active' => 0,
    'token-rules_config:weight' => 0,
    'token-rules_config:status' => 0,
    'token-rules_config:dirty' => 0,
    'token-rules_config:module' => 0,
    'token-rules_config:owner' => 0,
    'token-rules_config:access-exposed' => 0,
    'token-list<node>:0' => 0,
    'token-list<node>:1' => 0,
    'token-list<node>:2' => 0,
    'token-list<node>:3' => 0,
    'token-list<file>:0' => 0,
    'token-list<file>:1' => 0,
    'token-list<file>:2' => 0,
    'token-list<file>:3' => 0,
    'token-list<term>:0' => 0,
    'token-list<term>:1' => 0,
    'token-list<term>:2' => 0,
    'token-list<term>:3' => 0,
    'token-list<vocabulary>:0' => 0,
    'token-list<vocabulary>:1' => 0,
    'token-list<vocabulary>:2' => 0,
    'token-list<vocabulary>:3' => 0,
    'token-list<user>:0' => 0,
    'token-list<user>:1' => 0,
    'token-list<user>:2' => 0,
    'token-list<user>:3' => 0,
    'token-list<workbench_moderation_transition>:0' => 0,
    'token-list<workbench_moderation_transition>:1' => 0,
    'token-list<workbench_moderation_transition>:2' => 0,
    'token-list<workbench_moderation_transition>:3' => 0,
    'token-list<rules_config>:0' => 0,
    'token-list<rules_config>:1' => 0,
    'token-list<rules_config>:2' => 0,
    'token-list<rules_config>:3' => 0,
    'token-list<date>:0' => 0,
    'token-list<date>:1' => 0,
    'token-list<date>:2' => 0,
    'token-list<date>:3' => 0,
    'entity_form_field-node:body' => 0,
    'entity_form_field-node:field_up_category' => 0,
    'entity_form_field-node:field_up_dossier' => 0,
    'entity_form_field-node:field_up_tags' => 0,
    'entity_form_field-node:field_up_thumbnail' => 0,
    'entity_form_field-node:field_author' => 0,
    'entity_form_field-node:field_real_user' => 0,
    'entity_form_field-node:field_social_links' => 0,
    'entity_form_field-file:field_file_image_alt_text' => 0,
    'entity_form_field-file:field_file_image_title_text' => 0,
    'entity_view-node' => 'entity_view-node',
    'entity_view-file' => 0,
    'entity_view-taxonomy_term' => 0,
    'entity_view-user' => 0,
    'entity_view-workbench_moderation_transition' => 0,
    'entity_view-rules_config' => 0,
    'menu_tree-_active' => 0,
    'menu_tree-add-content' => 0,
    'menu_tree-devel' => 0,
    'menu_tree-main-menu' => 0,
    'menu_tree-management' => 0,
    'menu_tree-navigation' => 0,
    'menu_tree-menu-secondary-menu' => 0,
    'menu_tree-user-menu' => 0,
    'uber_publisher_follow_widget-uber_publisher_follow_widget' => 0,
    'views_panes-featured_article-highlighted_slides' => 0,
    'views_panes-featured_article-classic_slider' => 0,
    'views_panes-article_listing-article_listing' => 0,
    'views_panes-article_listing-related_articles' => 0,
    'views_panes-content_general-content_list' => 0,
    'views_panes-taxonomy_general-hot_tags' => 0,
    'views_panes-uber_publisher_author_profile-articles_by' => 0,
    'views-featured_article' => 0,
    'views-admin_views_file' => 0,
    'views-admin_views_node' => 0,
    'views-admin_views_user' => 0,
    'views-article_listing' => 0,
    'views-content_general' => 0,
    'views-media_default' => 0,
    'views-taxonomy_general' => 0,
    'views-uber_publisher_author_profile' => 0,
    'views-uber_publisher_latest_bar' => 0,
    'views-workbench_current_user' => 0,
    'views-workbench_edited' => 0,
    'views-workbench_moderation' => 0,
    'views-workbench_recent_content' => 0,
  );
  $export['panelizer_node:uber_publisher_article_allowed_types'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'panelizer_node:uber_publisher_article_allowed_types_default';
  $strongarm->value = 0;
  $export['panelizer_node:uber_publisher_article_allowed_types_default'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'panelizer_node:uber_publisher_article_default';
  $strongarm->value = array(
    'entity_field_extra' => 0,
    'entity_field' => 0,
    'custom' => 0,
    'block' => 0,
    'token' => 0,
    'entity_form_field' => 0,
    'entity_view' => 0,
    'menu_tree' => 0,
    'uber_publisher_follow_widget' => 0,
    'views_panes' => 0,
    'views' => 0,
    'other' => 0,
  );
  $export['panelizer_node:uber_publisher_article_default'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'scheduler_expand_fieldset_uber_publisher_article';
  $strongarm->value = '1';
  $export['scheduler_expand_fieldset_uber_publisher_article'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'scheduler_publish_enable_uber_publisher_article';
  $strongarm->value = 1;
  $export['scheduler_publish_enable_uber_publisher_article'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'scheduler_publish_past_date_uber_publisher_article';
  $strongarm->value = 'error';
  $export['scheduler_publish_past_date_uber_publisher_article'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'scheduler_publish_required_uber_publisher_article';
  $strongarm->value = 0;
  $export['scheduler_publish_required_uber_publisher_article'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'scheduler_publish_revision_uber_publisher_article';
  $strongarm->value = 0;
  $export['scheduler_publish_revision_uber_publisher_article'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'scheduler_publish_touch_uber_publisher_article';
  $strongarm->value = 1;
  $export['scheduler_publish_touch_uber_publisher_article'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'scheduler_unpublish_enable_uber_publisher_article';
  $strongarm->value = 0;
  $export['scheduler_unpublish_enable_uber_publisher_article'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'scheduler_unpublish_required_uber_publisher_article';
  $strongarm->value = 0;
  $export['scheduler_unpublish_required_uber_publisher_article'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'scheduler_unpublish_revision_uber_publisher_article';
  $strongarm->value = 0;
  $export['scheduler_unpublish_revision_uber_publisher_article'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'scheduler_use_vertical_tabs_uber_publisher_article';
  $strongarm->value = '0';
  $export['scheduler_use_vertical_tabs_uber_publisher_article'] = $strongarm;

  return $export;
}

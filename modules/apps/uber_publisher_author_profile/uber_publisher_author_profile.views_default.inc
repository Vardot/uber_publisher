<?php
/**
 * @file
 * uber_publisher_author_profile.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function uber_publisher_author_profile_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'uber_publisher_author_profile';
  $view->description = 'Provide author profile information view.';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Author';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'uber_publisher_author' => 'uber_publisher_author',
  );

  /* Display: Field author reference */
  $handler = $view->new_display('entityreference', 'Field author reference', 'field_author_reference');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['defaults']['css_class'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '5';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'entityreference_style';
  $handler->display->display_options['style_options']['search_fields'] = array(
    'title' => 'title',
    'field_up_thumbnail' => 0,
  );
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'entityreference_fields';
  $handler->display->display_options['row_options']['separator'] = '';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Thumbnail */
  $handler->display->display_options['fields']['field_up_thumbnail']['id'] = 'field_up_thumbnail';
  $handler->display->display_options['fields']['field_up_thumbnail']['table'] = 'field_data_field_up_thumbnail';
  $handler->display->display_options['fields']['field_up_thumbnail']['field'] = 'field_up_thumbnail';
  $handler->display->display_options['fields']['field_up_thumbnail']['label'] = '';
  $handler->display->display_options['fields']['field_up_thumbnail']['element_type'] = 'div';
  $handler->display->display_options['fields']['field_up_thumbnail']['element_class'] = 'profile-picture';
  $handler->display->display_options['fields']['field_up_thumbnail']['element_label_type'] = '0';
  $handler->display->display_options['fields']['field_up_thumbnail']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_up_thumbnail']['element_wrapper_type'] = '0';
  $handler->display->display_options['fields']['field_up_thumbnail']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_up_thumbnail']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_up_thumbnail']['settings'] = array(
    'image_style' => 'icon',
    'image_link' => '',
  );
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_type'] = 'h6';
  $handler->display->display_options['fields']['title']['element_class'] = 'profile-name';
  $handler->display->display_options['fields']['title']['element_label_type'] = '0';
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['element_wrapper_type'] = '0';
  $handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'uber_publisher_author' => 'uber_publisher_author',
  );

  /* Display: Articles by */
  $handler = $view->new_display('panel_pane', 'Articles by', 'articles_by');
  $handler->display->display_options['defaults']['css_class'] = FALSE;
  $handler->display->display_options['css_class'] = 'articles-by clearfix';
  $handler->display->display_options['defaults']['exposed_form'] = FALSE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'mini';
  $handler->display->display_options['pager']['options']['items_per_page'] = '6';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'views_bootstrap_grid_plugin_style';
  $handler->display->display_options['style_options']['columns'] = '1';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'ds';
  $handler->display->display_options['row_options']['alternating'] = 0;
  $handler->display->display_options['row_options']['grouping'] = 0;
  $handler->display->display_options['row_options']['advanced'] = 0;
  $handler->display->display_options['row_options']['delta_fieldset']['delta_fields'] = array();
  $handler->display->display_options['row_options']['grouping_fieldset']['group_field'] = 'node|created';
  $handler->display->display_options['row_options']['default_fieldset']['view_mode'] = 'teaser';
  $handler->display->display_options['row_options']['alternating_fieldset']['allpages'] = TRUE;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  /* Sort criterion: Content: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Content: Author (field_author) */
  $handler->display->display_options['arguments']['field_author_target_id']['id'] = 'field_author_target_id';
  $handler->display->display_options['arguments']['field_author_target_id']['table'] = 'field_data_field_author';
  $handler->display->display_options['arguments']['field_author_target_id']['field'] = 'field_author_target_id';
  $handler->display->display_options['arguments']['field_author_target_id']['default_action'] = 'default';
  $handler->display->display_options['arguments']['field_author_target_id']['default_argument_type'] = 'node';
  $handler->display->display_options['arguments']['field_author_target_id']['default_argument_skip_url'] = TRUE;
  $handler->display->display_options['arguments']['field_author_target_id']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_author_target_id']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_author_target_id']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['field_author_target_id']['specify_validation'] = TRUE;
  $handler->display->display_options['arguments']['field_author_target_id']['validate']['type'] = 'node';
  $handler->display->display_options['arguments']['field_author_target_id']['validate_options']['nid_type'] = 'nids';
  $handler->display->display_options['arguments']['field_author_target_id']['validate']['fail'] = 'ignore';
  /* Contextual filter: Exclude Self (NID) */
  $handler->display->display_options['arguments']['nid']['id'] = 'nid';
  $handler->display->display_options['arguments']['nid']['table'] = 'node';
  $handler->display->display_options['arguments']['nid']['field'] = 'nid';
  $handler->display->display_options['arguments']['nid']['ui_name'] = 'Exclude Self (NID)';
  $handler->display->display_options['arguments']['nid']['default_action'] = 'default';
  $handler->display->display_options['arguments']['nid']['default_argument_type'] = 'node';
  $handler->display->display_options['arguments']['nid']['default_argument_skip_url'] = TRUE;
  $handler->display->display_options['arguments']['nid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['nid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['nid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['nid']['specify_validation'] = TRUE;
  $handler->display->display_options['arguments']['nid']['validate']['type'] = 'node';
  $handler->display->display_options['arguments']['nid']['validate']['fail'] = 'ignore';
  $handler->display->display_options['arguments']['nid']['not'] = TRUE;
  /* Contextual filter: Article from current category */
  $handler->display->display_options['arguments']['field_up_category_tid']['id'] = 'field_up_category_tid';
  $handler->display->display_options['arguments']['field_up_category_tid']['table'] = 'field_data_field_up_category';
  $handler->display->display_options['arguments']['field_up_category_tid']['field'] = 'field_up_category_tid';
  $handler->display->display_options['arguments']['field_up_category_tid']['ui_name'] = 'Article from current category';
  $handler->display->display_options['arguments']['field_up_category_tid']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['field_up_category_tid']['default_argument_skip_url'] = TRUE;
  $handler->display->display_options['arguments']['field_up_category_tid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_up_category_tid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_up_category_tid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['field_up_category_tid']['specify_validation'] = TRUE;
  $handler->display->display_options['arguments']['field_up_category_tid']['validate']['type'] = 'taxonomy_term';
  $handler->display->display_options['arguments']['field_up_category_tid']['validate_options']['vocabularies'] = array(
    'up_category' => 'up_category',
  );
  $handler->display->display_options['arguments']['field_up_category_tid']['validate_options']['type'] = 'tids';
  $handler->display->display_options['arguments']['field_up_category_tid']['validate']['fail'] = 'ignore';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'uber_publisher_article' => 'uber_publisher_article',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;
  /* Filter criterion: Content: Author (field_author) */
  $handler->display->display_options['filters']['field_author_target_id']['id'] = 'field_author_target_id';
  $handler->display->display_options['filters']['field_author_target_id']['table'] = 'field_data_field_author';
  $handler->display->display_options['filters']['field_author_target_id']['field'] = 'field_author_target_id';
  $handler->display->display_options['filters']['field_author_target_id']['group'] = 1;
  $handler->display->display_options['filters']['field_author_target_id']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_author_target_id']['expose']['operator_id'] = 'field_author_target_id_op';
  $handler->display->display_options['filters']['field_author_target_id']['expose']['label'] = 'Author';
  $handler->display->display_options['filters']['field_author_target_id']['expose']['operator'] = 'field_author_target_id_op';
  $handler->display->display_options['filters']['field_author_target_id']['expose']['identifier'] = 'field_author_target_id';
  $handler->display->display_options['filters']['field_author_target_id']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    4 => 0,
    3 => 0,
    5 => 0,
    6 => 0,
    7 => 0,
    8 => 0,
    9 => 0,
  );
  /* Filter criterion: Content: Language */
  $handler->display->display_options['filters']['language']['id'] = 'language';
  $handler->display->display_options['filters']['language']['table'] = 'node';
  $handler->display->display_options['filters']['language']['field'] = 'language';
  $handler->display->display_options['filters']['language']['value'] = array(
    '***CURRENT_LANGUAGE***' => '***CURRENT_LANGUAGE***',
  );
  $handler->display->display_options['pane_title'] = 'Articles by';
  $handler->display->display_options['pane_description'] = 'List content of an author';
  $handler->display->display_options['pane_category']['name'] = 'Listing';
  $handler->display->display_options['pane_category']['weight'] = '0';
  $handler->display->display_options['allow']['use_pager'] = 'use_pager';
  $handler->display->display_options['allow']['items_per_page'] = 'items_per_page';
  $handler->display->display_options['allow']['offset'] = 0;
  $handler->display->display_options['allow']['link_to_view'] = 0;
  $handler->display->display_options['allow']['more_link'] = 0;
  $handler->display->display_options['allow']['path_override'] = 0;
  $handler->display->display_options['allow']['title_override'] = 'title_override';
  $handler->display->display_options['allow']['exposed_form'] = 'exposed_form';
  $handler->display->display_options['allow']['fields_override'] = 'fields_override';
  $handler->display->display_options['argument_input'] = array(
    'field_author_target_id' => array(
      'type' => 'none',
      'context' => 'node_edit_form.nid',
      'context_optional' => 1,
      'panel' => '0',
      'fixed' => '',
      'label' => 'Content: Author (field_author)',
    ),
    'nid' => array(
      'type' => 'none',
      'context' => 'entity:file.field_file_image_alt_text',
      'context_optional' => 0,
      'panel' => '0',
      'fixed' => '',
      'label' => 'Exclude Self (NID)',
    ),
    'field_up_category_tid' => array(
      'type' => 'context',
      'context' => 'entity:taxonomy_term.tid',
      'context_optional' => 1,
      'panel' => '0',
      'fixed' => '',
      'label' => 'Article from current category',
    ),
  );
  $handler->display->display_options['inherit_panels_path'] = '1';

  /* Display: Author listing */
  $handler = $view->new_display('panel_pane', 'Author listing', 'author_listing');
  $handler->display->display_options['defaults']['exposed_form'] = FALSE;
  $handler->display->display_options['exposed_form']['type'] = 'better_exposed_filters';
  $handler->display->display_options['exposed_form']['options']['bef'] = array(
    'general' => array(
      'allow_secondary' => 0,
      'secondary_label' => 'Advanced options',
    ),
  );
  $handler->display->display_options['exposed_form']['options']['input_required'] = 0;
  $handler->display->display_options['exposed_form']['options']['text_input_required_format'] = 'visual_editor';
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'mini';
  $handler->display->display_options['pager']['options']['items_per_page'] = '5';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'views_bootstrap_grid_plugin_style';
  $handler->display->display_options['style_options']['columns'] = '1';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'ds';
  $handler->display->display_options['row_options']['view_mode'] = 'mini_teaser';
  $handler->display->display_options['row_options']['alternating'] = 0;
  $handler->display->display_options['row_options']['grouping'] = 0;
  $handler->display->display_options['row_options']['advanced'] = 0;
  $handler->display->display_options['row_options']['delta_fieldset']['delta_fields'] = array();
  $handler->display->display_options['row_options']['grouping_fieldset']['group_field'] = 'node|created';
  $handler->display->display_options['row_options']['default_fieldset']['view_mode'] = 'mini_teaser';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  /* Sort criterion: Content: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Exclude Self (Author ID) */
  $handler->display->display_options['arguments']['nid']['id'] = 'nid';
  $handler->display->display_options['arguments']['nid']['table'] = 'node';
  $handler->display->display_options['arguments']['nid']['field'] = 'nid';
  $handler->display->display_options['arguments']['nid']['ui_name'] = 'Exclude Self (Author ID)';
  $handler->display->display_options['arguments']['nid']['default_action'] = 'default';
  $handler->display->display_options['arguments']['nid']['default_argument_type'] = 'node';
  $handler->display->display_options['arguments']['nid']['default_argument_skip_url'] = TRUE;
  $handler->display->display_options['arguments']['nid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['nid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['nid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['nid']['specify_validation'] = TRUE;
  $handler->display->display_options['arguments']['nid']['validate']['type'] = 'node';
  $handler->display->display_options['arguments']['nid']['validate_options']['types'] = array(
    'uber_publisher_author' => 'uber_publisher_author',
  );
  $handler->display->display_options['arguments']['nid']['validate']['fail'] = 'ignore';
  $handler->display->display_options['arguments']['nid']['not'] = TRUE;
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = '1';
  $handler->display->display_options['filters']['status']['group'] = 1;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'uber_publisher_author' => 'uber_publisher_author',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;
  /* Filter criterion: Content: Language */
  $handler->display->display_options['filters']['language']['id'] = 'language';
  $handler->display->display_options['filters']['language']['table'] = 'node';
  $handler->display->display_options['filters']['language']['field'] = 'language';
  $handler->display->display_options['filters']['language']['value'] = array(
    '***CURRENT_LANGUAGE***' => '***CURRENT_LANGUAGE***',
  );
  $handler->display->display_options['pane_title'] = 'Author listing';
  $handler->display->display_options['pane_category']['name'] = 'Listing';
  $handler->display->display_options['pane_category']['weight'] = '0';
  $handler->display->display_options['allow']['use_pager'] = 'use_pager';
  $handler->display->display_options['allow']['items_per_page'] = 'items_per_page';
  $handler->display->display_options['allow']['offset'] = 0;
  $handler->display->display_options['allow']['link_to_view'] = 0;
  $handler->display->display_options['allow']['more_link'] = 'more_link';
  $handler->display->display_options['allow']['path_override'] = 0;
  $handler->display->display_options['allow']['title_override'] = 'title_override';
  $handler->display->display_options['allow']['exposed_form'] = 0;
  $handler->display->display_options['allow']['fields_override'] = 'fields_override';
  $handler->display->display_options['inherit_panels_path'] = '1';
  $export['uber_publisher_author_profile'] = $view;

  return $export;
}

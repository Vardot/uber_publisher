<?php
/**
 * @file
 * bundle_starter.panelizer.inc
 */

/**
 * Implements hook_panelizer_defaults().
 */
function bundle_starter_panelizer_defaults() {
  $export = array();

  $panelizer = new stdClass();
  $panelizer->disabled = FALSE; /* Edit this to true to make a default panelizer disabled initially */
  $panelizer->api_version = 1;
  $panelizer->name = 'node:uber_publisher_article:default';
  $panelizer->title = 'Default';
  $panelizer->panelizer_type = 'node';
  $panelizer->panelizer_key = 'uber_publisher_article';
  $panelizer->no_blocks = FALSE;
  $panelizer->css_id = '';
  $panelizer->css = '';
  $panelizer->pipeline = 'ipe';
  $panelizer->contexts = array();
  $panelizer->relationships = array(
    0 => array(
      'identifier' => 'Taxonomy term from Node Category',
      'keyword' => 'taxonomy_term',
      'name' => 'entity_from_field:field_up_category-node-taxonomy_term',
      'delta' => '1',
      'context' => 'panelizer',
      'id' => 1,
    ),
  );
  $panelizer->access = array();
  $panelizer->view_mode = 'page_manager';
  $panelizer->css_class = '';
  $panelizer->title_element = 'H2';
  $panelizer->link_to_entity = TRUE;
  $panelizer->extra = array();
  $display = new panels_display();
  $display->layout = 'right_sidebar';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'top' => NULL,
      'content' => NULL,
      'right' => NULL,
      'bottom' => NULL,
      'center' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = '%node:title';
  $display->uuid = '4300be43-72fe-4634-83fe-b30822518495';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-e5ad891f-a014-4a28-8533-dbc7afe8302d';
    $pane->panel = 'center';
    $pane->type = 'entity_view';
    $pane->subtype = 'node';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'view_mode' => 'full',
      'context' => 'panelizer',
      'override_title' => 0,
      'override_title_text' => '',
      'override_title_heading' => 'h2',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = 'e5ad891f-a014-4a28-8533-dbc7afe8302d';
    $display->content['new-e5ad891f-a014-4a28-8533-dbc7afe8302d'] = $pane;
    $display->panels['center'][0] = 'new-e5ad891f-a014-4a28-8533-dbc7afe8302d';
    $pane = new stdClass();
    $pane->pid = 'new-5c147f8b-8d6c-43e9-90ba-b96ba3a1bf16';
    $pane->panel = 'right';
    $pane->type = 'views_panes';
    $pane->subtype = 'article_listing-related_articles';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'use_pager' => 0,
      'pager_id' => '1',
      'items_per_page' => '3',
      'context' => array(
        0 => 'panelizer',
      ),
      'override_title' => 1,
      'override_title_text' => 'Related article',
      'override_title_heading' => 'h2',
      'ds_view_mode_settings' => 'vertical_teaser',
      'ds_rows' => array(
        0 => 'full',
        1 => 'full',
        2 => 'full',
      ),
      'alternating' => 0,
      'varbase_magic' => array(
        'style_options' => array(
          'columns' => '1',
        ),
      ),
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = '5c147f8b-8d6c-43e9-90ba-b96ba3a1bf16';
    $display->content['new-5c147f8b-8d6c-43e9-90ba-b96ba3a1bf16'] = $pane;
    $display->panels['right'][0] = 'new-5c147f8b-8d6c-43e9-90ba-b96ba3a1bf16';
    $pane = new stdClass();
    $pane->pid = 'new-0f267847-97f9-43e9-bc9d-629abd9d5b66';
    $pane->panel = 'right';
    $pane->type = 'views_panes';
    $pane->subtype = 'article_listing-article_listing';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'use_pager' => 0,
      'pager_id' => '1',
      'items_per_page' => '3',
      'exposed' => array(
        'field_up_category_tid' => array(),
        'field_up_dossier_tid' => array(),
      ),
      'context' => array(
        1 => 'relationship_entity_from_field:field_up_category-node-taxonomy_term_1',
      ),
      'override_title' => 1,
      'override_title_text' => 'More Stories',
      'override_title_heading' => 'h2',
      'ds_view_mode_settings' => 'vertical_teaser',
      'ds_rows' => array(
        0 => 'full',
        1 => 'full',
        2 => 'full',
      ),
      'alternating' => 0,
      'varbase_magic' => array(
        'style_options' => array(
          'columns' => '1',
        ),
      ),
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 1;
    $pane->locks = array();
    $pane->uuid = '0f267847-97f9-43e9-bc9d-629abd9d5b66';
    $display->content['new-0f267847-97f9-43e9-bc9d-629abd9d5b66'] = $pane;
    $display->panels['right'][1] = 'new-0f267847-97f9-43e9-bc9d-629abd9d5b66';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $panelizer->display = $display;
  $export['node:uber_publisher_article:default'] = $panelizer;

  $panelizer = new stdClass();
  $panelizer->disabled = FALSE; /* Edit this to true to make a default panelizer disabled initially */
  $panelizer->api_version = 1;
  $panelizer->name = 'node:uber_publisher_author:default';
  $panelizer->title = 'Default';
  $panelizer->panelizer_type = 'node';
  $panelizer->panelizer_key = 'uber_publisher_author';
  $panelizer->no_blocks = FALSE;
  $panelizer->css_id = '';
  $panelizer->css = '';
  $panelizer->pipeline = 'ipe';
  $panelizer->contexts = array();
  $panelizer->relationships = array();
  $panelizer->access = array();
  $panelizer->view_mode = 'page_manager';
  $panelizer->css_class = '';
  $panelizer->title_element = 'H2';
  $panelizer->link_to_entity = TRUE;
  $panelizer->extra = array();
  $display = new panels_display();
  $display->layout = 'right_sidebar';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'center' => NULL,
      'top' => NULL,
      'right' => NULL,
      'bottom' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = '%node:title';
  $display->uuid = '7479bc68-6012-47a3-b8e3-077427477abf';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-d9428627-585a-4d4e-babb-580030d1c985';
    $pane->panel = 'center';
    $pane->type = 'node_content';
    $pane->subtype = 'node_content';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'links' => 0,
      'no_extras' => 1,
      'override_title' => 1,
      'override_title_text' => '',
      'identifier' => '',
      'link' => 0,
      'leave_node_title' => 0,
      'build_mode' => 'full',
      'context' => 'panelizer',
      'override_title_heading' => 'h2',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = 'd9428627-585a-4d4e-babb-580030d1c985';
    $display->content['new-d9428627-585a-4d4e-babb-580030d1c985'] = $pane;
    $display->panels['center'][0] = 'new-d9428627-585a-4d4e-babb-580030d1c985';
    $pane = new stdClass();
    $pane->pid = 'new-c84a7a54-83e4-4840-8a86-1ecf73c8ceb7';
    $pane->panel = 'center';
    $pane->type = 'views_panes';
    $pane->subtype = 'uber_publisher_author_profile-articles_by';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'use_pager' => 1,
      'pager_id' => '0',
      'items_per_page' => '6',
      'exposed' => array(
        'field_author_target_id' => '',
      ),
      'context' => array(
        0 => '',
        2 => '',
      ),
      'override_title' => 1,
      'override_title_text' => 'Articles by this author',
      'override_title_heading' => 'h2',
      'ds_view_mode_settings' => 'vertical_teaser',
      'ds_rows' => array(
        0 => 'full',
        1 => 'full',
        2 => 'full',
        3 => 'full',
        4 => 'full',
        5 => 'full',
      ),
      'alternating' => 0,
      'varbase_magic' => array(
        'style_options' => array(
          'columns' => '3',
        ),
      ),
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 1;
    $pane->locks = array();
    $pane->uuid = 'c84a7a54-83e4-4840-8a86-1ecf73c8ceb7';
    $display->content['new-c84a7a54-83e4-4840-8a86-1ecf73c8ceb7'] = $pane;
    $display->panels['center'][1] = 'new-c84a7a54-83e4-4840-8a86-1ecf73c8ceb7';
    $pane = new stdClass();
    $pane->pid = 'new-f1f669bf-01b8-4d7b-943c-a66cf85beb98';
    $pane->panel = 'right';
    $pane->type = 'views_panes';
    $pane->subtype = 'uber_publisher_author_profile-author_listing';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'use_pager' => 0,
      'pager_id' => '0',
      'items_per_page' => '5',
      'override_title' => 1,
      'override_title_text' => 'OUR AUTHORS',
      'override_title_heading' => 'h2',
      'ds_view_mode_settings' => 'mini_teaser',
      'ds_rows' => array(
        0 => 'full',
        1 => 'full',
        2 => 'full',
        3 => 'full',
        4 => 'full',
      ),
      'alternating' => 0,
      'varbase_magic' => array(
        'style_options' => array(
          'columns' => '1',
        ),
      ),
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = 'f1f669bf-01b8-4d7b-943c-a66cf85beb98';
    $display->content['new-f1f669bf-01b8-4d7b-943c-a66cf85beb98'] = $pane;
    $display->panels['right'][0] = 'new-f1f669bf-01b8-4d7b-943c-a66cf85beb98';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $panelizer->display = $display;
  $export['node:uber_publisher_author:default'] = $panelizer;

  $panelizer = new stdClass();
  $panelizer->disabled = FALSE; /* Edit this to true to make a default panelizer disabled initially */
  $panelizer->api_version = 1;
  $panelizer->name = 'taxonomy_term:up_category:default';
  $panelizer->title = 'Default';
  $panelizer->panelizer_type = 'taxonomy_term';
  $panelizer->panelizer_key = 'up_category';
  $panelizer->no_blocks = FALSE;
  $panelizer->css_id = '';
  $panelizer->css = '';
  $panelizer->pipeline = 'ipe';
  $panelizer->contexts = array();
  $panelizer->relationships = array();
  $panelizer->access = array();
  $panelizer->view_mode = 'page_manager';
  $panelizer->css_class = '';
  $panelizer->title_element = 'H2';
  $panelizer->link_to_entity = TRUE;
  $panelizer->extra = array();
  $display = new panels_display();
  $display->layout = 'right_sidebar';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'center' => NULL,
      'top' => NULL,
      'right' => NULL,
      'bottom' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = '';
  $display->uuid = 'a48fed93-8675-4de9-b3de-cb76c7daaeb9';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-a5ee6b37-def7-4ecd-911f-f08fa91ab451';
    $pane->panel = 'center';
    $pane->type = 'views_panes';
    $pane->subtype = 'content_general-promo_big_article';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'arguments' => array(
        'nid' => '',
      ),
      'fields_override' => array(
        'field_promo' => 1,
        'title' => 1,
        'created' => 1,
        'body' => 1,
      ),
      'override_title' => 0,
      'override_title_text' => '',
      'override_title_heading' => 'h2',
      'exposed' => array(
        'title' => '',
      ),
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = 'a5ee6b37-def7-4ecd-911f-f08fa91ab451';
    $display->content['new-a5ee6b37-def7-4ecd-911f-f08fa91ab451'] = $pane;
    $display->panels['center'][0] = 'new-a5ee6b37-def7-4ecd-911f-f08fa91ab451';
    $pane = new stdClass();
    $pane->pid = 'new-a7b831ec-2bad-422f-99ce-c4a04f90b605';
    $pane->panel = 'center';
    $pane->type = 'views_panes';
    $pane->subtype = 'content_general-content_list_advance';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'use_pager' => 1,
      'pager_id' => '0',
      'items_per_page' => '5',
      'fields_override' => array(
        'title' => 1,
        'created' => 0,
      ),
      'exposed' => array(
        'type' => array(
          'uber_publisher_article' => 'uber_publisher_article',
        ),
      ),
      'override_title' => 1,
      'override_title_text' => 'More Article',
      'override_title_heading' => 'h2',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 1;
    $pane->locks = array();
    $pane->uuid = 'a7b831ec-2bad-422f-99ce-c4a04f90b605';
    $display->content['new-a7b831ec-2bad-422f-99ce-c4a04f90b605'] = $pane;
    $display->panels['center'][1] = 'new-a7b831ec-2bad-422f-99ce-c4a04f90b605';
    $pane = new stdClass();
    $pane->pid = 'new-b851b5a4-5182-470f-b5fc-d49e8501400b';
    $pane->panel = 'right';
    $pane->type = 'views_panes';
    $pane->subtype = 'article_listing-article_listing';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'use_pager' => 1,
      'pager_id' => '1',
      'items_per_page' => '5',
      'exposed' => array(
        'field_up_category_tid' => array(),
        'field_up_dossier_tid' => array(),
      ),
      'context' => array(
        1 => 'panelizer',
      ),
      'override_title' => 1,
      'override_title_text' => 'Top Stories',
      'override_title_heading' => 'h2',
      'ds_view_mode_settings' => 'mini_teaser',
      'ds_rows' => array(
        0 => 'full',
        1 => 'full',
        2 => 'full',
      ),
      'alternating' => 0,
      'varbase_magic' => array(
        'style_options' => array(
          'columns' => '1',
        ),
      ),
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = 'b851b5a4-5182-470f-b5fc-d49e8501400b';
    $display->content['new-b851b5a4-5182-470f-b5fc-d49e8501400b'] = $pane;
    $display->panels['right'][0] = 'new-b851b5a4-5182-470f-b5fc-d49e8501400b';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $panelizer->display = $display;
  $export['taxonomy_term:up_category:default'] = $panelizer;

  return $export;
}

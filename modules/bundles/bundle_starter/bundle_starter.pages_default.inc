<?php
/**
 * @file
 * bundle_starter.pages_default.inc
 */

/**
 * Implements hook_default_page_manager_pages().
 */
function bundle_starter_default_page_manager_pages() {
  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'frontpage';
  $page->task = 'page';
  $page->admin_title = 'Frontpage';
  $page->admin_description = '';
  $page->path = 'front';
  $page->access = array();
  $page->menu = array();
  $page->arguments = array();
  $page->conf = array(
    'admin_paths' => FALSE,
  );
  $page->default_handlers = array();
  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'page_frontpage__panel_context_d1eb0881-4660-4c72-bfd6-80e65ddb20ea';
  $handler->task = 'page';
  $handler->subtask = 'frontpage';
  $handler->handler = 'panel_context';
  $handler->weight = 0;
  $handler->conf = array(
    'title' => 'Default',
    'no_blocks' => 1,
    'pipeline' => 'ipe',
    'body_classes_to_remove' => '',
    'body_classes_to_add' => '',
    'css_id' => '',
    'css' => '',
    'contexts' => array(),
    'relationships' => array(),
  );
  $display = new panels_display();
  $display->layout = 'jose_flipped';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'top' => NULL,
      'first_step_left' => NULL,
      'first_step_right' => NULL,
      'second_step_left' => NULL,
      'second_step_right' => NULL,
      'third_step_left' => NULL,
      'third_step_right' => NULL,
      'fourth_step_left' => NULL,
      'fourth_step_right' => NULL,
      'fifth_step_left' => NULL,
      'fifth_step_right' => NULL,
      'bottom' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = '';
  $display->uuid = '5a141eb5-0830-4e88-8368-08212322475b';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-f4e125e9-f061-4a8e-9624-7cd06c700069';
    $pane->panel = 'left';
    $pane->type = 'views_panes';
    $pane->subtype = 'content_general-content_list_advance';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'use_pager' => 0,
      'pager_id' => '0',
      'items_per_page' => '5',
      'fields_override' => array(
        'title' => 1,
        'created' => 1,
      ),
      'exposed' => array(
        'type' => array(
          'uber_publisher_article' => 'uber_publisher_article',
        ),
      ),
      'override_title' => 1,
      'override_title_text' => 'Top Stories',
      'override_title_heading' => 'h2',
    );
    $pane->cache = array();
    $pane->style = array();
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = 'f4e125e9-f061-4a8e-9624-7cd06c700069';
    $display->content['new-f4e125e9-f061-4a8e-9624-7cd06c700069'] = $pane;
    $display->panels['left'][0] = 'new-f4e125e9-f061-4a8e-9624-7cd06c700069';
    $pane = new stdClass();
    $pane->pid = 'new-61187136-82ba-42fe-98eb-91d3d00b8ad0';
    $pane->panel = 'top';
    $pane->type = 'uber_publisher_featured_article';
    $pane->subtype = 'uber_publisher_featured_article';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'views_display' => 'highlighted_slides',
      'override_title' => 0,
      'override_title_text' => '',
      'override_title_heading' => 'h2',
    );
    $pane->cache = array();
    $pane->style = array();
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = '61187136-82ba-42fe-98eb-91d3d00b8ad0';
    $display->content['new-61187136-82ba-42fe-98eb-91d3d00b8ad0'] = $pane;
    $display->panels['top'][0] = 'new-61187136-82ba-42fe-98eb-91d3d00b8ad0';
  $display->hide_title = PANELS_TITLE_NONE;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['frontpage'] = $page;

  return $pages;

}

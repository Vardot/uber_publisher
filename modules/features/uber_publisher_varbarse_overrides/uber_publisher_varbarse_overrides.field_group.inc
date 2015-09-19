<?php
/**
 * @file
 * uber_publisher_varbarse_overrides.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function uber_publisher_varbarse_overrides_field_group_info() {
  $export = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_basic_options|node|page|form';
  $field_group->group_name = 'group_basic_options';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'page';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_main_group';
  $field_group->data = array(
    'label' => 'Basic Options',
    'weight' => '10',
    'children' => array(
      0 => 'body',
    ),
    'format_type' => 'htab',
    'format_settings' => array(
      'label' => 'Basic Options',
      'instance_settings' => array(
        'required_fields' => 1,
        'id' => '',
        'classes' => '',
        'description' => '',
      ),
      'formatter' => 'closed',
    ),
  );
  $export['group_basic_options|node|page|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_main_group|node|landing_page|form';
  $field_group->group_name = 'group_main_group';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'landing_page';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_wrapper';
  $field_group->data = array(
    'label' => 'Main Group',
    'weight' => '5',
    'children' => array(
      0 => 'group_seo',
    ),
    'format_type' => 'htabs',
    'format_settings' => array(
      'formatter' => '',
      'instance_settings' => array(
        'classes' => 'group-main-group field-group-htabs',
      ),
    ),
  );
  $export['group_main_group|node|landing_page|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_main_group|node|page|form';
  $field_group->group_name = 'group_main_group';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'page';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_wrapper';
  $field_group->data = array(
    'label' => 'Main Group',
    'weight' => '3',
    'children' => array(
      0 => 'group_seo',
      1 => 'group_basic_options',
    ),
    'format_type' => 'htabs',
    'format_settings' => array(
      'label' => 'Main Group',
      'instance_settings' => array(
        'classes' => '',
      ),
    ),
  );
  $export['group_main_group|node|page|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_publish_options|node|landing_page|form';
  $field_group->group_name = 'group_publish_options';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'landing_page';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_sidebar';
  $field_group->data = array(
    'label' => 'Publish',
    'weight' => '7',
    'children' => array(),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'Publish',
      'instance_settings' => array(
        'required_fields' => 1,
        'id' => '',
        'classes' => 'property_box',
        'description' => '',
        'show_label' => '0',
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'none',
      ),
      'formatter' => 'open',
    ),
  );
  $export['group_publish_options|node|landing_page|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_publish_options|node|page|form';
  $field_group->group_name = 'group_publish_options';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'page';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_sidebar';
  $field_group->data = array(
    'label' => 'Publish',
    'weight' => '5',
    'children' => array(),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'Publish',
      'instance_settings' => array(
        'required_fields' => 1,
        'id' => '',
        'classes' => 'property_box',
        'description' => '',
        'show_label' => '0',
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'none',
      ),
      'formatter' => 'open',
    ),
  );
  $export['group_publish_options|node|page|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_seo|node|landing_page|form';
  $field_group->group_name = 'group_seo';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'landing_page';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_main_group';
  $field_group->data = array(
    'label' => 'SEO',
    'weight' => '9',
    'children' => array(),
    'format_type' => 'htab',
    'format_settings' => array(
      'label' => 'SEO',
      'instance_settings' => array(
        'required_fields' => 1,
        'id' => '',
        'classes' => 'group-seo field-group-htab',
        'description' => '',
      ),
      'formatter' => 'closed',
    ),
  );
  $export['group_seo|node|landing_page|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_seo|node|page|form';
  $field_group->group_name = 'group_seo';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'page';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_main_group';
  $field_group->data = array(
    'label' => 'SEO',
    'weight' => '12',
    'children' => array(),
    'format_type' => 'htab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-seo field-group-htab',
        'required_fields' => 1,
        'id' => '',
      ),
    ),
  );
  $export['group_seo|node|page|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_sidebar|node|landing_page|form';
  $field_group->group_name = 'group_sidebar';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'landing_page';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Sidebar',
    'weight' => '1',
    'children' => array(
      0 => 'group_publish_options',
    ),
    'format_type' => 'html5',
    'format_settings' => array(
      'label' => 'Sidebar',
      'instance_settings' => array(
        'id' => 'node_article_form_group_sidebar',
        'classes' => 'group-sidebar field-group-html5 fixed-pane-left',
        'wrapper' => 'section',
      ),
      'formatter' => '',
    ),
  );
  $export['group_sidebar|node|landing_page|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_sidebar|node|page|form';
  $field_group->group_name = 'group_sidebar';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'page';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Sidebar',
    'weight' => '1',
    'children' => array(
      0 => 'group_publish_options',
    ),
    'format_type' => 'html5',
    'format_settings' => array(
      'label' => 'Sidebar',
      'instance_settings' => array(
        'id' => 'node_article_form_group_sidebar',
        'classes' => 'group-sidebar field-group-html5 fixed-pane-left',
        'wrapper' => 'section',
      ),
    ),
  );
  $export['group_sidebar|node|page|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_wrapper|node|landing_page|form';
  $field_group->group_name = 'group_wrapper';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'landing_page';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Group Wrapper',
    'weight' => '0',
    'children' => array(
      0 => 'title',
      1 => 'group_main_group',
    ),
    'format_type' => 'html5',
    'format_settings' => array(
      'label' => 'Group Wrapper',
      'instance_settings' => array(
        'id' => 'node_article_form_group_wrapper',
        'classes' => 'group-wrapper field-group-html5 group-wrapper clearfix',
        'wrapper' => 'section',
      ),
    ),
  );
  $export['group_wrapper|node|landing_page|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_wrapper|node|page|form';
  $field_group->group_name = 'group_wrapper';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'page';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Group Wrapper',
    'weight' => '0',
    'children' => array(
      0 => 'title',
      1 => 'group_main_group',
    ),
    'format_type' => 'html5',
    'format_settings' => array(
      'label' => 'Group Wrapper',
      'instance_settings' => array(
        'id' => 'node_article_form_group_wrapper',
        'classes' => 'group-wrapper field-group-html5 group-wrapper clearfix',
        'wrapper' => 'section',
      ),
    ),
  );
  $export['group_wrapper|node|page|form'] = $field_group;

  return $export;
}

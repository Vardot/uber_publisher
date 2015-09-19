<?php
/**
 * @file
 * uber_publisher_author_profile.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function uber_publisher_author_profile_field_group_info() {
  $export = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_basic_options|node|uber_publisher_author|form';
  $field_group->group_name = 'group_basic_options';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'uber_publisher_author';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_main_group';
  $field_group->data = array(
    'label' => 'Basic Options',
    'weight' => '3',
    'children' => array(
      0 => 'body',
    ),
    'format_type' => 'htab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-basic-options field-group-htab',
        'required_fields' => 1,
        'id' => '',
      ),
    ),
  );
  $export['group_basic_options|node|uber_publisher_author|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_main_group|node|uber_publisher_author|form';
  $field_group->group_name = 'group_main_group';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'uber_publisher_author';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_wrapper';
  $field_group->data = array(
    'label' => 'Main Group',
    'weight' => '3',
    'children' => array(
      0 => 'group_basic_options',
      1 => 'group_seo',
    ),
    'format_type' => 'htabs',
    'format_settings' => array(
      'formatter' => '',
      'instance_settings' => array(
        'classes' => 'group-main-group field-group-htabs',
      ),
    ),
  );
  $export['group_main_group|node|uber_publisher_author|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_publish_options|node|uber_publisher_author|form';
  $field_group->group_name = 'group_publish_options';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'uber_publisher_author';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_sidebar';
  $field_group->data = array(
    'label' => 'Publish',
    'weight' => '8',
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
  $export['group_publish_options|node|uber_publisher_author|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_seo|node|uber_publisher_author|form';
  $field_group->group_name = 'group_seo';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'uber_publisher_author';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_main_group';
  $field_group->data = array(
    'label' => 'SEO',
    'weight' => '5',
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
  $export['group_seo|node|uber_publisher_author|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_sidebar|node|uber_publisher_author|form';
  $field_group->group_name = 'group_sidebar';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'uber_publisher_author';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_wrapper';
  $field_group->data = array(
    'label' => 'Sidebar',
    'weight' => '4',
    'children' => array(
      0 => 'group_publish_options',
      1 => 'group_thumbnail',
    ),
    'format_type' => 'html5',
    'format_settings' => array(
      'label' => 'Sidebar',
      'instance_settings' => array(
        'id' => 'node_article_form_group_sidebar',
        'classes' => 'group-sidebar field-group-html5 fixed-pane-left',
        'wrapper' => 'aside',
      ),
    ),
  );
  $export['group_sidebar|node|uber_publisher_author|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_thumbnail|node|uber_publisher_author|form';
  $field_group->group_name = 'group_thumbnail';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'uber_publisher_author';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_sidebar';
  $field_group->data = array(
    'label' => 'Profile Picture',
    'weight' => '9',
    'children' => array(
      0 => 'field_up_thumbnail',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'Profile Picture',
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
  $export['group_thumbnail|node|uber_publisher_author|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_wrapper|node|uber_publisher_author|form';
  $field_group->group_name = 'group_wrapper';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'uber_publisher_author';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Group Wrapper',
    'weight' => '0',
    'children' => array(
      0 => 'field_real_user',
      1 => 'title',
      2 => 'group_main_group',
      3 => 'group_sidebar',
    ),
    'format_type' => 'html5',
    'format_settings' => array(
      'label' => 'Group Wrapper',
      'instance_settings' => array(
        'id' => 'node_author_form_group_wrapper',
        'classes' => 'group-wrapper field-group-html5 group-wrapper clearfix',
        'wrapper' => 'section',
      ),
    ),
  );
  $export['group_wrapper|node|uber_publisher_author|form'] = $field_group;

  return $export;
}

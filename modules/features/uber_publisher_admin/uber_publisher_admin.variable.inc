<?php
/**
 * @file
 * Variables module integration.
 */

/**
 * Implements hook_variable_group_info().
 */
function uber_publisher_admin_variable_group_info() {
  $groups['uber_publisher_admin'] = array(
    'title' => t('Uber Publisher admin'),
    'description' => t('Uber Publisher admin variables.'),
    'access' => 'administer uber_publisher settings',
    'path' => array('admin/uber_publisher', 'admin/uber_publisher/social'),
  );

  return $groups;
}

/**
 * Implements hook_variable_type_info()
 */
function uber_publisher_admin_variable_type_info() {
  // Array whose keys are named properties.
  $type['follow_platforms'] = array(
    'title' => t('Platform Value'),
    'type' => 'properties',
    'element callback' => 'uber_publisher_admin_variable_form_element_follow_platforms',
  );

  return $type;
}

/**
 * Implements hook_variable_info().
 */
function uber_publisher_admin_variable_info($options) {
  $variables['follow_platforms'] = array(
    'type' => 'follow_platforms',
    'title' => t('Platforms'),
    'localize' => TRUE,
    'group' => 'uber_publisher_admin',
  );

  return $variables;
}

/**
 * Build array (table) form element
 *
 * see variable_form_element_array() for more information.
 */
function uber_publisher_admin_variable_form_element_follow_platforms($variable, $options = array()) {
  // This will be possibly a fieldset with tree value
  $element = variable_form_element_default($variable, $options);
  $element['#collapsible'] = TRUE;
  $element['#collapsed'] = FALSE;
  $element['#theme'] = 'uber_publisher_follow_platforms_table';

  // Get all supported platforms.
  $platforms = uber_publisher_follow_platforms();

  // We may have a multiple element base that will default to plain textfield
  $item = $variable['repeat'];
  $value = variable_get_value($variable, $options);
  // Compile names and defaults for all elements
  $names = $defaults = array();
  if (!empty($variable['multiple'])) {
    // If we've got a multiple value, it will be an array with known elements
    $names = $variable['multiple'];
  }
  else {
    // Array with unknown elements, we add an element for each existing one
    $names = $value ? array_combine(array_keys($value), array_keys($value)) : array();
  }
  // Now build elements with the right names
  foreach ($names as $key => $title) {
    if (isset($value[$key]) && is_array($value[$key])) {
      $element[$key]['platform_value'] = array(
        '#title' => $platforms[$key]['title'],
        '#field_prefix' => $platforms[$key]['base url'],
        '#type' => 'textfield',
        '#title_display' => 'invisible',
        '#size' => 40,
        '#default_value' => $value[$key]['platform_value'],
      );
      $element[$key]['weight'] = array(
        '#type' => 'weight',
        '#title' => t('Weight'),
        '#title_display' => 'invisible',
        '#title' => t('Platform'),
        '#default_value' => $value[$key]['weight'],
        '#attributes' => array('class' => array('weight')),
      );
    }
  }
  uasort($element, 'drupal_sort_weight');

  return $element;
}

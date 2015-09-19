<?php

/**
 * Implements template_preprocess_HOOK() for theme_menu_tree__menu_block__uber_publisher_main_menu_default().
 */
function template_preprocess_menu_tree__menu_block__uber_publisher_main_menu_default(&$variables) {
  $variables['tree'] = $variables['tree']['#children'];
}

/**
 * Implements template_preprocess_HOOK() for theme_menu_link__menu_block__uber_publisher_main_menu_default().
 */
function template_preprocess_menu_link__menu_block__uber_publisher_main_menu_default(&$variables) {
  $element = &$variables['element'];

  $uber_publisher_appearance = variable_get("uber_publisher_appearance", array());
  if (isset($uber_publisher_appearance['main_menu_type']) && $uber_publisher_appearance['main_menu_type'] == 'mega_menu') {

  } else {
    unset($element['#localized_options']['minipanel']);
    unset($element['#localized_options']['menu_minipanels_hover']);
  }
}

/**
 * Returns HTML for common Drupal time fields.
 *
 * @param $variables
 *   An associative array containing:
 *     - datetime: the diplayed time formated .
 *     - isodate: the date in ISO 8601 formate
 *
 * @ingroup themeable
 */
function theme_menu_tree__menu_block__uber_publisher_main_menu_default(array $variables) {
  return '<ul class="menu">' . $variables['tree'] . '</ul>';
}

/**
 * Returns HTML for common Drupal time fields.
 *
 * @param $variables
 *   An associative array containing:
 *     - datetime: the diplayed time formated .
 *     - isodate: the date in ISO 8601 formate
 *
 * @ingroup themeable
 */
function theme_menu_link__menu_block__uber_publisher_main_menu_default(array $variables) {
  $element = $variables['element'];
  $sub_menu = '';
  $depth = $element['#original_link']['depth'];

  if ($element['#below']) {
    unset($element['#below']['#theme_wrappers']);
    $element['#attributes']['class'][] = 'dropdown';
    $sub_menu = ' <span class="caret"></span>';
    $sub_menu .= '<ul class="sub-level-menu sub-menu-'. $depth.'">' . drupal_render($element['#below']) . '</ul>';
  }
  
  $element['#attributes']['class'][] = 'item-level-'. $depth;
  $output = l($element['#title'], $element['#href'], $element['#localized_options']);
  return '<li' . drupal_attributes($element['#attributes']) . '>' . $output . $sub_menu . "</li>\n";
}

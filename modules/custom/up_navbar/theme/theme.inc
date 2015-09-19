<?php

function template_preprocess_up_navbar_header(&$variables) {

}

function template_preprocess_up_navbar_face_box(&$variables) {

}

function template_preprocess_up_navbar_sidebar(&$variables) {

}

function template_preprocess_up_navbar_link(&$variables) {
  $element = &$variables['element'];
  $element['#title'] = '<i class="up-icon"></i><span class="text">' . $element['#title'] . '</span>';
  $element['#localized_options']['html'] = TRUE;
}

function theme_up_navbar_link(array $variables) {
  $element = $variables['element'];
  $sub_menu = '';

  if (isset($element['#below']) && $element['#below']) {
    $sub_menu = drupal_render($element['#below']);
  }
  $output = l($element['#title'], $element['#href'], $element['#localized_options']);
  return '<li' . drupal_attributes($element['#attributes']) . '>' . $output . $sub_menu . "</li>\n";
}

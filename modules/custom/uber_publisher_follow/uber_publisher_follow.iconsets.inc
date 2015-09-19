<?php

/**
 * @file
 * Callbacks for the icon sets.
 */

/**
 * Register the default icon sets.
 *
 * @return array
 *   Array of icon sets.
 */
function uber_publisher_follow_uber_publisher_follow_iconset_info() {

  $icons['font_awesome'] = array(
    'name' => 'Font Awesome',
    'type' => 'font',
    'class name' => 'fa',
    'styles' => array(
      'nl' => 'normal',
      'lg' => 'large',
      '2x' => '2x size',
      '3x' => '3x size',
      '4x' => '4x size',
      '5x' => '5x size',
    ),
  );

  return $icons;
}

function uber_publisher_follow_font_awesome_icon(&$variables) {
  switch ($variables['name']) {
    case 'vimeo':
      $variables['name'] = 'vimeo-square';
      break;
    case 'youtube-channel':
      $variables['name'] = 'youtube-play';
      break;
    case 'contact':
      $variables['name'] = 'phone';
      break;
    case 'email':
      $variables['name'] = 'envelope';
      break;
  }
}

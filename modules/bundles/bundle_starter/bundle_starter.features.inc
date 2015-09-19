<?php
/**
 * @file
 * bundle_starter.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function bundle_starter_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "ds" && $api == "ds") {
    return array("version" => "1");
  }
  if ($module == "page_manager" && $api == "pages_default") {
    return array("version" => "1");
  }
  if ($module == "panelizer" && $api == "panelizer") {
    return array("version" => "1");
  }
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_image_default_styles().
 */
function bundle_starter_image_default_styles() {
  $styles = array();

  // Exported image style: article_horizontal_teaser.
  $styles['article_horizontal_teaser'] = array(
    'label' => 'Article horizontal teaser',
    'effects' => array(
      5 => array(
        'name' => 'epsacrop_crop',
        'data' => array(
          'width' => 265,
          'height' => 200,
          'anchor' => 'center-center',
          'jcrop_settings' => array(
            'aspect_ratio' => '',
            'bgcolor' => 'black',
            'bgopacity' => 0.6,
            'fallback' => 1,
          ),
        ),
        'weight' => 1,
      ),
      6 => array(
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 265,
          'height' => 200,
        ),
        'weight' => 2,
      ),
    ),
  );

  // Exported image style: article_mini_teaser.
  $styles['article_mini_teaser'] = array(
    'label' => 'Article mini teaser',
    'effects' => array(
      3 => array(
        'name' => 'epsacrop_crop',
        'data' => array(
          'width' => 75,
          'height' => 75,
          'anchor' => 'center-center',
          'jcrop_settings' => array(
            'aspect_ratio' => '',
            'bgcolor' => 'black',
            'bgopacity' => 0.6,
            'fallback' => 1,
          ),
        ),
        'weight' => 1,
      ),
      4 => array(
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 75,
          'height' => 75,
        ),
        'weight' => 2,
      ),
    ),
  );

  // Exported image style: article_vertical_teaser.
  $styles['article_vertical_teaser'] = array(
    'label' => 'Article vertical teaser',
    'effects' => array(
      1 => array(
        'name' => 'epsacrop_crop',
        'data' => array(
          'width' => 265,
          'height' => 150,
          'anchor' => 'center-center',
          'jcrop_settings' => array(
            'aspect_ratio' => '',
            'bgcolor' => 'black',
            'bgopacity' => 0.6,
            'fallback' => 1,
          ),
        ),
        'weight' => 1,
      ),
      2 => array(
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 265,
          'height' => 150,
        ),
        'weight' => 2,
      ),
    ),
  );

  return $styles;
}

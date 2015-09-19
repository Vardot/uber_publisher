<?php

/**
 * Implements hook_panels_layouts().
 */
// Plugin definition
$plugin = array(
  'title' => t('Jose flipped'),
  'category' => t('Special layouts'),
  'icon' => 'jose_flipped.png',
  'theme' => 'jose_flipped',
  'admin css' => '../varbase-landing-layouts-admin.css',
  'regions' => array(
    'top' => t('Top'),
    'right' => t('Right Sidebar'),
    'center_top' => t('Content top'),
    'center_left' => t('Content left'),
    'center_right' => t('Content right'),
    'center_bottom' => t('Content bottom'),
    'bottom' => t('Bottom'),
  ),
);

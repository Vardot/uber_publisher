<?php
/**
 * @file
 * page.vars.php
 */

/**
 * Implements hook_preprocess_page().
 *
 * @see page.tpl.php
 */
function uber_theme_preprocess_page(&$variables) {
  // Get Uber Publisher Appearance settings.
  $uber_publisher_appearance = variable_get("uber_publisher_appearance", array());

  if (isset($uber_publisher_appearance['logo_path'])) {
    $variables['logo'] = file_create_url($uber_publisher_appearance['logo_path']);
  }

  $main_menu_block = block_load('uber_publisher_main_menu_default', 'uber_publisher_main_menu_default');
  $variables['main_menu_block'] = _block_get_renderable_array(_block_render_blocks(array($main_menu_block)));

  $secondry_menu_block = block_load('menu_block', 'secondary-menu-block');
  $variables['secondry_menu_block'] = _block_get_renderable_array(_block_render_blocks(array($secondry_menu_block)));
}

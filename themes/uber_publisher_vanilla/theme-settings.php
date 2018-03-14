<?php

/**
 * @file
 * theme-settings.php
 *
 * Provides theme settings for uber publisher theme.
 */

use Drupal\Core\Form\FormStateInterface;

/**
 * Implements hook_form_system_theme_settings_alter().
 */
function uber_publisher_vanilla_form_system_theme_settings_alter(&$form, FormStateInterface $form_state, $form_id = NULL) {

  $form['#attached']['library'][] = 'uber_publisher_vanilla/uber-publisher-vanilla-admin';

  // Custom settings in Vertical Tabs container.
  $form['uber_publisher_vanilla'] = array(
    '#type' => 'vertical_tabs',
    '#prefix' => '<h2><small>' . t('Uber Publisher Vanilla Theme Settings') . '</small></h2>',
    '#weight' => -19,
  );

  /* --------- Setting general ----------------*/
  $form['uber_publisher_vanilla_general'] = array(
    '#type' => 'details',
    '#title' => t('Gerenal options'),
    '#group' => 'uber_publisher_vanilla',
  );

  // Sticky menu settings.
  $form['uber_publisher_vanilla_general']['sticky_menu'] = array(
    '#type' => 'checkbox',
    '#title' => t('Enable Sticky Menu'),
    '#default_value' => theme_get_setting('sticky_menu'),
  );
}

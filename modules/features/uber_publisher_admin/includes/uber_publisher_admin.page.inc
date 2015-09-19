<?php

/**
 * @file
 * Code for the Uber Publisher Admin menu callback.
 */

/**
 * Form builder; Configure the site General settings.
 *
 * @ingroup forms
 */
function uber_publisher_general($form, &$form_state) {
  include_once DRUPAL_ROOT . '/includes/locale.inc';

  $form['site_information'] = array(
    '#type' => 'fieldset',
    '#title' => t('Site details'),
  );
  $form['site_information']['site_name'] = array(
    '#type' => 'textfield',
    '#title' => t('Site name'),
    '#default_value' => variable_get('site_name', 'Drupal'),
    '#required' => TRUE
  );
  $form['site_information']['site_slogan'] = array(
    '#type' => 'textfield',
    '#title' => t('Slogan'),
    '#default_value' => variable_get('site_slogan', ''),
    '#description' => t("How this is used depends on your site's theme."),
  );

  $form['site_information']['site_default_country'] = array(
    '#type' => 'select',
    '#title' => t('Default country'),
    '#empty_value' => '',
    '#default_value' => variable_get('site_default_country', ''),
    '#options' => country_get_list(),
    '#attributes' => array('class' => array('country-detect')),
  );

  $form['site_information']['date_default_timezone'] = array(
    '#type' => 'select',
    '#title' => t('Default time zone'),
    '#default_value' => variable_get('date_default_timezone', date_default_timezone_get()),
    '#options' => system_time_zones(),
  );

  $form['site_information']['date_first_day'] = array(
    '#type' => 'select',
    '#title' => t('First day of week'),
    '#default_value' => variable_get('date_first_day', 0),
    '#options' => array(0 => t('Sunday'), 1 => t('Monday'), 2 => t('Tuesday'), 3 => t('Wednesday'), 4 => t('Thursday'), 5 => t('Friday'), 6 => t('Saturday')),
  );

  return system_settings_form($form);
}

/**
 * Form builder; Configure the site Appearance settings.
 *
 * @ingroup forms
 * see system_theme_settings().
 */
function uber_publisher_appearance($form, &$form_state) {
  $appearance_settings = array(
    'colorpicker_settings' => array('input' => array()),
  );
  $form['#uber_publisher_appearance'] = variable_get("uber_publisher_appearance", array());

  $form['appearance_general'] = array(
    '#type' => 'fieldset',
    '#title' => t('Appearance General'),
  );

  if (isset($form['#uber_publisher_appearance']['logo_path'])) {
    $form['appearance_general']['logo_uploaded'] = array(
      '#type' => 'markup',
      '#prefix' => '<div class="logo-uploaded">',
      '#suffix' => '</div>',
      '#title' => t('Upload logo image'),
      '#markup' => theme('image_style', array('style_name' => 'thumbnail', 'path' => $form['#uber_publisher_appearance']['logo_path'])),
      '#description' => t("If you don't have direct file access to the server, use this field to upload your logo.")
    );
  }
  $form['appearance_general']['logo_upload'] = array(
    '#type' => 'file',
    '#title' => t('Upload logo image'),
    '#description' => t("If you don't have direct file access to the server, use this field to upload your logo.")
  );

  if (($less_engines = libraries_detect('less.js')) && $less_engines['installed'] = TRUE) {
    $less_settings = array(
     '@brand-primary' => 'Brand primary',
     '@brand-secondary' => 'Brand secondary',
     '@accent-primary' => 'Accent primary',
     '@accent-secondary' => 'Accent secondary'
    );

    $colorpicker_input = array();
    $form['appearance_general']['less']['#tree'] = TRUE;
    $form['appearance_general']['less']['variable']['#tree'] = TRUE;
    foreach ($less_settings as  $variable => $variable_name) {
      $class_name = drupal_html_class('colorpicker-'.$variable);
      $form['appearance_general']['less']['variable'][$variable]['#type'] = 'textfield';
      $form['appearance_general']['less']['variable'][$variable]['#attributes']['class'] = array($class_name);
      $form['appearance_general']['less']['variable'][$variable]['#maxlength'] = '7';
      $form['appearance_general']['less']['variable'][$variable]['#size'] = '7';
      $form['appearance_general']['less']['variable'][$variable]['#title_display'] = 'before';
      $form['appearance_general']['less']['variable'][$variable]['#title'] = $variable_name;
      $colorpicker_input[] = $class_name;

      if (!empty($form['#uber_publisher_appearance']['less']['variable'][$variable])) {
        $form['appearance_general']['less']['variable'][$variable]['#default_value'] = $form['#uber_publisher_appearance']['less']['variable'][$variable];
      } else {
        // @todo nthis should get values of current theme.
        $form['appearance_general']['less']['variable'][$variable]['#default_value'] = '';
      }
    }

    $appearance_settings['colorpicker_settings']['input'] = $colorpicker_input;
    $colorpicker_path = libraries_get_path('colorpicker');
    $colorpicker = array(
      'css' => array(
        $colorpicker_path . '/css/colorpicker.css',
      ),
      'js' => array(
        $colorpicker_path . '/js/colorpicker.js',
        drupal_get_path('module', 'uber_publisher_admin') . '/js/appearance.js',
        array(
          'data' => array('uber_publisher_admin' => array('appearance' => $appearance_settings)),
          'type' => 'setting',
        ),
      ),
    );
    $form['appearance_general']['less']['variable']['#attached'] = $colorpicker;
  }

  $form = system_settings_form($form);
  // We don't want to call system_settings_form_submit(), so change #submit.
  array_pop($form['#submit']);
  $form['#submit'][] = 'uber_publisher_appearance_submit';
  return $form;
}

function uber_publisher_appearance_validate($form, &$form_state) {
  // Handle file uploads.
  $validators = array('file_validate_is_image' => array('png svg'));

  // If there is no upload leave.
  if ($file = file_save_upload('logo_upload', $validators)) {
    // Check for a new uploaded logo.
    if (isset($file) && $file) {
      // Put the temporary file in form_values so we can save it on submit.
      $form_state['values']['logo_upload'] = $file;
    }
    else {
      // File upload failed.
      form_set_error('logo_upload', t('The logo could not be uploaded.'));
    }
  }
  elseif ((!isset($form['#uber_publisher_appearance']['logo_path']) || empty($form['#uber_publisher_appearance']['logo_path'])) &&
          (!isset($form_state['values']['logo_upload']) || empty($form_state['values']['logo_upload']))) {
    form_set_error('logo_upload', t('You have to upload a logo.'));
  }
}

function uber_publisher_appearance_submit($form, &$form_state) {
  form_state_values_clean($form_state);
  $values = $form_state['values'];

  if (!empty($values['logo_upload'])) {
    $file = $values['logo_upload'];
    unset($values['logo_upload']);
    $filename = file_unmanaged_copy($file->uri);
    $values['logo_path'] = $filename;
  } else {
    $values['logo_path'] = $form['#uber_publisher_appearance']['logo_path'];
  }

  if (module_exists('less')) {
    less_flush_caches();
  }

  variable_set("uber_publisher_appearance", $values);
}

/**
 * Form builder; Configure the site Social settings.
 *
 * @ingroup forms
 * see system_theme_settings().
 */
function uber_publisher_social($form, &$form_state) {
  $form = array();

  $form['social_group'] = array(
    '#type' => 'vertical_tabs',
    '#weight' => 50,
  );

  // Platforms.
  $form['follow_platforms'] = array(
    '#type' => 'fieldset',
    '#title' => t('Platforms'),
    '#collapsible' => TRUE,
    '#collapsed' => FALSE,
    '#tree' => TRUE,
    '#theme' => 'uber_publisher_follow_platforms_table',
  );

  $platform_values = isset($values['follow_platforms']) ? $values['follow_platforms'] : variable_get('follow_platforms', array());
  $platforms = uber_publisher_follow_platforms();

  if (!empty($platform_values)) {
    // Combine the platforms with the weight value for sorting.
    foreach ($platforms as $key => $value) {
      if (isset($platform_values[$key]['weight'])) {
        $platforms[$key]['weight'] = $platform_values[$key]['weight'];
      }
    }

    uasort($platforms, 'drupal_sort_weight');
  }

  $i = -10;
  foreach ($platforms as $key => $value) {
    $form['follow_platforms'][$key] = array(
      'platform_value' => array(
        '#type' => 'textfield',
        '#title' => $value['title'],
        '#title_display' => 'invisible',
        '#size' => 40,
        '#field_prefix' => $value['base url'],
        '#default_value' => isset($platform_values[$key]['platform_value']) ? $platform_values[$key]['platform_value'] : '',
      ),
      'weight' => array(
        '#type' => 'weight',
        '#title' => t('Weight'),
        '#title_display' => 'invisible',
        '#delta' => 10,
        '#default_value' => isset($platform_values[$key]['weight']) ? $platform_values[$key]['weight'] : $i + 1,
        '#attributes' => array('class' => array('weight')),
      ),
    );
    $i++;
  }

  return system_settings_form($form);
}

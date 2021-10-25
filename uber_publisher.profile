<?php

/**
 * @file
 * Enables modules and site configuration for a Varbase sub profile basic
 * site installation.
 */

use Drupal\Core\Form\FormStateInterface;
use Drupal\varbase\Config\ConfigBit;
use Drupal\uber_publisher\Form\UberPublisherAssemblerForm;
use Drupal\uber_publisher\Helper\HelperFunctions;

/**
 * Implements hook_form_FORM_ID_alter() for install_configure_form().
 *
 * Allows the profile to alter the site configuration form.
 */
function uber_publisher_form_install_configure_form_alter(&$form, FormStateInterface $form_state) {
  include_once drupal_get_path('profile', 'varbase') . '/varbase.profile';
  varbase_form_install_configure_form_alter($form, $form_state);
}

/**
 * Implements hook_install_tasks().
 */
function uber_publisher_install_tasks(&$install_state) {
  include_once drupal_get_path('profile', 'varbase') . '/varbase.profile';
  $varbase_install_tasks = varbase_install_tasks($install_state);

  return [
    'uber_publisher_extra_components' => [
      'display_name' => t('Extra components'),
      'display' => TRUE,
      'type' => 'form',
      'function' => UberPublisherAssemblerForm::class,
    ],
    'uber_publisher_assemble_extra_components' => [
      'display_name' => t('Assemble extra components'),
      'display' => TRUE,
      'type' => 'batch',
    ],
    'varbase_development_tools' => $varbase_install_tasks['varbase_development_tools'],
    'varbase_assemble_development_tools' => $varbase_install_tasks['varbase_assemble_development_tools'],
  ];
}

/**
 * Implements hook_install_tasks_alter().
 */
function uber_publisher_install_tasks_alter(array &$tasks, array $install_state) {
  $tasks['install_finished']['function'] = 'uber_publisher_after_install_finished';
}


/**
 * Batch job to assemble Varbase extra components.
 *
 * @param array $install_state
 *   The current install state.
 *
 * @return array
 *   The batch job definition.
 */
function uber_publisher_assemble_extra_components(array &$install_state) {
  include_once drupal_get_path('profile', 'varbase') . '/varbase.profile';

  // Default Varbase components, which must be installed.
  $default_components = ConfigBit::getList('configbit/default.components.uber_publisher.bit.yml', 'install_default_components', TRUE, 'dependencies', 'profile', 'uber_publisher');

  $batch = [];

  // Install default components first.
  foreach ($default_components as $default_component) {
    $batch['operations'][] = ['varbase_assemble_extra_component_then_install', (array) $default_component];
  }

  // Install selected extra features.
  $selected_extra_features = [];
  $selected_extra_features_configs = [];

  if (isset($install_state['varbase']['extra_features_values'])) {
    $selected_extra_features = $install_state['varbase']['extra_features_values'];
  }

  if (isset($install_state['varbase']['extra_features_configs'])) {
    $selected_extra_features_configs = $install_state['varbase']['extra_features_configs'];
  }

  // Get the list of extra features config bits.
  $extraFeatures = ConfigBit::getList('configbit/extra.components.uber_publisher.bit.yml', 'show_extra_components', TRUE, 'dependencies', 'profile', 'uber_publisher');

  // If we do have selected extra features.
  if (count($selected_extra_features) && count($extraFeatures)) {
    // Have batch processes for each selected extra features.
    foreach ($selected_extra_features as $extra_feature_key => $extra_feature_checked) {
      if ($extra_feature_checked) {

        // If the extra feature was a module and not enabled, then enable it.
        if (!\Drupal::moduleHandler()->moduleExists($extra_feature_key)) {
          // Add the checked extra feature to the batch process to be enabled.
          $batch['operations'][] = ['varbase_assemble_extra_component_then_install', (array) $extra_feature_key];
        }

        if (count($selected_extra_features_configs) &&
        isset($extraFeatures[$extra_feature_key]['config_form']) &&
        $extraFeatures[$extra_feature_key]['config_form'] == TRUE &&
        isset($extraFeatures[$extra_feature_key]['formbit'])) {

          $formbit_file_name = drupal_get_path('profile', 'uber_publisher') . '/' . $extraFeatures[$extra_feature_key]['formbit'];
          $formbit_file = new Filesystem();

          if ($formbit_file->exists($formbit_file_name)) {

            // Added the selected extra feature configs to the batch process
            // with the same function name in the formbit.
            $batch['operations'][] = ['varbase_save_editable_config_values', (array) [$extra_feature_key, $formbit_file_name, $selected_extra_features_configs]];
          }
        }
      }
    }

    // Hide Wornings and status messages.
    $batch['operations'][] = ['varbase_hide_warning_and_status_messages', (array) TRUE];

    // Fix entity updates to clear up any mismatched entity.
    $batch['operations'][] = ['varbase_fix_entity_update', (array) TRUE];
  }

  // Install selected Demo content.
  $selected_demo_content = [];
  $selected_demo_content_configs = [];

  if (isset($install_state['varbase']['demo_content_values'])) {
    $selected_demo_content = $install_state['varbase']['demo_content_values'];
  }

  if (isset($install_state['varbase']['demo_content_configs'])) {
    $selected_demo_content_configs = $install_state['varbase']['demo_content_configs'];
  }

  // Get the list of demo content config bits.
  $demoContent = ConfigBit::getList('configbit/demo.content.uber_publisher.bit.yml', 'show_demo', TRUE, 'dependencies', 'profile', 'uber_publisher');

  // If we do have demo_content and we have selected demo_content.
  if (count($selected_demo_content) && count($demoContent)) {
    // Have batch processes for each selected demo content.
    foreach ($selected_demo_content as $demo_content_key => $demo_content_checked) {
      if ($demo_content_checked) {

        // If the demo content was a module and not enabled, then enable it.
        if (!\Drupal::moduleHandler()->moduleExists($demo_content_key)) {
          // Add the checked demo content to the batch process to be enabled.
          $batch['operations'][] = ['varbase_assemble_extra_component_then_install', (array) $demo_content_key];
        }

        if (count($selected_demo_content_configs) &&
        isset($demoContent[$demo_content_key]['config_form']) &&
        $demoContent[$demo_content_key]['config_form'] == TRUE &&
        isset($demoContent[$demo_content_key]['formbit'])) {

          $formbit_file_name = drupal_get_path('profile', 'uber_publisher') . '/' . $demoContent[$demo_content_key]['formbit'];
          if (file_exists($formbit_file_name)) {

            // Added the selected development configs to the batch process
            // with the same function name in the formbit.
            $batch['operations'][] = ['varbase_save_editable_config_values', (array) [$demo_content_key, $formbit_file_name, $selected_demo_content_configs]];
          }
        }
      }
    }

    // Auto detect selected extra features demo content.
    foreach ($selected_extra_features as $extra_feature_key => $extra_feature_checked) {
      if ($extra_feature_checked) {
        // Enable extra feature demo content.
        $extra_feature_checked_demo_content = $extra_feature_key . '_demo_content';
        // If the extra feature demo_content was a module and not enabled, then enable it.
        if (HelperFunctions::module_path_exists(DRUPAL_ROOT . '/modules', $extra_feature_checked_demo_content) && !\Drupal::moduleHandler()->moduleExists($extra_feature_checked_demo_content)) {
          // Add the checked extra feature to the batch process to be enabled.
          $batch['operations'][] = ['varbase_assemble_extra_component_then_install', (array) $extra_feature_checked_demo_content];
        }

        // Enable extra feature demo content for current language.
        $current_language = \Drupal::languageManager()->getCurrentLanguage()->getId();
        $extra_feature_checked_demo_content_current_language = $extra_feature_key . '_demo_content_' . $current_language;
        // If the extra feature demo_content_CURRENT_LANGUAGE was a module and not enabled, then enable it.
        if (HelperFunctions::module_path_exists(DRUPAL_ROOT . '/modules', $extra_feature_checked_demo_content_current_language) && !\Drupal::moduleHandler()->moduleExists($extra_feature_checked_demo_content_current_language)) {
          // Add the checked extra feature to the batch process to be enabled.
          $batch['operations'][] = ['varbase_assemble_extra_component_then_install', (array) $extra_feature_checked_demo_content_current_language];
        }
      }
    }

    // Hide Wornings and status messages.
    $batch['operations'][] = ['varbase_hide_warning_and_status_messages', (array) TRUE];

    // Fix entity updates to clear up any mismatched entity.
    $batch['operations'][] = ['varbase_fix_entity_update', (array) TRUE];

  }

  return $batch;
}

/**
 * Implements hook_form_FORM_ID_alter() for install_configure_form().
 *
 * Altering form_install_select_language show message for Other languages.
 */
function uber_publisher_form_install_select_language_form_alter(&$form, FormStateInterface $form_state) {
  $form['#prefix'] = "<div class='messages status other-lang-warn'>Uber Publisher is built on Drupal, which makes it available in all languages. However, right now Uber Publisher is fully available in <b>Arabic</b> and <b>English</b> only. If you install it in any other language, you will most likely find a lot of English-language text that you will need to translate.</br>You can contact Vardot’s sales team at <a href='mailto:sales@vardot.com'>sales@vardot.com</a> for assistance to make Uber Publisher available in your language.</div>";
}

/**
 * Implements hook_preprocess_install_page().
 */
function uber_publisher_preprocess_install_page(&$variables) {

  // If you are accessing the value before it is written to configuration
  // during the installer use the $install_state global.
  global $install_state;
  $profile_name = 'varbase';
  // If the profile has been selected return it.
  if (isset($install_state['parameters']['profile'])) {
    $profile_name = $install_state['parameters']['profile'];
  }

  $current_profile_path = drupal_get_path('profile', $profile_name);
  // Profile logo.
  if (file_exists($current_profile_path . '/images/' . $profile_name . '-logo.png')) {
    $variables['profile_logo'] = base_path() . $current_profile_path . '/images/' . $profile_name . '-logo.png';
  }

  // Attach install page library.
  $variables['#attached']['library'][] = $profile_name . '/install_page';
}


/**
 * Uber Publisher after install finished.
 *
 * @param array $install_state
 *   The current install state.
 *
 * @return array
 *   A renderable array with a redirect header.
 */
function uber_publisher_after_install_finished(array &$install_state) {

  // Mark all updates by the update helper checklist as successful on install.
  if (\Drupal::moduleHandler()->moduleExists('update_helper_checklist')) {
    $checkList = \Drupal::service('update_helper_checklist.update_checklist');
    $checkList->markAllUpdates();
  }

  // Entity updates to clear up any mismatched entity and/or field definitions
  // And Fix changes were detected in the entity type and field definitions.
  \Drupal::classResolver()
    ->getInstanceFromDefinition(VarbaseEntityDefinitionUpdateManager::class)
    ->applyUpdates();

  // Full flash and clear cash and rebuilding newly created routes.
  // After install of extra modules by install: in the .info.yml files.
  // In Varbase profile and all Varbase components.
  // ---------------------------------------------------------------------------
  // * Necessary inlitilization for the entire system.
  // * Account for changed config by the end install.
  // * Flush all persistent caches.
  // * Flush asset file caches.
  // * Wipe the Twig PHP Storage cache.
  // * Rebuild module and theme data.
  // * Clear all plugin caches.
  // * Rebuild the menu router based on all rebuilt data.
  drupal_flush_all_caches();

  global $base_url;

  // After install direction.
  $after_install_direction = $base_url . '/';

  install_finished($install_state);
  $output = [];

  // Clear all messages.
  \Drupal::service('messenger')->deleteAll();

  $output = [
    '#title' => t('Uber Publisher'),
    'info' => [
      '#markup' => t('<p>Congratulations, you have installed Uber Publisher!</p><p>If you are not redirected to the front page in 5 seconds, Please <a href="@url">click here</a> to proceed to your installed site.</p>', [
        '@url' => $after_install_direction,
      ]),
    ],
    '#attached' => [
      'http_header' => [
        ['Cache-Control', 'no-cache'],
      ],
    ],
  ];

  $meta_redirect = [
    '#tag' => 'meta',
    '#attributes' => [
      'http-equiv' => 'refresh',
      'content' => '0;url=' . $after_install_direction,
    ],
  ];
  $output['#attached']['html_head'][] = [$meta_redirect, 'meta_redirect'];

  return $output;
}

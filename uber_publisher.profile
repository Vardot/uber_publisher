<?php
/**
* @file
* Enables modules and site configuration for a Varbase sub profile basic
* site installation.
*/

use Drupal\Core\Form\FormStateInterface;
use Drupal\language\Entity\ConfigurableLanguage;
use Drupal\varbase\Form\AssemblerForm;
use Drupal\varbase\Form\ConfigureMultilingualForm;
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
  $install_tasks = varbase_install_tasks($install_state);
  $needs_configure_multilingual = FALSE;

  unset($install_tasks['varbase_extra_components']);
  unset($install_tasks['varbase_assemble_extra_components']);
  unset($install_tasks['varbase_multilingual_configuration_form']);

  $install_tasks['uber_publisher_extra_components'] = [
    'display_name' => t('Extra components'),
    'display' => TRUE,
    'type' => 'form',
    'function' => UberPublisherAssemblerForm::class,
  ];

  $install_tasks['uber_publisher_assemble_extra_components'] = [
    'display_name' => t('Assemble extra components'),
    'display' => TRUE,
    'type' => 'batch',
  ];

  return $install_tasks;
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

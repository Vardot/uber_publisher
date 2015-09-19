<?php

function uber_publisher_bundle_form($form, &$form_state) {
  $bundles = array();
  $options = array();
  $modules = system_rebuild_module_data();
  $current_bundle = variable_get('uber_publisher_bundle', '');

  drupal_set_title('Choose a site bundle to start with');

  foreach ($modules as $module => &$status) {
    foreach ($status->info as $attribute => &$value) {
      if ($attribute == 'bundle' && !empty($value)) {
        $bundles[$module] = $status;
      }
    }
  }

  foreach ($bundles as $bundle_name => &$bundle_status) {
    $bundle_info = $bundle_status->info;
    $bundle = $bundle_info['bundle'];
    $options[$bundle_name] = theme('uber_publisher_bundle_teaser', array('machine_name' => $bundle_name,'bundle' => $bundle));
  }

  $form['uber_publisher_bundle'] = array(
    '#type' => 'radios',
    '#title' => '',
    '#required' => TRUE,
    '#default_value' => $current_bundle,
    '#options' => $options,
    '#attributes' => array(
      'class' => array('clearfix'),
    ),
  );
  $form['actions']['submit'] = array(
    '#type' => 'submit',
    '#value' => st("Let's Get Started!"),
    '#weight' => 10,
  );

  $form['actions']['#type'] = 'actions';
  $form['actions']['submit'] = array(
    '#type' => 'submit',
    '#value' => st("Save and continue"),
  );


  $form['#attached']['css'] = array(
    drupal_get_path('module', 'uber_publisher_admin') . '/css/bundle.css',
  );

  $form['#submit'][] = 'uber_publisher_bundle_form_submit';
  return $form;
}

function uber_publisher_bundle_form_validate($form, $form_state) {
  // @todo needs validation.
}

function uber_publisher_bundle_form_submit($form, $form_state) {
  module_load_include('inc', 'uber_publisher_admin', 'includes/uber_publisher_installer');

  if (!empty($form_state['values']['uber_publisher_bundle'])) {
    $bundle = array_filter(array($form_state['values']['uber_publisher_bundle']));
    $batch = _uber_publisher_installer($bundle);
    batch_set($batch);
  }
}

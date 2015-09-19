<?php

/**
 * Implements hook_form_ID_form_alter().
 */
function uber_theme_form_uber_publisher_article_node_form_alter(&$form, &$form_state, $form_id) {
  global $user;

  $form['#attributes']['class'][] = 'row';

  // Format Publishing actions
  $form['actions']['#attributes']['class'][] = 'btn-group';
  $form['#group_children']['actions'] = 'group_publish_options';
  $form['#fieldgroups']['group_publish_options']->children[] = 'actions';

  // Format Revision Information actions
  $form['revision_information']['#group'] = 'group_publish_options';
  $form['#group_children']['revision_information'] = 'group_publish_options';
  $form['#fieldgroups']['group_publish_options']->children[] = 'revision_information';

  $form['revision_information']['#weight'] = 1;
  $form['revision_information']['#type'] = 'container';
  $form['revision_information']['log']['#weight'] = 2;
  $form['revision_information']['log']['#resizable'] = false;
  $form['revision_information']['log']['#default_value'] = '';
  $form['revision_information']['log']['#attributes']['placeholder'] = t('Provide an explanation of the changes you are making');
  $form['revision_information']['log']['#description'] = '';

  if(isset($form['options']['log']) && is_array($form['options']['log'])) {
    // Move the revision log back into the revision information.
    $form['revision_information']['log'] = $form['options']['log'];
    $form['revision_information']['workbench_moderation_state_new'] = $form['options']['workbench_moderation_state_new'];
    unset($form['options']['log']);
    unset($form['options']['workbench_moderation_state_new']);
    $form['revision_information']['#access'] = TRUE;
  }

  //Format Scheduler Settings
  $form['scheduler_settings']['#group'] = 'group_publish_options';
  $form['#group_children']['scheduler_settings'] = 'group_publish_options';
  $form['#fieldgroups']['group_publish_options']->children[] = 'scheduler_settings';

  $form['scheduler_settings']['#type'] = 'container';
  $form['scheduler_settings']['#weight'] = 5;
  $form['scheduler_settings']['publish_on']['#weight'] = 5;
  $form['scheduler_settings']['publish_on']['#description'] = '';

  // Get workbench status
  if (module_exists('workbench_moderation')) {
    $workbench_block = module_invoke_all('workbench_block');
    if (!empty($workbench_block)) {
      $form['workbench_block'] = array(
        '#weight' => 0,
        '#group' => 'group_publish_options',
        '#type' => 'markup',
        '#markup' =>theme('container', array('element' => array('#children' => implode('<br />', $workbench_block), '#attributes' => array('class' => array('workbench-status-msg'))))),
      );
    }
    $form['options']['#access'] = FALSE;
    $form['#group_children']['workbench_block'] = 'group_publish_options';
    $form['#fieldgroups']['group_publish_options']->children[] = 'workbench_block';
  }
}

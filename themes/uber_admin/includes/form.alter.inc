<?php

/**
 * Implements hook_form_ID_form_alter().
 */
function uber_admin_form_node_form_alter(&$form, &$form_state, $form_id) {

  //Format SEO group
  if (isset($form['#fieldgroups']['group_seo'])) {
    //Format URL alias Settings
    $form['path']['#group'] = 'group_seo';
    $form['#group_children']['path'] = 'group_seo';
    $form['#fieldgroups']['group_seo']->children[] = 'path';
    $form['path']['#type'] = 'container';

    //Format URL redirects Settings
    if (isset($form['redirect'])) {
      $form['redirect']['#group'] = 'group_seo';
      $form['#group_children']['redirect'] = 'group_seo';
      $form['#fieldgroups']['group_seo']->children[] = 'redirect';
      $form['redirect']['#type'] = 'container';
    }

    //Format Metatags Settings
    if (isset($form['metatags'])) {
      $form['metatags']['#group'] = 'group_seo';
      $form['#group_children']['metatags'] = 'group_seo';
      $form['#fieldgroups']['group_seo']->children[] = 'metatags';
      $form['metatags']['#type'] = 'container';
    }
  }

  //Format publish options group
  if (isset($form['#fieldgroups']['group_publish_options'])) {
    // Get workbench status
    if (module_exists('workbench_moderation')) {
      $workbench_block = module_invoke_all('workbench_block');
      if (!empty($workbench_block)) {
        $form['workbench_block'] = array(
            '#weight' => -10,
            '#group' => 'group_publish_options',
            '#type' => 'markup',
            '#markup' => theme('container', array('element' => array('#children' => implode('<br />', $workbench_block), '#attributes' => array('class' => array('workbench-status-msg', $form['workbench_moderation_state_current']['#value']))))),
        );
      }
      $form['options']['#access'] = FALSE;
      $form['#group_children']['workbench_block'] = 'group_publish_options';
      $form['#fieldgroups']['group_publish_options']->children[] = 'workbench_block';
    }

    //Format language settings
    if (isset($form['language'])) {
      $form['language']['#group'] = 'group_publish_options';
      $form['#group_children']['language'] = 'group_publish_options';
      $form['#fieldgroups']['group_publish_options']->children[] = 'language';
      $form['language']['#weight'] = 10;
    }

    //Format scheduler settings
    if (isset($form['scheduler_settings'])) {
      $form['scheduler_settings']['#group'] = 'group_publish_options';
      $form['#group_children']['scheduler_settings'] = 'group_publish_options';
      $form['#fieldgroups']['group_publish_options']->children[] = 'scheduler_settings';
      $form['scheduler_settings']['#type'] = 'container';
      $form['scheduler_settings']['#weight'] = 20;
      $form['scheduler_settings']['publish_on']['#description'] = '';
    }

    // Format Revision Information actions
    if (isset($form['revision_information'])) {
      $form['revision_information']['#group'] = 'group_publish_options';
      $form['#group_children']['revision_information'] = 'group_publish_options';
      $form['#fieldgroups']['group_publish_options']->children[] = 'revision_information';
      $form['revision_information']['#type'] = 'container';
      $form['revision_information']['#weight'] = 30;
      $form['revision_information']['log']['#weight'] = 40;
      $form['revision_information']['#access'] = TRUE;

      if (isset($form['options']['log'])) {
        $form['revision_information']['log'] = $form['options']['log'];
        unset($form['options']['log']);
      }

      if (isset($form['options']['workbench_moderation_state_new'])) {
        $form['revision_information']['workbench_moderation_state_new'] = $form['options']['workbench_moderation_state_new'];
        unset($form['options']['workbench_moderation_state_new']);
      }
    }

    //Format panelizer Settings
    if (isset($form['panelizer'])) {
      $form['panelizer']['#group'] = 'group_publish_options';
      $form['#group_children']['panelizer'] = 'group_publish_options';
      $form['#fieldgroups']['group_publish_options']->children[] = 'panelizer';
      $form['panelizer']['#type'] = 'container';
      $form['panelizer']['#weight'] = 50;
    }

    //Format Authoring information Settings
    $form['author']['#group'] = 'group_publish_options';
    $form['#group_children']['author'] = 'group_publish_options';
    $form['#fieldgroups']['group_publish_options']->children[] = 'author';
    $form['author']['#type'] = 'container';
    $form['author']['#weight'] = 60;
  }

  // Format revision information
  if (isset($form['revision_information']['log'])) {
    $form['revision_information']['log']['#resizable'] = false;
    $form['revision_information']['log']['#default_value'] = '';
    $form['revision_information']['log']['#description'] = '';
  }
}

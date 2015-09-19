<?php

/**
 * Implements hook_form_FORM_ID_alter()
 */
function uber_publisher_admin_form_views_content_views_panes_content_type_edit_form_alter(&$form, &$form_state, $form_id) {
  if (isset($form['context'])) {
    foreach ($form['context'] as $key => &$elements) {
      // If no context is avilable
      if (empty($elements) || !is_array($elements) || !isset($elements['#options'])) {
        continue;
      }

      if ($elements['#type'] == 'select') {
        // If context is a select list convert it to radio buttons
        $elements['#type'] = 'radios';

        // Remove the "No context" context option.
        if (isset($elements['#options']['empty'])) {
          unset($elements['#options']['empty']);
        }

        // Remove the selection of no options are left
        if (empty($elements['#options'])) {
          $elements['#access'] = FALSE;
        }
      }
    }
  }
}

/**
 * Implements hook_form_ID_form_alter().
 */
function uber_publisher_admin_form_node_form_alter(&$form, &$form_state, $form_id) {
  $form['author']['date']['#access'] = FALSE;
}
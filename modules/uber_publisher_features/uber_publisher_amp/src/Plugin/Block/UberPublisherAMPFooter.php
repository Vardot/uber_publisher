<?php

/**
 * @file
 * Contains \Drupal\uber_publisher_amp\Plugin\Block\UberPublisherAMPFooter.
 */

namespace Drupal\uber_publisher_amp\Plugin\Block;

use Drupal\Core\Block\BlockBase;
use Drupal\Core\Block\BlockPluginInterface;
use Drupal\Core\Form\FormStateInterface;

/**
 * Provides a 'Uber Publisher AMP Footer'.
 *
 * @Block(
 * id = "uber_publisher_amp_footer",
 * admin_label = @Translation("Uber Publisher AMP Footer"),
 * category = @Translation("Uber Publisher")
 * )
 */
class UberPublisherAMPFooter extends BlockBase implements BlockPluginInterface {

  /**
   *
   * {@inheritdoc}
   */
  public function build() {
    $block_body = 'Powered by Vardot</br>Copyright © 2017 Uber Publisher. All rights reserved';

    return [
      '#type' => 'markup',
      '#markup' => t($block_body),
    ];
  }

  /**
   *
   * {@inheritdoc}
   */
  public function blockForm($form, FormStateInterface $form_state) {
    $form = parent::blockForm($form, $form_state);
    return $form;
  }

  /**
   *
   * {@inheritdoc}
   */
  public function blockSubmit($form, FormStateInterface $form_state) {
    parent::blockSubmit($form, $form_state);
  }

}

<?php

/**
 * @file
 * Contains \Drupal\uber_publisher_amp\Plugin\Block\UberPublisherAMPHeader.
 */

namespace Drupal\uber_publisher_amp\Plugin\Block;

use Drupal\Core\Block\BlockBase;
use Drupal\Core\Block\BlockPluginInterface;
use Drupal\Core\Form\FormStateInterface;

/**
 * Provides a 'Uber Publisher AMP Header'.
 *
 * @Block(
 * id = "uber_publisher_amp_header",
 * admin_label = @Translation("Uber Publisher AMP Header"),
 * category = @Translation("Uber Publisher")
 * )
 */
class UberPublisherAMPHeader extends BlockBase implements BlockPluginInterface {

  /**
   *
   * {@inheritdoc}
   */
  public function build() {
    $block_body = '<a href="/" title="Home" rel="home"><img style="max-width: 200px;" src="' . file_url_transform_relative(file_create_url(theme_get_setting('logo.url'))) . '" alt="Home"></a>';

    $block_body .= '<button class="hamburger" on="tap:sidebar1.toggle"><span class="one"></span><span class="two"></span><span class="three"></span></button>';

    $menu_tree = \Drupal::menuTree();
    $parameters = $menu_tree->getCurrentRouteMenuTreeParameters('main');
    $tree = $menu_tree->load('main', $parameters);
    $manipulators = [
      ['callable' => 'menu.default_tree_manipulators:checkAccess'],
      ['callable' => 'menu.default_tree_manipulators:generateIndexAndSort'],
    ];
    $tree = $menu_tree->transform($tree, $manipulators);
    $menu = $menu_tree->build($tree);
    $menu_html = ['#markup' => drupal_render($menu)];

    $block_body .= '<amp-sidebar id="sidebar1" layout="nodisplay" side="right"><button class="hamburger" on="tap:sidebar1.close">x</button>' . drupal_render($menu_html) . '</amp-sidebar>';

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

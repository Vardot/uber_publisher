<?php

namespace Drupal\uber_publisher_open_weather\Plugin\Block;

use Drupal\Core\Block\BlockBase;

/**
 * Provides a 'Open Weather' Block.
 *
 * @Block(
 *   id = "open_weather",
 *   admin_label = @Translation("Open Weather widget"),
 *   category = @Translation("Open Weather"),
 * )
 */
class OpenWeather extends BlockBase {

  /**
   * {@inheritdoc}
   */
  public function build() {
    return array(
        '#type' => 'markup',
        '#markup' => t('<div id="weather"></div>')
    );
  }

}

<?php

/**
 * Preprocesses variables for uber publisher follow platforms.
 *
 * @see theme_uber_publisher_follow_platforms()
 */
function template_preprocess_uber_publisher_follow_platforms(&$variables) {
  if (empty($variables)) return;
  $platform_infos = uber_publisher_follow_platforms();

  if (empty($variables['icon_style'])) {
    $variables['icon_style'] = 'font_awesome:nl';
  }
  list($icon_style, $icon_size) = explode(':', $variables['icon_style']);

  // Apply the link settings to the render array.
  foreach ($variables['link_attributes'] as $key => $value) {
    if ($value == '<none>') {
      unset($variables['link_attributes'][$key]);
    }
  }

  // Sort and loop over the platforms.
  uasort($variables['platform_values'], 'drupal_sort_weight');
  foreach ($variables['platform_values'] as $platform_name => $platform_value) {
    // Don't add target _blank to contact and rss links.
    if (in_array($platform_name, array('rss', 'contact'))) {
      unset($variables['link_attributes']['target']);
    }

    // Build the platform data array.
    $variables['platform_values'][$platform_name] = array(
      '#theme' => 'uber_publisher_follow_platform',
      '#name' => $platform_name,
      '#info' => $platform_infos[$platform_name],
      '#value' => $platform_value['platform_value'],
      '#icon_style' => $icon_style,
      '#icon_size' => $icon_size,
      '#appearance' => $variables['appearance'],
      '#attributes' => $variables['link_attributes'],
    );
  }

  if ($variables['appearance']['orientation'] == 'h') {
    $variables['attributes']['class'][] = 'inline horizontal';
  }
  else {
    $variables['attributes']['class'][] = 'vertical';
  }

  $variables['attributes']['class'][] = $icon_style;
}

/**
 * Theme function for the platforms.
 */
function theme_uber_publisher_follow_platforms(&$variables) {
  $output = '';
  $platforms = $variables['platform_values'];
  $attributes = $variables['attributes'];

  // Open the ul element.
  $output .= '<ul' . drupal_attributes($attributes) . '>';

  $num_platforms = count($platforms);
  $i = 1;

  foreach ($platforms as $name => $platform) {
    $class = array($name);

    // Add first and last classes to the list of platforms to help out themers.
    if ($i == 1) {
      $class[] = 'first';
    }
    if ($i == $num_platforms) {
      $class[] = 'last';
    }

    $output .= '<li ' . drupal_attributes(array('class' => $class)) . '>';
    // Render the platform item.
    $output .= drupal_render($platform);
    $output .= '</li>';

    $i++;
  }

  // Close the ul element.
  $output .= '</ul>';

  return $output;
}

/**
 * Processes variables for uber-publisher-follow-platform.tpl.php.
 *
 * @see theme_uber_publisher_follow_platform()
 */
function template_preprocess_uber_publisher_follow_platform(&$variables) {
  $info = $variables['info'];
  $name = $variables['name'];
  $value = $variables['value'];
  $icon_style = $variables['icon_style'];
  $icon_size = $variables['icon_size'];

  $function_name = "uber_publisher_follow_{$icon_style}_icon";
  if (function_exists($function_name)) {
    $function_name($variables);
  }

  // Call the url callback of the platform to create the link url.
  $variables['link'] = $info['base url'] . $value;
}

/**
 * Theme function for a single platform element.
 */
function theme_uber_publisher_follow_platform(&$variables) {
  $output = '';
  $set = uber_publisher_follow_iconset($variables['icon_style']);

  $options = array();
  $options['attributes'] = $variables['attributes'];
  $options['html'] = TRUE;

  $classes = array();
  $classes[] = $set['class name'];
  $classes[] = $set['class name'] . '-' . $variables['name'];
  $classes[] = $set['class name'] . '-' . $variables['icon_size'];
  $class = implode(' ', $classes);

  $output .= l("<i class='$class'></i>", $variables['link'], $options);

  if (!empty($variables['appearance']['show_name'])) {
    if ($variables['appearance']['orientation'] == 'h') {
      $output .= '<br />';
    }

    $title = check_plain($variables['info']['title']);
    $output .= '<span>' . l($title, $variables['link'], $options) . '</span>';
  }

  return $output;
}

/**
 * Returns HTML for the platform table with tabledrag.
 */
function theme_uber_publisher_follow_platforms_table(&$variables) {
  $form = $variables['form'];

  $rows = array();
  foreach (element_children($form) as $platform) {
    $form[$platform]['weight']['#attributes']['class'] = array('platforms-order-weight');
    $rows[] = array(
      'data' => array(
        '<strong>' . $form[$platform]['platform_value']['#title'] . '<strong>',
        array('class' => array('platform-cross'), 'data' => drupal_render($form[$platform]['platform_value'])),
        array('class' => array('tabledrag-hide'), 'data' => drupal_render($form[$platform]['weight'])),
      ),
      'class' => array('draggable'),
    );
  }

  $header = array(
    t('Platform'),
    '',
    array(
      'class' => array('tabledrag-hide'),
      'data' => t('Weight'),
    ),
  );

  $output = theme('table', array(
    'header' => $header,
    'rows' => $rows,
    'attributes' => array('id' => 'platforms-order'),
  ));

  drupal_add_tabledrag('platforms-order', 'order', 'silbing', 'platforms-order-weight');

  return $output;
}

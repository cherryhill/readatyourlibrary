<?php

/**
 * @file
 * owlcarousel.theme.inc
 *
 * Implements theme functions for Owl Carousel.
 */

/**
 * Default theme implementation for lists
 */
function theme_owlcarousel_list(&$vars) {
  $items = &$vars['items'];
  $output = '';

  if (!empty($items)) {
    foreach ($items as $i => $item) {
      $output .= theme('owlcarousel_list_item', array(
        'item' => $item['row'],
        'class' => drupal_html_class('item-' . $i),
      ));
    }
  }

  return $output;
}

/**
 * Default theme implementation for carousel items
 */
function theme_owlcarousel_list_item(&$vars) {
  return '<div class="' . $vars['class'] . '">' . $vars['item'] . "</div>";
}

/**
 * Template process carousel theme.
 */
function template_process_owlcarousel(&$vars) {
  $instance_id = $vars['settings']['instance'];
  $owlcarousel_id = $vars['settings']['attributes']['id']['default'];
  $vars['settings']['attributes']['id'] = $owlcarousel_id;

  owlcarousel_initiate_instance($instance_id, $owlcarousel_id);
}

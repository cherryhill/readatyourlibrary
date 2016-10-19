<?php

/**
 * @file
 * API documentation for Owl Carousel.
 */

/**
 * Implements hook_owlcarousel_settings_alter().
 *
 * @param array
 *   Instance settings.
 * @param string
 *   Carousel identifier.
 */
function hook_owlcarousel_settings_alter(&$settings, $instance) {
  switch ($instance) {
    case 'owlcarousel_settings_default':
      // 
      break;
  }
}

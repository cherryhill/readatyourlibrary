<?php
/**
 * @file
 * calendar_sticker_image_style.features.inc
 */

/**
 * Implements hook_image_default_styles().
 */
function calendar_sticker_image_style_image_default_styles() {
  $styles = array();

  // Exported image style: child_progress_sticker.
  $styles['child_progress_sticker'] = array(
    'label' => 'Child progress sticker',
    'effects' => array(
      1 => array(
        'name' => 'image_scale',
        'data' => array(
          'width' => 50,
          'height' => 50,
          'upscale' => 0,
        ),
        'weight' => 1,
      ),
      2 => array(
        'name' => 'image_resize',
        'data' => array(
          'width' => 50,
          'height' => 50,
        ),
        'weight' => 2,
      ),
    ),
  );

  return $styles;
}

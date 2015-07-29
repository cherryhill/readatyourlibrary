<?php

/**
 * @file
 * openbadging.features.inc
 */

/**
 * Implements hook_image_default_styles().
 */
function openbadging_image_default_styles() {
  $styles = array();

  // Exported image style: 110_110.
  $styles['110_110'] = array(
    'name' => '110_110',
    'effects' => array(
      5 => array(
        'label' => 'Scale',
        'help' => 'Scaling will maintain the aspect-ratio of the original image. If only a single dimension is specified, the other dimension will be calculated.',
        'effect callback' => 'image_scale_effect',
        'form callback' => 'image_scale_form',
        'summary theme' => 'image_scale_summary',
        'module' => 'image',
        'name' => 'image_scale',
        'data' => array(
          'width' => '110',
          'height' => '110',
          'upscale' => 0,
        ),
        'dimensions callback' => 'image_scale_dimensions',
        'weight' => '1',
      ),
    ),
  );

  // Exported image style: 200_200.
  $styles['200_200'] = array(
    'name' => '200_200',
    'effects' => array(
      9 => array(
        'label' => 'Scale',
        'help' => 'Scaling will maintain the aspect-ratio of the original image. If only a single dimension is specified, the other dimension will be calculated.',
        'effect callback' => 'image_scale_effect',
        'form callback' => 'image_scale_form',
        'summary theme' => 'image_scale_summary',
        'module' => 'image',
        'name' => 'image_scale',
        'data' => array(
          'width' => '200',
          'height' => '200',
          'upscale' => 0,
        ),
        'dimensions callback' => 'image_scale_dimensions',
        'weight' => '1',
      ),
    ),
  );

  // Exported image style: 60x60.
  $styles['60x60'] = array(
    'name' => '60x60',
    'effects' => array(
      12 => array(
        'label' => 'Scale',
        'help' => 'Scaling will maintain the aspect-ratio of the original image. If only a single dimension is specified, the other dimension will be calculated.',
        'effect callback' => 'image_scale_effect',
        'form callback' => 'image_scale_form',
        'summary theme' => 'image_scale_summary',
        'module' => 'image',
        'name' => 'image_scale',
        'data' => array(
          'width' => '60',
          'height' => '60',
          'upscale' => 0,
        ),
        'dimensions callback' => 'image_scale_dimensions',
        'weight' => '2',
      ),
    ),
  );

  // Exported image style: 75_75.
  $styles['75_75'] = array(
    'name' => '75_75',
    'effects' => array(
      4 => array(
        'label' => 'Scale and crop',
        'help' => 'Scale and crop will maintain the aspect-ratio of the original image, then crop the larger dimension. This is most useful for creating perfectly square thumbnails without stretching the image.',
        'effect callback' => 'image_scale_and_crop_effect',
        'form callback' => 'image_resize_form',
        'summary theme' => 'image_resize_summary',
        'module' => 'image',
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => '75',
          'height' => '75',
        ),
        'weight' => '1',
      ),
    ),
  );

  return $styles;
}

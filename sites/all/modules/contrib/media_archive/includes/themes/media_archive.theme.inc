<?php

/**
 * @file media_archive/includes/themes/media_archive.theme.inc
 *
 * Theme and preprocess functions for Media: Archive.
 */

/**
 * Preprocess function for theme('media_archive_video').
 */
function media_archive_preprocess_media_archive_video(&$variables) {
  // Define some variables.
  $protocol = 'http:';
  $url_base = 'archive.org';

  // Build the URL for display.
  $uri = $variables['uri'];
  $wrapper = file_stream_wrapper_get_instance_by_uri($uri);
  $parts = $wrapper->get_parameters();

  $variables['video_id'] = check_plain($parts['v']);
  $variables['wrapper_id'] = 'media_archive_' . $variables['video_id'] . '_' . $parts['video_videosecond'];

  // Define some links to the available formats.
  $mediaformat = array(
    'mp4URL'  => '_512kb.mp4',
    'webmURL' => '.webm',
    'ogvURL'  => '.ogv',
  );
  foreach ($mediaformat as $format => $ext) {
    $variables[$format]  = 'http://' . MEDIA_ARCHIVE_BASE_URL . '/download/' . $variables['video_id'] . '/' . $parts['video_videosecond'] . $ext;
  }

  // Add some options as their own template variables.
  foreach (array('width', 'height') as $theme_var) {
    $variables[$theme_var] = $variables['options'][$theme_var];
  }

  // Build the html5 player settings and flash query.
  $query = array();

  if ($variables['options']['autoplay']) {
    $variables['autoplay'] = ' autoplay';
    $query['autoplay'] = 'true';
  }
  else {
    $variables['autoplay'] = '';
  }

  // Show controls.
  if ($variables['options']['controls']) {
    $variables['controls'] = ' controls';
    $query['controlbar.position'] = 'over';
  }
  else {
    $variables['controls'] = '';
    $query['controlbar.position'] = 'none';
  }

  // Hide controls after mouse left the player window.
  if ($variables['options']['controls_hide']) {
    $query['controlbar.idlehide'] = 'true';
  }
  else {
    $query['controlbar.idlehide'] = 'false';
  }

  // Loop the video.
  if ($variables['options']['loop']) {
    $variables['loop'] = ' loop';
    $query['repeat'] = 'list';
  }
  else {
    $variables['loop'] = '';
  }

  $variables['poster'] = '';

  // Build the flash url.
  $variables['url'] = url($protocol . '//www.' . $url_base . '/embed/' . $variables['video_id'], array('query' => $query, 'external' => TRUE));
  $variables['url'] = htmlspecialchars($variables['url']);
}

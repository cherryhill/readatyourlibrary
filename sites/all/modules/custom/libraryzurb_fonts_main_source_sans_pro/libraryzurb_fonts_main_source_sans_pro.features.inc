<?php
/**
 * @file
 * libraryzurb_fonts_main_source_sans_pro.features.inc
 */

/**
 * Implements hook_fontyourface_features_default_font().
 */
function libraryzurb_fonts_main_source_sans_pro_fontyourface_features_default_font() {
  return array(
    'Source Sans Pro 700 (latin-ext)' => array(
      'name' => 'Source Sans Pro 700 (latin-ext)',
      'enabled' => 1,
      'url' => 'http://www.google.com/webfonts/family?family=Source Sans Pro&subset=latin-ext#700',
      'provider' => 'google_fonts_api',
      'css_selector' => 'h4, .field-label, .sidebar .block:not(.block-menu-block) h2.block-title, #comments h3',
      'css_family' => 'Source Sans Pro',
      'css_style' => 'normal',
      'css_weight' => 700,
      'css_fallbacks' => '',
      'foundry' => '',
      'foundry_url' => '',
      'license' => '',
      'license_url' => '',
      'designer' => '',
      'designer_url' => '',
      'metadata' => 'a:2:{s:4:"path";s:19:"Source Sans Pro:700";s:6:"subset";s:9:"latin-ext";}',
    ),
    'Source Sans Pro regular (latin-ext)' => array(
      'name' => 'Source Sans Pro regular (latin-ext)',
      'enabled' => 1,
      'url' => 'http://www.google.com/webfonts/family?family=Source Sans Pro&subset=latin-ext#regular',
      'provider' => 'google_fonts_api',
      'css_selector' => 'body, .block-menu-block .menu-name-main-menu ul ul, .section-library-search h2, .top-bar.expanded .main-nav .back h5',
      'css_family' => 'Source Sans Pro',
      'css_style' => 'normal',
      'css_weight' => 'normal',
      'css_fallbacks' => '',
      'foundry' => '',
      'foundry_url' => '',
      'license' => '',
      'license_url' => '',
      'designer' => '',
      'designer_url' => '',
      'metadata' => 'a:2:{s:4:"path";s:23:"Source Sans Pro:regular";s:6:"subset";s:9:"latin-ext";}',
    ),
  );
}

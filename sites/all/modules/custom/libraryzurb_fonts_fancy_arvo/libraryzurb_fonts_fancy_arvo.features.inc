<?php
/**
 * @file
 * libraryzurb_fonts_fancy_arvo.features.inc
 */

/**
 * Implements hook_fontyourface_features_default_font().
 */
function libraryzurb_fonts_fancy_arvo_fontyourface_features_default_font() {
  return array(
    'Arvo regular (latin)' => array(
      'name' => 'Arvo regular (latin)',
      'enabled' => 1,
      'url' => 'http://www.google.com/webfonts/family?family=Arvo&subset=latin#regular',
      'provider' => 'google_fonts_api',
      'css_selector' => 'h1, h2, h3, blockquote::before, blockquote::after, .aside, .block-menu-block .menu-name-main-menu ul, .special',
      'css_family' => 'Arvo',
      'css_style' => 'normal',
      'css_weight' => 'normal',
      'css_fallbacks' => '',
      'foundry' => '',
      'foundry_url' => '',
      'license' => '',
      'license_url' => '',
      'designer' => '',
      'designer_url' => '',
      'metadata' => 'a:2:{s:4:"path";s:12:"Arvo:regular";s:6:"subset";s:5:"latin";}',
    ),
  );
}

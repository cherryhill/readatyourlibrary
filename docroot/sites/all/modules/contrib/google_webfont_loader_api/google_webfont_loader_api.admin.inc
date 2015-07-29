<?php

/**
 * @file
 * The form which allows for user settings on the webfont loader api.
 */

/**
 * Form to set what the google webfont loader api will load upon startup.
 */
function google_webfont_loader_api_site_settings($form_state = array()) {
  $form = array();
  $listing = google_webfont_loader_api_get_font_list(TRUE);
  $form['google_webfont_loader_api_fontinfo_listing'] = array(
    '#type' => 'value',
    '#value' => $listing,
  );
  foreach ($listing as $list_item) {
    $fonts[$list_item->name] = check_plain($list_item->info['name']);
  }
  $form['google_webfont_loader_api_font'] = array(
    '#type' => 'checkboxes',
    '#title' => t('Font'),
    '#description' => t('Use the google webfont loader api to add a font styling to the site. If you select none, the loader will act as though it is disabled unless some other module loads it.'),
    '#options' => $fonts,
    '#default_value' => variable_get('google_webfont_loader_api_font', array()),
  );

  $form['google_webfont_loader_api_cache'] = array(
    '#type' => 'checkbox',
    '#title' => t('Cache Webfont Loader file locally'),
    '#description' => t("If checked, the webfont loader api is retrieved and cached locally. It is updated daily from Google's servers to ensure updates to code are reflected in the local copy."),
    '#default_value' => variable_get('google_webfont_loader_api_cache', 0),
  );

  $tokens = array(
    '!link' => l(t('google webfont docs'), 'https://code.google.com/apis/webfonts/docs/webfont_loader.html', array()),
  );
  $form['google_webfont_loader_api_display_style'] = array(
    '#type' => 'radios',
    '#title' => t('Font Loading Style'),
    '#description' => t('Select default if you wish for the font to get
                        displayed even though it may not yet have loaded (or
                        however you define it in your render stylesheets).
                        This provides you with control on how you want the fonts
                        to behave and this is useful if you want the users to see
                        text regardless of current loaded status of the font.
                        Choose hidden if you want the page to display only after
                        the fonts have been loaded on the page. Please read the
                        !link or the contents of the README.txt file for
                        more information on how to format your CSS', $tokens),
    '#default_value' => variable_get('google_webfont_loader_api_display_style', ''),
    '#options' => array(
      '' => t('default'),
      'hidden' => t('hidden'),
    ),
  );

  return system_settings_form($form);
}

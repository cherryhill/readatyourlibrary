<?php
/**
 * @file
 * Administrative settings for IE6NoMore.
 */

/**
 * Define settings form for which versions of Internet Explorer to target.
 * @ingroup forms
 */
function ie6nomore_admin_settings() {
  $form = array();

  $form['ie6nomore_ie'] = array(
    '#type' => 'radios',
    '#title' => t('Show banner for Internet Explorer version'),
    '#options' => array(
      'lt IE 7' => t('IE6'),
      'lt IE 8' => t('IE7 and below'),
      'lt IE 9' => t('IE8 and below'),
    ),
    '#default_value' => variable_get('ie6nomore_ie', 'lt IE 8'),
    //'#description' => t('Banner promoting upgrade will appear for version of IE selected and previous versions.'),
  );

  $form['ie6nomore_dismissable'] = array(
    '#type' => 'checkbox',
    '#title' => t('Allow user to dismiss banner.'),
    '#default_value' => variable_get('ie6nomore_dismissable', TRUE),
  );

  return system_settings_form($form);
}
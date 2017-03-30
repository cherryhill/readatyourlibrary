<?php
/**
 * Implements hook_form_FORM_ID_alter().
 *
 * @param $form
 *   The form.
 * @param $form_state
 *   The form state.
 */
function adult_program_form_system_theme_settings_alter(&$form, &$form_state) {
    /*$form['custom_color'] = array(
    '#type' => 'vertical_tabs',
    '#prefix' => '<h2><small>' . t('Color Palettes') . '</small></h2>',
    '#weight' => -10,
  );
  $form['color'] = array(
    '#type' => 'fieldset',
    '#title' => t('Theme Color Style'),
    '#group' => 'custom_color',
  );
  $form['color']['theme_color'] = array(
  '#type' => 'fieldset',
    '#title' => t('Choose Style'),
    '#collapsible' => TRUE,
    '#collapsed' => TRUE,
  );
  $form['color']['theme_color']['choose_color'] = array(
    '#type' => 'select',
    '#title' => t('Select Style'),
    '#description' => t('choose your theme style'),
    '#default_value' => theme_get_setting('choose_color'),
    '#options' => array(
      'cs-default' => t('default'),
      'cs-classic' => t('classic'),
      'cs-elegant' => t('elegant'),
    ),
  );*/
}

<?php

// Function callback for purchase link form.
function platform_configuration_teen($form, &$form_state) {

  $default_date = date('d/m/y');
  $program_start_date = variable_get('pmc_start_date_teen', $default_date);
  $program_end_date = variable_get('pmc_end_date_teen', $default_date);

  $form['program_configuration'] = array(
    '#type' => 'fieldset', 
    '#title' => t('Program Configuration'),
    '#collapsible' => TRUE, 
    '#collapsed' => FALSE,
  );
  $form['program_configuration']['pmc_start_date_teen'] = array(
    '#title' => t('Program Start date'),
    '#type' => 'date_popup',
    '#date_format' => 'd/m/Y',
    '#date_year_range' => '0:+10',
    '#required' => TRUE,
    '#size' => 8,
    '#default_value' => $program_start_date,
  );
  $form['program_configuration']['pmc_end_date_teen'] = array(
    '#title' => t('Program End date'),
    '#type' => 'date_popup',
    '#date_format' => 'd/m/Y',
    '#date_year_range' => '0:+10',
    '#required' => TRUE,
    '#size' => 8,
    '#default_value' => $program_end_date,
  );
  $form['program_configuration']['pmc_program_name_teen'] = array(
    '#type' => 'textfield',
    '#title' => 'Program Name',
  );
  $form['program_configuration']['pmc_progrm_image_teen'] = array(
    '#title' => t('Program Image'),
    '#type' => 'managed_file',
    '#description' => t('The uploaded image will be displayed on this page using the image style choosen below.'),
    '#upload_location' => 'public://',
  );

	return system_settings_form($form);
}
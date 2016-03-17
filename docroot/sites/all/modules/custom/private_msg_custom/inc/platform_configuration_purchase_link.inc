<?php

// Function callback for purchase link form.
function platform_configuration_purchase_link($form, &$form_state) {
    $form['program_configuration'] = array(
      '#type' => 'fieldset', 
      '#title' => t('Program Configuration'),
      '#collapsible' => TRUE, 
      '#collapsed' => FALSE,

    );
    $form['program_configuration']['pmc_start_date'] = array(
        '#title' => t('Start date'),
        '#type' => 'date_popup',
        '#date_format' => 'd/m/Y',
        '#date_year_range' => '0:+10',
        '#required' => TRUE,
        '#size' => 8,
        '#default_value' => date('Y-m-d', time()),
    );
    $form['program_configuration']['pmc_end_date'] = array(
        '#title' => t('End date'),
        '#type' => 'date_popup',
        '#date_format' => 'd/m/Y',
        '#date_year_range' => '0:+10',
        '#required' => TRUE,
        '#size' => 8,
        '#default_value' => date('Y-m-d', time()),
    );
    $form['program_configuration']['pmc_program_name'] = array(
        '#type' => 'textfield',
        '#title' => 'Program Name',
    );
    $form['program_configuration']['pmc_library_name'] = array(
        '#type' => 'textfield',
        '#title' => 'Library Name',
    );
    $form['program_configuration']['pmc_progrm_image'] = array(
      '#title' => t('Program Image'),
      '#type' => 'managed_file',
      '#description' => t('The uploaded image will be displayed on this page using the image style choosen below.'),
      '#upload_location' => 'public://',
    );

	$form['pmc_purchase_link'] = array(
		'#type' => 'textfield',
		'#title' => 'Purchase Link',
		'#description' => 'Enter a valid url (https://www.example.com)',
		'#default_value' => variable_get('pmc_purchase_link'),
	);


	return system_settings_form($form);
}

// validation for purchase link form
function platform_configuration_purchase_link_validate($form, &$form_state) {
	$purchase_link = $form_state['values']['pmc_purchase_link'];
	if(filter_var($purchase_link, FILTER_VALIDATE_URL) === false) {
		form_set_error('pmc_purchase_link','Please enter a valid URL');
	}
}
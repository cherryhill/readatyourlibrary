<?php

// Function callback for purchase link form.
function platform_configuration_purchase_link_teen($form, &$form_state) {
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
        '#title' => t('Start date'),
        '#type' => 'date_popup',
        '#date_format' => 'd/m/Y',
        '#date_year_range' => '0:+10',
        '#required' => TRUE,
        '#size' => 8,
        '#default_value' => $program_start_date,
    );
    $form['program_configuration']['pmc_end_date_teen'] = array(
        '#title' => t('End date'),
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
    $form['program_configuration']['pmc_library_name_teen'] = array(
        '#type' => 'textfield',
        '#title' => 'Library Name',
    );
    $form['program_configuration']['pmc_progrm_image_teen'] = array(
      '#title' => t('Program Image'),
      '#type' => 'managed_file',
      '#description' => t('The uploaded image will be displayed on this page using the image style choosen below.'),
      '#upload_location' => 'public://',
    );

	$form['pmc_purchase_link_teen'] = array(
		'#type' => 'textfield',
		'#title' => 'Purchase Link',
		'#description' => 'Enter a valid url (https://www.example.com)',
		'#default_value' => variable_get('pmc_purchase_link_teen'),
	);

    $form['library_for_teen'] = array(
        '#type' => 'textfield',
        '#title' => 'Library Name',
        '#description' => 'Enter the Library name',
        '#default_value' => variable_get('library_for_teen'),
    );

    $form['library_abbreviation_for_teen'] = array(
        '#type' => 'textfield',
        '#title' => 'Abbreviation for Library Name',
        '#description' => 'Abbreviation for Library name',
        '#default_value' => variable_get('library_abbreviation_for_teen'),
    );

    $form['catalog_link_for_teen_program'] = array(
        '#type' => 'textfield',
        '#title' => 'Catalog link for review',
        //'#description' => 'Catalog link for review',
        '#default_value' => variable_get('catalog_link_for_teen_program'),
    );

	return system_settings_form($form);
}

// validation for purchase link form
function platform_configuration_purchase_link_teen_validate($form, &$form_state) {
	$purchase_link = $form_state['values']['pmc_purchase_link'];
    if(isset($purchase_link)){
    	if(filter_var($purchase_link, FILTER_VALIDATE_URL) === false) {
    		form_set_error('pmc_purchase_link','Please enter a valid URL');
    	}
    }
}
<?php

// Function callback for program details.
function platform_details_teen($form, &$form_state) {

  $form['program_details'] = array(
    '#type' => 'fieldset', 
    '#title' => t('Program Details'),
    '#collapsible' => TRUE, 
    '#collapsed' => FALSE,
  );
	$form['program_details']['pmc_purchase_link_teen'] = array(
		'#type' => 'textfield',
		'#title' => 'Purchase Link',
		'#description' => 'Enter a valid url (https://www.example.com) for Booklist purchase',
		'#default_value' => variable_get('pmc_purchase_link_teen'),
	);
  $form['program_details']['pmc_library_name_teen'] = array(
    '#type' => 'textfield',
    '#title' => 'Library Name',
    '#description' => 'Enter the Library name for the program',
    '#default_value' => variable_get('pmc_library_name_teen'),
  );
  $form['program_details']['library_abbreviation_for_teen'] = array(
    '#type' => 'textfield',
    '#title' => 'Abbreviation for Library Name',
    '#description' => 'Abbreviation for Library name',
    '#default_value' => variable_get('library_abbreviation_for_teen'),
  );
  $form['program_details']['catalog_link_for_teen_program'] = array(
    '#type' => 'textfield',
    '#title' => 'Catalog link for review',
    '#default_value' => variable_get('catalog_link_for_teen_program'),
  );

  $form['program_details']['review_pre_header'] = array(
    '#type' => 'textarea',
    '#title' => 'Header content for review pages',
    '#default_value' => variable_get('review_pre_header'),
  );

	return system_settings_form($form);
}

// validation for purchase link form
function platform_details_teen_validate($form, &$form_state) {
  $purchase_link = $form_state['values']['pmc_purchase_link_teen'];
  if(isset($purchase_link)){
    if(filter_var($purchase_link, FILTER_VALIDATE_URL) === false) {
      form_set_error('pmc_purchase_link_teen','Please enter a valid URL');
    }
  }
}
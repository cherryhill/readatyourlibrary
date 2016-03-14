<?php

// Function callback for purchase link form.
function platform_configuration_purchase_link($form, &$form_state) {
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
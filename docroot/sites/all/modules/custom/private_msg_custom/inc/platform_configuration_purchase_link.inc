<?php

// Function callback for purchase link form.
function platform_configuration_purchase_link($form, &$form_state) {
    $default_date = date('d/m/y');
    $program_start_date = variable_get('pmc_start_date', $default_date);
    $program_end_date = variable_get('pmc_end_date', $default_date);

    $form['program_configuration'] = array(
      '#type' => 'fieldset', 
      '#title' => t('Program Configuration'),
      '#collapsible' => TRUE, 
      '#collapsed' => FALSE,

    );
    $form['program_configuration']['pmc_start_date'] = array(
        '#title' => t('Start date'),
        '#type' => 'date_popup',
        '#date_format' => 'F d, Y',
        '#date_year_range' => '0:+10',
        '#required' => TRUE,
        '#size' => 8,
        '#default_value' => $program_start_date,
    );
    $form['program_configuration']['pmc_end_date'] = array(
        '#title' => t('End date'),
        '#type' => 'date_popup',
        '#date_format' => 'F d, Y',
        '#date_year_range' => '0:+10',
        '#required' => TRUE,
        '#size' => 8,
        '#default_value' => $program_end_date,
    );
    $form['program_configuration']['pmc_program_name'] = array(
        '#type' => 'textfield',
        '#title' => 'Program Name',
    );
    $form['program_configuration']['pmc_progrm_image'] = array(
      '#title' => t('Program Image'),
      '#type' => 'managed_file',
      '#description' => t('The uploaded image will be displayed on this page using the image style choosen below.'),
      '#upload_location' => 'public://',
       '#default_value' => variable_get('pmc_progrm_image'),
    );

	$form['pmc_purchase_link'] = array(
		'#type' => 'textfield',
		'#title' => 'Purchase Link',
		'#description' => 'Enter a valid url (https://www.example.com)',
		'#default_value' => variable_get('pmc_purchase_link'),
	);

	$form['follow_author'] = array(
		'#title' => t('Author for follow message'),
		'#type' => 'textfield',
		'#autocomplete_path' => 'author/autocomplete',
		'#default_value' => variable_get('follow_author'),
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

// function for providing autocomplete for users
function _author_name_autocomplete($string = ''){
	$author_users = array();
  $sname_query = db_select('users','u');
  $sname_query->condition('u.name', '%' . db_like($string) . '%', 'LIKE');
  $sname_query->fields('u',array('name'));
  $sname_query->range(0, 15);

  $sname_result = $sname_query->execute()->fetchAll();

  foreach($sname_result as $res){
    $author_users[$res->name] = check_plain($res->name);
  }

 drupal_json_output($author_users);
}
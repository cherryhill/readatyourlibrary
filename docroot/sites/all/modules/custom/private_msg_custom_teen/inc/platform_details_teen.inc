<?php

// Function callback for program details.
function platform_details_teen($form, &$form_state) {

  $form['program_details'] = array(
    '#type' => 'fieldset', 
    '#title' => t('Program Details'),
    '#collapsible' => TRUE, 
    '#collapsed' => TRUE,
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

  $form['announcement_block_details'] = array(
    '#type' => 'fieldset', 
    '#title' => t('Announcement block'),
    '#collapsible' => TRUE, 
    '#collapsed' => TRUE,
  );

  $form['announcement_block_details']['title_announcement'] = array(
    '#type' => 'textfield',
    '#title' => t('Title for the block'),
    '#default_value' => variable_get('title_announcement'),
  );

  $form['activities_landing_page_details'] = array(
    '#type' => 'fieldset', 
    '#title' => t('Activities Landing Page Details'),
    //'#description' => 'Bay Area Hotspot Activities block deatils',
    '#collapsible' => TRUE, 
    '#collapsed' => TRUE,
  );

  $form['activities_landing_page_details']['hotspot_activities_block'] = array(
    '#type' => 'fieldset', 
    '#title' => t('Hotspot Activities block'),
    '#description' => 'Bay Area Hotspot Activities block deatils',
    '#collapsible' => TRUE, 
    '#collapsed' => TRUE,
  );

  $form['activities_landing_page_details']['hotspot_activities_block']['hotspot_block_title'] = array(
    '#type' => 'textfield',
    '#title' => t('Title for the block'),
    '#default_value' => variable_get('hotspot_block_title'),
  );

  $form['activities_landing_page_details']['hotspot_activities_block']['hotspot_block_description'] = array(
    '#type' => 'textarea',
    '#title' => t('Description'),
    '#default_value' => variable_get('hotspot_block_description'),
  );

  $form['activities_landing_page_details']['hotspot_activities_block']['hotspot_block_link'] = array(
    '#type' => 'textfield',
    '#title' => t('Suggest a New Activity Form Link'),
    '#description' => 'This will link to the Suggest a New Activity Form <br/> Enter a valid url (https://www.example.com).',
    '#default_value' => variable_get('hotspot_block_link'),
  );

  $form['activities_landing_page_details']['hotspot_activities_block']['hotspot_block_link_title'] = array(
    '#type' => 'textfield',
    '#title' => t('Title for the Link'),
    '#default_value' => variable_get('hotspot_block_link_title'),
  );

  $form['activities_landing_page_details']['review_activities_block'] = array(
    '#type' => 'fieldset', 
    '#title' => t('Review Activities block'),
    '#description' => 'Review Activity block deatils',
    '#collapsible' => TRUE, 
    '#collapsed' => TRUE,
  );

  $form['activities_landing_page_details']['review_activities_block']['review_activity_block_title'] = array(
    '#type' => 'textfield',
    '#title' => t('Title for the block'),
    '#default_value' => variable_get('review_activity_block_title'),
  );

  $form['activities_landing_page_details']['review_activities_block']['review_activity_block_description'] = array(
    '#type' => 'textarea',
    '#title' => t('Description'),
    '#default_value' => variable_get('review_activity_block_description'),
  );

  $form['activities_landing_page_details']['static_block_one'] = array(
    '#type' => 'fieldset', 
    '#title' => t('Static Block One'),
    '#collapsible' => TRUE, 
    '#collapsed' => TRUE,
  );

  $form['activities_landing_page_details']['static_block_one']['static_block_one_title'] = array(
    '#type' => 'textfield',
    '#title' => t('Title for the Activity'),
    '#default_value' => variable_get('static_block_one_title'),
  );

  $form['activities_landing_page_details']['static_block_one']['static_block_one_title_link'] = array(
    '#type' => 'textfield',
    '#title' => t('Link for the title'),
    '#default_value' => variable_get('static_block_one_title_link'),
  );

  $desc_block_one = variable_get('static_block_one_description', array('value' => '', 'format' => NULL));
  $form['activities_landing_page_details']['static_block_one']['static_block_one_description'] = array(
    '#type' => 'text_format',
    '#title' => t('Description for the activity'),
    '#default_value' => $desc_block_one['value'],
    '#format' => $desc_block_one['format'],
  );

  $form['activities_landing_page_details']['static_block_two'] = array(
    '#type' => 'fieldset', 
    '#title' => t('Static Block Two'),
    '#collapsible' => TRUE, 
    '#collapsed' => TRUE,
  );

  $form['activities_landing_page_details']['static_block_two']['static_block_two_title'] = array(
    '#type' => 'textfield',
    '#title' => t('Title for the Activity'),
    '#default_value' => variable_get('static_block_two_title'),
  );

  $form['activities_landing_page_details']['static_block_two']['static_block_two_title_link'] = array(
    '#type' => 'textfield',
    '#title' => t('Link for the title'),
    '#default_value' => variable_get('static_block_two_title_link'),
  );

  $desc_block_two = variable_get('static_block_two_description', array('value' => '', 'format' => NULL));
  $form['activities_landing_page_details']['static_block_two']['static_block_two_description'] = array(
    '#type' => 'text_format',
    '#title' => t('Description for the activity'),
    '#default_value' => $desc_block_two['value'],
    '#format' => $desc_block_two['format'],
  );

  $form['activities_landing_page_details']['static_block_three'] = array(
    '#type' => 'fieldset', 
    '#title' => t('Static Block Three'),
    '#collapsible' => TRUE, 
    '#collapsed' => TRUE,
  );

  $form['activities_landing_page_details']['static_block_three']['static_block_three_title'] = array(
    '#type' => 'textfield',
    '#title' => t('Title for the Activity'),
    '#default_value' => variable_get('static_block_three_title'),
  );

  $form['activities_landing_page_details']['static_block_three']['static_block_three_title_link'] = array(
    '#type' => 'textfield',
    '#title' => t('Link for the title'),
    '#default_value' => variable_get('static_block_three_title_link'),
  );

  $desc_block_three = variable_get('static_block_three_description', array('value' => '', 'format' => NULL));
  $form['activities_landing_page_details']['static_block_three']['static_block_three_description'] = array(
    '#type' => 'text_format',
    '#title' => t('Description for the activity'),
    '#default_value' => $desc_block_three['value'],
    '#format' => $desc_block_three['format'],
  );


	return system_settings_form($form);
}

// validation for purchase link form
if(isset($purchase_link)){
  function platform_details_teen_validate($form, &$form_state) {
    $purchase_link = $form_state['values']['pmc_purchase_link_teen'];
    if(filter_var($purchase_link, FILTER_VALIDATE_URL) === false) {
      form_set_error('pmc_purchase_link_teen','Please enter a valid URL');
    }
  }
}
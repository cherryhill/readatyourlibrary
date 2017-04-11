<?php

// // Function callback for program details.
// function pl_platform_details($form, &$form_state) {

//   $form['program_details'] = array(
//     '#type' => 'fieldset',
//     '#title' => t('Program Details'),
//     '#collapsible' => TRUE, 
//     '#collapsed' => TRUE,
//   );
//   $form['program_details']['email_description_field'] = array(
//     '#type' => 'textarea',
//     '#title' => t('Email Description Text'),
//     '#description' => t('Description provided for email field showed during registration'),
//     '#default_value' => variable_get('email_description_field'),
//   );
//   $form['program_details']['pmc_purchase_link'] = array(
//     '#type' => 'textfield',
//     '#title' => t('Purchase Link'),
//     '#description' => t('Enter a valid url (https://www.example.com) for Booklist purchase'),
//     '#default_value' => variable_get('pmc_purchase_link'),
//   );
//   $form['program_details']['pmc_library_name'] = array(
//     '#type' => 'textfield',
//     '#title' => t('Library Name'),
//     '#description' => t('Enter the Library name for the program'),
//     '#default_value' => variable_get('pmc_library_name'),
//   );
//   $form['program_details']['library_abbreviation'] = array(
//     '#type' => 'textfield',
//     '#title' => t('Abbreviation for Library Name'),
//     '#description' => t('Abbreviation for Library name'),
//     '#default_value' => variable_get('library_abbreviation'),
//   );
//   $form['program_details']['catalog_link_for_program'] = array(
//     '#type' => 'textfield',
//     '#title' => t('Catalog link for review'),
//     '#default_value' => variable_get('catalog_link_for_program'),
//   );

//   $form['program_details']['review_pre_header'] = array(
//     '#type' => 'textarea',
//     '#title' => t('Header content for review pages'),
//     '#default_value' => variable_get('review_pre_header'),
//   );

//   $form['announcement_block_details'] = array(
//     '#type' => 'fieldset', 
//     '#title' => t('Announcement block'),
//     '#collapsible' => TRUE, 
//     '#collapsed' => TRUE,
//   );

//   $form['announcement_block_details']['title_announcement'] = array(
//     '#type' => 'textfield',
//     '#title' => t('Title for the block'),
//     '#default_value' => variable_get('title_announcement'),
//   );

//   $form['activities_landing_page_details'] = array(
//     '#type' => 'fieldset', 
//     '#title' => t('Activities Landing Page Details'),
//     //'#description' => t('Bay Area Hotspot Activities block deatils'),
//     '#collapsible' => TRUE, 
//     '#collapsed' => TRUE,
//   );

//   $form['activities_landing_page_details']['hotspot_activities_block'] = array(
//     '#type' => 'fieldset', 
//     '#title' => t('Hotspot Activities block'),
//     '#description' => t('Bay Area Hotspot Activities block deatils'),
//     '#collapsible' => TRUE, 
//     '#collapsed' => TRUE,
//   );

//   $form['activities_landing_page_details']['hotspot_activities_block']['hotspot_block_title'] = array(
//     '#type' => 'textfield',
//     '#title' => t('Title for the block'),
//     '#default_value' => variable_get('hotspot_block_title'),
//   );

//   $form['activities_landing_page_details']['hotspot_activities_block']['hotspot_block_description'] = array(
//     '#type' => 'textarea',
//     '#title' => t('Description'),
//     '#default_value' => variable_get('hotspot_block_description'),
//   );

//   $form['activities_landing_page_details']['hotspot_activities_block']['hotspot_block_link'] = array(
//     '#type' => 'textfield',
//     '#title' => t('Suggest a New Activity Form Link'),
//     '#description' => t('This will link to the Suggest a New Activity Form <br/> Enter a valid url (https://www.example.com).'),
//     '#default_value' => variable_get('hotspot_block_link'),
//   );

//   $form['activities_landing_page_details']['hotspot_activities_block']['hotspot_block_link_title'] = array(
//     '#type' => 'textfield',
//     '#title' => t('Title for the Link'),
//     '#default_value' => variable_get('hotspot_block_link_title'),
//   );

//   $form['activities_landing_page_details']['review_activities_block'] = array(
//     '#type' => 'fieldset', 
//     '#title' => t('Review Activities block'),
//     '#description' => t('Review Activity block deatils'),
//     '#collapsible' => TRUE, 
//     '#collapsed' => TRUE,
//   );

//   $form['activities_landing_page_details']['review_activities_block']['review_activity_block_title'] = array(
//     '#type' => 'textfield',
//     '#title' => t('Title for the block'),
//     '#default_value' => variable_get('review_activity_block_title'),
//   );

//   $form['activities_landing_page_details']['review_activities_block']['review_activity_block_description'] = array(
//     '#type' => 'textarea',
//     '#title' => t('Description'),
//     '#default_value' => variable_get('review_activity_block_description'),
//   );

//   $form['activities_landing_page_details']['static_block_one'] = array(
//     '#type' => 'fieldset', 
//     '#title' => t('Static Block One'),
//     '#collapsible' => TRUE, 
//     '#collapsed' => TRUE,
//   );

//   $form['activities_landing_page_details']['static_block_one']['static_block_one_title'] = array(
//     '#type' => 'textfield',
//     '#title' => t('Title for the Activity'),
//     '#default_value' => variable_get('static_block_one_title'),
//   );

//   $form['activities_landing_page_details']['static_block_one']['static_block_one_title_link'] = array(
//     '#type' => 'textfield',
//     '#title' => t('Link for the title'),
//     '#default_value' => variable_get('static_block_one_title_link'),
//   );

//   $desc_block_one = variable_get('static_block_one_description', array('value' => '', 'format' => NULL));
//   $form['activities_landing_page_details']['static_block_one']['static_block_one_description'] = array(
//     '#type' => 'text_format',
//     '#title' => t('Description for the activity'),
//     '#default_value' => $desc_block_one['value'],
//     '#format' => $desc_block_one['format'],
//   );

//   $form['activities_landing_page_details']['static_block_two'] = array(
//     '#type' => 'fieldset', 
//     '#title' => t('Static Block Two'),
//     '#collapsible' => TRUE, 
//     '#collapsed' => TRUE,
//   );

//   $form['activities_landing_page_details']['static_block_two']['static_block_two_title'] = array(
//     '#type' => 'textfield',
//     '#title' => t('Title for the Activity'),
//     '#default_value' => variable_get('static_block_two_title'),
//   );

//   $form['activities_landing_page_details']['static_block_two']['static_block_two_title_link'] = array(
//     '#type' => 'textfield',
//     '#title' => t('Link for the title'),
//     '#default_value' => variable_get('static_block_two_title_link'),
//   );

//   $desc_block_two = variable_get('static_block_two_description', array('value' => '', 'format' => NULL));
//   $form['activities_landing_page_details']['static_block_two']['static_block_two_description'] = array(
//     '#type' => 'text_format',
//     '#title' => t('Description for the activity'),
//     '#default_value' => $desc_block_two['value'],
//     '#format' => $desc_block_two['format'],
//   );

//   $form['activities_landing_page_details']['static_block_three'] = array(
//     '#type' => 'fieldset', 
//     '#title' => t('Static Block Three'),
//     '#collapsible' => TRUE, 
//     '#collapsed' => TRUE,
//   );

//   $form['activities_landing_page_details']['static_block_three']['static_block_three_title'] = array(
//     '#type' => 'textfield',
//     '#title' => t('Title for the Activity'),
//     '#default_value' => variable_get('static_block_three_title'),
//   );

//   $form['activities_landing_page_details']['static_block_three']['static_block_three_title_link'] = array(
//     '#type' => 'textfield',
//     '#title' => t('Link for the title'),
//     '#default_value' => variable_get('static_block_three_title_link'),
//   );

//   $desc_block_three = variable_get('static_block_three_description', array('value' => '', 'format' => NULL));
//   $form['activities_landing_page_details']['static_block_three']['static_block_three_description'] = array(
//     '#type' => 'text_format',
//     '#title' => t('Description for the activity'),
//     '#default_value' => $desc_block_three['value'],
//     '#format' => $desc_block_three['format'],
//   );
  
//   return system_settings_form($form);
// }

// validation for purchase link form
if(isset($purchase_link)){
  function pl_platform_details_validate($form, &$form_state) {
    $purchase_link = $form_state['values']['pmc_purchase_link'];
    if(filter_var($purchase_link, FILTER_VALIDATE_URL) === false) {
      form_set_error('pmc_purchase_link',t('Please enter a valid URL'));
    }
  }
}
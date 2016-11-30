<?php

// Function callback for program details.
function pl_platform_details($form, &$form_state) {

  $form['program_details'] = array(
    '#type' => 'fieldset', 
    '#title' => t('Program Details'),
    '#collapsible' => TRUE, 
    '#collapsed' => TRUE,
  );
  $form['program_details']['email_description_field'] = array(
    '#type' => 'textarea',
    '#title' => t('Email Description Text'),
    '#description' => t('Description provided for email field showed during registration'),
    '#default_value' => variable_get('email_description_field'),
  );
  $form['program_details']['pmc_purchase_link'] = array(
    '#type' => 'textfield',
    '#title' => t('Purchase Link'),
    '#description' => t('Enter a valid url (https://www.example.com) for Booklist purchase'),
    '#default_value' => variable_get('pmc_purchase_link'),
  );
  $form['program_details']['pmc_library_name'] = array(
    '#type' => 'textfield',
    '#title' => t('Library Name'),
    '#description' => t('Enter the Library name for the program'),
    '#default_value' => variable_get('pmc_library_name'),
  );
  $form['program_details']['library_abbreviation'] = array(
    '#type' => 'textfield',
    '#title' => t('Abbreviation for Library Name'),
    '#description' => t('Abbreviation for Library name'),
    '#default_value' => variable_get('library_abbreviation'),
  );
  $form['program_details']['catalog_link_for_program'] = array(
    '#type' => 'textfield',
    '#title' => t('Catalog link for review'),
    '#default_value' => variable_get('catalog_link_for_program'),
  );

  $form['program_details']['review_pre_header'] = array(
    '#type' => 'textarea',
    '#title' => t('Header content for review pages'),
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
    //'#description' => t('Bay Area Hotspot Activities block deatils'),
    '#collapsible' => TRUE, 
    '#collapsed' => TRUE,
  );

  $form['activities_landing_page_details']['hotspot_activities_block'] = array(
    '#type' => 'fieldset', 
    '#title' => t('Hotspot Activities block'),
    '#description' => t('Bay Area Hotspot Activities block deatils'),
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
    '#description' => t('This will link to the Suggest a New Activity Form <br/> Enter a valid url (https://www.example.com).'),
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
    '#description' => t('Review Activity block deatils'),
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

  $form['progress_page'] = array(
    '#type' => 'fieldset', 
    '#title' => t('Progress Page Details'),
    '#collapsible' => TRUE, 
    '#collapsed' => TRUE,
  );


  $form['progress_page']['progress_details'] = array(
    '#type' => 'fieldset', 
    '#title' => t('Progress page details page'),
    '#collapsible' => TRUE, 
    '#collapsed' => TRUE,
  );

  $form['progress_page']['progress_details']['pg_title'] = array(
    '#type' => 'textfield', 
    '#title' => t('Progress page title'),
    '#default_value' => variable_get('pg_title') ? variable_get('pg_title') : 'Progress',
  );

  $form['progress_page']['progress_details']['pg_startdate'] = array(
    '#title' => t('Start Date'),
    '#type' => 'date_popup',
    '#date_format' => 'd/m/Y',
    '#date_year_range' => '0:+10',
    '#required' => TRUE,
    '#size' => 8,
    '#default_value' => variable_get('pg_startdate'),
  );

  $form['progress_page']['progress_details']['pg_enddate'] = array(
    '#title' => t('End Date'),
    '#type' => 'date_popup',
    '#date_format' => 'd/m/Y',
    '#date_year_range' => '0:+10',
    '#required' => TRUE,
    '#size' => 8,
    '#default_value' => variable_get('pg_enddate'),
  );

  $progress_details_desc = variable_get('pg_desc', array('value' => '', 'format' => NULL));
  $form['progress_page']['progress_details']['pg_desc'] = array(
    '#type' => 'text_format', 
    '#title' => t('Progress page description'),
    '#default_value' => $progress_details_desc['value'],
    '#format' => $progress_details_desc['format'],
  );

  $rewardMsg = variable_get('reward_msg', array('value' => '', 'format' => NULL));
  $form['progress_page']['progress_details']['reward_msg'] = array(
    '#type' => 'text_format', 
    '#title' => t('Reward Message'),
    '#default_value' => $rewardMsg['value'],
    '#format' => $rewardMsg['format'],
  );

  $form['progress_page']['progress_details']['progress_img'] = array(
    '#title' => t('Image for Activity Completion'),
    '#type' => 'managed_file',
    '#description' => t('The uploaded image will be displayed on this page using the image style choosen below.'),
    '#upload_location' => 'public://',
    '#default_value' => variable_get('progress_img'),
  );

  $form['progress_page']['progress_details']['no_of_grids'] = array(
    '#type' => 'textfield', 
    '#title' => t('No of grids needed for progress page'),
    '#default_value' => variable_get('no_of_grids') ? variable_get('no_of_grids') : 18,
  );

  $options_self = pl_activities_view_select_option();
  if (isset($options_self)) {
    $form['progress_page']['progress_details']['activities_progress'] = array(
      '#title' => t('Self Reported Activities for progress page'),
      '#description' => t('Check activities to be shown on progress page'),
      '#type' => 'checkboxes',  
      '#options' => $options_self,
      '#default_value' => variable_get('activities_progress'),
    );
  } else {
    $form['progress_page']['progress_details']['activities_progress_no'] = array(
      '#prefix' => t('<div><b>Activities for progress page.</b></div>'),
      '#type' => 'markup',  
      '#markup' => 'No Activities',
    );
  }

  $options_nonSelf = pl_activities_view_select_option_nonSelf();
  if (isset($options_self)) {
    $form['progress_page']['progress_details']['nonself_activities_progress'] = array(
      '#title' => t('Non Self Reported Activities for progress page'),
      '#description' => t('Check activities to be shown on progress page'),
      '#type' => 'checkboxes',  
      '#options' => $options_nonSelf,
      '#default_value' => variable_get('nonself_activities_progress'),
    );
  } else {
    $form['progress_page']['progress_details']['nonself_activities_progress_no'] = array(
      '#prefix' => t('<div><b>Non Self Reported Activities for progress page.</b></div>'),
      '#type' => 'markup',  
      '#markup' => 'No Activities',
    );
  }

  $form['progress_page']['progress_block'] = array(
    '#type' => 'fieldset', 
    '#title' => t('Report Progress Block Details'),
    '#collapsible' => TRUE, 
    '#collapsed' => TRUE,
  );

  $report_block_text = variable_get('report_block_desc', array('value' => '', 'format' => NULL));
  $form['progress_page']['progress_block']['report_block_desc'] = array(
    '#type' => 'text_format', 
    '#title' => t('Text for Report an Activity block'),
    '#default_value' => $report_block_text['value'],
    '#format' => $report_block_text['format'],
  );

  $form['progress_page']['rewards_block'] = array(
    '#type' => 'fieldset', 
    '#title' => t('Rewards'),
    '#collapsible' => TRUE, 
    '#collapsed' => TRUE,
  );

  $progress_rewards_text = variable_get('progress_rewards', array('value' => '', 'format' => NULL));
  $form['progress_page']['rewards_block']['progress_rewards'] = array(
    '#type' => 'text_format', 
    '#title' => t('Text for Rewards block'),
    '#default_value' => $progress_rewards_text['value'],
    '#format' => $progress_rewards_text['format'],
  );
  
  return system_settings_form($form);
}

// validation for purchase link form
if(isset($purchase_link)){
  function pl_platform_details_validate($form, &$form_state) {
    $purchase_link = $form_state['values']['pmc_purchase_link'];
    if(filter_var($purchase_link, FILTER_VALIDATE_URL) === false) {
      form_set_error('pmc_purchase_link',t('Please enter a valid URL'));
    }
  }
}
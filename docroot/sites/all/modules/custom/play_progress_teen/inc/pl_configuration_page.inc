<?php

function pl_configuration_progress($form, &$form_state) {

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

	// $form['progress_page']['progress_details']['pg_startdate'] = array(
	//   '#title' => t('Start Date'),
	//   '#type' => 'date_popup',
	//   '#date_format' => 'm.d.Y',
	//   '#date_year_range' => '0:+10',
	//   '#required' => TRUE,
	//   '#size' => 8,
	//   '#default_value' => variable_get('pg_startdate'),
	// );

	// $form['progress_page']['progress_details']['pg_enddate'] = array(
	//   '#title' => t('End Date'),
	//   '#type' => 'date_popup',
	//   '#date_format' => 'm/d/Y',
	//   '#date_year_range' => '0:+10',
	//   '#required' => TRUE,
	//   '#size' => 8,
	//   '#default_value' => variable_get('pg_enddate'),
	// );

	$progress_details_desc = variable_get('pg_desc', array('value' => '', 'format' => NULL));
	$form['progress_page']['progress_details']['pg_desc'] = array(
	  '#type' => 'text_format', 
	  '#title' => t('Progress page description'),
	  '#default_value' => $progress_details_desc['value'],
	  '#format' => $progress_details_desc['format'],
	);

	$form['progress_page']['progress_details']['reward_msg'] = array(
	  '#type' => 'textarea', 
	  '#title' => t('Reward Message'),
	  '#default_value' => variable_get('reward_msg'),
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


<?php

/**
 * function callback for progress page
 */
function progress_report_grid(){
	
  drupal_add_js( drupal_get_path('module', 'private_msg_custom_teen') . '/js/private_msg_custom_teen.js');
  return theme('progress-report');
}

/**
 * template for progress page
 */
function private_msg_custom_teen_theme(){

  $templates = array(
   'progress-report' => array(
    'template' => 'templates/progress_page',
  ));

  return $templates;
}
/**
 * ajax callback for progress page
 */

function ajax_call_progress(){
	global $user;
	$test = $user->uid;

	$aid = $_POST['id'];
	$date = $_POST['date'];

	activity_custom_node_insert($aid);

	$output = $aid.' '.$date;
	$found = true;           
  echo json_encode(array('success' => $found, 'content' => $output));
 
  module_invoke_all('exit');
  exit;
}

function progress_record($form,$form_state){

 	$form['activity_progress_select'] = array(
	  '#title' => t('I completed'),
	  '#type' => 'select',
	  '#options' => activities_view_select_option('hotspot_activities','1'),
	  '#attributes' => array(
	    'class' => array('activities_list_progress')
	  ),
	  '#weight' => 1,
	);

  $form['date'] = array(
    '#type' => 'date_popup', 
  	'#title' => 'on',
    '#date_format' => 'Y-m-d',
    '#date_year_range' => '-0:+1',
  	'#weight' => 2, 
  );
	return $form;
}

function activity_custom_node_insert($term_tid,$date){

	global $user;
	$current_user = $user->uid;

	$activity_term = taxonomy_term_load($term_tid); //103

	$firing_hook_name = $activity_term->name;
	$activity_tid = $activity_term->tid;
	$activity_id = $activity_term->field_activity_id['und'][0]['value'];
	$hotspot_activity_type = $activity_term->field_hotspot_activity_type['und'][0]['value'];
	$activity_progress_status = $activity_term->field_progress_page_term['und'][0]['value'];

	$node = new stdClass(); // Creating a new node object
	$node->type = 'activity_report'; //Content type
	$node->language = LANGUAGE_NONE;
	node_object_prepare($node);

	$node->title = $firing_hook_name;
	$node->status = 1;
	$node->uid = $current_user;
	$node->field_activity_id_report[LANGUAGE_NONE][0]['value'] = $activity_id;
	$node->field_name_of_firing_hook[LANGUAGE_NONE][0]['value'] = $firing_hook_name;
	$node->field_term_id[LANGUAGE_NONE][0]['value'] = $activity_tid;
	$node->field_hotspot_activity_report[LANGUAGE_NONE][0]['value'] = $hotspot_activity_type;
	$node->field_show_on_progress_report[LANGUAGE_NONE][0]['value'] = $activity_progress_status;
	$node->field_completion_date[LANGUAGE_NONE][0]['value'] = $date;
	node_save($node);
}

function user_avatar_progress_page(){
	global $user;
	$user_pf = profile2_load_by_user($user->uid);
	$user_main = user_load(430);

	$img_id = $user_pf['main']->field_user_avatar['und'][0]['target_id'];
	$user_name = $user_main->name;

	$query = db_select('field_data_field_avatar_image', 't');
	$query->join('file_managed', 'n', 'n.fid = t.field_avatar_image_fid');
	$result = $query
	  ->fields('n', array('uri'))
	  ->condition('t.entity_id', $img_id)
	  ->execute();

	$img_uri = $result->fetchObject();
	$img_uri = $img_uri->uri;
	$style = 'avatar_dashboard';
	$img_path = image_style_url($style, $img_uri);

	$img = "<img src='$img_path'>";

	$privacy = $data->_field_data['nid']['entity'];
	$privacy_key = $privacy->field_please_select_one[LANGUAGE_NONE][0]['value'];

	return $img.$user_name;
}


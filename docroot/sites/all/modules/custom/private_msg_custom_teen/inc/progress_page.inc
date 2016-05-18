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
function complete_activity_progress(){
	global $user;
	$activity_uid = $user->uid;

	$tid = $_POST['id'];
	$activity_date = $_POST['date'];

	$activity_term = taxonomy_term_load($tid);

	$activity_id = $activity_term->field_activity_id['und'][0]['value'];
	activity_report_node_create($activity_id, $activity_date, $tid);

	play_library_program_create_activity_entry($activity_id,$activity_uid);

	$output = $activity_id.' '.$activity_date;
	$found = true;           
  json_encode(array('success' => $found, 'content' => $output));
 
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

function activity_report_node_create($activity_id, $activity_date, $term_tid, $check_in_progress = 0) {

	$entity_info = entity_load('activity', array($activity_id));
	$activity_name = $entity_info[$activity_id]->field_activity_description['und'][0]['safe_value'];
	$hotspot_activity_type = $entity_info[$activity_id]->field_hotspot_activity['und'][0]['value'];
	$activity_progress_status = $entity_info[$activity_id]->field_show_on_progress_page['und'][0]['value'];
  $_SESSION['progress_activity_id']= $activity_id;

  // check activity 'show in progress' status
  if($check_in_progress) {
  	if(!$activity_progress_status) {
  	  return FALSE;
    }
  }
  
  // if show in progress is one, node is created.
		global $user;
		$current_user = $user->uid;

		$node = new stdClass(); // Creating a new node object
		$node->type = 'activity_report'; //Content type
		$node->language = LANGUAGE_NONE;
		node_object_prepare($node);
		$node->title = $activity_name;
		$node->status = 1;
		$node->uid = $current_user;
		$node->field_activity_id_report[LANGUAGE_NONE][0]['value'] = $activity_id;
		$node->field_hotspot_activity_report[LANGUAGE_NONE][0]['value'] = $hotspot_activity_type;
		$node->field_show_on_progress_report[LANGUAGE_NONE][0]['value'] = $activity_progress_status;
		$node->field_term_id[LANGUAGE_NONE][0]['value'] = $term_tid;
		$node->field_completion_date[LANGUAGE_NONE][0]['value'] = $activity_date;
		node_save($node);
		; 
    // $node = node_load(495);//495
    // $hook = "node_update|node|{$node->type}|updated";
    // _play_library_program_invoke_activity_entry_hooks($node, 'node', $hook, 1);
	  return $created_nid = $node->nid;
}

function user_avatar_progress_page($uid){
	global $user;
	$user_pf = profile2_load_by_user($user->uid);
	$user_main = user_load($uid);

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


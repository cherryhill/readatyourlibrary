<?php

/**
 * function callback for options in select list for hotspot activities
 */
function activities_view_select_list($term,$activity,$progress) {

	global $base_url;
	$voc = taxonomy_vocabulary_machine_name_load($term);
	$activity_term_vid = $voc->vid;
	$activities_terms = taxonomy_get_tree($activity_term_vid);

	foreach ($activities_terms as $key => $value) {
		$term_title = $value->name;
		$term_tid = $value->tid;
		$activity_term = taxonomy_term_load($term_tid);

		if($activity_term->field_hotspot_activity_type['und'][0]['value'] == $activity){
			$select_options[0] = 'Select from the following';
			$select_options[$base_url.'/activities-listing/'.$term_tid] .= $term_title;
		}else if($activity_term->field_progress_page_term['und'][0]['value'] == $progress){
			$select_options[0] = 'Select from the following';
			$select_options[$base_url.'/activities-listing/'.$term_tid] .= $term_title;
			$select_opt[$term_tid] .= $term_title;
		}
	}
	return $select_options;
}

function activities_submit_select_list($term,$activity) {

	global $base_url;
	$voc = taxonomy_vocabulary_machine_name_load($term);
	$activity_term_vid = $voc->vid;
	$activities_terms = taxonomy_get_tree($activity_term_vid);

	foreach ($activities_terms as $key => $value) {
		$term_title = $value->name;
		$term_tid = $value->tid;
		$activity_term = taxonomy_term_load($term_tid);

		if($activity_term->field_hotspot_activity_type['und'][0]['value'] == $activity){
			$select_options[0] = 'Select from the following';
			$select_options[$base_url.'/node/add/review-activity/'.$term_tid] .= $term_title;
		}
	}
	return $select_options;
}


/**
 * function callback for adding taxonomny terms for hotspot activities
 */

function adding_taxonomy_term_hotspot_activities($form, &$form_state){

	drupal_set_message("Its working !!");
}

/**
 * function callback for Activities landing page
 */
function activities_page(){

	$block_one_link = variable_get('static_block_one_title_link');
	$block_one_title = variable_get('static_block_one_title');

	if(!empty($block_one_link)){
		$title_block_one = "<a href = '$block_one_link' target='_blank'>".$block_one_title."</a>";
	}else{
		$title_block_one = $block_one_title;
	}
	$form['block_one_title'] = array(
		'#type' => 'markup',
		'#markup' => $title_block_one,
		'#prefix' => '<div class="block-one-title">',
 		'#suffix' => '</div>',
		'#weight' => 1,
	);

	$desc_block_one = variable_get('static_block_one_description', array('value' => '', 'format' => NULL));
	$form['block_one_description'] = array(
	  '#type' => 'markup',
	 	'#markup' => $desc_block_one['value'],
	 	'#prefix' => '<div class="block-one-description">',
	 	'#suffix' => '</div>',
	 	'#weight' => 2,
	);

	$block_two_link = variable_get('static_block_two_title_link');
	$block_two_title = variable_get('static_block_two_title');

	if(!empty($block_two_link)){
		$title_block_two = "<a href = '$block_two_link' target='_blank'>".$block_two_title."</a>";
	}else{
		$title_block_two = $block_two_title;
	}
	$form['block_two_title'] = array(
		'#type' => 'markup',
		'#markup' => $title_block_two,
		'#prefix' => '<div class="block-two-title">',
 		'#suffix' => '</div>',
		'#weight' => 3,
	);
	
	$desc_block_two = variable_get('static_block_two_description', array('value' => '', 'format' => NULL));
	$form['block_two_description'] = array(
	  '#type' => 'markup',
	 	'#markup' => $desc_block_two['value'],
	 	'#prefix' => '<div class="block-two-description">',
	 	'#suffix' => '</div>',
	 	'#weight' => 4,
	);

	$block_three_link = variable_get('static_block_three_title_link');
	$block_three_title = variable_get('static_block_three_title');

	if(!empty($block_three_link)){
		$title_block_three = "<a href = '$block_three_link' target='_blank'>".$block_three_title."</a>";
	}else{
		$title_block_three = $block_three_title;
	}
	$form['block_three_title'] = array(
		'#type' => 'markup',
		'#markup' => $title_block_three,
		'#prefix' => '<div class="block-three-title">',
 		'#suffix' => '</div>',
		'#weight' => 5,
	);
	
	$desc_block_one = variable_get('static_block_three_description', array('value' => '', 'format' => NULL));
	$form['block_three_description'] = array(
	  '#type' => 'markup',
	 	'#markup' => $desc_block_one['value'],
	 	'#prefix' => '<div class="block-three-description">',
	 	'#suffix' => '</div>',
	 	'#weight' => 6,
	);
	return $form;
}
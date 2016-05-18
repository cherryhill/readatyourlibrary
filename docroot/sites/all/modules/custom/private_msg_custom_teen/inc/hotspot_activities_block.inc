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

function activities_view_select_option($term,$progress) {

	global $base_url;
	$voc = taxonomy_vocabulary_machine_name_load($term);
	$activity_term_vid = $voc->vid;
	$activities_terms = taxonomy_get_tree($activity_term_vid);

	foreach ($activities_terms as $key => $value) {
		$term_title = $value->name;
		$term_tid = $value->tid;
		$activity_term = taxonomy_term_load($term_tid);

	if($activity_term->field_progress_page_term['und'][0]['value'] == $progress){
			$select_options[$term_tid] .= $term_title;
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
 * function for saving taxonomy term on creation of activity.
 */
function activities_term_save($term,$fire_hook,$activity) {

  $voc = taxonomy_vocabulary_machine_name_load($term);
  $activity_term_vid = $voc->vid;
  $activity_id = $activity->id;
  $activity_title = $activity->title;
  $activity_hotspot_value = $activity->field_hotspot_activity['und'][0]['value'];
  $activity_firehook = $activity->field_activity_fired_hook['und'][0]['value'];
  $activity_progress_page = $activity->field_show_on_progress_page['und'][0]['value'];

  $query = db_select('field_data_field_activity_id','activity_id')
  	->fields('activity_id',array('field_activity_id_value','entity_id'))
  	->condition('field_activity_id_value',$activity_id)
  	->execute()
  	->fetchAssoc();

 	$field_activity_id = $query['field_activity_id_value'];
 	$entity_field_id = $query['entity_id'];

 	if(!isset($field_activity_id)){
	  if($activity_firehook == $fire_hook){
		  $hotspot_activity_term = new stdClass();
		  $hotspot_activity_term->name = $activity_title;
		  $hotspot_activity_term->vid = $activity_term_vid; // The ID of the parent vocabulary
		  $hotspot_activity_term->parent = 0; // This tells taxonomy that this is a top-level term
		  
		  taxonomy_term_save($hotspot_activity_term);
		  $tid_term = $hotspot_activity_term->tid;
		  $activity_term = taxonomy_term_load($tid_term);

		  $activity_term->field_activity_id['und'][0]['value'] = $activity_id; 
		  $activity_term->field_hotspot_activity_type['und'][0]['value'] = $activity_hotspot_value ? $activity_hotspot_value:0;
		  $activity_term->field_progress_page_term['und'][0]['value'] = $activity_progress_page ? $activity_progress_page:0;
		  taxonomy_term_save($activity_term);
		  }
	}else if(isset($field_activity_id)) {
		$hotspot_query = db_select('taxonomy_term_data','tax')
		  ->fields('tax',array('tid'))
		  ->condition('tid',$entity_field_id)
		  ->execute()
		  ->fetchAssoc();

		$tid = $hotspot_query['tid'];
		if($activity_firehook != $fire_hook){
			taxonomy_term_delete($tid);
		}else{
			$activity_term = taxonomy_term_load($tid);
			$activity_term->field_activity_id['und'][0]['value'] = $activity_id; 
			$activity_term->field_hotspot_activity_type['und'][0]['value'] = $activity_hotspot_value;
		 		$activity_term->field_progress_page_term['und'][0]['value'] = $activity_progress_page;
		 		$activity_term->name = $activity_title;
			taxonomy_term_save($activity_term);
		}
	}
}

/**
 * function callback for hotspot activities block
 */
function hotspot_activities() {

  $link_book_review = $base_url.'/node/add/review-book';
  $link_movie_review = $base_url.'/node/add/movie-review';
  $link_music_review = $base_url.'/node/add/music-review';
  $link_video_game_review = $base_url.'/node/add/video-game-review';
  $link_booklist = $base_url.'/node/add/booklist';
  $link_activity_review = $base_url.'/node/add/review-activity';

  $view_book_review = $base_url.'/reviews';
  $view_movie_review = $base_url.'/movie-review';
  $view_music_review = $base_url.'/music-review-listing';
  $view_video_game_review = $base_url.'/video-game-review';
  $view_booklist = $base_url.'/booklists';
  $view_activity_review = $base_url.'/activities';

  $view_reviews = array(0 => t('Select from the following'),
  $view_book_review => t('Book Reviews'),
  $view_activity_review => t('Activity Reviews'),
  $view_movie_review => t('Movie Reviews'),
  $view_music_review => t('Music Reviews'),
  $view_video_game_review => t('Video Game Reviews'),
  $view_booklist => t('Booklists'));

  $add_reviews = array(0 => t('Select from the following'),
  $link_book_review => t('Book Reviews'),
  $link_activity_review => t('Activity Reviews'),
  $link_movie_review => t('Movie Reviews'),
  $link_music_review => t('Music Reviews'),
  $link_video_game_review => t('Video Game Reviews'),
  $link_booklist => t('Booklists'));

	$form['activity_title'] = array(
	  '#type' => 'markup',
  	'#markup' => variable_get('hotspot_block_title'),
  	'#prefix' => '<div class="activity_title">',
 		'#suffix' => '</div>',
 		'#weight' => 1,
	);

	$form['activity_description'] = array(
	  '#type' => 'markup',
	 	'#markup' => variable_get('hotspot_block_description'),
	 	'#prefix' => '<div class="activity_desc">',
	 	'#suffix' => '</div>',
	 	'#weight' => 2,
	);


	$form['activities_read_list'] = array(
	  '#title' => t('Read Reviews of Bay Area Hot Spots'),
	  '#type' => 'select',
	  '#options' => activities_view_select_list('hotspot_activities','1'),
	  '#attributes' => array(
	    'class' => array('activities_list_read')
	  ),
	  '#weight' => 3,
	);

	global $user;
	$current_user = $user->uid;

	if($current_user != 0){
		$form['activities_submit_list'] = array(
		  '#title' => t('Submit a Review'),
		  '#type' => 'select',
		  '#options' => activities_submit_select_list('hotspot_activities','1'),
		  '#attributes' => array(
		    'class' => array('activities_list_submit')
		  ),
		  '#weight' => 4,
		);
	}

	$form['suggest_link'] = array(
		'#type' => 'link',
		'#title' => variable_get('hotspot_block_link_title'),
		'#href' => variable_get('hotspot_block_link'),
		'#attributes' => array('target' => '_blank'),
		'#prefix' => '<div class="suggest-link">',
 		'#suffix' => '</div>',
		'#weight' => 5,
	);

	$form['activity_review_title'] = array(
	  '#type' => 'markup',
  	'#markup' => variable_get('review_activity_block_title'),
  	'#prefix' => '<div class="activity_review_title">',
 		'#suffix' => '</div>',
 		'#weight' => 6,
	);

	$form['activity_review_description'] = array(
	  '#type' => 'markup',
	 	'#markup' => variable_get('review_activity_block_description'),
	 	'#prefix' => '<div class="activity_review_desc">',
	 	'#suffix' => '</div>',
	 	'#weight' => 7,
	);

	$form['read_submit'] = array(
	  '#title' => t('Write a Review'),
	  '#type' => 'select',
	  '#options' => $add_reviews,
	  '#attributes' => array(
	    'class' => array('reviews_add')
	  ),
	  '#weight' => 8,
	);

	$form['read_reviews'] = array(
	  '#title' => t('Read Existing Reviews'),
	  '#type' => 'select',
	  '#options' => $view_reviews,
	  '#attributes' => array(
	    'class' => array('reviews_list_view')
	  ),
	  '#weight' => 9,
	);

	return $form;
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
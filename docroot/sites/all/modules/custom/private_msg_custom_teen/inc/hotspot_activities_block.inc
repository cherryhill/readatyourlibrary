<?php

/**
 * function callback for hotspot activities block
 */

function hotspot_activities() {

	global $base_url;

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

	$voc = taxonomy_vocabulary_machine_name_load('hotspot_activities');
	$activity_term_vid = $voc->vid;
	$activities_terms = taxonomy_get_tree($activity_term_vid);

	foreach ($activities_terms as $key => $value) {
		$term_title = $value->name;
		$term_tid = $value->tid;

		$select_options[0] = 'Select from the following';
		$select_options[$base_url.'/'.$term_tid] .= $term_title;
	}

	$form['activities_read_list'] = array(
	  '#title' => t('Read Reviews of Bay Area Hot Spots'),
	  '#type' => 'select',
	  '#options' => $select_options,
	  '#attributes' => array(
	    'class' => array('activities_list_read')
	  ),
	  '#weight' => 3,
	);

	$form['activities_submit_list'] = array(
	  '#title' => t('Submit a Review'),
	  '#type' => 'select',
	  '#options' => $select_options,
	  '#attributes' => array(
	    'class' => array('activities_list_submit')
	  ),
	  '#weight' => 4,
	);

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
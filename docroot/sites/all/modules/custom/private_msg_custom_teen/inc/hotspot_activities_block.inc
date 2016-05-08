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
		$select_options[$term_tid] .= $term_title;
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

	$form['read_reviews'] = array(
	  '#title' => t('Read Existing Reviews'),
	  '#type' => 'select',
	  '#options' => $view_reviews,
	  '#attributes' => array(
	    'class' => array('reviews_list_view')
	  ),
	  '#weight' => 8,
	);

	$form['read_submit'] = array(
	  '#title' => t('Write a Review'),
	  '#type' => 'select',
	  '#options' => $add_reviews,
	  '#attributes' => array(
	    'class' => array('reviews_add')
	  ),
	  '#weight' => 9,
	);
	return $form;
}
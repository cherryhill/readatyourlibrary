<?php
/**
 * @file
 * feature_for_activity_page.features.fe_block_boxes.inc
 */

/**
 * Implements hook_default_fe_block_boxes().
 */
function feature_for_activity_page_default_fe_block_boxes() {
  $export = array();

  $fe_block_boxes = new stdClass();
  $fe_block_boxes->info = ' Create your own booklist';
  $fe_block_boxes->format = 'full_html';
  $fe_block_boxes->machine_name = 'create_your_own_booklist_activit';
  $fe_block_boxes->body = '<p>You can also share lists of favorite books</p>
<div><a class="button" href="node/add/booklist">Create a Booklist</a></div>';

  $export['create_your_own_booklist_activit'] = $fe_block_boxes;

  $fe_block_boxes = new stdClass();
  $fe_block_boxes->info = 'Program Dashboard for Staff and Leadstaff';
  $fe_block_boxes->format = 'full_html';
  $fe_block_boxes->machine_name = 'program_dashboard_for_staff';
  $fe_block_boxes->body = '<p><a class="button" href="admin/content/dashboard">Program Dashboard</a></p>';

  $export['program_dashboard_for_staff'] = $fe_block_boxes;

  $fe_block_boxes = new stdClass();
  $fe_block_boxes->info = 'Progress Block for activities page';
  $fe_block_boxes->format = 'full_html';
  $fe_block_boxes->machine_name = 'progress_myactivity_block';
  $fe_block_boxes->body = '<div>Reading</div>
<div><a class="button" href="progress">See My Progress</a></div>';

  $export['progress_myactivity_block'] = $fe_block_boxes;

  $fe_block_boxes = new stdClass();
  $fe_block_boxes->info = 'write your own review';
  $fe_block_boxes->format = 'full_html';
  $fe_block_boxes->machine_name = 'write_your_own_review_activity';
  $fe_block_boxes->body = '<div>
<p>Would you like to share your opinion about a book with others?</p>
<div><a class="button" href="node/add/review-book">Write a Review</a></div>
</div>';

  $export['write_your_own_review_activity'] = $fe_block_boxes;

  return $export;
}

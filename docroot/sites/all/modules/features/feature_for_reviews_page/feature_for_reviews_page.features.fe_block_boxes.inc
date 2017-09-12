<?php
/**
 * @file
 * feature_for_reviews_page.features.fe_block_boxes.inc
 */

/**
 * Implements hook_default_fe_block_boxes().
 */
function feature_for_reviews_page_default_fe_block_boxes() {
  $export = array();

  $fe_block_boxes = new stdClass();
  $fe_block_boxes->info = 'Write your own review block';
  $fe_block_boxes->format = 'full_html';
  $fe_block_boxes->machine_name = 'write_your_own_review_reviews_pa';
  $fe_block_boxes->body = '<p>Would you like to share your opinion about a book with others?</p>
<p><a class="button" href="node/add/review-book">Write A Review</a></p>';

  $export['write_your_own_review_reviews_pa'] = $fe_block_boxes;

  return $export;
}

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
<p class="button" style="font-family: \'Helvetica Neue\', Helvetica, Helvetica, Arial, sans-serif; font-size: 16px;"><a href="node/add/review-book">Write A Review</a>&lt;div class="viewmenu"&gt;View: &lt;a href="reviews"&gt;All&lt;/a&gt; | &lt;a href="reviews/staff"&gt;Posted by Staff&lt;/a&gt; | &lt;a href="reviews/patrons"&gt;Posted by Kids&lt;/a&gt;&lt;/div&gt;</p>';

  $export['write_your_own_review_reviews_pa'] = $fe_block_boxes;

  return $export;
}

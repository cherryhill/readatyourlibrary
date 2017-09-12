<?php
  drupal_add_js(drupal_get_path('module', 'child_progress') . '/js/jquery-ui.min.js');
  drupal_add_js(drupal_get_path('module', 'child_progress') . '/js/fullcalendar.min.js');
  drupal_add_js(drupal_get_path('module', 'child_progress') . '/js/gcal.js');
  drupal_add_js(drupal_get_path('module', 'child_progress') . '/js/drag_drop_calendar.js');
?>

<!-- Tpl file for children progress page -->
<div class="progress-page-wrap">
	<div class="top-block-wrap">

	   <!-- This is the drupal views block of sticker -->

		<div class="sticker-block"> 
          <?php print views_embed_view('dropdown_sticker_list', 'block'); ?>
		</div>

		<!-- This is the reward list won by patron  -->

		<div class="pro-reward-block"> 
          <?php print views_embed_view('user_rewrad_for_progress_page', 'block'); ?>
		</div>
         
         <!-- This is the user progress for read activity. -->

		<div class="pro-progress-block"> 
          <?php 
            $block = module_invoke('child_progress', 'block_view', 'user_prize_block');
            print render($block['content']); 
          ?>
		</div>
	</div>

	<!-- This is for calendar div -->

	<div class="calendar-wrapper">
	  <div id="print_button">Print Calendar</div>
	  <div id="calendar">&nbsp;</div>
	</div>

	<?php 
      $block = module_invoke('child_progress', 'block_view', 'calendar-data');
      print render($block['content']); 
    ?>

</div>
<!-- Tpl file for children progress page -->
<div class="progress-page-wrap">
	<div class="top-block-wrap">

	   <!-- This is the drupal views block of sticker -->

		<div class="sticker-block"> 
          <?php print views_embed_view('child_progress', 'block'); ?>
		</div>

		<!-- This is the reward list won by patron  -->

		<div class="pro-reward-block"> 
          <?php print views_embed_view('prize_won_for_progress_page', 'block'); ?>
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

</div>
<!-- Progress Report Pagez -->
<div>
	<?php print variable_get('pg_title'); ?>
</div>
<div>
	<?php
	$page_desc = variable_get('pg_desc', array('value' => '', 'format' => NULL)); 
	print $page_desc['value']; ?>
</div>
<div>
	<button>Save as PDF</button>
</div>
<div>
	<?php print user_avatar_progress_page(); ?>
</div>
<div>
	<?php print 'Stamps Earned:'; ?>
</div>
<div>
	<?php print 'Raffle Tickets Earned:'; ?>
</div>
<div>
	<?php
		$block = block_load('private_msg_custom_teen', 'progress_submit_block');
  	$output = drupal_render(_block_get_renderable_array(_block_render_blocks(array($block))));
  	print $output; 
	?>
</div>
<div>
	<button id="pg-report">Submit</button>
</div>
<div><?php
		$report_block_text = variable_get('report_block_desc', array('value' => '', 'format' => NULL));
	  	print $report_block_text['value']
		?>
</div>
<div><?php
	print views_embed_view('prize_won_for_progress_page','block');
  ?>
</div>
<div>
	<?php
	  $reward_block = variable_get('progress_rewards', array('value' => '', 'format' => NULL)); 
	  print $reward_block['value']; ?>
</div>


<div class="progress-main">
	<?php 
		$grids = variable_get('no_of_grids');
		for($i=0; $i < $grids; $i++){
			echo '<div class = "grid" id = "cells'.$i.'"></div>';
		}
	?>
</div>



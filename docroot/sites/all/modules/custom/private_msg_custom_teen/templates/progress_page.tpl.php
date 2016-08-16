<!-- Progress Report Pagez -->
<?php   
  global $user;
  global $base_url;
  $current_uid = $user->uid;
  $raff_count = raffle_count($current_uid);
  $imgStyle = 'avatar_style';
?>
<div class="progress-page">
<h1 id = "title">
	<?php print variable_get('pg_title'); ?>
</h1>
<div class="progress-desc">
	<?php
	$page_desc = variable_get('pg_desc', array('value' => '', 'format' => NULL)); 
	print $page_desc['value']; ?>
</div>
<div class="print-page">
	<a href = "progress-print"><button class="print">Print Progress Report<span style="margin-left: 5px;">(pdf)</span></button></a>
</div>
<div class="user-desc">
<div class="avatar-id">
	<?php print user_avatar_progress_page($current_uid, $imgStyle); ?>
</div>
<div class="point-status">
<div class="activity-status">
  <?php print 'Activities Completed: '.specefic_user_nodes($current_uid).' activities'; ?>
</div>
<div class="activity-remaining">
<?php $grids = variable_get('no_of_grids'); $activities_left = $grids - specefic_user_nodes($current_uid);
  if($activities_left < 0){ print 'Activities Left to Complete: '.'0'.' activities';
  }else{ print 'Activities Left to Complete: '.$activities_left.' activities'; } ?>
</div>
<div class="points">
	<?php print 'Raffle Tickets Earned: '.$raff_count; ?>
</div>
</div>
</div>
<div class="progress-wrap">
<div class="report-acivity">
	<?php
      print '<h1>Report an Activity</h1>';
      print  '<div id = "errorwarn"></div>';
      print  '<div id = "errorwarn-activity"></div>';

	  $block = block_load('private_msg_custom_teen', 'progress_submit_block');
	  $render_block = _block_get_renderable_array(_block_render_blocks(array($block)));
  	  $output = drupal_render($render_block);
  	  print $output; 
	?>
	<div class="submit">
		<button id="pg-report">Submit</button>
	</div>
	<div><?php
		$report_block_text = variable_get('report_block_desc', array('value' => '', 'format' => NULL));
	  	//print $report_block_text['value']
		?>
	</div>
</div>


<div class="reward-won"><?php
  print views_embed_view('prize_won_for_progress_page','block'); ?>
</div>

<div class="progress-rewards"><?php
  $reward_block = variable_get('progress_rewards', array('value' => '', 'format' => NULL)); 
  print $reward_block['value']; ?>
</div></div>

<div class="progress-main"><?php 
  echo '<h1>My Passport Stamps</h1>';
  $exceed_limit = '';

  $criteria = array(
    'uid' => $current_uid,
    'type' => 'activity_report',
  );
  
  $nodes = entity_load('node',FALSE,$criteria);

  foreach ($nodes as $key => $value) {
    $node_date = $value->field_completion_date['und'][0]['value'];
    $user_reward = $value->field_won_reward['und'][0]['value'];
    $node_type_hotspot = $value->field_hotspot_activity_report['und'][0]['value'];
    $user_won_reward = '';
    $hotspot_type_activity = '';
    $n_date = date("m.d.y", strtotime($node_date));

	if($node_type_hotspot){
	  $hotspot_type_activity = '<p class = "hotspot-activity">Bay Area Hot Spot!</p>';
	}
	if($user_reward){
	  $user_won_reward = '<p class  = "won-rew">Congratulations! You have earned a prize!</p>';
	}

    $node_nid[] = '<p class  = "date-pg">'.$n_date.'</p>'.$hotspot_type_activity.'<p class = "title-pg">'.$value->title.'</p>'.$user_won_reward;
  }

  if(isset($_SESSION['exceed-activity-limit']['status'][0])){
    $exceed_limit = $_SESSION['exceed-activity-limit']['status'][0];
  }

  $i=0; $gr = ceil($grids/6);
  for($j=0;$j<$gr;$j++){
    echo "<div class = 'new-row'>";
    for($k=0; $k < 6; $k++){
	  if(isset($node_nid[$i])){
	    echo "<div class = 'grid inserted' id = 'cells'.$i.'>".$node_nid[$i]."</div>";
	  }
	  else{
	    echo "<div class = 'grid' id = 'cells'.$i.'></div>";
	  }
	  $i++;
	}
	echo '</div>';
  }
  unset($exceed_limit); ?>
</div></div>

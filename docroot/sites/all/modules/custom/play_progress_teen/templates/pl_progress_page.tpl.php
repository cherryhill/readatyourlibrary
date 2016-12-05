<!-- Progress Report Page -->
<?php   
  global $user;
  global $base_url;
  $current_uid = $user->uid;
  // $raff_count = pl_raffle_count($current_uid);  
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
	<!--<a href = "progress-print"><button class="print"><?php //print t('Print Progress Report'); ?><span style="margin-left: 5px;">(pdf) </span></button></a> -->
</div>
<div class="user-desc">
<div class="avatar-id">
	<?php //print pl_user_avatar_progress_page($current_uid, $imgStyle); ?>
</div>
<div class="point-status">
<div class="activity-status">
  <?php //print 'Activities Completed: '.pl_specefic_user_nodes($current_uid).' activities'; ?>
</div>
<div class="activity-remaining">
<?php //$grids = variable_get('no_of_grids'); $activities_left = $grids - pl_specefic_user_nodes($current_uid);
$grids = 18;
  // if($activities_left < 0){ print t('Activities Left to Complete: 0 activities');
  // }else{ print t('Activities Left to Complete: ').$activities_left.t(' activities'); } ?>
</div>
<div class="points">
	<?php //print t('Raffle Tickets Earned: ').$raff_count; ?>
</div>
</div>
</div>
<div class="progress-wrap">
<div class="report-acivity">
	<?php
      print '<h1>'.t('Report an Activity</h1>');
      print  '<div id = "errorwarn"></div>';
      print  '<div id = "errorwarn-activity"></div>';

	  $block = block_load('play_progress_teen', 'progress_submit_block');
	  $render_block = _block_get_renderable_array(_block_render_blocks(array($block)));
  	  $output = drupal_render($render_block);
  	  print $output; 
	?>
<!-- 	<div class="submit">
		<button id="pg-report">Submit</button>
	</div> -->
	<div><?php $report_block_text = variable_get('report_block_desc', array('value' => '', 'format' => NULL)); ?></div>
</div>

<div class="reward-won"><?php print views_embed_view('prize_won_for_progress_page','block'); ?> </div>

<div class="progress-rewards"><?php
  $reward_block = variable_get('progress_rewards', array('value' => '', 'format' => NULL)); 
  print $reward_block['value']; ?>
</div></div>

<div class="progress-main"><?php 
  echo '<h1>My Passport Stamps</h1>';
  $exceed_limit = '';

  global $language;
  $lang = $language->language;

  // $criteria = array(
  //   'uid' => $current_uid,
  //   'type' => 'activity_entry',
  // );

  $nonSelf = variable_get('nonself_activities_progress');
  $self = variable_get('activities_progress');
  $rewardMsg = variable_get('reward_msg');
  $imgFid = variable_get('progress_img');

  $file = file_load($imgFid);
  $uri = $file->uri;
  $urlImg = file_create_url($uri);

  // echo '<pre>'; print_r($url);die();

  $progressActi = array_merge($self, $nonSelf);

  $query = new EntityFieldQuery();
  $query->entityCondition('entity_type', 'activity');
  $query->entityCondition('bundle', 'activity_entry');
  $query->propertyCondition('uid', $current_uid);
  $query->fieldCondition('field_activity_entry_activity', 'target_id', $progressActi);
  $count = $query->execute();

  foreach ($count['activity'] as $key => $value) {
    $activityIds[] = $value->id;
  }

  $nodes = entity_load('activity', $activityIds);
  // $nodes = entity_load(  'activity',FALSE,$criteria);
  $node = reset($nodes);

  foreach ($nodes as $key => $value) {

    $activityTitle = $value->title;

    $title = substr($activityTitle, 0, -19);
    $date = substr($activityTitle, -16);

    $n_date = date("m.d.y", strtotime($date));

    if(isset($value->field_rw_claim_id[$lang])){
      $activityReward = $value->field_rw_claim_id[$lang][0]['value'];
    }

    if(isset($value->field_won_reward[$lang])){
      $user_reward = $value->field_won_reward[$lang][0]['value'];
    }

    $user_won_reward = '';
    $hotspot_type_activity = '';

  	if(isset($activityReward)){
  	  $user_won_reward = '<p class = "rew">'.$rewardMsg.'</p>';
  	}

    $node_nid[] = '<p class  = "date-pg">'.$n_date.'</p>'.$hotspot_type_activity.'<p class = "title-pg">'.$title.'</p>'.$user_won_reward;
  }

  if(isset($_SESSION['exceed-activity-limit']['status'][0])){
    $exceed_limit = $_SESSION['exceed-activity-limit']['status'][0];
  }

  $i=0; $gr = ceil($grids/6);
  for($j=0;$j<$gr;$j++){
    echo "<div class = 'new-row'>";
    for($k=0; $k < 6; $k++){
	  if(isset($node_nid[$i])){
	    echo "<div class = 'grid inserted' id = 'cells'.$i.'>".$node_nid[$i]."<img src='$urlImg'></div>";
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

<!-- Progress Report Page -->
<?php
  drupal_add_js(libraries_get_path('printThis', TRUE). '/printThis.js');
  drupal_add_js(libraries_get_path('printThis', TRUE). 'js/progress_teen_program.js');
  global $user;
  global $base_url;
  $current_uid = $user->uid;
  $raff_count = pl_raffle_count($current_uid);
  $imgStyle = 'avatar_style';

  // global $language;
  // $lang = $language->language;

  //Get values from configuration page
  $nonSelf = variable_get('nonself_activities_progress');
  $self = variable_get('activities_progress');
  $rewardMsg = variable_get('reward_msg');
  $imgFid = variable_get('progress_img');

  //Get completion stamp image
  if ($imgFid != 0) {
    $file = file_load($imgFid);
    $uri = $file->uri;
    $urlImg = file_create_url($uri);
    //$imageCompleted = "<img src='$urlImg'>";
  }

  //Get list of complete list of activities which need to be displayed on progress page
  $progressActi = array_merge($self, $nonSelf);

  // print_r($nonSelf); die();
  $query = new EntityFieldQuery();
  $query->entityCondition('entity_type', 'activity');
  $query->entityCondition('bundle', 'activity_entry');
  $query->propertyCondition('uid', $current_uid);
  $query->fieldCondition('field_activity_entry_activity', 'target_id', $progressActi);
  $result = $query->execute();

  foreach ($result['activity'] as $key => $value) {
    $activityIds[] = $value->id;
  }

  $count = sizeof($activityIds);

  if($count>0){
    $activiesList = entity_load('activity', $activityIds);
    $activiesLis = reset($activiesList);
    $lang = field_language('activity',$activiesLis);
    foreach ($lang as $key => $value) {
      ${$key} = $value;
    }
  }

  // echo "<pre>"; print_r($activiesList); die();
?>
<div class="progress-page">
<div class="top-progress-header">
<h1 id = "title">
	<?php print variable_get('pg_title'); ?>
</h1>
<div class="print-page">
  <button class="print_pg"><?php print t('Print Progress Report'); ?><span style="margin-left: 5px;">(pdf) </span></button>
</div>
</div>
<div class="progress-desc">
	<?php
	$page_desc = variable_get('pg_desc', array('value' => '', 'format' => NULL));
	print $page_desc['value']; ?>
</div>

<div class="user-desc">
<div class="avatar-id">
	<?php print pl_user_avatar_progress_page($current_uid); ?>
</div>
<div class="point-status">
<div class="activity-status" id = "activity-status">
  <?php print 'Activities Completed: '.$count.' activities'; ?>
</div>
<div class="activity-remaining" id ="activity-remaining">
<?php $grids = variable_get('no_of_grids'); $activities_left = $grids - $count;
// $grids = 40;
// echo 'pre'; print_r($grids);die();
   if($activities_left < 0){ print t('Activities Left to Complete: 0 activities');
   }else{ print t('Activities Left to Complete: ').$activities_left.t(' activities'); } ?>
</div>
<div class="points" id = "points">
	<?php print t('Raffle Tickets Earned: ');
    if(isset($raff_count)){
      print $raff_count;
    } else {
      print '0';
    }
  ?>
</div>
</div>
</div>
<div class="progress-wrap">
<div class="report-acivity">
	<?php
      if ($count >= $grids){
        print '<h1>Congratulations! You have completed the program.</h1>';

      }
      else{
        print '<h1>'.t('Report an Activity</h1>');
        print  '<div id = "errorwarn"></div>';
        print  '<div id = "errorwarn-activity"></div>';

        $block = block_load('play_progress_teen', 'progress_submit_block');
        $render_block = _block_get_renderable_array(_block_render_blocks(array($block)));
        $output = drupal_render($render_block);
        print $output;
      }
	?>
<!-- 	<div class="submit">
		<button id="pg-report">Submit</button>
	</div> -->
	<div class="report-activity-desc"><?php $report_block_text = variable_get('report_block_desc', array('value' => '', 'format' => NULL)); print t($report_block_text['value']);?></div>
</div>

<div class="reward-won"><?php print views_embed_view('Rewards_Progress','block'); ?> </div>

<div class="progress-rewards"><div><?php
  $reward_block = variable_get('progress_rewards', array('value' => '', 'format' => NULL));
  print $reward_block['value']; ?></div>
</div></div>

<div class="progress-main"><?php
  // echo '<h1>My Passport Stamps</h1>';
  $exceed_limit = '';

  foreach ($activiesList as $key => $value) {

    $activityTitle = $value->title;

    $title = substr($activityTitle, 0, -19);
    $date = substr($activityTitle, -16);

    $n_date = date("m.d.y", strtotime($date));

    if(!empty($value->field_rw_claim_id[$field_rw_claim_id])){
      $activityReward = $value->field_rw_claim_id[$field_rw_claim_id][0]['value'];
    } else {
      $activityReward = 1;
    }

    $user_won_reward = '';
    $hotspot_type_activity = '';

  	if($activityReward != 1){
  	  $user_won_reward = '<p class = "rew"><strong>'.$rewardMsg.'</strong></p>';
      $reward_won = 'reward-won-cell';
  	} else{ $reward_won = ''; }

    $act_id[] = array('data' => '<p class  = "date-pg">'.$n_date.'</p>'.$hotspot_type_activity.'<p class = "title-pg">'.$title.'</p>'.$user_won_reward,
      'selector'=> $reward_won,);
  }

  if(isset($_SESSION['exceed-activity-limit']['status'][0])){
    $exceed_limit = $_SESSION['exceed-activity-limit']['status'][0];
  }

  // $grids = 100;
  $i=0; $gr = ceil($grids/6);
  print("<h1>My Passport Stamps</h1>");
  print("<table class='progress-grid'><tbody>");

  for($j=0;$j<$gr;$j++){
    print("<tr id=$j class = 'new-row'>");
    // echo "<div class = 'new-row'>";
    for($k=0; $k < 6; $k++){
      $cell_counter ++;
      if(isset($act_id[$i])){
        print("<td class = 'grid inserted ". $act_id[$i]['selector']."' id = $cell_counter style='background: url($urlImg) no-repeat scroll center bottom 20px'>".$act_id[$i]['data']."</td>");
  	    // echo "<div class = 'grid inserted' id = 'cells'.$i.'>".$act_id[$i].$imageCompleted."</div>";
  	  }
  	  else{
        if($cell_counter > $grids){
          print("<td class='filler-cell'></td>");
        } else {
          print("<td class = 'grid' id = $cell_counter active = 'yes'></td>");
        }
  	  }
      $i++;
    }
    print("</tr>");
  }
  print("</tbody></table>");
?>
</div></div>

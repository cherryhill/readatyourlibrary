<?php

/**
 * ajax callback for progress page
 */
function complete_activity_progress(){
  global $user;
  $activity_uid = $user->uid;

  $tid = $_REQUEST['id'];
  $activity_date = $_REQUEST['date'];

  $activity_term = taxonomy_term_load($tid);
  $activity_id = $activity_term->field_activity_id['und'][0]['value'];

  $activity_limit = retrieve_activity_limit($activity_id);
  $node_created = activity_report_node_creation($activity_uid, $activity_id);

  if($node_created < $activity_limit){
    activity_report_node_create($activity_id, $activity_date, $tid);
    play_library_program_create_activity_entry($activity_id, $activity_uid);
  }else{
    $_SESSION['exceed-activity-limit'] = drupal_set_message("You have recorded maximum number of times this activity can be performed.");
  }
  echo 1;
}

function user_avatar_progress_page($uid){

	global $user;
	$user_pf = profile2_load_by_user($user->uid);
	$user_main = user_load($uid);

	$img_id = $user_pf['main']->field_user_avatar['und'][0]['target_id'];
	$user_name = $user_main->name;

	$query = db_select('field_data_field_avatar_image', 't');
	$query->join('file_managed', 'n', 'n.fid = t.field_avatar_image_fid');
	$result = $query
	  ->fields('n', array('uri'))
	  ->condition('t.entity_id', $img_id)
	  ->execute();

	$img_uri = $result->fetchObject();
	$img_uri = $img_uri->uri;
	$style = 'avatar_dashboard';
	$img_path = image_style_url($style, $img_uri);

	$img = "<img src='$img_path'>";
	return $img.$user_name;
}

/**
 * Provides user avatar image uri used for progress print pdf page
 */
function user_avatar_progress_print_page($uid){

  global $user;
  $user_pf = profile2_load_by_user($user->uid);

  $img_id = $user_pf['main']->field_user_avatar['und'][0]['target_id'];
  
  $query = db_select('field_data_field_avatar_image', 't');
  $query->join('file_managed', 'n', 'n.fid = t.field_avatar_image_fid');
  $result = $query
    ->fields('n', array('uri'))
    ->condition('t.entity_id', $img_id)
    ->execute();

  $img_uri = $result->fetchObject();
  $img_uri = $img_uri->uri;
  $style = 'avatar_dashboard';
  $img_path = image_style_url($style, $img_uri);
  return $img_path;
}

/**
 * Retrieves activity limt that is set
 */
function retrieve_activity_limit($activity_id){
  $entity_info = entity_load('activity', array($activity_id));
  return $activity_name = $entity_info[$activity_id]->field_activity_limit['und'][0]['value'];
}

/**
 * Retrieves how many times an activity report node has been created by the user
 */
function activity_report_node_creation($account_id, $activity_id){
  $query = new EntityFieldQuery();
  $query->entityCondition('entity_type', 'node');
  $query->entityCondition('bundle', 'activity_report');
  $query->propertyCondition('uid', $account_id);
  $query->fieldCondition('field_activity_id_report', 'value', $activity_id);
  return $query->count()->execute();
}

function specefic_user_nodes($current_uid){
  $user_stamp_query = db_select('node','n');
  $user_stamp_query->condition('type','activity_report');
  $user_stamp_query->condition('uid',$current_uid);
  $user_stamp_query->condition('status','1');
  $user_stamp_query->addExpression('COUNT(1)','count');
  $res_stamp = $user_stamp_query->execute();

  if($record = $res_stamp->fetchAssoc())
    return $stamp_count = $record['count'];
  return 0;
}

function progress_print_page(){
  global $user;
  global $base_url;
  $uid = $user->uid;

  $u_name = $user->name;
  $u_avatar = user_avatar_progress_print_page($uid);
  $grids = variable_get('no_of_grids');
  $pg_title = variable_get('pg_title');
  $page_desc = variable_get('pg_desc', array('value' => '', 'format' => NULL));
  $page_desc = $page_desc['value'];
  $activity_completed = specefic_user_nodes($uid);
  $activities_left = $grids - $activity_completed;

  $block_rewards = module_invoke('views','block_view','prize_won_for_progress_page-block_1');
  $user_rew_block = render($block_rewards['content']);
  $report_block_text = variable_get('report_block_desc', array('value' => '', 'format' => NULL));
  $report_block_text['value'];

  $reward_won = views_embed_view('prize_won_for_progress_page','block');
  $reward_block = variable_get('progress_rewards', array('value' => '', 'format' => NULL)); 
  $u_rew = $reward_block['value'];
  $reward_block = variable_get('progress_rewards', array('value' => '', 'format' => NULL)); 
  $rew_block = $reward_block['value'];

  $criteria = array(
    'uid' => $uid,
   'type' => 'activity_report',
  );

  $nodes = entity_load('node',FALSE,$criteria);
  $output = '';
  $output .= "
  <div class = '$base_url/sites/images'></div>
  <div class = 'main'>
    <div class = 'progress-page'>
      <h1 id = 'title'>$pg_title</h1>
      <div class = 'progress-desc'>$page_desc</div>
      <div class = 'user-desc'>
        <img src = '$u_avatar'>$u_name
        <div class = 'point-status'>
          <div class = 'activity-status'>Activities Completed: $activity_completed activities</div>
          <div class = 'activity-remaining'>Activities Left to Complete: $activities_left activities</div>
          <div class = 'raffle'>Raffle Tickets Earned: </div>
        </div>
      </div>
      <div class = 'middle-block'>
        <div class = 'report-activity'>$user_rew_block</div>
        <div class = 'progress-rewards'>$rew_block</div>
      </div>
      <div class='progress-main'><h2>My Passport Stamps</h2></div>
    </div>
  </div>
  ";
echo $output;die;
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

  $i=0; $gr = ceil($grids/6);
  for($j=0;$j<$gr;$j++){
    $output.= "<div class = 'new-row'>";
    for($k=0; $k < 6; $k++){
    if(isset($node_nid[$i])){
      $output.= "<div class = 'grid inserted' id = 'cells$i'>".$node_nid[$i]."</div>";
    }
    else{
      $output.= "<div class = 'grid' id = 'cells$i'></div>";
    }
    $i++;
  }
  $output.= '</div>';
  }
  // echo $output;

  //pdf for progress page
  require_once("sites/all/modules/contrib/print/lib/dompdf/dompdf_config.inc.php");
  $dompdf = new DOMPDF;
  $html = stripslashes($output); 
  $dompdf->load_html(utf8_decode($html));
  $dompdf->render();
  $font = Font_Metrics::get_font("din", "regular");
  $dompdf->stream("Progress-Page.pdf");
}

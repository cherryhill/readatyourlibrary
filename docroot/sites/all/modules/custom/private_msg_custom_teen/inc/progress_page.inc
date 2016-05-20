<?php



/**
 * ajax callback for progress page
 */
function complete_activity_progress(){
	echo 1;
	/*global $user;
	$activity_uid = $user->uid;

	$tid = $_POST['id'];
	$activity_date = $_POST['date'];

	$activity_term = taxonomy_term_load($tid);

	$activity_id = $activity_term->field_activity_id['und'][0]['value'];
	activity_report_node_create($activity_id, $activity_date, $tid);

	play_library_program_create_activity_entry($activity_id,$activity_uid);

	$found = true;           
  echo json_encode(array('success' => $found, 'content' => $output));
 
  module_invoke_all('exit');
  exit;*/
}

function activity_report_node_create($activity_id, $activity_date, $term_tid, $check_in_progress = 0, $current_user = 0) {

  $entity_info = entity_load('activity', array($activity_id));
  $activity_name = $entity_info[$activity_id]->field_activity_description['und'][0]['safe_value'];
  $hotspot_activity_type = $entity_info[$activity_id]->field_hotspot_activity['und'][0]['value'];
  $activity_progress_status = $entity_info[$activity_id]->field_show_on_progress_page['und'][0]['value'];
  $_SESSION['progress_activity_id']= $activity_id;

  // check activity 'show in progress' status
  if($check_in_progress) {
    if(!$activity_progress_status) {
  	  return FALSE;
    }
  }
  // if show in progress is one, node is created.
  if($current_user == 0){
    global $user;
	$current_user = $user->uid;
  }

  $node = new stdClass(); // Creating a new node object
  $node->type = 'activity_report'; //Content type
  $node->language = LANGUAGE_NONE;
  node_object_prepare($node);
  $node->title = $activity_name;
  $node->status = 1;
  $node->uid = $current_user;
  $node->field_activity_id_report[LANGUAGE_NONE][0]['value'] = $activity_id;
  $node->field_hotspot_activity_report[LANGUAGE_NONE][0]['value'] = $hotspot_activity_type;
  $node->field_show_on_progress_report[LANGUAGE_NONE][0]['value'] = $activity_progress_status;
  $node->field_term_id[LANGUAGE_NONE][0]['value'] = $term_tid;
  $node->field_completion_date[LANGUAGE_NONE][0]['value'] = $activity_date;
  node_save($node);
  $created_nid = $node->nid;

  $_SESSION['teen_progress_report_nid'] = $created_nid;
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

	$privacy = $data->_field_data['nid']['entity'];
	$privacy_key = $privacy->field_please_select_one[LANGUAGE_NONE][0]['value'];

	return $img.$user_name;
}

function progress_print_page(){
  global $user; 
  $uid = $user->uid;
  $u_avatar = user_avatar_progress_page($uid);
  $pg_title = variable_get('pg_title');
  $page_desc = variable_get('pg_desc', array('value' => '', 'format' => NULL));
  $page_desc = $page_desc['value'];

  $block = block_load('private_msg_custom_teen', 'progress_submit_block');
  $user_reward_block = drupal_render(_block_get_renderable_array(_block_render_blocks(array($block))));
  $report_block_text = variable_get('report_block_desc', array('value' => '', 'format' => NULL));
  $report_block_text['value'];

  $reward_won = views_embed_view('prize_won_for_progress_page','block');
  $reward_block = variable_get('progress_rewards', array('value' => '', 'format' => NULL)); 
  $u_rew = $reward_block['value'];

  $grids = variable_get('no_of_grids'); $criteria = array(
    'uid' => $userID,
    'type' => $type,
  );
  $criteria = array(
    'uid' => $uid,
   'type' => 'activity_report',
  );
  $output .= "<div class='progress-page'>
<h1 id = 'title'>$pg_title
</h1>
<div class='progress-desc'>
  $page_desc	
</div>
<div class='user-desc'>
<div class='avatar-id'>$u_avatar
</div>
<div class='point-status'>
<div class='activity-status'>Stamps Earned:
</div>
<div class='points'>Raffle Tickets Earned:
</div>
</div>
</div>
<div class='progress-wrap'>
<div class='report-acivity'><h1>Report an Activity</h1>$user_reward_block
	<div class='submit'>
		<button id='pg-report'>Submit</button>
	</div>
</div>
<div class='reward-won'>$reward_won
</div>
<div class='progress-rewards'>$u_rew
</div>
</div>
<div class='progress-main'><h1>My Passport Stamps</h1>";
$nodes = entity_load('node',FALSE,$criteria);
foreach ($nodes as $key => $value) {
  $node_date = $value->field_completion_date['und'][0]['value'];
  $user_reward = $value->field_won_reward['und'][0]['value'];
  if($user_reward != '0'){
    $user_won_reward = '<p class  = "won-rew">Congratulations! You have earned a prize!</p>';
  }
  $n_date = date("m.d.y", strtotime($node_date));
  $node_nid[] = '<p class  = "date-pg">'.$n_date.'</p><p class = "title-pg">'.$value->title.'</p>'.$user_won_reward;
}
$k=0; $gr = ceil($grids/6);
for($j=0;$j<$gr;$j++){
  $output .=	'<div class = "new-row">';
    for($i=0; $i < 6; $i++){
	  if($node_nid[$k]){
        $output .= '<div class = "grid inserted" id = "cells'.$k.'">'.$node_nid[$k].'</div>';
      }
      else{
        $output .= '<div class = "grid" id = "cells'.$k.'"></div>';
      }	
      $k++;	
    }
  $output .= '</div>';
}
$output .= '</div></div>';
echo $output;
}
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
  $output .= '<style>
   @font-face {
  font-family: "SpecialElite";
  src: url("images/SpecialElite.ttf");
  font-weight: normal;
  font-style: normal;
}
@font-face {
  font-family: "Raleway-Bold";
  src: url("images/Raleway-Bold.otf");
}
@font-face {
  font-family: "Raleway-Medium";
  src: url("images/Raleway-Medium.otf");
}
/* line 60, ../sass/custom.scss */
.main {
  padding: 25px 0px;
  background: #32024e;
  color: #fff;
  width: 1280px;
  margin: 0 auto;
}
/* line 65, ../sass/custom.scss */
.main .progress-page {
  padding-left: 25px;
  display: inline-block;
  padding-right: 25px;
  width: 100%;
}
/* line 71, ../sass/custom.scss */
.main #title {
  font-size: 26px;
  color: #fff;
  margin-top: 0;
  font-family: SpecialElite !important;
  font-weight: normal !important;
  font-style: normal !important;
  -webkit-font-smoothing: antialiased !important;
  -moz-osx-font-smoothing: grayscale !important;
  margin-bottom: 8px;
}
/* line 83, ../sass/custom.scss */
.main .progress-desc p {
  font-size: 16px;
  font-family: Raleway-Bold !important;
  font-style: normal !important;
  font-weight: normal !important;
  -webkit-font-smoothing: antialiased !important;
  -moz-osx-font-smoothing: grayscale !important;
  -moz-font-smoothing: grayscale !important;
}
/* line 92, ../sass/custom.scss */
.main .progress-desc ul {
  list-style: none;
  padding-left: 22px;
}
/* line 95, ../sass/custom.scss */
.main .progress-desc ul li {
  position: relative;
  line-height: 1.7;
  font-size: 16px;
  font-family: Raleway-Medium !important;
  font-style: normal !important;
  font-weight: normal !important;
  -webkit-font-smoothing: antialiased !important;
}
/* line 98, ../sass/custom.scss */
.main .progress-desc ul li:before {
  content: "";
  width: 5px;
  height: 5px;
  display: block;
  visibility: visible;
  position: absolute;
  top: 40%;
  left: -10px;
  border-radius: 100%;
  background: #fff;
}
/* line 112, ../sass/custom.scss */
.main .print-page {
  position: absolute;
  right: 25px;
  top: 25px;
}
/* line 116, ../sass/custom.scss */
.main .print-page .print {
  border: none !important;
  color: #fff;
  padding-left: 40px;
  font-size: 18px;
  background: #7eb600 url("images/libraryzurb/print.png") no-repeat scroll 10px center;
}
/* line 124, ../sass/custom.scss */
.main .user-desc {
  width: 94%;
  display: table;
  background: #7eb600;
  padding: 25px 14px;
}
/* line 129, ../sass/custom.scss */
.main .user-desc .avatar-id {
  width: 60%;
  display: table-cell;
  vertical-align: bottom;
  font-size: 20px;
  font-family: SpecialElite !important;
  font-weight: normal !important;
  font-style: normal !important;
  -webkit-font-smoothing: antialiased !important;
  -moz-osx-font-smoothing: grayscale !important;
}
/* line 139, ../sass/custom.scss */
.main .user-desc .avatar-id img {
  -webkit-box-shadow: 3px 3px 6px -1px rgba(0, 0, 0, 0.5);
  -moz-box-shadow: 3px 3px 6px -1px rgba(0, 0, 0, 0.5);
  box-shadow: 3px 3px 6px -1px rgba(0, 0, 0, 0.5);
  margin-right: 10px;
  vertical-align: bottom;
  background: #fff;
}
/* line 146, ../sass/custom.scss */
.main .user-desc .point-status {
  width: 40%;
  display: table-cell;
  vertical-align: middle;
}
/* line 150, ../sass/custom.scss */
.main .user-desc .point-status div {
  padding-left: 5%;
  float: left;
  font-size: 14px;
  font-family: Raleway-Medium !important;
  font-style: normal !important;
  font-weight: normal !important;
  -webkit-font-smoothing: antialiased !important;
}
/* line 162, ../sass/custom.scss */
.main .progress-wrap {
  width: 96%;
  display: table;
  margin-top: 25px;
}
/* line 166, ../sass/custom.scss */
.main .progress-wrap .report-acivity {
  display: table-cell;
  background: #fff;
  color: #32024e;
  vertical-align: top;
  padding: 25px 20px;
}
/* line 172, ../sass/custom.scss */
.main .progress-wrap .report-acivity h1 {
  color: #32024e;
  font-family: SpecialElite !important;
  font-weight: normal !important;
  font-style: normal !important;
  -webkit-font-smoothing: antialiased !important;
  -moz-osx-font-smoothing: grayscale !important;
  margin: 0;
  font-size: 22px;
}
/* line 183, ../sass/custom.scss */
.main .progress-wrap .report-acivity .submit button {
  font-size: 18px;
  color: #fff;
  margin-left: 0;
  background: #32024e;
  font-family: SpecialElite !important;
  font-weight: normal !important;
  font-style: normal !important;
  -webkit-font-smoothing: antialiased !important;
  -moz-osx-font-smoothing: grayscale !important;
  border: none !important;
}
/* line 196, ../sass/custom.scss */
.main .progress-wrap .report-acivity .block {
  margin-bottom: 0;
}
/* line 198, ../sass/custom.scss */
.main .progress-wrap .report-acivity .block form {
  width: 100%;
  display: inline-block;
  margin-top: 30px;
}
/* line 201, ../sass/custom.scss */
.main .progress-wrap .report-acivity .block form .form-item-activity-progress-select {
  margin: 0;
  width: 66%;
  float: left;
}
/* line 205, ../sass/custom.scss */
.main .progress-wrap .report-acivity .block form .form-item-activity-progress-select label {
  font-size: 16px;
  color: #32024e;
  font-family: Raleway-Medium !important;
  font-style: normal !important;
  font-weight: normal !important;
  -webkit-font-smoothing: antialiased !important;
  margin-bottom: 10px;
  margin-right: 10px;
}
/* line 215, ../sass/custom.scss */
.main .progress-wrap .report-acivity .block form .form-item-activity-progress-select .activities_list_progress {
  width: 91% !important;
  float: left;
  height: auto !important;
}
/* line 220, ../sass/custom.scss */
.main .progress-wrap .report-acivity .block form .form-item-activity-progress-select .activities_list_progress .chosen-single {
  border-radius: 0;
  border: 1px solid #32024e;
  background: #fff;
  color: #32024e;
  line-height: 19px;
  font-family: Raleway-Medium !important;
  font-style: normal !important;
  font-weight: normal !important;
  -webkit-font-smoothing: antialiased !important;
}
/* line 230, ../sass/custom.scss */
.main .progress-wrap .report-acivity .block form .form-item-activity-progress-select .activities_list_progress .chosen-single div {
  width: 33px;
  background: #32024e;
}
/* line 233, ../sass/custom.scss */
.main .progress-wrap .report-acivity .block form .form-item-activity-progress-select .activities_list_progress .chosen-single b {
  background: none;
  position: relative;
}
/* line 237, ../sass/custom.scss */
.main .progress-wrap .report-acivity .block form .form-item-activity-progress-select .activities_list_progress .chosen-single b:after {
  content: "";
  border-left: 7px solid transparent;
  border-right: 7px solid transparent;
  border-top: 7px solid #fff;
  position: absolute;
  left: 10px;
  top: 7px;
  display: inline-block;
}
/* line 252, ../sass/custom.scss */
.main .progress-wrap .report-acivity .block form .container-inline-date {
  width: 100%;
  float: left;
  clear: none;
  margin-top: 10px;
}
/* line 256, ../sass/custom.scss */
.main .progress-wrap .report-acivity .block form .container-inline-date > .form-item.form-item-date {
  width: 100%;
  margin-right: 0;
}
/* line 259, ../sass/custom.scss */
.main .progress-wrap .report-acivity .block form .container-inline-date > .form-item.form-item-date input {
  
  padding: 4px 10px;
  margin-top: 10px;
  position: relative;
  bottom: 5px;
}
/* line 267, ../sass/custom.scss */
.main .progress-wrap .report-acivity .block form .container-inline-date > .form-item.form-item-date label {
  font-family: Raleway-Medium !important;
  font-style: normal !important;
  font-weight: normal !important;
  -webkit-font-smoothing: antialiased !important;
  color: #32024e;
  font-size: 16px;
 
}
/* line 276, ../sass/custom.scss */
.main .progress-wrap .report-acivity .block form .container-inline-date > .form-item.form-item-date .date-padding {
  width: 80%;
}
/* line 278, ../sass/custom.scss */
.main .progress-wrap .report-acivity .block form .container-inline-date > .form-item.form-item-date .date-padding label {
  display: none;
}
/* line 281, ../sass/custom.scss */
.main .progress-wrap .report-acivity .block form .container-inline-date > .form-item.form-item-date .date-padding .description {
  display: none;
}
ul.contextual-links {
  display: none;
}
/* line 291, ../sass/custom.scss */
.main .progress-wrap .reward-won {
  display: table-cell;
  vertical-align: middle;
}
/* line 296, ../sass/custom.scss */
.main .progress-wrap .reward-won .view {
  color: #32024e;
  background: #fff;
  width: 82%;
  margin: 0 auto;
  padding: 22px;
}
/* line 303, ../sass/custom.scss */
.main .progress-wrap .reward-won .view .pager {
  margin-bottom: 0;
  text-align: right;
  list-style: none;
}
/* line 306, ../sass/custom.scss */
.main .progress-wrap .reward-won .view .pager .pager-current {
  display: none;
}
/* line 310, ../sass/custom.scss */
.main .progress-wrap .reward-won .view .pager li a {
  color: #32024e;
  font-size: 16px;
  font-family: Raleway-Bold !important;
  font-style: normal !important;
  font-weight: normal !important;
  -webkit-font-smoothing: antialiased !important;
  -moz-osx-font-smoothing: grayscale !important;
  -moz-font-smoothing: grayscale !important;
  text-transform: capitalize;
}
/* line 323, ../sass/custom.scss */
.main .progress-wrap .reward-won .view .view-header {
  font-family: SpecialElite !important;
  font-weight: normal !important;
  font-style: normal !important;
  -webkit-font-smoothing: antialiased !important;
  -moz-osx-font-smoothing: grayscale !important;
}
/* line 329, ../sass/custom.scss */
.main .progress-wrap .reward-won .view .view-header span {
  font-size: 22px;
}
/* line 335, ../sass/custom.scss */
.main .progress-wrap .reward-won .view .view-content .item-list ul {
  list-style: numeric;
}
/* line 337, ../sass/custom.scss */
.main .progress-wrap .reward-won .view .view-content .item-list ul li {
  font-size: 16px;
  font-family: Raleway-Medium !important;
  font-style: normal !important;
  font-weight: normal !important;
  -webkit-font-smoothing: antialiased !important;
}
/* line 349, ../sass/custom.scss */
.main .progress-wrap .progress-rewards {
  width: 22%;
  display: table-cell;
  vertical-align: middle;
  font-size: 22px;
  color: #32024e;
  font-family: SpecialElite !important;
  font-weight: normal !important;
  font-style: normal !important;
  -webkit-font-smoothing: antialiased !important;
  -moz-osx-font-smoothing: grayscale !important;
  background: #f6f45a;
  text-align: center;
}
/* line 362, ../sass/custom.scss */
.main .progress-wrap .progress-rewards p {
  font-size: 22px;
  font-family: SpecialElite !important;
  font-weight: normal !important;
  font-style: normal !important;
  -webkit-font-smoothing: antialiased !important;
  -moz-osx-font-smoothing: grayscale !important;
  color: #32024e;
  text-align: center;
}
/* line 374, ../sass/custom.scss */
.main .progress-main {
  margin-top: 82px;
  width: 100%;
  display: table;
  position: relative;
  padding-bottom: 25px;
}
select##edit-activity-progress-select {
  border: 1px solid #32024E;
  color: #32024E;
}
/* line 380, ../sass/custom.scss */
.main .progress-main h1 {
  width: 95%;
  display: inline-block;
  margin-top: 0;
  background: #7eb600;
  font-size: 24px;
  font-family: SpecialElite !important;
  font-weight: normal !important;
  font-style: normal !important;
  -webkit-font-smoothing: antialiased !important;
  -moz-osx-font-smoothing: grayscale !important;
  color: #fff;
  padding-left: 15px;
  padding-top: 15px;
  padding-bottom: 7px;
  position: absolute;
  width: 100%;
  margin-bottom: 0;
  top: -55px;
}
/* line 400, ../sass/custom.scss */
.main .progress-main .new-row {
  width: 100%;
  display: table-row;
}
/* line 403, ../sass/custom.scss */
.main .progress-main .new-row > .grid {
  width: 12.26%;
  display: inline-block;
  vertical-align: top;
  color: #32024e;
  padding: 10px 1.8%;
  position: relative;
  background: #fff;
  height: 200px;
  border: 0.5px solid #cccccc;
  bottom: 4px;
}
/* line 411, ../sass/custom.scss */
.main .progress-main .new-row > .grid.active-background {
  background: #f6f45a;
}
/* line 417, ../sass/custom.scss */
.main .progress-main .new-row > .grid.inserted {
  background-image: url("images/libraryzurb/complete.gif");
  background-repeat: no-repeat;
  background-position: center bottom 42px;
}
/* line 422, ../sass/custom.scss */
.main .progress-main .new-row > .grid p {
  font-family: SpecialElite !important;
  font-weight: normal !important;
  font-style: normal !important;
  -webkit-font-smoothing: antialiased !important;
  -moz-osx-font-smoothing: grayscale !important;
  line-height: 1.2;
  font-size: 14px;
}
/* line 430, ../sass/custom.scss */
.main .progress-main .new-row > .grid p.won-rew {
  position: absolute;
  bottom: 10px;
  margin-bottom: 0;
  left: 7.2%;
  width: 90%;
}


  </style>';
  $output .= "

  <div class = 'main'><div class='progress-page'>
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
$output .= '</div></div></div>';
echo $output;
}

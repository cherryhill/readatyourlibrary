<?php
  //drupal_add_js(drupal_get_path('module', 'play_progress_calendar') . '/js/jquery-ui.min.js');
  //drupal_add_js(drupal_get_path('module', 'play_progress_calendar') . '/js/fullcalendar.min.js');
  //drupal_add_js(drupal_get_path('module', 'play_progress_calendar') . '/js/gcal.js');

  drupal_add_js(drupal_get_path('module', 'play_progress_calendar') . '/fullcalendar/lib/moment.min.js');
  drupal_add_js(drupal_get_path('module', 'play_progress_calendar') . '/fullcalendar/lib/jquery.min.js');
  drupal_add_js(drupal_get_path('module', 'play_progress_calendar') . '/fullcalendar/lib/jquery-ui.min.js');
  drupal_add_js(drupal_get_path('module', 'play_progress_calendar') . '/fullcalendar/fullcalendar.min.js');
  drupal_add_js(drupal_get_path('module', 'play_progress_calendar') . '/js/drag_drop_calendar.js');
  drupal_add_js(drupal_get_path('module', 'play_progress_calendar') . '/printThis/printThis.js');

  drupal_add_css(drupal_get_path('module', 'play_progress_calendar') . '/fullcalendar/fullcalendar.css', array('group' => CSS_DEFAULT, 'every_page' => TRUE));
  // drupal_add_css(drupal_get_path('module', 'play_progress_calendar') . '/fullcalendar/fullcalendar.print.css', array('group' => CSS_DEFAULT, 'every_page' => TRUE));
  drupal_add_css(drupal_get_path('module', 'play_progress_calendar') . '/css/calendar.css', array('group' => CSS_DEFAULT, 'every_page' => TRUE));
  // drupal_add_css(drupal_get_path('module', 'play_progress_calendar') . '/progress.css', array('group' => CSS_DEFAULT, 'every_page' => TRUE));

?>

<!-- Tpl file for children progress page -->
<div class="progress-page-wrap">
<div class="print-pdf"><button class="printBtn hidden-print">Print Calendar</button></div>
	<div id='wrap'>
    <div class= 'sticker-block' id='sticker-wrap'>
      <span class="prog-name"><h2> <?php print(t("Kids Summer Reading")) ?> </h2></span>
      <span class="prog-days"><h3> <?php print(t("Days of Reading")) ?> </h3></span>
      <span class="prog-sticker-info"><p> <?php print(t("Drag and drop a sticker to mark the days you've read!")) ?> </p></span>
      <?php
  			$query = db_select('eck_activity','act');
        $query->join('field_data_field_activity_fired_hook','hook', 'hook.entity_id = act.id');
        $query->fields('act', array('id'));
        $query->condition('hook.field_activity_fired_hook_value','progress_page');
        $result = $query->execute()->fetchAll();
        foreach ($result as $key => $value) {
          $activity_ids[] = $value->id;
          if (isset($activity_list)){
            $activity_list = $activity_list.','. $value->id ;
          } else{
            $activity_list = $value->id ;
          }
          //$GLOBALS['activity_list']= array($value->id);
        }
        $associated_rewards = pl_get_activity_reward_ids($activity_ids);
        // print_r($associated_rewards);
        // // unset($_SESSION);
        // print_r($_SESSION);

  			if ($vocabulary = taxonomy_vocabulary_machine_name_load('calendar_sticker')) {
          $tree = taxonomy_get_tree($vocabulary->vid);
      ?>
      		<div id='external-events' value=<?php print($activity_list); ?> >
      		<?php
  				  foreach ($tree as $term) {
  						$image = taxonomy_term_load($term->tid);
              $staff_sticker_field = field_get_items('taxonomy_term', $image, 'field_staff_record_image');
              $staff_sticker_flag = $staff_sticker_field[0]['value'];
              if($staff_sticker_flag <> 1){
                if ($image_items = field_get_items('taxonomy_term', $image, 'field_cal_sticker_image')) {
                  $sticker_counter++;
                  if ($sticker_counter<=5){
    							   $uri = $image_items[0]['uri'];
    							   $external_url = file_create_url($uri);
                      // $external_urls[$term->tid] = $external_url;
    							   print('<div id ='.$term->tid.' class="fc-event" style="inline-block">'.'<img src ='.$external_url.' id = sticker_'.$term->tid.'></div>');
                  }
                }
              }
              else{
               if ($image_items = field_get_items('taxonomy_term', $image, 'field_cal_sticker_image')) {
                     $uri = $image_items[0]['uri'];
                     $external_url = file_create_url($uri);
                      // $external_urls[$term->tid] = $external_url;
                     print('<div id ='.$term->tid.' style="display:none">'.'<img src ='.$external_url.' id = sticker_'.$term->tid.'></div>');
                } 
              }
          	}
            if($sticker_counter == 0){
              drupal_set_message("No stickers are added for Calendar stickers", "error");
            }
      	}
  		?>
    </div>
  </div>


<div class="rewards">
  <?php
    // $block = module_invoke('views', 'block', 'view', 'rewards_dashboard');
    print views_embed_view('Rewards_Progress', 'block');;
  ?>
</div>

  <div class='reading-progress'>
    <div id='next-reward'>
      <?php
        $req_points = play_library_program_next_close_reward_points($activity_ids);
        if($req_points == 1) {
          $next_rew = t('<strong>'.$req_points.'</strong> more day of reading needed to receive your next prize');
        }
        else if ($req_points > 1){
          $next_rew = t('<strong>'.$req_points.'</strong> more days of reading needed to receive your next prize');
        }

        else {
          $next_rew = t('<strong>Congratulations!</strong> You have completed Reading Program.');
        }
        print('<h3>'.$next_rew.'</h3>');
      ?>
    </div>
  </div>
	</div>
<!-- Loading HTML -->

<div id='loading' class="cssload-container">
  <div class="cssload-loading"><i></i><i></i></div>
</div>
<!-- <div id=loading class="cssload-thecube">
  <div class="cssload-cube cssload-c1"></div>
  <div class="cssload-cube cssload-c2"></div>
  <div class="cssload-cube cssload-c4"></div>
  <div class="cssload-cube cssload-c3"></div>
</div>
 -->	<!-- This is for calendar div -->
  <div class='calendar-wrapper'>
  	<div id='calendar'></div>
  	<!-- <div id="print_button">Print Calendar</div> -->
    <!-- <button onclick="printPage()">Print this page</button> -->
  </div>
</div>

<?php
  //drupal_add_js(drupal_get_path('module', 'play_progress_calendar') . '/js/jquery-ui.min.js');
  //drupal_add_js(drupal_get_path('module', 'play_progress_calendar') . '/js/fullcalendar.min.js');
  //drupal_add_js(drupal_get_path('module', 'play_progress_calendar') . '/js/gcal.js');
  
  drupal_add_js(drupal_get_path('module', 'play_progress_calendar') . '/fullcalendar/lib/moment.min.js');
  drupal_add_js(drupal_get_path('module', 'play_progress_calendar') . '/fullcalendar/lib/jquery.min.js');
  drupal_add_js(drupal_get_path('module', 'play_progress_calendar') . '/fullcalendar/lib/jquery-ui.min.js');
  drupal_add_js(drupal_get_path('module', 'play_progress_calendar') . '/fullcalendar/fullcalendar.min.js');
  drupal_add_js(drupal_get_path('module', 'play_progress_calendar') . '/js/drag_drop_calendar.js');

  drupal_add_css(drupal_get_path('module', 'play_progress_calendar') . '/fullcalendar/fullcalendar.css', array('group' => CSS_DEFAULT, 'every_page' => TRUE));
  // drupal_add_css(drupal_get_path('module', 'play_progress_calendar') . '/fullcalendar/fullcalendar.print.css', array('group' => CSS_DEFAULT, 'every_page' => TRUE));
  drupal_add_css(drupal_get_path('module', 'play_progress_calendar') . '/css/calendar.css', array('group' => CSS_DEFAULT, 'every_page' => TRUE));
  // drupal_add_css(drupal_get_path('module', 'play_progress_calendar') . '/progress.css', array('group' => CSS_DEFAULT, 'every_page' => TRUE));

?>

<!-- Tpl file for children progress page -->
<div class="progress-page-wrap">
	<div id='wrap'>
    <div id='sticker-wrap'>
  		<?php 
  			$query = db_select('eck_activity','act');
        		$query->join('field_data_field_activity_fired_hook','hook', 'hook.entity_id = act.id');
        		$query->fields('act', array('id'));
        		$query->condition('hook.field_activity_fired_hook_value','progress_page');
        		$result = $query->execute()->fetchAll();
        			foreach ($result as $key => $value) {
        				if (isset($activity_list)){
            				$activity_list = $activity_list.','. $value->id ;
            			} else{
            				$activity_list = $value->id ;
            			}
            			//$GLOBALS['activity_list']= array($value->id);
            		}

  			if ($vocabulary = taxonomy_vocabulary_machine_name_load('calendar_sticker')) {
      			$tree = taxonomy_get_tree($vocabulary->vid); ?>
      			<div id='external-events' value=<?php print($activity_list); ?> >
      			<?php 
  				foreach ($tree as $term) {
  						$image = taxonomy_term_load($term->tid);
              			if ($image_items = field_get_items('taxonomy_term', $image, 'field_cal_sticker_image')) {
  							$uri = $image_items[0]['uri'];
  							$external_url = file_create_url($uri);
  							print('<div id ='.$term->tid.' class="fc-event" style="inline-block">'.'<img src ='.$external_url.'></div>');
                			}
                	}
        		}
  		?>
    </div>
		<?php 
			$query = db_select('eck_activity','act');
      		$query->join('field_data_field_activity_fired_hook','hook', 'hook.entity_id = act.id');
      		$query->fields('act', array('id'));
      		$query->condition('hook.field_activity_fired_hook_value','progress_page');
      		$result = $query->execute()->fetchAll();
      			foreach ($result as $key => $value) {
          	//		global $activity_list = array($value->id);
          		}
        ?>
<?php
	$block = module_invoke('views', 'block', 'view', 'block_sticker');
    print $block['content'];
?>
	   <!-- This is the drupal views block of sticker -->

		<div class="sticker-block"> 
          <?php //print views_embed_view('dropdown_sticker_list', 'block'); ?>
		</div>

		<!-- This is the reward list won by patron  -->

		<div class="pro-reward-block"> 
          <?php //print views_embed_view('user_rewrad_for_progress_page', 'block'); ?>
		</div>
         
         <!-- This is the user progress for read activity. -->

		<div class="pro-progress-block"> 
          <?php 
            //$block = module_invoke('play_progress_calendar', 'block_view', 'user_prize_block');
            print render($block['content']); 
          ?>
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
	<div id="print_button">Print Calendar</div>
</div>

	<?php 
      //$block = module_invoke('play_progress_calendar', 'block_view', 'calendar-data');
      //print render($block['content']); 
    ?>

</div>
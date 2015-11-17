<?php
//$Id openbadging-my-backpack-view.tpl.php

/**
 * User group view for badges on user's manage backpack which is created by user.
 * Only user can see these groups and user can set badge & group privacy.
 * 
 * Variables:
 * "Variables['view']" variable to show view result.
 *    
 */
?>
<div class="my-backpack-badges-view">
  <div class="my-backpack-badges-content-field">
    <?php
    if (empty($variables['view'])) {
			  global $user;
			  $status = achievements_unlocked_already(NULL, $user->uid);
        if($status != NULL){
      print t('If you have badges you have been awarded, you can group them here and change their privacy setting.');
		  }   
    } else {
      foreach ($variables['view'] as $key => $value) {
        ?>

        <?php
        global $base_url;
        $check_status_privacy = openbadging_user_group_status_check($value->bid);
        if ($check_status_privacy == 1) {
          $image_url_unlock = $base_url . '/' . drupal_get_path('module', 'openbadging_manage_backpack') . '/images/private.png';
        } else {
          $image_url_unlock = $base_url . '/' . drupal_get_path('module', 'openbadging_manage_backpack') . '/images/public.png';
        }
        $criteria_link_unlock = 'openbadging/' . $value->bid . '/edit';
        print '<h3>' . $value->openbadging_title . l(t('<img src="' . render($image_url_unlock) . '"/>'), $criteria_link_unlock, array('html' => TRUE)) . '</h3>';
        ?>
        <div class="my-backpack-edit-delete-view">
          <?php
          global $base_url;
          $criteria_link_edit = 'openbadging/' . $value->bid . '/edit';
          $image_url_edit = $base_url . '/' . drupal_get_path('module', 'openbadging_manage_backpack') . '/images/edit.png';
          print l(t('<img src="' . ($image_url_edit) . '"/>'), $criteria_link_edit, array('html' => TRUE));
          ?> 
        </div>
        <div class="my-backpack-badge-image">
          <?php
          global $base_url;
          foreach ($value->field_field_badge_entity_reference_1 as $key1 => $value1) {
						$badge = entity_load('openbadging', $ids = array($value1['raw']['entity']->bid));
            $img_url = $value1['raw']['entity']->field_badge_entity_unlock_image['und'][0]['uri'];

            $new_path = explode('.png', $img_url);
            $img_url = $new_path[0] . '-' . $value->_field_data['bid']['entity']->uid . '.png';

            $img = theme('image_style', array('style_name' => '110_110', 'path' => $img_url, 'alt' => NULL, 'title' => NULL));
            $title = openbadging_get_badge_title_mozila_send($value1['raw']['entity']->bid);
            ?>
            <div class="my-backpack-badge-image-outer">
            <div class="my-backpack-badge-image-inner">
            <?php
						$options = array(
							'attributes' => array(
							'class' => array('simple-dialog'), 
							'rel' => 'width:900;resizable:false;position:[center,60]',
							'title' => $badge[$value1['raw']['entity']->bid]->title,
							'name' => 'main',
						  ),
						'html' => true
						);  
            print l($img, $base_url . '/openbadging/' . $value1['raw']['entity']->bid, $options);
            ?>
             </div>
             
             <div class="my-backpack-badge-image-title">
            <?php
            print l($badge[$value1['raw']['entity']->bid]->title, $base_url . '/openbadging/' . $value1['raw']['entity']->bid, $options);
             ?>
             </div>
             </div>
          <?php
          }
          ?>           
        </div>
      <?php
      }
    }
    ?>
  </div>       
</div>

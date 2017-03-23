<!-- Bingo Progress Report Page -->
<?php
  //Add js file for bingo cards
  drupal_add_js(drupal_get_path('module', 'play_progress_bingo_cards') . '/js/play_progress_bingo_cards.js');
  //Add print js file for bingo cards
  // drupal_add_js(drupal_get_path('module', 'play_progress_bingo_cards') . '/printThis/printThis.js');

  drupal_add_css(drupal_get_path('module', 'play_progress_bingo_cards') . '/css/play_progress_bingo_cards.css', array('group' => CSS_DEFAULT, 'every_page' => TRUE));
  drupal_add_js(libraries_get_path('printThis', TRUE). '/printThis.js');
  global $user;
  global $base_url;
  $current_uid = $user->uid;
  // $raff_count = pl_raffle_count($current_uid);
  $imgStyle = 'avatar_style';
?>
<div class="bingo-progress-page">
 <div class="title">
  <div class="page-title">
    <h1 id = "title">
      Progress
      <?php /*print variable_get('pg_title'); */?>
    </h1>
  </div>
  <div class="print-pdf"><button class="printBtn hidden-print">Print Progress Report</button> </div>
  </div>


  <div class="user-info">
    <!-- Print avatar image and user name -->
    <div class="avatar-block">
      <?php
        //Get avatar image and user name for print
        global $user;
        $user_pf = profile2_load_by_user($user->uid);
        $img_id = $user_pf['main']->field_user_avatar[LANGUAGE_NONE][0]['target_id'];
        $user_name = $user->name;
        $query = db_select('field_data_field_avatar_image', 't');
        $query->join('file_managed', 'n', 'n.fid = t.field_avatar_image_fid');
        $result = $query
          ->fields('n', array('uri'))
          ->condition('t.entity_id', $img_id)
          ->execute();
        $img_uri_query = $result->fetchObject();
        $img_uri = $img_uri_query->uri;
        $img_path = file_create_url($img_uri);
        $img = "<img src='$img_path'>";
        print("<div class='avatar-image'>".$img."</div>");
        print("<div class='uname'>".$user_name."</div>");
      ?>
    </div>
    <!-- Print Points info -->
    <div class="user-points">
      <?php
        $points = play_library_program_get_activity_points();
        if($points['review']>0){
          print(t("<div class='review-points'>Review Points: <strong>". $points['review']. "</strong></div>") );
        }
        if($points['booklist']>0){
          print(t("<div class='booklist-points'>Booklist Points: <strong>". $points['booklist']. "</strong></div>") );
        }
        if($points['activity']>0){
          print(t("<div class='activity-points'>Activity Points: <strong>". $points['activity']. "</strong></div>") );
        }
      ?>
    </div>

    <div class="rewards-info">
      <?php
        $raff_count = _play_library_program_get_raffle_ticket_count();
        if($raff_count>0){
          print (t("Raffle Tickets Earned: <strong>$raff_count</strong>"));
        }
        print(t("<div class='general-points'>Total Points: <strong>". $points['general']. "</strong></div>") );
      ?>
    </div>
  </div>

  <div class="progress-wrap">
    <div><h2>Bingo!</h2></div>
    <div><p>Complete any 3 library activities and enter the raffle</p></div>
    <div class="bingo-progress-main">
    <div class="activities left-activity">
      <div class="report-acivity">
        <div><h3>1. Report an Activity</h3></div>
        <?php
          $block = block_load('play_progress_bingo_cards', 'progress_submit_block');
          $render_block = _block_get_renderable_array(_block_render_blocks(array($block)));
          $output = drupal_render($render_block);
          print $output;
        ?>
        <!--  <div class="submit">
          <button id="pg-report">Submit</button>
        </div> -->
      </div>
     </div>
     <div class="activities right-activity">
      <div class="write-review">
      <h3>2. Write A Review</h3>
        <?php

          print(drupal_render(drupal_get_form('pl_progress_create_reviews')));

        ?>
        <div><h3><a href="node/add/booklist">3. Create A Booklist</a></h3>
             <span>Earn a raffle ticket when your Review or Booklist gets approved.</span>
        </div>
      </div>
    </div>
    <?php
      global $user;
      //Get Pager nids


      // print_r($pager);die();
      if(!empty($_GET['page'])){
        $node_id_offset = ($_GET['page']-1)*4;
      } else{
        $node_id_offset = 0;
      }

      //Create new node if active bingo node is not available
      if (empty($_SESSION['bingo_node'])){
        play_progress_bingo_cards_get_bingo_node();
      }

      //Update pager array if new node is added
      if(empty($_SESSION['pager'])){
        $pager = play_progress_bingo_cards_get_pager_array();
      } else{
        $pager = $_SESSION['pager'];
      }

      //Get Node content for bingo nodes
      $res = play_progress_bingo_cards_get_cards(array_slice($pager,$node_id_offset,4));

      //create array with node id as key
      foreach ($res as $value) {
        $nid = $value->nid;
        $act_type = $value->type;
        $node_data[$nid]['type'] = $act_type;
        if($act_type == 'bingo_card'){
          $node_data[$nid][$value->field_cell_id_value]= array('title'=>$value->field_cell_data_value, 'date'=>date('m-d-Y',strtotime($value->field_bingo_activity_date_value)));
          $node_data[$nid]['status']= $value->field_card_status_value;
        }
        if($act_type != 'bingo_card'){
          $node_data[$nid]= array('type'=>$value->name , 'title'=>$value->title, 'date'=>date('d-m-Y',($value->created)));
        }
      }

      
      //Print bingo cards
      foreach ($node_data as $key => $value) {
        $card_id = array_search($key, $pager)+1;
        if ($card_id%2 == 0){
          $card_class = 'even';
        } else{
          $card_class = 'odd';
        }
        //If node typy is bingo_card create 3x3 table
        if ($value['type'] == 'bingo_card'){
          $status = $value['status'] ;
          if ($status==1){
            $active_class ='active';
          } else{
            $active_class ='not-active';
          }

          if($act_type ='bingo_card')
            print("<div class='bingo-card $active_class $card_class' active = $status>");
            for ($cell_counter = 1 ; $cell_counter <= 9 ; $cell_counter++){
              if($cell_counter==1){
                print("<table id=$key><tbody>");
              }
              if($cell_counter==1 || $cell_counter==4 || $cell_counter==7){
                print('<tr>');
              }
              if(!array_key_exists($cell_counter, $value)){
                print('<td id='.$cell_counter.'>');
              }
              if(array_key_exists($cell_counter, $value)){
                print(t("<td id=$cell_counter class ='filled-cell' >"));
                print(t('<span class="act-date">'.$value[$cell_counter]['date'].'</span>'));
                print(t('<span class="act-title">'.$value[$cell_counter]['title'].'</span>'));
              }
              print('</td>');
              if($cell_counter==3 || $cell_counter==6 || $cell_counter==9){
                print('</tr>');
              }
              if ($cell_counter==9){
                print('</tbody></table>');
              }
            }
            //print("</div>");
          }
          //Add single cell table for non bingo card nodes
          else{
            $node_title = $value['title'];
            $node_date = $value['date'];
            $node_type = $value['type'];
            print(t("<div class='non-bingo-card $card_class'><table id = $key><tbody><tr><td id=1 class='filled-cell'><span>$node_date</span><span>$node_type</span><span><a href='node/$key'>$node_title</a></span></td></tr></tbody></table>"));
          }
          //Print card Number
          print(t("<div class='card-no'>Card ". (array_search($key, $pager)+1) ."</div></div>"));
          // print('</div>');
        }
      ?>
    </div>

    <div class="pager">
      <?php
        //Print pager
        $page_count= floor(sizeof($pager)/4);
        if(sizeof($pager)%4 != 0){
          $page_count++;
        }
        if($page_count > 1){
          print("<ul class='pagination pager'>");
          if($page_count > 4){
            print("<li class='arrow'><a href=#><</a></li>");
          }
          for ($counter=1; $counter<=$page_count; $counter++){
            if ($counter == $_GET['page'] ){
              print("<li class='current'><a>$counter</a></li>");
            } else{
              print("<li><a href='?page=$counter'>$counter</a></li>");
            }
          }
          if($page_count > 4){
            print("<li class='arrow'><a href='?page=$page_count'>></a></li>");
          }
          print_r('</ul>');
        }?>
    </div>
  </div>
</div>

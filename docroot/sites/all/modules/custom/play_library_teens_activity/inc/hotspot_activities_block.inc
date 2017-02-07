<?php
/**
 * function callback for Activities landing page
 */
function activities_page() {

 // Write a query to get nid of activity type conent.
  $query = db_select('node','n')
    ->fields('n',array('nid'))
    ->condition('type', 'activity')
    ->execute()
    ->fetchAll();
  $nid = $query['nid'];

  // Write query to get the taxonomy term name of activity list filed of activity content type.

  $que = db_select('node', 'n');  
  $que->join('field_data_field_activity_list', 'alist', 'n.nid = alist.entity_id'); 
  $que->join('taxonomy_term_data', 'ttd', 'alist.field_activity_list_tid = ttd.tid');
  $que->join('field_data_field_read_review', 'read_r', 'alist.field_activity_list_tid = read_r.entity_id');
  $que->join('field_data_field_write_review', 'write_r', 'alist.field_activity_list_tid = write_r.entity_id');
  //$que->condition('n.nid', 4784);
  //$que->fields('n', array('nid'));
  $que->fields('ttd', array('name'));
  $que->fields('read_r', array('field_read_review_url'));
  $que->fields('write_r', array('field_write_review_url'));
  $result = $que->execute()->fetchAll();
  $read_review_lebal_name = array();
  $write_review_lebal_name = array();
  $read_review_lebal_name['all'] = 'select from following';
  $write_review_lebal_name['all'] = 'Select from following';
  
  foreach ($result as $key => $value) {
  	$read_review_url = $value->field_read_review_url;
  	$write_review_url = $value->field_write_review_url;
  	$read_review_lebal_name[$read_review_url] = $value->name;
  	$write_review_lebal_name[$write_review_url] = $value->name;
  }


  $form['write_review'] = array(
    '#title' => t('Write a Review'),
    '#type' => 'select',
    '#description' => "Select the project count type.",
    '#options' => $write_review_lebal_name,
  );
  $form['read_review'] = array(
    '#title' => t('Read Existing Reviews'),
    '#type' => 'select',
    '#description' => "Select the project count type.",
    '#options' => $read_review_lebal_name,
  );

  return $form;  

}

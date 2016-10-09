<?php

// function for providing autocomplete for users
function _author_name_autocomplete($string = ''){
	$author_users = array();
  $sname_query = db_select('users','u');
  $sname_query->condition('u.name', '%' . db_like($string) . '%', 'LIKE');
  $sname_query->fields('u',array('name'));
  $sname_query->range(0, 15);

  $sname_result = $sname_query->execute()->fetchAll();

  foreach($sname_result as $res){
    $author_users[$res->name] = check_plain($res->name);
  }

 drupal_json_output($author_users);
}
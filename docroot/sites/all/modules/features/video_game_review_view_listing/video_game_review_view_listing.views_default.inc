<?php
/**
 * @file
 * video_game_review_view_listing.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function video_game_review_view_listing_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'video_game_review';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Video Game Review';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Video Game Review';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['exposed_form']['options']['submit_button'] = 'Search';
  $handler->display->display_options['exposed_form']['options']['sort_asc_label'] = 'Ascending';
  $handler->display->display_options['exposed_form']['options']['sort_desc_label'] = 'Descending';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '10';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['quantity'] = '9';
  $handler->display->display_options['pager']['options']['expose']['items_per_page'] = TRUE;
  $handler->display->display_options['pager']['options']['expose']['items_per_page_options'] = '10, 20, 30';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['row_options']['inline'] = array(
    'title' => 'title',
    'counter' => 'counter',
  );
  /* Header: Global: Text area */
  $handler->display->display_options['header']['area']['id'] = 'area';
  $handler->display->display_options['header']['area']['table'] = 'views';
  $handler->display->display_options['header']['area']['field'] = 'area';
  $handler->display->display_options['header']['area']['content'] = '<h2 class = reviews-title>Reviews & Booklists</h2>
<div class="viewmenu">View: <a href="/video_game_review">All</a> | <a href="/video_game_review/staff">Posted by Staff</a> | <a href="/video_game_review/players">Posted by Players</a></div>
<h2 class = reviews-subtitle>VIDEO GAME REVIEWS</h2>';
  $handler->display->display_options['header']['area']['format'] = 'simple_html';
  /* Relationship: Content: Author */
  $handler->display->display_options['relationships']['uid']['id'] = 'uid';
  $handler->display->display_options['relationships']['uid']['table'] = 'node';
  $handler->display->display_options['relationships']['uid']['field'] = 'uid';
  /* Relationship: Flags: like counter */
  $handler->display->display_options['relationships']['flag_count_rel']['id'] = 'flag_count_rel';
  $handler->display->display_options['relationships']['flag_count_rel']['table'] = 'node';
  $handler->display->display_options['relationships']['flag_count_rel']['field'] = 'flag_count_rel';
  $handler->display->display_options['relationships']['flag_count_rel']['required'] = 0;
  $handler->display->display_options['relationships']['flag_count_rel']['flag'] = 'like';
  /* Relationship: Flags: like */
  $handler->display->display_options['relationships']['flag_content_rel']['id'] = 'flag_content_rel';
  $handler->display->display_options['relationships']['flag_content_rel']['table'] = 'node';
  $handler->display->display_options['relationships']['flag_content_rel']['field'] = 'flag_content_rel';
  $handler->display->display_options['relationships']['flag_content_rel']['required'] = 0;
  $handler->display->display_options['relationships']['flag_content_rel']['flag'] = 'like';
  $handler->display->display_options['relationships']['flag_content_rel']['user_scope'] = 'any';
  /* Relationship: User: Profile */
  $handler->display->display_options['relationships']['profile']['id'] = 'profile';
  $handler->display->display_options['relationships']['profile']['table'] = 'users';
  $handler->display->display_options['relationships']['profile']['field'] = 'profile';
  $handler->display->display_options['relationships']['profile']['relationship'] = 'uid';
  $handler->display->display_options['relationships']['profile']['bundle_types'] = array(
    'main' => 'main',
  );
  /* Field: Global: View result counter */
  $handler->display->display_options['fields']['counter']['id'] = 'counter';
  $handler->display->display_options['fields']['counter']['table'] = 'views';
  $handler->display->display_options['fields']['counter']['field'] = 'counter';
  $handler->display->display_options['fields']['counter']['label'] = '';
  $handler->display->display_options['fields']['counter']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['counter']['counter_start'] = '1';
  $handler->display->display_options['fields']['counter']['reverse'] = 0;
  /* Field: Content: Catalog Link */
  $handler->display->display_options['fields']['field_catalog_link_video_game_1']['id'] = 'field_catalog_link_video_game_1';
  $handler->display->display_options['fields']['field_catalog_link_video_game_1']['table'] = 'field_data_field_catalog_link_video_game';
  $handler->display->display_options['fields']['field_catalog_link_video_game_1']['field'] = 'field_catalog_link_video_game';
  $handler->display->display_options['fields']['field_catalog_link_video_game_1']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_catalog_link_video_game_1']['click_sort_column'] = 'url';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['path'] = '[field_catalog_link_video_game_1]';
  $handler->display->display_options['fields']['title']['alter']['target'] = '_blank';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  /* Field: Flags: Flag counter */
  $handler->display->display_options['fields']['count']['id'] = 'count';
  $handler->display->display_options['fields']['count']['table'] = 'flag_counts';
  $handler->display->display_options['fields']['count']['field'] = 'count';
  $handler->display->display_options['fields']['count']['relationship'] = 'flag_count_rel';
  $handler->display->display_options['fields']['count']['label'] = 'Likes';
  /* Field: Content: Platform */
  $handler->display->display_options['fields']['field_platform']['id'] = 'field_platform';
  $handler->display->display_options['fields']['field_platform']['table'] = 'field_data_field_platform';
  $handler->display->display_options['fields']['field_platform']['field'] = 'field_platform';
  $handler->display->display_options['fields']['field_platform']['exclude'] = TRUE;
  /* Field: Content: Platform other option */
  $handler->display->display_options['fields']['field_platform_other_option']['id'] = 'field_platform_other_option';
  $handler->display->display_options['fields']['field_platform_other_option']['table'] = 'field_data_field_platform_other_option';
  $handler->display->display_options['fields']['field_platform_other_option']['field'] = 'field_platform_other_option';
  $handler->display->display_options['fields']['field_platform_other_option']['exclude'] = TRUE;
  /* Field: Global: PHP */
  $handler->display->display_options['fields']['php']['id'] = 'php';
  $handler->display->display_options['fields']['php']['table'] = 'views';
  $handler->display->display_options['fields']['php']['field'] = 'php';
  $handler->display->display_options['fields']['php']['label'] = '';
  $handler->display->display_options['fields']['php']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['php']['use_php_setup'] = 0;
  $handler->display->display_options['fields']['php']['php_output'] = '<?php
$value = $data->field_field_platform[0][\'rendered\'][\'#markup\'];
$other_option_val = $data->field_field_platform[0][\'rendered\'][\'#markup\'];
$other_option_value = $data->field_field_platform_other_option[0][\'rendered\'][\'#markup\'];

if(isset($other_option_val)){
if($other_option_val == \'Other\'){
echo \'Platform: \'.$other_option_value;
}else{
echo \'Platform: \'.$value;
}
}

?>';
  $handler->display->display_options['fields']['php']['use_php_click_sortable'] = '0';
  $handler->display->display_options['fields']['php']['php_click_sortable'] = '';
  /* Field: Content: Catalog Link */
  $handler->display->display_options['fields']['field_catalog_link_video_game']['id'] = 'field_catalog_link_video_game';
  $handler->display->display_options['fields']['field_catalog_link_video_game']['table'] = 'field_data_field_catalog_link_video_game';
  $handler->display->display_options['fields']['field_catalog_link_video_game']['field'] = 'field_catalog_link_video_game';
  $handler->display->display_options['fields']['field_catalog_link_video_game']['label'] = '';
  $handler->display->display_options['fields']['field_catalog_link_video_game']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_catalog_link_video_game']['alter']['text'] = 'Catalog Link: [field_catalog_link_video_game]';
  $handler->display->display_options['fields']['field_catalog_link_video_game']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_catalog_link_video_game']['click_sort_column'] = 'url';
  $handler->display->display_options['fields']['field_catalog_link_video_game']['type'] = 'link_url';
  /* Field: Content: Age Rating Of Game */
  $handler->display->display_options['fields']['field_age_rating_of_game']['id'] = 'field_age_rating_of_game';
  $handler->display->display_options['fields']['field_age_rating_of_game']['table'] = 'field_data_field_age_rating_of_game';
  $handler->display->display_options['fields']['field_age_rating_of_game']['field'] = 'field_age_rating_of_game';
  $handler->display->display_options['fields']['field_age_rating_of_game']['label'] = '';
  $handler->display->display_options['fields']['field_age_rating_of_game']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_age_rating_of_game']['alter']['text'] = 'Age Rating Of Game: [field_age_rating_of_game]';
  $handler->display->display_options['fields']['field_age_rating_of_game']['element_label_colon'] = FALSE;
  /* Field: Content: Please select one */
  $handler->display->display_options['fields']['field_please_select_videogame']['id'] = 'field_please_select_videogame';
  $handler->display->display_options['fields']['field_please_select_videogame']['table'] = 'field_data_field_please_select_videogame';
  $handler->display->display_options['fields']['field_please_select_videogame']['field'] = 'field_please_select_videogame';
  $handler->display->display_options['fields']['field_please_select_videogame']['label'] = '';
  $handler->display->display_options['fields']['field_please_select_videogame']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_please_select_videogame']['element_label_colon'] = FALSE;
  /* Field: Global: PHP */
  $handler->display->display_options['fields']['php_1']['id'] = 'php_1';
  $handler->display->display_options['fields']['php_1']['table'] = 'views';
  $handler->display->display_options['fields']['php_1']['field'] = 'php';
  $handler->display->display_options['fields']['php_1']['label'] = '';
  $handler->display->display_options['fields']['php_1']['exclude'] = TRUE;
  $handler->display->display_options['fields']['php_1']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['php_1']['use_php_setup'] = 0;
  $handler->display->display_options['fields']['php_1']['php_output'] = '<?php

$privacy = $data->_field_data[\'nid\'][\'entity\'];
$privacy_key = $privacy->field_please_select_videogame[LANGUAGE_NONE][0][\'value\'];
if($privacy_key == \'public\'){
print \'Reviewed by \';
}

?>';
  $handler->display->display_options['fields']['php_1']['use_php_click_sortable'] = '0';
  $handler->display->display_options['fields']['php_1']['php_click_sortable'] = '';
  /* Field: Profile: Avatar image */
  $handler->display->display_options['fields']['field_user_avatar']['id'] = 'field_user_avatar';
  $handler->display->display_options['fields']['field_user_avatar']['table'] = 'field_data_field_user_avatar';
  $handler->display->display_options['fields']['field_user_avatar']['field'] = 'field_user_avatar';
  $handler->display->display_options['fields']['field_user_avatar']['relationship'] = 'profile';
  $handler->display->display_options['fields']['field_user_avatar']['label'] = '';
  $handler->display->display_options['fields']['field_user_avatar']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_user_avatar']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_user_avatar']['type'] = 'entityreference_entity_view';
  $handler->display->display_options['fields']['field_user_avatar']['settings'] = array(
    'view_mode' => 'default',
    'links' => 1,
  );
  /* Field: Global: PHP */
  $handler->display->display_options['fields']['php_2']['id'] = 'php_2';
  $handler->display->display_options['fields']['php_2']['table'] = 'views';
  $handler->display->display_options['fields']['php_2']['field'] = 'php';
  $handler->display->display_options['fields']['php_2']['label'] = '';
  $handler->display->display_options['fields']['php_2']['exclude'] = TRUE;
  $handler->display->display_options['fields']['php_2']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['php_2']['use_php_setup'] = 0;
  $handler->display->display_options['fields']['php_2']['php_output'] = '<?php

$img_id = $row->field_user_avatar;

$query = db_select(\'field_data_field_user_avatar\',\'avatar\')
->fields(\'avatar\',array(\'field_user_avatar_target_id\'))
->condition(\'entity_id\',$img_id)
->execute()
->fetchAssoc();

$image_id =  $query[\'field_user_avatar_target_id\'];

$query = db_select(\'field_data_field_avatar_image\', \'t\');
$query->join(\'file_managed\', \'n\', \'n.fid = t.field_avatar_image_fid\');
$result = $query
  ->fields(\'n\', array(\'uri\'))
  ->condition(\'t.entity_id\', $image_id)
  ->execute();

$img_uri = $result->fetchObject();
$img_uri = $img_uri->uri;
$style = \'avatar_style\';
$img_path = image_style_url($style, $img_uri);

$img = "<img src=\'$img_path\'>";

$privacy = $data->_field_data[\'nid\'][\'entity\'];
$privacy_key = $privacy->field_please_select_videogame[LANGUAGE_NONE][0][\'value\'];

if(isset($img_uri)){
	if($privacy_key == \'public\'){
	print $img;
	}
}
?>';
  $handler->display->display_options['fields']['php_2']['use_php_click_sortable'] = '0';
  $handler->display->display_options['fields']['php_2']['php_click_sortable'] = '';
  /* Field: User: Name */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'users';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['relationship'] = 'uid';
  $handler->display->display_options['fields']['name']['exclude'] = TRUE;
  /* Field: User: Uid */
  $handler->display->display_options['fields']['uid']['id'] = 'uid';
  $handler->display->display_options['fields']['uid']['table'] = 'users';
  $handler->display->display_options['fields']['uid']['field'] = 'uid';
  $handler->display->display_options['fields']['uid']['relationship'] = 'uid';
  $handler->display->display_options['fields']['uid']['exclude'] = TRUE;
  /* Field: Global: PHP */
  $handler->display->display_options['fields']['php_3']['id'] = 'php_3';
  $handler->display->display_options['fields']['php_3']['table'] = 'views';
  $handler->display->display_options['fields']['php_3']['field'] = 'php';
  $handler->display->display_options['fields']['php_3']['label'] = '';
  $handler->display->display_options['fields']['php_3']['exclude'] = TRUE;
  $handler->display->display_options['fields']['php_3']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['php_3']['use_php_setup'] = 0;
  $handler->display->display_options['fields']['php_3']['php_output'] = '<?php

$privacy = $data->_field_data[\'nid\'][\'entity\'];
$privacy_key = $privacy->field_please_select_videogame[LANGUAGE_NONE][0][\'value\'];
if($privacy_key == \'public\'){
echo "<a href = users/public_profile/$row->uid>".$row->name."</a>";
}

?>';
  $handler->display->display_options['fields']['php_3']['use_php_click_sortable'] = '0';
  $handler->display->display_options['fields']['php_3']['php_click_sortable'] = '';
  /* Field: Global: Custom text */
  $handler->display->display_options['fields']['nothing']['id'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['table'] = 'views';
  $handler->display->display_options['fields']['nothing']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['label'] = '';
  $handler->display->display_options['fields']['nothing']['alter']['text'] = '<div class="review">[php_1]</div><div class = "views-field-field-user-avatar">[php_2]</div><div class="user">[php_3]</div>';
  $handler->display->display_options['fields']['nothing']['element_label_colon'] = FALSE;
  /* Field: Content: Post date */
  $handler->display->display_options['fields']['created']['id'] = 'created';
  $handler->display->display_options['fields']['created']['table'] = 'node';
  $handler->display->display_options['fields']['created']['field'] = 'created';
  $handler->display->display_options['fields']['created']['label'] = '';
  $handler->display->display_options['fields']['created']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['created']['date_format'] = 'custom';
  $handler->display->display_options['fields']['created']['custom_date_format'] = 'M d, Y';
  $handler->display->display_options['fields']['created']['second_date_format'] = 'privatemsg_current_day';
  /* Field: Content: Body */
  $handler->display->display_options['fields']['body']['id'] = 'body';
  $handler->display->display_options['fields']['body']['table'] = 'field_data_body';
  $handler->display->display_options['fields']['body']['field'] = 'body';
  $handler->display->display_options['fields']['body']['label'] = '';
  $handler->display->display_options['fields']['body']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['body']['type'] = 'text_trimmed';
  $handler->display->display_options['fields']['body']['settings'] = array(
    'trim_length' => '200',
  );
  /* Field: Content: Link */
  $handler->display->display_options['fields']['view_node']['id'] = 'view_node';
  $handler->display->display_options['fields']['view_node']['table'] = 'views_entity_node';
  $handler->display->display_options['fields']['view_node']['field'] = 'view_node';
  $handler->display->display_options['fields']['view_node']['label'] = '';
  $handler->display->display_options['fields']['view_node']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['view_node']['text'] = 'View full review';
  /* Sort criterion: Content: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  $handler->display->display_options['sorts']['created']['exposed'] = TRUE;
  $handler->display->display_options['sorts']['created']['expose']['label'] = 'Post date';
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'video_game_review' => 'video_game_review',
  );
  /* Filter criterion: Search: Search Terms */
  $handler->display->display_options['filters']['keys']['id'] = 'keys';
  $handler->display->display_options['filters']['keys']['table'] = 'search_index';
  $handler->display->display_options['filters']['keys']['field'] = 'keys';
  $handler->display->display_options['filters']['keys']['exposed'] = TRUE;
  $handler->display->display_options['filters']['keys']['expose']['operator_id'] = 'keys_op';
  $handler->display->display_options['filters']['keys']['expose']['label'] = 'Search';
  $handler->display->display_options['filters']['keys']['expose']['operator'] = 'keys_op';
  $handler->display->display_options['filters']['keys']['expose']['identifier'] = 'keys';
  $handler->display->display_options['filters']['keys']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    6 => 0,
    10 => 0,
    11 => 0,
    4 => 0,
    3 => 0,
    12 => 0,
  );
  /* Filter criterion: User: Name (raw) */
  $handler->display->display_options['filters']['name']['id'] = 'name';
  $handler->display->display_options['filters']['name']['table'] = 'users';
  $handler->display->display_options['filters']['name']['field'] = 'name';
  $handler->display->display_options['filters']['name']['relationship'] = 'uid';
  $handler->display->display_options['filters']['name']['operator'] = 'contains';
  $handler->display->display_options['filters']['name']['exposed'] = TRUE;
  $handler->display->display_options['filters']['name']['expose']['operator_id'] = 'name_op';
  $handler->display->display_options['filters']['name']['expose']['label'] = 'Reviewer';
  $handler->display->display_options['filters']['name']['expose']['operator'] = 'name_op';
  $handler->display->display_options['filters']['name']['expose']['identifier'] = 'name';
  $handler->display->display_options['filters']['name']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    6 => 0,
    10 => 0,
    11 => 0,
    4 => 0,
    3 => 0,
    12 => 0,
  );
  /* Filter criterion: Content: Title */
  $handler->display->display_options['filters']['title']['id'] = 'title';
  $handler->display->display_options['filters']['title']['table'] = 'node';
  $handler->display->display_options['filters']['title']['field'] = 'title';
  $handler->display->display_options['filters']['title']['operator'] = 'contains';
  $handler->display->display_options['filters']['title']['exposed'] = TRUE;
  $handler->display->display_options['filters']['title']['expose']['operator_id'] = 'title_op';
  $handler->display->display_options['filters']['title']['expose']['label'] = 'by Title';
  $handler->display->display_options['filters']['title']['expose']['operator'] = 'title_op';
  $handler->display->display_options['filters']['title']['expose']['identifier'] = 'title';
  $handler->display->display_options['filters']['title']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    6 => 0,
    10 => 0,
    11 => 0,
    4 => 0,
    3 => 0,
    12 => 0,
  );
  /* Filter criterion: Content: Please select one (field_please_select_videogame) */
  $handler->display->display_options['filters']['field_please_select_videogame_value']['id'] = 'field_please_select_videogame_value';
  $handler->display->display_options['filters']['field_please_select_videogame_value']['table'] = 'field_data_field_please_select_videogame';
  $handler->display->display_options['filters']['field_please_select_videogame_value']['field'] = 'field_please_select_videogame_value';
  $handler->display->display_options['filters']['field_please_select_videogame_value']['value'] = array(
    'public' => 'public',
    'publicnoname' => 'publicnoname',
  );
  /* Filter criterion: Content: Platform (field_platform) */
  $handler->display->display_options['filters']['field_platform_value']['id'] = 'field_platform_value';
  $handler->display->display_options['filters']['field_platform_value']['table'] = 'field_data_field_platform';
  $handler->display->display_options['filters']['field_platform_value']['field'] = 'field_platform_value';
  $handler->display->display_options['filters']['field_platform_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_platform_value']['expose']['operator_id'] = 'field_platform_value_op';
  $handler->display->display_options['filters']['field_platform_value']['expose']['label'] = 'By Platform';
  $handler->display->display_options['filters']['field_platform_value']['expose']['operator'] = 'field_platform_value_op';
  $handler->display->display_options['filters']['field_platform_value']['expose']['identifier'] = 'field_platform_value';
  $handler->display->display_options['filters']['field_platform_value']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    6 => 0,
    10 => 0,
    11 => 0,
    4 => 0,
    3 => 0,
    12 => 0,
  );

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['defaults']['header'] = FALSE;
  /* Header: Global: Text area */
  $handler->display->display_options['header']['area']['id'] = 'area';
  $handler->display->display_options['header']['area']['table'] = 'views';
  $handler->display->display_options['header']['area']['field'] = 'area';
  $handler->display->display_options['header']['area']['content'] = '<h2 class = reviews-title>Reviews & Booklists</h2>
<div class="viewmenu">View: <a href="/video-game-review">All</a> | <a href="/video-game-review/staff">Posted by Staff</a> | <a href="/video-game-review/players">Posted by Players</a></div>
<h2 class = reviews-subtitle>Video Game Reviews</h2>';
  $handler->display->display_options['header']['area']['format'] = 'full_html';
  $handler->display->display_options['path'] = 'video-game-review';

  /* Display: Staff */
  $handler = $view->new_display('page', 'Staff', 'page_1');
  $handler->display->display_options['defaults']['header'] = FALSE;
  /* Header: Global: Text area */
  $handler->display->display_options['header']['area']['id'] = 'area';
  $handler->display->display_options['header']['area']['table'] = 'views';
  $handler->display->display_options['header']['area']['field'] = 'area';
  $handler->display->display_options['header']['area']['content'] = '<h2 class = reviews-title>Reviews & Booklists</h2>
<div class="viewmenu">View: <a href="/video-game-review">All</a> | <a href="/video-game-review/staff">Posted by Staff</a> | <a href="/video-game-review/players">Posted by Players</a></div>
<h2 class = reviews-subtitle>VIDEO GAME REVIEWS</h2>';
  $handler->display->display_options['header']['area']['format'] = 'simple_html';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'video_game_review' => 'video_game_review',
  );
  /* Filter criterion: Search: Search Terms */
  $handler->display->display_options['filters']['keys']['id'] = 'keys';
  $handler->display->display_options['filters']['keys']['table'] = 'search_index';
  $handler->display->display_options['filters']['keys']['field'] = 'keys';
  $handler->display->display_options['filters']['keys']['exposed'] = TRUE;
  $handler->display->display_options['filters']['keys']['expose']['operator_id'] = 'keys_op';
  $handler->display->display_options['filters']['keys']['expose']['label'] = 'Search';
  $handler->display->display_options['filters']['keys']['expose']['operator'] = 'keys_op';
  $handler->display->display_options['filters']['keys']['expose']['identifier'] = 'keys';
  $handler->display->display_options['filters']['keys']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    6 => 0,
    10 => 0,
    11 => 0,
    4 => 0,
    3 => 0,
    12 => 0,
  );
  /* Filter criterion: User: Name (raw) */
  $handler->display->display_options['filters']['name']['id'] = 'name';
  $handler->display->display_options['filters']['name']['table'] = 'users';
  $handler->display->display_options['filters']['name']['field'] = 'name';
  $handler->display->display_options['filters']['name']['relationship'] = 'uid';
  $handler->display->display_options['filters']['name']['operator'] = 'contains';
  $handler->display->display_options['filters']['name']['exposed'] = TRUE;
  $handler->display->display_options['filters']['name']['expose']['operator_id'] = 'name_op';
  $handler->display->display_options['filters']['name']['expose']['label'] = 'Reviewer';
  $handler->display->display_options['filters']['name']['expose']['operator'] = 'name_op';
  $handler->display->display_options['filters']['name']['expose']['identifier'] = 'name';
  $handler->display->display_options['filters']['name']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    6 => 0,
    10 => 0,
    11 => 0,
    4 => 0,
    3 => 0,
    12 => 0,
  );
  /* Filter criterion: Content: Title */
  $handler->display->display_options['filters']['title']['id'] = 'title';
  $handler->display->display_options['filters']['title']['table'] = 'node';
  $handler->display->display_options['filters']['title']['field'] = 'title';
  $handler->display->display_options['filters']['title']['operator'] = 'contains';
  $handler->display->display_options['filters']['title']['exposed'] = TRUE;
  $handler->display->display_options['filters']['title']['expose']['operator_id'] = 'title_op';
  $handler->display->display_options['filters']['title']['expose']['label'] = 'by Title';
  $handler->display->display_options['filters']['title']['expose']['operator'] = 'title_op';
  $handler->display->display_options['filters']['title']['expose']['identifier'] = 'title';
  $handler->display->display_options['filters']['title']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    6 => 0,
    10 => 0,
    11 => 0,
    4 => 0,
    3 => 0,
    12 => 0,
  );
  /* Filter criterion: Content: Please select one (field_please_select_videogame) */
  $handler->display->display_options['filters']['field_please_select_videogame_value']['id'] = 'field_please_select_videogame_value';
  $handler->display->display_options['filters']['field_please_select_videogame_value']['table'] = 'field_data_field_please_select_videogame';
  $handler->display->display_options['filters']['field_please_select_videogame_value']['field'] = 'field_please_select_videogame_value';
  $handler->display->display_options['filters']['field_please_select_videogame_value']['value'] = array(
    'public' => 'public',
    'publicnoname' => 'publicnoname',
  );
  /* Filter criterion: Profile: First name (field_user_first_name) */
  $handler->display->display_options['filters']['field_user_first_name_value']['id'] = 'field_user_first_name_value';
  $handler->display->display_options['filters']['field_user_first_name_value']['table'] = 'field_data_field_user_first_name';
  $handler->display->display_options['filters']['field_user_first_name_value']['field'] = 'field_user_first_name_value';
  $handler->display->display_options['filters']['field_user_first_name_value']['relationship'] = 'profile';
  $handler->display->display_options['filters']['field_user_first_name_value']['operator'] = 'contains';
  $handler->display->display_options['filters']['field_user_first_name_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_user_first_name_value']['expose']['operator_id'] = 'field_user_first_name_value_op';
  $handler->display->display_options['filters']['field_user_first_name_value']['expose']['label'] = 'Author first name';
  $handler->display->display_options['filters']['field_user_first_name_value']['expose']['operator'] = 'field_user_first_name_value_op';
  $handler->display->display_options['filters']['field_user_first_name_value']['expose']['identifier'] = 'field_user_first_name_value';
  $handler->display->display_options['filters']['field_user_first_name_value']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    6 => 0,
    10 => 0,
    11 => 0,
    4 => 0,
    3 => 0,
    12 => 0,
  );
  /* Filter criterion: Profile: Last name (field_user_last_name) */
  $handler->display->display_options['filters']['field_user_last_name_value']['id'] = 'field_user_last_name_value';
  $handler->display->display_options['filters']['field_user_last_name_value']['table'] = 'field_data_field_user_last_name';
  $handler->display->display_options['filters']['field_user_last_name_value']['field'] = 'field_user_last_name_value';
  $handler->display->display_options['filters']['field_user_last_name_value']['relationship'] = 'profile';
  $handler->display->display_options['filters']['field_user_last_name_value']['operator'] = 'contains';
  $handler->display->display_options['filters']['field_user_last_name_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_user_last_name_value']['expose']['operator_id'] = 'field_user_last_name_value_op';
  $handler->display->display_options['filters']['field_user_last_name_value']['expose']['label'] = 'Author last name';
  $handler->display->display_options['filters']['field_user_last_name_value']['expose']['operator'] = 'field_user_last_name_value_op';
  $handler->display->display_options['filters']['field_user_last_name_value']['expose']['identifier'] = 'field_user_last_name_value';
  $handler->display->display_options['filters']['field_user_last_name_value']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    6 => 0,
    10 => 0,
    11 => 0,
    4 => 0,
    3 => 0,
    12 => 0,
  );
  /* Filter criterion: User: Roles */
  $handler->display->display_options['filters']['rid']['id'] = 'rid';
  $handler->display->display_options['filters']['rid']['table'] = 'users_roles';
  $handler->display->display_options['filters']['rid']['field'] = 'rid';
  $handler->display->display_options['filters']['rid']['relationship'] = 'uid';
  $handler->display->display_options['filters']['rid']['value'] = array(
    10 => '10',
  );
  $handler->display->display_options['path'] = 'video-game-review/staff';

  /* Display: Players */
  $handler = $view->new_display('page', 'Players', 'page_2');
  $handler->display->display_options['defaults']['header'] = FALSE;
  /* Header: Global: Text area */
  $handler->display->display_options['header']['area']['id'] = 'area';
  $handler->display->display_options['header']['area']['table'] = 'views';
  $handler->display->display_options['header']['area']['field'] = 'area';
  $handler->display->display_options['header']['area']['content'] = '<h2 class = reviews-title>Reviews & Booklists</h2>
<div class="viewmenu">View: <a href="/video-game-review">All</a> | <a href="/video-game-review/staff">Posted by Staff</a> | <a href="/video-game-review/players">Posted by Players</a></div>
<h2 class = reviews-subtitle>VIDEO GAME REVIEWS</h2>';
  $handler->display->display_options['header']['area']['format'] = 'simple_html';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'video_game_review' => 'video_game_review',
  );
  /* Filter criterion: Search: Search Terms */
  $handler->display->display_options['filters']['keys']['id'] = 'keys';
  $handler->display->display_options['filters']['keys']['table'] = 'search_index';
  $handler->display->display_options['filters']['keys']['field'] = 'keys';
  $handler->display->display_options['filters']['keys']['exposed'] = TRUE;
  $handler->display->display_options['filters']['keys']['expose']['operator_id'] = 'keys_op';
  $handler->display->display_options['filters']['keys']['expose']['label'] = 'Search';
  $handler->display->display_options['filters']['keys']['expose']['operator'] = 'keys_op';
  $handler->display->display_options['filters']['keys']['expose']['identifier'] = 'keys';
  $handler->display->display_options['filters']['keys']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    6 => 0,
    10 => 0,
    11 => 0,
    4 => 0,
    3 => 0,
    12 => 0,
  );
  /* Filter criterion: User: Name (raw) */
  $handler->display->display_options['filters']['name']['id'] = 'name';
  $handler->display->display_options['filters']['name']['table'] = 'users';
  $handler->display->display_options['filters']['name']['field'] = 'name';
  $handler->display->display_options['filters']['name']['relationship'] = 'uid';
  $handler->display->display_options['filters']['name']['operator'] = 'contains';
  $handler->display->display_options['filters']['name']['exposed'] = TRUE;
  $handler->display->display_options['filters']['name']['expose']['operator_id'] = 'name_op';
  $handler->display->display_options['filters']['name']['expose']['label'] = 'Reviewer';
  $handler->display->display_options['filters']['name']['expose']['operator'] = 'name_op';
  $handler->display->display_options['filters']['name']['expose']['identifier'] = 'name';
  $handler->display->display_options['filters']['name']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    6 => 0,
    10 => 0,
    11 => 0,
    4 => 0,
    3 => 0,
    12 => 0,
  );
  /* Filter criterion: Content: Title */
  $handler->display->display_options['filters']['title']['id'] = 'title';
  $handler->display->display_options['filters']['title']['table'] = 'node';
  $handler->display->display_options['filters']['title']['field'] = 'title';
  $handler->display->display_options['filters']['title']['operator'] = 'contains';
  $handler->display->display_options['filters']['title']['exposed'] = TRUE;
  $handler->display->display_options['filters']['title']['expose']['operator_id'] = 'title_op';
  $handler->display->display_options['filters']['title']['expose']['label'] = 'by Title';
  $handler->display->display_options['filters']['title']['expose']['operator'] = 'title_op';
  $handler->display->display_options['filters']['title']['expose']['identifier'] = 'title';
  $handler->display->display_options['filters']['title']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    6 => 0,
    10 => 0,
    11 => 0,
    4 => 0,
    3 => 0,
    12 => 0,
  );
  /* Filter criterion: Content: Please select one (field_please_select_videogame) */
  $handler->display->display_options['filters']['field_please_select_videogame_value']['id'] = 'field_please_select_videogame_value';
  $handler->display->display_options['filters']['field_please_select_videogame_value']['table'] = 'field_data_field_please_select_videogame';
  $handler->display->display_options['filters']['field_please_select_videogame_value']['field'] = 'field_please_select_videogame_value';
  $handler->display->display_options['filters']['field_please_select_videogame_value']['value'] = array(
    'public' => 'public',
    'publicnoname' => 'publicnoname',
  );
  /* Filter criterion: Profile: First name (field_user_first_name) */
  $handler->display->display_options['filters']['field_user_first_name_value']['id'] = 'field_user_first_name_value';
  $handler->display->display_options['filters']['field_user_first_name_value']['table'] = 'field_data_field_user_first_name';
  $handler->display->display_options['filters']['field_user_first_name_value']['field'] = 'field_user_first_name_value';
  $handler->display->display_options['filters']['field_user_first_name_value']['relationship'] = 'profile';
  $handler->display->display_options['filters']['field_user_first_name_value']['operator'] = 'contains';
  $handler->display->display_options['filters']['field_user_first_name_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_user_first_name_value']['expose']['operator_id'] = 'field_user_first_name_value_op';
  $handler->display->display_options['filters']['field_user_first_name_value']['expose']['label'] = 'Author first name';
  $handler->display->display_options['filters']['field_user_first_name_value']['expose']['operator'] = 'field_user_first_name_value_op';
  $handler->display->display_options['filters']['field_user_first_name_value']['expose']['identifier'] = 'field_user_first_name_value';
  $handler->display->display_options['filters']['field_user_first_name_value']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    6 => 0,
    10 => 0,
    11 => 0,
    4 => 0,
    3 => 0,
    12 => 0,
  );
  /* Filter criterion: Profile: Last name (field_user_last_name) */
  $handler->display->display_options['filters']['field_user_last_name_value']['id'] = 'field_user_last_name_value';
  $handler->display->display_options['filters']['field_user_last_name_value']['table'] = 'field_data_field_user_last_name';
  $handler->display->display_options['filters']['field_user_last_name_value']['field'] = 'field_user_last_name_value';
  $handler->display->display_options['filters']['field_user_last_name_value']['relationship'] = 'profile';
  $handler->display->display_options['filters']['field_user_last_name_value']['operator'] = 'contains';
  $handler->display->display_options['filters']['field_user_last_name_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_user_last_name_value']['expose']['operator_id'] = 'field_user_last_name_value_op';
  $handler->display->display_options['filters']['field_user_last_name_value']['expose']['label'] = 'Author last name';
  $handler->display->display_options['filters']['field_user_last_name_value']['expose']['operator'] = 'field_user_last_name_value_op';
  $handler->display->display_options['filters']['field_user_last_name_value']['expose']['identifier'] = 'field_user_last_name_value';
  $handler->display->display_options['filters']['field_user_last_name_value']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    6 => 0,
    10 => 0,
    11 => 0,
    4 => 0,
    3 => 0,
    12 => 0,
  );
  /* Filter criterion: User: Roles */
  $handler->display->display_options['filters']['rid']['id'] = 'rid';
  $handler->display->display_options['filters']['rid']['table'] = 'users_roles';
  $handler->display->display_options['filters']['rid']['field'] = 'rid';
  $handler->display->display_options['filters']['rid']['relationship'] = 'uid';
  $handler->display->display_options['filters']['rid']['value'] = array(
    6 => '6',
  );
  $handler->display->display_options['path'] = 'video-game-review/players';
  $export['video_game_review'] = $view;

  return $export;
}

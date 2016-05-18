<?php

/**
 * @file
 * Default theme implementation to display a node.
 *
 * Available variables:
 * - $title: the (sanitized) title of the node.
 * - $content: An array of node items. Use render($content) to print them all, or
 *   print a subset such as render($content['field_example']). Use
 *   hide($content['field_example']) to temporarily suppress the printing of a
 *   given element.
 * - $user_picture: The node author's picture from user-picture.tpl.php.
 * - $date: Formatted creation date. Preprocess functions can reformat it by
 *   calling format_date() with the desired parameters on the $created variable.
 * - $name: Themed username of node author output from theme_username().
 * - $node_url: Direct url of the current node.
 * - $terms: the themed list of taxonomy term links output from theme_links().
 * - $display_submitted: whether submission information should be displayed.
 * - $classes: String of classes that can be used to style contextually through
 *   CSS. It can be manipulated through the variable $classes_array from
 *   preprocess functions. The default values can be one or more of the following:
 *   - node: The current template type, i.e., "theming hook".
 *   - node-[type]: The current node type. For example, if the node is a
 *     "Blog entry" it would result in "node-blog". Note that the machine
 *     name will often be in a short form of the human readable label.
 *   - node-teaser: Nodes in teaser form.
 *   - node-preview: Nodes in preview mode.
 *   The following are controlled through the node publishing options.
 *   - node-promoted: Nodes promoted to the front page.
 *   - node-sticky: Nodes ordered above other non-sticky nodes in teaser listings.
 *   - node-unpublished: Unpublished nodes visible only to administrators.
 * - $title_prefix (array): An array containing additional output populated by
 *   modules, intended to be displayed in front of the main title tag that
 *   appears in the template.
 * - $title_suffix (array): An array containing additional output populated by
 *   modules, intended to be displayed after the main title tag that appears in
 *   the template.
 *
 * Other variables:
 * - $node: Full node object. Contains data that may not be safe.
 * - $type: Node type, i.e. story, page, blog, etc.
 * - $comment_count: Number of comments attached to the node.
 * - $uid: User ID of the node author.
 * - $created: Time the node was published formatted in Unix timestamp.
 * - $classes_array: Array of html class attribute values. It is flattened
 *   into a string within the variable $classes.
 * - $zebra: Outputs either "even" or "odd". Useful for zebra striping in
 *   teaser listings.
 * - $id: Position of the node. Increments each time it's output.
 *
 * Node status variables:
 * - $view_mode: View mode, e.g. 'full', 'teaser'...
 * - $teaser: Flag for the teaser state (shortcut for $view_mode == 'teaser').
 * - $page: Flag for the full page state.
 * - $promote: Flag for front page promotion state.
 * - $sticky: Flags for sticky post setting.
 * - $status: Flag for published status.
 * - $comment: State of comment settings for the node.
 * - $readmore: Flags true if the teaser content of the node cannot hold the
 *   main body content.
 * - $is_front: Flags true when presented in the front page.
 * - $logged_in: Flags true when the current user is a logged-in member.
 * - $is_admin: Flags true when the current user is an administrator.
 *
 * Field variables: for each field instance attached to the node a corresponding
 * variable is defined, e.g. $node->body becomes $body. When needing to access
 * a field's raw values, developers/themers are strongly encouraged to use these
 * variables. Otherwise they will have to explicitly specify the desired field
 * language, e.g. $node->body['en'], thus overriding any language negotiation
 * rule that was previously applied.
 *
 * @see template_preprocess()
 * @see template_preprocess_node()
 * @see template_process()
 */
?>
<article id="node-<?php print $node->nid; ?>" class="<?php print $classes; ?>"<?php print $attributes; ?>>

  <?php print render($title_prefix); ?>
  <?php if (!$page): ?>
    <?php if (!$page): ?>
      <h2<?php print $title_attributes; ?>><a href="<?php print $node_url; ?>"><?php print $title; ?></a></h2>
    <?php endif; ?>
  <?php endif; ?>
  <?php print render($title_suffix); ?>

  <?php if ($display_submitted): ?>
    <div class="posted">
      <?php if ($user_picture): ?>
        <?php print $user_picture; ?>
      <?php endif; ?>
    </div>
  <?php endif; ?>

  <?php
  	$platform = $content['field_platform'][0]['#markup'];
		$platform_other_option = field_get_items('node', $node, 'field_platform_other_option');
		$actors = field_get_items('node', $node, 'field_actors');
		$director = field_get_items('node', $node, 'field_director');
  	$age_rating = $content['field_age_rating_of_game'][0]['#markup'];
  	$release_year = $content['field_release_year'][0]['#markup'];
  	$rating = $content['field_rating'][0]['#markup'];
  	$catalog_title = $content['field_catalog_link_video_game'][0]['#element']['title'];
  	$catalog_link = $content['field_catalog_link_video_game'][0]['#element']['url'];
		$review = field_get_items('node', $node, 'body');

	  global $base_url;
	  $reviewer = $node->name; 
	  $node_uid = $node->uid;
	  $node_created = $node->created;
	  $profile = profile2_load_by_user($node->uid);
	  $pid = $profile['main']->pid;
	  $node = node_load($nid);
	  $node_privacy_field = field_get_items('node', $node, 'field_please_select_videogame');
	  $node_privacy = $node_privacy_field[0]['value'];
	  $nid_node = $node->nid;

	  $query_img_id = db_select('field_data_field_user_avatar','av')
	    ->fields('av',array('field_user_avatar_target_id'))
	    ->condition('entity_id',$pid)
	    ->execute()
	    ->fetchAssoc();
	  $target_id = $query_img_id['field_user_avatar_target_id'];

	  if(isset($target_id)){
	    $query = db_select('field_data_field_avatar_image', 't');
	    $query->join('file_managed', 'n', 'n.fid = t.field_avatar_image_fid');
	    $result = $query
	      ->fields('n', array('uri'))
	      ->condition('t.entity_id', $target_id)
	      ->execute();
	    $img_uri = $result->fetchObject();
	    $img_uri = $img_uri->uri;
	    $style = 'avatar_style';
	    $img_path = image_style_url($style, $img_uri);
	    $img = "<img src='$img_path'>";
	  }
		
		$query = db_select('flag_counts','count')
      ->fields('count',array('count'))
      ->condition('entity_id',$nid_node)
      ->execute()
      ->fetchAssoc();
    $counts = $query['count'];

		$platform_other_option_value = $platform_other_option[0]['safe_value'];
		$actors_value = $actors[0]['safe_value'];
		$director_value = $director[0]['safe_value'];
		$review_value = $review['0']['safe_value']
  ?>
  <div class="vidiogamelikefollow-wrap">
  <div class="videogame-likes">
  	<div class="like-count">
      <?php if(isset($counts)){ print '<span class = "lk-count">Likes: </span>'.$counts; } ?>
  	</div>
  	<div class="like-here">
  		<?php print flag_create_link('like', $node->nid) ?>
  	</div>
  </div>
  <div class="follow_link_videogamereview">
  	<?php if($node_privacy === 'public'){ print flag_create_link('follow', $node->uid); } ?>
  </div>
  </div>
  <div class="videogame-review">
	  <div>
	  	<?php 
	  		if(isset($platform)){
		  		if($platform == 'Other'){
		  			print 'Platform: '.$platform_other_option_value;
		  		}else{
		  			print 'Platform: '.$platform;
		  		}
		  	}
	  	?>
	  </div>
	  <div><?php if(isset($age_rating)){ print 'Age Rating of Game: '.$age_rating; }	?></div>
	  <div><?php if(isset($catalog_link)){ echo '<a href ="'.$catalog_link.'" target="_blank">View in Library Catalog</a>'; }	?></div>
	  <div>
	  	<p class="reviewer">
    	<span class = "created"><?php if ($node_privacy == 'public' || $node_privacy == 'private'){ print 'Reviewed by '; }?></span><span class="avatar"><?php if ($node_privacy == 'public' || $node_privacy == 'private') { print $img; } ?></span><span class ="name_author"><?php if ($node_privacy == 'public' || $node_privacy == 'private'){ print "<a href = '$base_url/users/public_profile/$node_uid' class = 'user_profile_node'>".' '.$reviewer.'</a>'; } ?></span>
    	</p>
	  </div>
	  <p class="date_created"><?php print date('F d, Y',$node_created) ?></p>
	  <div><?php print $review_value;	?></div>

	</div>
  <?php if (!empty($content['field_tags']) && !$is_front): ?>
    <?php print render($content['field_tags']) ?>
  <?php endif; ?>

  <?php print render($content['links']); ?>
  <?php print render($content['comments']); ?>

</article>

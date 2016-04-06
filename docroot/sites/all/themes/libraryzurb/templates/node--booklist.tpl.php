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
<div class="booklist-title">
  <div class="bk_title">
    <p class = "book_title"><?php 
      $node = node_load($nid);
      $booklist_books = field_get_items('node', $node, 'field_book');
      $title_node = $node->title;
      $node_uid = $node->uid;
      $node_created = date('F d, Y',$node->created);
      $booklist_body = field_get_items('node', $node, 'body');
      $booklist_creator = $node->name;
      $profile = profile2_load_by_user($node->uid);
      $pid = $profile['main']->pid;
      $privacy_field = $node->field_privacy_settings['und'][0]['value'];

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
      print $title_node.' created on '.$node_created; ?></p>
    <p class = "book_desc"><?php print $booklist_body['0']['safe_value'];?></p>
    <p class="booklist_creator"><span class = "created"><?php if ($privacy_field == 'public' || $privacy_field == 'private'){ print 'Created by'; }?></span><span class="avatar"><?php if ($privacy_field == 'public' || $privacy_field == 'private') { print $img; } ?></span><span class ="name_author"><?php if ($privacy_field == 'public' || $privacy_field == 'private'){ print "<a href = 'users/public_profile/$node_uid' class = 'user_profile_node'>".$booklist_creator; } ?></span></p>
  </div>
  <div class="bk_follow_like">
    <div class="like-count">
      <?php
        $nid_node = $node->nid;
        $title_node = $node->title;

        $query = db_select('flag_counts','count')
        ->fields('count',array('count'))
        ->condition('entity_id',$nid_node)
        ->execute()
        ->fetchAssoc();

        $counts = $query['count'];
        if(isset($counts)){
        print 'Likes: '.$counts;}
      ?>
    </div>
    <div class="bk_follow">
      <?php 
      $node_privacy_field = field_get_items('node', $node, 'field_privacy_settings');
      $node_privacy = $node_privacy_field[0]['value'];
      if($node_privacy === 'public'){ print flag_create_link('follow', $node->uid); } ?>
    </div>
  </div>
</div>

<article id="node-<?php print $node->nid; ?>" class="<?php print $classes; ?>"<?php print $attributes; ?>>
  <div class="booklist_books">
    <?php
      $i = 0;
      foreach ($booklist_books as $key => $value) {
        $bk_title = $value['entity']->title;
        $i++;

        if($node->status == 1) {
          $book_cover_image = $value['entity']->field_booklist_cover_image['und'][0]['safe_value'];

        if ($book_cover_image) {                 
          $bimg = "<img src='".trim($book_cover_image)."' style='width:200px;height:200px;'>";  
        }
        else {
          $bimg =  "<img src='http://www.clker.com/cliparts/7/1/a/f/11971220941184963828dniezby_Generic_Book.svg.med.png' style='width:200px;height:200px;'>";
        }  
        print  "<table><tr><td>".$bimg."</td>"."<td>";
        print  "</tr></table>".'<p class = "node_title">'.'<span class = "counter">'.$i.'.'.'</span>'.$bk_title.'</p>';}
      }
    ?>
  </div>
  <?php print render($title_prefix); ?>
  <?php if (!$page): ?>
    <?php if (!$page): ?>
      <h2<?php print $title_attributes; ?>><a href="<?php print $node_url; ?>"><?php print $title; ?></a></h2>
    <?php endif; ?>
  <?php endif; ?>
  <?php print render($title_suffix); ?>
 <!-- Display according to user privacy setting -->
  <?php $privacy_field = $node->field_privacy_settings['und'][0]['value']; if ($privacy_field == 'public' || $privacy_field == 'private'): ?>
   <?php endif; ?>


  <?php
    // We hide the comments and links now so that we can render them later.
    hide($content['comments']);
    hide($content['links']);
    hide($content['field_tags']);
   // print_r($review = field_get_items('node', $node, 'body'));

  ?>

  <?php if (!empty($content['field_tags']) && !$is_front): ?>
    <?php print render($content['field_tags']) ?>
  <?php endif; ?>

  <?php print render($content['links']); ?>
  <?php print render($content['comments']); ?>

</article>

<?php
// $Id openbadging-badges-awarded-users-view.tpl.php

/**
 * Users on badge page who award this badge. 
 * Variables:
 * varibales['title'] use for showing view title.
 * varibales['view'] use for showing view 
 */
?>
<div class="openbadging-badges-awarded-users">
  <?php
  print '<h2>' . $variables['title'] . '</h2>';
  print $variables['view'];
  ?>
</div>

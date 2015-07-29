<?php
//$Id openbadging-badges-earned-badges-view.tpl.php

/**
 * Earned badges which earned by user on user page. 
 * 
 * Variables:
 * varibales['title'] use for showing view title.
 * varibales['view'] use for showing view 
 */
?>
<div class="openbadging-badges-earned-badges">
  <?php
  print '<h2>' . $variables['title'] . '</h2>';
  print $variables['view'];
  ?>
</div>

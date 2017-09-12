<?php
/**
 * @file
 * Default carousel output.
*/
?>
<div id="<?php print $settings['attributes']['id']; ?>" class="owl-carousel">
  <?php print theme('owlcarousel_list', array('items' => $items, 'settings' => $settings)); ?>
</div>

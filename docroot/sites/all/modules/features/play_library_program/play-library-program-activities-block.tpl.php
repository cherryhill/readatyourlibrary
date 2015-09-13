<ul class="play-activities-list">
  <?php foreach($pending as $pending_activity): ?>
  <li class="pending-activity"><?php print $pending_activity; ?></li>
  <?php endforeach; ?>

  <?php foreach($completed as $completed_activity): ?>
  <li class="completed-activity"><?php print $completed_activity; ?></li>
  <?php endforeach; ?>
</ul>
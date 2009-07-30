<?php
// $Id$

/**
 * @file widget.tpl.php
 *
 * UpDown widget theme for Vote Up/Down
 */
$unsigned_points = (int) $points;
?>
<div class="vud-widget-updown">
  <div class="updown-score"><span class="updown-current-score"><?php print $points; ?></span> votes</div>
  <div class="updown-voteup"><a href="<?php print $title_up; ?>">+</a></div>
  <div class="updown-votedown"><a href="<?php print $title_down; ?>">-</a></div>
</div>

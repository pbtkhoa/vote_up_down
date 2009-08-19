<?php
// $Id$

/**
 * @file
 * widget.tpl.php
 *
 * UpDown widget theme for Vote Up/Down
 */
?>
<div class="vud-widget-updown">
  <div class="updown-score"><span class="updown-current-score" id="total-votes-<?php print $type; ?>-<?php print $cid; ?>"><?php print $unsigned_points; ?></span><?php print $vote_label; ?></div>
  <a href="<?php print $link_up; ?>"><div class="<?php print $class_up; ?>" id="updown-up-<?php print $type; ?>-<?php print $cid; ?>" title="Vote up!">+</div></a>
  <a href="<?php print $link_down; ?>"><div class="<?php print $class_down; ?>" id="updown-down-<?php print $type; ?>-<?php print $cid; ?>" title="Vote down!">-</div></a>
</div>

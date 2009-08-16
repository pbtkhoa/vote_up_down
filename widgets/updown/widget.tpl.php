<?php
// $Id$

/**
 * @file
 * widget.tpl.php
 *
 * UpDown widget theme for Vote Up/Down
 */
$unsignpoints = (int) $points;
if ($unsignpoints > 1 || $unsignpoints < -1) { $lbl = "votes"; } else { $lbl = "vote"; }
?>
<div class="vud-widget-updown">
  <div class="updown-score"><span class="updown-current-score" id="total-votes-<?php print $type; ?>-<?php print $cid; ?>"><?php print $unsignpoints; ?></span><?php print $lbl; ?></div>
  <a href="<?php print $link_up; ?>"><div class="<?php print $class_up; ?>" id="updown-up-<?php print $type; ?>-<?php print $cid; ?>" title="Vote up!">+</div></a>
  <a href="<?php print $link_down; ?>"><div class="<?php print $class_down; ?>" id="updown-down-<?php print $type; ?>-<?php print $cid; ?>" title="Vote down!">-</div></a>
</div>

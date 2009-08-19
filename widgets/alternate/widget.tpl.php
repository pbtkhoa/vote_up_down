<?php
// $Id$
/**
 * @file
 * widget.tpl.php
 *
 * Alternate widget theme for Vote Up/Down
 */
?>
<div class="vud-widget-alternate">
<?php if ($class_up) : ?>
  <div id="total-votes-<?php print $type; ?>-<?php print $cid; ?>" class="<?php print $widget_theme; ?>-votes-display"><?php print $unsigned_points; ?></div>
  <a href="<?php print $link_up; ?>"><div id="vote-up-<?php print $type; ?>-<?php print $cid; ?>" class="<?php print $class_up; ?>" title="Vote up!"></div></a>
<?php endif; ?>
</div>

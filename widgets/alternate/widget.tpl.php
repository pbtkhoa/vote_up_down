<?php
// $Id$
/**
 * @file widget.tpl.php
 *
 * Alternate widget theme for Vote Up/Down
 */
$unsigned_points = (int) $points;
?>
<div class="vud-widget-<?php print $widget_theme; ?>">
<?php if ($class_up) : ?>
  <div id="total-votes-<?php print $cid; ?>" class="<?php print $widget_theme; ?>-votes-display"><?php print $unsigned_points; ?></div>
  <div id="vote-up-<?php print $cid; ?>" class="<?php print $class_up; ?>" title="<?php print $title_up; ?>"><?php print $link_up; ?></div>
<?php endif; ?>
</div>

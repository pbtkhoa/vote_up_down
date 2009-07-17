<?php
// $Id$
/**
 * @file widget.tpl.php
 *
 * Alternate widget theme for Vote Up/Down
 */
?>
<div class="vud-widget-<?php print $widget_theme; ?>">
<?php if ($class_up) : ?>
  <span id="vote_up_<?php print $cid; ?>" class="<?php print $class_up; ?>" title="<?php print $title_up; ?>"><?php print $link_up; ?></span>
<?php endif; ?>
</div>

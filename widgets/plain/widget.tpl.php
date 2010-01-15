<?php
// $Id$
/**
 * @file
 * widget.tpl.php
 *
 * Plain widget theme for Vote Up/Down
 */
?>
<div class="vud-widget-plain">
<?php if ($class_up): ?>
  <?php if ($readonly): ?>
    <span id="vote-up-<?php print $type; ?>-<?php print $cid; ?>" class="<?php print $class_up; ?>" title="Vote up!"></span>
    <span id="vote-down-<?php print $type; ?>-<?php print $cid; ?>" class="<?php print $class_down; ?>" title="Vote down!"></span>
  <?php else: ?>
    <a href="<?php print $link_up; ?>"><span id="vote-up-<?php print $type; ?>-<?php print $cid; ?>" class="<?php print $class_up; ?>" title="Vote up!"></span></a>
    <a href="<?php print $link_down; ?>"><span id="vote-down-<?php print $type; ?>-<?php print $cid; ?>" class="<?php print $class_down; ?>" title="Vote down!"></span></a>
  <?php endif ?>
<?php endif ?>
</div>

<?php
// $Id$
/**
 * @file widget.tpl.php
 *
 * Plain widget theme for Vote Up/Down
 * This template handles default voting widget output. Available variables:
 * - $widget_theme: The widget theme that is being rendered;
 * - $points: The total number of vote points for this object;
 * - $class_up: "up-active" or "up-inactive";
 * - $class-down: "down-active" or "down-inactive";
 * - $title_up, $title-up: Contains a voting URL, should not be removed;
 * - $link-up, $link-down: Voting URI for users with disabled JavaScript;
 * - $cid: $node->nid or $comment->cid or other unique object ID;
 */
?>
<div class="vud-widget-<?php print $widget_theme; ?>">
<?php if ($class_up) { ?>
  <span id="vote-up-<?php print $cid; ?>" class="<?php print $class_up; ?>" title="<?php print $title_up; ?>"><?php print $link_up; ?></span>
  <span id="vote-down-<?php print $cid; ?>" class="<?php print $class_down; ?>" title="<?php print $title_down; ?>"><?php print $link_down; ?></span>
<?php } ?>
</div>

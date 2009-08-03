<?php
// $Id$
/**
 * @file votes.tpl.php
 *
 * Plain widget votes display for Vote Up/Down
 * This template handles voting points output. Available variables:
 * - $points: points in +1 or -1 format;
 * - $label: translated points label without numbers ("point" or "points");
 * - $points_labelled: translated points label with numbers ("1 point" or "N points");
 * - $class: "positive", "negative" or "neutral" depending on the total vote points;
 * - $cid: $node->nid or $comment->cid or other unique object ID;
 */
?>
<span id="total-votes-<?php print $type; ?>-<?php print $cid; ?>" class="total-votes-plain"><span class="<?php print $class; ?> total"><?php print $points_labelled; ?></span></span>

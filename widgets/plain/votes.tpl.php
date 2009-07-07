<?php
// $Id$
/**
 * @file votes.tpl.php
 *
 * This template handles voting points output. Available variables:
 * - $points: points in +1 or -1 format;
 * - $label: translated points label without numbers ("point" or "points");
 * - $points_labelled: translated points label with numbers ("1 point" or "N points");
 * - $class: "positive", "negarive" or "neutral" regarding the points amout;
 * - $cid: $node->nid or $comment->cid;
 */
?>
<span id="vud_votes_<?php print $cid; ?>" class="total-votes"><span class="<?php print $class; ?>"><?php print $points_labelled; ?></span></span>

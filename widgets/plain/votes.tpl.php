<?php
// $Id$
/**
 * @file
 * votes.tpl.php
 *
 * Plain widget votes display for Vote Up/Down
 */
?>
<span id="total-votes-<?php print $type; ?>-<?php print $cid; ?>" class="total-votes-plain"><span class="<?php print $class; ?> total"><?php print $unsigned_points; ?> <?php print $vote_label; ?></span></span>

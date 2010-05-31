<?php
// $Id$
/**
 * @file
 * widget.tpl.php
 *
 * Plain widget theme for Vote Up/Down
 */
?>
<div class="vud-widget vud-widget-plain" id="<?php print $id; ?>">
<?php if ($class_up): ?>
    <a href="<?php print $link_up; ?>" class="<?php print $link_class_up; ?>">
      <span class="<?php print $class_up; ?>" title="<?php print t('Vote up!'); ?>"></span>
    </a>
    <a href="<?php print $link_down; ?>" class="<?php print $link_class_down; ?>">
      <span class="<?php print $class_down; ?>" title="<?php print t('Vote down!'); ?>"></span>
    </a>
<?php endif; ?>
</div>

<?php

/**
 * @file
 * Default template for admin toolbar.
 *
 * @see template_preprocess()
 * @see template_preprocess_up_navbar()
 *
 * @ingroup themeable
 */
?>
<div id="up_navbar_header" class="<?php print $classes; ?> clearfix">
  <div id="up_navbar_header_menu">
    <?php print render($up_navbar_header['header_menu']); ?>
  </div>
  <?php print render($up_navbar_header['user_box']); ?>
</div>

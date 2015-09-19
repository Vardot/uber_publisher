<?php
/**
 * @file
 * Default template for UP navbar avatar.
 *
 * @see up_navbar_header_pre_render()
 *
 * @ingroup themeable
 */
?>
<div id="face_box">
  <a href="" class="face-box-avatar" tabindex="-1">
    <?php print render($up_navbar_face_box['user_avatar']); ?>
    <b class="caret"></b>
  </a>
  <nav class="face-box-dropdown"><?php print render($up_navbar_face_box['user_menu']); ?></nav>
</div>

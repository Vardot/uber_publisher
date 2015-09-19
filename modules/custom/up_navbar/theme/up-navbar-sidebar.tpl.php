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
<nav id="up_navbar_navigation" class="<?php print $classes; ?> clearfix">
  <div class="up-navbar-navigation-top">
    <?php print render($up_navbar_sidebar['home_link']); ?>
    <div id="shortcut-menu-wrapper"><?php print render($up_navbar_sidebar['shortcut_tree']); ?></div>
  </div>
  
  <div class="up-navbar-navigation-bottom">
    <a href="" class="management-menu-link up-navigation-link" tabindex="-1">
      <span class="element-invisible">Management Menu</span>
      <i class="up-icon"></i>
    </a>
  </div>

  <div id="management-menu-wrapper">
    <?php print render($up_navbar_sidebar['management_menu']); ?>
  </div>
</nav>

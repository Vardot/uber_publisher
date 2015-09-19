(function ($) {

/**
 * Attach up_navbar behavior.
 */
Drupal.behaviors.toolbar = {
  attach: function(context) {
    // Toggling user-menu dropdown.
    $('#face_box .face-box-avatar', context).once('face-box-dropdown').click(function(event) {
      $(this).siblings('.face-box-dropdown').toggle();
      $(window).triggerHandler('resize');
      return false;
    });

    // Toggling management-menu slide.
    $('#up_navbar_navigation .management-menu-link', context).once('management-menu-wrapper').click(function(event) {
      $('#management-menu-wrapper', context).toggleClass('open');
      $('body', context).toggleClass('management-menu-wrapper-open');
      $(window).triggerHandler('resize');
      return false;
    });
  }
};

})(jQuery);

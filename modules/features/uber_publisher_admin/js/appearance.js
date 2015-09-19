// JavaScript should be made compatible with libraries other than jQuery by
// wrapping it with an "anonymous closure". See:
// - https://drupal.org/node/1446420
// - http://www.adequatelygood.com/2010/3/JavaScript-Module-Pattern-In-Depth
(function ($, Drupal, window, document, undefined) {

  Drupal.behaviors.uber_publisher_admin_appearance = {
    attach: function (context, settings) {
      settings.uber_publisher_admin = settings.uber_publisher_admin || {}
      var appearance_settings = settings.uber_publisher_admin.appearance  || {};
      if ($.isArray(appearance_settings.colorpicker_settings.input)) {
          $(appearance_settings.colorpicker_settings.input).each(function(index, class_name) {
            var input = $('.' + class_name);
            input.ColorPicker({
              color: input.val(),
              onShow: function (colpkr) {
                $(colpkr).fadeIn(500);
                return false;
              },
              onHide: function (colpkr) {
                $(colpkr).fadeOut(500);
                return false;
              },
              onChange: function (hsb, hex, rgb) {
                input.val('#' + hex);
              }
          });
        });
      }
    }
  }
})(jQuery, Drupal, this, this.document);

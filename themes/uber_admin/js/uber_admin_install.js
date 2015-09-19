// JavaScript should be made compatible with libraries other than jQuery by
// wrapping it with an "anonymous closure". See:
// - https://drupal.org/node/1446420
// - http://www.adequatelygood.com/2010/3/JavaScript-Module-Pattern-In-Depth
(function ($, Drupal, window, document, undefined) {

  Drupal.behaviors.uber_admin_install = {
    attach: function (context, settings) {
      try {
        jQuery.ajax({
          url: '//ipinfo.io/', 
          type: 'GET', 
          dataType: 'jsonp',
          success: function(response) {
            if (typeof(response.country) == 'string') {
              jQuery('#edit-site-default-country option[value="'+response.country+'"]').attr('selected', 'selected');
            }
            // @todo add support for timezone if possible.
          }
        });
      } catch (e) {
       // Do nothing I dont care.
      }
    }
  };
})(jQuery, Drupal, this, this.document);

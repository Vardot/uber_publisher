// JavaScript should be made compatible with libraries other than jQuery by
// wrapping it with an "anonymous closure". See:
// - https://drupal.org/node/1446420
// - http://www.adequatelygood.com/2010/3/JavaScript-Module-Pattern-In-Depth
(function ($, Drupal, window, document, undefined) {

  Drupal.behaviors.vartheme_views_view = {
    attach: function (context, settings) {
      // Varbase FPP Slideshow - Highlighted Slider
      if($('.varbase-fpp-highlighted-slides', context).length > 0) {
        $('.highlighted-pager > div', context).click(function(event) {
          $('.highlighted-slide').html($(this).html());
        });
      }
    }
  }
})(jQuery, Drupal, this, this.document);

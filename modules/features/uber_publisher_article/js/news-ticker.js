// JavaScript should be made compatible with libraries other than jQuery by
// wrapping it with an "anonymous closure". See:
// - https://drupal.org/node/1446420
// - http://www.adequatelygood.com/2010/3/JavaScript-Module-Pattern-In-Depth
(function ($, Drupal, window, document, undefined) {

  Drupal.behaviors.newsTicker = {
    attach: function (context, settings) {
      $('.news-ticker-list').marquee({
        delayBeforeStart: 1000,
        duration: 12000,
        gap: 100,
      });
    }
  }
})(jQuery, Drupal, this, this.document);

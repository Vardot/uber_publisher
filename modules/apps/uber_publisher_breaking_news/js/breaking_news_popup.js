// JavaScript should be made compatible with libraries other than jQuery by
// wrapping it with an "anonymous closure". See:
// - https://drupal.org/node/1446420
// - http://www.adequatelygood.com/2010/3/JavaScript-Module-Pattern-In-Depth
(function ($, Drupal, window, document, undefined) {

  Drupal.behaviors.breaking_news_popup = {
    attach: function (context, settings) {
      var basePath = Drupal.settings.basePath;
      // Get Breaking News NID from cookies
      var indexPrinted = $.cookie('breaking_news_nid');
      if (indexPrinted != null) {
        indexPrinted = indexPrinted.split('+');
      } else {
        var indexPrinted = [];
      }

      // Start PULL loop every 30 second
      var _ajax_breaking_news_noty = function () {
        $.get(basePath + 'ajax/uber_publisher_breaking_news', function (data) {
          if (typeof (data.nodes) == 'object' && Object.keys(data.nodes).length > 0) {
            $.each(data.nodes, function (index, element) {

              // Dont show already printed Breaking News
              if (indexPrinted.indexOf(index) != -1) {
                return;
              }

              // Save printed Breaking News in a variable and a cookie
              indexPrinted.push(index);
              $.cookie('breaking_news_nid', indexPrinted.join('+'), {
                expires: 1,
                path: basePath,
              });

              // Print the notification
              noty({
                text: element.html,
                type: 'notification',
                dismissQueue: true,
                maxVisible: 1,
//              timeout: 10000,
                modal: false,
                closeWith: ['button', 'click'],
                layout: 'bottom_left',
                theme: 'breakingNewsTheme'
              });
            });
          }
        });
      };

      _ajax_breaking_news_noty();
      var IntervalID = window.setInterval(_ajax_breaking_news_noty, 30000);
    }
  };

})(jQuery, Drupal, this, this.document);

// jQuery.noty theme look at the library directory for more examples
(function ($) {
  $.noty.themes.breakingNewsTheme = {
    name: 'breakingNewsTheme',
    style: function () {
      var containerSelector = this.options.layout.container.selector;
      $(containerSelector).addClass('list-group-list');

      this.$closeButton.append('<span aria-hidden="true">&times;</span><span class="sr-only">Close</span>');
      this.$closeButton.addClass('close');

      this.$bar.addClass("list-group-item");
    },
    callback: {
      onShow: function () {
        if ($('.node-breaking-news.node-teaser').length > 0) {
          $('.node-breaking-news.node-teaser').typewriter();
        }
      },
      onClose: function () {
        $('#noty_bottom').remove();
      }
    }
  };
})(jQuery);

(function ($) {
  $.noty.layouts.bottom_left = {
    name: 'bottom_left',
    options: {},
    container: {
      object: '<ul id="noty_bottom_layout_container" class="container" />',
      selector: 'ul#noty_bottom_layout_container',
      style: function () {
//        $(this).css({
//          bottom: 0,
//          left: '0',
//          position: 'fixed',
//          width: '100%',
//          height: 'auto',
//          margin: 0,
//          padding: 0,
//          listStyleType: 'none',
//          zIndex: 9999999
//        });
        $('#noty_bottom').remove();
        $(this).wrap('<div id="noty_bottom"></div>');
        
      }

    },
    parent: {
      object: '<li />',
      selector: 'li',
      css: {
      }
    },
    css: {
      display: 'none'
    },
  };
})(jQuery);

(function ($) {
  $.fn.typewriter = function () {
    this.each(function () {
      var $ele = $(this), str = $ele.text(), progress = 0;
      $ele.text('');
      var timer = setInterval(function () {
        $ele.text(str.substring(0, progress++) + (progress & 1 ? '_' : ''));
        if (progress >= str.length)
          clearInterval(timer);
      }, 40);
    });
    return this;
  };
})(jQuery);
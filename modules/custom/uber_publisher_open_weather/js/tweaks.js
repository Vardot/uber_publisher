(function ($, _, Drupal) {
  "use strict";

  Drupal.behaviors.weather = {
    attach: function (context, settings) {

      var html;
      // Service to get log and lat from IP address
      $.get("http://ip-api.com/json", function (response) {
        loadWeather(response.lat + ',' + response.lon); //call weather function
      }, "jsonp");


      function loadWeather(location, woeid) {
        $.simpleWeather({
          location: location,
          woeid: woeid,
          unit: 'C',
          success: function (weather) {
            html = '<div class="city">' + weather.city + '</div>';
            html += '<div>' + weather.temp + '&deg;' + weather.units.temp + '<i class="icon-' + weather.code + '"></i></div>';
            $("#weather").html(html);
          }
        });
      }
    }
  };

})(jQuery, _, Drupal);

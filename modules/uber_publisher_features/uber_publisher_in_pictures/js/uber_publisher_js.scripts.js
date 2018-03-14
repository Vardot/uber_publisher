(function ($, Drupal, drupalSettings) {

	'use strict';

	$(document).ready(function () {
		// Default view hide slider and show pig pictures.
		$('.field--name-dynamic-block-fieldnode-in-pictures-slider-view').css('display', 'none');
		$('#in-pictures-list').addClass('active');
		// Listen to click list tab.
		$('#in-pictures-list').on('click', function () {
			$('.field--name-dynamic-block-fieldnode-in-pictures-big-picture-view').css('display', 'block');
			$('.field--name-dynamic-block-fieldnode-in-pictures-slider-view').css('display', 'none');
			$(this).addClass('active');
			$('#in-pictures-slider').removeClass('active');
		});
		// Listen to click slider tab.
		$('#in-pictures-slider').on('click', function () {
			$('.field--name-dynamic-block-fieldnode-in-pictures-big-picture-view').css('display', 'none');
			$('.field--name-dynamic-block-fieldnode-in-pictures-slider-view').css('display', 'block');
			$(this).addClass('active');
			$('#in-pictures-list').removeClass('active');
		});
	});
})(jQuery, Drupal, drupalSettings);
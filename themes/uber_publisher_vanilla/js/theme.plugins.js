(function ($) {
   "use strict";

jQuery(document).ready(function () {

  $('.gva-search-region .search-icon').on('click',function(e){
    if($(this).parent().hasClass('show')) {
      $(this).parent().removeClass('show');
      $('i.fa-times').removeClass('fa-times').addClass('fa-search');
    }
    else {
      $(this).parent().addClass('show');
      $('.block-views-exposed-filter-blocksearch-search-page input').focus();
      $('i.fa-search').removeClass('fa-search').addClass('fa-times');
    }
    e.stopPropagation();
  });

  $('.block-views-exposed-filter-blocksearch-search-page input').attr('placeholder','Search');
  $('.block-views-exposed-filter-blocksearch-search-page input').attr('required','true');

  // ==================================================================================
  // Offcavas
  // ==================================================================================
  $('#menu-bar').on('click',function(e){
    if($('.gva-navigation').hasClass('show-view')) {
      $(this).removeClass('show-view');
      $('.gva-navigation').removeClass('show-view');
      $('body').removeClass('menu-opened');
      $('.overlay-body').remove();
    }
    else {
      $(this).addClass('show-view');
      $('.gva-navigation').addClass('show-view');
      $('body').addClass('menu-opened');
      $('body').append('<div class="overlay-body"></div>');
    }

    e.stopPropagation();
  })

    /*========== Click Show Sub Menu ==========*/

    $('.gva-navigation a').on('click','.nav-plus',function() {
        if($(this).hasClass('nav-minus') == false) {
          $(this).parent('a').parent('li').find('> ul').slideDown();
          $(this).addClass('nav-minus');
        }
        else {
          $(this).parent('a').parent('li').find('> ul').slideUp();
          $(this).removeClass('nav-minus');
        }
        return false;
    });

  // ============================================================================
  // Fixed top Menu Bar
  // ============================================================================
  if($('.gv-sticky-menu').length > 0){
    var sticky = new Waypoint.Sticky({
      element: $('.gv-sticky-menu')[0]
    });
  }

  // Remove editors pick section from not logged in users if it'sempty.
  if ($("body.user-logged-in").length) {
    $(".block-views-blockarticles-editors-pick-article:has('.view-empty')").css('display','block');
  }
  else {
    $(".block-views-blockarticles-editors-pick-article:has('.view-empty')").css('display','none');
  }

  // Remove the Breaking new section if it's empty.
  if($('.breaking-news .view-empty').length) {
    $(".breaking-news").css('display','none');
  }

});

})(jQuery);

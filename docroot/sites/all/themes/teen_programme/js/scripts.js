(function ($, Drupal) {

  Drupal.behaviors.teen_programmePhoneNumberLinksOnMobile = {
    attach: function(context, settings) {

      // var text = jQuery('#page-title').text();
      // if(text == 'Spanish my account') {
        
      //   var text = jQuery('#page-title').text('My Account'); 
      // }
        //message button change its background color by adding class new
        $('.msg:has(.new)').addClass('new');
        //announcement block change its image field as background image
      $('.annoncement-block .annocement').each(function() {
      if ($(this).find('img').length) {
        var imgURL = $(this).find('img').attr('src');
        $(this).css('background-image', 'url(' + imgURL + ')');
      }
    });
      //mobile menu
      $("button.hamburger").click(function() {
         $(".mobile-menu-wrapper").toggle();

      });
    //add readmore link
     $(function(){
      $('.page-rewards .main .block-views .view-teen-reward-page .reward-body-wrapp .reward-des').each(function(event){
         var max_length = 45;
         if($(this).html().length > max_length) {
           var short_content = $(this).html().substr(0,max_length);
           var long_content = $(this).html().substr(max_length);
           $(this).html(short_content+'<span class="temparory">...</span>'+
              '<a href="#" class="read_more"><br/>Read More..</a>'+
              '<span class="more_text" style="display:none;">'+long_content+'</span>'
            );
           $(this).find('a.read_more').click(function(event){
              event.preventDefault();
              $(this).hide();
              $(this).parents('.reward-des').find('.more_text').show();
              $(this).parents('.reward-des').find('.temparory').hide();
           });
         }
      });
     });
    //booklist and book-review title replacement
     $('.book-reviews-page .reviews-subtitle').insertAfter('.book-reviews-page .view-filters');
    //dashboard page overwrite homepage module jquery and make theming easier
    var activites =$('.homebox-draggable:has(.view-activities-dashboard)').addClass('dashboard-activities');
    var rewards =$('.homebox-draggable:has(.view-rewards-dashboard)').addClass('dashboard-rewards');
    var reviews =$('.homebox-draggable:has(.view-book-reviews-dashboard.review)').addClass('dashboard-reviews');
    var booklist =$('.homebox-draggable:has(.view-book-reviews-dashboard.booklist)').addClass('dashboard-booklists');
    var follow =$('.homebox-draggable:has(.view-follow-block-dashboard)').addClass('dashboard-following');
    var leaderboard =$('.homebox-draggable.block-play_library_teens_leaderboard').addClass('dashboard-leaderboard');
    var obj =$("#homebox-add ul li");
    $.each( obj , function( key, value ) {
    $(value).addClass($(value).find('a').text().toLowerCase());
     var crntState =$('.dashboard-'+$(value).find('a').text().toLowerCase()).css('display');
      if (crntState != 'undefined') {
        if (crntState == 'block') {
         $(value).hide();
        } else  {
         $(value).show();
        }
      }
    });


    }
  };

})(jQuery, Drupal);

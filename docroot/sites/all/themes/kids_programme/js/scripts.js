(function ($, Drupal) {

  Drupal.behaviors.kids_programmePhoneNumberLinksOnMobile = {
    attach: function(context, settings) {
        //message button change its background color by adding class new
        $('.msg:has(.new)').addClass('new');
        //announcement block change its image field as background image
           $('.annoncement-block .annocement').each(function() {
      if ($(this).find('img').length) {
        var imgURL = $(this).find('img').attr('src');
        $(this).css('background-image', 'url(' + imgURL + ')');
      }

  });


    }
  };

})(jQuery, Drupal);

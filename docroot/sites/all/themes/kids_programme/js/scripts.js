(function ($, Drupal) {

  Drupal.behaviors.kids_programmePhoneNumberLinksOnMobile = {
    attach: function(context, settings) {
        jQuery('.msg:has(.new)').addClass('new');


    }
  };

})(jQuery, Drupal);

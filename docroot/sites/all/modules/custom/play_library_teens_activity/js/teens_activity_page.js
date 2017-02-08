/**
 * function callback for progress page report
 */
(function($) {
Drupal.behaviors.bfc_api_custom = {
  attach: function (context, settings) {
    var basePath = Drupal.settings.basePath; 
    jQuery( '.view-activities-page-for-teens-site .form-type-select .form-select' ).change(function() {
      var url = jQuery(this).val();
      window.location.href = basePath + url;
    });
  
  }
};
})(jQuery);

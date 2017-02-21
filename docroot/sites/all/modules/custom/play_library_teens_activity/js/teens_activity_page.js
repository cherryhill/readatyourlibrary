/**
 * function callback for progress page report
 */
(function($) {
Drupal.behaviors.bfc_api_custom = {
  attach: function (context, settings) {
  	// Js for activity page.
    var basePath = Drupal.settings.basePath; 
    jQuery( '.view-activities-page-for-teens-site .form-type-select .form-select' ).change(function() {
      var url = jQuery(this).val();
      window.location.href = basePath + url;
    });
    // Js for create reviews block.
    jQuery( '.form-item-read-activity .form-select' ).change(function() {
      var url = jQuery(this).val();
      window.location.href = basePath + url;
    });

    jQuery('.page-admin-structure-entity-type-reward-reward-add #eck-entity-form-add-reward-reward .form-item-title label').text('Reward title / Name of raffle').append('<span class="form-required" title="This field is required.">*</span>');
    jQuery('.page-admin-structure-entity-type-reward-reward-edit #eck-entity-form-edit-reward-reward .form-item-title label').text('Reward title / Name of raffle').append('<span class="form-required" title="This field is required.">*</span>');
  }
};
})(jQuery);

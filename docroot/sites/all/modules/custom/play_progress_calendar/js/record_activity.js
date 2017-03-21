(function($) {
  Drupal.behaviors.play_progress_teen = {
    attach: function (context, settings) {
      $("#patron-activity-record-form #edit-username").change(function() {
        $('#views-exposed-form-raffle-winners-page #edit-uid').val( this.value );
      });
    }
  }
}) (jQuery);

(function ($) {

  Drupal.behaviors.scaldFlickr = {
    attach: function (context, settings) {
      $('input#edit-results-select-all-import').change(function() {
        if ($(this).attr('checked') == false) {
          $('table#scald-flickr-images input.form-checkbox:not(#edit-results-select-all-import)').attr('checked', false);
        }
        else {
          $('table#scald-flickr-images input.form-checkbox:not(#edit-results-select-all-import)').attr('checked', true);
        }
      });
    }
  }

})(jQuery);

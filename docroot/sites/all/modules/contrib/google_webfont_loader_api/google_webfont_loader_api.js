/**
 * @file
 * This file retrieves the webfont js file from google if necessary and loads
 * the webfont loader with the appropriate file callbacks.
 */
(function ($) {
  Drupal.behaviors.google_webfont_loader = {
    attach: function() {
      $('body').once('google-webfont-loader', function() {
        try {
          WebFont.load(Drupal.settings.google_webfont_loader_api_setting);
        } catch(err) {
          console.log('Webfont Library has not loaded. Check that you are connected to the internet.');
        }
      });
      // Remove the wf-loading class after a few seconds. This is to make sure
      // that your content is not forever hidden from being displayed in the
      // event of a font not loading (or font-face not supported) failure.
      setTimeout(function() {
        var html_object = $('html');
        if ($(html_object).hasClass('wf-loading')) {
          $(html_object).removeClass('wf-loading');
        }
      }, 3000);
    }
  }
})(jQuery);

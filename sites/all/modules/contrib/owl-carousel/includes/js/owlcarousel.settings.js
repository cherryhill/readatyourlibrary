/**
 * @file
 * Initiate Owl Carousel.
 */

(function($) {
  Drupal.behaviors.owlcarousel = {
    attach: function(context, settings) {
      for (var carousel in settings.owlcarousel) {
        // lazyLoad support.
        if (settings.owlcarousel[carousel].lazyLoad) {
          var images = $('#' + carousel).find('img');

          $.each(images, function(i, image) {
            $(image).attr('data-src', $(image).attr('src'));
          });

          images.addClass('lazyOwl');
        }

        // Attach instance settings.
        $("#" + carousel).owlCarousel(settings.owlcarousel[carousel]);
      }
    }
  };
}(jQuery));

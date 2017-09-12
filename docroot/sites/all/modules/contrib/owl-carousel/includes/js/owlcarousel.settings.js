/**
 * @file
 * Initiate Owl Carousel.
 */

(function($) {

  Drupal.behaviors.owlcarousel = {
    attach: function(context, settings) {
    
      for (var carousel in settings.owlcarousel) {
        // Carousel instance.
        var owl = $('#' + carousel);

        // lazyLoad support.
        if (settings.owlcarousel[carousel].settings.lazyLoad) {
          var images = owl.children('img');

          $.each(images, function(i, image) {
            $(image).attr('data-src', $(image).attr('src'));
          });

          images.addClass('lazyOwl');
        }

        // Attach instance settings.
        owl.owlCarousel(settings.owlcarousel[carousel].settings);

        // Set an inline height if custom AJAX pagination is enabled;
        // otherwise replacement of carousel element causes scrolling effect.
        if (settings.owlcarousel[carousel].views.ajax_pagination) {
          owl.parent().css('height', owl.height());

          var view = owl.parent().parent();
          var next = $(view).find('.pager-next a');
          var prev = $(view).find('.pager-previous a');

          // Attach Owl Carousel behaviors to pager elements.
          $(next, context).click(function() {
            owl.trigger('owl.next');
          })
          $(prev, context).click(function() {
            owl.trigger('owl.prev');
          })
        }
      }
    }
  };

}(jQuery));

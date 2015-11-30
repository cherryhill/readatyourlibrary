/**
 * @file
 * Adds form selector behaviors for setting up random items.
 * May move to ajax down the line.
 */
(function ($) {
  Drupal.behaviors.random_list_widget_field = {
    attach: function() {
      $('.random-list-widget-regenerate').click(function() {
        var classes = $(this).attr('class').split(" ");
        for (i = 0; i < classes.length; i++) {
          if (classes[i].startsWith('random_list_widget_text_')) {
            my_list = Drupal.settings[classes[i]];
            var item = my_list[Math.floor(Math.random()*my_list.length)];
            var input = $(this).parent().find('.random-list-widget');
            $(input).val(item);
          }
        }
        return false;
      });
    }
  }
})(jQuery);
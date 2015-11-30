/**
 * Display banner if using Internet Explorer. Presence of markup is controlled by IE conditional comments.
 */
(function ($) {

Drupal.behaviors.ie6nomore = {
  attach: function (context) {
    if($.browser.msie && !$.cookie('ie6nomore_dismissed')) {
      $("body").prepend($("#ie6nomore")).find('#ie6nomore').show();
      // Attach dismiss action to link.
      $("#ie6nomore .close-button").click(function() {
        $('#ie6nomore').hide();
        $.cookie('ie6nomore_dismissed', 1);
      });
    }
  }
};

})(jQuery);

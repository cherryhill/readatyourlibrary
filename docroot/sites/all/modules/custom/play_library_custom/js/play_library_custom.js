/**
 * function callback for progress page report
 */
(function($) {
  
  Drupal.behaviors.play_progress_teen = {
    attach: function (context, settings) {
      // select list option with thier link
      $('.add_review_node').change(function(){
        var option = jQuery(this).find('option:selected').val();
        if(option != 0){
          window.location = option;
        }else{
          return false;
        }
      });
    }
  };
})(jQuery);
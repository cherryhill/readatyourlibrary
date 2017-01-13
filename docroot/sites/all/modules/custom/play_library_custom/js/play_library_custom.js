/*
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
      //wrap 3 block in one and make a slider
       $('input[type="radio"]').click(function(){
         $(".slide").removeClass('open');
        if($(this).attr("value")=="blslider1"){
        $(".slide").not(".blslider1").addClass('close');
        $(".blslider1.slide").removeClass('close').addClass('open');

      }
      if($(this).attr("value")=="blslider2"){
        $(".slide").not(".blslider2").addClass('close');
        $(".blslider2.slide").removeClass('close').addClass('open');
      }
      if($(this).attr("value")=="blslider3"){
        $(".slide").not(".blslider3").addClass('close');
        $(".blslider3.slide").removeClass('close').addClass('open');
      }

  });
      //making accordian
       $('.accordionWrapper .accordionItem').addClass('close');
       $('.accordionWrapper .accordionItem legend').click(function(){

         if($(this).parent().parent().hasClass('open')) {
           $(this).parent().parent().removeClass('open').addClass('close');
         }else {
          $('.accordionWrapper .accordionItem').removeClass('open').addClass('close');
          $(this).parent().parent().removeClass('close').addClass('open');

         }
       });
      //Making single selection for avatar image
      $(".av_radio.form-radio").change(function () {
        $('.av_radio.form-radio').not(this).prop('checked', false);
      });
    }
  };
})(jQuery);

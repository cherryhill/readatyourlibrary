(function ($, Drupal) {

  Drupal.behaviors.STARTER = {
    attach: function(context, settings) {
      // Get your Yeti started.
    }
  };

})(jQuery, Drupal);
jQuery( document ).ready(function() {


  /* jQuery for homepage book slider */
  jQuery(".blslider2.slide").hide();
  jQuery(".blslider3.slide").hide();
  jQuery(".blslider1").show();

    jQuery('input[type="radio"]').click(function(){
        if(jQuery(this).attr("value")=="blslider1"){
        jQuery(".slide").not(".blslider1").hide();
        jQuery(".blslider1.slide").show();

      }
      if(jQuery(this).attr("value")=="blslider2"){
        jQuery(".slide").not(".blslider2").hide();
        jQuery(".blslider2.slide").show();
      }
      if(jQuery(this).attr("value")=="blslider3"){
        jQuery(".slide").not(".blslider3").hide();
        jQuery(".blslider3.slide").show();
      }
     
  });
  /**jquery for removing header and footer from lightbox**/
   jQuery('#lightbox  .l-header').hide();
   jQuery('#lightbox  .post-footer').hide();
  /**jquery for new msg**/
  jQuery('.msg:has(.new)').addClass('newclass');
  /**jquery for swap divs in register page***/
   div1 = jQuery('#edit-profile-main-field-receive-notifications .form-radios');
    div2 = jQuery('#edit-profile-main-field-receive-notifications .description');

    tdiv1 = div1.clone();
    tdiv2 = div2.clone();

if(!div2.is(':empty')){
    div1.replaceWith(tdiv2);
    div2.replaceWith(tdiv1);
    
    tdiv1.addClass("replaced");
}
 });

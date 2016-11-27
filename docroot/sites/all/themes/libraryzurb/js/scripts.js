(function ($, Drupal) {

  // This fuction adds a class to phone number links on small screens. We use
  // this class to style phone number links as buttons on small screens.
  Drupal.behaviors.libraryzurbPhoneNumberLinksOnMobile = {
    attach: function(context, settings) {

      // Showing of email notification field if user enters valid email
      $('#edit-profile-main-field-receive-notifications').addClass('mail-notification-hidden')
      $('#edit-mail').blur(function() {
          var testEmail = /^[A-Z0-9._%+-]+@([A-Z0-9-]+\.)+[A-Z]{2,4}$/i;
          if (testEmail.test(this.value)) {
              $('#edit-profile-main-field-receive-notifications').removeClass('mail-notification-hidden');
          }
          else ($('#edit-profile-main-field-receive-notifications').addClass('mail-notification-hidden'));
      });
    //MyDashboard page hide homebox add buttons when dragable homebox blocks are visible
     var activites =$('.homebox-draggable:has(.view-my-activities-for-patron-dashboard)').addClass('dashboard-activities');
var rewards =$('.homebox-draggable:has(.view-patron-rewads-for-patron-dashboard)').addClass('dashboard-rewards');
var reviews =$('.homebox-draggable:has(.view-my-book-reviews)').addClass('dashboard-reviews');
var booklist =$('.homebox-draggable:has(.view-booklist-on-activities-page)').addClass('dashboard-booklists');
var follow =$('.homebox-draggable:has(.view-follow)').addClass('dashboard-following');
var leadeboard =$('.homebox-draggable:has(.view-leadeboard)').addClass('dashboard-leaderboard');
var progress =$('.homebox-draggable:has(.msg-highlight)').addClass('dashboard-progress');
var obj =$("#homebox-add ul li");
$.each( obj , function( key, value ) {
$(value).addClass($(value).find('a').text().toLowerCase());
 var crntState =$('.dashboard-'+$(value).find('a').text().toLowerCase()).css('display');
  if (crntState != 'undefined') { 
    if (crntState == 'block') {
     $(value).hide();
    } else  {
     $(value).show();
    }
  }
});
      //Making single selection for avatar image
      $(".av_radio.form-radio").change(function () {
        $('.av_radio.form-radio').not(this).prop('checked', false);
      });
        //Announcement block in landing page make image field as background image
     $('.block.announcement').each(function() {
      if ($(this).find('img').length) {
        var imgURL = $(this).find('img').attr('src');
        $(this).css('background-image', 'url(' + imgURL + ')');
      $('.block.announcement img').hide();
      }
   
  });

      // Hiding of private message notification
      $('.page-user-edit #edit-privatemsg').hide();
      $('.page-user-edit-main .username-curr').hide();
      
     //make accordian of avtar images in user register page
       function getpanels(panelclass) {

        var panels = $('.'+panelclass+' #checkboxes-div #checkboxes-div .fieldset-wrapper').hide();
    
        $('.'+panelclass+' #checkboxes-div #checkboxes-div legend .fieldset-legend').click(function() {
          panels.slideUp();
        $(this).parent().next('.fieldset-wrapper').toggle();
       
        return false;
        });
      }
      if($('body.section-user').length > 0) {
        getpanels('section-user');
      }
      else if($('body.page-user-register').length > 0) {
        getpanels('.page-user-register');
      }
      // Get width of browser viewport. **Note:** The value we check against
      // should probably match the value set for `$topbar-breakpoint` in
      // libraryzurb/scss/_variables.scss.
      var windowWidth = $( window ).width();
      if ( windowWidth < 769 ) {
        $( 'a[href^="tel"]' ).addClass( 'button' );
      }
      if ( windowWidth >= 769 ) {
        $( 'a[href^="tel"]' ).removeClass( 'button' );
      }
    }
  };

})(jQuery, Drupal);





jQuery( document ).ready(function() {

// Js for mobile progress report

jQuery('.image_tracker').click(function() {
  var radio_image = jQuery("input[name = image_radio]:checked").prev().children().attr('src');
  var image_class = jQuery("input[name = image_radio]:checked").prev().children().addClass('active');
  var split_image = radio_image.split('?');
  var split_image1 = split_image[0].split('/');
  var image_name = split_image1[split_image1.length - 1];
  jQuery('#generate-mobile-progress-form .image_name').prop('value', image_name);


  
});

  // var str = window.location.href;
  // var n = str.lastIndexOf('&');
  // var result = str.substring(n + 1);
  // var splited_result = result.split("=")[0]; 
  // //alert(splited_result);
  // if(splited_result != 'undefined') {
  //   jQuery('.' + splited_result).next().prop('checked', true);
  // }



  /**interchanging the position of divs in progress page at mobile screen and tablet screen**/
  var windowWidth = jQuery( window ).width();
   if (windowWidth < 1025) {

     jQuery(".section-progress .main .block-auto-role-allocation-user-prize-block").insertAfter(".section-progress .main .progress-calendar");
      jQuery(".section-progress .main .block-views").insertAfter(".section-progress .main .progress-calendar");
      jQuery(".section-progress .main .block-auto-role-allocation-mobile-sticker-count").insertAfter(".section-progress .main .progress-calendar");
   }
   /**jquery for hamburger button in mobile screen**/
    jQuery('.mobile-header button').click(function(){
      jQuery('.mobile-header .block-private-msg-custom').toggle();
    });

  
  /* jQuery for homepage book slider */
  jQuery( '<p>Avatar icons provided free by <a href="http://emojione.com/"target="_blank"> Emoji One</a></p>' ).insertAfter( "#user-register-form" );
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
   
  /* jQuery for validation on username field of request new password page */
  jQuery(".page-user-password #user-pass #edit-name").keypress(function (e) {
    if (e.which === 64) {
      //display error message
      alert('Please enter only username');
      return false;
    }
  });

  // Placing Email div after field (how did you hear about the program)
  jQuery('.form-item-mail').insertAfter('.form-item-profile-main-field-how-did-you-hear-about-thi-und-other');

  //changes for follow link in user dashboard
  jQuery('.view-follow .view-header').insertAfter('.view-follow .attachment');
  
  /* Jquery for script for raffle entry checkbox */

    jQuery( ".active_raffle" ).click(function() {
        //var location = window.location;
        var baseUrl1 = Drupal.settings.basePath + 'raffle_pro';

      jQuery.ajax({
        
            //url: 'http://localhost/playatyourlibrary/docroot/raffle_pro',
            url: baseUrl1,
            success: function(res){
                //alert(res);
              jQuery('.raffle-filter-form').html(res);
            },
            error: function(jqXHR, data, error){
                // console.log(jqXHR);
                // console.log(data);
                // console.log(error);
            }
        });

      
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
  /* jquery for print calendar */

    jQuery( "#print_button" ).click(function() {
      var contant = jQuery(".l-main");
      var inner_content = contant.html();

      var WinPrint = window.open('', '', 'letf=0,top=0,width=400,height=400,toolbar=0,scrollbars=0,status=0');
        WinPrint.document.write(inner_content);
        WinPrint.focus();
        WinPrint.print();
        WinPrint.close();
    });

});





jQuery(document).on('click','#raffle_form_button',function() {

    
    
        //var location = window.location;
        var baseUrl1 = Drupal.settings.basePath + 'raffle_user_list';
        
        var raffleId = jQuery("input[name='raffle']:checked").attr('raffle_id');

        
        var reward_id = jQuery("input[name='raffle']:checked").val();
        var school = jQuery('#edit-school').val();
        var organization = jQuery('#edit-organization').val();
        var library_branch = jQuery('#edit-library-branch').val();
        var grade = jQuery('#edit-grade').val();

      jQuery.ajax({
        
            //url: 'http://localhost/playatyourlibrary/docroot/raffle_user_list',
            url: baseUrl1,
            async: false,
            type: 'post',
            data: 'active_raffle_id='+raffleId+'&school='+school+'&organization='+organization+'&library_branch='+library_branch+'&grade='+grade+'&reward_id='+reward_id,
            success: function(res){
                //alert(res);
              jQuery('.raffle-entry-user-list').html(res);
            },
            error: function(jqXHR, data, error){
                // console.log(jqXHR);
                // console.log(data);
                // console.log(error);
            }
        });

      
    
 });

jQuery(document).on('click','#raffle-entry-list-btn',function() {
  
  //var location = window.location;
  var baseUrl1 = Drupal.settings.basePath + 'raffle_winner';
  var raffleUid = '';
  jQuery( "input:checkbox:checked" ).each(function() { 
    var uid = jQuery( this ).attr( "id" );
    var uid_exp = uid.split('_');
    if (raffleUid == '') {
      raffleUid += uid_exp[1];
    } else {
      raffleUid += ',' + uid_exp[1];
    }
  });

  if (raffleUid == '') {
    alert('Please select user for Raffle Winner.');
    return false;
  }

  var reward_id = jQuery('#raffle_reward_id').val();

  jQuery.ajax({
    //url: 'http://localhost/playatyourlibrary/docroot/raffle_winner',
    url: baseUrl1,
    type: 'post',
    data: 'active_raffle_uid='+raffleUid+'&reward_id='+reward_id,
    success: function(res){
        url = "admin/content/dashboard?=true";
                //alert(res);
                window.location.reload(true);
                window.location.href = url;
                alert("Thank you Raffle winner has been selected"); 
            },
            error: function(jqXHR, data, error){
            }
  });

 

});


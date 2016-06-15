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

    

    var currentDate =  Drupal.settings.auto_role_allocation.currentDate;

    var time_strings = currentDate.split('-');

    var now_time_strings = parseInt(time_strings[0] + time_strings[1] + time_strings[2]);


    
    //if((now_time_strings >= pro_start_date) && now_time_strings <= pro_end_date) {
       //console.log("running");
       jQuery('.view-calendar-sticker .view-content .views-field-field-sticker-calendar-image .field-content').each(function () {

        // create an Event Object (http://arshaw.com/fullcalendar/docs/event_data/Event_Object/)
       // it doesn't need to have a start or end
        var eventObject = {
          title: jQuery.trim(jQuery(this).html()) // use the element's text as the event title
        };

        // store the Event Object in the DOM element so we can get to it later
         jQuery(this).data('eventObject', eventObject);

        // make the event draggable using jQuery UI
        jQuery(this).draggable({
          zIndex: 999,
          revert: true, // will cause the event to go back to its
          revertDuration: 0 //  original position after the drag
        });

      });

    //}

    

  

  jQuery('#calendar').fullCalendar({

    editable: true,
    droppable: true, // this allows things to be dropped onto the calendar !!!
        
    drop: function (date, allDay) {
     // this function is called when something is dropped
       // var count = jQuery(".fc-event-container").children('div').length;
        //alert(count);
        // retrieve the dropped element's stored Event Object
        var originalEventObject = jQuery(this).data(('eventObject'));
        
        // console.log("original");
        // console.log(originalEventObject);

        // we need to copy it, so that multiple events don't have a reference to the same object
        var copiedEventObject = jQuery.extend({}, originalEventObject);
        copiedEventObject.description = copiedEventObject.title;
        
        var calender_img = copiedEventObject.title; 
        var expl_img = calender_img.split("src");

        var expl_img1 = expl_img[1].split("?");
        var src_array = expl_img1[0].split('/');
        var image_name = src_array[src_array.length - 1];


        
        console.log(copiedEventObject.title);
        //console.log(copiedEventObject);

        // Event start date and end date

        var proStart = Drupal.settings.private_msg_custom.proStart;
        var start_string = proStart.split('-');
        var pro_start_date = parseInt(start_string[0] + start_string[1] + start_string[2]);

        var proEnd = Drupal.settings.private_msg_custom.proEnd;
        var end_string = proEnd.split('-');
        var pro_end_date = parseInt(end_string[0] + end_string[1] + end_string[2]);

        // assign it the date that was reported
        copiedEventObject.start = date;
        var event_date = copiedEventObject.start;
         event_date = event_date.toJSON().slice(0, 10);
         event_date = event_date.split('-');
         event_date = parseInt(event_date[0] + event_date[1] + event_date[2]);
         //alert(event_date);

        //console.log(copiedEventObject.start);
        copiedEventObject.allDay = allDay;

        // render the event on the calendar
        // the last `true` argument determines if the event "sticks" (http://arshaw.com/fullcalendar/docs/event_rendering/renderEvent/)
        jQuery('#calendar').fullCalendar('renderEvent', copiedEventObject, true);

        // is the "remove after drop" checkbox checked?
        if (jQuery('#drop-remove').is(':checked')) {
            // if so, remove the element from the "Draggable Events" list
            jQuery(this).remove();
        }

        //var loc = window.location;
        var baseUrl = Drupal.settings.basePath + 'calendar';

        var currentUser = Drupal.settings.auto_role_allocation.currentUser;
        if((event_date >= pro_start_date) && (event_date <= pro_end_date)) {
         if(now_time_strings >= event_date) {
          jQuery.ajax({
        
            //url: 'http://localhost/playatyourlibrary/docroot/calendar',
            url: baseUrl,
            async: false,
            type: 'post',
            data: 'image='+image_name+'&date='+copiedEventObject.start+'&user_id='+currentUser,
            success: function(res){ //alert(res);
              res = parseInt(res);
              window.location.reload(true);
            },
            error: function(jqXHR, data, error){
                // console.log(jqXHR);
                // console.log(data);
                // console.log(error);
            }
        });
      }
     } else {
       alert("You cannot record activity before or after program period.");
       window.location.reload(true);
     }
       
    },

    header: {
        left: 'prev,next today',
        center: 'title',
        right: 'month,agendaWeek,agendaDay'
    },
    // eventRender: function (event, element, view) {
    //     element.bind('click', function () {
    //         var day = (jQuery.fullCalendar.formatDate(event.start, 'dd'));
    //         var month = (jQuery.fullCalendar.formatDate(event.start, 'MM'));
    //         var year = (jQuery.fullCalendar.formatDate(event.start, 'yyyy'));
    //         alert(year + '-' + month + '-' + day);
    //     });
    // },
    editable: true,
    eventRender: function(event, element) {
        element.description = element[0].textContent;
        // $('#mycalendar').fullCalendar('renderEvent', event);
        // console.log('Element:');
         //console.log(element);
        return element.description;
    },
    eventDrop: function( event, dayDelta, minuteDelta, allDay, revertFunc, jsEvent, ui, view ) {
         

       var event_date1 = event.start;
         event_date1 = event_date1.toJSON().slice(0, 10);
         event_date1 = event_date1.split('-');
         event_date1 = parseInt(event_date1[0] + event_date1[1] + event_date1[2]);

        var currentUser = Drupal.settings.auto_role_allocation.currentUser;
        console.log(event.title);
        var event_title = event.title;
        var event_title1 = event_title.split('<div>');
        var event_title2 = event_title1[1].split('</div>');
        var event_title3 = event_title2[0].split('data-id');
        var event_title4 = event_title3[1].split('=');
        var event_title5 = event_title4[1].split('"');
        var final_image_id = event_title5[1];

        var event_tit = event.title;
        var event_tit1 = event_tit.split('<div>');
        var event_tit2 = event_tit1[1].split('src');
        var event_tit3 = event_tit2[1].split('=');
        var event_tit4 = event_tit3[1].split('"');
        var event_tit5 = event_tit4[1].split('/');
        var image_path = event_tit5[6];  
          
        //var loc = window.location;
        var baseUrl = Drupal.settings.basePath + 'calendar';
        if(now_time_strings >= event_date1) {
          jQuery.ajax({        
            //url: 'http://localhost/playatyourlibrary/docroot/calendar',
            url: baseUrl,
            type: 'post',
            dataType: 'json',
            data: {
                id: final_image_id,
                image: image_path,
                date: event.start,
                user_id: currentUser
            },
            success: function(res){
              window.location.reload(true);
              console.log("data:");
              console.log(res);
              //alert("data");
            },
            error: function(jqXHR, data, error){
                //console.log(jqXHR);
                //console.log(data);
                //console.log(error);
            }
         });
       }   
            
        
    },
    events: eventsList

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


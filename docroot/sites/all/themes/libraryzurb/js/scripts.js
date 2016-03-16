(function ($, Drupal) {

  // This fuction adds a class to phone number links on small screens. We use
  // this class to style phone number links as buttons on small screens.
  Drupal.behaviors.libraryzurbPhoneNumberLinksOnMobile = {
    attach: function(context, settings) {

      $(':checkbox').on('change',function(){
       var th = $(this), name = th.prop('class'); 
       if(th.is(':checked')){
           $(':checkbox[class="'  + name + '"]').not($(this)).prop('checked',false);   
        }
      });
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
  

  /* Jquery for script for raffle entry checkbox */

    jQuery( ".active_raffle" ).click(function() {
        var location = window.location;
        var baseUrl1 = location.protocol + "//" + location.host + '/raffle_pro';

        // var active_raffle = jQuery(this).attr('id');
        // var active_raffle_exp = active_raffle.split('_');
        // var active_raffle_id = parseInt(active_raffle_exp[2]);
        // var reward_id = jQuery(this).val();

      jQuery.ajax({
        
            //url: 'http://localhost/playatyourlibrary/docroot/raffle_pro',
            url: baseUrl1,
            // async: false,
            // type: 'post',
            // data: 'reward_id='+reward_id,
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
      var contant = jQuery(".main");
      var inner_content = contant.html();

      var WinPrint = window.open('', '', 'letf=0,top=0,width=400,height=400,toolbar=0,scrollbars=0,status=0');
        WinPrint.document.write(inner_content);
        WinPrint.focus();
        WinPrint.print();
        WinPrint.close();
    });
    

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


  jQuery('#calendar').fullCalendar({

    editable: true,
    droppable: true, // this allows things to be dropped onto the calendar !!!
        
    drop: function (date, allDay) {
     var currentDate = new Date(jQuery.now());
     var time_string = currentDate.toJSON().slice(0, 10);
     time_string = time_string.split('-');
     time_string = parseInt(time_string[0] + time_string[1] + time_string[2]);
     //console.log(time_string); return false;
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
        var expl_img1 = expl_img[1].split("//");
        var expl_img2 = expl_img1[1].split("?");
        var expl_img3 = expl_img2[0].split("/");
        //var image_name = expl_img3[9];
        var image_name = expl_img3[7];

        
        console.log(copiedEventObject.title);
        //console.log(copiedEventObject);

        // assign it the date that was reported
        copiedEventObject.start = date;
        var event_date = copiedEventObject.start;
         event_date = event_date.toJSON().slice(0, 10);
         event_date = event_date.split('-');
         event_date = parseInt(event_date[0] + event_date[1] + event_date[2]);

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

        var loc = window.location;
        var baseUrl = loc.protocol + "//" + loc.host + '/calendar';

        var currentUser = Drupal.settings.auto_role_allocation.currentUser;
        if(time_string > event_date) {
          jQuery.ajax({
        
            //url: 'http://localhost/playatyourlibrary/docroot/calendar',
            url: baseUrl,
            async: false,
            type: 'post',
            data: 'image='+image_name+'&date='+copiedEventObject.start+'&user_id='+currentUser,
            success: function(res){ //alert(res);
              if (res) {
                window.location.reload(true);
              } else {
                alert ('test');
              }
            },
            error: function(jqXHR, data, error){
                // console.log(jqXHR);
                // console.log(data);
                // console.log(error);
            }
        });
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
       var currentDateInternal = new Date(jQuery.now());
       var time_string1 = currentDateInternal.toJSON().slice(0, 10);
         time_string1 = time_string1.split('-');
         time_string1 = parseInt(time_string1[0] + time_string1[1] + time_string1[2]);
         

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
          
        var loc = window.location;
        var baseUrl = loc.protocol + "//" + loc.host + '/calendar';
        if(time_string1 > event_date1) {
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

    
    
        var location = window.location;
        var baseUrl1 = location.protocol + "//" + location.host + '/raffle_user_list';
        


        var raffleId = 0;
        jQuery( ".active_raffle" ).each(function() {
          if(jQuery("input[name='raffle']:checked").val()) {
             raffleId = jQuery(this).attr('raffle_id');

          }

        });


        
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
  
  var location = window.location;
  var baseUrl1 = location.protocol + "//" + location.host + '/raffle_winner';
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


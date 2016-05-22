(function ($, Drupal) {

  // This fuction adds a class to phone number links on small screens. We use
  // this class to style phone number links as buttons on small screens.
  Drupal.behaviors.libraryzurbPhoneNumberLinksOnMobile = {
    attach: function(context, settings) {

// user register page fields fixes on teen
    jQuery("#user-register-form .form-item-mail").insertAfter("#user-register-form #edit-profile-main-field-how-did-you-hear-about-thi");
    jQuery("#user-register-form #edit-profile-main-field-receive-notifications").insertAfter("#user-register-form .form-item-mail");
    jQuery("#user-register-form .form-item-avatar-select").insertAfter("#user-register-form #edit-profile-main-field-receive-notifications");
    jQuery("#user-register-form #checkboxes-div").insertAfter("#user-register-form .form-item-avatar-select");
    jQuery("#user-register-form .username").insertAfter("#user-register-form #checkboxes-div");


      $(':checkbox').on('change',function(){
       var th = $(this), name = th.prop('class'); 
       if(th.is(':checked')){
           $(':checkbox[class="'  + name + '"]').not($(this)).prop('checked',false);   
        }
      });
      //change position of review title after viewfilter in all review pages
      $('.reviews-subtitle').insertAfter('.view-filters');
      //for progress page table format of divs wrap every 6 divs in single div
         var divs = $("div.progress-main > div.grid");
        for(var i = 0; i < divs.length; i+=6) {
        divs.slice(i, i+6).wrapAll("<div class='new-row'></div>");
    }
    //Announcement block in landing page make image field as background image
     $('.block.announcement').each(function() {
  if ($(this).find('img').length) {
    var imgURL = $(this).find('img').attr('src');
    $(this).css('background-image', 'url(' + imgURL + ')');
  $('.block.announcement img').hide();
  }
   
  });
      //reward page give same counter list to two different views
       $('.page-rewards .view-program-rewards-raffle .views-row').insertAfter('.page-rewards .view-program-rewards .views-row:nth-last-child(1)');
      // select list option with thier link
      jQuery('.add_review_node').change(function(){
        var option = jQuery(this).find('option:selected').val();
        if(option != 0){
        window.location = option;
        }else{
          return false;
        }
      });
      jQuery('.reviews_list_view').change(function(){
        var option = jQuery(this).find('option:selected').val();
        if(option != 0){
        window.location = option;
        }else{
          return false;
        }
      });
      jQuery('.reviews_add').change(function(){
        var option = jQuery(this).find('option:selected').val();
        if(option != 0){
        window.location = option;
        }else{
          return false;
        }
      });
      jQuery('.activities_list_read').change(function(){
        var option = jQuery(this).find('option:selected').val();
        if(option != 0){
        window.location = option;
        }else{
          return false;
        }
      });
      jQuery('.activities_list_submit').change(function(){
        var option = jQuery(this).find('option:selected').val();
        if(option != 0){
        window.location = option;
        }else{
          return false;
        }
      });

      jQuery("#edit-field-activity-type select option").each(function() {
        var current_url = window.location.href;
        var current_value = current_url.substring(current_url.lastIndexOf('/') + 1);
        if(jQuery(this).val() == current_value){
          jQuery(this).attr("selected","selected");   
          var content_text = jQuery(this).text()
          jQuery('#edit-field-activity-type .chosen-single span').text(content_text);
        }
      });
  
      //for node page vedio list show textbox after selected radio button has value Other
      $('.page-node-add-video-game-review #edit-field-platform-other-option').hide();
       $('.page-node-add-video-game-review input[type="radio"]').click(function(){
         if($(this).attr("value")=="other") {
          $('.page-node-add-video-game-review #edit-field-platform-other-option').show();
         }
         else {
           $('.page-node-add-video-game-review #edit-field-platform-other-option').hide();
         }
       });
       //position of textbox after checked Other radio button in generic at vediogame, music, movie review form
         $('.page-node-add-music-review .field-name-field-genre-other-option-music').insertAfter('.page-node-add-music-review .form-item.form-type-checkbox.form-item-field-genre-music-und-genre-other-music:nth-last-child(1)');
         $('.page-node-add-video-game-review .field-name-field-platform-other-option').insertAfter('.page-node-add-video-game-review .form-item.form-type-radio.form-item-field-platform-und:nth-last-child(1)');
         $('.page-node-add-movie-review .field-name-field-genre-other-option').insertAfter('.page-node-add-movie-review .form-item.form-type-radio.form-item-field-genre-und:nth-last-child(1)');
       //reward page description
       var showChar = 30;
    var ellipsestext = "...";
    var moretext = "more";
    var lesstext = "less";
    $('.page-rewards .reward_description div:nth-last-child(1)').each(function() {
        var content = $(this).html();
 
        if(content.length > showChar) {
 
            var c = content.substr(0, showChar);
            var h = content.substr(showChar-1, content.length - showChar);
 
            var html = c + '<span class="moreellipses">' + ellipsestext+ '&nbsp;</span><span class="morecontent"><span style="display:none;">' + h + '</span>&nbsp;&nbsp;<a href="" class="morelink">' + moretext + '</a></span>';
 
            $(this).html(html);
        }
 
    });
 
    $(".morelink").click(function(){
        if($(this).hasClass("less")) {
            $(this).removeClass("less");
            $(this).html(moretext);
        } else {
            $(this).addClass("less");
            $(this).html(lesstext);
        }
        $(this).parent().prev().toggle();
        $(this).prev().toggle();
        return false;
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
   

  /* Jquery for script for raffle entry checkbox */

    jQuery( ".active_raffle" ).click(function() {
        var location = window.location;
        var baseUrl1 = location.protocol + "//" + location.host + '/raffle_pro';

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
      var contant = jQuery(".main");
      var inner_content = contant.html();

      var WinPrint = window.open('', '', 'letf=0,top=0,width=400,height=400,toolbar=0,scrollbars=0,status=0');
        WinPrint.document.write(inner_content);
        WinPrint.focus();
        WinPrint.print();
        WinPrint.close();
    });

    var proStart = Drupal.settings.private_msg_custom.proStart;
    var start_string = proStart.split('-');
    var pro_start_date = parseInt(start_string[0] + start_string[1] + start_string[2]);

    var proEnd = Drupal.settings.private_msg_custom.proEnd;
    var end_string = proEnd.split('-');
    var pro_end_date = parseInt(end_string[0] + end_string[1] + end_string[2]);  

    var now = new Date(jQuery.now());
    var time_strings = now.toJSON().slice(0, 10);
    time_strings = time_strings.split('-');
    var now_time_strings = parseInt(time_strings[0] + time_strings[1] + time_strings[2]);


    
    if((now_time_strings >= pro_start_date) && now_time_strings <= pro_end_date) {
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

    }

    

  

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


(function ($, Drupal) {

  // This fuction adds a class to phone number links on small screens. We use
  // this class to style phone number links as buttons on small screens.
  Drupal.behaviors.libraryzurbPhoneNumberLinksOnMobile = {
    attach: function(context, settings) {
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

  //console.log("running");
  jQuery('.view-progress .view-content .views-field-field-sticker-calendar-image .field-content').each(function () {

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
    drop: function (date, allDay) { // this function is called when something is dropped

        // retrieve the dropped element's stored Event Object
        var originalEventObject = jQuery(this).data(('eventObject'));

        // we need to copy it, so that multiple events don't have a reference to the same object
        var copiedEventObject = jQuery.extend({}, originalEventObject);
        copiedEventObject.description = copiedEventObject.title;
        var calender_img = copiedEventObject.title; 
        var expl_img = calender_img.split("src");
        var expl_img1 = expl_img[1].split("//");
        var expl_img2 = expl_img1[1].split("?");
        var expl_img3 = expl_img2[0].split("/");
        var image_name = expl_img3[8];  
        
        console.log(copiedEventObject.title);
        //console.log(copiedEventObject);

        // assign it the date that was reported
        copiedEventObject.start = date;
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

        var currentUser = Drupal.settings.auto_role_allocation.currentUser;
       

       

        jQuery.ajax({
        
            url: 'http://dev-chillco.gailabs.com/test',
            type: 'post',
            dataType: 'json',
            data: {
                image: image_name,
                date: copiedEventObject.start,
                user_id: currentUser
            },
            success: function(data){
              console.log("data:");
              console.log(data);
              alert("data");
            },
            error: function(jqXHR, data, error){
                console.log(jqXHR);
                console.log(data);
                console.log(error);
            }
        });

    },

    header: {
        left: 'prev,next today',
        center: 'title',
        right: 'month,agendaWeek,agendaDay'
    },
    eventRender: function (event, element, view) {
        element.bind('click', function () {
            var day = (jQuery.fullCalendar.formatDate(event.start, 'dd'));
            var month = (jQuery.fullCalendar.formatDate(event.start, 'MM'));
            var year = (jQuery.fullCalendar.formatDate(event.start, 'yyyy'));
            alert(year + '-' + month + '-' + day);
        });
    },
    editable: true,
    eventRender: function(event, element) {
        element.description = element[0].textContent;
        // $('#mycalendar').fullCalendar('renderEvent', event);
        console.log('Element:');
        console.log(element);
        return jQuery.parseHTML(element.description);
    },
    events: eventsList

});

});


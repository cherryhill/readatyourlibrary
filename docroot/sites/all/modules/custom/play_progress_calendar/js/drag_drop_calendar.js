$(document).ready(function() {


    /* initialize the external events
    -----------------------------------------------------------------*/

    $('#external-events .fc-event').each(function() {

      // // // store data so the calendar knows to render an event upon drop
       var eventObject = {
          title: jQuery.trim(jQuery(this).html()) // use the element's text as the event title
        };

      //var draggedElement = $(this).data('eventObject', eventObject, { stick: true});
      $(this).data('eventObject', eventObject, { stick: true});
      
      ////console.log(originalEventObject);
      // $(this).data('event', {
      //   title: $.trim($(this).text()), // use the element's text as the event title
      //   stick: true // maintain when user navigates (see docs on the renderEvent method)
      // });

      // make the event draggable using jQuery UI
      $(this).draggable({
        zIndex: 999,
        revert: true,      // will cause the event to go back to its
        revertDuration: 0  //  original position after the drag
      });

    });


    /* initialize the calendar
    -----------------------------------------------------------------*/


    $('#calendar').fullCalendar({
      header: {
        left: '',//'next today',
        center: 'prev,title,next',
        right: ''//'month,agendaWeek,agendaDay'
      },
      editable: true,
      droppable: true, // this allows things to be dropped onto the calendar
      drop: function(date, allDay) {
        $('#message').remove();
        var eventObject = {
          title: jQuery.trim(jQuery(this).html()) // use the element's text as the event title
        };
        var tid = ($(this).attr('id'));
        var act_ids =($('#external-events').attr('value'));
        //console.log('act'+ $('#external-events').attr('value'));
        //var droppedEventObject = $(this).data('eventObject', eventObject,  {stick: true});
        var currentUser = Drupal.settings.play_progress_calendar.currentUser;
        ////console.log(droppedEventObject);
        var event_date = date;
        var calendar = $('#calendar').fullCalendar('getCalendar');
        var view = calendar.view;
        var start = view.start._d;
        var end = view.end._d;
       
        event_date = event_date.toJSON().slice(0, 10);
        event_date = event_date.split('-');
        event_date = (event_date[0] +'-'+ event_date[1] + '-' + event_date[2])
      
        var baseUrl = Drupal.settings.basePath + 'calendar';
        //console.log (baseUrl);
        //console.log('tid='+tid+'&drop_date='+moment(date).format('YYYY-MMM-DD')+'&start='+start+'&end='+end+'&user_id='+currentUser);
        jQuery.ajax({
        
            //url: 'http://localhost/playatyourlibrary/docroot/calendar',
            url: baseUrl,
            async: true,
            type: 'post',
            data: 'act_ids='+act_ids+'&tid='+tid+'&drop_date='+moment(date).format('YYYY-MMM-DD')+'&start_date='+start+'&end_date='+end+'&user_id='+currentUser,

            
            success: function(res){
              //console.log(res); 
              //$('#messages').innerHTML = res;
              // $('#message').remove();
              $('#sticker-wrap').after('<div id = "message"><div class="section clearfix">' + res + '</div></div>');
              $('#message .section').css('width' , '960px');
              $('#message .section').css('margin-left' , 'auto');
              $('#message .section').css('margin-right' , 'auto');               
              $('#calendar').fullCalendar('refetchEvents');
            },
            error: function(jqXHR, data, error){
                alert("Apologies. There is some error in the system. " + error );
                //console.log(jqXHR);
                // //console.log(data);
                //console.log(error);
            }
        });
      },

      //Show loading while updating calendar
      loading: function(bool) {
        if (bool) {
          $('#loading').show();
          // $('#external-events').hide();
        }
        else { 
          //$('.calendar-wrapper').show();
          $('#loading').hide();
          // $('#external-events').show();
        }
      },

      eventDrop: function( event, dayDelta, minuteDelta, allDay, revertFunc, jsEvent, ui, view ) {
         $('.reward-won').removeClass('reward-won');
         $('#message').remove();
        var eventObject = {
          title: jQuery.trim(jQuery(this).html()) // use the element's text as the event title
        };
        var tid = ($(this).attr('id'));
        var act_ids =($('#external-events').attr('value'));
        //console.log('act'+ $('#external-events').attr('value'));
        //var droppedEventObject = $(this).data('eventObject', eventObject,  {stick: true});
        var currentUser = Drupal.settings.play_progress_calendar.currentUser;
        ////console.log(droppedEventObject);
        var event_date = event.start;
        var calendar = $('#calendar').fullCalendar('getCalendar');
        var view = calendar.view;
        var start = view.start._d;
        var end = view.end._d;
       
        event_date = event_date.toJSON().slice(0, 10);
        event_date = event_date.split('-');
        event_date = (event_date[0] +'-'+ event_date[1] + '-' + event_date[2])
      
        var baseUrl = Drupal.settings.basePath + 'calendar';
        //console.log (baseUrl);
        //console.log('entry_id='+event.id+'&drop_date='+moment(event.start).format('YYYY-MMM-DD')+'&start='+start+'&end='+end+'&user_id='+currentUser);
        jQuery.ajax({
        
            //url: 'http://localhost/playatyourlibrary/docroot/calendar',
            url: baseUrl,
            async: true,
            type: 'post',
            data: 'act_ids='+act_ids+'&entry_id='+event.id+'&drop_date='+moment(event_date).format('YYYY-MMM-DD')+'&start_date='+start+'&end_date='+end+'&user_id='+currentUser,

            
            success: function(html){
              // $('#messages').load("/ #messages"); 
              console.log(html);
              // $('#message').remove();
              $('#sticker-wrap').after('<div id = "message"><div class="section clearfix">' + html + '</div></div>');
              $('#message .section').css('width' , '960px');
              $('#message .section').css('margin-left' , 'auto');
              $('#message .section').css('margin-right' , 'auto');
              // var msg = '' 
              // $('#calendar').getElementsByClassName('reward-won').removeClass('reward-won');           
              $('#calendar').fullCalendar('refetchEvents');
            },
            error: function(jqXHR, data, error){
                alert("Apologies. There is some error in the system" + error );
                //console.log(jqXHR);
                // //console.log(data);
                //console.log(error);
            }
        });    
            
        
      },
      //Disable all future dates
      dayRender: function(date, cell){
        if (date > new Date){
            $(cell).addClass('disabled');
        }
      },

      events: {
        url: Drupal.settings.basePath + 'calendar2'+'?'+'act_ids='+$('#external-events').attr('value'),
        //async: true,
        //type: 'post',
        //data: 'act_ids=3,81',//+ $('#external-events').attr('value'),
        
        success: function(res){
        //console.log (res) ;  

        },
        error: function(res) {
          ////console.log ('test' + (res))          
          $('#script-warning').show();
        }
      },
      eventRender: function(event, element, view) {
        //console.log(event.imageurl);
             //alert(event.imageurl + 'here');
        //clean up all added classes first
        // $(element).find('[class=reward-won]').removeClass('reward-won');
        if(event.imageurl){
            if(event.allDay){
                $(element).find('[class=fc-content]').append('<img src="'+event.imageurl+'" /><br/>');
            }else{
               $(element).find('[class=fc-content]').append('<img src="'+event.imageurl+'" /><br/>');
            }
        }
        if(event.read_days){
            if(event.allDay){
                $(element).find('[class=fc-content]').append('<div>'+event.read_days+'</div>');
            }else{
               $(element).find('[class=fc-content]').append('<div>'+event.read_days+'</div>');
            }
        }
        if(event.class == 'reward-won'){
          //console.log(moment(event.start).format('YYYY-MM-DD'));
          $(element).find('[class=fc-content]').addClass('reward-content')
          $("[data-date='"+moment(event.start).format('YYYY-MM-DD')+"']").addClass('reward-won');
           // getAllElementsWithAttribute('data-date', event.start, 'reward-won');
        }
      },
    });

  });

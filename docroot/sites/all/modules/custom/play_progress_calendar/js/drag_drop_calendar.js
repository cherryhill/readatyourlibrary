(function($) {
  Drupal.behaviors.play_progress_teen = {
    attach: function (context, settings) {
    //message button change its background color by adding class new(done for theming)
        $('.msg:has(.new)').addClass('new');
    //
    $('.printBtn').on('click', function (){
      $(".progress-page-wrap").printThis({debug: true});
    });

      /* initialize the external events
      -----------------------------------------------------------------*/
      $('#external-events .fc-event').each(function() {
        // store data so the calendar knows to render an event upon drop
        var eventObject = {
          title: jQuery.trim(jQuery(this).html()) // use the element's text as the event title
        };

        //var draggedElement = $(this).data('eventObject', eventObject, { stick: true});
        $(this).data('eventObject', eventObject, { stick: true});

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
        //Render header
        header: {
          left: '',//'next today',
          center: 'prev,title,next',
          right: ''//'month,agendaWeek,agendaDay'
        },
        editable: true,
        droppable: true, // this allows things to be dropped onto the calendar
        drop: function(date, allDay) {
          //Create event object for dropped sticker
          var eventObject = {
            title: jQuery.trim(jQuery(this).html()) // use the element's text as the event title
          };

          //Get sticker id of dropped sticker
          var tid = ($(this).attr('id'));
          var act_ids =($('#external-events').attr('value'));
          //Get current logged in user
          var currentUser = Drupal.settings.play_progress_calendar.currentUser;

          //Get displayed date range - start and end dates
          var calendar = $('#calendar').fullCalendar('getCalendar');
          var view = calendar.view;
          var start = view.start._d;
          var end = view.end._d;

          var baseUrl = Drupal.settings.basePath + 'calendar';
          //post drop details to calendar function
          jQuery.ajax({
            url: baseUrl,
            async: true,
            type: 'post',
            data: 'act_ids='+act_ids+'&tid='+tid+'&drop_date='+moment(date).format('YYYY-MMM-DD')+'&start_date='+start+'&end_date='+end+'&user_id='+currentUser,
            //on Successs render drupal set messages
            success: function(res){
              $('#calendar').fullCalendar('refetchEvents');
              console.log(res);
              jq_json_obj = $.parseJSON(res); //Convert the JSON object to jQuery-compatible
              if(typeof jq_json_obj == 'object'){ //Test if variable is a [JSON] object
                jq_obj = eval (jq_json_obj);
                //Convert back to an array
                jq_array = [];
                for(elem in jq_obj){
                  jq_array.push(jq_obj[elem]);
                }
                console.log(jq_array);
              }else{
                console.log("Error occurred!");
              }
              $('#message').remove();
              $('#next-reward').remove();
              $('.reward-won').removeClass('reward-won');
              $('#wrap').after('<div id = "message"><div class="section clearfix">' + jq_array[1] + '</div></div>');
              $('.reading-progress').append('<div id = "next-reward"><h3>' + jq_array[0] + '</h3></div>');
              $('#message .section').css('width' , '960px');
              $('#message .section').css('margin-left' , 'auto');
              $('#message .section').css('margin-right' , 'auto');
            },
            error: function(jqXHR, data, error){
              alert("Apologies. There is some error in the system. " + error );
            }
          });
        },

        //Show loading while updating calendar
        loading: function(bool) {
          if (bool) {
            $('#loading').show();
            $('#external-events').hide();
          }
          else {
            $('#loading').hide();
            $('#external-events').show();
          }
        },

        //For internal drag drop of sticker
        eventDrop: function( event, dayDelta, minuteDelta, allDay, revertFunc, jsEvent, ui, view ) {
          var eventObject = {
            title: jQuery.trim(jQuery(this).html()) // use the element's text as the event title
          };
          var tid = ($(this).attr('id'));
          var act_ids =($('#external-events').attr('value'));
          var currentUser = Drupal.settings.play_progress_calendar.currentUser;

          //Get dates for start end and drag drop
          var event_date = event.start;
          var calendar = $('#calendar').fullCalendar('getCalendar');
          var view = calendar.view;
          var start = view.start._d;
          var end = view.end._d;
          //get URL of page for callback
          var baseUrl = Drupal.settings.basePath + 'calendar';
          //Ajax post for update activity dates
          jQuery.ajax({
            url: baseUrl,
            async: true,
            type: 'post',
            data: 'act_ids='+act_ids+'&entry_id='+event.id+'&drop_date='+moment(event_date).format('YYYY-MMM-DD')+'&start_date='+start+'&end_date='+end+'&user_id='+currentUser,

            //On success show drupal messages
            success: function(html){
              $('#calendar').fullCalendar('refetchEvents');
              console.log(html);
              jq_json_obj = $.parseJSON(html); //Convert the JSON object to jQuery-compatible
              if(typeof jq_json_obj == 'object'){ //Test if variable is a [JSON] object
                jq_obj = eval (jq_json_obj);
                //Convert back to an array
                jq_array = [];
                for(elem in jq_obj){
                  jq_array.push(jq_obj[elem]);
                }
                console.log(jq_array);
              }else{
                console.log("Error occurred!");
              }
              $('#message').remove();
              $('#next-reward').remove();
              $('.reward-won').removeClass('reward-won');
              $('#wrap').after('<div id = "message"><div class="section clearfix">' + jq_array[1] + '</div></div>');
              $('.reading-progress').append('<div id = "next-reward"><h3>' + jq_array[0] + '</h3></div>');
              $('#message .section').css('width' , '960px');
              $('#message .section').css('margin-left' , 'auto');
              $('#message .section').css('margin-right' , 'auto');
            },
            //On error show error alert
            error: function(jqXHR, data, error){
              alert("Apologies. There is some error in the system" + error );
            }
          });
        },

        //Disable all future dates
        dayRender: function(date, cell){
          if (date > new Date){
            $(cell).addClass('disabled');
          }
        },

        //Render events from json through ajax call
        events: {
          url: Drupal.settings.basePath + 'calendar2'+'?'+'act_ids='+$('#external-events').attr('value'),
          success: function(res){
            // console.log (res) ;
          },
          //Alert error message
          error: function(res) {
            $('#script-warning').show();
          }
        },

        //render evevnt images and add classes wherever required
        eventRender: function(event, element, view) {
          //Append image tag after fc-content
          if(event.imageurl_id){
            var imageurl = $('#sticker_'+event.imageurl_id).attr('src');
            if(event.allDay){
              // var imageurl = $('#external-events').('#'+event.imageurl_id).getAttribute('src');
              $(element).find('[class=fc-content]').append('<img src="'+imageurl+'" /><br/>');
            }else{
              $(element).find('[class=fc-content]').append('<img src="'+imageurl+'" /><br/>');
            }
          }
          //Append days read after image
          if(event.read_days){
            if(event.allDay){
              $(element).find('[class=fc-content]').append('<div>'+event.read_days+'</div>');
            }else{
              $(element).find('[class=fc-content]').append('<div>'+event.read_days+'</div>');
            }
          }
          if(event.class == 'day-read'){
            $(element).find('[class=fc-content]').addClass('read-content')
            $("[data-date='"+moment(event.start).format('YYYY-MM-DD')+"']").addClass('day-read');
          }
          //Add reward won class if reward won class is present
          if(event.class == 'reward-won'){
            $(element).find('[class=fc-content]').addClass('reward-content')
            $("[data-date='"+moment(event.start).format('YYYY-MM-DD')+"']").addClass('reward-won');
          }
        },
      });
    }
  }
})(jQuery);

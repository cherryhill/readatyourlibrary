/**
 * function callback for progress page report
 */
(function($) {
  
Drupal.behaviors.play_progress_teen = {
  attach: function (context, settings) {

  var tes = $('#edit-activity-progress-select').val();
  if (tes == null) {
    $('#edit-activity-progress-select').append('<option value = 0>Please select activity</option>');
  }

  $('.print_pg').on('click', function() {
    printDiv('.progress-page');
  });

  function printDiv(elem) {
    Popup($(elem).html());
  }
  
  function Popup(data){
    var mywindow = window.open('', 'new div', 'height=400,width=600');
    mywindow.document.write('<html><head><title>my div</title>');
    mywindow.document.write('</head><body >');
    mywindow.document.write(data);
    mywindow.document.write('</body></html>');

    mywindow.print();
    mywindow.close();

    return true;
  }


  $('#pg-report').click(function() {
    var errors = 0;
    var tid = $("#edit-activity-progress-select option:selected").val();
    if(tid === '0'){
      $('#errorwarn-activity').text("Please enter activity");
      return false;
    }else{
      $('#errorwarn-activity').text("");
    }
    $("#edit-date-datepicker-popup-0").map(function(){
      if( !$(this).val() ) {
        $('#edit-date-datepicker-popup-0').addClass('warning');
        errors++;
      }else if ($(this).val()) {
        $('#edit-date-datepicker-popup-0').removeClass('warning');
      }   
    });
    if(errors > 0){
      $('#errorwarn').text("Please enter date");
      return false;
    }

    $(this).attr('disabled','disabled'); 
    var tid = $("#edit-activity-progress-select option:selected").val();
    var date = $("#edit-date-datepicker-popup-0").val();
    // var count = $('.progress-grid td').length;
    var count_grid = $(".progress-grid td[active='yes']").length;
    console.log(count_grid);
    if(count_grid >= 1){
      // var insert = count + 1;
      $.ajax({
        url: Drupal.settings.basePath + 'complete-activity-progress',
        type: 'post',
        async: true,
        data: "id="+tid+"&date="+date,
        success: function (data) {
          // var selector = '.view-dom-id-'+ settings.view_dom_id;
          // console.log(selector);
          // $(selector).triggerHandler('RefreshView');
          console.log(data) ;
          var json_res = JSON.parse(data) ;
          // json_res = $.parseJSON(data);
          console.log (json_res);
          if (json_res.create_status) {
            var views = settings.views.ajaxViews;
            var dom_id = views[Object.keys(views)[0]]['view_dom_id'];
            var selector = '.view-dom-id-' + dom_id;
            $(selector).triggerHandler('RefreshView');

            var x =$(".progress-grid td[active='yes']");//document.getElementById("active");//.innerHTML=data;// = data;
            // console.log(x);
            
            x[0].innerHTML =json_res.cell_data;
            $(x[0]).removeAttr("active");
            $(x[0]).addClass(json_res.cell_selector);
            $('#pg-report').removeAttr("disabled");
            $('#message').remove();
            $('#next-reward').remove();
            $('.progress-wrap').after('<div id = "message"><div class="section clearfix">' + json_res.drupal_message + '</div></div>');
            $('#message .section').css('width' , '960px');
            $('#message .section').css('margin-left' , 'auto');
            $('#message .section').css('margin-right' , 'auto');
            $(".activity-status").text(json_res.act_completed);
            $(".activity-remaining").text(json_res.act_remaining);
            $(".points").text(json_res.raffle_count);
          }
          else{
            $('#pg-report').removeAttr("disabled");
            $('#message').remove();
            $('.progress-wrap').after('<div id = "message"><div class="section clearfix">' + json_res.drupal_message + '</div></div>');
            $('#message .section').css('width' , '960px');
            $('#message .section').css('margin-left' , 'auto');
            $('#message .section').css('margin-right' , 'auto');
          }
        }
      });
      // $("#cells"+insert).addClass("inserted");
    }else{
      alert('Filled');
    }	
  });
  }
};
})(jQuery);

/**
 * function callback for progress page report
 */
(function($) {
Drupal.behaviors.play_progress_teen = {
  attach: function (context, settings) {

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
    var count = $('.inserted').length;
    var count_grid = $('.grid').length;
    if(count_grid != count){
      var insert = count + 1;
      $.ajax({
        url: Drupal.settings.basePath + 'complete-activity-progress',
        type: 'post',
        async: false,
        data: "id="+tid+"&date="+date,
        success: function (data) {
          if (data) {
            window.location.reload(true);
          }
        }
      });
      $("#cells"+insert).addClass("inserted");
    }else{
      alert('Filled');
    }	
  });
  }
};
})(jQuery);

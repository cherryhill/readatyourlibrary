/**
 * function callback for progress page report
 */
(function($) {
Drupal.behaviors.bfc_api_custom = {
  attach: function (context, settings) {

	  $('#pg-report').click(function() {
	    $(this).attr('disabled','disabled'); 
		  var aid = $("#edit-activity-progress-select option:selected").val();
		  var date = $("#edit-date-datepicker-popup-0").val();
		  var count = $('.inserted').length;
		  var count_grid = $('.grid').length;
		  if(count_grid != count){
		  var insert = count + 1;
		  $.ajax({
		    url: Drupal.settings.basePath + 'complete-activity-progress',
		    type: 'post',
		    async: false,
		    data: "id="+aid+"&date="+date,
			  success: function (data) {
				  if (data) {
				    // $("#cells"+insert).html(data.content);
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

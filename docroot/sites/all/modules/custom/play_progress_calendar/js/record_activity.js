(function($) {
  Drupal.behaviors.play_progress_teen = {
    attach: function (context, settings) {
      $("#patron-activity-record-form #edit-username").change(function() {
        $('#views-exposed-form-raffle-winners-page #edit-uid').val( this.value );
      });

      //Update reward pickup
      $('.update-rew').on('click', function (){
      	console.log("daas");
      	var rew_id = this.id;
      	var pickup_date = $('#staff-date-'+ rew_id + '-datepicker-popup-0').val();
      	var staff_notes = $('#staff-notes-'+ rew_id).val();
      	var pick_up_status = $('#staff-status-' + rew_id).val();
      	
      	if(pickup_date.length == 0 || staff_notes.length == 0 || $('#staff-status-' + rew_id).checked ){
	      	alert("Please enter all fields");
      	}
      	else{
      		var baseUrl = Drupal.settings.basePath + 'update-reward-pickup';
	      	jQuery.ajax({
	            url: baseUrl,
	            async: true,
	            type: 'post',
	            data: 'reward-id=' + rew_id + '&pickup-date=' + pickup_date + '&staff-notes=' +staff_notes+ '&pickup-status=' +pick_up_status,
	            //on Successs render drupal set messages
	            success: function(res){
	              console.log(res);
	              if(res == 'success'){
	              	alert("Reward Pickup date updated");
	              	window.location.reload();
	              }
	            },
	            error: function(jqXHR, data, error){
	              alert("Apologies. There is some error in the system. Please refresh page. If problem persists report to system administrator" + error );
	            }
	          });
      	}
    });
  }
}
}) (jQuery);

(function($) {
  Drupal.behaviors.play_progress_bingo_cards = {
   attach: function(context, settings) {
    var baseUrl = Drupal.settings.basePath + 'progress-activity';
    // var activity = $('#edit-activity .chosen-single span').text();
    // console.log (activity);
   $('.printBtn ').click(function(){
      console.log(baseUrl);
      $.ajax({
        url: 'http://localhost/kids17/playatyourlibrary/docroot/progress-activity' ,
        async: true,
        type: 'post',
        data: 'act_ids=sdfsdfsdf',//'act_ids='+act_ids+'&tid='+tid+'&drop_date='+moment(date).format('YYYY-MMM-DD')+'&start_date='+start+'&end_date='+end+'&user_id='+currentUser,
        //on Successs render drupal set messages
        success: function(res){
          console.log(res);
          // jq_json_obj = $.parseJSON(res); //Convert the JSON object to jQuery-compatible
          // if(typeof jq_json_obj == 'object'){ //Test if variable is a [JSON] object
          //   jq_obj = eval (jq_json_obj);
          //   //Convert back to an array
          //   jq_array = [];
          //   for(elem in jq_obj){
          //     jq_array.push(jq_obj[elem]);
          //   }
          //   console.log(jq_array);
          // }else{
          //   console.log("Error occurred!");
          // }
        },
        error: function(jqXHR, data, error){
          alert("Apologies. There is some error in the system. " + data );
        },
    });
   }); 
  },
}
}) (jQuery);


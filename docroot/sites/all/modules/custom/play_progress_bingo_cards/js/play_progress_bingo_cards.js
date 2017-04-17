
(function($) {
  Drupal.behaviors.play_progress_bingo_cards = {
   attach: function(context, settings) {
    var baseUrl = Drupal.settings.basePath + 'progress-activity';
    // var activity = $('#edit-activity .chosen-single span').text();
    // console.log (activity);


  $('.printBtn').on('click', function (){
      // var baseUrl = Drupal.settings.basePath;
      // console.log("ddgfs");
      // jQuery('.bingo-progress-page').printThis({
      //   debug: false,               //* show the iframe for debugging
      //   importCSS: true,            //* import page CSS
      //   importStyle: false,         //* import style tags
      //   printContainer: true,       //* grab outer container as well as the contents of the selector
      //   loadCSS: [ baseUrl + "sites/all/modules/custom/play_progress_bingo_cards/css/print.css"],// baseUrl + "sites/all/modules/custom/play_progress_bingo_cards/css/play_progress_bingo_cards.css"],  //* path to additional css file - use an array [] for multiple
      //   pageTitle: "",              //* add title to print page
      //   removeInline: false,        //* remove all inline styles from print elements
      //   printDelay: 333,            //* variable print delay; depending on complexity a higher value may be necessary
      //   header: null,               //* prefix to html
      //   base: false,                 //* preserve the BASE tag, or accept a string for the URL
      //   formValues: true,            //* preserve input/form values
      // });
      window.print();
    });
  }
}
}) (jQuery);


  // $('.printBtn ').click(function(){
   //    console.log(baseUrl);
   //    $.ajax({
   //      url: 'http://localhost/kids17/playatyourlibrary/docroot/progress-activity' ,
   //      async: true,
   //      type: 'post',
   //      data: 'act_ids=sdfsdfsdf',//'act_ids='+act_ids+'&tid='+tid+'&drop_date='+moment(date).format('YYYY-MMM-DD')+'&start_date='+start+'&end_date='+end+'&user_id='+currentUser,
   //      //on Successs render drupal set messages
   //      success: function(res){
   //        console.log(res);
   //        // jq_json_obj = $.parseJSON(res); //Convert the JSON object to jQuery-compatible
   //        // if(typeof jq_json_obj == 'object'){ //Test if variable is a [JSON] object
   //        //   jq_obj = eval (jq_json_obj);
   //        //   //Convert back to an array
   //        //   jq_array = [];
   //        //   for(elem in jq_obj){
   //        //     jq_array.push(jq_obj[elem]);
   //        //   }
   //        //   console.log(jq_array);
   //        // }else{
   //        //   console.log("Error occurred!");
   //        // }
   //      },
   //      error: function(jqXHR, data, error){
   //        alert("Apologies. There is some error in the system. " + data );
   //      },
   //  });
  //  }); 
  // },
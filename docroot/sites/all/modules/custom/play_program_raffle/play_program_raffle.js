
(function($) {

  Drupal.behaviors.play_program_raffle = {
    attach: function (context, settings) {
    // var outputTable =

    // $("#print_raffle").click(function(){
    //   window.print();

    var raffleReward = $('#edit-active-raffle').val();
    var raffleName = $('#edit-name-raffle').val();
    var winnerNumbers = $('#edit-winners-selected').val();

    if (raffleReward == 0 || raffleName == "" || winnerNumbers == "") {
      $('#raff_winners').prop('disabled', true);
    } else {
      $('#raff_winners').prop('disabled', false);
    }

    $("#edit-active-raffle").change(function(){
      var raffleReward = $('#edit-active-raffle').val();
      var raffleName = $('#edit-name-raffle').val();
      var winnerNumbers = $('#edit-winners-selected').val();
      if (raffleReward == 0 || raffleName == "" || winnerNumbers == "") {
        $('#raff_winners').prop('disabled', true);
      } else {
        $('#raff_winners').prop('disabled', false);
      }      
    });

    $("#edit-name-raffle").keyup(function(){
      var raffleReward = $('#edit-active-raffle').val();
      var raffleName = $('#edit-name-raffle').val();
      var winnerNumbers = $('#edit-winners-selected').val();
      if (raffleReward == 0 || raffleName == "" || winnerNumbers == "") {
        $('#raff_winners').prop('disabled', true);
      } else {
        $('#raff_winners').prop('disabled', false);
      }      
    });

    $("#edit-winners-selected").keyup(function(){
      var raffleReward = $('#edit-active-raffle').val();
      var raffleName = $('#edit-name-raffle').val();
      var winnerNumbers = $('#edit-winners-selected').val();
      if (raffleReward == 0 || raffleName == "" || winnerNumbers == "") {
        $('#raff_winners').prop('disabled', true);
      } else {
        $('#raff_winners').prop('disabled', false);
      }      
    });

      $('#raff_winners').click(function() {
        confirm_rf_winners();
      })

    

      function rf_winners_list() {
        var raffle_id = $("#edit-active-raffle option:selected").val();
        var rf_drawing_name = $('#edit-name-raffle').val();
        var rf_library = $('#edit-library-branch').val();
        var rf_sch = $('#edit-school').val();
        var rf_grade = $('#edit-grade').val();
        var rf_dob_sdate = $('#edit-dob-from').val();
        var rf_dob_edate = $('#edit-dob-to').val();
        var rf_all = $('#edit-pervious-all-wnrs').val();
        var rf_num_winers = $('#edit-winners-selected').val();

        if(document.getElementById('edit-pervious-this-wnrs').checked) {
          var rf_this = 1;
        } else {
          var rf_this = 0;
        }

        if(document.getElementById('edit-pervious-all-wnrs').checked) {
          var rf_all = 1;
        } else {
          var rf_all = 0;
        }

        $.ajax({
          url: Drupal.settings.basePath + 'raffle_user_list',
          type: 'post',
          async: false,
          data: "raffle_id="+raffle_id+"&rf_drawing_name="+rf_drawing_name+"&no_needed="+rf_num_winers+"&rf_sch="+rf_sch+"&rf_library="+rf_library+"&rf_grade="+rf_grade+"&rf_this="+rf_this+"&rf_all="+rf_all+"&rf_dob_sdate="+rf_dob_sdate+"&rf_dob_edate="+rf_dob_edate,
          success: function (data) {
            if(raffle_id){
              $('#reward_tbl').html(data);
              $('#print_raffle').on('click', function() {
                printDiv('rf-tbl');
              });
            }
          }
        });
      }

      function confirm_rf_winners() {
        bootbox.confirm({
          message: "<div class = 'alrt'>Alert<div><br/>Raffle once drawn cannot be reversed. Please click Yes to proceed or Cancel to go back to the Draw Raffle Winners screen",
          buttons: {
            confirm: {
              label: 'Proceed',
              className: 'btn-success'
            },
            cancel: {
              label: 'Cancel',
              className: 'btn-danger'
            }
          },
          callback: function (result) {
            if(result){
              $('#raff_winners').hide();
              return rf_winners_list();
            }
          }
        });
      }
      function printDiv(divName) {

        var printContents = document.getElementById(divName).innerHTML;
        var originalContents = document.body.innerHTML;

        document.body.innerHTML = printContents;
        window.print();
        document.body.innerHTML = originalContents;
      }

    }
  }
})(jQuery);







(function($) {

  Drupal.behaviors.play_program_raffle = {
    attach: function (context, settings) {
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
          data: "raffle_id="+raffle_id+"&rf_drawing_name="+rf_drawing_name+"&no_needed="+rf_num_winers+"&rf_sch="+rf_sch+"&rf_library="+rf_library+"&rf_grade="+rf_grade+"&rf_this="+rf_this+"&rf_all="+rf_all,
          success: function (data) {
            if(raffle_id){
              $('#reward_tbl').html(data);
            }
          }
        });
      }

      function confirm_rf_winners() {
          bootbox.confirm({
            message: "Raffle once drawn cannot be reversed. Please click Yes to proceed or Cancel to go back to the Draw Raffle Winners screen",
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
              if (result) return rf_winners_list() ;
            }
          });

          
        } 
    }
  }
})(jQuery);





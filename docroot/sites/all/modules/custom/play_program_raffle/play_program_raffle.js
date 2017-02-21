
(function($) {

  Drupal.behaviors.play_program_raffle = {
    attach: function (context, settings) {
      // js for changing add reward or raffle ticket title text.
      jQuery('.page-admin-structure-entity-type-reward-reward-add #eck-entity-form-add-reward-reward .form-item-title label').text('Reward title / Name of raffle').append('<span class="form-required" title="This field is required.">*</span>');
    jQuery('.page-admin-structure-entity-type-reward-reward-edit #eck-entity-form-edit-reward-reward .form-item-title label').text('Reward title / Name of raffle').append('<span class="form-required" title="This field is required.">*</span>');
      $("#user-register-form .form-item-mail").insertAfter("#user-register-form #edit-profile-main-field-how-did-you-hear-about-thi");
      $("#user-register-form #edit-profile-main-field-receive-notifications").insertAfter("#user-register-form .form-item-mail");
      $("#user-register-form .form-item-avatar-select").insertAfter("#user-register-form #edit-profile-main-field-receive-notifications");
      $("#user-register-form #checkboxes-div").insertAfter("#user-register-form .form-item-avatar-select");
      $("#user-register-form .username-curr").insertAfter("#user-register-form #checkboxes-div");
      $("#user-register-form #edit-profile-main-field-receive-notifications").hide();

      //validate email field  
      $('#edit-mail').on('keyup', function(){
        var valid = /^([\w-\.]+@([\w-]+\.)+[\w-]{2,4})?$/.test(this.value);
        if(valid) { $("#user-register-form #edit-profile-main-field-receive-notifications").show(); }
        else{ $("#user-register-form #edit-profile-main-field-receive-notifications").hide(); }
      });
      // $(':checkbox').on('change',function(){
      //   var th = $(this), name = th.prop('class'); 
      //   if(th.is(':checked')){
      //     $(':checkbox[class="'  + name + '"]').not($(this)).prop('checked',false);   
      //   }
      // });

      $('#edit-dob-from').focusout(function() {
        var divLength = $(this).val();
        if(divLength.length > 0 ) {
          $('#edit-dob-to').prev().html("To <span class='form-required'>*</span>");
        }else {
          $('#edit-dob-to').prev().html("To ");
        }
      });

      $('#edit-dob-to').focusout(function() {
        var divLength = $(this).val();
        if(divLength.length > 0 ) {
          $('#edit-dob-from').prev().html("From <span class='form-required'>*</span>");
        }else {
          $('#edit-dob-from').prev().html("From ");
        }
      });
          
    var raffleReward = $('#edit-active-raffle').val();
    var raffleName = $('#edit-name-raffle').val();
    var winnerNumbers = $('#edit-winners-selected').val();

    $("#edit-dob-from").keyup(function(){
      var userAgeFrom = $('#edit-dob-from').val();
      var userAgeTo = $('#edit-dob-to').val();
      if ((userAgeFrom.length > 0 || userAgeTo.length > 0) && !(userAgeFrom.length > 0 && userAgeTo.length > 0)) {
        $('#raff_winners').prop('disabled', true);
      } else {
        $('#raff_winners').prop('disabled', false);
      }
    });

    $("#edit-dob-to").keyup(function(){
      var userAgeFrom = $('#edit-dob-from').val();
      var userAgeTo = $('#edit-dob-to').val();
      if ((userAgeFrom.length > 0 || userAgeTo.length > 0) && !(userAgeFrom.length > 0 && userAgeTo.length > 0)) {
        $('#raff_winners').prop('disabled', true);
      } else {
        $('#raff_winners').prop('disabled', false);
      }
    });


    if (raffleReward == 0 || raffleName == "" || winnerNumbers == "")  {
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
      // var 
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
                setTimeout(function(){
                  var error_div = $('#error_raffle').text();
                  if(error_div) {
                $('#raff_winners').show();
                  } else {
                    $('#raff_winners').hide();
                  }
                }, 25);
              $('#print_raffle').on('click', function() {
                printDiv('#rf-tbl');
              });
            }
          }
        });
      }

      function confirm_rf_winners() {
        bootbox.confirm({
          message: "<div class = 'alrt'>Alert<div><br/>Raffle once drawn cannot be reversed. Please click Proceed to contunue or Cancel to go back to the Draw Raffle Winners screen",
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
              return rf_winners_list();
            }
          }
        });
      }

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
    }
  }
})(jQuery);






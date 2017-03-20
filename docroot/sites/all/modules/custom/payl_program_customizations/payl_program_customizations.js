/**
 * @file
 * Adds form selector behaviors for setting up random items.
 */

// Extend string
// if (typeof String.prototype.startsWith != 'function') {
//   // see below for better implementation!
//   String.prototype.startsWith = function (str){
//     return this.indexOf(str) === 0;
//   };
// }

(function ($) {
  Drupal.behaviors.payl_program_customizations = {
    attach: function() {
      Drupal.settings.payl_program_customizations_birthday_limit = parseInt(Drupal.settings.payl_program_customizations_birthday_limit);
      
      $('#user-register-form .form-item-name').hide();
      $('#user-register-form .date-year .form-select').on('change', function() {
        var birthdayMonth = jQuery('#user-register-form .date-month .form-select').val();
        console.log (birthdayMonth);
        var birthdayDay = jQuery('#user-register-form .date-day .form-select').val();
        console.log (birthdayDay);
        var birthdayYear = jQuery('#user-register-form .date-year .form-select').val();
        console.log (birthdayYear);
        var age = calculate_age(birthdayMonth,birthdayDay,birthdayYear);
        console.log(age);
        // More than 13 years old.
        if (age > 12 || age == NaN) {
          $('#user-register-form .form-item-name').show();
        }
        // Less than 13 years old.
        else {
          $('#user-register-form .form-item-name').hide();
        }

      });

      $('#user-register-form .field-widget-random-list-widget-randomizer').each(function(index) {
        fieldname = 'Change ' + $(this).find('label').html();
        $(this).find('#user-register-form input .random-list-widget-regenerate').val(fieldname);
        $(this).find('#user-register-form button .random-list-widget-regenerate').html(fieldname);
      });
      $('#user-register-form .field-widget-random-list-widget-randomizer .form-type-textfield').hide();
      $('#user-register-form .random-list-widget').attr('readonly', true);
      $('#user-register-form .random-list-widget-regenerate').click(function() {
        setTimeout(function() {
          var name = '';
          $('#user-register-form .random-list-widget').each(function(index) {
            name = name + $(this).val();
          });
          $('#user-register-form #edit-name').val(name);
      

      $('.not-logged-in #user-register-form .date-year').bind('change', function() {
        var birthdayMonth = jQuery('#user-register-form .date-month .form-select').val();
      // console.log(birthdayMonth);
      var birthdayDay = jQuery('#user-register-form .date-day .form-select').val();
      // console.log(birthdayDay);
      var birthdayYear = jQuery('#user-register-form .date-year .form-select').val();
      // console.log(birthdayYear);

        var age = calculate_age(birthdayMonth,birthdayDay,birthdayYear);
        console.log(age);
        // More than 13 years old.
        if (age > 12 || age == NaN) {
          $('#user-register-form .form-item-name').show();
        }
        // Less than 13 years old.
        else {
          $('#user-register-form .form-item-name').hide();
        }

      });
          var username = name;
          $.ajax({
            url: Drupal.settings.basePath + 'username/check',
            type: 'post',
            async: true,
            data: "name="+username,
            success: function (data) {
              if (data) {
                if (data == 'yes') {
                  console.log(data);
                  setTimeout(function() {
                    $('#user-register-form .random-list-widget-regenerate').click();
                  }, 150);
                }
              }
            }
          });
          payl_program_customizations_change_name();
        }, 50);
      });
      $('#user-register-form #edit-name').keyup(payl_program_customizations_change_name);

      var edit_username = $('#user-register-form #edit-account #edit-name').val();

      //username not to change on field errors 
      var url = window.location.href;
      var array = url.split('/');
      var lastsegment = array[array.length-1];

      if (lastsegment == 'register'){
        if($("div").hasClass("error")){
          localStorage.setItem('username_generated', name);
          var uname = localStorage.getItem('username_generated');
          $('#user-register-form .current-username').html(uname);
        }else{
          setTimeout(function() {
            $('#user-register-form .random-list-widget-regenerate').click();
          }, 150);
        }
      }else{
        if($("#user-register-form button").hasClass("random-list-widget-regenerate")){
          if(edit_username.length > 0){
            $('#user-register-form .current-username').html(edit_username);
          }else{
            $('#user-register-form .random-list-widget-regenerate').click();
          }
        }
      }
    }
  }

  function payl_program_customizations_change_name() {
    name = $('#user-register-form #edit-name').val();
    $('#user-register-form .current-username').html(name);
  }

  function calculate_age(birth_month,birth_day,birth_year) {
    today_date = new Date(); 
    today_year = today_date.getFullYear();
    today_month = today_date.getMonth(); 
    today_day = today_date.getDate();
    age = today_year - birth_year; 
    if ( today_month < (birth_month - 1)) { 
      age--; 
    } if (((birth_month - 1) == today_month) && (today_day < birth_day)) {
      age--; 
    } 
    return age; 
  }



})(jQuery);

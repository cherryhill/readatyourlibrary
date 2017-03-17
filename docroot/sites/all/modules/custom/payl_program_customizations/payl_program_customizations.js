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
      
      $('.page-user-register .form-item-name').hide();
      $('.page-user-register .date-year .form-select').on('change', function() {
        var birthdayMonth = jQuery('.page-user-register .date-month .form-select').val();
        console.log (birthdayMonth);
        var birthdayDay = jQuery('.page-user-register .date-day .form-select').val();
        console.log (birthdayDay);
        var birthdayYear = jQuery('.page-user-register .date-year .form-select').val();
        console.log (birthdayYear);
        var age = calculate_age(birthdayMonth,birthdayDay,birthdayYear);
        console.log(age);
        // More than 13 years old.
        if (age > 12 || age == NaN) {
          $('.page-user-register .form-item-name').show();
        }
        // Less than 13 years old.
        else {
          $('.page-user-register .form-item-name').hide();
        }

      });

      $('.page-user-register .field-widget-random-list-widget-randomizer').each(function(index) {
        fieldname = 'Change ' + $(this).find('label').html();
        $(this).find('.page-user-register input .random-list-widget-regenerate').val(fieldname);
        $(this).find('.page-user-registerbutton .random-list-widget-regenerate').html(fieldname);
      });
      $('.page-user-register .field-widget-random-list-widget-randomizer .form-type-textfield').hide();
      $('.page-user-register .random-list-widget').attr('readonly', true);
      $('.page-user-register .random-list-widget-regenerate').click(function() {
        setTimeout(function() {
          var name = '';
          $('.page-user-register .random-list-widget').each(function(index) {
            name = name + $(this).val();
          });
          $('.page-user-register #edit-name').val(name);
      

      $('.page-user-register .date-year').bind('change', function() {
        var birthdayMonth = jQuery('.page-user-register .date-month .form-select').val();
      // console.log(birthdayMonth);
      var birthdayDay = jQuery('.page-user-register .date-day .form-select').val();
      // console.log(birthdayDay);
      var birthdayYear = jQuery('.page-user-register .date-year .form-select').val();
      // console.log(birthdayYear);

        var age = calculate_age(birthdayMonth,birthdayDay,birthdayYear);
        console.log(age);
        // More than 13 years old.
        if (age > 12 || age == NaN) {
          $('.page-user-register .form-item-name').show();
        }
        // Less than 13 years old.
        else {
          $('.page-user-register .form-item-name').hide();
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
                    $('.page-user-register .random-list-widget-regenerate').click();
                  }, 150);
                }
              }
            }
          });
          payl_program_customizations_change_name();
        }, 50);
      });
      $('.page-user-register #edit-name').keyup(payl_program_customizations_change_name);

      var edit_username = $('.page-user-register #edit-account #edit-name').val();

      //username not to change on field errors 
      var url = window.location.href;
      var array = url.split('/');
      var lastsegment = array[array.length-1];

      if (lastsegment == 'register'){
        if($("div").hasClass("error")){
          localStorage.setItem('username_generated', name);
          var uname = localStorage.getItem('username_generated');
          $('.page-user-register .current-username').html(uname);
        }else{
          setTimeout(function() {
            $('.page-user-register .random-list-widget-regenerate').click();
          }, 150);
        }
      }else{
        if($(".page-user-register button").hasClass("random-list-widget-regenerate")){
          if(edit_username.length > 0){
            $('.page-user-register .current-username').html(edit_username);
          }else{
            $('.page-user-register .random-list-widget-regenerate').click();
          }
        }
      }
    }
  }

  function payl_program_customizations_change_name() {
    name = $('.page-user-register #edit-name').val();
    $('.page-user-register .current-username').html(name);
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

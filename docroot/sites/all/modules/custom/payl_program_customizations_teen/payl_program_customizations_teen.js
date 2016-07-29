/**
 * @file
 * Adds form selector behaviors for setting up random items.
 * May move to ajax down the line.
 */
// Extend string
if (typeof String.prototype.startsWith != 'function') {
  // see below for better implementation!
  String.prototype.startsWith = function (str){
    return this.indexOf(str) === 0;
  };
}
(function ($) {
  Drupal.behaviors.payl_program_customizations_teen = {
    attach: function() {
        var role_block = $('.role-based p').text();
        if(role_block) {
          $("#branding .tabs.primary a").each(function() {
            if($(this).text() == 'Manage display') {
              $(this).remove();
            }
          });
        }
      $('.role-based').hide();

      Drupal.settings.payl_program_customizations_teen_birthday_limit = parseInt(Drupal.settings.payl_program_customizations_teen_birthday_limit);
      var birthday = new Date($('#edit-profile-main-field-user-birthday-und-0-value-datepicker-popup-0').val());
      var birthday_timestamp = Math.floor(birthday.getTime() / 1000);

      var user_dob = Drupal.settings.payl_program_customizations_user_date_of_birth;
      var birthday_patron = new Date(user_dob);
      var birthday_timestamp_patron = Math.floor(birthday_patron.getTime() / 1000);
      // alert(birthday_timestamp_patron);
      // More than 13 years old.
      if (birthday_timestamp < Drupal.settings.payl_program_customizations_teen_birthday_limit) {
        $('.page-user-register .form-item-name').show();
      }
      // Less than 13 years old.
      else {
        $('.page-user-register .form-item-name').hide();
      }

      // Changes for user edit profile
      if (birthday_timestamp_patron > Drupal.settings.payl_program_customizations_teen_birthday_limit) {
        $('.page-user-edit .form-item-name').hide();
      }
      else {
        $('.page-user-edit .form-item-name').show();
      }

      $('#edit-profile-main-field-user-birthday-und-0-value-datepicker-popup-0').bind('change', function(date_object) {
        Drupal.settings.payl_program_customizations_teen_birthday_limit = parseInt(Drupal.settings.payl_program_customizations_teen_birthday_limit);
        var birthday = new Date($('#edit-profile-main-field-user-birthday-und-0-value-datepicker-popup-0').val());
        var birthday_timestamp = Math.floor(birthday.getTime() / 1000);
        
        if (birthday_timestamp < Drupal.settings.payl_program_customizations_teen_birthday_limit) {
          $('.page-user-register .form-item-name').show();
        }
        else {
        $('.page-user-register .form-item-name').hide();
        }
      });

      $('.field-widget-random-list-widget-randomizer').each(function(index) {
        fieldname = 'Change ' + $(this).find('label').html();
        $(this).find('input.random-list-widget-regenerate').val(fieldname);
        $(this).find('button.random-list-widget-regenerate').html(fieldname);
      });
      $('.field-widget-random-list-widget-randomizer .form-type-textfield').hide();
      $('.random-list-widget').attr('readonly', true);
      $('.random-list-widget-regenerate').click(function() {
        setTimeout(function() {
          var name = '';
          $('.random-list-widget').each(function(index) {
            name = name + $(this).val();
          });
          $('#edit-name').val(name);
          payl_program_customizations_teen_change_name();
        }, 50);
      });
      $('#edit-name').keyup(payl_program_customizations_teen_change_name);

      var edit_username = $('#edit-account #edit-name').val();

      //username not to change on field errors 
      var url = window.location.href;
      var array = url.split('/');
      var lastsegment = array[array.length-1];

      if (lastsegment == 'register'){
        if($("div").hasClass("error")){
          localStorage.setItem('username_generated', name);
          var uname = localStorage.getItem('username_generated');
          $('.current-username').html(uname);
        }else{
          setTimeout(function() {
            $('.random-list-widget-regenerate').click();
          }, 150);
        }
      }else{
        if($("button").hasClass("random-list-widget-regenerate")){
          if(edit_username.length > 0){
            $('.current-username').html(edit_username);
          }else{
            $('.random-list-widget-regenerate').click();
          }
        }
      }
    }
  }

  function payl_program_customizations_teen_change_name() {
    name = $('#edit-name').val();
    $('.current-username').html(name);
  }
})(jQuery);

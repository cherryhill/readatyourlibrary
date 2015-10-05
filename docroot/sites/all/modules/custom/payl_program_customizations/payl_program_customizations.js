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
  Drupal.behaviors.payl_program_customizations = {
    attach: function() {
      Drupal.settings.payl_program_customizations_birthday_limit = parseInt(Drupal.settings.payl_program_customizations_birthday_limit);
      $('#edit-profile-main-field-user-birthday-und-0-value-datepicker-popup-0').bind('change', function(date_object) {
        var birthday = new Date($(this).val());
        var birthday_timestamp = Math.floor(birthday.getTime() / 1000);
        // More than 13 years old.
        if (birthday_timestamp < Drupal.settings.payl_program_customizations_birthday_limit) {
          $('.form-item-name').show();
        }
        // Less than 13 years old.
        else {
          $('.form-item-name').hide();
        }
      });

      $('.form-item-name').hide();
      $('.field-widget-random-list-widget-randomizer').each(function(index) {
        fieldname = 'Regenerate ' + $(this).find('label').html();
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
          payl_program_customizations_change_name();
        }, 50);
      });
      $('#edit-name').keyup(payl_program_customizations_change_name);

      setTimeout(function() {
        $('.random-list-widget-regenerate').click();
      }, 150);
    }
  }

  function payl_program_customizations_change_name() {
    name = $('#edit-name').val();
    $('.current-username').html(name);
  }
})(jQuery);

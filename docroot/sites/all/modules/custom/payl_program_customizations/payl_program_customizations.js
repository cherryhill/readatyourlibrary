/**
 * @file
 * Adds form selector behaviors for setting up random items.
 * May move to ajax down the line.
 */
(function ($) {
  Drupal.behaviors.payl_program_customizations = {
    attach: function() {
      Drupal.settings.payl_program_customizations_birthday_limit = parseInt(Drupal.settings.payl_program_customizations_birthday_limit);
      $('#edit-field-user-birthday-und-0-value-datepicker-popup-0').bind('change', function(date_object) {
        var birthday = new Date($(this).val());
        var birthday_timestamp = Math.floor(birthday.getTime() / 1000);
        // More than 13 years old.
        if (birthday_timestamp < Drupal.settings.payl_program_customizations_birthday_limit) {
          console.log('old!');
          $('#edit-field-username').show();
        }
        // Less than 13 years old.
        else {
          $('#edit-field-username').hide();
        }
      });
      $('#edit-field-username').hide();
    }
  }
})(jQuery);
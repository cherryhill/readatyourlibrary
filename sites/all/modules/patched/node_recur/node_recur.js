(function ($) {

Drupal.behaviors.noderecur = {};
Drupal.noderecur = Drupal.noderecur || {};

/**
 * Attach behavior to node recur form
 */
Drupal.behaviors.noderecur = {
  attach: function (context) {
    // Attach the date popup to the 'recur until' field
    $('#edit-until', context).datepicker();
    
    // Select the recur form components
    var days = $('.form-item-days', context);
    var rules = $('#edit-rules', context);
    var monthly = $('#edit-monthly', context);
    var until =  $('.form-item-until', context);
    var option_days = $('#edit-option-days', context);
    var option_rules = $('#edit-option-rules', context);
    var option_monthly = $('#edit-option-monthly', context);
    var option_none = $('#edit-option-none', context);
    var options = $('#edit-option input', context);
    
    // Set the visibility based on the current option selected
    Drupal.noderecur.toggle(option_days, option_rules, option_monthly, option_none, days, rules, monthly, until);
    
    // Reset the visibility when the option changes
    options.change(function() {
      Drupal.noderecur.toggle(option_days, option_rules, option_monthly, option_none, days, rules, monthly, until);
    });
  }
};

/**
 * Toggle the visibility of the form widgets
 */
Drupal.noderecur.toggle = function(option_days, option_rules, option_monthly, option_none, days, rules, monthly, until) {
  if (option_days.attr('checked')) {
    rules.hide();
    monthly.hide();
    days.show();
    until.show();
  }
  
  if (option_rules.attr('checked')) {
    days.hide();
    monthly.hide();
    rules.show();
    until.show();
  }

  if (option_monthly.attr('checked')) {
    days.hide();
    rules.hide();
    monthly.show();
    until.show();
  }
  
  if (option_none.attr('checked')) {
    days.hide();
    rules.hide();
    monthly.hide();
    until.hide();
  }
};

})(jQuery);


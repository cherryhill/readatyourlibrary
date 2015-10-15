(function ($) {
  Drupal.behaviors.flexicolor = {
    attach: function() {
      // Update both the flexicolor preview and the textbox background whenever a textbox gets changed.
      function updateTextBox(color, object) {
        $(object).css({
          'backgroundColor': color,
          'color': Drupal.settings.flexicolorAdminFarbtastic.RGBToHSL(Drupal.settings.flexicolorAdminFarbtastic.unpack(color))[2] > 0.5 ? '#000' : '#fff'
        });
      }
      
      function updateAllTextBoxes() {
        // Colour the text boxes their value color.
        $('#flexicolor-fieldset input:text').each(function(index, object) {
          var value = $(object).val();
          if (value) {
            updateTextBox($(object).val(), object);
          }
        });
      }
      
      // Create the Farbtastic color picker
      if ($('#flexicolor-admin-update-selector').length) {
        $('#flexicolor-color-picker').addClass('color-processed');
        Drupal.settings.flexicolor = $.farbtastic('#flexicolor-color-picker', '#edit-color');
      }
      else if ($('#flexicolor-fieldset').length) {
        // Create the Farbtastic color picker
        Drupal.settings.flexicolorAdminFarbtastic = $.farbtastic('#flexicolor-color-picker', function(color) {
          if ($('#edit-flexicolor-selected-preset').length && color != $(Drupal.settings.flexicolorAdminTextbox).val()) {
            $('#edit-flexicolor-selected-preset').val('');
          }
          $(Drupal.settings.flexicolorAdminTextbox).val(color);
          updateTextBox(color, Drupal.settings.flexicolorAdminTextbox);
        });
      
        // Make the focus of the textbox change the input box we're acting on.
        $('#flexicolor-fieldset input:text').focus(function() {
          $('#flexicolor-fieldset .form-item').css({
            'border': 'none'
          });
          $(this).parent().css({
            'border': 'solid 2px red'
          });
          Drupal.settings.flexicolorAdminTextbox = this;
          Drupal.settings.flexicolorAdminFarbtastic.setColor(this.value);
        });
        
        $('#flexicolor-fieldset input:text').keyup(function() {
          Drupal.settings.flexicolorAdminFarbtastic.setColor(this.value);
          if ($('#edit-flexicolor-selected-preset').length) {
            $('#edit-flexicolor-selected-preset').val('');
          }
        })
        
        updateAllTextBoxes();
      }
      
      if ($('#edit-flexicolor-selected-preset').length) {
        // Start to add some cool stuff in here!
        $('#edit-flexicolor-selected-preset').change(function() {
          selected_preset_value = $(this).val();
          if (selected_preset_value != '') {
            preset_selectors = Drupal.settings.flexicolor_preset_selectors;
            $.each(preset_selectors, function(preset_key, preset_value) {
              if (selected_preset_value == preset_key) {
                $.each(preset_value, function(selector_key, selector_value){
                  selector_id = '#edit-flexicolor-' + selector_key;
                  $(selector_id).val(selector_value);
                });
              }
            });
            updateAllTextBoxes();
          }
        });
      }
    }
  }
})(jQuery);

/**
 * @file
 * Overrides the default vertical tabs behavior on the Manage Features page.
 */

(function ($) {
  Drupal.behaviors.verticalTabs = {
    attach: function (context) {
      $('.vertical-tabs-panes', context).once('vertical-tabs', function () {
        var focusID = $(':hidden.vertical-tabs-active-tab', this).val();
        var tab_focus;

        // Check if there are some fieldsets that can be converted to vertical-tabs
        var $fieldsets = $('> fieldset', this);
        if ($fieldsets.length == 0) {
          return;
        }

        // Create the tab column.
        var tab_list = $('<ul class="vertical-tabs-list"></ul>');
        $(this).wrap('<div class="vertical-tabs clearfix"></div>').before(tab_list);

        // Transform each fieldset into a tab.
        $fieldsets.each(function () {
          var vertical_tab = new Drupal.verticalTab({
            title: $('> legend', this).text(),
            fieldset: $(this)
          });
          tab_list.append(vertical_tab.item);
          $(this)
            .removeClass('collapsible collapsed')
            .addClass('vertical-tabs-pane')
            .data('verticalTab', vertical_tab);
          if (this.id == focusID) {
            tab_focus = $(this);
          }
        });

        $('> li:first', tab_list).addClass('first');
        $('> li:last', tab_list).addClass('last');

        if (!tab_focus) {
          // If the current URL has a fragment and one of the tabs contains an
          // element that matches the URL fragment, activate that tab.
          if (window.location.hash && $(this).find(window.location.hash).length) {
            tab_focus = $(this).find(window.location.hash).closest('.vertical-tabs-pane');
          }
          // The following `else if` is the only customization in this function.
          // If the default tab variable exists, give the default tab focus.
          else if ($(Drupal.settings.featuresDefaultTab.id).length) {
            // Get the index of the default tab and give it focus.
            var tab_number = $(Drupal.settings.featuresDefaultTab.id).prevAll().andSelf().length;
            tab_focus = $('> .vertical-tabs-pane:nth-child(' + tab_number + ')', this);
          }
          else {
            tab_focus = $('> .vertical-tabs-pane:first', this);
          }
        }
        if (tab_focus.length) {
          tab_focus.data('verticalTab').focus();
        }
      });
    }
  };
})(jQuery);

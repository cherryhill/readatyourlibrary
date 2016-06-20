/**
 * @file table_trash.js
 * 
 * Takes parameters set on the configuration page and invokes the DataTables JS
 * and DataTables-Responsive JS libraries.
 */
(function ($) {
  Drupal.behaviors.table_trash_attach = {

    attach: function(context, settings) {

      $(settings.table_trash, context).each(function() {
        // settings.table_trash is an array of params indexed by selectors as
        // entered on the Table Trash config page. One selector per decoration.
        $.each(this, function(selector, params) {
          var tables = $(selector);

          if (tables.length > 0) {
            if (params['iExpandCol'] >= 0) {
              // Expand column specified: set up for responsive DataTables.
              tables.find('th:eq(' + params['iExpandCol'] + ')').attr('data-class', 'expand');
              for (var i = 0; i < params['aiHideColsPhone'].length; i++) {
                var th = tables.find('th:eq(' + params['aiHideColsPhone'][i] + ')');
                th.attr('data-hide', 'phone');
              }
              for (var j = 0; j < params['aiHideColsTablet'].length; j++) {
                var th = tables.find('th:eq(' + params['aiHideColsTablet'][j] + ')');
                th.attr('data-hide', th.attr('data-hide') ? 'phone,tablet' : 'tablet');
              }
              params['bAutoWidth'] = false,
              params['fnPreDrawCallback'] = function() {
                if (!this.responsiveHelper) {
                  var breakpointDef = { phone: params['iBreakpointPhone'], tablet: params['iBreakpointTablet'] };
                  this.responsiveHelper = new ResponsiveDatatablesHelper(this, breakpointDef);
                }
              };
              params['aaSorting'] = [];
              params['fnRowCallback'] = function(nRow) { this.responsiveHelper.createExpandIcon(nRow); };
              params['fnDrawCallback'] = function() { this.responsiveHelper.respond(); };
            }

            var trashed_tables = tables.dataTable(params);

            if (params['sScrollXInner']) {
              if (params['iFixedLeftColumns']) {
                // trashed_tables[t] does not work for FixedColumns()
                new FixedColumns(trashed_tables, { iLeftColumns: params['iFixedLeftColumns'] });
              }
            }
            else if (params['bFixedHeader']) {
              for (var t = 0; t < trashed_tables.length; t++) {
                new FixedHeader(trashed_tables[t]);
              }
            }
          }
        });
      });
    }
  };
}) (jQuery);

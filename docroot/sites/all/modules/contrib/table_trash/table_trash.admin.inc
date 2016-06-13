<?php

/**
 * @file
 * table_trash.admin.inc
 *
 * Configuration options for Table Trash module.
 */

/**
 * Menu callback for admin configuration settings.
 */
function table_trash_admin_configure($form, &$form_state) {

  // Retain tree-hierarchy in values, prevent the form from being flattened.
  $form['#tree'] = TRUE;

  $decorations = variable_get('table_trash_decorations', array());
  if (!isset($form_state['num-decorations'])) {
    $form_state['num-decorations'] = max(0, count($decorations));
  }

  $form['decorations'] = array(
    '#type' => 'fieldset',
    '#collapsible' => FALSE,
    '#title' => t('Table decorations on this site'),
    // The following id refers to the #ajax wrappers below.
    '#prefix' => '<div id="decorations-wrapper">',
    '#suffix' => '</div>',
  );
  $form['decorations']['#attached']['css'][] = drupal_get_path('module', 'table_trash') . '/css/table_trash.admin.css';

  for ($i = 1; $i <= $form_state['num-decorations']; $i++) {
    $form['decorations'][$i] = array(
      '#type' => 'fieldset',
      '#collapsible' => TRUE,
      '#title' => t('Table decoration #@no', array('@no' => $i)),
    );
    $decoration_params = $decorations[$i]['decoration-params'];
    $form['decorations'][$i]['decoration-params'] = array(
      '#type' => 'markup',
      '#prefix' => '<div class="decoration-params">',
      '#suffix' => '</div>',
    );
    $form['decorations'][$i]['decoration-params']['search-box'] = array(
      '#type' => 'checkbox',
      '#title' => t('Display search-box'),
      '#default_value' => isset($decoration_params['search-box']) ? $decoration_params['search-box'] : TRUE,
      '#description' => t('The search-box allows the visitor to filter the table by keywords they enter.'),
    );
    $form['decorations'][$i]['decoration-params']['column-reorder'] = array(
      '#type' => 'checkbox',
      '#title' => t('Reorder and/or resize columns'),
      '#default_value' => isset($decoration_params['column-reorder']) ? $decoration_params['column-reorder'] : TRUE,
      '#description' => t('Reposition and adjust widths of columns by clicking and dragging the headers.'),
    );
    $form['decorations'][$i]['decoration-params']['export-buttons'] = array(
      '#type' => 'checkbox',
      '#title' => t('Add export buttons'),
      '#default_value' => isset($decoration_params['export-buttons']) ? $decoration_params['export-buttons'] : TRUE,
      '#description' => t('Copy-to-clipboard, CSV, Excel, PDF, Print.'),
    );
    $form['decorations'][$i]['decoration-params']['retrieve-data'] = array(
      '#type' => 'checkbox',
      '#title' => t('Allow AJAX updates of targeted tables'),
      '#default_value' => isset($decoration_params['retrieve-data']) ? $decoration_params['retrieve-data'] : FALSE,
      '#description' => t('Tick if you get error messages using Exposed Filters on tabular Views with <strong>Use AJAX: Yes</strong>. Do not tick if you do not have any issues, as there is a small performance penalty to pay.'),
    );
    $form['decorations'][$i]['decoration-params']['pager-style'] = array(
      '#type' => 'select',
      '#multiple' => FALSE,
      '#title' => t('Pager style'),
      '#options' => array(
        '' => t('No pager'),
        'two_button' => t('Prev/Next buttons only'),
        'full_numbers' => t('Prev/Next, First/Last and page counts'),
      ),
      '#default_value' => isset($decoration_params['pager-style']) ? $decoration_params['pager-style'] : '',
      '#description' => t('If you use this client-side pager, it is recommended you switch off the server-side pager (as provided by Views).'),
    );
    $form['decorations'][$i]['decoration-params']['page-height'] = array(
      '#type' => 'textfield',
      '#size' => 4,
      '#maxlength' => 4,
      '#title' => t('Page height'),
      '#default_value' => isset($decoration_params['page-height']) ? $decoration_params['page-height'] : '',
      '#description' => t('If paged, number of rows per page.'),
    );
    $form['decorations'][$i]['decoration-params']['dont-sort-columns'] = array(
      '#type' => 'textfield',
      '#size' => 32,
      '#title' => t('Columns NOT sortable'),
      '#default_value' => isset($decoration_params['dont-sort-columns']) ? $decoration_params['dont-sort-columns'] : '',
      '#description' => t('All columns are sortable by default. Enter a comma-separated list of column numbers for which client-side sorting is to be <em>disabled</em>. The leftmost column is number 1. Enter <strong>0</strong> to switch off column-sorting altogether.'),
    );
    $form['decorations'][$i]['decoration-params']['x-scroll'] = array(
      '#type' => 'textfield',
      '#size' => 4,
      '#title' => t('Oversize and scroll horizontally'),
      '#default_value' => isset($decoration_params['x-scroll']) ? $decoration_params['x-scroll'] : '',
      '#description' => t('Enter the desired width of the widened table. May be expressed in pixels or as a percentage of its original width. Example: <strong>150%</strong>'),
    );
    $form['decorations'][$i]['decoration-params']['fixed-left-columns'] = array(
      '#type' => 'textfield',
      '#size' => 4,
      '#maxlength' => 2,
      '#title' => t('Fix left column(s)'),
      '#default_value' => isset($decoration_params['fixed-left-columns']) ? $decoration_params['fixed-left-columns'] : '',
      '#description' => t('Works in conjunction with <em>Oversize and scroll horizontally</em>. Enter the number of left columns to fix in position when scrolling horizontally. Example: <strong>1</strong>'),
    );
    $form['decorations'][$i]['decoration-params']['fixed-header'] = array(
      '#type' => 'checkbox',
      '#title' => t('Fix table header on scroll'),
      '#default_value' => isset($decoration_params['fixed-header']) ? $decoration_params['fixed-header'] : FALSE,
      '#description' => t('Fix the header to the top of the window when vertically scrolling tall tables. Cannot be used with <em>Oversize and scroll horizontally</em> or AJAX.'),
    );

    $form['decorations'][$i]['decoration-params']['responsive'] = array(
      '#type' => 'fieldset',
      '#collapsible' => TRUE,
      '#collapsed' => TRUE,
      '#title' => t('Responsive tables feature'),
      '#description' => t('Responsively hides selected columns on small windows. Hidden cell content is revealed when the "expand" icon is clicked. Does not work in combination with <em>Oversize and scroll horizontally</em>.'),
    );
    $responsive = $decoration_params['responsive'];
    $form['decorations'][$i]['decoration-params']['responsive']['responsive-expand-col'] = array(
      '#type' => 'textfield',
      '#size' => 4,
      '#title' => t('"Expand" column'),
      '#default_value' => isset($responsive['responsive-expand-col']) ? $responsive['responsive-expand-col'] : '',
      '#description' => t("Typically you'd pick the title column for this. The leftmost column is number 1. Leave empty to disallow tables from responding to small window-sizes."),
    );
    $form['decorations'][$i]['decoration-params']['responsive']['responsive-collapse-cols-phone'] = array(
      '#type' => 'textfield',
      '#size' => 32,
      '#maxsize' => 256,
      '#title' => t('Columns to hide when width of window is phone-size'),
      '#default_value' => isset($responsive['responsive-collapse-cols-phone']) ? $responsive['responsive-collapse-cols-phone'] : '',
    );
    $form['decorations'][$i]['decoration-params']['responsive']['responsive-collapse-cols-tablet'] = array(
      '#type' => 'textfield',
      '#size' => 32,
      '#maxsize' => 256,
      '#title' => t('Columns to hide when width of window is tablet-size'),
      '#default_value' => isset($responsive['responsive-collapse-cols-tablet']) ? $responsive['responsive-collapse-cols-tablet'] : '',
      '#description' => t('This is usually a subset of the columns specified for phone-sized windows.'),
    );

    $form['decorations'][$i]['pages-and-selector'] = array(
      '#type' => 'markup',
      '#prefix' => '<div class="pages-and-selector">',
      '#suffix' => '</div>',
    );
    $pages_and_selector = $decorations[$i]['pages-and-selector'];
    $form['decorations'][$i]['pages-and-selector']['include-pages'] = array(
      '#type' => 'textarea',
      '#rows' => 2,
      '#title' => t('Pages to be adorned with all of the above'),
      '#default_value' => isset($pages_and_selector['include-pages']) ? $pages_and_selector['include-pages'] : TABLE_TRASH_DEFAULT_PAGE_INCLUSIONS,
      '#description' => t("Enter relative paths, one per line. Do not start with a slash. You may use path aliases. <em>&lt;front&gt;</em> means the front page. The asterisk <em>*</em> is the wildcard character, i.e. <em>admin/*</em> denotes all pages that have a path starting with <em>admin/</em>"),
      '#required' => TRUE,
    );
    $form['decorations'][$i]['pages-and-selector']['exclude-pages'] = array(
      '#type' => 'textarea',
      '#rows' => 3,
      '#title' => t('Exceptions: pages excluded from wildcards on the left'),
      '#default_value' => isset($pages_and_selector['exclude-pages']) ? $pages_and_selector['exclude-pages'] : TABLE_TRASH_DEFAULT_PAGE_EXCLUSIONS,
      '#description' => t('One relative path per line.'),
    );
    $form['decorations'][$i]['pages-and-selector']['table-selector'] = array(
      '#type' => 'textfield',
      '#size' => 32,
      '#title' => t('CSS-selector for tables targeted'),
      '#default_value' => isset($pages_and_selector['table-selector']) ? $pages_and_selector['table-selector'] : '',
      '#description' => t('Empty defaults to <strong>@default-selector</strong> and will usually be ok. If you want to decorate say a <a href="@views" target="views">Views</a> block and a Views attachment, but no other tables on that page, then target the individual tables. Like this: <strong>.view-display-id-block_1&nbsp;table, .view-display-id-attachment_1&nbsp;table</strong>', array(
        '@views' => url('http://drupal.org/project/views'),
        '@default-selector' => TABLE_TRASH_DEFAULT_TABLE_SELECTOR)
      ),
    );
  }

  $form['decorations']['add-another'] = array(
    '#type' => 'submit',
    '#value' => empty($form_state['num-decorations']) ? t('Add table decoration') : t('Add another table decoration'),
    '#weight' => 1,
    '#submit' => array('_table_trash_add_decoration_submit'),
    '#ajax' => array(
      'callback' => '_table_trash_decoration_js',
      'wrapper' => 'decorations-wrapper',
      // 'fade', 'none' or 'slide'.
      'effect' => 'fade',
      // 'fast', 'slow' or number of millisec.
      'speed' => 'slow',
    ),
  );
  if ($form_state['num-decorations'] > 0) {
    $form['decorations']['remove'] = array(
      '#type' => 'submit',
      '#value' => t('Remove last decoration'),
      '#weight' => 2,
      '#submit' => array('_table_trash_remove_decoration_submit'),
      '#ajax' => array(
        'callback' => '_table_trash_decoration_js',
        'wrapper' => 'decorations-wrapper',
        // 'fade', 'none' or 'slide'.
        'effect' => 'fade',
        // 'fast', 'slow' or number of millisec.
        'speed' => 'fast',
      ),
    );
  }

  $form['global-settings'] = array(
    '#type' => 'fieldset',
    '#collapsible' => TRUE,
    '#collapsed' => TRUE,
    '#title' => t('Global settings'),
  );
  $global_settings = variable_get('table_trash_global_settings', array());

  $form['global-settings']['responsive'] = array(
    '#type' => 'markup',
    '#prefix' => '<div id="global-settings-responsive">',
    '#suffix' => '</div>',
  );
  $form['global-settings']['responsive']['responsive-breakpoint-phone'] = array(
    '#type' => 'textfield',
    '#size' => 4,
    '#maxlength' => 4,
    '#field_suffix' => t('px'),
    '#title' => t('Responsive width breakpoint for phone-sized windows'),
    '#default_value' => isset($global_settings['responsive']['responsive-breakpoint-phone']) ? $global_settings['responsive']['responsive-breakpoint-phone'] : '',
    '#description' => t('The default width for phones is %px.', array('%px' => TABLE_TRASH_DEFAULT_BREAKPOINT_PHONE)),
  );
  $form['global-settings']['responsive']['responsive-breakpoint-tablet'] = array(
    '#type' => 'textfield',
    '#size' => 4,
    '#maxlength' => 4,
    '#field_suffix' => t('px'),
    '#title' => t('Responsive width breakpoint for tablet-sized windows'),
    '#default_value' => isset($global_settings['responsive']['responsive-breakpoint-tablet']) ? $global_settings['responsive']['responsive-breakpoint-tablet'] : '',
    '#description' => t('The default width for tablets is %px.', array('%px' => TABLE_TRASH_DEFAULT_BREAKPOINT_TABLET)),
  );

  $form['global-settings']['use-bug-fixed-library'] = array(
    '#type' => 'checkbox',
    '#title' => t('Use the bug-fixed variants of the required JS libraries.'),
    '#default_value' => isset($global_settings['use-bug-fixed-library']) ? $global_settings['use-bug-fixed-library'] : TRUE,
    '#description' => t('The bug-fixed parts come included with this module. They do not need to be downloaded. However you still need the original DataTables JS libraries as well.'),
  );
  $form['global-settings']['use-datatables-css'] = array(
    '#type' => 'checkbox',
    '#title' => t('Add native DataTables styling'),
    '#default_value' => isset($global_settings['use-datatables-css']) ? $global_settings['use-datatables-css'] : TRUE,
  );
  $form['global-settings']['use-module-css'] = array(
    '#type' => 'checkbox',
    '#title' => t('Add Table Trash styling'),
    '#default_value' => isset($global_settings['use-module-css']) ? $global_settings['use-module-css'] : TRUE,
  );

  $form['actions']['#type'] = 'actions';
  $form['actions']['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Save configuration'),
  );
  $form['#submit'][] = 'table_trash_admin_configure_form_submit';
  $form['#theme'] = 'system_settings_form';
  return $form;
}

/**
 * Submit handler for the "Add another decoration" button.
 *
 * Increments the counter and forces a form rebuild.
 */
function _table_trash_add_decoration_submit($form, &$form_state) {
  $form_state['num-decorations']++;
  $form_state['rebuild'] = TRUE;
}

/**
 * Submit handler for the "Remove" button.
 *
 * Decrements the counter and forces a form rebuild.
 */
function _table_trash_remove_decoration_submit($form, &$form_state) {
  if ($form_state['num-decorations'] > 0) {
    $form_state['num-decorations']--;
    $form_state['rebuild'] = TRUE;
  }
}

/**
 * Ajax callback in response to new rows.
 *
 * At this point the $form has already been rebuilt. All we have to do here is
 * tell AJAX what part of the browser form needs to be updated.
 */
function _table_trash_decoration_js($form, &$form_state) {
  // Return the updated table, so that ajax.inc can issue commands to the
  // browser to update only the targeted sections of the page.
  return $form['decorations'];
}

/**
 * Form submit handler for admin settings.
 *
 * @param array $form
 *   The form
 * @param array $form_state
 *   The form state
 */
function table_trash_admin_configure_form_submit($form, &$form_state) {

  // Clear out the form from stuff, like buttons, we do not wish to save.
  // @todo recursively sanitize (check_plain) all leaf values?)
  form_state_values_clean($form_state);

  variable_set('table_trash_decorations', $form_state['values']['decorations']);
  variable_set('table_trash_global_settings', $form_state['values']['global-settings']);

  // A change in the library files to be included requires clearing of the
  // Libraries cache. A call to libraries_flush_caches() is not sufficient here.
  cache_clear_all('*', 'cache_libraries', TRUE);

  drupal_set_message(t('Table decorations and global configuration have been saved.'));
}

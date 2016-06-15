<?php

/**
 * @file
 *   Drush integration for Table Trash.
 */

/**
 * Two DataTables JS libraries required for Table Trash.
 */
define('TT_DATATABLES_JS_LIB', 'http://datatables.net/releases/DataTables-1.9.4.zip');
define('TT_DATATABLES_RESPONSIVE_JS_LIB', 'https://github.com/Comanche/datatables-responsive/archive/master.zip');
define('TT_DATATABLES_COLREORDER_WITH_RESIZE', 'http://datatables.net/extras/thirdparty/ColReorderWithResize/ColReorderWithResize.js');

/**
 * Implements hook_drush_command().
 */
function table_trash_drush_command() {
  $items = array();

  // The key in the $items array is the name of the command.
  $items['dl-datatables'] = array(
    'callback' => 'table_trash_drush_download_libraries',
    'description' => dt('Download and install the DataTables JS libraries.'),
    'bootstrap' => DRUSH_BOOTSTRAP_DRUSH,
    'arguments' => array(
      'path' => dt('Optional path to download DataTables JS libraries to. Defaults to "sites/all/libraries"'),
    ),
    'aliases' => array('dl-dt'),
  );
  return $items;
}

/**
 * Implementd hook_drush_help().
 *
 * This function is called in response to: 'drush help dl-datatables'
 */
function table_trash_drush_help($section) {
  switch ($section) {
    case 'drush:dl-datatables':
      return dt('Download the DataTables JS and DataTables Responsive JS libraries to thier appropriate places.');
  }
}

/**
 * Command to download the DataTables JS libraries.
 */
function table_trash_drush_download_libraries() {
  $args = func_get_args();
  $lib_path = empty($args[0]) ? 'sites/all/libraries' : trim($args[0]);

  // Create the libraries directory if it does not exist.
  if (!is_dir($lib_path)) {
    drush_op('mkdir', $lib_path);
    drush_log(dt('Directory @lib_path created.', array('@lib_path' => $lib_path)), 'notice');
  }
  drush_log(dt('Starting downloads to @lib_path. This usually takes up to 30 seconds. Please wait...', array('@lib_path' => $lib_path)), 'success');

  if ($zip = table_trash_download_zip(TT_DATATABLES_JS_LIB, $lib_path)) {
    if (table_trash_rename_dir("$lib_path/" . basename($zip, '.zip'), "$lib_path/datatables")) {
      if (table_trash_download_zip(TT_DATATABLES_RESPONSIVE_JS_LIB, $lib_path)) {
        table_trash_rename_dir("$lib_path/datatables-responsive-master", "$lib_path/datatables-responsive");
      }
      // drush_download_file() [without leading underscore] does not work here.
      if (_drush_download_file(TT_DATATABLES_COLREORDER_WITH_RESIZE, "$lib_path/datatables/" . TABLE_TRASH_COLREORDER_WITH_RESIZE_JS, TRUE)) {
        drush_log(dt('Column Reorder JS @url downloaded.', array('@url' => TT_DATATABLES_COLREORDER_WITH_RESIZE)), 'success');
      }
    }
  }
}

/**
 * Download a zipped library from the specified URL to a destination directory.
 *
 * @param string $url
 *   The url to the .zip to be downloaded.
 * @param string $dest_path
 *   The path relative to the Drupal root to put the extracted .zip
 *   Defaults to sites/all/libraries
 *
 * @return boolean
 *   TRUE when the .zip could be downloaded AND extracted successfully
 */
function table_trash_download_zip($url, $dest_path = 'sites/all/libraries') {
  $zip = drush_download_file($url);
  if ($zip) {
    if (drush_tarball_extract($zip, $dest_path)) {
      drush_log(dt('Library @url downloaded and extracted.', array('@url' => $url)), 'success');
    }
    else {
      drush_log(dt('File @zip was downloaded, but could not be extracted.', array('@zip' => $zip)), 'error');
      return FALSE;
    }
  }
  else {
    drush_log(dt('Drush could not download @url', array('@url' => $url)), 'error');
  }
  return $zip;
}

/**
 * Rename a directory.
 *
 * @param string $old_name
 *   Relative the Drupal root.
 * @param string $new_name
 *   Relative to the Drupal root.
 *
 * @return boolean
 *   TRUE on success, FALSE otherwise
 */
function table_trash_rename_dir($old_name, $new_name) {
  if (is_dir($new_name) && drush_delete_dir($new_name, TRUE)) {
    drush_log(dt('The existing library directory @new_name was deleted.', array('@new_name' => $new_name)), 'notice');
  }
  if (drush_move_dir($old_name, $new_name, TRUE)) {
    drush_log(dt('The library directory was renamed to @new_name', array('@new_name' => $new_name)), 'notice');
    return TRUE;
  }
  drush_log(dt('The temporary library directory could not be renamed from @old_name to @new_name', array('@old_name' => $old_name, '@new_name' => $new_name)), 'error');
  return FALSE;
}
<?php
/**
 * @file
 * activity_calendar_sticker.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function activity_calendar_sticker_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}
<?php
/**
 * @file
 * librarysite_text_formats_wysiwyg_imce.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function librarysite_text_formats_wysiwyg_imce_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "linkit" && $api == "linkit_profiles") {
    return array("version" => "1");
  }
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

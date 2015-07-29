<?php

/**
 * Implements hook_features_export_options. [component_hook]
 *
 * This hook will alert features of which specific items of this component may
 * be exported. For instances, in this case, we want to make available all the
 * existing items.  If there are no items to be exported, this component will
 * not be made available in the features export page.
 *
 * @return array
 *   A keyed array of items, suitable for use with a FormAPI select or
 *   checkboxes element.
 */
function flexicolor_selectors_features_export_options() {
  $selectors = array();

  foreach (flexicolor_get_selectors() as $key => $selector) {
    $selectors[$selector->machine] = $selector->display_name;
  }

  return $selectors;
}

/**
 * Implements hook_features_export [component hook]
 *
 * This is a component hook, rather then a module hook, therefore this is the
 * callback from hook_features_api which relates to the specific component we
 * are looking to export.  When a specific instance of the component we are
 * looking to export is selected, this will include the necessariy item, plus
 * any dependencies into our export array.
 *
 * @param array $data
 *   this is the machine name for the component in question
 * @param array &$export
 *   array of all components to be exported
 * @param string $module_name
 *   The name of the feature module to be generated.
 * @return array
 *   The pipe array of further processors that should be called
 */
function flexicolor_selectors_features_export($data, &$export, $module_name = '') {
  $export['dependencies']['flexicolor'] = 'flexicolor';

  foreach (flexicolor_get_selectors() as $key => $selector) {
    if (in_array($selector->machine, $data)) {
      $export['features']['flexicolor_selectors'][$selector->machine] = $selector->machine;
    }
  }

  return $export;
}

/**
 * Implements hook_features_export_render. [component hook]
 *
 * This hook will be invoked in order to export
 * Component hook. The hook should be implemented using the name ot the
 * component, not the module, eg. [component]_features_export() rather than
 * [module]_features_export().
 *
 * Render one or more component objects to code.
 *
 * @param string $module_name
 *   The name of the feature module to be exported.
 * @param array $data
 *   An array of machine name identifiers for the objects to be rendered.
 * @param array $export
 *   The full export array of the current feature being exported. This is only
 *   passed when hook_features_export_render() is invoked for an actual feature
 *   update or recreate, not during state checks or other operations.
 * @return array
 *   An associative array of rendered PHP code where the key is the name of the
 *   hook that should wrap the PHP code. The hook should not include the name
 *   of the module, e.g. the key for `hook_example` should simply be `example`.
 */
function flexicolor_selectors_features_export_render($module, $data) {
  $code = array();

  $selectors = flexicolor_get_selectors();
  foreach ($data as $name) {
    foreach ($selectors as $key => $selector) {
      if($selector->machine == $name) {
        $export_selector = clone $selector;
        unset($export_selector->fsid);
        $code[$name] = $export_selector;
      }
    }
  }
  $code = "  return " . features_var_export($code, '  ') . ";";
  return array('flexicolor_features_default_selectors' => $code);
}

/**
 * Component hook. The hook should be implemented using the name of the
 * component, not the module, eg. [component]_features_export() rather than
 * [module]_features_export().
 *
 * Rebuild all component objects for a given feature module. Should only be
 * implemented for 'faux-exportable' components.
 *
 * This hook is called at points where Features determines that it is safe
 * (ie. the feature is in state `FEATURES_REBUILDABLE`) for your module to
 * replace objects in the database with defaults that you collect from your
 * own defaults hook. See API.txt for how Features determines whether a
 * rebuild of components is possible.
 *
 * @param string $module_name
 *   The name of the feature module whose components should be rebuilt.
 */
function flexicolor_selectors_features_rebuild($module_name) {
  $selectors = module_invoke($module_name, 'flexicolor_features_default_selectors');
  if (!empty($selectors)) {
    foreach ($selectors as $selector) {
      $existing_selector = flexicolor_get_selector_by_machine_name($selector['machine']);
      if (is_object($existing_selector)) {
        $selector['fsid'] = $existing_selector->fsid;
      }
      flexicolor_save_selector($selector);
    }
  }
}

/**
 * Implements hook_features_revert().
 */
function flexicolor_selectors_features_revert($module_name) {
  flexicolor_selectors_features_rebuild($module_name);
}

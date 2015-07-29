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
function flexicolor_presets_features_export_options() {
  $presets = array();

  foreach (flexicolor_get_presets() as $key => $preset) {
    $presets[$preset->machine] = $preset->display_name;
  }

  return $presets;
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
function flexicolor_presets_features_export($data, &$export, $module_name = '') {
  $export['dependencies']['flexicolor'] = 'flexicolor';

  foreach (flexicolor_get_presets() as $key => $preset) {
    if (in_array($preset->machine, $data)) {
      $export['features']['flexicolor_presets'][$preset->machine] = $preset->machine;
    }
    $presets[$preset->machine] = $preset->display_name;
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
function flexicolor_presets_features_export_render($module, $data) {
  $code = array();
  $test_code = array();

  $presets = flexicolor_get_presets();
  $selectors = flexicolor_get_selectors();
  foreach ($data as $name) {
    foreach ($presets as $key => $preset) {
      if($preset->machine == $name) {
        $export_preset = clone $preset;
        unset($export_preset->fpid);
        $export_preset->selectors = array();
        foreach ($selectors as $selector) {
          $preset_selector = flexicolor_get_preset_selector($preset->machine, $selector->machine);
          if (is_object($preset_selector)) {
            $export_preset->selectors[] = $preset_selector;
          }
        }
        $code[$name] = $export_preset;
      }
    }
  }
  $code = "  return " . features_var_export($code, '  ') . ";";
  return array('flexicolor_features_default_presets' => $code);
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
function flexicolor_presets_features_rebuild($module_name) {
  $presets = module_invoke($module_name, 'flexicolor_features_default_presets');
  if (!empty($presets)) {
    foreach ($presets as $preset) {
      $existing_preset = flexicolor_get_preset_by_machine_name($preset['machine']);
      if (is_object($existing_preset)) {
        $preset['fpid'] = $existing_preset->fpid;
      }
      $preset_selectors = $preset['selectors'];
      unset($preset['selectors']);
      flexicolor_save_preset($preset);
      foreach ($preset_selectors as $preset_selector) {
        flexicolor_save_preset_selector($preset_selector['fpmachine'], $preset_selector['fsmachine'], $preset_selector['color'], $preset_selector['machine']);
      }
    }
  }
}

/**
 * Implements hook_features_revert().
 */
function flexicolor_presets_features_revert($module_name) {
  flexicolor_presets_features_rebuild($module_name);
}

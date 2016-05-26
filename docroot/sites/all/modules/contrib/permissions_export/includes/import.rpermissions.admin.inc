<?php

/**
 * @file
 * Import all roles and their associated permissions.
 */

/**
 * Form constructor for import roles permissions.
 *
 * @see permissions_export_rpermissions_import_form_submit()
 */
function permissions_export_rpermissions_import_form($form, &$form_state) {
  if (empty($form_state['storage']['values'])) {
    $form['import_code'] = array(
        '#type' => 'textarea',
        '#title' => t('Import'),
        '#required' => TRUE,
        '#rows' => 15,
        '#description' => t('Paste an exported role(s) and permisiions array structure here.'),
    );

    $override_desc = "If you selected 'Yes', then existing Role(s) Permissions";
    $override_desc .= " will be overidden otherwise process will be skipped.";
    $form['overriden_confirmation'] = array(
        '#type' => 'radios',
        '#title' => t('Confirmation'),
        '#options' => array(1 => t('Yes'), -1 => t('No')),
        '#required' => TRUE,
        '#description' => check_plain($override_desc),
    );
  }

  $form['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Import Roles Permissions'),
  );

  return $form;
}

/**
 * Submit handler to create/update role(s) and their associated permissions.
 */
function permissions_export_rpermissions_import_form_submit($form, &$form_state) {
  $is_updated = array();
  $message = t('No roles/permissions updated.');
  if ($form_state['values']['overriden_confirmation'] == '1') {
    if (empty($form_state['storage']['values'])) {
      $roles = array();
      $string = $form_state['values']['import_code'];

      @eval($string);
      if (is_array($roles)) {
        foreach ($roles as $data) {
          if (isset($data['name']) && $data['name']) {
            $role = user_role_load_by_name($data['name']);

            if (is_object($role) && count($role)) {
              if ($role->rid) {
                $is_updated[$role->rid] = $role->name;
                if (isset($data['permissions']) && is_array($data['permissions'])) {
                  $permissions = _permissions_export_validate_rpermissions($data['permissions']);
                  user_role_grant_permissions($role->rid, $permissions);
                }
              }
            }
            else {
              $role = new stdClass();
              $role->name = $data['name'];
              $rid = user_role_save($role);
              if ($rid) {
                $is_updated[$rid] = $role->name;
                if (isset($data['permissions']) && is_array($data['permissions']) && count($data['permissions']) > 0) {
                  $permissions = _permissions_export_validate_rpermissions($data['permissions']);
                  user_role_grant_permissions($rid, $permissions);
                }
              }
            }
          }
        }
        cache_clear_all('*', 'cache_menu', TRUE);
        $form_state['rebuild'] = TRUE;
      }
    }

    if (count($is_updated)) {
      $message = t("The role(s) '!roles's permissions has has been updated successfully.", array('!roles' => implode(", ", $is_updated)));
    }
  }

  drupal_set_message(check_plain($message));
  drupal_goto('admin/people/export-import-rpermissions');
}

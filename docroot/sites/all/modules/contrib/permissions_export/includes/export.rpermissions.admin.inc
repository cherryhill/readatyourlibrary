<?php

/**
 * @file
 * Export role(s) and their associated permissions.
 */

/**
 * Form constructor for export roles permissions as an array structure.
 *
 * @see permissions_export_rpermissions_export_form_submit()
 * @see permissions_export_rpermissions_export_form_validate()
 * @see _export_import_roles_permissions_get_importable_roles_permissions()
 */
function permissions_export_rpermissions_export_form($form, &$form_state) {
  // A condition to verify form element export_code is empty.
  if (empty($form_state['storage']['values'])) {
    $form['erp'] = array(
    '#tree' => TRUE,
    '#prefix' => '<table><tr bgcolor="#ccc">'
      . '<td width="85%"><b>Role Name</b></td>'
      . '<td width="15%"><b>Action</b></td>',
    '#suffix' => '</tr>',
    );

    $roles = user_roles();
    if (count($roles)) {
      // $counter is used to set the alternate color on extracted rows.
      $counter = 0;
      // Iterate over each roles array.
      foreach ($roles as $rid => $role_name) {
        if (substr($role_name, 0, 11) == '_user_role_') {
          continue;
        }

        $class = 'odd';
        if ($counter % 2 == 0) {
          $class = 'even';
        }

        $form['erp'][$rid]['export'] = array(
          '#type' => 'checkbox',
          '#title' => check_plain($role_name),
          '#prefix' => '<tr class="' . $class . '"><td>',
          '#suffix' => '</td>',
        );

        $edit_link = l(t('Edit role'), 'admin/people/permissions/roles/edit/' . $rid, array('attributes' => array('target' => '_blank')));

        $form['erp'][$rid]['operation'] = array(
          '#type' => 'item',
          '#markup' => $edit_link,
          '#prefix' => '<td>',
          '#suffix' => '</td></tr>',
        );
        $counter++;
      }

      $form['submit'] = array(
        '#type' => 'submit',
        '#value' => t('Export Roles Permissions'),
        '#validate' => array('permissions_export_rpermissions_export_form'),
        '#prefix' => '<tr><td colspan="2">',
        '#suffix' => '</td></tr></table>',
      );
    }
    else {
      $form['erp']['no_role'] = array(
        '#type' => 'item',
        '#markup' => t('No role exists.'),
        '#prefix' => '<tr><td colspan="2">',
        '#suffix' => '</td></tr></table>',
      );
    }
  }
  else {
    // Get Importable array structure as string.
    $export_data = _permissions_export_get_importable_roles_permissions($form_state);

    $export_desc = "For importing copy the content of the text area and paste";
    $export_desc .= " it into the import page.";
    $form['export_code'] = array(
      '#type' => 'textarea',
      '#title' => t('Export'),
      '#default_value' => $export_data,
      '#rows' => 15,
      '#description' => check_plain($export_desc),
    );

    $link = l(t('<< Back'), 'admin/people/export-import-rpermissions');
    $form['back'] = array(
      '#type' => 'item',
      '#markup' => $link,
    );
  }
  return $form;
}

/**
 * Use to validate user must be selected at least one role to export permissios.
 */
function permissions_export_rpermissions_export_form_validate($form, $form_state) {
  $roles = $form_state['values']['erp'];
  $flag = FALSE;
  foreach ($roles as $data) {
    if ($data['export']) {
      $flag = TRUE;
      break;
    }
  }

  if ($flag == FALSE) {
    form_set_error('erp', t('Please select at least one role.'));
  }
}

/**
 * Export an array object of all selected roles and permissions.
 *
 * @return array
 *   Formatted structured array for import.
 */
function _permissions_export_get_importable_roles_permissions($form_state) {
  // Verify that input text area have some code.
  if (!empty($form_state['storage']['values'])) {
    // Get the all the permissions having module name.
    $modules = user_permission_get_modules();
    // Get the roles object data.
    $roles = user_roles();

    $export_data = "\$roles = array();\n";
    // Append the roles array.
    // Iterate for each selected role.
    foreach ($form_state['storage']['values'] as $rid => $storage_data) {
      if ($storage_data['export']) {
        if ($rid) {
          $export_data .= "\$roles[] = array(\n";
          $export_data .= "\t// Create the role if necessary.\n";
          $export_data .= "\t'name' => '" . $roles[$rid] . "',\n";
          $perms = user_role_permissions(array($rid => $rid));
          $export_data .= "\n\t// Append the permissions to the role.\n";
          $export_data .= "\t'permissions' => array(\n";
          $counter = 1;
          foreach ($perms[$rid] as $perm => $val) {
            if (array_key_exists($perm, $modules)) {
              $export_data .= "\t\t'" . $perm . "',";
              if ($counter < count($perms[$rid])) {
                $export_data .= "\n";
              }
              $counter++;
            }
          }
          $export_data .= "\n\t),\n";
          $export_data .= ");\n\n";
        }
      }
    }
    return $export_data;
  }
}

/**
 * Submit handler for to export the roles and their associated permissions.
 */
function permissions_export_rpermissions_export_form_submit($form, &$form_state) {
  if (empty($form_state['storage']['values'])) {
    // If there is no previous values redraw for next step.
    $form_state['storage']['values'] = $form_state['values']['erp'];
    $form_state['rebuild'] = TRUE;
  }
  else {
    // Form is on the next step, process the data here.
  }
}

<?php

// $Id openbadging.admin.inc

/**
 * @file
 * Admin settings of for the openbadging module.
 */

/**
 * Generates the task type editing form.
 */
function openbadging_types_form($form, &$form_state, $openbadging_type, $op = 'edit') {

  if ($op == 'clone') {
    $openbadging_type->label .= ' (cloned)';
    $openbadging_type->type = '';
  }

  $form['label'] = array(
    '#title' => t('Label'),
    '#type' => 'textfield',
    '#default_value' => $openbadging_type->label,
    '#description' => t('The human-readable name of this openbadging type.'),
    '#required' => TRUE,
    '#size' => 30,
  );

  // Machine-readable type name.
  $form['type'] = array(
    '#type' => 'machine_name',
    '#default_value' => isset($openbadging_type->type) ? $openbadging_type->type : '',
    '#maxlength' => 32,
    '#disabled' => $openbadging_type->isLocked() && $op != 'clone',
    '#machine_name' => array(
      'exists' => 'openbadging_types',
      'source' => array('label'),
    ),
    '#description' => t('A unique machine-readable name for this openbadging type. It must only contain lowercase letters, numbers, and underscores.'),
  );

  $form['description'] = array(
    '#type' => 'textarea',
    '#default_value' => isset($openbadging_type->description) ? $openbadging_type->description : '',
    '#description' => t('Description about the openbadging type.'),
  );

  $form['actions'] = array('#type' => 'actions');
  $form['actions']['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Save openbadging type'),
    '#weight' => 40,
  );

  if (!$openbadging_type->isLocked() && $op != 'add' && $op != 'clone') {
    $form['actions']['delete'] = array(
      '#type' => 'submit',
      '#value' => t('Delete openbadging type'),
      '#weight' => 45,
      '#limit_validation_errors' => array(),
      '#submit' => array('openbadging_types_form_submit_delete'),
    );
  }
  return $form;
}

/**
 * Submit handler for creating/editing openbadging_type.
 */
function openbadging_types_form_submit(&$form, &$form_state) {
  $openbadging_type = entity_ui_form_submit_build_entity($form, $form_state);
  // Save and go back.
  openbadging_save($openbadging_type);

  // Redirect user back to list of openbadging types.
  $form_state['redirect'] = 'admin/structure/openbadging';
}

/**
 * Function for delete openbadging types 
 */
function openbadging_types_form_submit_delete(&$form, &$form_state) {
  $form_state['redirect'] = 'admin/structure/openbadging/' . $form_state['openbadging_types']->type . '/delete';
}

/**
 * openbadging type delete form.
 */
function openbadging_types_form_delete_confirm($form, &$form_state, $openbadging_type) {
  $form_state['openbadging_types'] = $openbadging_type;
  // Always provide entity id in the same form key as in the entity edit form.
  $form['openbadging_types_id'] = array('#type' => 'value',
    '#value' => entity_id('openbadging_types', $openbadging_type),
  );
  return confirm_form($form, t('Are you sure you want to delete openbadging type %title?', array('%title' => entity_label('openbadging_types', $openbadging_type))), 'openbadging/' . entity_id('openbadging_types', $openbadging_type), t('This action cannot be undone.'), t('Delete'), t('Cancel')
  );
}

/**
 * openbadging type delete form submit handler.
 */
function openbadging_types_form_delete_confirm_submit($form, &$form_state) {
  $openbadging_type = $form_state['openbadging_types'];
  openbadging_types_delete($openbadging_type);

  watchdog('openbadging_types', '@type: deleted %title.', array('@type' => $openbadging_type->type, '%title' => $openbadging_type->label));
  drupal_set_message(t('@type %title has been deleted.', array('@type' => $openbadging_type->type, '%title' => $openbadging_type->label)));

  $form_state['redirect'] = 'admin/structure/openbadging';
}

/**
 * Page to select openbadging Type to add new openbadging.
 */
function openbadging_admin_add_page() {
  $items = array();
  foreach (openbadging_types() as $openbadging_types_key => $openbadging_types) {
    $items[] = l(entity_label('openbadging_types', $openbadging_types), 'openbadging/add/' . $openbadging_types_key);
  }
  return array('list' => array('#theme' => 'item_list',
      '#items' => $items,
      '#title' => t('Select type of openbadging to create.'),
    ));
}

/**
 * Add new openbadging page callback.
 */
function openbadging_add($type) {
  $openbadging_types = openbadging_types($type);

  $openbadging = entity_create('openbadging', array('type' => $type));
  drupal_set_title(t('Create @name', array('@name' => entity_label('openbadging_types', $openbadging_types))));

  $output = drupal_get_form('openbadging_form', $openbadging);

  return $output;
}

/**
 * openbadging Form.
 */
function openbadging_form($form, &$form_state, $openbadging) {
  $form_state['openbadging'] = $openbadging;

  $form['title'] = array(
    '#type' => 'textfield',
    '#required' => TRUE,
    '#title' => t('Title'),
    '#default_value' => $openbadging->title,
  );
  $form['status'] = array(
    '#type' => 'checkbox',
    '#default_value' => $openbadging->status,
    '#title' => t('Mark as Approved'),
    '#weight' => 99,
  );
  /* $form['description'] = array(
    '#type' => 'textarea',
    '#title' => t('Description'),
    '#default_value' => $openbadging->description,
    ); */

  $form['uid'] = array(
    '#type' => 'value',
    '#value' => $openbadging->uid,
  );
  field_attach_form('openbadging', $openbadging, $form, $form_state);

  $submit = array();
  if (!empty($form['#submit'])) {
    $submit += $form['#submit'];
  }

  $form['actions'] = array(
    '#weight' => 100,
  );

  $form['actions']['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Save'),
    '#submit' => $submit + array('openbadging_form_submit'),
  );

  // Show Delete button if we edit openbadging.
  $openbadging_id = entity_id('openbadging', $openbadging);
  if (!empty($openbadging_id) && openbadging_access('edit', $openbadging)) {
    $form['actions']['delete'] = array(
      '#type' => 'submit',
      '#value' => t('Delete'),
      '#submit' => array('openbadging_form_submit_delete'),
    );
  }

  $form['#validate'][] = 'openbadging_form_validate';

  return $form;
}

/*
 * Implementation of form validation 
 */

function openbadging_form_validate($form, &$form_state) {
  
}

/**
 * openbadging submit handler.
 * @param array $form
 * @param array $form_state
 */
function openbadging_form_submit($form, &$form_state) {
  $openbadging = $form_state['openbadging'];

  entity_form_submit_build_entity('openbadging', $openbadging, $form, $form_state);

  openbadging_save($openbadging);

  $openbadging_uri = entity_uri('openbadging', $openbadging);

  $form_state['redirect'] = $openbadging_uri['path'];

  drupal_set_message(t('Openbadging %title saved.', array('%title' => entity_label('openbadging', $openbadging))));
}

/**
 * function call on deleting openbadging entity
 * @param array $form
 * @param array $form_state 
 */
function openbadging_form_submit_delete($form, &$form_state) {
  $openbadging = $form_state['openbadging'];
  $openbadging_uri = entity_uri('openbadging', $openbadging);
  $form_state['redirect'] = $openbadging_uri['path'] . '/delete';
}

/**
 * Delete confirmation form.
 * @param array $form
 * @param array $form_state
 * @param type $openbadging
 * @return array
 */
function openbadging_delete_form($form, &$form_state, $openbadging) {
  $form_state['openbadging'] = $openbadging;
  // Always provide entity id in the same form key as in the entity edit form.
  $form['openbadging_type_id'] = array('#type' => 'value',
    '#value' => entity_id('openbadging', $openbadging));
  $openbadging_uri = entity_uri('openbadging', $openbadging);
  return confirm_form($form, t('Are you sure you want to delete openbadging %title?', array('%title' => entity_label('openbadging', $openbadging))), $openbadging_uri['path'], t('This action cannot be undone.'), t('Delete'), t('Cancel')
  );
}

/**
 * Delete form submit handler.
 */
function openbadging_delete_form_submit($form, &$form_state) {
  $openbadging = $form_state['openbadging'];
  openbadging_delete($openbadging);
  drupal_set_message(t('openbadging %title deleted.', array('%title' => entity_label('openbadging', $openbadging))));
  $form_state['redirect'] = '<front>';
}

/**
 * Menu callback: content administration.
 */
function openbadging_admin_content($form, $form_state) {
  if (isset($form_state['values']['operation']) && $form_state['values']['operation'] == 'delete') {
    return openbadging_types_form_delete($form, $form_state, array_filter($form_state['values']['nodes']));
  }
  $form['filter'] = openbadging_filter_form();
  $form['#submit'][] = 'openbadging_filter_form_submit';
  $form['admin'] = openbadging_admin_openbadgings();
  return $form;
}

/**
 * Return form for openbadging administration filters.
 */
function openbadging_filter_form() {
  $session = isset($_SESSION['node_overview_filter']) ? $_SESSION['node_overview_filter'] : array();
  $filters = openbadging_filters();
  $i = 0;
  $form['filters'] = array(
    '#type' => 'fieldset',
    '#title' => t('Show only items where'),
    '#theme' => 'exposed_filters__node',
  );
  foreach ($session as $filter) {
    list($type, $value) = $filter;
    $value = $filters[$type]['options'][$value];
    $t_args = array('%property' => $filters[$type]['title'], '%value' => $value);
    $form['filters']['current'][] = array('#markup' => t('where %property is %value', $t_args));
    if (in_array($type, array('type'))) {
      // Remove the option if it is already being filtered on.
      unset($filters[$type]);
    }
  }

  $form['filters']['status'] = array(
    '#type' => 'container',
    '#attributes' => array('class' => array('clearfix')),
    '#prefix' => ($i ? '<div class="additional-filters">' . t('and where') . '</div>' : ''),
  );
  $form['filters']['status']['filters'] = array(
    '#type' => 'container',
    '#attributes' => array('class' => array('filters')),
  );
  foreach ($filters as $key => $filter) {

    $form['filters']['status']['filters'][$key] = array(
      '#type' => 'select',
      '#options' => $filter['options'],
      '#title' => $filter['title'],
      '#default_value' => '[any]',
    );
  }


  $form['filters']['status']['actions'] = array(
    '#type' => 'actions',
    '#attributes' => array('class' => array('container-inline')),
  );
  $form['filters']['status']['actions']['submit'] = array(
    '#type' => 'submit',
    '#value' => count($session) ? t('Reset') : t('Filter'),
  );
  drupal_add_js('misc/form.js');

  return $form;
}

/**
 * Process result from node administration filter form.
 */
function openbadging_filter_form_submit($form, &$form_state) {
  $filters = openbadging_filters();
  switch ($form_state['values']['op']) {
    case t('Filter'):
      // Apply every filter that has a choice selected other than 'any'.
      foreach ($filters as $filter => $options) {
        if (isset($form_state['values'][$filter]) &&
          $form_state['values'][$filter] != '[any]') {
          // Flatten the options array to accommodate 
          // hierarchical/nested options.
          $flat_options = form_options_flatten($filters[$filter]['options']);
          // Only accept valid selections offered on the dropdown, block bad input.
          if (isset($flat_options[$form_state['values'][$filter]])) {
            $_SESSION['node_overview_filter'][] = array($filter, $form_state['values'][$filter]);
          }
        }
      }
      break;
    case t('Reset'):
      $_SESSION['node_overview_filter'] = array();
      break;
  }
}

/**
 * List openbadging administration filters that can be applied.
 */
function openbadging_filters() {
  $filters['type'] = array(
    'title' => t('type'),
    'options' => array(
    '[any]' => t('any'),
    ) + openbadging_type_get_names(),
  );
  $filters['status'] = array(
    'title' => t('status'),
    'options' => array(
      '[any]' => t('any'),
      'status-1' => t('published'),
      'status-0' => t('not published'),
    ),
  );
  return $filters;
}

/**
 * Form builder: Builds the node administration overview.
 */
function openbadging_admin_openbadgings() {
  $admin_access = user_access('administer nodes');
  // Build the 'Update options' form.
  $form['options'] = array(
    '#type' => 'fieldset',
    '#title' => t('Update options'),
    '#attributes' => array('class' => array('container-inline')),
    '#access' => $admin_access,
  );
  $options = array();
  foreach (module_invoke_all('openbadging_operations') as $operation => $array) {
    $options[$operation] = $array['label'];
  }
  $form['options']['operation'] = array(
    '#type' => 'select',
    '#title' => t('Operation'),
    '#title_display' => 'invisible',
    '#options' => $options,
    '#default_value' => 'approve',
  );
  $form['options']['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Update'),
    '#validate' => array('openbadging_admin_openbadgings_validate'),
    '#submit' => array('openbadging_admin_openbadgings_submit'),
  );
  // Enable language column if translation module is enabled
  // or if we have any node with language.
  // Build the sortable table header.
  $header = array(
    'title' => array('data' => t('Title'), 'field' => 'n.title'),
    'type' => array('data' => t('Type'), 'field' => 'n.type'),
    'author' => t('Author'),
    'changed' => array('data' => t('Updated'),
      'field' => 'n.changed',
      'sort' => 'desc'),
  );
  $header['operations'] = array('data' => t('Operations'));
  $query = db_select('openbadging', 'n')->extend('PagerDefault')->extend('TableSort');
  openbadging_build_filter_query($query);
  if (!user_access('bypass node access')) {
    // If the user is able to view their own unpublished nodes, allow them
    // to see these in addition to published nodes. Check that they actually
    // have some unpublished nodes to view before adding the condition.
    if (user_access('view own unpublished content') && $own_unpublished = db_query('SELECT bid FROM {openbadging} WHERE uid = :uid', array(':uid' => $GLOBALS['user']->uid))->fetchCol()) {
      $query
        ->condition('n.bid', $own_unpublished, 'IN');
    }
  }
  $bids = $query
    ->fields('n', array('bid'))
    ->limit(50)
    ->orderByHeader($header)
    ->execute()
    ->fetchCol();
  $openbadgings = openbadging_load_multiple($bids);
  // Prepare the list of nodes.
  $destination = drupal_get_destination();
  $options = array();
  foreach ($openbadgings as $openbadging) {
    $account = user_load($openbadging->uid, $reset = FALSE);
    $options[$openbadging->bid] = array(
      'title' => array(
        'data' => array(
          '#type' => 'link',
          '#title' => $openbadging->title,
          '#href' => 'openbadging/' . $openbadging->bid,
          '#suffix' => ' ' . theme('mark', array('type' => openbadging_mark($openbadging->bid, $openbadging->changed))),
        ),
      ),
      'type' => openbadging_type_get_name($openbadging),
      'author' => theme('username', array('account' => $account)),
      'changed' => format_date($openbadging->changed, 'short'),
    );
    // Build a list of all the accessible operations for the current node.
    $operations = array();
    $operations['edit'] = array(
      'title' => t('edit'),
      'href' => 'openbadging/' . $openbadging->bid . '/edit',
      'query' => $destination,
    );
    $operations['delete'] = array(
      'title' => t('delete'),
      'href' => 'openbadging/' . $openbadging->bid . '/delete',
      'query' => $destination,
    );
    $options[$openbadging->bid]['operations'] = array();
    if (count($operations) > 1) {
      // Render an unordered list of operations links.
      $options[$openbadging->bid]['operations'] = array(
        'data' => array(
          '#theme' => 'links__node_operations',
          '#links' => $operations,
          '#attributes' => array('class' => array('links', 'inline')),
        ),
      );
    } elseif (!empty($operations)) {
      // Render the first and only operation as a link.
      $link = reset($operations);
      $options[$openbadging->bid]['operations'] = array(
        'data' => array(
          '#type' => 'link',
          '#title' => $link['title'],
          '#href' => $link['href'],
          '#options' => array('query' => $link['query']),
        ),
      );
    }
  }
  // Only use a tableselect when the current user is able to perform any
  // operations.
  if ($admin_access) {
    $form['nodes'] = array(
      '#type' => 'tableselect',
      '#header' => $header,
      '#options' => $options,
      '#empty' => t('No content available.'),
    );
  }
  // Otherwise, use a simple table.
  else {
    $form['nodes'] = array(
      '#theme' => 'table',
      '#header' => $header,
      '#rows' => $options,
      '#empty' => t('No content available.'),
    );
  }
  $form['pager'] = array('#markup' => theme('pager'));
  return $form;
}

/**
 * Validate openbadging_admin_openbadgings form submissions.
 * Check if any openbadging have been selected to perform the chosen
 */
function openbadging_admin_openbadgings_validate($form, &$form_state) {
  // Error if there are no items to select.
  if (!is_array($form_state['values']['nodes']) || !count(array_filter($form_state['values']['nodes']))) {
    form_set_error('', t('No items selected.'));
  }
}

/**
 * Execute the chosen 'Update option' on the selected openbadgings.
 */
function openbadging_admin_openbadgings_submit($form, &$form_state) {
  $operations = module_invoke_all('openbadging_operations');
  $operation = $operations[$form_state['values']['operation']];
  // Filter out unchecked nodes.
  $openbadgings = array_filter($form_state['values']['nodes']);
  if ($function = $operation['callback']) {
    // Add in callback arguments if present.
    if (isset($operation['callback arguments'])) {
      $args = array_merge(array($openbadgings), $operation['callback arguments']);
    } else {
      $args = array($openbadgings);
    }
    call_user_func_array($function, $args);

    cache_clear_all();
  } else {
    // We need to rebuild the form to go to a second step. For example, to
    // show the confirmation form for the deletion of nodes.
    $form_state['rebuild'] = TRUE;
  }
}

/**
 * Implements hook_openbadging_operations().
 */
function openbadging_openbadging_operations() {
  $operations = array(
    'delete' => array(
      'label' => t('Delete selected content'),
      'callback' => NULL,
    ),
    'publish' => array(
      'label' => t('Mark as Approved selected content'),
      'callback' => 'openbadging_mass_update',
      'callback arguments' => array('updates' => array('status' => NODE_PUBLISHED)),
    ),
    'unpublish' => array(
      'label' => t('Mark as Unapproved selected content'),
      'callback' => 'openbadging_mass_update',
      'callback arguments' => array('updates' => array('status' => NODE_NOT_PUBLISHED)),
    ),
  );
  return $operations;
}

/**
 * openbadgings type delete form.
 */
function openbadging_types_form_delete($form, &$form_state, $openbadgings) {
  $form['nodes'] = array('#prefix' => '<ul>',
    '#suffix' => '</ul>',
    '#tree' => TRUE);
  // Array_filter returns only elements with TRUE values.
  foreach ($openbadgings as $bid => $value) {
    $title = db_query('SELECT title FROM {openbadging} WHERE bid = :bid', array(':bid' => $bid))->fetchField();
    $form['nodes'][$bid] = array(
      '#type' => 'hidden',
      '#value' => $bid,
      '#prefix' => '<li>',
      '#suffix' => check_plain($title) . "</li>\n",
    );
  }
  $form['operation'] = array('#type' => 'hidden', '#value' => 'delete');
  $form['#submit'][] = 'openbadging_multiple_delete_submit';
  $confirm_question = format_plural(count($openbadgings), 'Are you sure you want to delete this item?', 'Are you sure you want to delete these items?');
  return confirm_form($form, $confirm_question, 'admin/content', t('This action cannot be undone.'), t('Delete'), t('Cancel'));
}

/**
 * openbadging type delete multiple submit form.
 */
function openbadging_multiple_delete_submit($form, &$form_state) {
  if ($form_state['values']['confirm']) {
    openbadging_delete_multiple(array_keys($form_state['values']['nodes']));
    $count = count($form_state['values']['nodes']);
    watchdog('content', 'Deleted @count posts.', array('@count' => $count));
    drupal_set_message(format_plural($count, 'Deleted 1 post.', 'Deleted @count posts.'));
  }
  $form_state['redirect'] = 'admin/structure/openbadging/content';
}

/**
 * Apply filters for openbadging administration filters based on session.
 * @param SelectQueryInterface $query
 * A SelectQuery to which the filters should be applied.
 */
function openbadging_build_filter_query(SelectQueryInterface $query) {
  // Build query.
  $filter_data = isset($_SESSION['node_overview_filter']) ? $_SESSION['node_overview_filter'] : array();
  foreach ($filter_data as $index => $filter) {
    list($key, $value) = $filter;
    switch ($key) {
      case 'status':
        // Note: no exploitable hole as $key/$value have already been checked when submitted
        list($key, $value) = explode('-', $value, 2);
      case 'type':
        $query->condition('n.' . $key, $value);
        break;
    }
  }
}

/**
 * 
 * @param unknown_type $openbadging
 * @param unknown_type $updates
 */
function openbadging_mass_update($openbadging, $updates) {
  foreach ($openbadging as $bid) {
    _openbadging_mass_update_helper($bid, $updates);
  }
  drupal_set_message(t('The update has been performed.'));
}

/**
 * Node Mass Update - helper function.
 */
function _openbadging_mass_update_helper($bid, $updates) {
  $entity = entity_load('openbadging', array($bid));
  $key = key($entity);
  // For efficiency manually save the original node before applying any changes.
  foreach ($updates as $name => $value) {
    db_update('openbadging')->fields(array('status' => $value))
      ->condition('bid', $key)->execute();
    module_invoke_all('openbadging_update_status', $entity, $value);
  }
  return $entity;
}

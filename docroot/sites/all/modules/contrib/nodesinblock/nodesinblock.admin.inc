<?php
// $Id: nodesinblock.admin.inc,v 1.1.2.23.2.6 2010/10/30 16:19:05 swentel Exp $

/**
 * @file
 * Administration page for nodes in block.
 */

/**
 * Menu callback to configure general settings for nodes in block.
 */
function nodesinblock_settings() {
  $form = array();
  $content_types = node_type_get_names();
  $saved_types = variable_get('nodesinblock_contenttypes', array());

  $form['nodesinblock'] = array(
    '#type' => 'fieldset',
    '#title' => t('General settings'),
    '#description' => t('Select number of blocks to create and associate content types which nodes can be used to insert as content in a block. When you change the number, be sure to goto the <a href="@url">block configuration</a> page so the block settings are updated in the database. When at least one content type is selected, two fieldsets will become available after clicking the submit button where you can change general settings and associate content types per block.', array('@url' => url('admin/build/block'))),
  );
  $form['nodesinblock']['nodesinblock_nrofblocks'] = array(
    '#type' => 'select',
    '#title' => t('Total number of blocks'),
    '#options' => drupal_map_assoc(array(1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15)),
    '#default_value' => variable_get('nodesinblock_nrofblocks', 1),
  );
  $form['nodesinblock']['nodesinblock_contenttypes'] = array(
    '#type' => 'checkboxes',
    '#title' => t('Content types'),
    '#options' =>  $content_types,
    '#default_value' => $saved_types,
  );
  $form['nodesinblock']['nodesinblock_referer'] = array(
    '#type' => 'checkbox',
    '#title' => t('Use the referring page as the default value for <em>visibility</em> at the content node form'),
    '#default_value' => variable_get('nodesinblock_referer', FALSE),
    '#prefix' => '<strong>'. t('Creating and modifying blocks') .':</strong>',
  );

  // Settings per block & content type.
  if (!empty($saved_types)) {

    $form['general_settings'] = array(
      '#type' => 'fieldset',
      '#title' => t('Settings per block'),
      '#description' => t('Note: if you set the visibility setting for the block as "<em>Show on every page except the listed pages</em>", multiple paths will not work correct because of the way that Drupal core block visibility works. You\'ll be better off choosing the default option. ')
    );

    for ($i = 0, $a = 1; $i < variable_get('nodesinblock_nrofblocks', 1); $i++, $a++) {
      $form['general_settings']['nodesinblock_friendlyname_' . $i] = array(
        '#type' => 'textfield',
        '#title' => t('User friendly name for block') . ' ' . $a,
        '#default_value' => check_plain(variable_get('nodesinblock_friendlyname_' . $i, t('Nodes in block ' . $a))),
        '#description' => t('Only use alphanumeric characters.'),
      );
      $form['general_settings']['nodesinblock_visibility_' . $i] = array(
        '#type' => 'select',
        '#title' => t('Visibility settings for block') . ' ' . $a,
        '#options' => array(
          t('Show on every page except the listed pages.'),
          t('Show on only the listed pages.')
        ),
        '#default_value' => variable_get('nodesinblock_visibility_' . $i, '1'),
      );
    }

    $blocks = module_invoke('nodesinblock', 'block_info');
    $block_options = array();
    $a = 1;
    foreach ($blocks as $key => $value) {
      $block_options[$a] = $value['info'];
      $a++;
    }

    $form['contenttypes_block'] = array(
      '#type' => 'fieldset',
      '#title' => t('Settings per content type'),
      '#description' => t('Define per content type which blocks are available. On the content node form, a select box will be available to select the appropriate block where the node content must be displayed. You can also choose the label of the fieldset and if it is collapsible and/or collapsed by default. You can set a default render mode for the node. If you choose one, the select box on the node form will be hidden.'),
    );

    // Iterate over selected types
    foreach ($saved_types as $key => $value) {
      if ($value != '0') {
        $form['contenttypes_block']['nodesinblock_' . $key . '_block'] = array(
          '#type' => 'checkboxes',
          '#title' => t('Blocks'),
          '#options' => $block_options,
          '#default_value' => variable_get('nodesinblock_' . $key . '_block', array()),
          '#prefix' => '<div style="float: left; padding:5px; margin: 10px 5px 10px 0px; border: 1px solid #cccccc;"> <strong>' . t('Configure @key', array('@key' => $key)) . '</strong>',
        );

        $form['contenttypes_block']['nodesinblock_' . $key . '_label'] = array(
          '#type' => 'textfield',
          '#title' => t('Fieldset label'),
          '#default_value' => check_plain(variable_get('nodesinblock_' . $key . '_label', t('Nodes in block'))),
          '#size' => 20,
        );
        $form['contenttypes_block']['nodesinblock_' . $key . '_collapsed'] = array(
          '#type' => 'checkbox',
          '#title' => t('Collapsed fieldset'),
          '#default_value' => variable_get('nodesinblock_' . $key . '_collapsed', TRUE),
        );
        $form['contenttypes_block']['nodesinblock_' . $key . '_collapsible'] = array(
          '#type' => 'checkbox',
          '#title' => t('Collapsible fieldset'),
          '#default_value' => variable_get('nodesinblock_' . $key . '_collapsible', TRUE),
        );
        $options = array(0 => t('Let the user decide'));
        $options += _nodesinblock_render_options();
        $form['contenttypes_block']['nodesinblock_' . $key . '_render'] = array(
          '#type' => 'select',
          '#title' => t('Render mode'),
          '#default_value' => variable_get('nodesinblock_' . $key . '_render', 0),
          '#options' => $options,
          '#suffix' => '</div>',
        );
      }
    }
  }

  // Don't use system_settings_form because we want
  // to have a warning screen when clearing configuration.
  $form['buttons']['submit'] = array(
    '#value' => t('Save configuration'),
    '#type' => 'submit',
    '#submit' => array('nodesinblock_settings_save')
  );
  $form['buttons']['reset'] = array(
    '#value' => t('Clear configuration'),
    '#type' => 'submit',
    '#submit' => array('nodesinblock_settings_clear_redirect')
  );
  return $form;
}

/**
 * Submit callback: save settings.
 * We use parts of system_settings_submit here to save the variables.
 */
function nodesinblock_settings_save($form, &$form_state) {
  // Exclude unnecessary elements.
  unset($form_state['values']['submit'], $form_state['values']['reset'], $form_state['values']['form_id'], $form_state['values']['op'], $form_state['values']['form_token'], $form_state['values']['form_build_id']);

  foreach ($form_state['values'] as $key => $value) {
    if (is_array($value) && isset($form_state['values']['array_filter'])) {
      $value = array_keys(array_filter($value));
    }
    variable_set($key, $value);
  }

  drupal_set_message(t('The configuration options have been saved.'));
  cache_clear_all();
}

/**
 * Submit callback: clear settings, simply redirects to confirmation page.
 */
function nodesinblock_settings_clear_redirect($form, &$form_state) {
  $form_state['redirect'] = 'admin/config/nodesinblock/clear';
}

/**
 * Menu callback: show confirmation screen to clear nodes in block settings.
 */
function nodesinblock_settings_clear_confirm() {
  $form = array();
  return confirm_form(
    $form,
    t('Do you want to clear the settings for nodes in block?'),
    'admin/config/nodesinblock',
    t('Warning, you will loose all settings including all entries in the nodesinblock table and the blocks generated by your previous configuration.'),
    t('Clear configuration'), t('Cancel')
  );
}

/**
 * Submit callback: clear nodes in block settings.
 */
function nodesinblock_settings_clear_confirm_submit($form, &$form_state) {
  db_delete('variable')
    ->condition('name', 'nodesinblock_%', 'LIKE')
    ->execute();
  db_delete('blocks')
    ->condition('module', 'nodesinblock', '=')
    ->execute();
  db_truncate('nodesinblock')->execute();
  cache_clear_all('variables', 'cache');
  drupal_set_message(t('All nodes in block settings have been cleared'));
  $form_state['redirect'] = 'admin/config/nodesinblock';
}

/**
 * Menu callback to look at the queue for nodes in block.
 *
 * @param $block
 *   The delta of the block.
 * @param $show_block_links
 *   Whether to render the blocklinks or not.
 * @param $show_create_links
 *   Whether to render the create node links or not.
 */
function nodesinblock_queue($form, &$form_state, $block = NULL, $show_block_links = TRUE, $show_create_links = TRUE) {
  $form = array();
  $form['nodes'] = array('#tree' => TRUE);

  $number_of_blocks = variable_get('nodesinblock_nrofblocks', 1);
  if ($block == NULL) $block = 0;

  // Blocklinks.
  if ($show_block_links == TRUE) {
    $blocklinks = array();
    for ($i = 0, $a = 1; $i < $number_of_blocks; $i++, $a++) {
      $title = check_plain(variable_get('nodesinblock_friendlyname_' . $i, t('Nodes in block ' . $a)));
      $delta = ($i != '0') ? '/' . $i : '';
      $blocklinks[] = array(
        'title' => $title,
        'href' => 'admin/config/nodesinblock/queue' . $delta
      );
    }
    $form['blocklinks'] = array('#type' => 'item', '#value' => theme('links', $blocklinks));
  }

  // Content create links.
  if ($show_create_links == TRUE) {
    $createlinks = array();
    $saved_delta = $block + 1;
    $saved_types = variable_get('nodesinblock_contenttypes', array());
    foreach ($saved_types as $type) {
      $deltas = variable_get('nodesinblock_' . $type . '_block', array());
      if (isset($deltas[$saved_delta]) && $deltas[$saved_delta] != 0) {
        $createlinks[] = array(
          'title' => t('Create new @type', array('@type' => $type)),
          'href' => 'node/add/' . $type,
        );
      }
    }
    $form['createlinks'] = array('#type' => 'item', '#value' => theme('links', $createlinks));
  }

  // Get nodes and store them in #nodes key.
  $query = db_select('nodesinblock', 'nib');
  $query->join('node', 'n', 'nib.nid = n.nid');
  $query->fields('nib', array('nid', 'visibility', 'render', 'weight'));
  $query->fields('n', array('title', 'status'))
    ->condition('delta', $block)
    ->orderBy('weight', 'ASC');

  $results = $query->execute()->fetchAll();

  foreach ($results as $row) {
    $form['nodes'][$row->nid]['nid'] = array(
      '#type' => 'value',
      '#value' => $row->nid,
    );
    $form['nodes'][$row->nid]['title'] = array(
      '#markup' => check_plain($row->title),
    );
    $form['nodes'][$row->nid]['node_status'] = array(
      '#markup' => ($row->status == 1) ? t('published') : t('unpublished'),
    );
    $form['nodes'][$row->nid]['visibility'] = array(
      '#markup' => htmlentities($row->visibility),
    );
    $form['nodes'][$row->nid]['weight'] = array(
      '#type' => 'weight',
      '#default_value' => $row->weight,
      '#delta' => 30,
    );
  }

  // Block delta
  $form['delta'] = array('#type' => 'value', '#value' => $block);

  // Save button.
  $form['submit'] = array('#type' => 'submit', '#value' => t('Save'));
  return $form;
}

/**
 * Submit callback, save weights after queue submit.
 */
function nodesinblock_queue_submit($form, &$form_state) {
  foreach ($form_state['values']['nodes'] as $node) {
    db_update('nodesinblock')
      ->condition('delta', $form_state['values']['delta'])
      ->condition('nid', $node['nid'])
      ->fields(array(
        'weight' => $node['weight'],
      ))
      ->execute();
  }
}

/**
 * Theme queue form.
 */
function theme_nodesinblock_queue($variables) {
  $output = '';
  $rows = array();
  $form = $variables['form'];

  foreach (element_children($form['nodes']) as $nid) {
    $element = &$form['nodes'][$nid];

    $element['weight']['#attributes']['class'] = array('nodes-weight');

    $row = array();
    $row[] = drupal_render($element['title']);
    $row[] = drupal_render($element['node_status']);
    $row[] = drupal_render($element['visibility']);
    $row[] = drupal_render($element['weight']);
    $row[] = l(t('View'), 'node/' . $nid) . ' - ' . l(t('Edit'), 'node/' . $nid . '/edit', array('query' => drupal_get_destination()));

    $row = array_merge(array('data' => $row), array());
    $row['class'][] = 'draggable';
    $rows[] = $row;
  }

  if (isset($form['blocklinks']))
  $output .= drupal_render($form['blocklinks']);
  if (isset($form['createlinks']))
  $output .= drupal_render($form['createlinks']);

  if ($rows) {

    drupal_add_tabledrag('nodesinblock', 'order', 'sibling', 'nodes-weight');

    $header = array(
      t('Title'),
      t('Node status'),
      t('Visibility'),
      t('Weight'),
      t('Operations'),
    );
    $output .= theme('table', array('header' => $header, 'rows' => $rows, 'attributes' => array('id' => 'nodesinblock')));
    $output .= drupal_render_children($form);
  }
  else {
    $output .= t('No nodes found.');
  }

  return $output;
}


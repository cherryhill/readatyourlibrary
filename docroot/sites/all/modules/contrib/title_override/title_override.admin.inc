<?php
/**
 * @file
 * Admin page implementations for Title Override.
 */

/**
 * Provides administration overview page for Title override
 *
 * @return Ambigous <An, string>
 */
function title_override_config_overview() {
  $contexts = context_enabled_contexts(TRUE);
  $header = array(t('Name'), t('Paths'), t('Operations'));
  $rows = array();

  foreach ($contexts as $name => $context) {
    // Show only contexts that have title_override reaction and paths conditions.
    if (isset($context->reactions['title_override']['admin']) &&  $context->reactions['title_override']['admin'] && isset($context->conditions['path']['values'])) {
      $ops = array(
        l('Edit', 'admin/config/user-interface/to_titles/'.$context->name, array('query' => array('destination' => 'admin/config/user-interface/to_titles'))),
        l('Delete', 'admin/config/user-interface/to_titles/'.$context->name . '/delete', array('query' => array('destination' => 'admin/config/user-interface/to_titles'))),
      );
      $rows[] = array(
          $context->name,
          htmlentities(implode(', ', $context->conditions['path']['values'])),
          implode(' | ', $ops),
      );
    }
  }
  return theme('table', array('header' => $header, 'rows' => $rows));
}

/**
 * Provides form for adding context name for Title override
 *
 * @param unknown_type $form
 * @param unknown_type $form_state
 * @return multitype:string Ambigous <string, unknown> Ambigous <The, string, A, Optional>
 */
function title_override_config_add_form($form, &$form_state) {
  $form['name'] = array(
    '#title' => 'Name',
    '#type' => 'textfield',
    '#default_value' => '',
    '#description' => 'The unique ID for this metatag path context rule. This must contain only lower case letters, numbers and underscores.',
    '#required' => 1,
    '#maxlength' => 255,
    '#element_validate' => Array('title_override_edit_name_validate'),
  );

  $form['actions']['#type'] = 'actions';
  $form['actions']['save'] = array(
    '#type' => 'submit',
    '#value' => t('Add and configure'),
  );
  $form['actions']['cancel'] = array(
    '#type' => 'link',
    '#title' => t('Cancel'),
    '#href' => isset($_GET['destination']) ? $_GET['destination'] : 'admin/config/user-interface/to_titles',
  );
  return $form;
}

/**
 * Validates context name.
 *
 * @param unknown_type $element
 * @param unknown_type $form_state
 */
function title_override_edit_name_validate($element, &$form_state) {
  // Check for string identifier sanity
  if (!preg_match('!^[a-z0-9_-]+$!', $element['#value'])) {
    form_error($element, t('The name can only consist of lowercase letters, underscores, dashes, and numbers.'));
    return;
  }

  // Ensure the CTools exportables system is loaded.
  ctools_include('export');

  // Check for name collision
  if ($exists = ctools_export_crud_load('context', $element['#value'])) {
    form_error($element, t('A context with this name already exists. Please choose another name or delete the existing item before creating a new one.'));
  }
}

/**
 * Creates default context for title overrides with submitted name.
 *
 * @param unknown_type $form
 * @param unknown_type $form_state
 */
function title_override_config_add_form_submit($form, &$form_state) {
  $context = title_override_load_default_context();
  $context->name = $form_state['values']['name'];
  context_save($context);
  $form_state['redirect'] = 'admin/config/user-interface/to_titles/'.$context->name;
}

/**
 *
 * Provides form for overriding H1 titles
 *
 * @param unknown_type $form
 * @param unknown_type $form_state
 * @param unknown_type $context
 */
function title_override_config_edit_form($form, &$form_state, $context) {
  $form_state['to_title_override']['context'] = $context;
  $form = array();
  $form['paths'] = array(
    '#title' => 'Path',
    '#description' => 'Set this title context when any of the paths above match the page path. Put each path on a separate line. You can use the <code>*</code> character (asterisk) as a wildcard and the <code>~</code> character (tilde) to exclude one or more paths. Use &lt;front&gt; for the site front page.',
    '#type' => 'textarea',
    '#default_value' => isset($context->conditions['path']['values']) ? html_entity_decode(implode('&#13;&#10;', $context->conditions['path']['values'])) : '',
    '#required' => 1,
    '#weight' => -100,
  );

  $form['title'] = array(
    '#title' => t('Title tag'),
    '#description' => t('Overrides the H1 title'),
    '#type' => 'textfield',
    '#maxlength' => 400,
    '#default_value' => isset($context->reactions['title_override']['title']) ? $context->reactions['title_override']['title'] : '',
  );

  $form['actions']['#type'] = 'actions';
  $form['actions']['save'] = array(
    '#type' => 'submit',
    '#value' => t('Save'),
  );
  $form['actions']['cancel'] = array(
    '#type' => 'submit',
    '#value' => t('Cancel'),
    '#submit' => array('title_override_config_edit_form_cancel_submit'),
    '#limit_validation_errors' => array(),
  );
  $form['#submit'][] = 'title_override_config_edit_form_submit';

  return $form;
}

/**
 *
 * @param unknown_type $form
 * @param unknown_type $form_state
 */
function title_override_config_edit_form_cancel_submit($form, &$form_state) {
  context_delete($form_state['to_title_override']['context']);
  $form_state['redirect'] = 'admin/config/user-interface/to_titles';
}

/**
 *
 * @param unknown_type $form
 * @param unknown_type $form_state
 */
function title_override_config_edit_form_submit($form, &$form_state) {
  $context = $form_state['to_title_override']['context'];
  $context->reactions['title_override']['title'] =  $form_state['values']['title'];
  $paths = explode("\n", str_replace("\r", "", $form_state['values']['paths']));
  $paths = array_combine($paths, $paths);
  $context->conditions['path']['values'] = $paths;
  context_save($context);
  $form_state['redirect'] = 'admin/config/user-interface/to_titles';
}

/**
 *
 * @param unknown_type $form
 * @param unknown_type $form_state
 * @param unknown_type $context
 */
function title_override_delete_form($form, &$form_state, $context) {
  $form_state['to_title_override']['context'] = $context;

  $form['delete'] = array(
    '#value' => 'This action will permanently remove this item from your database.'
  );

  $form['actions']['#type'] = 'actions';
  $form['actions']['save'] = array(
    '#type' => 'submit',
    '#value' => t('Delete'),
  );
  $form['actions']['cancel'] = array(
    '#type' => 'link',
    '#title' => t('Cancel'),
    '#href' => isset($_GET['destination']) ? $_GET['destination'] : 'admin/config/user-interface/to_titles',
  );
  $form['#submit'][] = 'title_override_delete_form_submit';
  return $form;
}

/**
 *
 * @param unknown_type $form
 * @param unknown_type $form_state
 */
function title_override_delete_form_submit($form, &$form_state) {
  context_delete($form_state['to_title_override']['context']);
  $form_state['redirect'] = 'admin/config/user-interface/to_titles';
}

/**
 *
 * Provides default context settings for Title overrides
 *
 * @return stdClass
 */
function title_override_load_default_context() {
  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'Title override default';
  $context->description = '';
  $context->tag = 'Title override';
  $context->conditions = array(
    'path' => array(
      'values' => array(
      ),
    ),
  );
  $context->reactions = array(
    'title_override' => array(
      'admin' => TRUE,
    ),
  );
  $context->condition_mode = 0;
  // Translatables
  // Included for use with string extractors like potx.
  t('Title Overrides');
  return $context;
}

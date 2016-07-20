<?php
/**
 * @file
 * Contains the class to extend views display with rows merge functionality.
 */

/**
 * The plugin that merges rows with the same content in the specified fields.
 *
 * @ingroup views_display_plugins
 */
class views_merge_rows_plugin_display_extender extends views_plugin_display_extender {
  /**
   * Provide a list of options for this plugin.
   */
  public function options_definition_alter(&$options) {
    $options['merge_rows'] = array('default' => FALSE, 'bool' => TRUE);
    $options['field_config'] = array('default' => array());
  }


  /**
   * Returns configuration for row merging.
   *
   * Only returns the configuration for the fields present in the view.
   * If a new field was added to the view, the default configuration for this
   * field is returned.
   *
   * @return array
   *   Configuration for row merging.
   */
  public function get_options() {
    if ($this->display->display->handler->uses_fields()) {
      $options = array();
      $options['merge_rows'] = $this->display->get_option('merge_rows');
      if (empty($options['merge_rows'])) {
        $options['merge_rows'] = FALSE;
      }
      $options['field_config'] = array();
      $field_config = $this->display->get_option('field_config');
      $fields = $this->display->display->handler->get_option('fields');
      foreach ($fields as $field => $info) {
        if (isset($field_config[$field])) {
          $options['field_config'][$field] = $field_config[$field];
        }
        else {
          $options['field_config'][$field] = array(
            'merge_option' => 'merge_unique',
            'separator' => ', ',
          );
        }
      }
    }
    else {
      $options['merge_rows'] = FALSE;
      $options['field_config'] = array();
    }
    return $options;
  }


  /**
   * Provide a form to edit options for this plugin.
   */
  protected function views_merge_rows_options_form(&$form, &$form_state) {
    $options = $this->get_options();

    if ($this->display->display->handler->use_pager()) {
      $form['warning_markup'] = array(
        '#markup' => '<div class="warning messages">' . t('It is highly recommended to disable pager if you merge rows.') . '</div>',
      );
    }

    $form['#tree'] = TRUE;
    $form['#theme'] = 'views_merge_rows_display_extender_plugin_table';
    $form['#title'] .= t('Merge rows with the same content.');
    $form['merge_rows'] = array(
      '#type' => 'checkbox',
      '#title' => t('Merge rows with the same content in the specified fields'),
      '#default_value' => $options['merge_rows'],
    );
    // Create an array of allowed columns from the data we know:
    $field_names = $this->display->display->handler->get_field_labels();

    foreach ($field_names as $field => $name) {
      $safe = str_replace(array('][', '_', ' '), '-', $field);
      // Markup for the field name.
      $form['field_config'][$field]['name'] = array(
        '#markup' => $name,
      );

      // Select for merge options.
      $form['field_config'][$field]['merge_option'] = array(
        '#type' => 'select',
        '#options' => array(
          'merge_unique' => t('Merge unique values of this field'),
          'merge' => t('Merge values of this field'),
          'filter' => t('Use values of this field as a filter'),
          'first_value' => t('Use the first value of this field'),
          'count' => t('Count merged values of this field'),
          'count_unique' => t('Count merged unique values of this field'),
        ),
        '#default_value' => $options['field_config'][$field]['merge_option'],
      );

      $form['field_config'][$field]['separator'] = array(
        '#title' => t('Separator:'),
        '#type' => 'textfield',
        '#size' => 10,
        '#default_value' => $options['field_config'][$field]['separator'],
        '#dependency' => array('edit-options-field-config-' . $safe . '-merge-option' => array('merge', 'merge_unique')),
      );
    }
  }

  /**
   * Saves the row merge options.
   */
  protected function views_merge_rows_options_form_submit(&$form, &$form_state) {
    foreach ($form_state['values']['options'] as $option => $value) {
      $this->display->set_option($option, $value);
    }
  }

  /**
   * Provide the form to set the rows merge options.
   */
  public function options_form(&$form, &$form_state) {
    switch ($form_state['section']) {
      case 'views_merge_rows':
        $this->views_merge_rows_options_form($form, $form_state);
        break;
    }
  }

  /**
   * Saves the row merge options.
   */
  public function options_submit(&$form, &$form_state) {
    switch ($form_state['section']) {
      case 'views_merge_rows':
        $this->views_merge_rows_options_form_submit($form, $form_state);
        break;
    }

  }

  /**
   * Provide the default summary for options in the views UI.
   */
  public function options_summary(&$categories, &$options) {
    if ($this->display->display->handler->uses_fields()) {
      $configuration = $this->get_options();
      $options['views_merge_rows'] = array(
        'category' => 'other',
        'title' => t('Merge rows'),
        'value' => $configuration['merge_rows'] ? t('Settings') : t('No'),
        'desc' => t('Allow merging rows with the same content in the specified fields.'),
      );
    }
  }

}

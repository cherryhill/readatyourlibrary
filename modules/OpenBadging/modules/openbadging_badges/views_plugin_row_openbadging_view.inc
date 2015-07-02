<?php

/**
 * @file
 * Contains the openbadging view row style plugin.
 */

/**
 * Plugin which performs a openbadging_badges_view_mode on the resulting object.
 *
 * Most of the code on this object is in the theme function.
 *
 * @ingroup views_row_plugins
 */
class views_plugin_row_openbadging_view extends views_plugin_row {

  // Basic properties that let the row style follow relationships.
  var $base_table = 'achievement_unlocks';
  var $base_field = 'achievement_id';
  // Stores the badges loaded with pre_render.
  var $badges = array();

  function init(&$view, &$display, $options = NULL) {
    parent::init($view, $display, $options);
    // Handle existing views with the deprecated 'teaser' option.
    if (isset($this->options['teaser'])) {
      $this->options['build_mode'] = $this->options['teaser'] ? 'teaser' : 'full';
    }
    // Handle existing views which has used build_mode instead of view_mode.
    if (isset($this->options['build_mode'])) {
      $this->options['view_mode'] = $this->options['build_mode'];
    }
  }

  function option_definition() {
    $options = parent::option_definition();

    $options['view_mode'] = array('default' => 'teaser');
    $options['links'] = array('default' => TRUE);
    $options['comments'] = array('default' => FALSE);

    return $options;
  }

  function options_form(&$form, &$form_state) {
    parent::options_form($form, $form_state);

    $options = $this->options_form_summary_options();
    $form['view_mode'] = array(
      '#type' => 'select',
      '#options' => $options,
      '#title' => t('View mode'),
      '#default_value' => $this->options['view_mode'],
    );
  }

  /**
   * Return the main options, which are shown in the summary title.
   */
  function options_form_summary_options() {
    $options['full'] = t('Full View');
    $options['teaser'] = t('Teaser View');
    $options['popup'] = t('Popup View');
    return $options;
  }

  function summary_title() {
    $options = $this->options_form_summary_options();
    return check_plain($options[$this->options['view_mode']]);
  }

  function pre_render($values) {
    $nids = array();
    foreach ($values as $row) {
      $nids[] = $row->{$this->field_alias};
    }
    $this->badges = openbadging_load_multiple($nids);
  }

  function render($row) {
    $badge = $this->badges[$row->{$this->field_alias}];
    $badge->view = $this->view;
    $build = openbadging_badges_view_mode($badge, $this->options['view_mode']);
    return $build;
  }

}

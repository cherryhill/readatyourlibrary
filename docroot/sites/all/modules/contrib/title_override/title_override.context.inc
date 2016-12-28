<?php
/**
 * @file
 * Context reaction for Metatag.
 */

class title_override_reaction_override extends context_reaction {
  function options_form($context) {
    $values = $this->fetch_from_context($context);
    $form = array();
    $form['title'] = array(
      '#title' => t('Title tag'),
      '#description' => t('Overrides the page title'),
      '#type' => 'textfield',
      '#maxlength' => 400,
      '#default_value' => isset($values['title']) ? $values['title'] : '',
    );
    $form['admin'] = array('#type' => 'hidden', '#value' => TRUE);
    $form['tokens'] = array(
      '#theme' => 'token_tree',
      '#token_types' => 'all', // The token types that have specific context. Can be multiple token types like 'term' and/or 'user'
      '#global_types' => TRUE, // A boolean TRUE or FALSE whether to include 'global' context tokens like [current-user:*] or [site:*]. Defaults to TRUE.
      '#click_insert' => TRUE, // A boolean whether to include the 'Click this token to insert in into the the focused textfield' JavaScript functionality. Defaults to TRUE.
    );
    return $form;
  }
  /**
   * Output a list of active contexts.
   */
  function execute() {
    $contexts = context_active_contexts();
    foreach ($contexts as $context) {
      if (!empty($context->reactions['title_override'])) {
        $title_override = &drupal_static('title_override');
        $title_override = $context->reactions['title_override']['title'];
      }
    }
  }
}

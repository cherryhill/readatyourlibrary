<?php

/**
 * @file
 * Views handler.
 */

/**
 * Field handler to allow linking to a comment.
 *
 * @ingroup views_field_handlers
 */
class views_handler_field_achievement_id extends views_handler_field {

  function init(&$view, &$options) {
    parent::init($view, $options);
    $this->additional_fields['achievement_id'] = 'achievement_id';
    $this->additional_fields['bid'] = 'bid';
  }

}

<?php
/**
 * @file
 * A handler to provide proper displays for individual user badges.
 *
 * @author Richard Skinner (Likeless), http://drupal.org/user/310635
 *
 * @ingroup views_field_handlers
 */
class views_handler_field_user_badges_badges_badge extends views_handler_field {

  //Get the additional fields we need
  function construct() {
    parent::construct();
    $this->additional_fields['name'] = 'name';
    $this->additional_fields['image'] = 'image';
    $this->additional_fields['href'] = 'href';
    $this->additional_fields['weight'] = 'weight';
  }

  //Render the badge HTML
  function render($values) {
    //Format the field by theming the badge
    //First, check to see if there is a badge
    if (isset($values->{$this->field_alias})) {
      //create the badge object
      $badge = new stdClass();
      $badge->bid = $values->{$this->field_alias};
      $badge->name = $values->{$this->aliases['name']};
      $badge->image = $values->{$this->aliases['image']};
      $badge->href = $values->{$this->aliases['href']};
      $badge->weight = $values->{$this->aliases['weight']};
  
      //Send it through the standard theme and return it
      return theme('user_badge', array('badge' => $badge));
    }
    //Else, just return the unformatted field
    else {
      $value = $this->get_value($values);
      return $this->sanitize_value($value);
    }
  }
}

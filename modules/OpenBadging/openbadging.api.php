<?php

/**
 * @file
 * Hooks provided by this module.
 */
/**
 * @addtogroup hooks
 * @{
 */

/**
 * Acts on openbadging being loaded from the database.
 *
 * This hook is invoked during $openbadging loading, which is handled by
 * entity_load(), via the EntityCRUDController.
 *
 * @param array $entities
 *   An array of $openbadging entities being loaded, keyed by id.
 *
 * @see hook_entity_load()
 */
function hook_openbadging_load(array $entities) {
  $result = db_query('SELECT pid, foo FROM {mytable} WHERE pid IN(:ids)', array(':ids' => array_keys($entities)));
  foreach ($result as $record) {
    $entities[$record->pid]->foo = $record->foo;
  }
}

/**
 * Responds when a $openbadging is inserted.
 *
 * This hook is invoked after the $openbadging 
 * which had been inserted to database.
 * @param OpenbadgingEntity $openbadging
 *   The $openbadging that is being inserted.
 *
 * @see hook_entity_insert()
 */
function hook_openbadging_insert(OpenbadgingEntity $openbadging) {
  db_insert('mytable')
    ->fields(array(
      'id' => entity_id('openbadging', $openbadging),
      'extra' => print_r($openbadging, TRUE),
    ))
    ->execute();
}

/**
 * Acts on a $openbadging being inserted or updated.
 *
 * This hook is invoked before the $openbadging is saved to the database.
 *
 * @param OpenbadgingEntity $openbadging
 *   The $openbadging that is being inserted or updated.
 *
 * @see hook_entity_presave()
 */
function hook_openbadging_presave(OpenbadgingEntity $openbadging) {
  $openbadging->name = 'foo';
}

/**
 * Responds to a $openbadging being updated.
 *
 * This hook is invoked after the $openbadging 
 * has been updated in the database.
 *
 * @param OpenbadgingEntity $openbadging
 *   The $openbadging that is being updated.
 *
 * @see hook_entity_update()
 */
function hook_openbadging_update(OpenbadgingEntity $openbadging) {
  db_update('mytable')
    ->fields(array('extra' => print_r($openbadging, TRUE)))
    ->condition('id', entity_id('openbadging', $openbadging))
    ->execute();
}

/**
 * Responds to $openbadging deletion.
 *
 * This hook is invoked after the $openbadging 
 * has been removed from the database.
 *
 * @param OpenbadgingEntity $openbadging
 *   The $openbadging that is being deleted.
 *
 * @see hook_entity_delete()
 */
function hook_openbadging_delete(OpenbadgingEntity $openbadging) {
  db_delete('mytable')
    ->condition('pid', entity_id('openbadging', $openbadging))
    ->execute();
}

/**
 * Act on a openbadging that is being assembled before rendering.
 *
 * @param $openbadging
 *   The openbadging entity.
 * @param $view_mode
 *   The view mode the openbadging is rendered in.
 * @param $langcode
 *   The language code used for rendering.
 *
 * The module may add elements to $openbadging->content prior to rendering. The
 * structure of $openbadging->content is a renderable array as expected by
 * drupal_render().
 *
 * @see hook_entity_prepare_view()
 * @see hook_entity_view()
 */
function hook_openbadging_view($openbadging, $view_mode, $langcode) {
  $openbadging->content['my_additional_field'] = array(
    '#markup' => $additional_field,
    '#weight' => 10,
    '#theme' => 'mymodule_my_additional_field',
  );
}

/**
 * Alter the results of entity_view() for openbadgings.
 *
 * @param $build
 *   A renderable array representing the openbadging content.
 *
 * This hook is called after the content has been assembled in a structured
 * array and may be used for doing processing which requires that the complete
 * openbadging content structure has been built.
 *
 * If the module wishes to act on the rendered HTML of the openbadging rather than
 * the structured content array, it may use this hook to add a #post_render
 * callback. Alternatively, it could also implement hook_preprocess_openbadging().
 * See drupal_render() and theme() documentation respectively for details.
 *
 * @see hook_entity_view_alter()
 */
function hook_openbadging_view_alter($build) {
  if ($build['#view_mode'] == 'full' && isset($build['an_additional_field'])) {
    // Change its weight.
    $build['an_additional_field']['#weight'] = -10;

    // Add a #post_render callback to act on the rendered HTML of the entity.
    $build['#post_render'][] = 'my_module_post_render';
  }
}

/**
 * Acts on openbadging_type being loaded from the database.
 *
 * This hook is invoked during openbadging_type loading, which is handled by
 * entity_load(), via the EntityCRUDController.
 *
 * @param array $entities
 *   An array of openbadging_type entities being loaded, keyed by id.
 *
 * @see hook_entity_load()
 */
function hook_openbadging_type_load(array $entities) {
  $result = db_query('SELECT pid, foo FROM {mytable} WHERE pid IN(:ids)', array(':ids' => array_keys($entities)));
  foreach ($result as $record) {
    $entities[$record->pid]->foo = $record->foo;
  }
}

/**
 * Responds when a openbadging_type is inserted.
 *
 * This hook is invoked after the openbadging_type is inserted into the database.
 *
 * @param OpenbadgingEntityType $openbadging_type
 *   The openbadging_type that is being inserted.
 *
 * @see hook_entity_insert()
 */
function hook_openbadging_type_insert(OpenbadgingEntityType $openbadging_type) {
  db_insert('mytable')
    ->fields(array(
      'id' => entity_id('openbadging_type', $openbadging_type),
      'extra' => print_r($openbadging_type, TRUE),
    ))
    ->execute();
}

/**
 * Acts on a openbadging_type being inserted or updated.
 *
 * This hook is invoked before the openbadging_type is saved to the database.
 *
 * @param OpenbadgingEntityType $openbadging_type
 *   The openbadging_type that is being inserted or updated.
 *
 * @see hook_entity_presave()
 */
function hook_openbadging_type_presave(OpenbadgingEntityType $openbadging_type) {
  $openbadging_type->name = 'foo';
}

/**
 * Responds to a openbadging_type being updated.
 *
 * This hook is invoked after the openbadging_type has been updated in the database.
 *
 * @param OpenbadgingEntityType $openbadging_type
 *   The openbadging_type that is being updated.
 *
 * @see hook_entity_update()
 */
function hook_openbadging_type_update(OpenbadgingEntityType $openbadging_type) {
  db_update('mytable')
    ->fields(array('extra' => print_r($openbadging_type, TRUE)))
    ->condition('id', entity_id('openbadging_type', $openbadging_type))
    ->execute();
}

/**
 * Responds to openbadging_type deletion.
 *
 * This hook is invoked after the openbadging_type has been removed from the database.
 *
 * @param OpenbadgingEntityType $openbadging_type
 *   The openbadging_type that is being deleted.
 *
 * @see hook_entity_delete()
 */
function hook_openbadging_type_delete(OpenbadgingEntityType $openbadging_type) {
  db_delete('mytable')
    ->condition('pid', entity_id('openbadging_type', $openbadging_type))
    ->execute();
}

/**
 * Define default openbadging_type configurations.
 *
 * @return
 *   An array of default openbadging_type, keyed by machine names.
 *
 * @see hook_default_openbadging_type_alter()
 */
function hook_default_openbadging_type() {
  $defaults['main'] = entity_create('openbadging_type', array(
    // …
    ));
  return $defaults;
}

/**
 * Alter default openbadging_type configurations.
 *
 * @param array $defaults
 *   An array of default openbadging_type, keyed by machine names.
 *
 * @see hook_default_openbadging_type()
 */
function hook_default_openbadging_type_alter(array &$defaults) {
  $defaults['main']->name = 'custom name';
}

/**
 * 
 * @param unknown_type $entity
 * @param unknown_type $value
 */
function hook_openbadging_update_status($entity, $value) {
//update openbadging entity status
}

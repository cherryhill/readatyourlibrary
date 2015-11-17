<?php

/**
 * @file
 * Provides Entity metadata integration.
 */

/**
 * Extend the defaults.
 */
/*class OpenbadgingMetadataController extends EntityDefaultMetadataController {

  public function entityPropertyInfo() {
    $info = parent::entityPropertyInfo();
    $properties = &$info[$this->type]['properties'];

    $properties['label'] = array(
      'label' => t('Label'),
      'description' => t('The openbadging label.'),
      'setter callback' => 'entity_property_verbatim_set',
      'setter permission' => 'administer openbadging',
      'schema field' => 'label',
    );

    $properties['type'] = array(
      'type' => 'openbadging_type',
      'getter callback' => 'entity_property_getter_method',
      'setter callback' => 'entity_property_verbatim_set',
      'setter permission' => 'administer openbadging',
      'required' => TRUE,
      'description' => t('The openbadging type.'),
      ) + $properties['type'];

    unset($properties['uid']);

    $properties['user'] = array(
      'label' => t("User"),
      'type' => 'user',
      'description' => t("The owner of the openbadging."),
      'getter callback' => 'entity_property_getter_method',
      'setter callback' => 'entity_property_setter_method',
      'setter permission' => 'administer openbadging',
      'required' => TRUE,
      'schema field' => 'uid',
    );

    $properties['created'] = array(
      'label' => t("Date created"),
      'type' => 'date',
      'description' => t("The date the openbadging was created."),
      'setter callback' => 'entity_property_verbatim_set',
      'setter permission' => 'administer openbadging',
      'schema field' => 'created',
    );
    $properties['changed'] = array(
      'label' => t("Date changed"),
      'type' => 'date',
      'schema field' => 'changed',
      'description' => t("The date the openbadging was most recently updated."),
    );
    $properties['status'] = array(
      'label' => t("Published"),
      'description' => t("Whether the node is published or unpublished."),
      'type' => 'integer',
      'setter callback' => 'entity_property_verbatim_set',
      'setter permission' => 'administer openbadging',
      'schema field' => 'status',
    );
    return $info;
  }

}*/

/**
 * Implements hook_entity_property_info_alter().
 */
/*function openbadging_entity_property_info_alter(&$info) {
  $properties = &$info['user']['properties'];
  foreach (openbadging_types() as $type_name => $type) {
    $properties['openbadging_' . $type_name] = array(
      'type' => 'openbadging',
      'label' => t('@type_name openbadging', array('@type_name' => drupal_ucfirst($type->label))),
      'description' => t("The users's @type_name openbadging.", array('@type_name' => $type->label)),
      'getter callback' => 'openbadging_user_get_properties',
      'bundle' => $type_name,
    );
  }
}*/

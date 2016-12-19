<?php
/**
 * @file
 * entity_for_avatar.features.taxonomy.inc
 */

/**
 * Implements hook_taxonomy_default_vocabularies().
 */
function entity_for_avatar_taxonomy_default_vocabularies() {
  return array(
    'avatars' => array(
      'name' => 'Avatars',
      'machine_name' => 'avatars',
      'description' => 'User avatars for registration page',
      'hierarchy' => 0,
      'module' => 'taxonomy',
      'weight' => 0,
      'rdf_mapping' => array(
        'rdftype' => array(
          0 => 'skos:ConceptScheme',
        ),
        'name' => array(
          'predicates' => array(
            0 => 'dc:title',
          ),
        ),
        'description' => array(
          'predicates' => array(
            0 => 'rdfs:comment',
          ),
        ),
      ),
    ),
  );
}

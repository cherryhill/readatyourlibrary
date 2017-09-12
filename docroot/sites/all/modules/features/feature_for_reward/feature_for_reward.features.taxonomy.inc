<?php
/**
 * @file
 * feature_for_reward.features.taxonomy.inc
 */

/**
 * Implements hook_taxonomy_default_vocabularies().
 */
function feature_for_reward_taxonomy_default_vocabularies() {
  return array(
    'type_of_reward' => array(
      'name' => 'Type of reward',
      'machine_name' => 'type_of_reward',
      'description' => 'Taxonomy term for different types of rewards',
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

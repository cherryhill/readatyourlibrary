<?php
/**
 * @file
 * program_and_activities_pages.features.taxonomy.inc
 */

/**
 * Implements hook_taxonomy_default_vocabularies().
 */
function program_and_activities_pages_taxonomy_default_vocabularies() {
  return array(
    'current_program' => array(
      'name' => 'current program',
      'machine_name' => 'current_program',
      'description' => 'This is used for current program views filter.',
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

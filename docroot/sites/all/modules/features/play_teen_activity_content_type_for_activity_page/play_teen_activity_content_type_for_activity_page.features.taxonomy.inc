<?php
/**
 * @file
 * play_teen_activity_content_type_for_activity_page.features.taxonomy.inc
 */

/**
 * Implements hook_taxonomy_default_vocabularies().
 */
function play_teen_activity_content_type_for_activity_page_taxonomy_default_vocabularies() {
  return array(
    'activity' => array(
      'name' => 'Activity',
      'machine_name' => 'activity',
      'description' => 'This is for teens activity page.',
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

<?php
/**
 * @file
 * activity_calendar_sticker.features.taxonomy.inc
 */

/**
 * Implements hook_taxonomy_default_vocabularies().
 */
function activity_calendar_sticker_taxonomy_default_vocabularies() {
  return array(
    'calendar_sticker' => array(
      'name' => 'Calendar Sticker',
      'machine_name' => 'calendar_sticker',
      'description' => 'Stickers for drag and drop Calendar',
      'hierarchy' => 0,
      'module' => 'taxonomy',
      'weight' => 0,
      'language' => 'und',
      'i18n_mode' => 0,
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

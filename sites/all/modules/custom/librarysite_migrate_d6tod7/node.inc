<?php

/**
 * Common mappings for the Drupal 6 node migrations.
 */
class LibrarysiteNodeMigration extends DrupalNode6Migration {
  public function __construct(array $arguments) {
    parent::__construct($arguments);

  
  }
  
}


class PageMigration extends LibrarysiteNodeMigration {
  public function __construct(array $arguments) {
    // Add any other data we're pulling into the source row, before the parent
    // constructor.
    $this->sourceFields['lead_graphic'] = 'Lead graphic string from D6';
    $this->sourceFields['summary'] = 'Summary string from D6';

    parent::__construct($arguments);
    
    $this->addFieldMapping('field_image', 'lead_graphic');
    $this->addFieldMapping('field_image:alt', 'image_alt');
    $this->addFieldMapping('field_image:title', 'image_title');
    
  }

}

class EventMigration extends LibrarysiteNodeMigration {
  public function __construct(array $arguments) {
    // Add any other data we're pulling into the source row, before the parent
    // constructor.
    //$this->sourceFields['lead_graphic'] = 'Lead graphic string from D6';
    //$this->sourceFields['summary'] = 'Summary string from D6';
    


    parent::__construct($arguments);


    //$this->addFieldMapping('language', 'language');
    $this->addFieldMapping('field_description', 'body');
    $this->addFieldMapping('field_description:format')
    ->defaultValue('full_html');
    $this->addFieldMapping('field_description:summary', 'teaser');
    
    //mapped from prepare_row
    $this->addFieldMapping('field_event_branch_ref', 'branch_dest');
    $this->addFieldMapping('field_audience_term', 'audience');
    
    $this->addFieldMapping('field_event_date_and_time', 'field_event_date');
    $this->addFieldMapping('field_event_date_and_time:to', 'field_event_date:value2');
    //$this->addFieldMapping('field_event_date_and_time:rrule', 'field_event_date:rrule');
    $this->addFieldMapping('field_event_date_and_time:rrule', NULL);
    $this->addFieldMapping('field_event_date_and_time:timezone')
             ->defaultValue('UTC');
     
   // Map address field
   $address_arguments = array(
     'administrative_area' => array('field_event_location' => 'province'),
     'locality' => array('field_event_location' => 'city'),
     'thoroughfare' => array('field_event_location' => 'street'),
     'premise' => array('field_event_location' => 'additional'),
     'postal_code' => array('field_event_location' => 'postal_code'),
   );
   //$this->addFieldMapping('field_event_location', 'country')
        //->arguments($address_arguments);
   $this->addFieldMapping('field_event_location', 'field_event_location');
   //$this->addFieldMapping('field_event_location:country', 'country');
   $this->addFieldMapping('field_event_location:name_line', 'name');
   $this->addFieldMapping('field_event_location:thoroughfare', 'street');
   $this->addFieldMapping('field_event_location:locality', 'city');
   $this->addFieldMapping('field_event_location:administrative_area', 'province');
   $this->addFieldMapping('field_event_location:premise', 'additional');
   $this->addFieldMapping('field_event_location:postal_code', 'postal_code');
   

   //drush_print_r($this);
   
   // Hide these sources because they are added as arguments
   $unmapped_sources = array(
     'province',
     'city',
     'street',
     'additional',
     'postal_code',
   );
   $this->addUnmigratedSources($unmapped_sources, t('DNM'));
  }

  protected function query() {
    $query = parent::query();

    // Join location table, which is not CCK
    $query->leftjoin('location_instance', 'i', 'i.nid = n.nid AND i.vid = n.vid');
    $query->leftjoin('location', 'l', 'l.lid = i.lid');
    $query->fields('l', array('name', 'street', 'additional', 'city', 'province', 'postal_code', 'country'));
    
    

    return $query;
  }
  
  function prepareRow($row) {
    
    
    // Always include this fragment at the beginning of every prepareRow()
    // implementation, so parent classes can ignore rows.
    if (parent::prepareRow($row) === FALSE) {
      return FALSE;
    }
    
    //drush_print_r($row);
    //dsm($row);
    
    $sections = array("Children" => 4, "Teens" => 5, "Adults" => 3);
    if ($row->field_event_display_sections[0]) {
      $row->audience = $sections[$row->field_event_display_sections[0]];
    }
    
    //Get branch id
    if ($row->field_event_branches) {
      $result = db_select('migrate_map_branch', 'branch')
          ->fields('branch')
          ->condition('sourceid1', $row->field_event_branches,'=')
          ->execute()
          ->fetchAssoc();
    
      //drush_print_r($result->destid1);
      if ($result['destid1']) {
        $row->branch_dest = $result['destid1'];
      } else {
        $row->branch_dest = NULL;
      }
      
      //dsm($row->branch_dest);
      //drush_print_r($result);
      
    }
    
    return TRUE;
  }

}

class BranchMigration extends LibrarysiteNodeMigration {
  public function __construct(array $arguments) {
    // Add any other data we're pulling into the source row, before the parent
    // constructor.
    $this->sourceFields['lead_graphic'] = 'Lead graphic string from D6';
    //$this->sourceFields['summary'] = 'Summary string from D6';

    parent::__construct($arguments);
    
    //$this->addFieldMapping('language', 'language');
    $this->addFieldMapping('field_description', 'body');
    $this->addFieldMapping('field_image', 'lead_graphic');
 
    $this->addFieldMapping('field_branch_hours', 'field_branch_hours_list');
    //$this->addFieldMapping('field_image:alt', 'image_alt');
    //$this->addFieldMapping('field_image:title', 'image_title');
    $this->addFieldMapping('field_branch_phone', 'field_branch_phone');
    
    $this->addFieldMapping('field_branch_address', 'country');
    $this->addFieldMapping('field_branch_address:thoroughfare', 'street');
    $this->addFieldMapping('field_branch_address:locality', 'city');
    $this->addFieldMapping('field_branch_address:administrative_area', 'province');
    $this->addFieldMapping('field_branch_address:premise', 'additional');
    $this->addFieldMapping('field_branch_address:postal_code', 'postal_code');


    // Hide these sources because they are added as arguments
    $unmapped_sources = array(
      'province',
      'city',
      'street',
      'additional',
      'postal_code',
    );
    $this->addUnmigratedSources($unmapped_sources, t('DNM'));
   }

   protected function query() {
     $query = parent::query();

     // Join location table, which is not CCK
     $query->join('location_instance', 'i', 'i.nid = n.nid AND i.vid = n.vid');
     $query->join('location', 'l', 'l.lid = i.lid');
     $query->fields('l', array('street', 'additional', 'city', 'province', 'postal_code', 'country'));

     return $query;
   }
}


class CheckitoutMigration extends LibrarysiteNodeMigration {
  public function __construct(array $arguments) {
    // Add any other data we're pulling into the source row, before the parent
    // constructor.
    
    parent::__construct($arguments);
    
    //$this->addFieldMapping('body', 'body');
    
  }

}

class FaqMigration extends LibrarysiteNodeMigration {
  public function __construct(array $arguments) {
    // Add any other data we're pulling into the source row, before the parent
    // constructor.
    
    parent::__construct($arguments);
    
    //$this->addFieldMapping('body', 'body');
    
  }

}

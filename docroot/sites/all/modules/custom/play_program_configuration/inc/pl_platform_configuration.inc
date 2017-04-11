<?php

// function 
function pl_platform_configuration($form, &$form_state) {

  $default_date = date('d/m/y');
  $program_start_date = variable_get('pmc_start_date', $default_date);
  $program_end_date = variable_get('pmc_end_date', $default_date);

  $form['program_configuration'] = array(
    '#type' => 'fieldset', 
    '#title' => t('Program Configuration'),
    '#collapsible' => TRUE, 
    '#collapsed' => TRUE,
  );

  // $form['program_configuration']['pmc_start_date'] = array(
  //   '#title' => t('Program Start date'),
  //   '#type' => 'date_popup',
  //   '#date_format' => 'd/m/Y',
  //   '#date_year_range' => '0:+10',
  //   '#required' => TRUE,
  //   '#size' => 8,
  //   '#default_value' => $program_start_date,
  // );

  // $form['program_configuration']['pmc_end_date'] = array(
  //   '#title' => t('Program End date'),
  //   '#type' => 'date_popup',
  //   '#date_format' => 'd/m/Y',
  //   '#date_year_range' => '0:+10',
  //   '#required' => TRUE,
  //   '#size' => 8,
  //   '#default_value' => $program_end_date,
  // );

  $form['program_configuration']['pmc_program_name'] = array(
    '#type' => 'textfield',
    '#title' => t('Program Name'),
  );

  $form['program_configuration']['pmc_progrm_image'] = array(
    '#title' => t('Library Program Image'),
    '#type' => 'managed_file',
    '#description' => t('The uploaded image will be displayed on this page using the image style choosen below.'),
    '#upload_location' => 'public://',
    '#default_value' => variable_get('pmc_progrm_image'),
  );

  // pl_program_logo_image();


  $program_footer = variable_get('pmc_program_footer', array('value' => '', 'format' => NULL));
  $form['program_configuration']['pmc_program_footer'] = array(
    '#type' => 'text_format',
    '#title' => t('Footer Content'),
    '#default_value' => $program_footer['value'],
    '#format' => $program_footer['format']
  );

  $form['pm_configuration'] = array(
    '#type' => 'fieldset', 
    '#title' => t('Private Message Configuration'),
    '#collapsible' => TRUE, 
    '#collapsed' => TRUE,
  );

  $form['pm_configuration']['pm_author'] = array(
    '#title' => t('Author for follow message'),
    '#type' => 'textfield',
    '#autocomplete_path' => 'author/autocomplete',
    '#default_value' => variable_get('pm_author'),
  );

  $form['program_details'] = array(
    '#type' => 'fieldset',
    '#title' => t('Program Details'),
    '#collapsible' => TRUE, 
    '#collapsed' => TRUE,
  );
  $form['program_details']['email_description_field'] = array(
    '#type' => 'textarea',
    '#title' => t('Email Description Text'),
    '#description' => t('Description provided for email field showed during registration'),
    '#default_value' => variable_get('email_description_field'),
  );
  $form['program_details']['pmc_purchase_link'] = array(
    '#type' => 'textfield',
    '#title' => t('Purchase Link'),
    '#description' => t('Enter a valid url (https://www.example.com) for Booklist purchase'),
    '#default_value' => variable_get('pmc_purchase_link'),
  );
  // $form['program_details']['pmc_library_name'] = array(
  //   '#type' => 'textfield',
  //   '#title' => t('Library Name'),
  //   '#description' => t('Enter the Library name for the program'),
  //   '#default_value' => variable_get('pmc_library_name'),
  // );
  // $form['program_details']['library_abbreviation'] = array(
  //   '#type' => 'textfield',
  //   '#title' => t('Abbreviation for Library Name'),
  //   '#description' => t('Abbreviation for Library name'),
  //   '#default_value' => variable_get('library_abbreviation'),
  // );
  $form['program_details']['catalog_link_for_program'] = array(
    '#type' => 'textfield',
    '#title' => t('Catalog link for review'),
    '#default_value' => variable_get('catalog_link_for_program'),
  );

  // $form['program_details']['review_pre_header'] = array(
  //   '#type' => 'textarea',
  //   '#title' => t('Header content for review pages'),
  //   '#default_value' => variable_get('review_pre_header'),
  // );

  // $form['announcement_block_details'] = array(
  //   '#type' => 'fieldset', 
  //   '#title' => t('Announcement block'),
  //   '#collapsible' => TRUE, 
  //   '#collapsed' => TRUE,
  // );

  // $form['announcement_block_details']['title_announcement'] = array(
  //   '#type' => 'textfield',
  //   '#title' => t('Title for the block'),
  //   '#default_value' => variable_get('title_announcement'),
  // );

  // $form['activities_landing_page_details'] = array(
  //   '#type' => 'fieldset', 
  //   '#title' => t('Activities Landing Page Details'),
  //   //'#description' => t('Bay Area Hotspot Activities block deatils'),
  //   '#collapsible' => TRUE, 
  //   '#collapsed' => TRUE,
  // );

  // $form['activities_landing_page_details']['hotspot_activities_block'] = array(
  //   '#type' => 'fieldset', 
  //   '#title' => t('Hotspot Activities block'),
  //   '#description' => t('Bay Area Hotspot Activities block deatils'),
  //   '#collapsible' => TRUE, 
  //   '#collapsed' => TRUE,
  // );

  // $form['activities_landing_page_details']['hotspot_activities_block']['hotspot_block_title'] = array(
  //   '#type' => 'textfield',
  //   '#title' => t('Title for the block'),
  //   '#default_value' => variable_get('hotspot_block_title'),
  // );

  // $form['activities_landing_page_details']['hotspot_activities_block']['hotspot_block_description'] = array(
  //   '#type' => 'textarea',
  //   '#title' => t('Description'),
  //   '#default_value' => variable_get('hotspot_block_description'),
  // );

  // $form['activities_landing_page_details']['hotspot_activities_block']['hotspot_block_link'] = array(
  //   '#type' => 'textfield',
  //   '#title' => t('Suggest a New Activity Form Link'),
  //   '#description' => t('This will link to the Suggest a New Activity Form <br/> Enter a valid url (https://www.example.com).'),
  //   '#default_value' => variable_get('hotspot_block_link'),
  // );

  // $form['activities_landing_page_details']['hotspot_activities_block']['hotspot_block_link_title'] = array(
  //   '#type' => 'textfield',
  //   '#title' => t('Title for the Link'),
  //   '#default_value' => variable_get('hotspot_block_link_title'),
  // );

  // $form['activities_landing_page_details']['review_activities_block'] = array(
  //   '#type' => 'fieldset', 
  //   '#title' => t('Review Activities block'),
  //   '#description' => t('Review Activity block deatils'),
  //   '#collapsible' => TRUE, 
  //   '#collapsed' => TRUE,
  // );

  // $form['activities_landing_page_details']['review_activities_block']['review_activity_block_title'] = array(
  //   '#type' => 'textfield',
  //   '#title' => t('Title for the block'),
  //   '#default_value' => variable_get('review_activity_block_title'),
  // );

  // $form['activities_landing_page_details']['review_activities_block']['review_activity_block_description'] = array(
  //   '#type' => 'textarea',
  //   '#title' => t('Description'),
  //   '#default_value' => variable_get('review_activity_block_description'),
  // );

  // $form['activities_landing_page_details']['static_block_one'] = array(
  //   '#type' => 'fieldset', 
  //   '#title' => t('Static Block One'),
  //   '#collapsible' => TRUE, 
  //   '#collapsed' => TRUE,
  // );

  // $form['activities_landing_page_details']['static_block_one']['static_block_one_title'] = array(
  //   '#type' => 'textfield',
  //   '#title' => t('Title for the Activity'),
  //   '#default_value' => variable_get('static_block_one_title'),
  // );

  // $form['activities_landing_page_details']['static_block_one']['static_block_one_title_link'] = array(
  //   '#type' => 'textfield',
  //   '#title' => t('Link for the title'),
  //   '#default_value' => variable_get('static_block_one_title_link'),
  // );

  // $desc_block_one = variable_get('static_block_one_description', array('value' => '', 'format' => NULL));
  // $form['activities_landing_page_details']['static_block_one']['static_block_one_description'] = array(
  //   '#type' => 'text_format',
  //   '#title' => t('Description for the activity'),
  //   '#default_value' => $desc_block_one['value'],
  //   '#format' => $desc_block_one['format'],
  // );

  // $form['activities_landing_page_details']['static_block_two'] = array(
  //   '#type' => 'fieldset', 
  //   '#title' => t('Static Block Two'),
  //   '#collapsible' => TRUE, 
  //   '#collapsed' => TRUE,
  // );

  // $form['activities_landing_page_details']['static_block_two']['static_block_two_title'] = array(
  //   '#type' => 'textfield',
  //   '#title' => t('Title for the Activity'),
  //   '#default_value' => variable_get('static_block_two_title'),
  // );

  // $form['activities_landing_page_details']['static_block_two']['static_block_two_title_link'] = array(
  //   '#type' => 'textfield',
  //   '#title' => t('Link for the title'),
  //   '#default_value' => variable_get('static_block_two_title_link'),
  // );

  // $desc_block_two = variable_get('static_block_two_description', array('value' => '', 'format' => NULL));
  // $form['activities_landing_page_details']['static_block_two']['static_block_two_description'] = array(
  //   '#type' => 'text_format',
  //   '#title' => t('Description for the activity'),
  //   '#default_value' => $desc_block_two['value'],
  //   '#format' => $desc_block_two['format'],
  // );

  // $form['activities_landing_page_details']['static_block_three'] = array(
  //   '#type' => 'fieldset', 
  //   '#title' => t('Static Block Three'),
  //   '#collapsible' => TRUE, 
  //   '#collapsed' => TRUE,
  // );

  // $form['activities_landing_page_details']['static_block_three']['static_block_three_title'] = array(
  //   '#type' => 'textfield',
  //   '#title' => t('Title for the Activity'),
  //   '#default_value' => variable_get('static_block_three_title'),
  // );

  // $form['activities_landing_page_details']['static_block_three']['static_block_three_title_link'] = array(
  //   '#type' => 'textfield',
  //   '#title' => t('Link for the title'),
  //   '#default_value' => variable_get('static_block_three_title_link'),
  // );

  // $desc_block_three = variable_get('static_block_three_description', array('value' => '', 'format' => NULL));
  // $form['activities_landing_page_details']['static_block_three']['static_block_three_description'] = array(
  //   '#type' => 'text_format',
  //   '#title' => t('Description for the activity'),
  //   '#default_value' => $desc_block_three['value'],
  //   '#format' => $desc_block_three['format'],
  // );

  

  // form for setting firing hooks label
  $form['activity_trigger'] = array(
    '#type' => 'fieldset',
    '#title' => t('Setting of Firing Hooks Label'),
    '#description' => t('Provide label for firing hooks that will be used for activity trigger'),
    '#collapsible' => TRUE,
    '#collapsed' => TRUE,
  );

  $form['activity_trigger']['user_insert'] = array(
    '#type' => 'textfield',
    '#title' => t('User Insert'),
    '#description' => t('When user is inserted'),
    '#default_value' => variable_get('user_insert') ? variable_get('user_insert') : 'User is Inserted'
  );

  $form['activity_trigger']['poll'] = array(
    '#type' => 'textfield',
    '#title' => t('Poll'),
    '#description' => t('For creation of poll'),
    '#default_value' => variable_get('poll') ? variable_get('poll') : 'Poll',
  );

  $entities = entity_get_info();

  foreach($entities as $entity_key => $entity) {
    if ($entity_key == 'node') {
      $entity['module'] = 'node';
    }

    if (isset($entity['module']) && ($entity['module'] == 'eck' || $entity['module'] == 'node')) {
      foreach ($entity['bundles'] as $bundle_key => $bundle_options) {
        if($entity_key == 'node' && $bundle_options['label'] == 'sticker') {
          $form['activity_trigger'][$bundle_key] = array(
            '#type' => 'textfield',
            '#title' => t('Calender'),
            '#description' => t('For calender'),
            '#default_value' => variable_get($bundle_key) ? variable_get($bundle_key) : t('Calender')
          );
        }

        if ($entity_key == 'node' && ($bundle_options['label'] == 'Booklist' || $bundle_options['label'] == 'Book Review' || $bundle_options['label'] == '_play_library_program_get_webformsMovie Review' || $bundle_options['label'] == 'Video Game Review' || $bundle_options['label'] == 'Music Review' || $bundle_options['label'] == 'Activity Review')) {
          $form['activity_trigger'][$bundle_key] = array(
            '#type' => 'textfield',
            '#title' => t($bundle_options['label']),
            '#description' => t("For review of @value", array('@value' => $bundle_options['label'])),
            '#default_value' => variable_get($bundle_key) ? variable_get($bundle_key) : $bundle_options['label']
          );
        }
      }
    }
  }

  $webforms = _play_library_program_get_webforms();

  foreach($webforms as $webform) {
    $form['activity_trigger'][$webform->nid] = array(
      '#type' => 'textfield',
      '#title' => t($webform->title),
      '#description' => t("For survey purposes of form @value", array('@value' => $webform->title)),
      '#default_value' => variable_get($webform->nid) ? variable_get($webform->nid) : $webform->title
    );
  }

	return system_settings_form($form);
}

// function for providing autocomplete for users
function _author_name_autocomplete($string = ''){
  $author_users = array();
  $sname_query = db_select('users','u');
  $sname_query->condition('u.name', '%' . db_like($string) . '%', 'LIKE');
  $sname_query->fields('u',array('name'));
  $sname_query->range(0, 15);

  $sname_result = $sname_query->execute()->fetchAll();

  foreach($sname_result as $res){
    $author_users[$res->name] = check_plain($res->name);
  }

 drupal_json_output($author_users);
}
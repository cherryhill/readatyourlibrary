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

  $form['program_configuration']['pmc_start_date'] = array(
    '#title' => t('Program Start date'),
    '#type' => 'date_popup',
    '#date_format' => 'd/m/Y',
    '#date_year_range' => '0:+10',
    '#required' => TRUE,
    '#size' => 8,
    '#default_value' => $program_start_date,
  );

  $form['program_configuration']['pmc_end_date'] = array(
    '#title' => t('Program End date'),
    '#type' => 'date_popup',
    '#date_format' => 'd/m/Y',
    '#date_year_range' => '0:+10',
    '#required' => TRUE,
    '#size' => 8,
    '#default_value' => $program_end_date,
  );

  $form['program_configuration']['pmc_program_name'] = array(
    '#type' => 'textfield',
    '#title' => t('Program Name'),
  );

  $form['program_configuration']['pmc_progrm_image'] = array(
    '#title' => t('Program Image'),
    '#type' => 'managed_file',
    '#description' => t('The uploaded image will be displayed on this page using the image style choosen below.'),
    '#upload_location' => 'public://',
    '#default_value' => variable_get('pmc_progrm_image'),
  );

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
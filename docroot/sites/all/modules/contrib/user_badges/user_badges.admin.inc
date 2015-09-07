<?php

/**
 * @file
 * @brief User Badges admin functions
 *
 * This file contains all the admin functions used by the module.
 *
 * @author Jeff Robbins (jjeff), http://drupal.org/user/17190
 * @author Chad Phillips (hunmonk), http://drupal.org/user/22079
 * @author Heine Deelstra (Heine), http://drupal.org/user/17943
 * @author Nuno Veloso (nunoveloso18), http://drupal.org/user/80656
 * @author Richard Skinner (Likeless), http://drupal.org/user/310635
 * @author Nancy Wichmann (NancyDru), http://drupal.org/user/101412
 * @author Ehud Shahak (basik.drupal) http://drupal.org/user/134140
 * @author Shabana Navas (Shabana Blackborder), http://drupal.org/user/1311398
 */

/**
 * Form builder; list of badges
 */
function user_badges_badgelist_form($form, &$form_state) {
  $show_users = (bool) variable_get('user_badges_list_show_users', 0);
  // Load the badges that we want to display.
  $header = array(
    'name' => array('data' => t('Name'), 'field' => 'name'),
    'badge' => array('data' => t('Badge')),
    'weight' => array('data' => t('Weight'), 'field' => 'weight'),
    'options' => array('data' => t('Options')),
  );

  if ($show_users) {
    $header['users'] = array('data' => t('Assigned to'));
  }

  $header['edit'] = array('data' => t('Edit'));
  $header['delete'] = array('data' => t('Delete'));

  // Which will be the default sort order?
  if (variable_get('user_badges_userweight', 0)) {
    $header['weight']['sort'] = 'asc';
  }
  else {
    $header['name']['sort'] = 'asc';
  }

  $form['#header'] = $header;

  $result = db_select('user_badges_badges', 'ubb')
    ->fields('ubb')
    ->extend('PagerDefault')
    ->limit(50)
    ->extend('TableSort')
    ->orderByHeader($header)
    ->execute();

  // Build a table listing the appropriate badges.
  foreach ($result as $badge) {
    $badge->class = 'badge badge-' . $badge->bid . ' ' . drupal_html_class($badge->name);

    $form['name'][$badge->bid] = array('#value' => check_plain($badge->name));

    $form['badge'][$badge->bid] = array(
      '#value' => theme('user_badge', array('badge' => $badge)));

    $form['weight'][$badge->bid] = array(
      '#type' => 'textfield',
      '#size' => 4,
      '#maxlength' => 255,
      '#default_value' => $badge->weight,
    );

    $options = array();
    if ($badge->unhideable) {
      $options[] = t('Cannot be hidden');
    }
    if ($badge->doesnotcounttolimit) {
      $options[] = t('Does not count to limit');
    }

    $form['options'][$badge->bid] = array(
      '#type' => 'value',
      '#value' => implode("<br />", $options),
    );

    if ($show_users) {

      $query = db_select('user_badges_user', 'ubu');
      $query->join('users', 'u', 'u.uid = ubu.uid');
      $query->fields('u', array('uid', 'name'))
        ->condition('ubu.bid', $badge->bid);
      $users = $query->execute();

      $u_list = array();
      foreach ($users as $acct) {
        $u_list[$acct->uid] = l(format_username($acct), "user/$acct->uid/badges");
      }
      if (!$u_list) {
        $u_list[] = t('None');
      }

      $form['users'][$badge->bid] = array('#value' => theme('item_list', array('items' => $u_list)));
    }

    $form['edit'][$badge->bid] = array('#value' => l(t('edit'), USER_BADGES_ADMIN_PATH . '/edit/' . $badge->bid));

    $form['delete'][$badge->bid] = array('#value' => l(t('delete'), USER_BADGES_ADMIN_PATH . '/delete/' . $badge->bid));
  }

  $form['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Update')
  );

  $form['pager'] = array('#markup' => theme('pager', array('tags' => NULL, 'element' => 0)));

  return $form;
}

/**
 * Validate user_badges_badgelist_form form submissions.
 *
 * All weights should be numeric.
 */
function user_badges_badgelist_form_validate($form, &$form_state) {
  if (isset($form['weight']) && is_array($form['weight'])) {
    foreach (element_children($form['weight']) as $bid) {
      if (!is_numeric($form_state['values'][$bid])) {
        form_set_error($bid, t('All weight values must be numeric.'));
      }
    }
  }
}

/**
 * Process user_badges_badgelist_form form submissions.
 *
 * Update the badge weights.
 */
function user_badges_badgelist_form_submit($form, &$form_state) {
  if (isset($form['weight']) && is_array($form['weight'])) {
    foreach (element_children($form['weight']) as $bid) {
      db_update('user_badges_badges')
        ->fields(array('weight' => $form_state['values'][$bid]))
        ->condition('bid', $bid)
        ->execute();
    }
    drupal_set_message(t('The badge weights have been updated.'));
  }
}

/**
 * Theme the badge list form.
 *
 * @param $form
 *   An associative array containing the structure of the form.
 * @ingroup themeable
 */
function theme_user_badges_badgelist_form($variables) {
  $form = $variables['form'];
  $output = '';

  // Loop through the array items in the name array to get all the bids for our listed badges.
  if (isset($form['name']) && is_array($form['name'])) {
    foreach (element_children($form['name']) as $key) {
      //We only want bids as values of $key
      if (!is_numeric($key)) {
        continue;
      }

      // Create the rows array for the table theme.
      $row = array();
      $row[] = $form['name'][$key]['#value'];
      $row[] = $form['badge'][$key]['#value'];
      $row[] = drupal_render($form['weight'][$key]);
      $row[] = $form['options'][$key]['#value'];
      if (variable_get('user_badges_list_show_users', 0)) {
        $row[] = $form['users'][$key]['#value'];
      }
      $row[] = $form['edit'][$key]['#value'];
      $row[] = $form['delete'][$key]['#value'];
      $rows[] = $row;
    }

    // Add the submit button.
    $rows[] = array(
      array(
        'data' => drupal_render($form['submit']),
        'align' => 'center',
        'colspan' => '20',
      ),
    );
  }
  else {
    $rows[] = array(array(
      'data' => t('No badges available.'),
      'colspan' => '5',
    ));
  }

  // Theme all that we have processed so far into a table.
  $output .= theme('table', array('header' => $form['#header'], 'rows' => $rows));

  // Create the table's pager.
  if ($form['pager']['#markup']) {
    $output .= drupal_render($form['pager']);
  }

  //Render the rest of the form elements
  $output .= drupal_render_children($form);

  return $output;
}

/**
 * Define the edit form for userbadges.
 */
function user_badges_edit_form($form, $form_state, $badge = NULL) {
  // If we have been given an existing badge then pass the bid.
  if ($badge) {
    $form['bid'] = array(
      '#type' => 'value',
      '#value' => $badge->bid,
    );
  }

  // General information fieldset.
  $form['general'] = array(
    '#type' => 'fieldset',
    '#title' => t('General'),
    '#collapsible' => TRUE,
    '#weight' => -10,
  );
  $form['general']['name'] = array(
    '#type' => 'textfield',
    '#title' => t('Name'),
    '#default_value' => $badge ? $badge->name : '',
    '#size' => 40,
    '#maxlength' => 100,
    '#description' => t('Name for the badge. Will be displayed as a tooltip when rolling over the badge.'),
    '#required' => TRUE,
    '#weight' => -10,
  );

  // Let the user choose the image location (URL, upload, library).
  $form['general']['image_location'] = array(
    '#type' => 'radios',
    '#title' => t('Image location'),
    '#options' => array(
      'external' => t('External'),
      'upload' => t('Upload new image'),
      'library' => t('Image from library'),
    ),
    // Are we using a library image (integer) or an image URL (string)?
    '#default_value' => !$badge || !file_valid_uri($badge->image) ? 'external' : 'library',
  );

  // External url.
  $form['general']['imageurl'] = array(
    '#type' => 'textfield',
    '#title' => t('Image URL'),
    '#default_value' => isset($badge->image) && !file_valid_uri($badge->image) ? $badge->image : '',
    '#size' => 60,
    '#maxlength' => 255,
    '#description' => t('The image URL for this badge. If you want to use an image from the user badges image library, select from the list below.'),
    '#states' => array(
      'visible' => array(
        ':input[name="image_location"]' => array('value' => 'external'),
      ),
    ),
  );

  // File upload.
  $form['general']['imagefile'] = array(
    '#type' => 'managed_file',
    '#title' => t('Upload image'),
    '#description' => t('The image file for this badge. This image will then be available in the library after badge creation.'),
    '#states' => array(
      'visible' => array(
        ':input[name="image_location"]' => array('value' => 'upload'),
      ),
    ),
  );

  // File from library.
  $form['general']['imagefromlibrary'] = array(
    '#title' => t('Image from library'),
    '#states' => array(
      'visible' => array(
        ':input[name="image_location"]' => array('value' => 'library'),
      ),
    ),
  );
  $images = _user_badges_images_from_library();
  if (count($images)) {
    $options = array();
    // Transform images to options
    foreach ($images as $path => $image_data) {
      $options[$path] = $image_data->image;
    }
    $form['general']['imagefromlibrary'] += array(
      '#type' => 'radios',
      '#default_value' => isset($badge->image) && file_valid_uri($badge->image) ? $badge->image : reset(array_keys($options)),
      '#options' => $options
    );
  }
  else {
    $form['general']['imagefromlibrary'] += array(
      '#type' => 'item',
      '#description' => t('No badge images uploaded yet. You can upload an image by choosing "Upload image" above or choose to use an external URL.'),
    );
  }

  // Provide other general informations.
  $form['general']['weight'] = array(
    '#type' => 'textfield',
    '#title' => t('Weight'),
    '#size' => 4,
    '#maxlength' => 10,
    '#default_value' => $badge ? $badge->weight : 0,
    '#description' => t('Lighter weighted items float to the top of lists. Heavier items go to the bottom. You must enter a number (negative values are allowed).'),
    '#required' => TRUE,
    '#weight' => 1,
  );

  $form['general']['href'] = array(
    '#type' => 'textfield',
    '#title' => t('Description URL'),
    '#size' => 60,
    '#maxlength' => 255,
    '#description' => t('You can specify here the link where your badge will redirect your user.
      This is useful for explanation pages about the badge, for instance. If you do not wish
      your badge to be clickable, please leave this field empty.') . '<br />' .
      '<u>' . t('Tips:') . '</u>' . '<ul>' .
      '<li>' . t('If you provide the full URL, it will be considered an external URL.') . '</li>' .
      '<li>' . t('If you provide only the path (e.g. "admin/content/node"), it is considered an
          internal link.') . '</li>' .
      '<li>' . t('Use %none to override a default link in the settings tab with no link for this badge.', array('%none' => '<none>')) . '</li>' .
      '</ul>',
    '#default_value' => $badge ? $badge->href : '',
    '#weight' => 1,
  );

  // Tokens help.
  if (module_exists('token')) {
    $form['token_help'] = array(
      '#title' => t('Replacement patterns'),
      '#type' => 'fieldset',
      '#collapsible' => TRUE,
      '#collapsed' => TRUE,
      '#weight' => -3,
    );

    $form['token_help']['help'] = array(
      '#theme' => 'token_tree',
      '#token_types' => array('userbadge', 'user'),
    );
  }
  else {
    $form['token_help'] = array(
      '#title' => t('Replacement patterns'),
      '#type' => 'fieldset',
      '#collapsible' => TRUE,
      '#collapsed' => TRUE,
      '#weight' => -3,
    );
    $form['token_help']['help'] = array(
      '#value' => t('Install the <a href="!link">Token</a> module if you want this URL to include dynamic elements such as badge ID numbers.',
        array('!link' => url('http://drupal.org/project/token', array('absolute' => TRUE)))
      ),
    );
  }

  // Display options.
  $form['options'] = array(
    '#type' => 'fieldset',
    '#title' => t('Display options'),
    '#collapsible' => TRUE,
    '#collapsed' => FALSE,
    '#weight' => -2,
  );

  $form['options']['unhideable'] = array(
    '#type' => 'checkbox',
    '#title' => t('Cannot be Hidden'),
    '#default_value' => $badge ? $badge->unhideable : '',
    '#description' => t('If this is set, the badge cannot be hidden by being moved down in weight. It will always show up.'),
  );

  $form['options']['fixedweight'] = array(
    '#type' => 'checkbox',
    '#title' => t('Fixed Weight'),
    '#default_value' => $badge ? $badge->fixedweight : '',
    '#description' => t('If this is set, the badge cannot have a user assigned weight, regardless of settings.'),
  );

  $form['options']['doesnotcounttolimit'] = array(
    '#type' => 'checkbox',
    '#title' => t('Does Not Count to Limit'),
    '#default_value' => $badge ? $badge->doesnotcounttolimit : '',
    '#description' => t('If this is set, the badge does not count towards the limit for number of badges to display per user.'),
  );

  if (module_exists('taxonomy')) {
    $badges_vid = variable_get('user_badges_vid', '');

    if (!empty($badges_vid)) {
      $terms = user_badges_get_term_from_vid($badges_vid);
      $form['tid'] = array(
        '#title' => t('Taxonomy Relation'),
        '#type' => 'select',
        '#options' => !empty($terms) ? $terms : array(t('There are no terms in the selected vocabulery')),
        '#default_value' => $badge ? $badge->tid : '',
        '#weight' => -1,
      );
    }
    else {
      $form['tid']['help'] = array(
        '#value' => t('Activate the taxonomy module if you want to associate badges with taxonomy terms.'),
        '#weight' => -1,
      );
    }
  }

  $form['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Save badge'),
    '#weight' => 1,
  );

  return $form;
}

/**
 * Validate user_badges_edit_form form submissions.
 */
function user_badges_edit_form_validate($form, &$form_state) {
  // Verify that the user has provided the required information based
  // upon the image location choosen.
  $image_location = $form_state['values']['image_location'];
  if ($image_location == 'external') {
    if (!$form_state['values']['imageurl']) {
      form_set_error('imageurl', t('You must enter an image URL.'));
    }
    elseif (!valid_url($form_state['values']['imageurl'], TRUE)) {
      // The image URL must also be a valid url.
      form_set_error('imageurl', t('This is not a valid image URL. You need to enter a complete image URL, including the "http://" at the start.'));
    }
  }
  elseif ($image_location == 'upload' && !$form_state['values']['imagefile']) {
    form_set_error('imagefile', t('You need to upload a local file.'));
  }
  elseif ($image_location == 'library' && empty($form_state['values']['imagefromlibrary'])) {
    form_set_error('imagelibrary', t('Your library is empty, please upload a file.'));
  }

  // Weights must be numeric.
  if (!is_numeric($form_state['values']['weight'])) {
    form_set_error('weight', t('Your value for the weight must be a number. Negative numbers are allowed, but not decimals.'));
  }
}

/**
 * Process user_badges_edit_form form submissions.
 *
 * Inserts the badge into the DB and sets a success message
 */
function user_badges_edit_form_submit($form, &$form_state) {
  $edit = $form_state['values'];

  // Let other modules know about this.
  module_invoke_all('user_badges_edit_badge', $edit);

  $edit = (object) $edit;

  if (isset($edit->bid)) {
    // If the badge already exists, delete it and re-insert it.
    $result = db_merge('user_badges_badges')
      ->key(array('bid' => $edit->bid));
    // Remove image usage for old image.
    $old_image = db_select('user_badges_badges', 'ubb')
      ->fields('ubb', array('image'))
      ->condition('ubb.bid', $edit->bid)
      ->execute()
      ->fetchField();
    if ($old_image) {
      $file = _user_badges_managed_file($old_image);
      if ($file) {
        file_usage_delete($file, 'user_badges', 'user_badge', $edit->bid);
      }
    }
  }
  else {
    // If the badge does not exist, insert it.
    $result = db_insert('user_badges_badges');
  }

  // Define image data (string or integer)
  switch ($edit->image_location) {
    case 'external':
      $image = trim($edit->imageurl);
      break;
    case'upload':
      $image = $edit->imagefile;
      break;
    case'library':
      $image = $edit->imagefromlibrary;
  }

  // Add the rest of the fields and execute.
  $result = $result->fields(array(
    'name' => trim($edit->name),
    'image' => $image,
    'weight' => $edit->weight,
    'href' => (!empty($edit->href) ? trim($edit->href) : NULL),
    'unhideable' => $edit->unhideable,
    'fixedweight' => $edit->fixedweight,
    'doesnotcounttolimit' => $edit->doesnotcounttolimit,
    'tid' => (!empty($edit->tid) ? $edit->tid : NULL),
  ))
    ->execute();

  $bid = isset($edit->bid) ? $edit->bid : $result;
  if ($bid) {
    if ($edit->image_location == 'upload') {
      // Make the uploaded file permanent.
      $file = file_load($form_state['values']['imagefile']);
      if ($file) {
        $file->status = FILE_STATUS_PERMANENT;
        $file = file_move($file, 'public://badges');
        if ($file) {
          // Record that the module is using the file.
          file_usage_add($file, 'user_badges', 'user_badge', $bid);
          // Update the image url for the badge.
          $result = db_merge('user_badges_badges')
            ->key(array('bid' => $bid))
            ->fields(array('image' => $file->uri))
            ->execute();
          $image = $file->uri;
        }
        else {
          $result = FALSE;
          watchdog('user_badges', 'Failed to save image file after upload.', array(), WATCHDOG_ERROR);
        }
      }
      else {
        $result = FALSE;
        watchdog('user_badges', 'Failed to load image file after upload.', array(), WATCHDOG_ERROR);
      }
    }
    elseif ($edit->image_location == 'library') {
      // Record that the badge is using the file.
      $file = _user_badges_managed_file($image);
      if ($file) {
        file_usage_add($file, 'user_badges', 'user_badge', $bid);
      }
    }
  }
  else {
    $result = FALSE;
    watchdog('user_badges', 'Invalid badge ID.', array(), WATCHDOG_ERROR);
  }

  if ($result) {
    drupal_set_message(t('Badge %badgename saved.', array('%badgename' => $edit->name)));
  }
  else {
    drupal_set_message(t('There was a problem saving the badge information into the database.'));
  }

  $form_state['redirect'] = USER_BADGES_ADMIN_PATH;
}

/**
 * Form to upload the badge images or to delete existing ones.
 */
function user_badges_images_form($form, $form_state) {
  $selects = _user_badges_images_from_library();
  if (count($selects)) {
    $form['images'] = array('#tree' => TRUE);
    foreach ($selects as $filepath => $image) {
      $form['images'][$filepath] = array(
        '#type' => 'checkbox',
        '#title' => $image->image,
        '#return_value' => 1,
        '#default_value' => FALSE,
        '#description' => check_plain($image->file->uri),
      );
    }
    $form['delete_image'] = array(
      '#type' => 'submit',
      '#value' => t('Delete'),
    );
  }
  else {
    $form['empty'] = array(
      '#type' => 'item',
      '#description' => t('There are no images in your library at the moment. You can add one !create_link and uploading an image.', array('!create_link' => l(t('by creating a badge'), 'admin/config/people/user_badges/add'))),
    );
  }

  return $form;
}

/**
 * Submission action for user_badges_images_form
 *
 * Save the uploaded file or delete the selected one
 */
function user_badges_images_form_submit($form, &$form_state) {
  $count = 0;
  $files_to_delete = array_keys(array_filter($form_state['values']['images']));
  if (!empty($files_to_delete)) {
    $dir = 'public://badges';
    if (file_prepare_directory($dir)) {
      foreach ($files_to_delete as $path) {
        $file = _user_badges_managed_file($path);
        if ($file) {
          if (file_usage_list($file)) {
            drupal_set_message(t('The file %file is in use and cannot be deleted.', array('%file' => $path)), 'error');
          }
          else {
            $count++;
            file_delete($file);
          }
        }
        else {
          drupal_set_message(t('The file %file cannot be deleted by User Badges.', array('%file' => $path)), 'error');
        }
      }
    }
    else {
      drupal_set_message(t('The image directory %dir cannot be accessed.', array('%dir' => $dir)), 'error');
    }
    if ($count > 0) {
      drupal_set_message(t('Deleted @count image(s).', array('@count' => $count)));
    }
  }
}

/**
 * Form to associated badges with roles.
 */
function user_badges_roles_form($form, &$form_state) {
  // No badges for the anonymous role.
  $roles = user_roles(TRUE);
  $role_badges = user_badges_get_roles(NULL, array('returnbadges' => TRUE));

  $form['blocked'] = array(
    '#type' => 'fieldset',
    '#title' => t('Blocked Badge'),
    '#collapsible' => TRUE,
    '#collapsed' => FALSE,
    '#tree' => TRUE,
  );

  $form['roles'] = array(
    '#type' => 'fieldset',
    '#title' => t('Role Badges'),
    '#collapsible' => TRUE,
    '#collapsed' => FALSE,
    '#tree' => TRUE,
  );

  //Determine which selector type the user wants to use to set badges from their settings
  //If the user wants to use the drop-down selector, display that if there are records in the db
  if (variable_get('user_badges_selector_type', 1) == 0) {

    //First, load all the available badges from the database by calling the following helper function
    $result = user_badges_load_badges();

    //Display the drop-down only if we get any records
    if ($result->rowCount()) {
      foreach ($result as $badge) {
        $options[$badge->bid] = t('Badge') . ' ' . $badge->bid . ' ' . '-' . ' ' . $badge->name;
      }

      $form['blocked'][0] = array(
        '#type' => 'select',
        '#title' => t('blocked user'),
        '#empty_option' => '- None -',
        '#options' => $options,
        '#default_value' => isset($role_badges[0]) ? $role_badges[0]->bid : '',
      );

      foreach ($roles as $rid => $role) {
        $form['roles'][$rid] = array(
          '#type' => 'select',
          '#title' => check_plain($role),
          '#empty_option' => '- None -',
          '#options' => $options,
          '#default_value' => isset($role_badges[$rid]) ? $role_badges[$rid]->bid : '',
        );
      }
    }
  }
  //Else, if the user wants to use the autocomplete or if there are no records in the db, display that
  else {
    $form['blocked'][0] = array(
      '#type' => 'textfield',
      '#title' => t('blocked user'),
      '#size' => 40,
      '#maxlength' => 255,
      '#autocomplete_path' => 'user_badges/autocomplete',
      '#default_value' => isset($role_badges[0]) ? $role_badges[0]->name . ' ' . t('(Badge ID') . ' ' . $role_badges[0]->bid . ')' : '',
      '#field_suffix' => isset($role_badges[0]) ? ' ' . t('Current:') . ' ' . _user_badges_build_image($role_badges[0]) : '',
    );

    foreach ($roles as $rid => $role) {
      $form['roles'][$rid] = array(
        '#type' => 'textfield',
        '#title' => check_plain($role),
        '#maxlength' => 255,
        '#autocomplete_path' => 'user_badges/autocomplete',
        '#default_value' => isset($role_badges[$rid]) ? $role_badges[$rid]->name . ' '
          . t('(Badge ID') . ' ' . $role_badges[$rid]->bid . ')' : '',
        '#field_suffix' => isset($role_badges[$rid]) ?
          ' ' . t('Current:') . ' ' . _user_badges_build_image($role_badges[$rid]) : '',
      );
    }
  }

  $form[] = array(
    '#type' => 'submit',
    '#value' => t('Save Role Badges'),
  );
  return $form;
}

/**
 * Validation function for user_badges_roles_form.
 */
function user_badges_roles_form_validate($form, &$form_state) {
  // Get the user selected values from the multi-select/autocomplete.
  $array = $form_state['values']['roles'] + $form_state['values']['blocked'];

  // Initialize the $bids array which will store all the bids.
  $bids = array();

  // Go through all the entries and make sure they all have a valid badge ID.
  foreach ($array as $field => $value) {
    //If the selector type used to add badges was the autocomplete, then, validate the text in the autocomplete boxes
    if (variable_get('user_badges_selector_type', 1) == 1) {
      if (!empty($value)) {
        // The field isn't empty, so we should validate it.
        $validation = user_badges_badge_autocomplete_validation($value);
        //Is it correctly formatted?
        if ($validation[1] == 'string') {
          if ($field == 0) {
            form_set_error('blocked][' . $field, t('"@value" is not a valid badge name. Try using the autocomplete function (requires javascript).', array('@value' => $value)));
          }
          else {
            form_set_error('roles][' . $field, t('"@value" is not a valid badge name. Try using the autocomplete function (requires javascript).', array('@value' => $value)));
          }
        }
        // The format was correct, but we need to check the bid exists.
        elseif ($validation[1] == 'nobid') {
          if ($field == 0) {
            form_set_error('blocked][' . $field, t('@value is not a valid badge ID. Try using the autocomplete function (requires javascript).', array('@value' => $validation[0])));
          }
          else {
            form_set_error('roles][' . $field, t('@value is not a valid badge ID. Try using the autocomplete function (requires javascript).', array('@value' => $validation[0])));
          }
        }
      }
    }
    // Now we add the valid bids to an array so that we can check if there
    // are any duplicate bids assigned to a role.
    // Only add to the array if the selected value is not 'none' (multi-select)
    if ($value != NULL) {
      $bids[$field] = $value;
    }
  }

  // Now we check if there are duplicate bids in the $bids array and output
  // an error message if there are.
  if (isset($bids)) {
    $duplicate_bids = array_unique(array_diff_assoc($bids, array_unique($bids)));
    if (isset($duplicate_bids)) {
      foreach ($duplicate_bids as $field => $bid) {
        form_set_error('roles][' . $field, t('@bid has already been assigned to a role. Please choose another bid to assign to this role.', array('@bid' => $bid)));
      }
    }
  }
}

/**
 * Submission function for user_badges_roles_form.
 */
function user_badges_roles_form_submit($form, &$form_state) {
  $array = $form_state['values']['roles'] + $form_state['values']['blocked'];

  //If the selectory type used to enter badges was the autocomplete, then, extract the bid from the text
  if (variable_get('user_badges_selector_type', 1) == 1) {
    foreach ($array as $field => &$value) {
      // We now have a string as our badge, so just extract the bid.
      preg_match('/\(' . t('Badge ID') . ' (\d+)\)/', $value, $matches);
      // Transform our value into just the bid.
      if (!empty($matches)) {
        $value = $matches[1];
      }
    }
  }
  user_badges_save_roles($array);
}

/**
 * Form for general module settings.
 */
function user_badges_settings_form($form, &$form_state) {
  $noyes = array(t('No'), t('Yes'));

  $form['showone'] = array(
    '#type' => 'textfield',
    '#title' => t('Number of badges to display'),
    '#size' => 4,
    '#maxlength' => 4,
    '#default_value' => variable_get('user_badges_showone', 0),
    '#description' => t('Only this many badges with the lightest weights will be shown.')
      . t('Set to zero to apply no limit.')
      . t('Note that if multiple badges have the same lightest weight, only one of them will appear (first by alphabetical order).'),
  );

  $form['showblocked'] = array(
    '#type' => 'radios',
    '#options' => $noyes,
    '#title' => t('Only show blocked user badge'),
    '#default_value' => variable_get('user_badges_showblocked', 0),
    '#description' => t('If checked, only the badge associated to blocked users will be shown, overriding other badges the user eventually has as well as any other settings.') . ' ' .
      t('Note that if there is no badge associated to blocked users, no badges will appear.') . ' ' .
      t('This option only acts on blocked users and has no repercussions on active user badges.'),
    '#attributes' => array('class' => array('container-inline')),
  );

  $form['userweight'] = array(
    '#type' => 'radios',
    '#options' => $noyes,
    '#title' => t('Allow users to reorder badges'),
    '#default_value' => variable_get('user_badges_userweight', 0),
    '#description' => t('If checked, users will have the ability to reweight their badges in their profile, enabling them to set what order their badges display, and also which badges will display if a limit is set above.') . ' ' .
      t('Note that you can make individual badges exempt from this function, allowing you to force them to the top or bottom of the list by giving them a very high or low weight value.'),
    '#attributes' => array('class' => array('container-inline')),
  );

  $form['show_users'] = array(
    '#type' => 'radios',
    '#options' => $noyes,
    '#title' => t('Show users in badge list'),
    '#default_value' => variable_get('user_badges_list_show_users', 0),
    '#description' => t('If selected, the user badges list will include all of the users who have been assigned the badge.'),
    '#attributes' => array('class' => array('container-inline')),
  );

  $form['selector_type'] = array(
    '#type' => 'select',
    '#options' => array(
      0 => t('drop-down multi-select'),
      1 => t('autocomplete'),
    ),
    '#title' => t('Selector to set a badge'),
    '#default_value' => variable_get('user_badges_selector_type', 1),
    '#description' => t('Select which type of selector to use to set a badge.'),
    '#attributes' => array('class' => array('container-inline')),
  );

  $form['imagecache'] = array(
    '#type' => 'select',
    '#options' => image_style_options(),
    '#title' => t('Image style to size badges'),
    '#default_value' => variable_get('user_badges_imagecache', ''),
    '#description' => t('This determines the size of the image display.'),
    '#attributes' => array('class' => array('container-inline')),
  );

  $form['nobadges'] = array(
    '#type' => 'textfield',
    '#title' => t('"No badges" message'),
    '#size' => 60,
    '#maxlength' => 500,
    '#default_value' => variable_get('user_badges_nobadges', ''),
    '#description' => t('This provides this message if the user has no badges, rather than nothing. Leave it blank for no message.'),
  );

  $form['defaulthref'] = array(
    '#type' => 'textfield',
    '#title' => t('Default badge link URL'),
    '#size' => 60,
    '#maxlength' => 500,
    '#default_value' => variable_get('user_badges_defaulthref', ''),
    '#description' => t('Enter a default URL to link all badges to. You can override this for individual badges.'),
  );

  // Tokens help.
  if (module_exists('token')) {
    include_once(drupal_get_path('module', 'user_badges') . '/user_badges.tokens.inc');
    $form['token_help'] = array(
      '#title' => t('Replacement patterns'),
      '#type' => 'fieldset',
      '#collapsible' => TRUE,
      '#collapsed' => TRUE,
    );

    $form['token_help']['help'] = array(
      '#theme' => 'token_tree',
      '#token_types' => array('userbadge', 'user'),
    );
  }
  else {
    $form['token_help']['help'] = array(
      // Ignore Coder flag on link.
      '#value' => t('Install the <a href="!link">Token</a> module if you want this URL to include dynamic elements such as badge ID numbers.', array('!link' => url('http://drupal.org/project/token', array('absolute' => TRUE)))),
    );
  }

  // Let the user select a vocabulary to associate with badges.
  if (module_exists('taxonomy')) {
    //Build the options for the element
    $vocabs = taxonomy_get_vocabularies();
    $selects = array('' => t('&lt;none&gt;'));
    foreach ($vocabs as $vid => $vocab) {
      $selects[$vid] = $vocab->name;
    }

    $form['vid'] = array(
      '#type' => 'radios',
      '#title' => t('Vocabulary'),
      '#default_value' => variable_get('user_badges_vid', ''),
      '#options' => $selects,
      '#description' => t('Optional. Select a vocabulary to associate badges with. You can optionally associate each badge with one term in this vocabulary.'),
      '#attributes' => array('class' => array('container-inline')),
    );
  }

  $form[] = array(
    '#type' => 'submit',
    '#value' => t('Save configuration'),
    '#weight' => 100,
  );
  return $form;
}

/**
 * Validate user_badges_settings_form input.
 */
function user_badges_settings_form_validate($form, $form_state) {
  // 'showone' must be numeric.
  if (!is_numeric($form_state['values']['showone']) || $form_state['values']['showone'] < 0) {
    form_set_error('showone', t('Must be a positive number.'));
  }
}

/**
 * Submission function for user_badges_settings_form.
 *
 * Set the variables and display a message about the set values.
 */
function user_badges_settings_form_submit($form, $form_state) {
  variable_set('user_badges_showone', $form_state['values']['showone']);
  variable_set('user_badges_showblocked', $form_state['values']['showblocked']);
  variable_set('user_badges_userweight', $form_state['values']['userweight']);
  variable_set('user_badges_list_show_users', $form_state['values']['show_users']);
  variable_set('user_badges_selector_type', $form_state['values']['selector_type']);
  variable_set('user_badges_imagecache', $form_state['values']['imagecache']);
  variable_set('user_badges_nobadges', $form_state['values']['nobadges']);

  // Only set a default href if we have some non-whitespace in there.
  $defaulthref = trim($form_state['values']['defaulthref']);
  if (empty($defaulthref)) {
    variable_del('user_badges_defaulthref');
  }
  else {
    variable_set('user_badges_defaulthref', $form_state['values']['defaulthref']);
  }

  // Only set a vid if we have a value, otherwise wipe it for none/no taxonomy.
  if ($form_state['values']['vid']) {
    variable_set('user_badges_vid', $form_state['values']['vid']);
  }
  else {
    variable_del('user_badges_vid');
  }

  drupal_set_message(t('Configuration saved.'));
}

/**
 * Scan the badges image directory.
 *
 * @return
 *  An array of images from the image library, in the form
 *  $filepath => object('image' => $image_html, 'file' => $file_unmanaged)
 */
function _user_badges_images_from_library() {
  $selects = array();

  $path = 'public://badges';

  if (file_prepare_directory($path, FILE_CREATE_DIRECTORY | FILE_MODIFY_PERMISSIONS)) {
    // Scan directory for images in supported formats.
    $files = file_scan_directory($path, '/.*\.(jpe?g|png|gif)/i', array('recurse' => FALSE));
    foreach ($files as $file) {
      $image = image_get_info($file->uri);
      if ($image) {
        $file->filepath = $path . '/' . $file->filename;

        $style_name = variable_get('user_badges_imagecache', '');
        $variables = array('path' => $file->filepath);

        if ($style_name) {
          $theme = 'image_style';
          $variables['style_name'] = $style_name;
        }
        else {
          $theme = 'image';
          $variables['width'] = $image['width'];
          $variables['height'] = $image['height'];
        }

        $selects[$file->filepath] = (object) array('image' => theme($theme, $variables), 'file' => $file);

        // Ensures this file is managed in database.
        if (!_user_badges_managed_file($file->filepath)) {
          watchdog('user_badges', 'Failed to manage detected image file: @file', array('@file' => $file->filepath), WATCHDOG_ERROR);
        }
      }
    }
  }
  else {
    // 'public://badges' directory could not be created or has wrong permissions.
    watchdog('user_badges', 'Scanning for badge images library failed.  Badges directory could not be created or has wrong permissions: @dir', array('@dir' => $path), WATCHDOG_ERROR);
  }
  return $selects;
}


/**
 * Convert a uri into a managed file object.
 *
 * Loads existing file object for uri
 * or creates new managed file entry.
 *
 * @return object|false
 *   A file object on success or FALSE in the event of an error.
 */
function _user_badges_managed_file($file_uri) {
  global $user;
  if (file_valid_uri($file_uri)) {
    // Check if there's an entry in the database for this file.
    $fid = db_select('file_managed', 'f')
          ->fields('f', array('fid'))
          ->condition('f.uri', $file_uri)
          ->execute()
          ->fetchField();

    if ($fid) {
      return file_load($fid);
    }
    else {
      // If no entry found, we need to save this to the database.
      $fileob = new stdClass();
      $fileob->fid = NULL;
      $fileob->uri = $file_uri;
      $fileob->filename = drupal_basename($fileob->uri);
      $fileob->filemime = file_get_mimetype($fileob->uri);
      $fileob->uid = $user->uid;
      $fileob->status = FILE_STATUS_PERMANENT;
      return file_save($fileob);
    }
  }
  return FALSE;
}


/**
 * Get terms belonging to a vocabulary. Can be used in the form's #options field.
 *
 * @param vid
 *   The vocabulary's id.
 * @return
 *   Array whose key is the tid and value the term's name.
 */
function user_badges_get_term_from_vid($vid) {
  $query = db_select('taxonomy_term_data', 't');
  $query->join('taxonomy_term_hierarchy', 'h', 'h.tid = t.tid');
  $query->fields('t', array('tid', 'name'));
  $query->condition('t.vid', $vid, '=');
  $query->condition('h.parent', 0, '='); // remove this line to get all terms.
  $result = $query->execute();

  $data = array();
  while ($record = $result->fetchAssoc()) {
    $data[$record['tid']] = t($record['name']);
  }

  return $data;
}

/**
 * User badge deletion form.
 */
function user_badges_delete_form($form, $form_state, $badge) {
  $form = array();
  $form['bid'] = array('#type' => 'value', '#value' => $badge->bid);
  return confirm_form($form, t('Are you sure you want to delete the badge %name?', array('%name' => $badge->name)), USER_BADGES_ADMIN_PATH);
}

/**
 * Submit handler for user badge deletion.
 */
function user_badges_delete_form_submit($form, &$form_state) {
  $bid = $form_state['values']['bid'];
  $badge = user_badge_load($bid);

  // Let other modules know about this.
  module_invoke_all('user_badges_delete', $badge);

  // Remove file usage for image file.
  $file = _user_badges_managed_file($badge->image);
  if ($file) {
    file_usage_delete($file, 'user_badges', 'user_badge', $badge->bid);
  }

  db_delete('user_badges_badges')
    ->condition('bid', $bid)
    ->execute();

  db_delete('user_badges_user')
    ->condition('bid', $bid)
    ->execute();

  db_delete('user_badges_roles')
    ->condition('bid', $bid)
    ->execute();

  drupal_set_message(t('The @name badge has been deleted.', array('@name' => $badge->name)));
  $form_state['redirect'] = USER_BADGES_ADMIN_PATH;
}

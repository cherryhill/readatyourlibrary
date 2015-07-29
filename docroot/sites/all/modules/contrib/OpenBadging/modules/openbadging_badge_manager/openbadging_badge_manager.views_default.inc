<?php

/**
 * @file
 * openbadging_badge_manager.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function openbadging_badge_manager_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'badge_manager_earner';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'openbadging';
  $view->human_name = 'badge manager earner';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'badge manager earner';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'none';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '10';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Field: openbadging: Unlocked image */
  $handler->display->display_options['fields']['field_badge_entity_unlock_image']['id'] = 'field_badge_entity_unlock_image';
  $handler->display->display_options['fields']['field_badge_entity_unlock_image']['table'] = 'field_data_field_badge_entity_unlock_image';
  $handler->display->display_options['fields']['field_badge_entity_unlock_image']['field'] = 'field_badge_entity_unlock_image';
  $handler->display->display_options['fields']['field_badge_entity_unlock_image']['label'] = '';
  $handler->display->display_options['fields']['field_badge_entity_unlock_image']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_badge_entity_unlock_image']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_badge_entity_unlock_image']['settings'] = array(
    'image_style' => '110_110',
    'image_link' => 'content',
  );
  /* Field: openbadging: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'openbadging';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  /* Field: Field: Program */
  $handler->display->display_options['fields']['field_badge_entity_program']['id'] = 'field_badge_entity_program';
  $handler->display->display_options['fields']['field_badge_entity_program']['table'] = 'field_data_field_badge_entity_program';
  $handler->display->display_options['fields']['field_badge_entity_program']['field'] = 'field_badge_entity_program';
  $handler->display->display_options['fields']['field_badge_entity_program']['label'] = '';
  $handler->display->display_options['fields']['field_badge_entity_program']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_badge_entity_program']['type'] = 'taxonomy_term_reference_plain';
  $handler->display->display_options['fields']['field_badge_entity_program']['delta_offset'] = '0';
  /* Field: openbadging: Year */
  $handler->display->display_options['fields']['field_badge_entity_year']['id'] = 'field_badge_entity_year';
  $handler->display->display_options['fields']['field_badge_entity_year']['table'] = 'field_data_field_badge_entity_year';
  $handler->display->display_options['fields']['field_badge_entity_year']['field'] = 'field_badge_entity_year';
  $handler->display->display_options['fields']['field_badge_entity_year']['label'] = '';
  $handler->display->display_options['fields']['field_badge_entity_year']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_badge_entity_year']['type'] = 'taxonomy_term_reference_plain';
  /* Contextual filter: openbadging: openbadging ID */
  $handler->display->display_options['arguments']['bid']['id'] = 'bid';
  $handler->display->display_options['arguments']['bid']['table'] = 'openbadging';
  $handler->display->display_options['arguments']['bid']['field'] = 'bid';
  $handler->display->display_options['arguments']['bid']['default_action'] = 'default';
  $handler->display->display_options['arguments']['bid']['default_argument_type'] = 'user';
  $handler->display->display_options['arguments']['bid']['default_argument_options']['user'] = FALSE;
  $handler->display->display_options['arguments']['bid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['bid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['bid']['summary_options']['items_per_page'] = '25';
  /* Filter criterion: openbadging: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'openbadging';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'badges' => 'badges',
  );

  /* Display: Block */
  $handler = $view->new_display('block', 'Block', 'block_1');
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
  $handler->display->display_options['defaults']['access'] = FALSE;
  $handler->display->display_options['access']['type'] = 'role';
  $handler->display->display_options['access']['role'] = array(
    3 => '3',
  );
  $export['badge_manager_earner'] = $view;

	$view = new view();
	$view->name = 'badge_maneger';
	$view->description = '';
	$view->tag = 'default';
	$view->base_table = 'openbadging';
	$view->human_name = 'badge maneger';
	$view->core = 7;
	$view->api_version = '3.0';
	$view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

	/* Display: Master */
	$handler = $view->new_display('default', 'Master', 'default');
	$handler->display->display_options['title'] = 'Badges';
	$handler->display->display_options['use_ajax'] = TRUE;
	$handler->display->display_options['use_more_always'] = FALSE;
	$handler->display->display_options['access']['type'] = 'role';
	$handler->display->display_options['access']['role'] = array(
		3 => '3',
		5 => '5',
	);
	$handler->display->display_options['cache']['type'] = 'none';
	$handler->display->display_options['query']['type'] = 'views_query';
	$handler->display->display_options['exposed_form']['type'] = 'basic';
	$handler->display->display_options['exposed_form']['options']['submit_button'] = 'Filter';
	$handler->display->display_options['pager']['type'] = 'none';
	$handler->display->display_options['pager']['options']['offset'] = '0';
	$handler->display->display_options['style_plugin'] = 'table';
	$handler->display->display_options['style_options']['columns'] = array(
		'bid' => 'bid',
		'views_bulk_operations' => 'views_bulk_operations',
		'url' => 'url',
		'title' => 'title',
		'field_badge_entity_program' => 'field_badge_entity_program',
		'php' => 'php',
	);
	$handler->display->display_options['style_options']['default'] = '-1';
	$handler->display->display_options['style_options']['info'] = array(
		'bid' => array(
			'sortable' => 0,
			'default_sort_order' => 'asc',
			'align' => '',
			'separator' => '',
			'empty_column' => 0,
		),
		'views_bulk_operations' => array(
			'align' => 'views-align-center',
			'separator' => '',
			'empty_column' => 0,
		),
		'url' => array(
			'align' => '',
			'separator' => '',
			'empty_column' => 0,
		),
		'title' => array(
			'sortable' => 1,
			'default_sort_order' => 'asc',
			'align' => 'views-align-left',
			'separator' => '',
			'empty_column' => 0,
		),
		'field_badge_entity_program' => array(
			'align' => 'views-align-left',
			'separator' => '',
			'empty_column' => 0,
		),
		'php' => array(
			'align' => 'views-align-left',
			'separator' => '',
			'empty_column' => 0,
		),
	);
	/* Field: Openbadging: Openbadging ID */
	$handler->display->display_options['fields']['bid']['id'] = 'bid';
	$handler->display->display_options['fields']['bid']['table'] = 'openbadging';
	$handler->display->display_options['fields']['bid']['field'] = 'bid';
	$handler->display->display_options['fields']['bid']['label'] = '';
	$handler->display->display_options['fields']['bid']['exclude'] = TRUE;
	$handler->display->display_options['fields']['bid']['element_label_colon'] = FALSE;
	/* Field: Bulk operations: Openbadging */
	$handler->display->display_options['fields']['views_bulk_operations']['id'] = 'views_bulk_operations';
	$handler->display->display_options['fields']['views_bulk_operations']['table'] = 'openbadging';
	$handler->display->display_options['fields']['views_bulk_operations']['field'] = 'views_bulk_operations';
	$handler->display->display_options['fields']['views_bulk_operations']['label'] = '';
	$handler->display->display_options['fields']['views_bulk_operations']['element_label_colon'] = FALSE;
	$handler->display->display_options['fields']['views_bulk_operations']['element_default_classes'] = FALSE;
	$handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['display_type'] = '0';
	$handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['enable_select_all_pages'] = 0;
	$handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['force_single'] = 0;
	$handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['display_result'] = 1;
	$handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['entity_load_capacity'] = '5000';
	$handler->display->display_options['fields']['views_bulk_operations']['vbo_operations'] = array(
		'action::views_bulk_operations_delete_item' => array(
			'selected' => 0,
			'use_queue' => 0,
			'skip_confirmation' => 0,
			'override_label' => 0,
			'label' => '',
		),
		'action::system_message_action' => array(
			'selected' => 0,
			'use_queue' => 0,
			'skip_confirmation' => 0,
			'override_label' => 0,
			'label' => '',
		),
		'action::views_bulk_operations_script_action' => array(
			'selected' => 0,
			'use_queue' => 0,
			'skip_confirmation' => 0,
			'override_label' => 1,
			'label' => 'Take Away',
		),
		'action::openbadging_badge_manager_give_achievements' => array(
			'selected' => 1,
			'use_queue' => 0,
			'skip_confirmation' => 1,
			'override_label' => 0,
			'label' => '',
		),
		'action::views_bulk_operations_modify_action' => array(
			'selected' => 0,
			'use_queue' => 0,
			'skip_confirmation' => 0,
			'override_label' => 0,
			'label' => '',
			'settings' => array(
				'show_all_tokens' => 0,
				'display_values' => array(
					'_all_' => '_all_',
				),
			),
		),
		'action::notify_admin_to_delete_user' => array(
			'selected' => 0,
			'use_queue' => 0,
			'skip_confirmation' => 0,
			'override_label' => 0,
			'label' => '',
		),
		'action::views_bulk_operations_argument_selector_action' => array(
			'selected' => 0,
			'skip_confirmation' => 0,
			'override_label' => 1,
			'label' => 'give openbadging',
			'settings' => array(
				'url' => 'admin/give/openbadging/69',
			),
		),
		'action::system_goto_action' => array(
			'selected' => 0,
			'use_queue' => 1,
			'skip_confirmation' => 1,
			'override_label' => 0,
			'label' => '',
		),
		'action::resend_badge_notification_mail' => array(
			'selected' => 0,
			'use_queue' => 0,
			'skip_confirmation' => 0,
			'override_label' => 0,
			'label' => '',
		),
		'action::openbadging_badge_manager_take_achievements' => array(
			'selected' => 1,
			'use_queue' => 0,
			'skip_confirmation' => 1,
			'override_label' => 0,
			'label' => '',
		),
		'action::system_send_email_action' => array(
			'selected' => 0,
			'use_queue' => 0,
			'skip_confirmation' => 0,
			'override_label' => 0,
			'label' => '',
		),
	);
	/* Field: Openbadging: URL */
	$handler->display->display_options['fields']['url']['id'] = 'url';
	$handler->display->display_options['fields']['url']['table'] = 'views_entity_openbadging';
	$handler->display->display_options['fields']['url']['field'] = 'url';
	$handler->display->display_options['fields']['url']['label'] = '';
	$handler->display->display_options['fields']['url']['exclude'] = TRUE;
	$handler->display->display_options['fields']['url']['element_label_colon'] = FALSE;
	$handler->display->display_options['fields']['url']['display_as_link'] = FALSE;
	$handler->display->display_options['fields']['url']['link_to_entity'] = 0;
	/* Field: Openbadging: Title */
	$handler->display->display_options['fields']['title']['id'] = 'title';
	$handler->display->display_options['fields']['title']['table'] = 'openbadging';
	$handler->display->display_options['fields']['title']['field'] = 'title';
	$handler->display->display_options['fields']['title']['label'] = 'Badge Name';
	$handler->display->display_options['fields']['title']['alter']['make_link'] = TRUE;
	$handler->display->display_options['fields']['title']['alter']['path'] = '[url]';
	$handler->display->display_options['fields']['title']['alter']['absolute'] = TRUE;
	$handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
	/* Field: Field: Program */
	$handler->display->display_options['fields']['field_badge_entity_program']['id'] = 'field_badge_entity_program';
	$handler->display->display_options['fields']['field_badge_entity_program']['table'] = 'field_data_field_badge_entity_program';
	$handler->display->display_options['fields']['field_badge_entity_program']['field'] = 'field_badge_entity_program';
	$handler->display->display_options['fields']['field_badge_entity_program']['element_label_colon'] = FALSE;
	$handler->display->display_options['fields']['field_badge_entity_program']['type'] = 'taxonomy_term_reference_plain';
	$handler->display->display_options['fields']['field_badge_entity_program']['delta_offset'] = '0';
	/* Field: Global: PHP */
	$handler->display->display_options['fields']['php']['id'] = 'php';
	$handler->display->display_options['fields']['php']['table'] = 'views';
	$handler->display->display_options['fields']['php']['field'] = 'php';
	$handler->display->display_options['fields']['php']['label'] = 'Status';
	$handler->display->display_options['fields']['php']['element_label_colon'] = FALSE;
	$handler->display->display_options['fields']['php']['use_php_setup'] = 0;
	$handler->display->display_options['fields']['php']['php_setup'] = 'foreach($row->title as $row->title)';
	$handler->display->display_options['fields']['php']['php_output'] = '<?php 
	$status = openbadging_check_badge_awared($row->bid,arg(2));
	echo $status;
	 ?>';
	$handler->display->display_options['fields']['php']['use_php_click_sortable'] = '0';
	$handler->display->display_options['fields']['php']['php_click_sortable'] = '';
	/* Sort criterion: Openbadging: Title */
	$handler->display->display_options['sorts']['title']['id'] = 'title';
	$handler->display->display_options['sorts']['title']['table'] = 'openbadging';
	$handler->display->display_options['sorts']['title']['field'] = 'title';
	/* Filter criterion: Openbadging: Type */
	$handler->display->display_options['filters']['type']['id'] = 'type';
	$handler->display->display_options['filters']['type']['table'] = 'openbadging';
	$handler->display->display_options['filters']['type']['field'] = 'type';
	$handler->display->display_options['filters']['type']['value'] = array(
		'badges' => 'badges',
	);
	/* Filter criterion: Field: Program (field_badge_entity_program) */
	$handler->display->display_options['filters']['field_badge_entity_program_tid']['id'] = 'field_badge_entity_program_tid';
	$handler->display->display_options['filters']['field_badge_entity_program_tid']['table'] = 'field_data_field_badge_entity_program';
	$handler->display->display_options['filters']['field_badge_entity_program_tid']['field'] = 'field_badge_entity_program_tid';
	$handler->display->display_options['filters']['field_badge_entity_program_tid']['operator'] = 'and';
	$handler->display->display_options['filters']['field_badge_entity_program_tid']['exposed'] = TRUE;
	$handler->display->display_options['filters']['field_badge_entity_program_tid']['expose']['operator_id'] = 'field_badge_entity_program_tid_op';
	$handler->display->display_options['filters']['field_badge_entity_program_tid']['expose']['label'] = 'Filter By Program';
	$handler->display->display_options['filters']['field_badge_entity_program_tid']['expose']['operator'] = 'field_badge_entity_program_tid_op';
	$handler->display->display_options['filters']['field_badge_entity_program_tid']['expose']['identifier'] = 'field_badge_entity_program_tid';
	$handler->display->display_options['filters']['field_badge_entity_program_tid']['expose']['remember_roles'] = array(
		2 => '2',
		1 => 0,
		3 => 0,
		4 => 0,
		5 => 0,
		6 => 0,
	);
	$handler->display->display_options['filters']['field_badge_entity_program_tid']['group_info']['label'] = 'Program (field_badge_entity_program)';
	$handler->display->display_options['filters']['field_badge_entity_program_tid']['group_info']['identifier'] = 'field_badge_entity_program_tid';
	$handler->display->display_options['filters']['field_badge_entity_program_tid']['group_info']['remember'] = FALSE;
	$handler->display->display_options['filters']['field_badge_entity_program_tid']['group_info']['group_items'] = array(
		1 => array(),
		2 => array(),
		3 => array(),
	);
	$handler->display->display_options['filters']['field_badge_entity_program_tid']['type'] = 'select';
	$handler->display->display_options['filters']['field_badge_entity_program_tid']['vocabulary'] = 'program';
	$handler->display->display_options['filters']['field_badge_entity_program_tid']['error_message'] = FALSE;
	/* Filter criterion: Openbadging: Year (field_badge_entity_year) */
	$handler->display->display_options['filters']['field_badge_entity_year_tid']['id'] = 'field_badge_entity_year_tid';
	$handler->display->display_options['filters']['field_badge_entity_year_tid']['table'] = 'field_data_field_badge_entity_year';
	$handler->display->display_options['filters']['field_badge_entity_year_tid']['field'] = 'field_badge_entity_year_tid';
	$handler->display->display_options['filters']['field_badge_entity_year_tid']['operator'] = 'and';
	$handler->display->display_options['filters']['field_badge_entity_year_tid']['exposed'] = TRUE;
	$handler->display->display_options['filters']['field_badge_entity_year_tid']['expose']['operator_id'] = 'field_badge_entity_year_tid_op';
	$handler->display->display_options['filters']['field_badge_entity_year_tid']['expose']['label'] = 'Filter By Year ';
	$handler->display->display_options['filters']['field_badge_entity_year_tid']['expose']['operator'] = 'field_badge_entity_year_tid_op';
	$handler->display->display_options['filters']['field_badge_entity_year_tid']['expose']['identifier'] = 'field_badge_entity_year_tid';
	$handler->display->display_options['filters']['field_badge_entity_year_tid']['expose']['remember_roles'] = array(
		2 => '2',
		1 => 0,
		3 => 0,
		4 => 0,
		5 => 0,
		6 => 0,
	);
	$handler->display->display_options['filters']['field_badge_entity_year_tid']['type'] = 'select';
	$handler->display->display_options['filters']['field_badge_entity_year_tid']['vocabulary'] = 'year';
	$handler->display->display_options['filters']['field_badge_entity_year_tid']['error_message'] = FALSE;
	/* Filter criterion: Openbadging: Title */
	$handler->display->display_options['filters']['title']['id'] = 'title';
	$handler->display->display_options['filters']['title']['table'] = 'openbadging';
	$handler->display->display_options['filters']['title']['field'] = 'title';
	$handler->display->display_options['filters']['title']['exposed'] = TRUE;
	$handler->display->display_options['filters']['title']['expose']['operator_id'] = 'title_op';
	$handler->display->display_options['filters']['title']['expose']['label'] = 'Title';
	$handler->display->display_options['filters']['title']['expose']['operator'] = 'title_op';
	$handler->display->display_options['filters']['title']['expose']['identifier'] = 'title';

	/* Display: Page */
	$handler = $view->new_display('page', 'Page', 'page_1');
	$handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
	$handler->display->display_options['defaults']['exposed_form'] = FALSE;
	$handler->display->display_options['exposed_form']['type'] = 'basic';
	$handler->display->display_options['exposed_form']['options']['submit_button'] = 'Filter';
	$handler->display->display_options['exposed_form']['options']['reset_button'] = TRUE;
	$handler->display->display_options['defaults']['pager'] = FALSE;
	$handler->display->display_options['pager']['type'] = 'full';
	$handler->display->display_options['pager']['options']['items_per_page'] = '25';
	$handler->display->display_options['pager']['options']['offset'] = '0';
	$handler->display->display_options['pager']['options']['id'] = '0';
	$handler->display->display_options['pager']['options']['quantity'] = '9';
	$handler->display->display_options['defaults']['filter_groups'] = FALSE;
	$handler->display->display_options['defaults']['filters'] = FALSE;
	/* Filter criterion: Openbadging: Type */
	$handler->display->display_options['filters']['type']['id'] = 'type';
	$handler->display->display_options['filters']['type']['table'] = 'openbadging';
	$handler->display->display_options['filters']['type']['field'] = 'type';
	$handler->display->display_options['filters']['type']['value'] = array(
		'badges' => 'badges',
	);
	$handler->display->display_options['filters']['type']['group'] = 1;
	$handler->display->display_options['filters']['type']['expose']['operator_id'] = 'type_op';
	$handler->display->display_options['filters']['type']['expose']['label'] = 'Type';
	$handler->display->display_options['filters']['type']['expose']['operator'] = 'type_op';
	$handler->display->display_options['filters']['type']['expose']['identifier'] = 'type';
	$handler->display->display_options['filters']['type']['expose']['remember_roles'] = array(
		2 => '2',
		1 => 0,
		3 => 0,
		4 => 0,
		5 => 0,
		6 => 0,
	);
	/* Filter criterion: Openbadging: Title */
	$handler->display->display_options['filters']['title']['id'] = 'title';
	$handler->display->display_options['filters']['title']['table'] = 'openbadging';
	$handler->display->display_options['filters']['title']['field'] = 'title';
	$handler->display->display_options['filters']['title']['operator'] = 'allwords';
	$handler->display->display_options['filters']['title']['group'] = 1;
	$handler->display->display_options['filters']['title']['exposed'] = TRUE;
	$handler->display->display_options['filters']['title']['expose']['operator_id'] = 'title_op';
	$handler->display->display_options['filters']['title']['expose']['label'] = 'Badge Title';
	$handler->display->display_options['filters']['title']['expose']['description'] = 'Enter text to Search by Badge name.';
	$handler->display->display_options['filters']['title']['expose']['operator'] = 'title_op';
	$handler->display->display_options['filters']['title']['expose']['identifier'] = 'title';
	$handler->display->display_options['filters']['title']['expose']['remember_roles'] = array(
		2 => '2',
		1 => 0,
		3 => 0,
		5 => 0,
		4 => 0,
		6 => 0,
	);
	$handler->display->display_options['filters']['title']['group_info']['label'] = 'Title';
	$handler->display->display_options['filters']['title']['group_info']['identifier'] = 'title';
	$handler->display->display_options['filters']['title']['group_info']['group_items'] = array(
		1 => array(
			'title' => 'dfdf',
			'operator' => 'allwords',
			'value' => 'dgfdgd',
		),
		2 => array(
			'title' => '',
			'operator' => 'allwords',
			'value' => '',
		),
		3 => array(
			'title' => '',
			'operator' => 'allwords',
			'value' => '',
		),
	);
	/* Filter criterion: Field: Program (field_badge_entity_program) */
	$handler->display->display_options['filters']['field_badge_entity_program_tid']['id'] = 'field_badge_entity_program_tid';
	$handler->display->display_options['filters']['field_badge_entity_program_tid']['table'] = 'field_data_field_badge_entity_program';
	$handler->display->display_options['filters']['field_badge_entity_program_tid']['field'] = 'field_badge_entity_program_tid';
	$handler->display->display_options['filters']['field_badge_entity_program_tid']['operator'] = 'and';
	$handler->display->display_options['filters']['field_badge_entity_program_tid']['group'] = 1;
	$handler->display->display_options['filters']['field_badge_entity_program_tid']['exposed'] = TRUE;
	$handler->display->display_options['filters']['field_badge_entity_program_tid']['expose']['operator_id'] = 'field_badge_entity_program_tid_op';
	$handler->display->display_options['filters']['field_badge_entity_program_tid']['expose']['label'] = 'Filter By Program';
	$handler->display->display_options['filters']['field_badge_entity_program_tid']['expose']['operator'] = 'field_badge_entity_program_tid_op';
	$handler->display->display_options['filters']['field_badge_entity_program_tid']['expose']['identifier'] = 'field_badge_entity_program_tid';
	$handler->display->display_options['filters']['field_badge_entity_program_tid']['expose']['remember_roles'] = array(
		2 => '2',
		1 => 0,
		3 => 0,
		4 => 0,
		5 => 0,
		6 => 0,
	);
	$handler->display->display_options['filters']['field_badge_entity_program_tid']['group_info']['label'] = 'Program (field_badge_entity_program)';
	$handler->display->display_options['filters']['field_badge_entity_program_tid']['group_info']['identifier'] = 'field_badge_entity_program_tid';
	$handler->display->display_options['filters']['field_badge_entity_program_tid']['group_info']['remember'] = FALSE;
	$handler->display->display_options['filters']['field_badge_entity_program_tid']['group_info']['group_items'] = array(
		1 => array(),
		2 => array(),
		3 => array(),
	);
	$handler->display->display_options['filters']['field_badge_entity_program_tid']['type'] = 'select';
	$handler->display->display_options['filters']['field_badge_entity_program_tid']['vocabulary'] = 'program';
	$handler->display->display_options['filters']['field_badge_entity_program_tid']['error_message'] = FALSE;
	/* Filter criterion: Openbadging: Year (field_badge_entity_year) */
	$handler->display->display_options['filters']['field_badge_entity_year_tid']['id'] = 'field_badge_entity_year_tid';
	$handler->display->display_options['filters']['field_badge_entity_year_tid']['table'] = 'field_data_field_badge_entity_year';
	$handler->display->display_options['filters']['field_badge_entity_year_tid']['field'] = 'field_badge_entity_year_tid';
	$handler->display->display_options['filters']['field_badge_entity_year_tid']['operator'] = 'and';
	$handler->display->display_options['filters']['field_badge_entity_year_tid']['group'] = 1;
	$handler->display->display_options['filters']['field_badge_entity_year_tid']['exposed'] = TRUE;
	$handler->display->display_options['filters']['field_badge_entity_year_tid']['expose']['operator_id'] = 'field_badge_entity_year_tid_op';
	$handler->display->display_options['filters']['field_badge_entity_year_tid']['expose']['label'] = 'Filter By Year ';
	$handler->display->display_options['filters']['field_badge_entity_year_tid']['expose']['operator'] = 'field_badge_entity_year_tid_op';
	$handler->display->display_options['filters']['field_badge_entity_year_tid']['expose']['identifier'] = 'field_badge_entity_year_tid';
	$handler->display->display_options['filters']['field_badge_entity_year_tid']['expose']['remember_roles'] = array(
		2 => '2',
		1 => 0,
		3 => 0,
		4 => 0,
		5 => 0,
		6 => 0,
	);
	$handler->display->display_options['filters']['field_badge_entity_year_tid']['type'] = 'select';
	$handler->display->display_options['filters']['field_badge_entity_year_tid']['vocabulary'] = 'year';
	$handler->display->display_options['filters']['field_badge_entity_year_tid']['error_message'] = FALSE;
	/* Filter criterion: Openbadging: Published */
	$handler->display->display_options['filters']['status']['id'] = 'status';
	$handler->display->display_options['filters']['status']['table'] = 'openbadging';
	$handler->display->display_options['filters']['status']['field'] = 'status';
	$handler->display->display_options['filters']['status']['value']['value'] = '1';
	$handler->display->display_options['path'] = 'badge-manager/badges/%';

  $export['badge_maneger'] = $view;

  $view = new view();
  $view->name = 'earner_manager_default';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'users';
  $view->human_name = 'earner manager default';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Earners';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['access']['perm'] = 'access user profiles';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['exposed_form']['options']['reset_button'] = TRUE;
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '25';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['quantity'] = '9';
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'uid' => 'uid',
    'views_bulk_operations' => 'views_bulk_operations',
    'name' => 'name',
    'mail' => 'mail',
    'php' => 'php',
  );
  $handler->display->display_options['style_options']['default'] = '-1';
  $handler->display->display_options['style_options']['info'] = array(
    'uid' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'views_bulk_operations' => array(
      'align' => 'views-align-left',
      'separator' => '',
      'empty_column' => 0,
    ),
    'name' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'mail' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => 'views-align-left',
      'separator' => '',
      'empty_column' => 0,
    ),
    'php' => array(
      'align' => 'views-align-left',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  /* Field: User: Uid */
  $handler->display->display_options['fields']['uid']['id'] = 'uid';
  $handler->display->display_options['fields']['uid']['table'] = 'users';
  $handler->display->display_options['fields']['uid']['field'] = 'uid';
  $handler->display->display_options['fields']['uid']['label'] = '';
  $handler->display->display_options['fields']['uid']['exclude'] = TRUE;
  $handler->display->display_options['fields']['uid']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['uid']['link_to_user'] = FALSE;
  /* Field: Bulk operations: User */
  $handler->display->display_options['fields']['views_bulk_operations']['id'] = 'views_bulk_operations';
  $handler->display->display_options['fields']['views_bulk_operations']['table'] = 'users';
  $handler->display->display_options['fields']['views_bulk_operations']['field'] = 'views_bulk_operations';
  $handler->display->display_options['fields']['views_bulk_operations']['label'] = '';
  $handler->display->display_options['fields']['views_bulk_operations']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['display_type'] = '0';
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['enable_select_all_pages'] = 1;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['force_single'] = 0;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['display_result'] = 1;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['entity_load_capacity'] = '500';
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_operations'] = array(
    'action::system_block_ip_action' => array(
      'selected' => 0,
      'use_queue' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'action::user_block_user_action' => array(
      'selected' => 0,
      'use_queue' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'action::views_bulk_operations_delete_item' => array(
      'selected' => 0,
      'use_queue' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'action::system_message_action' => array(
      'selected' => 0,
      'use_queue' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'action::views_bulk_operations_script_action' => array(
      'selected' => 0,
      'use_queue' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'action::openbadging_badge_manager_give_achievements' => array(
      'selected' => 1,
      'use_queue' => 0,
      'skip_confirmation' => 1,
      'override_label' => 0,
      'label' => '',
    ),
    'action::views_bulk_operations_modify_action' => array(
      'selected' => 0,
      'use_queue' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
      'settings' => array(
        'show_all_tokens' => 1,
        'display_values' => array(
          '_all_' => '_all_',
        ),
      ),
    ),
    'action::views_bulk_operations_user_roles_action' => array(
      'selected' => 0,
      'use_queue' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'action::views_bulk_operations_argument_selector_action' => array(
      'selected' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
      'settings' => array(
        'url' => '',
      ),
    ),
    'action::system_goto_action' => array(
      'selected' => 0,
      'use_queue' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'action::system_send_email_action' => array(
      'selected' => 0,
      'use_queue' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
    ),
    'action::openbadging_badge_manager_take_achievements' => array(
      'selected' => 1,
      'use_queue' => 0,
      'skip_confirmation' => 1,
      'override_label' => 0,
      'label' => '',
    ),
  );
  /* Field: User: Name */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'users';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['label'] = 'User Name';
  $handler->display->display_options['fields']['name']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['name']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['name']['element_label_colon'] = FALSE;
  /* Field: User: E-mail */
  $handler->display->display_options['fields']['mail']['id'] = 'mail';
  $handler->display->display_options['fields']['mail']['table'] = 'users';
  $handler->display->display_options['fields']['mail']['field'] = 'mail';
  $handler->display->display_options['fields']['mail']['label'] = 'User E-mail';
  $handler->display->display_options['fields']['mail']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['mail']['link_to_user'] = 'user';
  /* Field: Global: PHP */
  $handler->display->display_options['fields']['php']['id'] = 'php';
  $handler->display->display_options['fields']['php']['table'] = 'views';
  $handler->display->display_options['fields']['php']['field'] = 'php';
  $handler->display->display_options['fields']['php']['label'] = 'Status';
  $handler->display->display_options['fields']['php']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['php']['use_php_setup'] = 0;
  $handler->display->display_options['fields']['php']['php_output'] = '<?php 
$static = openbadging_check_badge_awared(arg(2),$row->uid);
echo $static;
 ?>';
  $handler->display->display_options['fields']['php']['use_php_click_sortable'] = '0';
  $handler->display->display_options['fields']['php']['php_click_sortable'] = '';
  /* Sort criterion: User: Created date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'users';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  /* Filter criterion: User: Active */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'users';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = '1';
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: User: Name */
  $handler->display->display_options['filters']['uid']['id'] = 'uid';
  $handler->display->display_options['filters']['uid']['table'] = 'users';
  $handler->display->display_options['filters']['uid']['field'] = 'uid';
  $handler->display->display_options['filters']['uid']['value'] = '';
  $handler->display->display_options['filters']['uid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['uid']['expose']['operator_id'] = 'uid_op';
  $handler->display->display_options['filters']['uid']['expose']['label'] = 'Search By Name';
  $handler->display->display_options['filters']['uid']['expose']['operator'] = 'uid_op';
  $handler->display->display_options['filters']['uid']['expose']['identifier'] = 'uid';
  $handler->display->display_options['filters']['uid']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    5 => 0,
    4 => 0,
  );
  /* Filter criterion: User: E-mail */
  $handler->display->display_options['filters']['mail']['id'] = 'mail';
  $handler->display->display_options['filters']['mail']['table'] = 'users';
  $handler->display->display_options['filters']['mail']['field'] = 'mail';
  $handler->display->display_options['filters']['mail']['operator'] = 'allwords';
  $handler->display->display_options['filters']['mail']['exposed'] = TRUE;
  $handler->display->display_options['filters']['mail']['expose']['operator_id'] = 'mail_op';
  $handler->display->display_options['filters']['mail']['expose']['label'] = 'Search By E-mail';
  $handler->display->display_options['filters']['mail']['expose']['operator'] = 'mail_op';
  $handler->display->display_options['filters']['mail']['expose']['identifier'] = 'mail';
  $handler->display->display_options['filters']['mail']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    5 => 0,
    4 => 0,
  );

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
  $handler->display->display_options['path'] = 'badge-manager/earner/%';
  $export['earner_manager_default'] = $view;

  $view = new view();
  $view->name = 'open_badge_manager_user';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'users';
  $view->human_name = 'open badge manager user';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'open badge manager user';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['access']['perm'] = 'administer permissions';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Relationship: User: Profile */
  $handler->display->display_options['relationships']['profile']['id'] = 'profile';
  $handler->display->display_options['relationships']['profile']['table'] = 'users';
  $handler->display->display_options['relationships']['profile']['field'] = 'profile';
  /* Field: Profile: Profile Image */
  $handler->display->display_options['fields']['field_main_profile_image']['id'] = 'field_main_profile_image';
  $handler->display->display_options['fields']['field_main_profile_image']['table'] = 'field_data_field_main_profile_image';
  $handler->display->display_options['fields']['field_main_profile_image']['field'] = 'field_main_profile_image';
  $handler->display->display_options['fields']['field_main_profile_image']['relationship'] = 'profile';
  $handler->display->display_options['fields']['field_main_profile_image']['label'] = '';
  $handler->display->display_options['fields']['field_main_profile_image']['empty'] = '<img src= "/sites/all/modules/ssp_open_badges/achievement_user_profile/images/isef_userprofile_200x200.gif" class="user-default-image" />';
  $handler->display->display_options['fields']['field_main_profile_image']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_main_profile_image']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_main_profile_image']['settings'] = array(
    'image_style' => '110_110',
    'image_link' => '',
  );
  /* Field: User: Name */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'users';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['label'] = '';
  $handler->display->display_options['fields']['name']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['name']['alter']['ellipsis'] = FALSE;
  /* Field: User: E-mail */
  $handler->display->display_options['fields']['mail']['id'] = 'mail';
  $handler->display->display_options['fields']['mail']['table'] = 'users';
  $handler->display->display_options['fields']['mail']['field'] = 'mail';
  $handler->display->display_options['fields']['mail']['label'] = '';
  $handler->display->display_options['fields']['mail']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['mail']['link_to_user'] = '0';
  /* Field: Profile: Participation Level */
  $handler->display->display_options['fields']['field_main_profile_part_level']['id'] = 'field_main_profile_part_level';
  $handler->display->display_options['fields']['field_main_profile_part_level']['table'] = 'field_data_field_main_profile_part_level';
  $handler->display->display_options['fields']['field_main_profile_part_level']['field'] = 'field_main_profile_part_level';
  $handler->display->display_options['fields']['field_main_profile_part_level']['relationship'] = 'profile';
  $handler->display->display_options['fields']['field_main_profile_part_level']['label'] = '';
  $handler->display->display_options['fields']['field_main_profile_part_level']['element_label_colon'] = FALSE;
  /* Field: Profile: Organization */
  $handler->display->display_options['fields']['field_main_profile_org']['id'] = 'field_main_profile_org';
  $handler->display->display_options['fields']['field_main_profile_org']['table'] = 'field_data_field_main_profile_org';
  $handler->display->display_options['fields']['field_main_profile_org']['field'] = 'field_main_profile_org';
  $handler->display->display_options['fields']['field_main_profile_org']['relationship'] = 'profile';
  $handler->display->display_options['fields']['field_main_profile_org']['label'] = '';
  $handler->display->display_options['fields']['field_main_profile_org']['element_label_colon'] = FALSE;
  /* Sort criterion: User: Created date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'users';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  /* Contextual filter: Profile: User uid */
  $handler->display->display_options['arguments']['user']['id'] = 'user';
  $handler->display->display_options['arguments']['user']['table'] = 'profile';
  $handler->display->display_options['arguments']['user']['field'] = 'user';
  $handler->display->display_options['arguments']['user']['relationship'] = 'profile';
  $handler->display->display_options['arguments']['user']['default_action'] = 'default';
  $handler->display->display_options['arguments']['user']['default_argument_type'] = 'user';
  $handler->display->display_options['arguments']['user']['default_argument_options']['user'] = FALSE;
  $handler->display->display_options['arguments']['user']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['user']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['user']['summary_options']['items_per_page'] = '25';
  /* Filter criterion: User: Active */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'users';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = '1';
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;

  /* Display: Block */
  $handler = $view->new_display('block', 'Block', 'block_1');
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
  $handler->display->display_options['defaults']['access'] = FALSE;
  $handler->display->display_options['access']['type'] = 'role';
  $handler->display->display_options['access']['role'] = array(
    3 => '3',
  );
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Profile: User uid */
  $handler->display->display_options['arguments']['user']['id'] = 'user';
  $handler->display->display_options['arguments']['user']['table'] = 'profile';
  $handler->display->display_options['arguments']['user']['field'] = 'user';
  $handler->display->display_options['arguments']['user']['relationship'] = 'profile';
  $handler->display->display_options['arguments']['user']['default_action'] = 'default';
  $handler->display->display_options['arguments']['user']['default_argument_type'] = 'user';
  $handler->display->display_options['arguments']['user']['default_argument_options']['user'] = FALSE;
  $handler->display->display_options['arguments']['user']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['user']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['user']['summary_options']['items_per_page'] = '25';
  $export['open_badge_manager_user'] = $view;

  return $export;
}

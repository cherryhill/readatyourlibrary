<?php

// $Id openbadging_notifications.admin.inc

/**
 * @file
 * Admin settings for openbadging notification.
 */

/**
 * openbadging notification mail setup for admin.
 */
function openbadging_notifications_settings() {

  $form['openbadging_notification_mail_subject'] = array(
    '#title' => t('Email Notification Subject'),
    '#type' => 'textfield',
    '#default_value' => variable_get('openbadging_notification_mail_subject', 'Congratulations %first_name! You received a badge from %issuer_name'),
  );

  $form['openbadging_notification_mail_before_login_body'] = array(
    '#title' => t('Email Notification Text For Unregistered Users'),
    '#type' => 'textarea',
    '#default_value' => variable_get('openbadging_notification_mail_before_login_body', 'Congratulations %first_name,
      
You have been awarded with %badge_name by %issuer_name

Issuer details: 
Origin - %issuer_origin
Name - %issuer_name
Contact - %issuer_contact

Badge details:
Version - %badge_name
Name - %badge_version
Description - %badge_description

Go to %one-time-login-url to view your badge. You can change the privacy setting of your badge from My Backpack. Go to My Backpack, create a group, assign badges to group and then change its privacy.'),
    '#description' => t('Edit the e-mail messages sent to users when badge award to user.'),
  );

  $form['openbadging_notification_mail_after_login_body'] = array(
    '#title' => t('Email Notification Text For Registered Users'),
    '#type' => 'textarea',
    '#default_value' => variable_get('openbadging_notification_mail_after_login_body', 'Congratulations %first_name,
You have been awarded with %badge_name by %issuer_name

Issuer details: 
Origin - %issuer_origin
Name - %issuer_name
Contact - %issuer_contact

Badge details:
Version - %badge_name
Name - %badge_version
Description - %badge_description

Go to %login_url to view your badge. You can change the privacy setting of your badge from My Backpack. Go to My Backpack, create a group, assign badges to group and then change its privacy.'),
    '#description' => t('Edit the e-mail messages sent to users when badge award to user.'),
  );
  return system_settings_form($form);
}

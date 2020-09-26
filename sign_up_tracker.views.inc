<?php

/**
 * @file
 * Views integration for the Login Tracker module.
 */

/**
 * Implements hook_views_data().
 */
function sign_up_tracker_views_data() {
  $data = [];
  $data['sign_up_tracker']['table']['group'] = t('User Sign Up Tracker');
  $data['sign_up_tracker']['table']['base'] = [
    'field' => 'id',
    'title' => t('User Sign Up Tracker'),
    'help'  => t('Contains data about user sign up.'),
  ];
  $data['sign_up_tracker']['table']['join'] = [
    'users_field_data' => [
      'left_field' => 'uid',
      'field'      => 'uid',
    ],
  ];
  // The UID field.
  $data['sign_up_tracker']['id'] = [
    'title' => t('SignUp record ID'),
    'help'  => t("The unique ID referring to this sign up record."),
    'field' => [
      'id' => 'numeric',
    ],
    'sort' => [
      'id' => 'standard',
    ],
    'filter' => [
      'title' => t('ID'),
      'id' => 'numeric',
    ],
  ];
  $data['sign_up_tracker']['uid'] = [
    'title' => t('UID'),
    'help'  => t("The user's UID."),
    'field' => [
      'id' => 'numeric',
    ],
    'sort' => [
      'id' => 'standard',
    ],
    'filter' => [
      'title' => t('UID'),
      'id' => 'numeric',
    ],
    'relationship' => [
      'title'              => t('User who signed up'),
      'help'               => t('The user associated with the sign up record.'),
      'id'                 => 'standard',
      'base'               => 'users_field_data',
      'base field'         => 'uid',
      'field'              => 'uid',
      'label'              => t('User who logged in'),
    ],
  ];
  // The sign u timestamp field.
  $data['sign_up_tracker']['created'] = [
    'title'  => t('Sign Up timestamp'),
    'help'   => t('The timestamp that the user logged in at.'),
    'field'  => [
      'id' => 'date',
    ],
    'sort'   => [
      'id' => 'date',
    ],
    'filter' => [
      'id' => 'date',
    ],
  ];
  $data['sign_up_tracker']['user_agent'] = [
    'title' => t('Sign Up user agent'),
    'help'  => t('Sign Up record information.'),
    'field' => [
      'id'             => 'serialized',
      'click sortable' => FALSE,
    ],
    'sort' => [
      'id' => 'standard',
    ],
    'filter' => [
      'id' => 'string',
    ],
  ];
  $data['sign_up_tracker']['ip'] = [
    'title' => t('Sign Up IP Address'),
    'help'  => t('User IP Address.'),
    'field' => [
      'id'             => 'serialized',
      'click sortable' => FALSE,
    ],
    'sort' => [
      'id' => 'standard',
    ],
    'filter' => [
      'id' => 'string',
    ],
  ];
  return $data;
}

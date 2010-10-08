<?php

/**
 * Implementation of hook_user_default_permissions().
 */
function person_to_person_user_default_permissions() {
  $permissions = array();

  // Exported permission: create experience content
  $permissions['create experience content'] = array(
    'name' => 'create experience content',
    'roles' => array(),
  );

  // Exported permission: create guest content
  $permissions['create guest content'] = array(
    'name' => 'create guest content',
    'roles' => array(
      '0' => 'guest',
      '1' => 'p2p admin',
    ),
  );

  // Exported permission: create host content
  $permissions['create host content'] = array(
    'name' => 'create host content',
    'roles' => array(
      '0' => 'host',
      '1' => 'p2p admin',
    ),
  );

  // Exported permission: create offer content
  $permissions['create offer content'] = array(
    'name' => 'create offer content',
    'roles' => array(),
  );

  // Exported permission: delete any experience content
  $permissions['delete any experience content'] = array(
    'name' => 'delete any experience content',
    'roles' => array(),
  );

  // Exported permission: delete any guest content
  $permissions['delete any guest content'] = array(
    'name' => 'delete any guest content',
    'roles' => array(
      '0' => 'p2p admin',
    ),
  );

  // Exported permission: delete any host content
  $permissions['delete any host content'] = array(
    'name' => 'delete any host content',
    'roles' => array(
      '0' => 'p2p admin',
    ),
  );

  // Exported permission: delete any offer content
  $permissions['delete any offer content'] = array(
    'name' => 'delete any offer content',
    'roles' => array(),
  );

  // Exported permission: delete own guest content
  $permissions['delete own guest content'] = array(
    'name' => 'delete own guest content',
    'roles' => array(),
  );

  // Exported permission: delete own host content
  $permissions['delete own host content'] = array(
    'name' => 'delete own host content',
    'roles' => array(),
  );

  // Exported permission: delete own offer content
  $permissions['delete own offer content'] = array(
    'name' => 'delete own offer content',
    'roles' => array(),
  );

  // Exported permission: edit any experience content
  $permissions['edit any experience content'] = array(
    'name' => 'edit any experience content',
    'roles' => array(),
  );

  // Exported permission: edit any guest content
  $permissions['edit any guest content'] = array(
    'name' => 'edit any guest content',
    'roles' => array(
      '0' => 'p2p admin',
    ),
  );

  // Exported permission: edit any host content
  $permissions['edit any host content'] = array(
    'name' => 'edit any host content',
    'roles' => array(
      '0' => 'p2p admin',
    ),
  );

  // Exported permission: edit any offer content
  $permissions['edit any offer content'] = array(
    'name' => 'edit any offer content',
    'roles' => array(),
  );

  // Exported permission: edit field_address1
  $permissions['edit field_address1'] = array(
    'name' => 'edit field_address1',
    'roles' => array(
      '0' => 'guest',
      '1' => 'p2p admin',
    ),
  );

  // Exported permission: edit field_address2
  $permissions['edit field_address2'] = array(
    'name' => 'edit field_address2',
    'roles' => array(
      '0' => 'guest',
      '1' => 'p2p admin',
    ),
  );

  // Exported permission: edit field_adults
  $permissions['edit field_adults'] = array(
    'name' => 'edit field_adults',
    'roles' => array(
      '0' => 'guest',
      '1' => 'p2p admin',
    ),
  );

  // Exported permission: edit field_adults_ages
  $permissions['edit field_adults_ages'] = array(
    'name' => 'edit field_adults_ages',
    'roles' => array(
      '0' => 'guest',
      '1' => 'p2p admin',
    ),
  );

  // Exported permission: edit field_age
  $permissions['edit field_age'] = array(
    'name' => 'edit field_age',
    'roles' => array(
      '0' => 'guest',
      '1' => 'p2p admin',
    ),
  );

  // Exported permission: edit field_anniversary
  $permissions['edit field_anniversary'] = array(
    'name' => 'edit field_anniversary',
    'roles' => array(
      '0' => 'guest',
      '1' => 'p2p admin',
    ),
  );

  // Exported permission: edit field_bahamas_address1
  $permissions['edit field_bahamas_address1'] = array(
    'name' => 'edit field_bahamas_address1',
    'roles' => array(
      '0' => 'guest',
      '1' => 'p2p admin',
    ),
  );

  // Exported permission: edit field_bahamas_address2
  $permissions['edit field_bahamas_address2'] = array(
    'name' => 'edit field_bahamas_address2',
    'roles' => array(
      '0' => 'guest',
      '1' => 'p2p admin',
    ),
  );

  // Exported permission: edit field_bahamas_hotel
  $permissions['edit field_bahamas_hotel'] = array(
    'name' => 'edit field_bahamas_hotel',
    'roles' => array(
      '0' => 'guest',
      '1' => 'p2p admin',
    ),
  );

  // Exported permission: edit field_bahamas_room
  $permissions['edit field_bahamas_room'] = array(
    'name' => 'edit field_bahamas_room',
    'roles' => array(
      '0' => 'guest',
      '1' => 'p2p admin',
    ),
  );

  // Exported permission: edit field_birthday
  $permissions['edit field_birthday'] = array(
    'name' => 'edit field_birthday',
    'roles' => array(
      '0' => 'guest',
      '1' => 'p2p admin',
    ),
  );

  // Exported permission: edit field_children
  $permissions['edit field_children'] = array(
    'name' => 'edit field_children',
    'roles' => array(
      '0' => 'guest',
      '1' => 'p2p admin',
    ),
  );

  // Exported permission: edit field_children_ages
  $permissions['edit field_children_ages'] = array(
    'name' => 'edit field_children_ages',
    'roles' => array(
      '0' => 'guest',
      '1' => 'p2p admin',
    ),
  );

  // Exported permission: edit field_city
  $permissions['edit field_city'] = array(
    'name' => 'edit field_city',
    'roles' => array(
      '0' => 'guest',
      '1' => 'p2p admin',
    ),
  );

  // Exported permission: edit field_club_affiliations
  $permissions['edit field_club_affiliations'] = array(
    'name' => 'edit field_club_affiliations',
    'roles' => array(
      '0' => 'guest',
      '1' => 'p2p admin',
    ),
  );

  // Exported permission: edit field_confirm_admin
  $permissions['edit field_confirm_admin'] = array(
    'name' => 'edit field_confirm_admin',
    'roles' => array(
      '0' => 'p2p admin',
    ),
  );

  // Exported permission: edit field_confirm_guest
  $permissions['edit field_confirm_guest'] = array(
    'name' => 'edit field_confirm_guest',
    'roles' => array(
      '0' => 'p2p admin',
    ),
  );

  // Exported permission: edit field_confirm_host
  $permissions['edit field_confirm_host'] = array(
    'name' => 'edit field_confirm_host',
    'roles' => array(
      '0' => 'p2p admin',
    ),
  );

  // Exported permission: edit field_country
  $permissions['edit field_country'] = array(
    'name' => 'edit field_country',
    'roles' => array(
      '0' => 'guest',
    ),
  );

  // Exported permission: edit field_group
  $permissions['edit field_group'] = array(
    'name' => 'edit field_group',
    'roles' => array(
      '0' => 'guest',
    ),
  );

  // Exported permission: edit field_guest
  $permissions['edit field_guest'] = array(
    'name' => 'edit field_guest',
    'roles' => array(
      '0' => 'p2p admin',
    ),
  );

  // Exported permission: edit field_hobbies
  $permissions['edit field_hobbies'] = array(
    'name' => 'edit field_hobbies',
    'roles' => array(
      '0' => 'guest',
    ),
  );

  // Exported permission: edit field_hobbies_other
  $permissions['edit field_hobbies_other'] = array(
    'name' => 'edit field_hobbies_other',
    'roles' => array(
      '0' => 'guest',
    ),
  );

  // Exported permission: edit field_home_phone
  $permissions['edit field_home_phone'] = array(
    'name' => 'edit field_home_phone',
    'roles' => array(
      '0' => 'guest',
    ),
  );

  // Exported permission: edit field_host
  $permissions['edit field_host'] = array(
    'name' => 'edit field_host',
    'roles' => array(
      '0' => 'p2p admin',
    ),
  );

  // Exported permission: edit field_occupation
  $permissions['edit field_occupation'] = array(
    'name' => 'edit field_occupation',
    'roles' => array(
      '0' => 'guest',
      '1' => 'p2p admin',
    ),
  );

  // Exported permission: edit field_occupation_other
  $permissions['edit field_occupation_other'] = array(
    'name' => 'edit field_occupation_other',
    'roles' => array(
      '0' => 'guest',
      '1' => 'p2p admin',
    ),
  );

  // Exported permission: edit field_pics
  $permissions['edit field_pics'] = array(
    'name' => 'edit field_pics',
    'roles' => array(
      '0' => 'guest',
      '1' => 'host',
      '2' => 'p2p admin',
    ),
  );

  // Exported permission: edit field_state
  $permissions['edit field_state'] = array(
    'name' => 'edit field_state',
    'roles' => array(
      '0' => 'guest',
      '1' => 'p2p admin',
    ),
  );

  // Exported permission: edit field_visit_dates
  $permissions['edit field_visit_dates'] = array(
    'name' => 'edit field_visit_dates',
    'roles' => array(
      '0' => 'guest',
      '1' => 'p2p admin',
    ),
  );

  // Exported permission: edit field_work_phone
  $permissions['edit field_work_phone'] = array(
    'name' => 'edit field_work_phone',
    'roles' => array(
      '0' => 'guest',
      '1' => 'p2p admin',
    ),
  );

  // Exported permission: edit field_zip
  $permissions['edit field_zip'] = array(
    'name' => 'edit field_zip',
    'roles' => array(
      '0' => 'guest',
      '1' => 'p2p admin',
    ),
  );

  // Exported permission: edit own experience content
  $permissions['edit own experience content'] = array(
    'name' => 'edit own experience content',
    'roles' => array(),
  );

  // Exported permission: edit own guest content
  $permissions['edit own guest content'] = array(
    'name' => 'edit own guest content',
    'roles' => array(
      '0' => 'guest',
    ),
  );

  // Exported permission: edit own host content
  $permissions['edit own host content'] = array(
    'name' => 'edit own host content',
    'roles' => array(
      '0' => 'host',
    ),
  );

  // Exported permission: edit own offer content
  $permissions['edit own offer content'] = array(
    'name' => 'edit own offer content',
    'roles' => array(),
  );

  // Exported permission: view field_address1
  $permissions['view field_address1'] = array(
    'name' => 'view field_address1',
    'roles' => array(
      '0' => 'guest',
      '1' => 'host',
      '2' => 'p2p admin',
    ),
  );

  // Exported permission: view field_address2
  $permissions['view field_address2'] = array(
    'name' => 'view field_address2',
    'roles' => array(
      '0' => 'guest',
      '1' => 'host',
      '2' => 'p2p admin',
    ),
  );

  // Exported permission: view field_adults
  $permissions['view field_adults'] = array(
    'name' => 'view field_adults',
    'roles' => array(
      '0' => 'guest',
      '1' => 'host',
      '2' => 'p2p admin',
    ),
  );

  // Exported permission: view field_adults_ages
  $permissions['view field_adults_ages'] = array(
    'name' => 'view field_adults_ages',
    'roles' => array(
      '0' => 'guest',
      '1' => 'host',
      '2' => 'p2p admin',
    ),
  );

  // Exported permission: view field_age
  $permissions['view field_age'] = array(
    'name' => 'view field_age',
    'roles' => array(
      '0' => 'guest',
      '1' => 'host',
      '2' => 'p2p admin',
    ),
  );

  // Exported permission: view field_anniversary
  $permissions['view field_anniversary'] = array(
    'name' => 'view field_anniversary',
    'roles' => array(
      '0' => 'guest',
      '1' => 'host',
      '2' => 'p2p admin',
    ),
  );

  // Exported permission: view field_bahamas_address1
  $permissions['view field_bahamas_address1'] = array(
    'name' => 'view field_bahamas_address1',
    'roles' => array(
      '0' => 'guest',
      '1' => 'host',
      '2' => 'p2p admin',
    ),
  );

  // Exported permission: view field_bahamas_address2
  $permissions['view field_bahamas_address2'] = array(
    'name' => 'view field_bahamas_address2',
    'roles' => array(
      '0' => 'guest',
      '1' => 'host',
      '2' => 'p2p admin',
    ),
  );

  // Exported permission: view field_bahamas_hotel
  $permissions['view field_bahamas_hotel'] = array(
    'name' => 'view field_bahamas_hotel',
    'roles' => array(
      '0' => 'guest',
      '1' => 'host',
      '2' => 'p2p admin',
    ),
  );

  // Exported permission: view field_bahamas_room
  $permissions['view field_bahamas_room'] = array(
    'name' => 'view field_bahamas_room',
    'roles' => array(
      '0' => 'guest',
      '1' => 'host',
      '2' => 'p2p admin',
    ),
  );

  // Exported permission: view field_birthday
  $permissions['view field_birthday'] = array(
    'name' => 'view field_birthday',
    'roles' => array(
      '0' => 'guest',
      '1' => 'host',
      '2' => 'p2p admin',
    ),
  );

  // Exported permission: view field_children
  $permissions['view field_children'] = array(
    'name' => 'view field_children',
    'roles' => array(
      '0' => 'guest',
      '1' => 'host',
      '2' => 'p2p admin',
    ),
  );

  // Exported permission: view field_children_ages
  $permissions['view field_children_ages'] = array(
    'name' => 'view field_children_ages',
    'roles' => array(
      '0' => 'guest',
      '1' => 'host',
      '2' => 'p2p admin',
    ),
  );

  // Exported permission: view field_city
  $permissions['view field_city'] = array(
    'name' => 'view field_city',
    'roles' => array(
      '0' => 'guest',
      '1' => 'host',
      '2' => 'p2p admin',
    ),
  );

  // Exported permission: view field_club_affiliations
  $permissions['view field_club_affiliations'] = array(
    'name' => 'view field_club_affiliations',
    'roles' => array(
      '0' => 'guest',
      '1' => 'host',
      '2' => 'p2p admin',
    ),
  );

  // Exported permission: view field_confirm_admin
  $permissions['view field_confirm_admin'] = array(
    'name' => 'view field_confirm_admin',
    'roles' => array(
      '0' => 'guest',
      '1' => 'host',
      '2' => 'p2p admin',
    ),
  );

  // Exported permission: view field_confirm_guest
  $permissions['view field_confirm_guest'] = array(
    'name' => 'view field_confirm_guest',
    'roles' => array(
      '0' => 'guest',
      '1' => 'host',
      '2' => 'p2p admin',
    ),
  );

  // Exported permission: view field_confirm_host
  $permissions['view field_confirm_host'] = array(
    'name' => 'view field_confirm_host',
    'roles' => array(
      '0' => 'guest',
      '1' => 'host',
      '2' => 'p2p admin',
    ),
  );

  // Exported permission: view field_country
  $permissions['view field_country'] = array(
    'name' => 'view field_country',
    'roles' => array(
      '0' => 'guest',
      '1' => 'host',
      '2' => 'p2p admin',
    ),
  );

  // Exported permission: view field_group
  $permissions['view field_group'] = array(
    'name' => 'view field_group',
    'roles' => array(
      '0' => 'guest',
      '1' => 'host',
      '2' => 'p2p admin',
    ),
  );

  // Exported permission: view field_guest
  $permissions['view field_guest'] = array(
    'name' => 'view field_guest',
    'roles' => array(
      '0' => 'guest',
      '1' => 'host',
      '2' => 'p2p admin',
    ),
  );

  // Exported permission: view field_hobbies
  $permissions['view field_hobbies'] = array(
    'name' => 'view field_hobbies',
    'roles' => array(
      '0' => 'guest',
      '1' => 'host',
      '2' => 'p2p admin',
    ),
  );

  // Exported permission: view field_hobbies_other
  $permissions['view field_hobbies_other'] = array(
    'name' => 'view field_hobbies_other',
    'roles' => array(
      '0' => 'guest',
      '1' => 'host',
      '2' => 'p2p admin',
    ),
  );

  // Exported permission: view field_home_phone
  $permissions['view field_home_phone'] = array(
    'name' => 'view field_home_phone',
    'roles' => array(
      '0' => 'guest',
      '1' => 'host',
      '2' => 'p2p admin',
    ),
  );

  // Exported permission: view field_host
  $permissions['view field_host'] = array(
    'name' => 'view field_host',
    'roles' => array(
      '0' => 'guest',
      '1' => 'host',
      '2' => 'p2p admin',
    ),
  );

  // Exported permission: view field_occupation
  $permissions['view field_occupation'] = array(
    'name' => 'view field_occupation',
    'roles' => array(
      '0' => 'guest',
      '1' => 'host',
      '2' => 'p2p admin',
    ),
  );

  // Exported permission: view field_occupation_other
  $permissions['view field_occupation_other'] = array(
    'name' => 'view field_occupation_other',
    'roles' => array(
      '0' => 'guest',
      '1' => 'host',
      '2' => 'p2p admin',
    ),
  );

  // Exported permission: view field_pics
  $permissions['view field_pics'] = array(
    'name' => 'view field_pics',
    'roles' => array(
      '0' => 'guest',
      '1' => 'host',
      '2' => 'p2p admin',
    ),
  );

  // Exported permission: view field_state
  $permissions['view field_state'] = array(
    'name' => 'view field_state',
    'roles' => array(
      '0' => 'guest',
      '1' => 'host',
      '2' => 'p2p admin',
    ),
  );

  // Exported permission: view field_visit_dates
  $permissions['view field_visit_dates'] = array(
    'name' => 'view field_visit_dates',
    'roles' => array(
      '0' => 'guest',
      '1' => 'host',
      '2' => 'p2p admin',
    ),
  );

  // Exported permission: view field_work_phone
  $permissions['view field_work_phone'] = array(
    'name' => 'view field_work_phone',
    'roles' => array(
      '0' => 'guest',
      '1' => 'host',
      '2' => 'p2p admin',
    ),
  );

  // Exported permission: view field_zip
  $permissions['view field_zip'] = array(
    'name' => 'view field_zip',
    'roles' => array(
      '0' => 'guest',
      '1' => 'host',
      '2' => 'p2p admin',
    ),
  );

  // Exported permission: view revisions
  $permissions['view revisions'] = array(
    'name' => 'view revisions',
    'roles' => array(
      '0' => 'p2p admin',
    ),
  );

  return $permissions;
}

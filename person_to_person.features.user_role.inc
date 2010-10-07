<?php

/**
 * Implementation of hook_user_default_roles().
 */
function person_to_person_user_default_roles() {
  $roles = array();

  // Exported role: guest
  $roles['guest'] = array(
    'name' => 'guest',
  );

  // Exported role: host
  $roles['host'] = array(
    'name' => 'host',
  );

  // Exported role: p2p admin
  $roles['p2p admin'] = array(
    'name' => 'p2p admin',
  );

  return $roles;
}

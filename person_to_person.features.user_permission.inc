<?php

/**
 * Implementation of hook_user_default_permissions().
 */
function person_to_person_user_default_permissions() {
  $permissions = array();

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

  // Exported permission: view revisions
  $permissions['view revisions'] = array(
    'name' => 'view revisions',
    'roles' => array(
      '0' => 'p2p admin',
    ),
  );

  return $permissions;
}

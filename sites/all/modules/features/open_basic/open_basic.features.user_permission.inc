<?php
/**
 * @file
 * open_basic.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function open_basic_user_default_permissions() {
  $permissions = array();

  // Exported permission: 'create open_basic_page content'.
  $permissions['create open_basic_page content'] = array(
    'name' => 'create open_basic_page content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'delete any open_basic_page content'.
  $permissions['delete any open_basic_page content'] = array(
    'name' => 'delete any open_basic_page content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'delete own open_basic_page content'.
  $permissions['delete own open_basic_page content'] = array(
    'name' => 'delete own open_basic_page content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'edit any open_basic_page content'.
  $permissions['edit any open_basic_page content'] = array(
    'name' => 'edit any open_basic_page content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'edit own open_basic_page content'.
  $permissions['edit own open_basic_page content'] = array(
    'name' => 'edit own open_basic_page content',
    'roles' => array(),
    'module' => 'node',
  );

  return $permissions;
}

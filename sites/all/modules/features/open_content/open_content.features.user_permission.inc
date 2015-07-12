<?php
/**
 * @file
 * open_content.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function open_content_user_default_permissions() {
  $permissions = array();

  // Exported permission: 'create open_content content'.
  $permissions['create open_content content'] = array(
    'name' => 'create open_content content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'delete any open_content content'.
  $permissions['delete any open_content content'] = array(
    'name' => 'delete any open_content content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'delete own open_content content'.
  $permissions['delete own open_content content'] = array(
    'name' => 'delete own open_content content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'edit any open_content content'.
  $permissions['edit any open_content content'] = array(
    'name' => 'edit any open_content content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'edit own open_content content'.
  $permissions['edit own open_content content'] = array(
    'name' => 'edit own open_content content',
    'roles' => array(),
    'module' => 'node',
  );

  return $permissions;
}

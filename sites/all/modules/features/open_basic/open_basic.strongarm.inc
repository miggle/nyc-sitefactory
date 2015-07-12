<?php
/**
 * @file
 * open_basic.strongarm.inc
 */

/**
 * Implements hook_strongarm().
 */
function open_basic_strongarm() {
  $export = array();

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'additional_settings__active_tab_open_basic_page';
  $strongarm->value = 'edit-display';
  $export['additional_settings__active_tab_open_basic_page'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'menu_options_open_basic_page';
  $strongarm->value = array(
    0 => 'main-menu',
  );
  $export['menu_options_open_basic_page'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'menu_parent_open_basic_page';
  $strongarm->value = 'main-menu:0';
  $export['menu_parent_open_basic_page'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'metatag_enable_node__open_basic_page';
  $strongarm->value = TRUE;
  $export['metatag_enable_node__open_basic_page'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_options_open_basic_page';
  $strongarm->value = array(
    0 => 'status',
  );
  $export['node_options_open_basic_page'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_preview_open_basic_page';
  $strongarm->value = '0';
  $export['node_preview_open_basic_page'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_submitted_open_basic_page';
  $strongarm->value = 0;
  $export['node_submitted_open_basic_page'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'save_continue_open_basic_page';
  $strongarm->value = 'Save and add fields';
  $export['save_continue_open_basic_page'] = $strongarm;

  return $export;
}

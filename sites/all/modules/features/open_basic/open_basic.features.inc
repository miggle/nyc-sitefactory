<?php
/**
 * @file
 * open_basic.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function open_basic_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_node_info().
 */
function open_basic_node_info() {
  $items = array(
    'open_basic_page' => array(
      'name' => t('Basic Page'),
      'base' => 'node_content',
      'description' => t('Defines a basic page content type'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}

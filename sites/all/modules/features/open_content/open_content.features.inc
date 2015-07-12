<?php
/**
 * @file
 * open_content.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function open_content_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_node_info().
 */
function open_content_node_info() {
  $items = array(
    'open_content' => array(
      'name' => t('Content'),
      'base' => 'node_content',
      'description' => t('Defines key content type to be imported from external data source'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}

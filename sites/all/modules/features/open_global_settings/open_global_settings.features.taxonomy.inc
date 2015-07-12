<?php
/**
 * @file
 * open_global_settings.features.taxonomy.inc
 */

/**
 * Implements hook_taxonomy_default_vocabularies().
 */
function open_global_settings_taxonomy_default_vocabularies() {
  return array(
    'open_tags' => array(
      'name' => 'Tags',
      'machine_name' => 'open_tags',
      'description' => 'Sitewide tags vocabulary',
      'hierarchy' => 0,
      'module' => 'taxonomy',
      'weight' => 0,
    ),
  );
}

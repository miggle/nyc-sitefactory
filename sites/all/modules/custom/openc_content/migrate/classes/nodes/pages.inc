<?php

/**
 * @file
 * Class definition for the pages content import.
 */

/**
 * Class OpenPagesNodeMigration
 */
class OpenPagesNodeMigration extends Migration {
  public function __construct($arguments) {
    parent::__construct($arguments);

    // Source and destination relation for rollbacks
    $this->map = new MigrateSQLMap($this->machineName,
      array(
        'title' => array(
          'type' => 'varchar',
          'length' => 255,
          'not null' => TRUE,
          'description' => 'Topic ID',
        )
      ),
      MigrateDestinationNode::getKeySchema()
    );

    // Set defaults for unmapped fields
    $this->addFieldMapping('promote')->defaultValue(0);
    $this->addFieldMapping('status')->defaultValue(1);
    $this->addFieldMapping('language')->defaultValue('und');

    // Migration source settings.
    $csv_path = drupal_get_path('module', 'openc_content') . '/migrate/content/nodes/pages.csv';
    $columns = $this->csvcolumns();
    $content_type = 'open_basic_page';

    // Create a MigrateSource object, which manages retrieving the input data.
    $this->description = t('Import: Pages');
    $this->source = new MigrateSourceCSV($csv_path, $columns, array('header_rows' => 1));
    $this->destination = new MigrateDestinationNode($content_type);

    // Mappings.
    $this->addSimpleMappings(array('title', 'path', 'body'));
    $this->addFieldMapping('body:format', 'format')
      ->defaultValue('filtered_html');
  }

  // CVS column mapping.
  function csvcolumns() {
    $cols[0] = array('title', 'Node title');
    $cols[1] = array('body', 'Body text');
    $cols[2] = array('format', 'Body text format');
    $cols[3] = array('path', 'Node path');
    return $cols;
  }
}
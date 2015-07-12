<?php

/**
 * @file
 * Migration include for tags taxonomy terms
 */


/**
 * Class OpenTagsTermMigration
 */
class OpenTagsTermMigration extends Migration {
  public function __construct($arguments) {
    parent::__construct($arguments);

    // Migration source settings.
    $csv = drupal_get_path('module', 'openc_content') . '/migrate/content/terms/tags.csv';
    $columns = $this->csvcolumns();

    $vocab = 'open_tags';

    $this->source = new MigrateSourceCSV($csv, $columns, array('header_rows' => 1));

    $this->destination = new MigrateDestinationTerm($vocab);

    // Source and destination relation for rollbacks
    $this->map = new MigrateSQLMap($this->machineName,
      array(
        'name' => array(
          'type' => 'varchar',
          'length' => 255,
          'not null' => TRUE,
        )
      ),
      MigrateDestinationTerm::getKeySchema()
    );

    $this->addFieldMapping('name', 'name');
  }

  function csvcolumns() {
    // name
    $cols[0] = array('name', 'Term name');
    return $cols;
  }
}
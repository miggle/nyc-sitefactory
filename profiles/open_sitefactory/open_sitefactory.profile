<?php

/**
 * Implements hook_install_tasks().
 *
 * Add the option to install starter example content.
 */
function open_sitefactory_install_tasks(&$install_state) {
  $tasks = array();

  // define a task for configuring client info
  $tasks['open_sitefactory_client_config'] = array(
    'display_name' => st('Client Configuration'),
    'display' => TRUE,
    'type' => 'form',
    'run' => INSTALL_TASK_RUN_IF_NOT_COMPLETED,
    'function' => 'open_sitefactory_client_config_form',
  );
  // define a task for enabling a "content" module
  $tasks['open_sitefactory_example_content'] = array(
    'display_name' => st('Install example content'),
    'display' => TRUE,
    'type' => 'form',
    'run' => INSTALL_TASK_RUN_IF_NOT_COMPLETED,
    'function' => 'open_sitefactory_example_content_form',
  );

  return $tasks;
}

/**
 * Form callback for configuring client level details on install
 * @param $form
 * @param $form_state
 * @return array
 */
function open_sitefactory_client_config_form($form, &$form_state) {
  $form = array();

  // retrieve options from Aegir via drush
  if (function_exists('drush_get_option')) {
    $client_id = drush_get_option('client_id', '');
    $site_package = drush_get_option('site_package', '');
  }
  // set defaults
  else {
    $client_id = NULL;
    $site_package = 'basic';
  }

  // set our package options
  $site_packages = array(
    'basic',
    'advanced',
    'custom',
  );

  $form['client_config'] = array(
    '#type' => 'fieldset',
    '#title' => 'Client Configuration',
  );
  $form['client_config']['open_sitefactory_client_id'] = array(
    '#type' => 'textfield',
    '#title' => t('Client ID'),
    '#default_value' => $client_id,
  );
  $form['client_config']['open_sitefactory_package'] = array(
    '#type' => 'select',
    '#title' => t('Site Package'),
    '#default_value' => $site_package,
    '#options' => drupal_map_assoc($site_packages),
  );

  $form['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Save and continue'),
  );
  return $form;
}

/**
 * Submit handler for saving client configuration values.
 * @param $form
 * @param $form_state
 */
function open_sitefactory_client_config_form_submit($form, &$form_state) {
  $values = $form_state['values'];

  // save client id
  variable_set('open_sitefactory_client_id', $values['open_sitefactory_client_id']);

  // save the site package
  variable_set('open_sitefactory_package', $values['open_sitefactory_package']);

  // @todo: enable a package dependency based on selection
}

/**
 * Task callback form function to enable the example content module.
 */
function open_sitefactory_example_content_form($form, &$form_state) {
  $form = array();

  $form['example_content'] = array(
    '#title' => st('Install example content'),
    '#description' => st('Enable the openc_content module - this will register and run migrations to populate the site with default content.'),
    '#type' => 'checkbox',
    '#default_value' => 1,
  );

  $form['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Save and continue'),
  );

  return $form;
}

/**
 * For submit function for the example content install task.
 */
function open_sitefactory_example_content_form_submit(&$form, &$form_state) {
  $values = $form_state['values'];

  if ($values['example_content']) {
    if (module_enable(array('openc_content'))) {
      drupal_set_message('Example content has been installed.');
    }
  }
}
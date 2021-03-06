<?php

/**
 * @file
 * Creates the admin and settings pages for the Mark Visited Nodes module.
 */

/**
 * Implements hook_menu.
 */
function mark_visited_nodes_menu() {

  $items['admin/config/mark-visited-nodes'] = array(
    'title' => 'Mark visited nodes',
    'page callback' => 'system_admin_menu_block_page',
    'access arguments' => array('Administer mark visited nodes settings'),
    'file path' => drupal_get_path('module', 'system'),
    'file' => 'system.admin.inc',
  );

   $items['admin/config/mark-visited-nodes/settings'] = array(
    'title' => 'Basic Settings',
    'description' => 'Mark visited nodes Settings',
    'page callback' => 'drupal_get_form',
    'page arguments' => array('mark_visited_nodes_form'),
    'access arguments' => array('Administer mark visited nodes settings'),
  );

  return $items;
}

/*
 * Implements hook_form.
 */
function mark_visited_nodes_form($form, &$form_state) {
  //Creates an array of content type machine names.
  foreach (node_type_get_names() as $key => $value) {
    $nodetype[] = $key;
  }

  $form['content_type'] = array(
    '#title' => t('Choose content type'),
    '#type' => 'checkboxes',
    '#options' => drupal_map_assoc($nodetype),
    '#default_value' => variable_get("content_type", ""),
    '#required' => FALSE,
  );

  $form['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Submit'),
    "#attributes" => array(
      "class" => array(
        "btn",
      ),
    )
  );
  return $form;
}

/**
 * Implements hook_form_submit
 */
function mark_visited_nodes_form_submit($form, $form_state) {
  $old_content_types = variable_get("content_type", "");
  variable_set("content_type", $form_state['values']['content_type']);
  foreach ($old_content_types as $key => $value) {
    if ($old_content_types[$key] ==! $form_state['values']['content_type'][$key] && $form_state['values']['content_type'][$key] === 0) {
      remove_visited_nodes_contenttype($value);
    }
  }
}

<?php

/**
 * @file
 * Views definitions for mark_visited_nodes module.
 */

/**
 * Implements hook_views_data_alter().
 */
function mark_visited_nodes_views_data_alter(&$data) {

  $data['node']['visited'] = array(
    'title' => t('Visited nodes'),
    'help' => t('Marks the visited nodes by logged in user.'),
    'field' => array(
      'handler' => 'mark_visited_nodes_handler_field_boolean',
    ),
  );
  dpm($data);
  return $data;
}

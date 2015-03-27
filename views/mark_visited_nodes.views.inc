<?php

/**
 * @file
 * Views definitions for mark_visited_nodes module.
 */


/**
 * Implements hook_views_data_alter().
 */
function mark_visited_nodes_views_data_alter(&$data) {

  $data['mark_visited_nodes']['table']['group'] = t('Visited nodes');

  $data['mark_visited_nodes']['table']['base'] = array(
    'title' => t('Visited nodes'),
    'help' => t('Contains records of the visitde nodes (nid->uid)')
  );

  $data['mark_visited_nodes']['table']['join'] = array(
    'node' => array(
      'left_field' => 'nid',
      'field' => 'nid',
      ),
    );

  $data['mark_visited_nodes']['nid'] = array(
    'title' => t('Visited'),
    'help' => t('Visited Yes/No.'),
    'field' => array(
      'handler' => 'mark_visited_nodes_handler_field_boolean',
    ),
    'filter' => array(
        'handler' => 'views_handler_filter_boolean_operator',
    ),
    'relationship' => array(
        'base' => 'node',
        'field' => 'nid',
        'handler' => 'views_handler_relationship',
        'label' => t('Node'),
      ),
    );

  $data['mark_visited_nodes']['uid'] = array(
    'title' => t('Visited uid'),
    'help' => t('Visited uid.'),
    'field' => array(
      'handler' => 'views_handler_field_numeric',
    ),
    'filter' => array(
        'handler' => 'views_handler_filter_boolean_operator',
    ),
    'relationship' => array(
        'base' => 'user',
        'field' => 'uid',
        'handler' => 'views_handler_relationship',
        'label' => t('User'),
      ),
    );
  return $data;
}

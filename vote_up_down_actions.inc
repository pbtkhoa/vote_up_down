<?php
// $Id$

/**
 * @file
 * Contains Drupal actions and actions sets for use with vote_up_down.module and the Voting API..
 */

/**
 * Implementation of a Drupal action.
 * Award userpoint to node author.
 */
function action_vote_up_down_userpoints_add($op, $edit = array(), &$node) {
  switch($op) {
    case 'metadata':
      return array(
        'description' => t('Award userpoint to node author (Vote up/down)'),
        'type' => t('Node'),
        'batchable' => FALSE,
        'configurable' => FALSE,
      );
    case 'do':
      userpoints_userpointsapi('points', variable_get('userpoints_actions', 0), $node->uid);
      watchdog('action', t('Awarded userpoint to author of node id %id', array('%id' => intval($node->nid))));
      break;
    // process the HTML form to store configuration
    case 'submit':
      return '';
  }
}

/**
 * Implementation of a Drupal action.
 * Deduct userpoint from node author.
 */
function action_vote_up_down_userpoints_remove($op, $edit = array(), &$node) {
  switch($op) {
    case 'metadata':
      return array(
        'description' => t('Deduct userpoint from node author (Vote up/down)'),
        'type' => t('Node'),
        'batchable' => FALSE,
        'configurable' => FALSE,
      );
    case 'do':
      userpoints_userpointsapi('points', -variable_get('userpoints_actions', 0), $node->uid);
      watchdog('action', t('Deducted userpoint from author of node id %id', array('%id' => intval($node->nid))));
      break;
    // process the HTML form to store configuration
    case 'submit':
      return '';
  }
}

?>
<?php
// $Id$

/**
 * @file
 * Themeing functions
 */

/**
 * Preprocessing of vud_widget template.
 */
function template_preprocess_vud_widget(&$variables) {
  global $user;
  $cid = $variables['cid'];
  $type = $variables['type'];
  $widget = $variables['widget_theme'];
  $tag = isset($variables['tag']) ? $variables['tag'] : variable_get('vud_tag', 'vote');

  drupal_add_css(drupal_get_path('module', 'vud') .'/widgets'."/$widget".'/widget.css');
  drupal_add_js(drupal_get_path('module', 'vud') .'/widgets'."/$widget".'/ajax.js');

  if ($user->uid) {
    $criteria = array(
      'content_type' => $type,
      'content_id' => $cid,
      'uid' => _vud_get_uid(),
      'tag' => $tag,
    );
    $user_vote = votingapi_select_single_vote_value($criteria);

    if ($user_vote > 0) {
      $variables['class1'] = 'vote-up-act';
      $variables['class2'] = 'vote-down-inact';
    }
    else if ($user_vote < 0) {
      $variables['class1'] = 'vote-up-inact';
      $variables['class2'] = 'vote-down-act';
    }
    else {
      $variables['class1'] = 'vote-up-inact';
      $variables['class2'] = 'vote-down-inact';
    }

    $token = drupal_get_token("vud/$type/$cid/1");
    $variables['title1'] = url("vud/$type/$cid/1/$tag/1", array('query' => 'token='. $token));
    $variables['link1'] = l('', "vud/$type/$cid/1/$tag", array(
			    'attributes' => array(
			      'class' => $variables['class1'],
			      'title' => t('Vote up')
			    ),
			    'query' => drupal_get_destination() .'&token='. $token,)
                          );

    $token = drupal_get_token("vud/$type/$cid/-1");
    $variables['title2'] = url("vud/$type/$cid/-1/$tag/1", array('query' => 'token='. $token));
    $variables['link2'] =  l('', "vud/$type/$cid/-1/$tag", array(
                                                'attributes' => array(
                                                  'class' => $variables['class2'],
                                                  'title' => t('Vote down')
                                                ),
                                                'query' => drupal_get_destination() .'&token='. $token,
                                               )
                                             );
  }
  else {
    $variables['class1'] = 'up-inact';
    $variables['class2'] = 'down-inact';
    $variables['title1'] = t('You must login to vote!');
    $variables['title2'] = t('You must login to vote!');
  }
}


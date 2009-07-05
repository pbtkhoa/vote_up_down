<?php
// $Id$

/**
 * @file
 * Theme functions
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

  vud_add_css($widget);  // Search and add the CSS files.
  vud_add_js($widget);   // Search and add the JS files.

  if ($user->uid) {
    $criteria = array(
      'content_type' => $type,
      'content_id' => $cid,
      'tag' => $tag,
    );
    $user_vote = votingapi_select_single_vote_value($criteria);
    var_dump($user_vote);

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

/**
 * Read and parse the widgets/ directory recursively.
 */
function vud_read_widgets() {
  $vud_path = drupal_get_path('module', 'vud');
  $widgets_dir = $vud_path .'/widgets';
  $files = file_scan_directory($widgets_dir, 'widget\.tpl\.php$');
  $themes = array();
  foreach ($files as $file) {
    $widgetword = strlen($file->filename) - strlen($widgets_dir) - strlen($file->basename);
    $themename = substr($file->filename, strlen($widgets_dir) + 1, $widgetword - 2);
    $themes["$themename"] = $themename;
  }

  return $themes;
}

/**
 * Read and load all CSS files in the selected widget directory.
 */
function vud_add_css($widget) {
  $vud_path = drupal_get_path('module', 'vud');
  $widgets_dir = $vud_path .'/widgets/'. $widget;
  $files = file_scan_directory($widgets_dir, '\.css$');
  foreach ($files as $file) {
    drupal_add_css($file->filename);
  }
}

/**
 * Read and load all JavaScript files in the selected widget directory.
 */
function vud_add_js($widget) {
  $vud_path = drupal_get_path('module', 'vud');
  $widgets_dir = $vud_path .'/widgets/'. $widget;
  $files = file_scan_directory($widgets_dir, '\.js$');
  foreach ($files as $file) {
    drupal_add_js($file->filename);
  }
}

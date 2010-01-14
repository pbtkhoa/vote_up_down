<?php
// $Id$

/**
 * @file
 * Theme functions
 */

/**
 * Proxy widget function that hook_theme() calls.
 */
function vud_widget_proxy($cid, $type, $tag, $widget_theme) {
  $render_function = 'theme_render_template';
  $extension = '.tpl.php';

  $template_file = drupal_get_path('module', 'vud') ."/widgets/$widget_theme/widget". $extension;
  $variables = array('cid' => $cid, 'type' => $type, 'widget_theme' => $widget_theme);

  global $user;
  $variables['cid'] = $cid;
  $variables['type'] = $type;
  $variables['widget_theme'] = $widget_theme;
  $variables['tag'] = $tag ? $tag : variable_get('vud_tag', 'vote');
  $uid = votingapi_current_user_identifier();

  vud_add_css($widget_theme);  // Search and add the CSS files.
  vud_add_js($widget_theme);   // Search and add the JS files.

  $base_criteria = array(
    'content_type' => $type,
    'content_id' => $cid,
    'tag' => $variables['tag'],
  );
  $criteria = $base_criteria + $uid;
  $user_vote = votingapi_select_single_vote_value($criteria);

  if ($user_vote > 0) {
    $variables['class_up'] = 'up-active';
    $variables['class_down'] = 'down-inactive';
  }
  else if ($user_vote < 0) {
    $variables['class_up'] = 'up-inactive';
    $variables['class_down'] = 'down-active';
  }
  else {
    $variables['class_up'] = 'up-inactive';
    $variables['class_down'] = 'down-inactive';
  }

  $token_up = drupal_get_token("vote/$type/$cid/1/$tag");
  $variables['link_up'] = url("vote/$type/$cid/1/$tag/$token_up");

  $token_down = drupal_get_token("vote/$type/$cid/-1/$tag");
  $variables['link_down'] = url("vote/$type/$cid/-1/$tag/$token_down");

  $result_criteria = array(
    'content_type' => $type,
    'content_id' => $cid,
    'value_type' => 'points',
    'tag' => $tag,
    'function' => 'sum'
  );
  $vote_result = (int) votingapi_select_single_result_value($result_criteria);
  $variables['unsigned_points'] = $vote_result;

  if ($vote_result > 0) {
    $variables['class'] = 'positive';
    $variables['points'] = '+'. $vote_result;
  }
  else {
    $variables['points'] = $vote_result;
    if ($vote_result < 0) {
      $variables['class'] = 'negative';
    }
    else {
      $variables['class'] = 'neutral';
    }
  }
  $variables['vote_label'] = format_plural($vote_result, 'vote', 'votes');

  $output = $render_function($template_file, $variables);
  return $output;
}

/**
 * Proxy votes display function, that hook_theme() calls.
 */
function vud_votes_proxy($cid, $type, $tag, $widget_theme) {
  $render_function = 'theme_render_template';
  $extension = '.tpl.php';

  $template_file = drupal_get_path('module', 'vud') ."/widgets/$widget_theme/votes". $extension;
  $variables = array('cid' => $cid, 'type' => $type, 'widget_theme' => $widget_theme);

  $variables['tag'] = $tag;

  $criteria = array(
    'content_type' => $type,
    'content_id' => $cid,
    'value_type' => 'points',
    'tag' => $tag,
    'function' => 'sum'
  );
  $vote_result = (int) votingapi_select_single_result_value($criteria);
  $variables['unsigned_points'] = $vote_result;

  if ($vote_result > 0) {
    $variables['class'] = 'positive';
    $variables['points'] = '+'. $vote_result;
  }
  else {
    $variables['points'] = $vote_result;
    if ($vote_result < 0) {
      $variables['class'] = 'negative';
    }
    else {
      $variables['class'] = 'neutral';
    }
  }
  $variables['vote_label'] = format_plural($vote_result, 'vote', 'votes');

  vud_add_css($widget_theme);  // Search and add the CSS files.
  vud_add_js($widget_theme);   // Search and add the JS files.

  $output = '';
  if (file_exists($template_file)) {
    $output = $render_function($template_file, $variables);
  }
  else {
    drupal_set_message(t('The %template_file file is missing. Please create the file, or set vote points to "Don\'t display".', array('%template_file' => $template_file)), 'error');
  }
  return $output;
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
  asort($themes);
  return $themes;
}

/**
 * Read and load all CSS files in the selected widget directory.
 */
function vud_add_css($widget) {
  $vud_path = drupal_get_path('module', 'vud');
  $widget_dir = $vud_path .'/widgets/'. $widget;
  $files = file_scan_directory($widget_dir, '\.css$');
  foreach ($files as $file) {
    drupal_add_css($file->filename);
  }
}

/**
 * Read and load all JavaScript files in the selected widget directory.
 */
function vud_add_js($widget) {
  $vud_path = drupal_get_path('module', 'vud');
  $widget_dir = $vud_path .'/widgets/'. $widget;
  $files = file_scan_directory($widget_dir, '\.js$');
  foreach ($files as $file) {
    drupal_add_js($file->filename);
  }
}

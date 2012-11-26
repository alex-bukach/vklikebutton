<?php

/**
 * @file
 * Theme function for vklikebutton.
 */

/**
 * Returns field content to display
 */
function theme_vklikebutton($conf) {
  $width = $conf['width'];
  $height = $conf['height'];
  $type = $conf['type'];
  $verb = $conf['verb'];
  $appid = $conf['appid'];
  $title = $conf['title'];
  $description = $conf['description'];
  $text = $conf['text'];
  $url = urlencode($conf['url']);
  $image = $conf['image'];
  $page_id = $conf['page_id'];

  $element_id = 'vk_like_' . $page_id;

  $options = array();
  if ($width) $options[] = 'width: ' . json_encode($width);
  if ($height) $options[] = 'height: ' . json_encode($height);
  if ($type) $options[] = 'type: ' . json_encode($type);
  if (!is_null($verb)) $options[] = 'verb: ' . json_encode($verb);
  if ($title) $options[] = 'pageTitle: ' . json_encode($title);
  if ($description) $options[] = 'pageDescription: ' . json_encode($description);
  if ($url) $options[] = 'pageUrl: ' . json_encode($url);
  if ($image) $options[] = 'pageImage: ' . json_encode($image);
  if ($text) $options[] = 'text: ' . json_encode($text);

  $output = '<div id="' . $element_id . '"></div>';
  drupal_add_js('http://vk.com/js/api/openapi.js?62', array(
      'type' => 'external',
      'weight' => '-20',
      'group' => JS_LIBRARY,
  ), 'vklikebutton_openapi');
  drupal_add_js('VK.init({apiId: ' . $appid . ', onlyWidgets: true});', array(
      'type' => 'inline',
      'scope' => 'header',
      'weight' => '0',
      'group' => JS_LIBRARY,
  ), 'vklikebutton_init');
  drupal_add_js('VK.Widgets.Like(' . json_encode($element_id) . ', {' . implode(', ', $options) . '}, ' . $page_id . ');', array(
      'type' => 'inline',
      'scope' => 'footer',
  ));
  return $output;
}
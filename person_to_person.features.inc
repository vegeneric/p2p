<?php

/**
 * Implementation of hook_node_info().
 */
function person_to_person_node_info() {
  $items = array(
    'guest' => array(
      'name' => t('Guest'),
      'module' => 'features',
      'description' => t('This content type represents potential guests using the person-to-person service.'),
      'has_title' => '1',
      'title_label' => t('Full Name'),
      'has_body' => '1',
      'body_label' => t('Bio'),
      'min_word_count' => '0',
      'help' => '',
    ),
    'host' => array(
      'name' => t('Host'),
      'module' => 'features',
      'description' => t('This content type represents hosts participating the person-to-person service.'),
      'has_title' => '1',
      'title_label' => t('Full Name'),
      'has_body' => '1',
      'body_label' => t('Bio'),
      'min_word_count' => '0',
      'help' => '',
    ),
    'offer' => array(
      'name' => t('Offer'),
      'module' => 'features',
      'description' => t('An offer of potential host matches to a potential guest in the person-to-person program.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'has_body' => '1',
      'body_label' => t('Offer Notes'),
      'min_word_count' => '0',
      'help' => '',
    ),
  );
  return $items;
}

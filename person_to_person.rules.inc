<?php

/**
 * Implementation of hook_rules_action_info()
 * Our custom action callbacks are defined here.
 */
function person_to_person_rules_action_info() {

  return array(
    'person_to_person_rules_action_flag_potential_hosts' => array(
      'label' => t('Flag potential hosts'),
      'arguments' => array(
        'node' => array('label' => t('Guest Node'), 'type' => 'node'),
        'user' => array('label' => t('Guest'), 'type' => 'user'),
      ),
      'help' => t('Locates and flags potential hosts on guest creation.'),
      'module' => 'person_to_person',
    ),
    'person_to_person_rules_action_email_referenced_hosts' => array(
      'label' => t('Notify referenced host(s)'),
      'arguments' => array(
        'node' => array('label' => t('Offer Node'), 'type' => 'node'),
        'user' => array('label' => t('Guest'), 'type' => 'user'),
      ),
      'help' => t('Shoots off an email to the hosts involved in an offer.'),
      'module' => 'person_to_person',
    )
  );
}

/**
 * Our custom callback for flagging potential hosts on guest creation
 * @param $node - The guest node object
 * @param $account - The guest user's account object
 */
function person_to_person_rules_action_flag_potential_hosts($node, $account) {
  
  $hosts = _person_to_person_flag_hosts_for_guest($account, $node);
  foreach ($hosts AS $key => $value) {
    
  }
  dsm($node);
  dsm($account);
  
}

/*
 * Our custom callback for emailing hosts referenced in an offer node
 * @param $node - The offer node object
 * @param $account - The guest's user account object
 */
function person_to_person_rules_action_email_referenced_hosts($node, $account) {

  dsm($node);
  dsm($account);
  
}

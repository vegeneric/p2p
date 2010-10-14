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
    ),
    'person_to_person_rules_action_unflag_deselected_hosts' => array(
      'label' => t('Unflag hosts deselected from an offer'),
      'arguments' => array(
        'node' => array('label' => t('Offer Node'), 'type' => 'node'),
        'user' => array('label' => t('Guest'), 'type' => 'user'),
      ),
      'help' => t('Unflag hosts deselected from an offer on update.'),
      'module' => 'person_to_person',
    ),
    'person_to_person_rules_action_offer_host_confirmed' => array(
      'label' => t('Host confirmed in an offer'),
      'arguments' => array(
        'node' => array('label' => t('Offer Node'), 'type' => 'node'),
        'user' => array('label' => t('Guest'), 'type' => 'user'),
      ),
      'help' => t('Host confirmed in an offer.'),
      'module' => 'person_to_person',
    ),
    'person_to_person_rules_action_offer_guest_confirmed' => array(
      'label' => t('Guest confirmed in an offer'),
      'arguments' => array(
        'node' => array('label' => t('Offer Node'), 'type' => 'node'),
        'user' => array('label' => t('Guest'), 'type' => 'user'),
      ),
      'help' => t('Guest confirmed in an offer.'),
      'module' => 'person_to_person',
    ),
    'person_to_person_rules_action_offer_all_confirmed' => array(
      'label' => t('All confirmed in an offer'),
      'arguments' => array(
        'node' => array('label' => t('Offer Node'), 'type' => 'node'),
        'user' => array('label' => t('Guest'), 'type' => 'user'),
      ),
      'help' => t('All confirmed in an offer.'),
      'module' => 'person_to_person',
    )
  );
}

/**
 * Our custom action for flagging potential hosts on guest creation
 * @param $node - The guest node object
 * @param $account - The guest user's account object
 */
function person_to_person_rules_action_flag_potential_hosts($node, $account) {
  
  $hosts = _person_to_person_find_hosts_for_guest($account, $node, TRUE);
  
}

/**
 * Our custom action for unflagging hosts that have been deselected in an offer
 * @param $node - The offer node object
 * @param $account - The guest user's account object
 */
function person_to_person_rules_action_unflag_deselected_hosts($node, $account) {
  // Build a decent array of selected hosts
  $hosts = array();
  foreach ($node->field_host AS $key => $host) {
    foreach ($host AS $a => $value) {
      $hosts[] = $value;
    }
  }
  
  // Unflag hosts that are no longer selected
  $host_flag = flag_get_flag('potential_host');
  $sql = db_query("SELECT phid, host_nid FROM {person_to_person_potential_hosts} WHERE guest_nid = %d AND guest_uid = %d AND status = 'flagged'", $node->nid, $account->uid);
  while ($data = db_fetch_object($sql)) {
    if (!in_array($data->host_nid, $hosts)) {
      $host_flag->flag('unflag', $data->host_nid, $account);
    }
  }
}

/*
 * Our custom action for emailing hosts referenced in an offer node
 * @param $node - The offer node object
 * @param $account - The guest's user account object
 */
function person_to_person_rules_action_email_referenced_hosts($node, $account) {
  foreach ($node->field_host AS $key => $host_nid) {
    //_person_to_person_email_host($host_nid);
  }
}

/**
 * Our custom action runs when the host is confirmed in an offer
 * @param $node - The offer node object
 * @param $account - The guest user's account object
 */
function person_to_person_rules_action_offer_host_confirmed($node, $account) {

}

/**
 * Our custom action runs when the guest is confirmed in an offer
 * @param $node - The offer node object
 * @param $account - The guest user's account object
 */
function person_to_person_rules_action_offer_guest_confirmed($node, $account) {

}

/**
 * Our custom action runs when all parties are confirmed in an offer
 * @param $node - The offer node object
 * @param $account - The guest user's account object
 */
function person_to_person_rules_action_offer_all_confirmed($node, $account) {

}
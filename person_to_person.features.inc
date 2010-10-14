<?php

/**
 * Implementation of hook_flag_default_flags().
 */
function person_to_person_flag_default_flags() {
$flags = array();
// Exported flag: "Potential Host".
$flags[] = array (
  'content_type' => 'node',
  'name' => 'potential_host',
  'title' => 'Potential Host',
  'global' => '0',
  'types' => 
  array (
    0 => 'host',
  ),
  'flag_short' => 'add as host',
  'flag_long' => 'Flag this host as a potential match for the guest.',
  'flag_message' => '',
  'unflag_short' => 'remove as host',
  'unflag_long' => 'unflag this host as a potential match for the guest.',
  'unflag_message' => '',
  'unflag_denied_text' => '',
  'link_type' => 'toggle',
  'roles' => 
  array (
    'flag' => 
    array (
      0 => 5,
    ),
    'unflag' => 
    array (
      0 => 5,
    ),
  ),
  'show_on_page' => 1,
  'show_on_teaser' => 1,
  'show_on_form' => 0,
  'access_author' => '',
  'i18n' => 0,
  'module' => 'person_to_person',
  'locked' => 
  array (
    'name' => 'name',
  ),
  'api_version' => 2,
);
return $flags;
}

/**
 * Implementation of hook_node_info().
 */
function person_to_person_node_info() {
  $items = array(
    'experience' => array(
      'name' => t('Experience'),
      'module' => 'features',
      'description' => t('A shared experience between a host and a guest in the person-to-person program.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'has_body' => '1',
      'body_label' => t('Description'),
      'min_word_count' => '0',
      'help' => '',
    ),
    'guest' => array(
      'name' => t('Guest'),
      'module' => 'features',
      'description' => t('This content type represents potential guests using the person-to-person service.'),
      'has_title' => '1',
      'title_label' => t('Full Name'),
      'has_body' => '1',
      'body_label' => t('Comments or any special requirements or needs'),
      'min_word_count' => '0',
      'help' => t('Our free program lets you experience Bahamian culture and cuisine as well as learn more about our history and develop long-lasting friendships with one of our many friendly Bahamian volunteers.

Some of the activities you might enjoy, include:

    • Receive a ride to and from the hosting experience
    • Home-cooked Bahamian meal
    • Church service with host
    • Visit to local schools
    • Invitation to tea parties
    • And much more

To join, fill out the form below, speak with the tour desk at your hotel, or visit the nearest Bahamas Tourist Office.

For more information, contact us and we’ll get back to you as soon as possible'),
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

/**
 * Implementation of hook_rules_defaults().
 */
function person_to_person_rules_defaults() {
  return array(
    'rules' => array(
      'person_to_person_2' => array(
        '#type' => 'rule',
        '#set' => 'event_node_insert',
        '#label' => 'Offer creation notifications',
        '#active' => 1,
        '#weight' => '0',
        '#categories' => array(
          '0' => 'person-to-person',
          'person_to_person' => 'person_to_person',
        ),
        '#status' => 'default',
        '#conditions' => array(
          '0' => array(
            '#type' => 'condition',
            '#settings' => array(
              'type' => array(
                'offer' => 'offer',
              ),
              '#argument map' => array(
                'node' => 'node',
              ),
            ),
            '#name' => 'rules_condition_content_is_type',
            '#info' => array(
              'label' => 'Created content is Offer',
              'arguments' => array(
                'node' => array(
                  'type' => 'node',
                  'label' => 'Content',
                ),
              ),
              'module' => 'Node',
            ),
            '#weight' => 0,
          ),
        ),
        '#actions' => array(
          '0' => array(
            '#weight' => 0,
            '#info' => array(
              'label' => 'Send a mail to a user',
              'arguments' => array(
                'user' => array(
                  'type' => 'user',
                  'label' => 'Recipient',
                ),
              ),
              'module' => 'System',
              'eval input' => array(
                '0' => 'subject',
                '1' => 'message',
                '2' => 'from',
              ),
            ),
            '#name' => 'rules_action_mail_to_user',
            '#settings' => array(
              'from' => '',
              'subject' => 'We have potential hosts for you!',
              'message' => 'Aight.',
              '#argument map' => array(
                'user' => 'author',
              ),
            ),
            '#type' => 'action',
          ),
          '1' => array(
            '#type' => 'action',
            '#settings' => array(
              '#argument map' => array(
                'node' => 'node',
                'user' => 'author',
              ),
            ),
            '#name' => 'person_to_person_rules_action_email_referenced_hosts',
            '#info' => array(
              'label' => 'Notify referenced host(s)',
              'arguments' => array(
                'node' => array(
                  'label' => 'Offer Node',
                  'type' => 'node',
                ),
                'user' => array(
                  'label' => 'Guest',
                  'type' => 'user',
                ),
              ),
              'module' => 'person_to_person',
            ),
            '#weight' => 0,
          ),
          '2' => array(
            '#weight' => 0,
            '#info' => array(
              'label' => 'Unflag hosts deselected from an offer',
              'arguments' => array(
                'node' => array(
                  'label' => 'Offer Node',
                  'type' => 'node',
                ),
                'user' => array(
                  'label' => 'Guest',
                  'type' => 'user',
                ),
              ),
              'module' => 'person_to_person',
            ),
            '#name' => 'person_to_person_rules_action_unflag_deselected_hosts',
            '#settings' => array(
              '#argument map' => array(
                'node' => 'node',
                'user' => 'author',
              ),
            ),
            '#type' => 'action',
          ),
        ),
        '#version' => 6003,
      ),
      'person_to_person_5' => array(
        '#type' => 'rule',
        '#set' => 'event_node_update',
        '#label' => 'Offer update - all confirmed',
        '#active' => 1,
        '#weight' => '0',
        '#categories' => array(
          '0' => 'person-to-person',
          'person_to_person' => 'person_to_person',
        ),
        '#status' => 'default',
        '#conditions' => array(
          '0' => array(
            '#type' => 'condition',
            '#settings' => array(
              'type' => array(
                'offer' => 'offer',
              ),
              '#argument map' => array(
                'node' => 'node',
              ),
            ),
            '#name' => 'rules_condition_content_is_type',
            '#info' => array(
              'label' => 'Updated content is Offer',
              'arguments' => array(
                'node' => array(
                  'type' => 'node',
                  'label' => 'Content',
                ),
              ),
              'module' => 'Node',
            ),
            '#weight' => 0,
          ),
          '1' => array(
            '#weight' => 0,
            '#info' => array(
              'label' => 'Updated content\'s field \'field_confirm_admin\' has value',
              'arguments' => array(
                'node' => array(
                  'type' => 'node',
                  'label' => 'Content',
                ),
              ),
              'eval input' => array(
                '0' => 'code',
              ),
              'module' => 'CCK',
            ),
            '#name' => 'content_rules_field_has_value',
            '#settings' => array(
              'field_name' => 'field_confirm_admin',
              '#argument map' => array(
                'node' => 'node',
              ),
              'value' => array(
                '0' => array(
                  'value' => 1,
                ),
              ),
              'code' => '',
            ),
            '#type' => 'condition',
          ),
          '2' => array(
            '#type' => 'condition',
            '#settings' => array(
              'field_name' => 'field_confirm_guest',
              '#argument map' => array(
                'node' => 'node',
              ),
              'value' => array(
                '0' => array(
                  'value' => 1,
                ),
              ),
              'code' => '',
            ),
            '#name' => 'content_rules_field_has_value',
            '#info' => array(
              'label' => 'Updated content\'s field \'field_confirm_guest\' has value',
              'arguments' => array(
                'node' => array(
                  'type' => 'node',
                  'label' => 'Content',
                ),
              ),
              'eval input' => array(
                '0' => 'code',
              ),
              'module' => 'CCK',
            ),
            '#weight' => 0,
          ),
          '3' => array(
            '#weight' => 0,
            '#info' => array(
              'label' => 'Updated content\'s field \'field_confirm_host\' has value',
              'arguments' => array(
                'node' => array(
                  'type' => 'node',
                  'label' => 'Content',
                ),
              ),
              'eval input' => array(
                '0' => 'code',
              ),
              'module' => 'CCK',
            ),
            '#name' => 'content_rules_field_has_value',
            '#settings' => array(
              'field_name' => 'field_confirm_host',
              '#argument map' => array(
                'node' => 'node',
              ),
              'value' => array(
                '0' => array(
                  'value' => 1,
                ),
              ),
              'code' => '',
            ),
            '#type' => 'condition',
          ),
          '4' => array(
            '#type' => 'condition',
            '#settings' => array(
              'field_name' => 'field_confirm_admin',
              '#argument map' => array(
                'node' => 'node',
                'node_unchanged' => 'node_unchanged',
              ),
            ),
            '#name' => 'content_rules_field_changed',
            '#info' => array(
              'label' => 'Updated content\'s field \'field_confirm_admin\' has been changed',
              'arguments' => array(
                'node' => array(
                  'type' => 'node',
                  'label' => 'Content containing changes',
                ),
                'node_unchanged' => array(
                  'type' => 'node',
                  'label' => 'Content not containing changes',
                ),
              ),
              'module' => 'CCK',
            ),
            '#weight' => 0,
          ),
        ),
        '#actions' => array(
          '0' => array(
            '#type' => 'action',
            '#settings' => array(
              'title' => '[node:title]',
              'type' => 'experience',
              'node_access' => 0,
              '#argument map' => array(
                'author' => 'author',
                'node_added' => 'experience_added',
              ),
              '#eval input' => array(
                'token_rules_input_evaluator' => array(
                  'title' => array(
                    '0' => 'node',
                  ),
                ),
              ),
            ),
            '#name' => 'rules_action_add_node',
            '#info' => array(
              'label' => 'Create experience node',
              'label callback' => FALSE,
              'arguments' => array(
                'author' => array(
                  'type' => 'user',
                  'label' => 'User, who is set as author',
                ),
                'title' => array(
                  'type' => 'string',
                  'label' => 'Title',
                  'description' => 'The title of the newly created content.',
                ),
              ),
              'new variables' => array(
                'experience_added' => array(
                  'label' => 'new experience',
                  'label callback' => FALSE,
                  'type' => 'node',
                  'save' => TRUE,
                ),
              ),
              'module' => 'Node',
            ),
            '#weight' => 0,
          ),
          '1' => array(
            '#weight' => 0,
            '#info' => array(
              'label' => 'Notify referenced host(s)',
              'arguments' => array(
                'node' => array(
                  'label' => 'Offer Node',
                  'type' => 'node',
                ),
                'user' => array(
                  'label' => 'Guest',
                  'type' => 'user',
                ),
              ),
              'module' => 'person_to_person',
            ),
            '#name' => 'person_to_person_rules_action_email_referenced_hosts',
            '#settings' => array(
              '#argument map' => array(
                'node' => 'node',
                'user' => 'author',
              ),
            ),
            '#type' => 'action',
          ),
          '2' => array(
            '#type' => 'action',
            '#settings' => array(
              'recipients' => array(
                '0' => 5,
              ),
              'from' => '',
              'subject' => '',
              'message' => '',
            ),
            '#name' => 'rules_action_mail_to_users_of_role',
            '#info' => array(
              'label' => 'Send a mail to all users of a role',
              'module' => 'System',
              'eval input' => array(
                '0' => 'subject',
                '1' => 'message',
                '2' => 'from',
              ),
            ),
            '#weight' => 0,
          ),
          '3' => array(
            '#weight' => 0,
            '#info' => array(
              'label' => 'Send a mail to a user',
              'arguments' => array(
                'user' => array(
                  'type' => 'user',
                  'label' => 'Recipient',
                ),
              ),
              'module' => 'System',
              'eval input' => array(
                '0' => 'subject',
                '1' => 'message',
                '2' => 'from',
              ),
            ),
            '#name' => 'rules_action_mail_to_user',
            '#settings' => array(
              'from' => '',
              'subject' => '',
              'message' => '',
              '#argument map' => array(
                'user' => 'author',
              ),
            ),
            '#type' => 'action',
          ),
        ),
        '#version' => 6003,
      ),
      'person_to_person_1' => array(
        '#type' => 'rule',
        '#set' => 'event_node_insert',
        '#label' => 'Guest creation',
        '#active' => 1,
        '#weight' => '0',
        '#categories' => array(
          '0' => 'person-to-person',
          '1' => 'person_to_person',
        ),
        '#status' => 'default',
        '#conditions' => array(
          '0' => array(
            '#type' => 'condition',
            '#settings' => array(
              'type' => array(
                'guest' => 'guest',
              ),
              '#argument map' => array(
                'node' => 'node',
              ),
            ),
            '#name' => 'rules_condition_content_is_type',
            '#info' => array(
              'label' => 'Created content is Guest',
              'arguments' => array(
                'node' => array(
                  'type' => 'node',
                  'label' => 'Content',
                ),
              ),
              'module' => 'Node',
            ),
            '#weight' => 0,
          ),
        ),
        '#actions' => array(
          '0' => array(
            '#weight' => 0,
            '#info' => array(
              'label' => 'Send a mail to all users of a role',
              'module' => 'System',
              'eval input' => array(
                '0' => 'subject',
                '1' => 'message',
                '2' => 'from',
              ),
            ),
            '#name' => 'rules_action_mail_to_users_of_role',
            '#settings' => array(
              'recipients' => array(
                '0' => 5,
              ),
              'from' => '',
              'subject' => 'New guest interested in the person-to-person program',
              'message' => 'Test body... [node:field_visit_dates-view] - to - [node:field_visit_dates-to-view]',
              '#eval input' => array(
                'token_rules_input_evaluator' => array(
                  'message' => array(
                    '0' => 'node',
                  ),
                ),
              ),
            ),
            '#type' => 'action',
          ),
          '1' => array(
            '#type' => 'action',
            '#settings' => array(
              'from' => '',
              'subject' => 'Thank you for registering as a guest in the person-to-person program',
              'message' => 'Good job!',
              '#argument map' => array(
                'user' => 'author',
              ),
            ),
            '#name' => 'rules_action_mail_to_user',
            '#info' => array(
              'label' => 'Send a mail to a user',
              'arguments' => array(
                'user' => array(
                  'type' => 'user',
                  'label' => 'Recipient',
                ),
              ),
              'module' => 'System',
              'eval input' => array(
                '0' => 'subject',
                '1' => 'message',
                '2' => 'from',
              ),
            ),
            '#weight' => 0,
          ),
          '2' => array(
            '#type' => 'action',
            '#settings' => array(
              '#argument map' => array(
                'node' => 'node',
                'user' => 'author',
              ),
            ),
            '#name' => 'person_to_person_rules_action_flag_potential_hosts',
            '#info' => array(
              'label' => 'Flag potential hosts',
              'arguments' => array(
                'node' => array(
                  'label' => 'Guest Node',
                  'type' => 'node',
                ),
                'user' => array(
                  'label' => 'Guest',
                  'type' => 'user',
                ),
              ),
              'module' => 'person_to_person',
            ),
            '#weight' => 0,
          ),
        ),
        '#version' => 6003,
      ),
      'person_to_person_3' => array(
        '#type' => 'rule',
        '#set' => 'event_node_update',
        '#label' => 'Offer updated - host confirmed',
        '#active' => 1,
        '#weight' => '0',
        '#categories' => array(
          '0' => 'person-to-person',
          'person_to_person' => 'person_to_person',
        ),
        '#status' => 'default',
        '#conditions' => array(
          '0' => array(
            '#type' => 'condition',
            '#settings' => array(
              'type' => array(
                'offer' => 'offer',
              ),
              '#argument map' => array(
                'node' => 'node',
              ),
            ),
            '#name' => 'rules_condition_content_is_type',
            '#info' => array(
              'label' => 'Updated content is Offer',
              'arguments' => array(
                'node' => array(
                  'type' => 'node',
                  'label' => 'Content',
                ),
              ),
              'module' => 'Node',
            ),
            '#weight' => 0,
          ),
          '1' => array(
            '#weight' => 0,
            '#info' => array(
              'label' => 'Host confirmation changed',
              'label callback' => FALSE,
              'arguments' => array(
                'node' => array(
                  'type' => 'node',
                  'label' => 'Content containing changes',
                ),
                'node_unchanged' => array(
                  'type' => 'node',
                  'label' => 'Content not containing changes',
                ),
              ),
              'module' => 'CCK',
            ),
            '#name' => 'content_rules_field_changed',
            '#settings' => array(
              'field_name' => 'field_confirm_host',
              '#argument map' => array(
                'node' => 'node',
                'node_unchanged' => 'node_unchanged',
              ),
            ),
            '#type' => 'condition',
          ),
          '2' => array(
            '#type' => 'condition',
            '#settings' => array(
              'field_name' => 'field_confirm_host',
              '#argument map' => array(
                'node' => 'node',
              ),
              'value' => array(
                '0' => array(
                  'value' => NULL,
                ),
              ),
              'code' => '',
            ),
            '#name' => 'content_rules_field_has_value',
            '#info' => array(
              'label' => 'Host confirmation given',
              'label callback' => FALSE,
              'arguments' => array(
                'node' => array(
                  'type' => 'node',
                  'label' => 'Content',
                ),
              ),
              'eval input' => array(
                '0' => 'code',
              ),
              'module' => 'CCK',
            ),
            '#weight' => 0,
          ),
        ),
        '#actions' => array(
          '0' => array(
            '#weight' => 0,
            '#info' => array(
              'label' => 'Send a mail to a user',
              'arguments' => array(
                'user' => array(
                  'type' => 'user',
                  'label' => 'Recipient',
                ),
              ),
              'module' => 'System',
              'eval input' => array(
                '0' => 'subject',
                '1' => 'message',
                '2' => 'from',
              ),
            ),
            '#name' => 'rules_action_mail_to_user',
            '#settings' => array(
              'from' => '',
              'subject' => 'Your host has been confirmed!',
              'message' => 'Excellent!',
              '#argument map' => array(
                'user' => 'author',
              ),
            ),
            '#type' => 'action',
          ),
        ),
        '#version' => 6003,
      ),
      'person_to_person_4' => array(
        '#type' => 'rule',
        '#set' => 'event_node_update',
        '#label' => 'Offer updated - guest confirmed',
        '#active' => 1,
        '#weight' => '0',
        '#categories' => array(
          '0' => 'person-to-person',
          'person_to_person' => 'person_to_person',
        ),
        '#status' => 'default',
        '#conditions' => array(
          '0' => array(
            '#type' => 'condition',
            '#settings' => array(
              'type' => array(
                'offer' => 'offer',
              ),
              '#argument map' => array(
                'node' => 'node',
              ),
            ),
            '#name' => 'rules_condition_content_is_type',
            '#info' => array(
              'label' => 'Updated content is Offer',
              'arguments' => array(
                'node' => array(
                  'type' => 'node',
                  'label' => 'Content',
                ),
              ),
              'module' => 'Node',
            ),
            '#weight' => 0,
          ),
          '1' => array(
            '#weight' => 0,
            '#info' => array(
              'label' => 'Updated content\'s field \'field_confirm_guest\' has been changed',
              'arguments' => array(
                'node' => array(
                  'type' => 'node',
                  'label' => 'Content containing changes',
                ),
                'node_unchanged' => array(
                  'type' => 'node',
                  'label' => 'Content not containing changes',
                ),
              ),
              'module' => 'CCK',
            ),
            '#name' => 'content_rules_field_changed',
            '#settings' => array(
              'field_name' => 'field_confirm_guest',
              '#argument map' => array(
                'node' => 'node',
                'node_unchanged' => 'node_unchanged',
              ),
            ),
            '#type' => 'condition',
          ),
          '2' => array(
            '#type' => 'condition',
            '#settings' => array(
              'field_name' => 'field_confirm_guest',
              '#argument map' => array(
                'node' => 'node',
              ),
              'value' => array(
                '0' => array(
                  'value' => NULL,
                ),
              ),
              'code' => '',
            ),
            '#name' => 'content_rules_field_has_value',
            '#info' => array(
              'label' => 'Updated content\'s field \'field_confirm_guest\' has value',
              'arguments' => array(
                'node' => array(
                  'type' => 'node',
                  'label' => 'Content',
                ),
              ),
              'eval input' => array(
                '0' => 'code',
              ),
              'module' => 'CCK',
            ),
            '#weight' => 0,
          ),
        ),
        '#actions' => array(
          '0' => array(
            '#weight' => 0,
            '#info' => array(
              'label' => 'Notify admins',
              'label callback' => FALSE,
              'module' => 'System',
              'eval input' => array(
                '0' => 'subject',
                '1' => 'message',
                '2' => 'from',
              ),
            ),
            '#name' => 'rules_action_mail_to_users_of_role',
            '#settings' => array(
              'recipients' => array(
                '0' => 5,
              ),
              'from' => '',
              'subject' => 'A guest has just confirmed their offer!',
              'message' => 'Finalize that!',
            ),
            '#type' => 'action',
          ),
        ),
        '#version' => 6003,
      ),
      'person_to_person_6' => array(
        '#type' => 'rule',
        '#set' => 'event_node_update',
        '#label' => 'Offer updated',
        '#active' => 1,
        '#weight' => '0',
        '#categories' => array(
          '0' => 'person-to-person',
          'person_to_person' => 'person_to_person',
        ),
        '#status' => 'default',
        '#conditions' => array(
          '0' => array(
            '#type' => 'condition',
            '#settings' => array(
              'type' => array(
                'offer' => 'offer',
              ),
              '#argument map' => array(
                'node' => 'node',
              ),
            ),
            '#name' => 'rules_condition_content_is_type',
            '#info' => array(
              'label' => 'Updated content is Offer',
              'arguments' => array(
                'node' => array(
                  'type' => 'node',
                  'label' => 'Content',
                ),
              ),
              'module' => 'Node',
            ),
            '#weight' => 0,
          ),
        ),
        '#actions' => array(
          '0' => array(
            '#weight' => 0,
            '#info' => array(
              'label' => 'Unflag hosts deselected from an offer',
              'arguments' => array(
                'node' => array(
                  'label' => 'Offer Node',
                  'type' => 'node',
                ),
                'user' => array(
                  'label' => 'Guest',
                  'type' => 'user',
                ),
              ),
              'module' => 'person_to_person',
            ),
            '#name' => 'person_to_person_rules_action_unflag_deselected_hosts',
            '#settings' => array(
              '#argument map' => array(
                'node' => 'node',
                'user' => 'author',
              ),
            ),
            '#type' => 'action',
          ),
        ),
        '#version' => 6003,
      ),
    ),
  );
}

/**
 * Implementation of hook_views_api().
 */
function person_to_person_views_api() {
  return array(
    'api' => '2',
  );
}

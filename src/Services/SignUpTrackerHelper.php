<?php

namespace Drupal\sign_up_tracker;
use Drupal\Core\Database\Driver\mysql\Connection;
use Symfony\Component\HttpFoundation\RequestStack;
use Drupal\Core\Config\ConfigFactoryInterface;

/**
 * Class SignUpTrackerHelper.
 */
class SignUpTrackerHelper {

  /**
   * Drupal\Core\Database\Driver\mysql\Connection definition.
   *
   * @var \Drupal\Core\Database\Driver\mysql\Connection
   */
  protected $database;

  /**
   * Symfony\Component\HttpFoundation\RequestStack definition.
   *
   * @var \Symfony\Component\HttpFoundation\RequestStack
   */
  protected $requestStack;

  /**
   * Drupal\Core\Config\ConfigFactoryInterface definition.
   *
   * @var \Drupal\Core\Config\ConfigFactoryInterface
   */
  protected $configFactory;

  /**
   * Constructs a new SignUpTrackerHelper object.
   */
  public function __construct(Connection $database, RequestStack $request_stack, ConfigFactoryInterface $config_factory) {
    $this->database = $database;
    $this->requestStack = $request_stack;
    $this->configFactory = $config_factory;
  }

  /**
   * Stores the data into tracker table.
   */
  public function logSignUp($entity) {
    $activityConfig = $this->configFactory->get('activity_tracking.settings');
    // Fetching user's IP address.
    $ip = $this->requestStack->getCurrentRequest()->getClientIp();
    $httpagent = $_SERVER['HTTP_USER_AGENT'];
    $httpagent = substr($httpagent,0,255);

    $fields = [
      'uid'        => $entity->id(),
      'ip'         => $ip,
      'user_agent' => $httpagent,
      'created'    => REQUEST_TIME,
    ];
    \Drupal::logger('my_module')->notice('logSignUp' .  $entity->id();
    try {
      $this->database->insert('sign_up_tracker')
        ->fields($fields)
        ->execute();
    }
    catch (Exception $e) {
      // Exception handling if something else gets thrown.
      \Drupal::logger('sign_up_tracker')->error($e->getMessage());
    }
  }
}

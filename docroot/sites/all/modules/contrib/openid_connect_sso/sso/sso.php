<?php

/**
 * @file
 * Creates cookies for each of the network sites to signal a login/logout.
 */

if (empty($_SERVER['HTTP_HOST'])) {
  // Some pre-HTTP/1.1 clients will not send a Host header.
  // We can't work around this.
  exit;
}

// The collection of SSO script addresses which form the redirection network.
// Don't include the protocol (http://, https://).
// Example url (SSO script on subdomain): "a.firstsite.com"
// Example url (SSO script in the Drupal directory): "firstsite.com/sso.php"
$network = array(
  'a.firstsite.com',
  'a.shop.secondsite.com',
);

// An array of network domain names. The keys are potential origin host names
// which do not appear in the list above, and each value is the cookie domain
// name for that host.
// $domains = array();

// Enable HTTPS for all redirect URLs.
// $https = true;

// Enable adding the domain name to the cookie name.
// $cookie_name_strict = true;

// Validate the query parameters and network size.
if (!sso_validate_query_params() || count($network) < 2) {
  exit;
}

// $_SERVER['HTTP_HOST'] is lowercased here per specifications.
$host = strtolower($_SERVER['HTTP_HOST']);

$origin_host = $_GET['origin_host'];
$origin_domain = isset($domains[$origin_host]) ? $domains[$origin_host] : $origin_host;

// Find the next site that needs to be visited in the $network, by removing
// the origin site re-keying the array.
foreach ($network as $delta => $site) {
  if (strpos($site, $origin_domain) === 0 || strpos($site, 'a.' . $origin_domain) === 0) {
    unset($network[$delta]);
  }
}
$network = array_values($network);

if (ltrim($host, 'a.') == $origin_domain) {
  // We are on the site which has started the process.
  // No need to create the cookie, the site already handled its login / logout.
  // Start from the beginning of the redirect list.
  $redirect_destination = sso_redirect_url($network[0], !empty($https));
}
else {
  sso_create_cookie($_GET['op']);

  foreach ($network as $delta => $site) {
    if (strpos($site, $host) === 0 || strpos($site, 'a.' . $host) === 0) {
      $current_site_delta = $delta;
      break;
    }
  }

  if (!isset($current_site_delta)) {
    trigger_error('Current site not found in network', E_USER_ERROR);
    exit;
  }

  $next_site_delta = $current_site_delta + 1;
  if (isset($network[$next_site_delta])) {
    // Redirect to the next network site.
    $redirect_destination = sso_redirect_url($network[$next_site_delta], !empty($https));
  }
  else {
    // We are at the last network site. In these scenarios, we need to
    // redirect to the destination, or to the original host in case of a logout.
    if ($_GET['op'] == 'login') {
      $redirect_destination = $_GET['destination'];
    }
    else {
      $redirect_destination = ($https ? 'https://' : 'http://') . $_GET['origin_host'];
    }
  }
}

// Redirect the user. We need to prevent the redirect from being cached.
header('Cache-Control: max-age=0', TRUE);
header('Expires: Sun, 09 Aug 1987 22:00:00 +0100', TRUE);
header('Pragma: no-cache', TRUE);
header('Location: ' . $redirect_destination, TRUE, 302);
exit;

/**
 * Validates the query parameters.
 *
 * Required parameters:
 * - op: Tells us what the current operation is: login or logout.
 * - origin_host: Indicates which site initiated the login/logout.
 * Additional required parameter when the operation is "login":
 * - destination: The url to redirect the user to after all redirects are done.
 */
function sso_validate_query_params() {
  if (empty($_GET['op']) || empty($_GET['origin_host'])) {
    return FALSE;
  }
  if (!in_array($_GET['op'], array('login', 'logout'))) {
    return FALSE;
  }
  if ($_GET['op'] == 'login' && !isset($_GET['destination'])) {
    return FALSE;
  }

  return TRUE;
}

/**
 * Creates a cookie signaling the required operation.
 *
 * Removes any conflicting cookies.
 *
 * @param $operation
 *   The operation to signal, login or logout.
 */
function sso_create_cookie($operation) {
  if ($operation == 'login') {
    $remove = 'Drupal.visitor.SSOLogout';
    $create = 'Drupal.visitor.SSOLogin';
  }
  else {
    $remove = 'Drupal.visitor.SSOLogin';
    $create = 'Drupal.visitor.SSOLogout';
  }

  $secure = !empty($GLOBALS['https']);

  $domain = ltrim(strtolower($_SERVER['HTTP_HOST']), 'a.');

  if (!empty($GLOBALS['cookie_name_strict'])) {
    $remove .= '_' . $domain;
    $create .= '_' . $domain;
  }

  setcookie($remove, '', time() - 3600, '/', $domain, $secure);
  // The expiration should be less than the Drupal session duration.
  // The most common Drupal `session.gc_maxlifetime` value is 200000 seconds,
  // so we define the expiration to half a minute before that, accordingly.
  setcookie($create, 1, time() + 200000 - 30, '/', $domain, $secure);
}

/**
 * Returns an URL to which redirection can be issued.
 *
 * @param string $host
 * @param bool $https
 * @return string
 */
function sso_redirect_url($host, $https) {
  if (!strpos($host, '//')) {
    $host = ($https ? 'https://' : 'http://') . $host;
  }
  $args = array(
    'op' => $_GET['op'],
    'origin_host' => $_GET['origin_host'],
  );
  if ($_GET['op'] == 'login') {
    $args['destination'] = $_GET['destination'];
  }
  return $host . '/?' . http_build_query($args);
}

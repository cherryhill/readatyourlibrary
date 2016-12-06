Provides a single sign-on solution based on OpenID Connect.

The OpenID Connect server (central place of login) is a Drupal site running oauth2_server.
The clients are Drupal sites running openid_connect.

After the user's login on the server or logout on any of the network sites,
the module starts a redirect chain that visits the SSO script of each site in the network.
The SSO script then sets a cookie notifying the parent site of the pending login / logout.
When the user visits the actual site, the cookie is read, and the user logged in / out automatically.

This is the same approach used by Google Accounts.
The point of the redirects is to give each site a chance to set a cookie valid for its domain,
thus going around the same-origin policy that forbids a site from setting a cookie for another domain.
The redirects are fast and unnoticeable, since the SSO script is standalone (no Drupal bootstrap) and only sets the cookie.

See the documentation for more examples and setup instructions:
https://drupal.org/node/2274367


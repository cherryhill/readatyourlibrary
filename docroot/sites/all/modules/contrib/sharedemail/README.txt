
The Shared E-mail module overrides the 'user' module's validation,
that prevents the same e-mail address being used by more than one user. 

Works for both registration and account updates. 

Displays a warning to the user that they are using a shared email.

Based on http://drupal.org/node/15578#comment-249157

All this module does is modify the email address before it is validated by the user module.

Because it only changes the edit value rather than the form value, 
the validation will pass but the original unchanged email is still stored properly.

Installation
* Enable the module in /admin/modules
* Check permissions in /admin/people/permissions#module-sharedemail
* By default the warning text will not be displayed unless the 'show warning text' is selected for the users role
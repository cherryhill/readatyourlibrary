------------------------------------------------------------------------------------

Admin can give or take badges by this module. Using this module admin 
can give, one badge to multiple user  and  multiple badges to a single user at 
a time. This module creates a link (badge manager) in admin menu.


Important Note
---------------

*  In order to Assing(Give) a badge(openbadging) using badge manager or Achievements module, 
   your server environment must be web accessible 
	 (i.e., Mozilla must be able to open a page on your site). 
	 So, local development environments (e.g., MAMP), won't work to test that functionality.
*  Makesure your allow_url_fopen in php.ini must be ON.
*  Must use views_bulk_oprations module version 7.x-3.0 (Download url http://drupal.org/node/161539/release).

Installation
--------------

* Copy the whole "openbadging_badge_manager" directory to your 
  modules directory (sites/all/modules).
* Enable the module (admin/modules).


Usage
-----
   
 * Login as admin you can see Badge Manager link in admin menu.
 * On link click admin will see two tabs named manage badges and manage earners.
 * On manage badge tab click a autocomplete textbox will open , admin select 
   user from this textbox and click button named next.
 * On next click a new page will opened on which all badges are shown according 
   to selected user.
 * Now Admin can give or take multiple badgs to selected user using 
   operations which have two option named Give for give
   openbadging and Take for take openbadgings.
 * On manage earners tab click a autocomplete textbox will open, admin select 
   openbadging from this textbox and click button named next.
 * On next click a new page will opened on which all user are shown according 
   to selected openbadging.
 * Now Admin can give or take selected openbadging to multiple user using 
   oprations which have two option named Give for give
   openbadging and Take for take openbadgings.
  

Views
-------

* badge_manager (for create page showing on manage badge tab)
* earner_manager_default (for create page showing on manage earners tab)


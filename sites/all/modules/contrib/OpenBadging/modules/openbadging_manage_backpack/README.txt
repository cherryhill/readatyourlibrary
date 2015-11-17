-------------------------------------------------------------------------------

openbadging Manage Backpack is manage backpack for user. User can create group 
to maintain their badges.
This module creates Badges group bundle for backpack of badges and 
it makes group and badge public or private.


Installation
------------

* Copy the whole "openbadging_manage_backpack" directory to your 
  modules directory (sites/all/modules).
* Enable the module (admin/modules) and create group through 
  My Backpack tab on user profile.
* Set your desired permissions at admin/people/permissions.

Usage
-----
   
 * Go to /admin/structure/openbadging you can see Badges group bundle.
   (structure >> Openbadging Configurations >> Badges group)
 * It adds one more tab(My Backpack) on user profile page.
 * For creating group open tab "My Backpack" and click "create badge group" 
   link. 
 * It also makes public or private badges and groups.


Feature fields
--------------

-openbadging-user_groups-field_badge_entity_reference_1
-openbadging-user_groups-field_user_group_private

Views
-----

-my_groups
  * This view shows the user's all badges group(public or private) in user's profile.
  
Block
------

create group block
    * This block shows the create group block link on mybackpack tab.

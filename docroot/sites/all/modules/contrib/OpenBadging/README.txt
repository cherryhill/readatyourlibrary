                                                                     
                                                                     
                                                                     
                                             
-----------------------------------------------------------------
This module creates openbadging Entity user interface(UI) for creating entities 
using entity module.

bundles can be created with this UI. 

Current features and design
---------------------------

* The module is aimed to provide a simple, but extensible solution providing a 
  similar entity type for comments, user profile,etc.
* openbadging Entity module creates user interface for creating bundle through 
  this.
* Permission can be set for bundle.
* All content of all bundles can be shown on Openbadging Configuration content 
  tab.



Installation
-------------

* Copy the whole "openbadging" directory to your modules
  directory - "sites/all/modules"
* Enable the module and add bundles at - "admin/structure/openbadging".
* Set your desired bundle wise permissions at - "admin/people/permissions".


Usage
------
   
 * Go to "/admin/structure/openbadging"(structure >> Openbadging Configurations)
   and add bundles.
 * For add any content for these bundles go to openbadging/add.
 * All content saved in content tab at admin/structure/openbadging/content.

Permissions available for each bundle
-------------------------------------
* View Bundle openbadging
* Create Bundle openbadging
* Edit any Bundle openbadging
* Edit own Bundle openbadging
* Delete any Bundle openbadging
* Delete own Bundle openbadging



---------------------------------------------------------------

This module create fields for Issuer information bundle for creating 
issuer information.
This issuer information linked with the program and it will be attach to user 
if admin gives Badge Issuer role.  


Installation
------------

* Copy the whole openbadging_issuer directory to your 
  modules directory (sites/all/modules).
* Enable the module and add issuer information at 
  openbadging/add/issuer_information.
  (structure >> Openbadging Configurations >> ADD openbadging)
* Set your desired permissions at admin/people/permissions.

Usage
-----
   
 * Go to /admin/structure/openbadging you can see Issuer Information bundle.
   (structure >> Openbadging Configurations >> Issuer Information)
 * For creating badges go to (/openbadging/add/issuer_information) 
   and create issuer information.


Taxonomy fields
---------------

-Program


Feature fields
--------------
-openbadging-issuer_information-field_badge_entity_program
-openbadging-issuer_information-field_issuer_contact
-openbadging-issuer_information-field_issuer_org
-openbadging-issuer_information-field_issuer_origin

General Description
---------------------

Add taxonomy terms in Program. 

Program:

      It is existing taxonomy field which is exist in openbadging_badges. 



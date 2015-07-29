                                                                     
                                                                     
                                                                     
                                             

--------------------------------------------------------------
Designed to be the successor of "Achievements module", it helps to create 
badges using Achievements API.
This module provides a new, fieldable 'badges' bundle in openbadging 
Configuration using "openbadging" module.

This module create fields for Badges Bundle for creating badges according to 
the "Open Badge Infrastructure(OBI) complaint". 
It uses Achievements API for giving and taking openbadging. 


Installation
------------

* Copy the whole "openbadging_badges" directory to your 
  modules directory - "sites/all/modules"
* Enable the module and add badges at - "openbadging/add/badges".
* Set your desired permissions at "admin/people/permissions".

Usage
-----
   
 * Go to /admin/structure/openbadging where you will see badges bundle.
   (structure >> Openbadging Configurations >> Badges)
 * For creating badges go to "/openbadging/add/badges" and 
   create badges.(structure >> Openbadging Configurations >> ADD openbadging)
 * It connect openbadging issuer by program taxonomy.
 * There should be two roles defined for users through which 
   badge view functionality will work
 - "Badge Earner" = who wants to earn badge.
 - "Badge Issuer" = Who issues badge to earner. 


Taxonomy fields
---------------
-Badge Recipient
-Badges type
-Year
-Program 


Feature fields
--------------

-openbadging-badges-field_badge_entity_criteria
-openbadging-badges-field_badge_entity_description
-openbadging-badges-field_badge_entity_evidence
-openbadging-badges-field_badge_entity_expiration
-openbadging-badges-field_badge_entity_issued_date
-openbadging-badges-field_badge_entity_lock_image
-openbadging-badges-field_badge_entity_program
-openbadging-badges-field_badge_entity_recipients
-openbadging-badges-field_badge_entity_recommend
-openbadging-badges-field_badge_entity_type
-openbadging-badges-field_badge_entity_unlock_image
-openbadging-badges-field_badge_entity_version
-openbadging-badges-field_badge_entity_year
 


Views
------

-Awarded Users:
  * This view shows users who award this badge on badge page. 

-Earned Badges:
  * This view shows earned badges on the user's profile page. 


General Description
---------------------

Add taxonomy terms in Badges type, Year and Program. 
The badge name is combination of all three taxonomies.

Badge name = [Program][Year][Badge Type].

Fields for Taxonomy
--------------------

Badge Recipient:       
        It is list of recipient.
 as: 
       Interpreter/Adult
       Finalist/Student

Badge Type: 

      It is list of type of badges.
as:         
       1st Place Winner 
       2nd Place Winner 
       Grand Award 
       
Program:

      It is list of program.
as:
      at school level "summer program".

Year:

     Listing of years.

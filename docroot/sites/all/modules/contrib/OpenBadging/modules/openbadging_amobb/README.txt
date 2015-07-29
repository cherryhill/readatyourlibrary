About this module
------
Module that allows Badges to be sent to a Mozilla Open Badges Backpack.

Installation
------------
Copy the "openbadging_amobb" module directory to your modules 
directory and then enable on the admin modules page.  The manage
module by Morbus Iff must already be enabled.  Create Badges as
instructed in the Achievements module, and make 'unlocked' openbadging 
images use the .png format.  A 'badge' openbadging image may also be
included to allow for larger resolution badges (e.g. 256x256).

Devlopment feature
-------------------
If send to mozilla backpack link require , then create link inside a div with class name
achievement-openbadges-backpack-button with div id 'title of badge' for example:

<div class='achievement-openbadges-backpack-button' id='title of badge which you want to send to mozilla backpack'>
create link here
</div>  

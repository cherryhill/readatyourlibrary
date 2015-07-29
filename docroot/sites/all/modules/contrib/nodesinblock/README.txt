Nodes in block
--------------
Requires Drupal 7 and block module.

Author: Kristof De Jaeger - http://drupal.org/user/107403

Overview:
--------
Nodes in block makes it possible to add nodes into a block. A number of configurable 
blocks can be made available which you can assign to a region. On the node content form,
you select the block and visibility per node. The block which this node is assigned
to will inherit the node's visibility settings. With this module, you don't have to explain 
your customers how blocks work but is still able to decide on which pages content must be 
rendered.

Installation:
-------------
1. Place this module directory in your modules folder 
   (this will usually be "sites/all/modules/").
2. Go to "administer -> build -> modules" and enable the module.

Configuration:
--------------
Go to "administer -> settings -> nodesinblock" 

Select how many blocks you want and which content types will benefit from this feature. 
After submitting this, two fieldsets will become available where you can change the block 
settings and define the settings per content type. Now it's time to go to admin/build/block
and assign one or more blocks to a region.

On the node form, you can choose the region, render mode (depending on your settings)
and the visibility of the node. Weight and status of the node in the block can be altered
by visiting administer -> settings -> nodesinblock -> queue.

If you set the visibility setting for the block as "Show on every page except the listed pages", 
multiple paths will not work correct because of the way that Drupal core block visibility works. 
You'll be better off choosing the default option.

Theming
-------
An extra property is added to the node object which you can use in your node 
template file to make theming even more easier:

<?php
// node.tpl.php
if (isset($node->nodesinblock)) {
  // Theming for node in block
}
else {
  // Normal theming
}
?>

Support:
--------
Please use the issue queue available at http://drupal.org/project/nodesinblock to
file support and feature requests, bugs etc. Be as descriptive as you can.

Last updated:
------------
; $Id: README.txt,v 1.1.2.7.2.3 2010/10/30 13:03:38 swentel Exp $

Description
-----------
This module allows the users to export one or more roles and their associated
permissions. The main purpose for creating this module is to transfer roles and
their associate permissions from a local/dev/staging machine/server to a remote
dev/stage/production server.

No additional configuration is required to export/Import roles and their
associated permissions. Also does not create any table in the database.
Therefore it will not effect the application performance.

Related Module
--------------
Name: Export Roles & Permissions
URL: https://www.drupal.org/project/export_roles_permissions

Why This
--------
Using this module user can easily export the roles and their associated
permissions and import them using the same interface.

Installation
------------
1. Copy the entire permissions_export directory the Drupal sites/all/modules or
sites/all/modules/contrib directory.

2. Login as an administrator. Enable the module in the "Administer" -> "Modules"

3. Access the links to export the roles and their associated permissions
(admin/people/export-import-rpermissions)

4. Access the links to to Import the roles and their associated permissions
(admin/people/export-import-rpermissions/import)

DEPENDENCIES:
-------------
user

AUTHOR:
-------
Devendra Yadav <dev.firoza@gmail.com>

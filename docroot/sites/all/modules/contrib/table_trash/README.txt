
TABLE TRASH QUICK INSTALL

-- If you wish to use Drush:

drush dl table_trash
drush en table_trash
drush dl-datatables

-- If you do not wish to use Drush:

For the bulk of its features, Table Trash relies on this jQuery library:
http://datatables.net/download. Please download it and uncompress into
sites/all/libraries. Rename the folder to datatables (lower-case, no verson
number).

If, in addition, you wish to use the responsive table feature, press "Download
Zip" on this page: https://github.com/Comanche/datatables-responsive. Unzip the
downloaded folder to sites/all/libraries, renaming it to datatables-responsive.

Visit admin/reports/status and verify that the Table Trash section does not
report any warnings.

With that you should be in business! All you have to do is visit
/admin/config/content/table_trash to assign the features of your choice to the
tables that need them. That's it. Enjoy!

NOTES AND CAVEATS

o To get the full benefits of fast sorting and paging, you're advised to switch
  OFF server-side sorting and paging where possible, e.g. in the Views UI.
  This is because the client-side sorting and paging functions provided by
  DataTables JS operate on the data downloaded with the latest browser request,
  which in case of server-side sorting is not the entire db query result set.

o Column reordering works out-of-the box. But after installing with "drush dl-
  datatables" or after dropping this file,
  http://datatables.net/extras/thirdparty/ColReorderWithResize/ColReorderWithResize.js,
  into sites/all/libraries/datatables/extras/ColReorder/media/js you cannot only
  drag and drop columns into a different spot, but also adjust their widths, by
  sliding the vertical separator between the column headers.
  Note: width-adjustment can be fiddly when "Fix table header on scroll" is
  active on the same table.

o The DataTables JS library does not cope well with tables that don't fully
  comply with modern HTML and omit the <thead> section, see
  http://datatables.net/forums/discussion/18273/datatables-requires-tables-to-have-a-thead
  Luckily nearly all tables on Drupal comply and work beautifully. These don't:
  admin/reports/status and admin/reports/updates.
  DataTables also does not like colspans anywhere in the table. If a table
  has a <td> with a colspan attribute, you get an error in your browser console.
  See http://datatables.net/forums/discussion/18274/datatables-does-not-cope-with-cols
  Problem pages: admin/people/permissions and admin/modules

o For the above reasons Table Trash comes with a patched version of parts of the
  DataTables JS library already installed. It won't fix all idiosyncracies, but
  it will allow some features to continue to work despite others failing.

o For the "Fixed left columns" feature and the export buttons to work on
  MULTIPLE tables on the same page, you have to create and configure a separate
  table decoration for EACH table, using a well-targeted CSS selector, at
  /admin/config/content/table_trash.

FORUMS

https://datatables.net/forums/discussions
https://github.com/Comanche/datatables-responsive/issues


Installation & Setup
=======================

1. Create a content type that will contain the files, for e.g., call it 'File'.
2. Add a file field to the content type. You'll probably want to set it to
   contain multiple values. Remember what you called it.
3. On the content type edit page at /admin/structure/types/manage/file (if
   you've called your type 'file'), click the 'Attachment links' section at the
   bottom. Select the file field that will be used by Attachment links when
   delivering the canonical file. This option exists as you may have multiple
   file fields on a single content type.
4. You can then create a file node and attach some files to it. When you view
   the node, you'll see the links to the two versions of the file provided in
   the content area. You can change this by heading to 'Display fields' section
   for the content type, and dragging to change it's position or hide it for
   the teaser or all modes like 'full', 'rss' and 'teaser'.
5. There is also an 'Attachment links' section on the node edit form that shows
   information, such as the currently used field and the links (in case these
   are not prominently displayed on the node view page.

Upgrading from Drupal 6
========================

The system updates will move your files from the Upload module's 'attached' list
to a file field named 'upload' automatically. Simply select this field on the
content type edit form under 'Attachment links' to re-enable this functionality.


Written and maintained by:
Four Kitchens
http://fourkitchens.com

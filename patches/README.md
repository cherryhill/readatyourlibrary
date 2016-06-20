# Patches
---------

Patch documentation should be in the following format:

* _module name_
  * _brief description_
  * _issue link (if exists)_
  * _patch file location_

* addressfield_staticmap
  * $settings variable check in tpl results in `0` printing above map
  * https://www.drupal.org/node/2218091
  * https://www.drupal.org/files/issues/addressfield_staticmap-check_for_string_value-2218091-4.patch

* block_titlelink
  * Collapse fieldset by default
  * https://www.drupal.org/node/2500739
  * https://www.drupal.org/files/issues/block_titlelink-fieldset_default_collapsed-2500739-1.patch
  * The patch is made against 7.x-1.x-dev but the stable release has been
    modified on this site.

* calendar
  * Fix "Notice: Undefined index: groupby_times"
  * https://www.drupal.org/node/2160183
  * https://www.drupal.org/files/issues/calendar-groupby-times-2160183-1.patch

* date
  * Fix notice from new show remaining days setting
  * https://www.drupal.org/node/2469189
  * https://www.drupal.org/files/issues/date-show_remaining_days_notice-2469189-1.patch

* wysiwyg
  * Fix "Warning: file_get_contents(…)"
  * https://www.drupal.org/node/1802394
  * https://www.drupal.org/files/wysiwyg-1802394-4.patch
  * COMMITTED; remove patch file and documentation after next stable release
  * http://cgit.drupalcode.org/wysiwyg/commit/?id=cab91b8

* table_trash
  * Update Table Trash to work with DataTables library v1.10
  * https://www.drupal.org/node/2259283
  * https://www.drupal.org/files/issues/table_trash-2259283-20-rewrite-for-110.patch

# DESCRIPTION

This module converts references fields (from references module) to entity
reference fields. A batch task will be issued (per field) to create a temporary
table, store the reference values, delete the reference field, create a new 
entity reference field, and copy over the values from the temporary table.

## USAGE

There are 2 possible ways to convert fields:

### USER INTERFACE

Go to admin/content/migrate-references, select the fields you wish to convert,
and click confirm.

### DRUSH

Type 'drush entityreference-migrate-references' (or 'drush emr') to convert all
fields. You may provide a field machine name as an argument to convert on a
field-by-field basis.

## PRE-CONVERSION TASK LIST

Before starting any conversion, there are a few recommended tasks.

### FIELDS

 * Create a where-used list of fields, widgets and formatters, using:
  * core: /admin/reports/fields
  * contrib: https://drupal.org/project/field_info

### VIEWS

 *Create a where-used list of fields, filter criteria, sort criteria, contextual
filters, using:
  * views: /admin/reports/fields/views-fields
  * There are some issues when you have a entityreference as an exposed filter,
see: https://drupal.org/project/issues/entityreference?text=exposed+filter

### CUSTOM CODE

Check your custom code that explicitly calls on data stored in references
format.

### BACKUP YOUR DATA

This is (very) strongly recommended.  This is a one way conversion and data may
not be easily restored if something goes wrong. Having a backup will ensure you
have a safe point to revert your site.

## POST-CONVERSION TASK LIST

Test all CRUD operation for each entity.

### FIELDS

 * For each field:
  * restore the widget: it is reset tot Autocomplete by default;
  * restore the formatter of each View mode; it is set to "Label, with link to
referenced entity" by default

### VIEWS

 * Check any views where you used the entityreference; they may have broken
handlers and will need to be rebuilt.
 * For each mentioned View, check each display and test thoroughly!
 * If you have dev environment and/or use features, perform the changes locally
and check your views. You will have the ability to export them and import into
your live site after the conversion. Using features would be even easier as you
can just revert to your new views that utilize the entity reference handler.

### CUSTOM CODE

Again, check your custom code.


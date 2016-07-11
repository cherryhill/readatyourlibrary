Sometimes when you use relationships in views you get a number of rows with the
same content in some of the fields. This results in a huge table (grid, list,
etc.) that affects the usability of your view.

The Views Merge Rows module provides a way to combine rows with the same content
in the specified fields.

Installation and Configuration
------------------------------
After installing the module you get the “Merge rows” item in the OTHER section
of the Views UI.

To configure the row merging click the link next to the “Merge rows” item.

In the configuration dialog you can enable/disable row merging with the
“Merge rows with the same content in the specified fields” checkbox.
After you enable the merging you will see the table with all the available
fields. You can specify the “Merge option” for each field.

The fields with “Merge option” set to “Use values of this field as a filter” are
used to check which rows should be merged. If several rows contain exactly the
same values in all of these fields, they are merged together. The values for
other fields are calculated as follows:

For fields with “Merge option” set to “Use the first value of this field” only
the value from the first merged rows is used. The values in other rows are
disregarded.
For fields with “Merge option” set to “Merge values of this field” all the
values appears in the resulting row.

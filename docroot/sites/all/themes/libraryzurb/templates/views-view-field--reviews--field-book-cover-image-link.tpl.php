<?php

/**
 * @file
 * This template is used to print a single field in a view.
 *
 * It is not actually used in default Views, as this is registered as a theme
 * function which has better performance. For single overrides, the template is
 * perfectly okay.
 *
 * Variables available:
 * - $view: The view object
 * - $field: The field handler object that can process the input
 * - $row: The raw SQL result that can be used
 * - $output: The processed output that will normally be used.
 *
 * When fetching output from the $row, this construct should be used:
 * $data = $row->{$field->field_alias}
 *
 * The above will guarantee that you'll always get the correct data,
 * regardless of any changes in the aliasing that might happen if
 * the view is modified.
 */

if ($output) {                 
    $bimg = "<img src='".trim($output)."' style='width:200px;height:200px;'>";  
  }
  else {
    $bimg =  "<img src='http://www.clker.com/cliparts/7/1/a/f/11971220941184963828dniezby_Generic_Book.svg.med.png' style='width:200px;height:200px;'>";
  }  
  print  "<table><tr><td>".$bimg."</td>";
  print  "</tr></table>";

?>
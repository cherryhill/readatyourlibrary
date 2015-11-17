
## BASIC INFO

   Noggin allows users to add or change the header images.
   The original module was coded by Jeff Eaton. Later work
   has been contributed by Jeff Burnz and Stefan Borchert.

   Noggin was originally designed for use with Bartik and
   other core themes, however Noggin will now work with
   any theme. The main fearures are:

   - Upload header image
   - Choose from existing images (supplied by Noggin or your theme)
   - CSS settings to position, tile or stretch the image
   - Set a background color
   - Set height of the header
   - Add extra CSS declarations


## CSS SELECTOR

   This is the CSS id or class your theme uses on the header.
   We use this so Noggin knows what element to apply the image
   and other CSS styles to. Many themes, such as Bartik, will
   use #header, however other themees might not and you will
   need to view the page source (using Firefox or View Source
   in your browser) to find the right CSS selector. Some trial
   and error may be needed.

   Here are a few themes and the correct selector:
   - Bartik: #header or #header .section
   - Garland: #header
   - AT Commerce: #header-wrapper or #header-wrapper .container
   - Pixture Reloaded: #header .header-innner


## HEADER HEIGHT

   Header height may depend on other elements and CSS in the
   theme and the limited options provided by Noggin module may
   not be enough to adjust the header height. In this case you
   will either need to provide your own custom CSS or other
   changes.

   When setting the header height you must give the value and the
   unit, for example 200px (200 is the value, px is the unit).


## INCLUDING IMAGES FROM YOUR THEME

   Noggin can use header images supplied by your theme. All you
   need to do is place the images in a "header-images" directory
   in your theme root, e.g.

   ~/sites/all/themes/mytheme/header-images

   Images must be either .png or .jpg.


## HELP!!!

   http://drupal.org/project/issues/noggin





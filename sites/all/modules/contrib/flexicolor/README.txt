$Id $

FLEXICOLOR MODULE
=================

INSTALL INSTRUCTIONS:
1) Install flexicolor module
2) Grant users that have the ability to create CSS rulesets and color scheme
  presets with the 'administer flexicolor settings' permission and grant users
  that have the ability to change the look/feel of the site (only the colors)
  from the presets with 'manage flexicolor settings'.
3) Go to /admin/settings/flexicolor.  There are 4 tabs that you should see:
  * Site Settings pertaining to Flexicolor
  * Manage Flexicolor Settings
  * Add Flexicolor Selector
  * Add Flexicolor Preset
4) Add Flexicolor selector is where you start defining css selectors on the
  site.  You allow for someone with 'manage flexicolor settings' to select a color
  for the selectors that are defined.
  (a) Provide a display name - this is strictly to provide context on the type
    of selectors you are going to define.
  (b) Define your list of CSS selectors.  You may learn more about this at
    http://www.w3.org/TR/CSS2/selector.html
  (c) Provide the type of color rule (does it apply to the background color for
    the selector or is it a text color.
  (d) Select your color using the color picker or type in a valid hex color and
    hit 'Save'.
  (e) The submission state will validate against W3C's CSS Validation service -
    this is to ensure nothing problematic is entered.  If there is an error in
    the CSS, the user will be notified to correct the issue.  Otherwise, the
    selector and the selected color are saved.
  (f) Repeat steps 4(a) - 4(e) for whatever number of selectors and colors you
    wish to be able to configure for your site.
5) Add Flexicolor Preset is where you start defining preset color schemes.
  (a) Provide a display name - this is to provide context on the type of preset
    color scheme you are defining.
  (b) Select your colors for the various selectors that were defined during
    step 4 and hit 'Save'.
  (c) Repeat steps 5(a) - 5(b) for whatever number of preset color schemes you
    wish to be able to define for your site.
6) Manage Flexicolor Settings is an administrative area for viewing, editing, or
  deleting the various selectors and presets that have been defined for your
  site.
7) The primary screen (Site Settings pertaining to Flexicolor) allows you to
  pick the colors you want for your site based on the selectors that have been
  defined.  You may pick a preset to use one that was defined during step 5 or
  pick a custom set of colors or a combination of a preset with alteration of
  its colors (which will turn into a custom set of colors.  Hit
  'Save configuration' to save your settings.  Flexicolor will then generate the
  file that gets used on the site.

DESCRIPTION:
Flexicolor provides a flexible method for Drupal Designers to provide content
administrators with ways to color text and backgrounds on different parts of the
site.

The flexicolor module works in 2 stages. First, you must create selectors.
Selectors refer to CSS Selectors which are accepted (if you do not know about
them, W3 has an excellent article at
http://www.w3.org/TR/2001/CR-css3-selectors-20011113/#selectors). The selectors
require a name, a list of the selectors you want a color to apply to, along with
the default color. Second, you have the option to create presets, which will be
a color set based on all the selectors on the site. Finally, the site
editor/administrator have the ability to have to select what the colors will be
on on the site (these selections are saved to a css file).

While the core color module is an absolutely fantastic and powerful module, one
of the biggest shortcomings (as of Drupal 6) has been that there are only 5
regions of a page that can be colored (base color, link color, top header,
bottom header, and text color). And while the color ng module
(http://drupal.org/project/color_soc08) is also fantastic, it is not recommended
for production usage by the core maintainer and it still did not satisfy my set
of requirements (which is where the Drupal 7 version stands for my needs as well
for a virtually limitless set of areas that can be colored without
re-implementing changes at the theme layer). This module came out of a set of
client's need where:

  1. There are an unspecified set of areas where the colors are customizable by
    the site editor. The process would be slowed down by requiring the designer
    to go through me each time new coloring regions need to be added.
  2. The set of areas that have customizable colors can be increased or reduced.
    Down the line, the client needed to be able to add new regions that can be
    colored. While having these settings in the theme would be useful, it would
    also be problematic as it would require a developer/designer familiar with
    the way the color module works to make it all run correctly.
  3. Presets can be created for the site editor to choose from.
  4. The module must play well with the domain access module.

The module also plays very well with the domain access module.

Features that I would like to add down the line:

  1. Pre-added blocks region selectors that a non-designer/developer could add
    as a selectors to get custom colors.
  2. On-the-fly preview of the page as colors are being changed. While it is
    fairly easy to solve if the main site theme is loaded, it is more difficult
    to try and color pages that are running with an administrative theme.
  3. Different presets that are applied for different themes. It currently
    works with the active site theme in non-admin areas of the site.
  4. Due to the problem set being covered, the module is definitely created
    for someone that has a solid understanding of css selectors to get more
    power out of the site. Any suggestions for a simpler ui are very welcome.
    
CREDIT:
Sponsored and maintained by the California Institute of the Arts
OVERVIEW
========

The ABBRfilter module allows you to filter abbreviations in site content
and replace the filtered abbreviations with <abbr> tags and a title
descriptor that contains the unabbreviated phrase. The filter can be
enabled for any Text Format in D7, and will apply to any content that can
use the text format. The filters are applied only when viewing content so
the original text is not altered.


THEMING
=======

If you wish to attempt to filter other text in your theme,
call the function _filter_abbrfilter_process($text)


CREDITS
=======

6.x branch written by Eric Davila
http://drupal.org/user/430759

7.x branch maintained by Four Kitchens

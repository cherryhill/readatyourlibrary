<?php
/**
 * @file
 * librarysite_text_formats_wysiwyg_imce.features.wysiwyg.inc
 */

/**
 * Implements hook_wysiwyg_default_profiles().
 */
function librarysite_text_formats_wysiwyg_imce_wysiwyg_default_profiles() {
  $profiles = array();

  // Exported profile: filtered_html
  $profiles['filtered_html'] = array(
    'format' => 'filtered_html',
    'editor' => 'tinymce',
    'settings' => array(
      'default' => 1,
      'user_choose' => 0,
      'show_toggle' => 1,
      'theme' => 'advanced',
      'language' => 'en',
      'buttons' => array(
        'default' => array(
          'bold' => 1,
          'italic' => 1,
          'bullist' => 1,
          'numlist' => 1,
          'unlink' => 1,
          'image' => 1,
          'formatselect' => 1,
          'styleselect' => 1,
          'blockquote' => 1,
        ),
        'paste' => array(
          'pasteword' => 1,
        ),
        'imce' => array(
          'imce' => 1,
        ),
        'linkit' => array(
          'linkit' => 1,
        ),
      ),
      'toolbar_loc' => 'top',
      'toolbar_align' => 'left',
      'path_loc' => 'bottom',
      'resizing' => 1,
      'verify_html' => 1,
      'preformatted' => 0,
      'convert_fonts_to_spans' => 1,
      'remove_linebreaks' => 0,
      'apply_source_formatting' => 0,
      'paste_auto_cleanup_on_paste' => 1,
      'block_formats' => 'p,h2,h3,h4,div,blockquote',
      'css_setting' => 'self',
      'css_path' => '/sites/all/themes/libraryzurb/css/custom.css',
      'css_classes' => 'Align right=right
Align left=left
Special=special
Aside=aside
Notice=notice',
      'buttonorder' => 'bold,italic,bullist,numlist,linkit,unlink,image,formatselect,styleselect,blockquote,pasteword,imce',
    ),
    'rdf_mapping' => array(),
  );

  // Exported profile: filtered_html_with_embed
  $profiles['filtered_html_with_embed'] = array(
    'format' => 'filtered_html_with_embed',
    'editor' => 'tinymce',
    'settings' => array(
      'default' => 1,
      'user_choose' => 0,
      'show_toggle' => 1,
      'theme' => 'advanced',
      'language' => 'en',
      'buttons' => array(
        'default' => array(
          'bold' => 1,
          'italic' => 1,
          'bullist' => 1,
          'numlist' => 1,
          'unlink' => 1,
          'image' => 1,
          'formatselect' => 1,
          'styleselect' => 1,
          'blockquote' => 1,
        ),
        'paste' => array(
          'pasteword' => 1,
        ),
        'media' => array(
          'media' => 1,
        ),
        'imce' => array(
          'imce' => 1,
        ),
        'linkit' => array(
          'linkit' => 1,
        ),
      ),
      'toolbar_loc' => 'top',
      'toolbar_align' => 'left',
      'path_loc' => 'bottom',
      'resizing' => 1,
      'verify_html' => 1,
      'preformatted' => 0,
      'convert_fonts_to_spans' => 1,
      'remove_linebreaks' => 0,
      'apply_source_formatting' => 0,
      'paste_auto_cleanup_on_paste' => 1,
      'block_formats' => 'p,h2,h3,h4,div,blockquote',
      'css_setting' => 'self',
      'css_path' => '/sites/all/themes/libraryzurb/css/custom.css',
      'css_classes' => 'Align right=right
Align left=left
Special=special
Aside=aside
Notice=notice',
      'buttonorder' => 'bold,italic,bullist,numlist,linkit,unlink,image,formatselect,styleselect,blockquote,pasteword,media,imce',
    ),
    'rdf_mapping' => array(),
  );

  // Exported profile: filtered_html_with_tables
  $profiles['filtered_html_with_tables'] = array(
    'format' => 'filtered_html_with_tables',
    'editor' => 'tinymce',
    'settings' => array(
      'default' => 1,
      'user_choose' => 0,
      'show_toggle' => 1,
      'theme' => 'advanced',
      'language' => 'en',
      'buttons' => array(
        'default' => array(
          'bold' => 1,
          'italic' => 1,
          'bullist' => 1,
          'numlist' => 1,
          'unlink' => 1,
          'image' => 1,
          'formatselect' => 1,
          'styleselect' => 1,
          'blockquote' => 1,
        ),
        'paste' => array(
          'pasteword' => 1,
        ),
        'table' => array(
          'tablecontrols' => 1,
        ),
        'imce' => array(
          'imce' => 1,
        ),
        'linkit' => array(
          'linkit' => 1,
        ),
      ),
      'toolbar_loc' => 'top',
      'toolbar_align' => 'left',
      'path_loc' => 'bottom',
      'resizing' => 1,
      'verify_html' => 1,
      'preformatted' => 0,
      'convert_fonts_to_spans' => 1,
      'remove_linebreaks' => 0,
      'apply_source_formatting' => 0,
      'paste_auto_cleanup_on_paste' => 1,
      'block_formats' => 'p,h2,h3,h4,div,blockquote',
      'css_setting' => 'self',
      'css_path' => '/sites/all/themes/libraryzurb/css/custom.css',
      'css_classes' => 'Align right=right
Align left=left
Special=special
Aside=aside
Notice=notice',
      'buttonorder' => 'bold,italic,bullist,numlist,linkit,unlink,image,formatselect,styleselect,blockquote,pasteword,tablecontrols,imce',
    ),
    'rdf_mapping' => array(),
  );

  // Exported profile: simple_html
  $profiles['simple_html'] = array(
    'format' => 'simple_html',
    'editor' => 'tinymce',
    'settings' => array(
      'default' => 1,
      'user_choose' => 0,
      'show_toggle' => 1,
      'theme' => 'advanced',
      'language' => 'en',
      'buttons' => array(
        'default' => array(
          'bold' => 1,
          'italic' => 1,
          'unlink' => 1,
        ),
        'paste' => array(
          'pasteword' => 1,
        ),
        'linkit' => array(
          'linkit' => 1,
        ),
      ),
      'toolbar_loc' => 'top',
      'toolbar_align' => 'left',
      'path_loc' => 'bottom',
      'resizing' => 1,
      'verify_html' => 1,
      'preformatted' => 0,
      'convert_fonts_to_spans' => 1,
      'remove_linebreaks' => 0,
      'apply_source_formatting' => 0,
      'paste_auto_cleanup_on_paste' => 1,
      'block_formats' => 'p,address,pre,h2,h3,h4,h5,h6,div',
      'css_setting' => 'self',
      'css_path' => '/sites/all/themes/libraryzurb/css/custom.css',
      'css_classes' => 'Align right=right
Align left=left
Special=special
Aside=aside
Notice=notice',
      'buttonorder' => 'bold,italic,unlink,pasteword,linkit',
    ),
    'rdf_mapping' => array(),
  );

  return $profiles;
}

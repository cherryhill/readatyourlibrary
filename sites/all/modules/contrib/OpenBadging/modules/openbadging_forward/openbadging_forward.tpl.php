<?php
// $Id openbadging_forward.tpl.php

/**
 * This template should only contain the contents of the body
 * of the email, what would be inside of the body tags, and not
 * the header.  You should use tables for layout since Microsoft
 * actually regressed Outlook 2007 to not supporting CSS layout.
 * All styles should be inline.
 * * 
 *
 * If you are upgrading from an old version of Forward, be sure
 * to visit the openbadging Forward settings page to enable use of the new
 * template system.
 */
?>
<html>
  <body>
    <table width="<?php print $width; ?>" cellspacing="0" cellpadding="10" border="0">
      <thead>
        <tr>
          <td>
            <h1 style="font-family:Arial,Helvetica,sans-serif; font-size:18px;">
              <a href="<?php if ($title) { ?>" title="<?php //print $title;    ?>">
                  <?php //print $logo; ?> 
                  <?php print $title;
                } ?>
              </a>
            </h1>
          </td>
        </tr>
      </thead>
      <tbody>
        <tr>
          <td style="font-family:Arial,Helvetica,sans-serif; font-size:13px;">
            <?php print $openbadging_forward_message; ?>
            <?php if ($message) { ?>
              <p>
                <?php print t('Message from Sender:'); ?>
              </p>
              <p>
                <?php print $message; ?>
              </p>
            <?php } ?>                                
          </td>          
        </tr>
        <tr> 
          <td style="font-family:Arial,Helvetica,sans-serif; font-size:13px;">
            <?php print $openbadging_forward_footer; ?>
          </td>
        </tr>
      </tbody>
    </table>
  </body>
</html>

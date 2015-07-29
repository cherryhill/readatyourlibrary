<?php

/**
 * @file
 * Template that formats the individual link output.
 *
 * $vls_data
 *   The array of languages and their associated counts
 * $vls_data['language']
 *   An array containing the language name in English, in its
 *   native format, and its two-letter code.
 * $vls_data['count']
 *   The number of items that were found. Basically either 0 or
 *   non-zero are the two distinctions.
 * $vls_data['path']
 *   The path that we should link to.
 */
?>
<?php if ($vls_data['count'] != 0): ?>
  <span class="vls-item vls-<?php print $vls_data['language']['code'] ?> vls-link <?php print $vls_data['language']['is_current'] ?>" lang="<?php print $vls_data['language']['code'] ?>">
    <a href="<?php print $vls_data['path'] ?>"><?php print $vls_data['language']['native']; ?></a>
  </span>
<?php else: ?>
  <span class="vls-item vls-<?php print $vls_data['language']['code'] ?> vls-nolink <?php print $vls_data['language']['is_current'] ?>" lang="<?php print $vls_data['language']['code'] ?>">
    <?php print $vls_data['language']['native']; ?>
  </span>
<?php endif; ?>

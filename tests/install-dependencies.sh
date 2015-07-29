#!/bin/sh

BEHAT_DIRECTORY="$( cd "$( dirname "${BASH_SOURCE[0]}" )" && pwd )/behat"

curl -sS https://getcomposer.org/installer | php -- --install-dir=$BEHAT_DIRECTORY
rm -rf $BEHAT_DIRECTORY/bin $BEHAT_DIRECTORY/vendor $BEHAT_DIRECTORY/composer.lock
php $BEHAT_DIRECTORY/composer.phar --working-dir=$BEHAT_DIRECTORY install
php $BEHAT_DIRECTORY/composer.phar --working-dir=$BEHAT_DIRECTORY update
find $BEHAT_DIRECTORY -name ".git" | xargs rm -rf
find $BEHAT_DIRECTORY -name ".gitignore" | xargs rm -rf


#!/bin/sh

RESULTS_DIRECTORY="$( cd "$( dirname "${BASH_SOURCE[0]}" )" && pwd )/../results"
BEHAT_DIRECTORY="$( cd "$( dirname "${BASH_SOURCE[0]}" )" && pwd )/behat"

rm -rf $RESULTS_DIRECTORY/*
# rm -rf $BEHAT_DIRECTORY/bin $BEHAT_DIRECTORY/composer.phar $BEHAT_DIRECTORY/composer.lock $BEHAT_DIRECTORY/vendor

#!/bin/sh

# BEHAT TESTS
BEHAT_CONFIG_FILE=$1
BEHAT_ENVIRONMENT_PROFILE=$2
BEHAT_DIRECTORY="$( cd "$( dirname "${BASH_SOURCE[0]}" )" && pwd )/behat"

if [[ -z $BEHAT_CONFIG_FILE ]]
then
  BEHAT_CONFIG_FILE="behat.yml"
fi

if [[ -z $BEHAT_ENVIRONMENT_PROFILE ]]
then
  BEHAT_ENVIRONMENT_PROFILE="default"
fi

# bash $BEHAT_DIRECTORY/../install-dependencies.sh
$BEHAT_DIRECTORY/bin/behat --config $BEHAT_DIRECTORY/config/$BEHAT_CONFIG_FILE --profile $BEHAT_ENVIRONMENT_PROFILE $BEHAT_DIRECTORY/config/features --format junit --out $BEHAT_DIRECTORY/../../results

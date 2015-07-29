# features/search.feature
Feature: Search
  In order to see a word definition
  As a website user
  I need to be able to search for a word

  Scenario: Searching for a page that does NOT exist
    Given I am on "/search"
    Then I should see "Search"

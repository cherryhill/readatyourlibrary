Feature: Homepage
  When I am on the homepage
  I need to be able to see the page

  Scenario: Home page components
    Given I am on "/"
    Then I should see "Cherry Hill LibrarySite"
    And I should see "Upcoming Events"
    And I should see "The Cherry Hill Company. All rights reserved."

  Scenario: Use search
    Given I am on "/"
    When I follow "quicktabs-tab-search_our-0"
    And I fill in "search_block_form" with "test"
    And I press "edit-submit"
    Then I should be on "/search/node/test"
    And I should see "Search"

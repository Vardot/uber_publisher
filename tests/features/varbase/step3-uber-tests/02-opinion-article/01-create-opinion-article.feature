Feature: Create Opinion Article content
As an anonymous user
I will not be able to create Opinion Article content
As an admin
I will be able to create Opinion Article content

  Background:
    Given I am an anonymous user

  @javascript @local @development @staging @production
  Scenario: Check if anonymous users can create Author profile content.
    When I go to "/node/add/opinion_article"
    And I wait
    Then I should see "Access denied"

  @javascript @local @development @staging @production
  Scenario: Check if site admin users can create Author profile content.
    Given I am a logged in user with the "opinion_writer" user
    When I go to "/node/add/opinion_article"
    And I wait
    Then I should see "Create Opinion article"
    When I fill in "The race to create the perfect city" for "Title"
    And I press the "Select an image" button
    And I wait for AJAX to finish
    Then the image media browser should be open
    When I switch to iframe "entity_browser_iframe_image_browser"
    And I fill in "up avatar" for "Search keywords"
    And I press the "Search" button
    And I wait for AJAX to finish
    When I double click on the image with the "up avatar" title text
    And I wait
    And I switch to main frame
    And I select "10" from "field_section"
    When I fill in "Jon Snow (54)" for "field_author_profile[0][target_id]"
    And I fill in the rich text editor field "Body" with "<p>BBC Designed explores humankind’s desire to create ideal cities, from 8,000 years ago to the present day, in a beautiful animated video.</p>"
    And I press the "Save" button
    Then I should see "Opinion article The race to create the perfect city has been created."
    And I should see "Edit" in the "tabs"
    And I should see "Delete" in the "tabs"

    @javascript @local @development @staging @production
    Scenario: Check if anonymous users can see Opinion Article content.
      When I go to "/opinions"
      And I wait
      Then I should see "The race to create the perfect city"
      When I go to "/authors/jon-snow"
      And I wait
      Then I should see "The race to create the perfect city"

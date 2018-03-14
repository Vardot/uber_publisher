Feature: Create Breaking news content
As an anonymous user
I will not be able to create Breaking news content
As an admin
I will be able to create Breaking news content

  Background:
    Given I am an anonymous user

    @javascript @local @development @staging @production
    Scenario: Check if anonymous users can create Breaking news content.
      When I go to "/node/add/breaking_news"
      And I wait
      Then I should see "Access denied"

    @javascript @local @development @staging @production
    Scenario: Check if site admin users can create Breaking news content.
      Given I am a logged in user with the "test_site_admin" user
      When I go to "/node/add/breaking_news"
      And I wait
      Then I should see "Create Breaking news"
      When I fill in "Breaking news for testing purpose" for "Administrative title"
      And I fill in "Breaking news for testing purpose" for "Head line"
      And I fill in "<front>" for "URL"
      And I press the "Save" button

      Then I should see "Breaking news for testing purpose has been created."
      And I should see "Edit" in the "tabs"
      And I should see "Delete" in the "tabs"

    #After change the Theme this will work fine.
    #@javascript @local @development @staging @production
    #Scenario: Check if anonymous users can see Breaking news content.
      #When I go to "/"
      #And I wait
      #Then I should see "Breaking news for testing purpose"

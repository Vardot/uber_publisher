Feature: Create Author profile content - Only admins login
As an anonymous user
I will not be able to Author profile content

  Background:
    Given I am an anonymous user

  @javascript @local @development @staging @production
  Scenario: Check if anonymous users can create Author profile content.
     When I go to "/node/add/author_profile"
      And I wait
     Then I should see "Access denied"

  @javascript @local @development @staging @production
  Scenario: Check if site admin users can create Author profile content.
    Given I am a logged in user with the "test_site_admin" user
    When I go to "/node/add/author_profile"
    And I wait
    Then I should see "Create Author profile"
    When I fill in "Jon Snow" for "Name"
    And  I fill in "Ned Stark's son, Jon joined the Night's Watch. On a mission for Lord Commander Mormont, Jon infiltrated the wildlings by pretending to forsake his Night Watch brothers. In doing so, he fell in love with Ygritte, a wildling woman." for "About"
    And I attach the file "up-avatar.png" to "Profile image"
    And I wait for AJAX to finish
    And I fill in "Uber publisher avatar"
    And I press the "Save" button
    Then I should see "Author profile Jon Snow has been created."
    And I should see "Edit" in the "tabs"
    And I should see "Delete" in the "tabs"
    When I go to "/authors"
    Then I should see "Jon Snow"

Feature: Create Cartoons content
As an anonymous user
I will not be able to create Cartoons content
As an admin
I will be able to create Cartoons content

  Background:
    Given I am an anonymous user

    @javascript @local @development @staging @production
    Scenario: Check if anonymous users can create Cartoon content.
      When I go to "/node/add/caricature"
      And I wait
      Then I should see "Access denied"

    @javascript @local @development @staging @production
    Scenario: Check if site admin users can create Cartoons content.
      Given I am a logged in user with the "test_site_admin" user
      When I go to "/node/add/caricature"
      And I wait
      Then I should see "Create Cartoon"
      When I fill in "What is Cartoon today?" for "Title"
      And I fill in "Jon Snow (54)" for "field_author_profile[0][target_id]"

      And I fill in the rich text editor field "Description" with "<p>A caricature is a rendered image showing the features of its subject in a simplified or exaggerated way through sketching, pencil strokes, or through other artistic drawings.<br>In literature, a caricature is a description of a person using exaggeration of some characteristics and oversimplification of others.<br>Caricatures can be insulting or complimentary and can serve a political purpose or be drawn solely for entertainment. Caricatures of politicians are commonly used in editorial cartoons, while caricatures of movie stars are often found in entertainment magazines.</p>"

      And I attach the file "up-avatar.png" to "Image"
      And I wait for AJAX to finish
      And I fill in "Uber publisher avatar" for "Alternative text"
      And I press the "Save" button

      Then I should see "Cartoon What is Cartoon today? has been created."
      And I should see "Edit" in the "tabs"
      And I should see "Delete" in the "tabs"

      When I go to "/node/add/caricature"
      And I wait
      Then I should see "Create Cartoon"
      When I fill in "Old Cartoon" for "Title"
      And I fill in "2017-10-01" for "Date"
      And I fill in "Jon Snow (54)" for "field_author_profile[0][target_id]"

      And I fill in the rich text editor field "Description" with "<p>A caricature is a rendered image showing the features of its subject in a simplified or exaggerated way through sketching, pencil strokes, or through other artistic drawings.<br>In literature, a caricature is a description of a person using exaggeration of some characteristics and oversimplification of others.<br>Caricatures can be insulting or complimentary and can serve a political purpose or be drawn solely for entertainment. Caricatures of politicians are commonly used in editorial cartoons, while caricatures of movie stars are often found in entertainment magazines.</p>"

      And I attach the file "up-avatar.png" to "Image"
      And I wait for AJAX to finish
      And I fill in "Uber publisher avatar" for "Alternative text"
      And I press the "Save" button

      Then I should see "Old Cartoon has been created."
      And I should see "Edit" in the "tabs"
      And I should see "Delete" in the "tabs"

    @javascript @local @development @staging @production
    Scenario: Check if anonymous users can see Cartoons content.
      When I go to "/cartoons"
      And I wait
      Then I should see "What is Cartoon today?"
      And I should see "Daily Cartoons: October 1, 2017" in the "more cartoons landing page"
      When I click "Daily Cartoons: October 1, 2017" in the "more cartoons landing page"
      And I wait
      Then I should see "Old Cartoon"
      And I should see "2017-10-01 "
      And I should see "Jon Snow"
      When I click "Jon Snow"
      And I wait
      Then I should see "What is Cartoon today?"

Feature: Create media for uber pub;isher tests.
  Background:
    Given I am a logged in user with the "webmaster" user
  @javascript @local @development @staging @production
  Scenario: Check if content admins can edit files.
     When I go to "media/add/image"
     And I attach the file "up-avatar.png" to "Image"
     And I wait for AJAX to finish
     And I fill in "up avatar" for "field_image[0][alt]"
     And I fill in "up avatar" for "field_image[0][title]"
     And I fill in "up avatar" for "Media name"
     And I press the "Save" button
     Then I should see "up avatar"

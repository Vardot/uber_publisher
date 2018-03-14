Feature: Create opinion writer testing users.

# opinion_writer: { email: 'opinion_writer.test@vardot.com', password: 'dD.123123ddd' }

  Background:
    Given I am a logged in user with the "webmaster" user

  @init @tools @local @development @staging
  Scenario: Create the test_authenticated user.
     When I go to "/admin/people/create"
      And I wait
      And I fill in "opinion_writer.test@vardot.com" for "Email address"
      And I fill in "opinion_writer" for "Username"
      And I fill in "dD.123123ddd" for "Password"
      And I fill in "dD.123123ddd" for "Confirm password"
      And I check the box "Opinion writer"
      And I press "Create new account"
      And I wait
     Then I should not see "The name opinion_writer is already taken."

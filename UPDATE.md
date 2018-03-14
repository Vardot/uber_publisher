---

# Uber Publisher 8.4.0-alpha01 to Uber Publisher 8.4.0-alpha02

## Updating files with Copy and Paste for 8.4.0-alpha01 to Uber Publisher 8.4.0-alpha02
```
  Given that we are at the drupal root folder for uber_publisher
   When we delete all drupal core folders and files
    And we copy all new Uber publisher files drupal root folder for uber_publisher
    And we make sure that we have all custom module or themes still in the
        "sites" folder
    And we make sure that all new used modules and features are present.
   Then we will be ready to update the active config and database.
```
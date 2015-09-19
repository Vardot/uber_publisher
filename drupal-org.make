; A make file to specify Varbase distro packages
; These projects are dependencies for profile or for features included in the profile,
; some packages are added as a suggestion with their patches or being very popular
core = 7.x
api = 2

;;;;;;;;;;;;;;;;;;;;;
;; Uber Publisher Core contrib modules.
;;;;;;;;;;;;;;;;;;;;;

projects[hierarchical_select][version] = 3.0-beta2
projects[hierarchical_select][subdir] = contrib
projects[hierarchical_select][patch][2456075] = "http://www.drupal.org/files/issues/hs-double-encoding-fix.patch"

projects[less][version] = 4.0
projects[less][subdir] = contrib

projects[menu_attributes][version] = 1.0-rc3
projects[menu_attributes][subdir] = contrib

projects[menu_minipanels][version] = 2.0-beta1
projects[menu_minipanels][subdir] = contrib
projects[menu_minipanels][patch][2427971] = "http://www.drupal.org/files/issues/load_mini_panels_block-2427971-1.patch"

projects[nodequeue][version] = 2.0
projects[nodequeue][subdir] = contrib

projects[panels_mini_ipe][version] = 1.0-beta4
projects[panels_mini_ipe][subdir] = contrib

projects[rules][version] = 2.9
projects[rules][subdir] = contrib

projects[scheduler][version] = 1.3
projects[scheduler][subdir] = contrib

projects[service_links][version] = 2.3
projects[service_links][subdir] = contrib

projects[shortcutperrole][version] = 1.2
projects[shortcutperrole][subdir] = contrib

projects[special_menu_items][version] = 2.0
projects[special_menu_items][subdir] = contrib

projects[views_autocomplete_filters][version] = 1.2
projects[views_autocomplete_filters][subdir] = contrib

projects[views_litepager][version] = 3.0
projects[views_litepager][subdir] = contrib

projects[views_load_more][version] = 1.5
projects[views_load_more][subdir] = contrib

projects[views_slideshow][version] = 3.1
projects[views_slideshow][subdir] = contrib
projects[views_slideshow][do_recursion] = 0


;;;;;;;;;;;;;;;;;;;;;
;; Uber Publisher Apps contrib modules.
;;;;;;;;;;;;;;;;;;;;;

projects[disqus][version] = 1.12
projects[disqus][subdir] = apps_contrib

projects[mailchimp][version] = 3.4
projects[mailchimp][subdir] = apps_contrib

projects[socialfield][version] = "1.x-dev"
projects[socialfield][download][type] = "git"
projects[socialfield][download][url] = "http://git.drupal.org/project/socialfield.git"
projects[socialfield][download][revision] = "af34c5777183a58deb27f07645c8cf0961ef0eb2"
projects[socialfield][subdir] = apps_contrib


;;;;;;;;;;;;;;;;;;;;;
;; Uber Publisher migration modules.
;;;;;;;;;;;;;;;;;;;;;

projects[feeds][version] = 2.0-beta1
projects[feeds][subdir] = migrate

projects[feeds_crawler][version] = 1.0-beta2
projects[feeds_crawler][subdir] = migrate

projects[feeds_tamper][version] = 1.1
projects[feeds_tamper][subdir] = migrate

projects[feeds_ex][version] = 1.0-beta2
projects[feeds_ex][subdir] = migrate

projects[media_feeds][version] = 2.0-alpha1
projects[media_feeds][subdir] = migrate


;;;;;;;;;;;;;;;;;;;;;
;; Libraries
;;;;;;;;;;;;;;;;;;;;;

libraries[bootstrap][download][type] = "get"
libraries[bootstrap][download][url] = "http://github.com/twbs/bootstrap/archive/v3.3.4.tar.gz"
libraries[bootstrap][destination] = "themes/uber_theme/lib/"

libraries[bootstrap-rtl][download][type] = "get"
libraries[bootstrap-rtl][download][url] = "http://github.com/morteza/bootstrap-rtl/archive/v3.3.4.tar.gz"
libraries[bootstrap-rtl][destination] = "themes/uber_theme/lib/"

libraries[colorpicker][download][type] = "get"
libraries[colorpicker][download][url] = "http://www.eyecon.ro/colorpicker/colorpicker.zip"

libraries[disqusapi][download][type] = "get"
libraries[disqusapi][download][subtree] = "disqus-php-b1149196ec8aaa9d4dac35a4a28c5647c17ef8af/disqusapi/"
libraries[disqusapi][download][url] = "http://github.com/disqus/disqus-php/archive/b1149196ec8aaa9d4dac35a4a28c5647c17ef8af.tar.gz"

libraries[jQuery.Marquee][download][type] = "get"
libraries[jQuery.Marquee][download][url] = "http://github.com/aamirafridi/jQuery.Marquee/archive/1.3.1.zip"

libraries[jquery.cycle][download][type] = "get"
libraries[jquery.cycle][download][url] = "http://github.com/malsup/cycle/archive/3.0.3.tar.gz"

libraries[mailchimp][download][type] = "get"
libraries[mailchimp][download][url] = "http://bitbucket.org/mailchimp/mailchimp-api-php/get/2.0.6.tar.gz"

libraries[noty][download][type] = "get"
libraries[noty][download][url] = "http://github.com/needim/noty/archive/v2.3.5.tar.gz"

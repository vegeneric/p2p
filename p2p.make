core = 6.x
api = 2

projects[] = "drupal"

; Modules

projects[admin_menu][subdir] = "contrib"

projects[cck][subdir] = "contrib"

projects[autoassignrole][subdir] = "contrib"

projects[content_profile][subdir] = "contrib"

projects[date][subdir] = "contrib/date"

projects[diff][subdir] = "contrib"

projects[features][subdir] = "contrib"

projects[flag][subdir] = "contrib"
projects[flag][version] = 2.0-beta3

projects[jquery_ui][subdir] = "contrib"

projects[rules][subdir] = "contrib/rules"

projects[token][subdir] = "contrib"

projects[views][subdir] = "contrib"

projects[person_to_person][type] = module
projects[person_to_person][download][type] = git
projects[person_to_person][download][url] = https://vegeneric@github.com/vegeneric/p2p.git
projects[person_to_person][subdir] = "custom"

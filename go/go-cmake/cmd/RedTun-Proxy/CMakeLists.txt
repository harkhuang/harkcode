ExternalGoProject_Add(yaml.v2 gopkg.in/yaml.v2)

set(SOURCE_FILE yaml.v2
                main.go)

add_go_executable(RedTun ${SOURCE_FILE})

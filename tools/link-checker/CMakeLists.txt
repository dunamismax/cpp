add_executable(link-checker src/main.cpp)

target_link_libraries(link-checker PRIVATE cpr::cpr)

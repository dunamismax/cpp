add_executable(http-server src/main.cpp)

target_link_libraries(http-server PRIVATE httplib::httplib)

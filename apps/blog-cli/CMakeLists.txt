add_executable(blog-cli src/main.cpp)

target_link_libraries(blog-cli PRIVATE markdown-generator cxxopts::cxxopts)

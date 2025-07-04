add_library(markdown-generator src/lib.cpp src/lib.h)
target_include_directories(markdown-generator PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/src)

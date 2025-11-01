add_library(test_basic OBJECT test.cpp)
target_include_directories(test_basic PRIVATE ${CMAKE_SOURCE_DIR}/include)
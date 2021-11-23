cmake_minimum_required(VERSION 3.8)
project(SimpleTest)

# Use specific path to libs and headers for 3pp libraries
include_directories(SYSTEM /tmp/install/include)
link_directories(/tmp/install/lib)

set(CMAKE_CXX_STANDARD 14)
enable_testing()

add_executable(${PROJECT_NAME}
  main.cpp
  gtest.cpp
  approvals.cpp)

target_link_libraries(${PROJECT_NAME} ApprovalTests gtest gtest_main pthread)

add_test(NAME ${PROJECT_NAME} COMMAND ${PROJECT_NAME})

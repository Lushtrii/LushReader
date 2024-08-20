cmake_minimum_required(VERSION 3.14)

project(LushReader VERSION 0.1)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED True)
set(CMAKE_CXX_EXTENSIONS OFF)

include(FetchContent)
FetchContent_Declare(
  googletest
  GIT_REPOSITORY        https://github.com/google/googletest.git
  GIT_TAG               ff233bdd4cac0a0bf6e5cd45bda3406814cb2796
)

FetchContent_MakeAvailable(googletest)

add_subdirectory(lushreader)
add_subdirectory(tests)

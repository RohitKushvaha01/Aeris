cmake_minimum_required(VERSION 3.10)

project(Aeris)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Find MirAL package
find_package(PkgConfig REQUIRED)
pkg_check_modules(MIRAL REQUIRED miral)

# Add include directories and link libraries
include_directories(${MIRAL_INCLUDE_DIRS})
link_directories(${MIRAL_LIBRARY_DIRS})

file(GLOB_RECURSE SOURCES src/*.cpp)


add_executable(aeris ${SOURCES})

target_link_libraries(aeris ${MIRAL_LIBRARIES})

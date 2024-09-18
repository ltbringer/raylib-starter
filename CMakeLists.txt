cmake_minimum_required(VERSION 3.29)
project(raylib-starter C)

set(CMAKE_C_STANDARD 23)
set(CMAKE_C_STANDARD_REQUIRED ON)

include(${CMAKE_CURRENT_SOURCE_DIR}/cmake/Dependencies.cmake)

#[[ Compile Source ]]
#[[ Search for all the .c files in the src directory (recursively).
The paths found will be available within the `SOURCE_FILES` variable.
]]
file(GLOB_RECURSE SOURCE_FILES src/*.c)

#[[ Build ]]
# Creates an executable named $PROJECT_NAME using the .c files.
# NOTE!: This should come before [[ Dependencies ]].
add_executable(${PROJECT_NAME} ${SOURCE_FILES})

#[[ Dependencies ]]
add_git_dependency(${PROJECT_NAME} raylib https://github.com/raysan5/raylib.git 5.0 PRIVATE)
target_include_directories(${PROJECT_NAME} PRIVATE include)

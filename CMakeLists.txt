cmake_minimum_required(VERSION 3.6)

set(PROJECT "ADVENT_OF_CODE")
project(${PROJECT})

message("${CMAKE_CURRENT_SOURCE_DIR}" ${CMAKE_CURRENT_SOURCE_DIR})

message(STATUS "These are the sources :" ${SOURCES})
message(STATUS "And headers: " ${HEADERS})

set(BUILD_DIR ${CMAKE_CURRENT_SOURCE_DIR}/build_debug)

if( CMAKE_BUILD_TYPE STREQUAL "Release")
    message(STATUS "Building release....")
    add_compile_definitions(RELEASE_AOC)
    set(BUILD_DIR ${CMAKE_CURRENT_SOURCE_DIR}/build)
else()
    message(STATUS "Building debug....")
    
endif()

set(CMAKE_BINARY_DIR ${BUILD_DIR})
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${BUILD_DIR})
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${BUILD_DIR})


file(GLOB_RECURSE SOURCES adventUtil/*.cpp
    days/*.cpp 
    main.cpp
    )

file(GLOB_RECURSE HEADERS adventUtil/*.h
    days/*.h
    )

add_executable(${PROJECT} ${SOURCES} ${HEADERS})

target_include_directories(${PROJECT} PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/days
    ${CMAKE_CURRENT_SOURCE_DIR}/days/firstDay
    ${CMAKE_CURRENT_SOURCE_DIR}/days/secondDay
    ${CMAKE_CURRENT_SOURCE_DIR}/days/thirdDay
    ${CMAKE_CURRENT_SOURCE_DIR}/days/fourthDay
    ${CMAKE_CURRENT_SOURCE_DIR}/days/fifthDay
    ${CMAKE_CURRENT_SOURCE_DIR}/days/sixthDay
    ${CMAKE_CURRENT_SOURCE_DIR}/days/seventhDay
    ${CMAKE_CURRENT_SOURCE_DIR}/days/eighthDay
    ${CMAKE_CURRENT_SOURCE_DIR}/adventUtil
)

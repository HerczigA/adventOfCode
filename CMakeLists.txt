cmake_minimum_required(VERSION 3.6)

set(PROJECT "ADVENT_OF_CODE")
project(${PROJECT})

file(GLOB_RECURSE SOURCES adventUtil/*.cpp
    days/*.cpp 
    main.cpp
    )

file(GLOB_RECURSE HEADERS adventUtil/*.h
    days/*.h
    )

message(STATUS "These are the sources :" ${SOURCES})
message(STATUS "And headers: " ${HEADERS})

add_executable(${PROJECT} ${SOURCES} ${HEADERS})

target_include_directories(${PROJECT} PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/days
    ${CMAKE_CURRENT_SOURCE_DIR}/days/firstDay
    ${CMAKE_CURRENT_SOURCE_DIR}/days/secondDay
    ${CMAKE_CURRENT_SOURCE_DIR}/days/thirdDay
    ${CMAKE_CURRENT_SOURCE_DIR}/days/fourthDay
    ${CMAKE_CURRENT_SOURCE_DIR}/adventUtil
)

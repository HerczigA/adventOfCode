cmake_minimum_required(VERSION 3.6)

set(PROJECT "ADVENT_OF_CODE")
project(${PROJECT})


file(GLOB SOURCES adventUtil/*.cpp
    firstDay/*.cpp 
    secondDay/*.cpp
    thirdDay/*.cpp 
    main.cpp
    )

file(GLOB HEADERS adventUtil/*.h
    firstDay/*.h
    secondDay/*.h
    thirdDay/*.h
    )

message(STATUS "These are the sources :" ${SOURCES})
message(STATUS "And headers: " ${HEADERS})


add_executable(${PROJECT} ${SOURCES} ${HEADERS})

target_include_directories(${PROJECT} PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/FirstDay
)

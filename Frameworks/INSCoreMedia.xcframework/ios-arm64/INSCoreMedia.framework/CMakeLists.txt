cmake_minimum_required(VERSION 2.8)
project(llog)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 ")
set(llog_src
        src/llog/llog.h
        src/llog/llog.cpp
        src/llog/llog_message.h
        src/llog/llog_message.cpp
        src/llog/stlog.h
        src/llog/stlog.cpp
        src/llog/string_printf.h
        src/llog/string_printf.cpp
        src/llog/ptr.h
        )
if(IOS OR APPLE)
    list(APPEND llog_src 
        src/llog/apple_log.h
        src/llog/apple_log.m
        )
endif()
add_library(llog ${llog_src})
if(ANDROID)
    target_link_libraries(llog PUBLIC log)
elseif(IOS)
    target_link_libraries(llog PUBLIC "-framework Foundation")
endif()
target_include_directories(llog PUBLIC src/)

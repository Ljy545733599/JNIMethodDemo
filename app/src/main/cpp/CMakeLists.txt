# 设置 CMake 要求的最低版本
cmake_minimum_required(VERSION 3.10.2)

# 声明并命名项目
project("jnimethoddemo")

# 创建一个库，可以是 STATIC 静态库，也可以是 SHARED 动态库

add_library(
        jnimethoddemo

        SHARED

        JNIInitHelper.cpp
        ExceptionHelper.cpp
        ExceptionMethod.cpp
        MethodA.cpp
        MethodB.cpp
        MethodC.cpp)

target_sources(
        jnimethoddemo

        PUBLIC
        JNILog.h
        ExceptionHelper.h
)

# Searches for a specified prebuilt library and stores the path as a
# variable. Because CMake includes system libraries in the search path by
# default, you only need to specify the name of the public NDK library
# you want to add. CMake verifies that the library exists before
# completing its build.

find_library( # Sets the name of the path variable.
        log-lib

        # Specifies the name of the NDK library that
        # you want CMake to locate.
        log)

# Specifies libraries CMake should link to your target library. You
# can link multiple libraries, such as libraries you define in this
# build script, prebuilt third-party libraries, or system libraries.

target_link_libraries( # Specifies the target library.
        jnimethoddemo

        # Links the target library to the log library
        # included in the NDK.
        ${log-lib})
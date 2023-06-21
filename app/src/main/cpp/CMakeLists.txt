# 设置 CMake 要求的最低版本
cmake_minimum_required(VERSION 3.10.2)

# 声明并命名项目
project("jnimethoddemo")

# 遍历当前文件，添加所有的 .cpp 文件到 SRC_JNI 列表中
file(GLOB_RECURSE SRC_JNI ./*.cpp JNIUtil.cpp)
list(APPEND SRC_LIST ${SRC_JNI})

# 创建一个库，可以是 STATIC 静态库，也可以是 SHARED 动态库
add_library(
        jnimethoddemo

        SHARED

        "")

target_sources(
        jnimethoddemo

        PUBLIC
        ${SRC_LIST}
)

target_include_directories(
        jnimethoddemo

        PUBLIC
        ./
)

# 查找预编译库，并命名
find_library(
        log-lib

        log)

# 链接三方库
target_link_libraries(
        jnimethoddemo

        ${log-lib})
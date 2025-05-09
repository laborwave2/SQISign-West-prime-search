cmake_minimum_required(VERSION 3.10)
project(MyPrimeSearch)

# 查找 GMP 库：手动查找头文件和库
find_path(GMP_INCLUDE_DIR NAMES gmp.h)
find_library(GMP_LIBRARY NAMES gmp)

if(NOT GMP_INCLUDE_DIR OR NOT GMP_LIBRARY)
    message(FATAL_ERROR "找不到 GMP 库，请安装 libgmp-dev。")
endif()

include_directories(${GMP_INCLUDE_DIR})

add_executable(MyPrimeSearch main.cpp)

target_link_libraries(MyPrimeSearch ${GMP_LIBRARY})

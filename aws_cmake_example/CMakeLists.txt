# This is for getting the aws sdk going; hello_aws.cpp
cmake_minimum_required(VERSION 3.10.2)

option(BUILD_SHARED_LIBS "Build shared libraries" ON)

project(aws_cmake)

find_package(AWS REQUIRED COMPONENTS core)

add_executable(aws_cmake aws_cmake.cpp)

target_compile_features(aws_cmake PUBLIC cxx_std_11)

target_link_libraries(aws_cmake ${AWSSDK_LINK_LIBRARIES})
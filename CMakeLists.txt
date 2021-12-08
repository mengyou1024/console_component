cmake_minimum_required(VERSION 3.10)

project(y_console_component)

include_directories(.)

AUX_SOURCE_DIRECTORY(. DIR_LOC_SRCS)
message(${DIR_LOC_SRCS})

add_executable(y_console_component ${DIR_LOC_SRCS})
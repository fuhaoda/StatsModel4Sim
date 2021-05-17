cmake_minimum_required(VERSION 3.11)
project(demo)
set(CMAKE_CXX_STANDARD 17)


#The following single line works
include_directories(/Users/haodafu/Documents/Packages/Eigen/)


include_directories(../include/)
add_executable(demo main.cpp ../src/StatsModel4Sim.cpp)
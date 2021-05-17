set(sources "StatsModel4Sim.cpp")
include_directories(${PROJECT_SOURCE_DIR}/include)
add_library(StatsModel4Sim STATIC ${sources})
install(TARGETS StatsModel4Sim DESTINATION lib)
cmake_minimum_required(VERSION 3.10)
project(TradeRelay)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -pthread")

# Find Boost
find_package( Boost )

if(Boost_FOUND)
    include_directories(${Boost_INCLUDE_DIRS})
    link_directories(${Boost_LIBRARY_DIRS})
else()
    message(FATAL_ERROR "Could not find Boost libraries")
endif()

include_directories(include)

add_executable(C++LowLatencyRelay src/main.cpp src/relay.cpp)
target_link_libraries(C++LowLatencyRelay ${Boost_LIBRARIES})



cmake_minimum_required(VERSION 3.05)
project(myproject)

# SET(CMAKE_BUILD_TYPE "Debug")
SET(CMAKE_BUILD_TYPE "Release")
SET(CMAKE_CXX_FLAGS_DEBUG "$ENV{CXXFLAGS} -O0 -Wall -g2 -ggdb")
SET(CMAKE_CXX_FLAGS_RELEASE "$ENV{CXXFLAGS} -O3 -Wall")
 

set(CMAKE_CXX_STANDARD 11)
 
add_executable(${PROJECT_NAME}
  main.cpp
)
 
target_link_libraries(${PROJECT_NAME} 
  # -lzmq
  # -lprotobuf
  # -ljsoncpp
)

cmake_minimum_required( VERSION 2.8 )

project( ThreadVille )

set(CMAKE_BUILD_TYPE Debug)

include_directories(${PROJECT_SOURCE_DIR}/include)

add_executable(threadvile main.c ./src/confReader.c ./src/city.c  ./src/queues.c ./src/queues.c ./src/vehicle.c ./src/serialBridge.c ./lib/arduino-serial-lib.c)

target_link_libraries(threadvile pthread)

install (TARGETS threadvile DESTINATION bin)
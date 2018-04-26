cmake_minimum_required( VERSION 2.8 )

project( ThreadVille )


include_directories(${PROJECT_SOURCE_DIR}/include)

add_executable(threadvile main.c ./src/arduino-serial-lib.c)

target_link_libraries(threadvile)

install (TARGETS threadvile DESTINATION bin)
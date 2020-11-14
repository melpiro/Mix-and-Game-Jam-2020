cmake_minimum_required(VERSION 3.16)
project(mixgamejam2020)

set(CMAKE_CXX_STANDARD 17)

include_directories("include")

file(GLOB SRCS
        "./src/*.cpp"
        "./src/Enemies/*.cpp")
file(GLOB SRCS_OMEGA
        "./src/Omega/*.cpp"
        "./src/Omega/Data/*.cpp"
        "./src/Omega/Files/*.cpp"
        "./src/Omega/Graphics/*.cpp"
        "./src/Omega/Math/*.cpp"
        "./src/Omega/Operators/*.cpp"
        "./src/Omega/String/*.cpp"
        "./src/Omega/Vector/*.cpp"
        )

# file(GLOB OMEGA_SRCS "/home/melvyn/Documents/Projets_personels/Omega/Src/*.cpp" )
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include

        ${CMAKE_CURRENT_SOURCE_DIR}/include/Omega/
        ${CMAKE_CURRENT_SOURCE_DIR}/include/Omega/Data
        ${CMAKE_CURRENT_SOURCE_DIR}/include/Omega/Files
        ${CMAKE_CURRENT_SOURCE_DIR}/include/Omega/Graphics
        ${CMAKE_CURRENT_SOURCE_DIR}/include/Omega/Math
        ${CMAKE_CURRENT_SOURCE_DIR}/include/Omega/Operators
        ${CMAKE_CURRENT_SOURCE_DIR}/include/Omega/String
        ${CMAKE_CURRENT_SOURCE_DIR}/include/Omega/Vector)

add_executable(mixgamejam2020 ${SRCS} ${SRCS_OMEGA} src/Tilemap.cpp include/Tilemap.h src/Tile.cpp include/Tile.h src/ObjectManager.cpp include/ObjectManager.h src/Object.cpp include/Object.h src/Spawner.cpp include/Spawner.h)

# Windows
if (WIN32)
    target_link_libraries(mixgamejam2020 sfml-main sfml-graphics sfml-window sfml-system sfml-audio)
endif(WIN32)

# Linux
if (UNIX AND NOT APPLE)
    target_link_libraries(mixgamejam2020  -lX11 sfml-system sfml-window sfml-graphics sfml-network sfml-audio -pthread -lxdo)
endif (UNIX AND NOT APPLE)



# Resources area
ADD_CUSTOM_TARGET(
        copy_resources_files
        cp -r ${PROJECT_SOURCE_DIR}/resources ${CMAKE_CURRENT_BINARY_DIR}
        COMMENT "Copying Files for target: ${PROJECT_NAME}" VERBATIM
)

ADD_DEPENDENCIES(mixgamejam2020 copy_resources_files)
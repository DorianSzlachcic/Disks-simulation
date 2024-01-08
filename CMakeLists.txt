cmake_minimum_required(VERSION 3.16)
project(Disks LANGUAGES CXX)

include(FetchContent)
FetchContent_Declare(SFML
    GIT_REPOSITORY https://github.com/SFML/SFML.git
    GIT_TAG 2.6.x)
FetchContent_MakeAvailable(SFML)

file(GLOB SrcFiles
     "src/*.h"
     "src/*.cpp"
)

add_executable(Disks ${SrcFiles})
target_link_libraries(Disks PRIVATE sfml-graphics)
target_compile_features(Disks PRIVATE cxx_std_17)

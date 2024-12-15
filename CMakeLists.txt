CMAKE_MINIMUM_REQUIRED(VERSION 3.31)
PROJECT(Blython)

option(MAKE_SUBMODULES "This is to decide whether to compile SDL(_image) or not" OFF)

set(CMAKE_BUILD_TYPE Debug)

add_executable(${PROJECT_NAME} src/main.cpp)

if(MAKE_SUBMODULES)
    add_subdirectory(external/SDL)
    add_subdirectory(external/SDL_image)
endif()

target_include_directories(${PROJECT_NAME}
    PUBLIC external/SDL/include
    PUBLIC external/SDL_image/include
    PUBLIC include
)

target_link_directories(${PROJECT_NAME}
    PRIVATE build/external/SDL
    PRIVATE build/external/SDL_image
)

target_link_libraries(${PROJECT_NAME}
    SDL3
    SDL3_image
)
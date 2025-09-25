cmake_minimum_required(VERSION 3.16)
project(SailorDuckRenderer LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_library(miniwin STATIC
    vendor/miniwin/miniwin.cpp
)

target_include_directories(miniwin PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/vendor/miniwin)

if(WIN32)
    target_link_libraries(miniwin PUBLIC gdi32 user32)
endif()

add_library(sailor_duck_core STATIC
    src/ColorPalette.cpp
    src/Sprite.cpp
    src/SpriteRenderer.cpp
    src/SailorDuckSprite.cpp
)

target_include_directories(sailor_duck_core
    PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/include
        ${CMAKE_CURRENT_SOURCE_DIR}/vendor/miniwin
)

target_link_libraries(sailor_duck_core PUBLIC miniwin)

add_executable(sailor_duck_renderer WIN32
    src/main.cpp
)

target_link_libraries(sailor_duck_renderer PRIVATE sailor_duck_core)

if(MSVC)
    target_compile_options(miniwin PRIVATE /W4 /permissive-)
    target_compile_options(sailor_duck_core PRIVATE /W4 /permissive-)
    target_compile_options(sailor_duck_renderer PRIVATE /W4 /permissive-)
else()
    target_compile_options(miniwin PRIVATE -Wall -Wextra -Wpedantic)
    target_compile_options(sailor_duck_core PRIVATE -Wall -Wextra -Wpedantic)
    target_compile_options(sailor_duck_renderer PRIVATE -Wall -Wextra -Wpedantic)
endif()

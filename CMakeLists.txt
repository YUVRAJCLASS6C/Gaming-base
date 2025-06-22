cmake_minimum_required(VERSION 3.9)
project(GOOD LANGUAGES C CXX)
 find_package(OpenGL REQUIRED)
 find_package(SDL2 REQUIRED)
 
find_package(PkgConfig REQUIRED)
pkg_search_module(GLFW REQUIRED glfw3)
set(CMAKE_CXX_STANDARD 23)
set(CMAKE_C_STANDARD 23)
set(CMAKE_C_STANDARD_REQUIRED True)
set(CMAKE_C_FLAGS_DEBUG "-g -lm -O0")
set(CMAKE_CXX_FLAGS_DEBUG "-g")


file( GLOB_RECURSE  impl_c "impl/*.c")
file(GLOB_RECURSE impl_cpp "impl/*.cpp")
file(GLOB_RECURSE malloc "alloc/*c")
file(GLOB_RECURSE src_c "src/*.c")
file(GLOB_RECURSE src_cpp  "src/*.cpp")


add_library(malloc_l SHARED ${malloc})
add_library(lib_impl SHARED ${impl_c} ${impl_cpp})

target_include_directories(lib_impl PRIVATE  ${CMAKE_CURRENT_SOURCE_DIR}/include ${GLFW_INCLUDE_DIRS})
target_link_libraries(lib_impl PRIVATE ${GLFW_LIBRARIES} GL m malloc_l OpenGL::GL SDL2::SDL2)
target_include_directories(malloc_l PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)
target_link_libraries(malloc_l m OpenGL::GL SDL2::SDL2)

add_executable(exe ${src_c} ${src_cpp})

target_include_directories(exe PUBLIC ${GLFW_INCLUDE_DIRS} ${CMAKE_CURRENT_SOURCE_DIR}/include)
target_link_libraries(exe PUBLIC  ${GLFW_LIBRARIES} GL m lib_impl OpenGL::GL SDL2::SDL2 GLU glut)

cmake_minimum_required(VERSION 3.5)

set(CMAKE_MODULE_PATH
	${CMAKE_CURRENT_SOURCE_DIR}/../../../deps/Dependencies/cmake-modules
	${CMAKE_MODULE_PATH}
)

include(Header)

project(GSH_OpenGL)

if(NOT TARGET Framework_OpenGl)
add_subdirectory(
	${CMAKE_CURRENT_SOURCE_DIR}/../../../deps/Framework/build_cmake/FrameworkOpenGl
	${CMAKE_CURRENT_BINARY_DIR}/FrameworkOpenGl
)
endif()
list(APPEND PROJECT_LIBS Framework_OpenGl)

add_library(gsh_opengl STATIC 
	GSH_OpenGL.cpp
	GSH_OpenGL.h
	GSH_OpenGL_Shader.cpp
	GSH_OpenGL_Texture.cpp
)
target_link_libraries(gsh_opengl Boost::boost Framework_OpenGl ${PROJECT_LIBS})
target_include_directories(gsh_opengl PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/Source/gs/GSH_OpenGL/)

if(TARGET_PLATFORM_ANDROID OR TARGET_PLATFORM_IOS OR TARGET_PLATFORM_UNIX_AARCH64)
	target_compile_definitions(gsh_opengl PUBLIC GLES_COMPATIBILITY)
endif()

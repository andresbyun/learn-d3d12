cmake_minimum_required(VERSION 3.10.2)
project(Learn-D3D12)

set(PROJECTS
	00_initialization
)

include_directories(${CMAKE_SOURCE_DIR}/include)

function(create_project proj)
	if (CMAKE_BUILD_TYPE STREQUAL "Debug")
		add_compile_definitions("DEBUG")
	endif (CMAKE_BUILD_TYPE STREQUAL "Debug")

	file(GLOB SOURCES
		"src/${proj}/*.h"
		"src/${proj}/*.cpp"
		"util/GenericWindow.h"
		"util/GenericWindow.cpp"
	)

	add_executable(${proj} WIN32 ${SOURCES})
endfunction()

foreach(PROJECT ${PROJECTS})
	create_project(${PROJECT})
endforeach(PROJECT)

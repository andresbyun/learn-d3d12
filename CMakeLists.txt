cmake_minimum_required(VERSION 3.10.2)
project(Learn-D3D12)

set(PROJECTS
	00_initialization
)

function(create_project proj)
	file(GLOB SOURCES
		"src/${proj}/*.h"
		"src/${proj}/*.cpp"
	)

	add_executable(${proj} ${SOURCES})
endfunction()

foreach(PROJECT ${PROJECTS})
	create_project(${PROJECT})
endforeach(PROJECT)

include_directories(${CMAKE_SOURCE_DIR}/include)
cmake_minimum_required (VERSION 3.8)

project (
	"app"
	VERSION 0.0.0
	LANGUAGES C
)

if (LINUX)
	set (${CMAKE_C_FLAGS} "${CMAKE_C_FLAGS} -g")
	set (${CMAKE_C_FLAGS} "${CMAKE_C_FLAGS} -Wall")
	set (${CMAKE_C_FLAGS} "${CMAKE_C_FLAGS} -Werror")
	set (${CMAKE_C_FLAGS} "${CMAKE_C_FLAGS} -O0")
elseif(MSVC)
endif()

file (GLOB UTIL_LIBRARY
	src/util/matrix.c	src/util/matrix.h
				src/util/type.h
				src/util/vector.h
)

add_executable (${PROJECT_NAME}
	src/main.c
	${UITL_LIBRARY}
)

## Link
if (LINUX)
	target_link_libraries (${PROJECT_NAME} m)
	target_link_libraries (${PROJECT_NAME} GL)
elseif(MSVC)
	#target_link_libraries (${PROJECT_NAME} openGL)
endif()

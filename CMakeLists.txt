cmake_minimum_required (VERSION 3.8)

project (
  "app"
  VERSION 0.0.0
  LANGUAGES C
)

add_executable (${PROJECT_NAME} src/main.c)

## Link
if (LINUX)
  target_link_libraries (${PROJECT_NAME} m)
  target_link_libraries (${PROJECT_NAME} GL)
elseif(MSVC)
  #target_link_libraries (${PROJECT_NAME} openGL)
endif()

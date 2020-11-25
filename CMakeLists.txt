cmake_minimum_required(VERSION 3.16.3)

project(GameSystem)

file(GLOB_RECURSE SOURCES CONFIGURE_DEPENDS code/*.cpp)

add_executable("${PROJECT_NAME}" ${SOURCES})

set(CMAKE_EXPORT_COMPILE_COMMANDS 1)

target_include_directories(
	"${PROJECT_NAME}" PUBLIC
	header
	header/External/imgui
	header/External/imgui-sfml
	header/External/box2d
	)

target_link_directories(
	"${PROJECT_NAME}" PUBLIC
	libs
	)

find_package(ImGui-SFML REQUIRED)
target_link_libraries(
	"${PROJECT_NAME}" PUBLIC
	sfml-graphics
	sfml-window
	sfml-system
	tgui
	thor
	GL
	GLU
	glut
	box2d
	)

target_link_libraries(
	"${PROJECT_NAME}" PRIVATE
	ImGui-SFML::ImGui-SFML
	)

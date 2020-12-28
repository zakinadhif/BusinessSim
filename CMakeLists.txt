cmake_minimum_required(VERSION 3.18.4)

project(BusinessStrategy)

add_subdirectory(tests)

file(GLOB_RECURSE SOURCES CONFIGURE_DEPENDS code/*.cpp)

add_executable("${PROJECT_NAME}" ${SOURCES})

set(CMAKE_EXPORT_COMPILE_COMMANDS 1)

# Set to use C++17
set_target_properties(
	"${PROJECT_NAME}"
	PROPERTIES
	CXX_STANDARD 17
	)

# Put your box2d or EnTT or any other library's include directory below
target_include_directories(
	"${PROJECT_NAME}" PUBLIC
	header
	)

# Put your box2d or EnTT or any other library's lib directory below
target_link_directories(
	"${PROJECT_NAME}" PUBLIC

	)

# If you installed ImGui-SFML and imgui on your system, you can use this and
# add ImGui-SFML::ImGui-SFML on target_link_libraries below this, if you don't
# want to you can just remove both line, by default we include & link ImGui-SFML
# from the system, which can be a trouble if you don't have it installed
find_package(ImGui-SFML REQUIRED)
# you can though, install it manually by adding its source code manually to this project
# read more at dear imgui's and imgui-sfml's documentation

# Put box2d below if you want to link your project with box2d
target_link_libraries(
	"${PROJECT_NAME}"
	PRIVATE
	sfml-graphics
	sfml-window
	sfml-system
	tgui
	fmt
	spdlog
	GL
	ImGui-SFML::ImGui-SFML
	)

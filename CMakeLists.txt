cmake_minimum_required(VERSION 3.18.4)

project(BusinessStrategy)

add_subdirectory(tests)

file(GLOB_RECURSE SOURCES CONFIGURE_DEPENDS code/*.cpp)

add_executable("${PROJECT_NAME}" ${SOURCES})

set(CMAKE_EXPORT_COMPILE_COMMANDS 1)
add_compile_options(-Wall -Wextra -pedantic -Werror -Og)

# Set to use C++17
set_target_properties(
	"${PROJECT_NAME}"
	PROPERTIES
	CXX_STANDARD 17
	)

find_package(ImGui-SFML REQUIRED)
find_package(fmt REQUIRED)
find_package(spdlog REQUIRED)
find_package(yaml-cpp REQUIRED)
find_package(TGUI 0.9 REQUIRED)
find_package(SFML 2.5 COMPONENTS system window graphics REQUIRED)

target_include_directories(
	"${PROJECT_NAME}" PUBLIC
	"${YAML_CPP_INCLUDE_DIR}"
	header
	)

target_link_directories(
	"${PROJECT_NAME}" PUBLIC

	)

target_link_libraries(
	"${PROJECT_NAME}"
	PRIVATE
	"${YAML_CPP_LIBRARIES}"
	sfml-graphics
	sfml-window
	sfml-system
	tgui
	fmt::fmt
	spdlog::spdlog
	)

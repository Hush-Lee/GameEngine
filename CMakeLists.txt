cmake_minimum_required(VERSION 3.30)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

project(engine-learning LANGUAGES CXX)

execute_process(
	COMMAND ${CMAKE_CXX_COMPILER} -print-file-name=libstdc++.modules.json
	OUTPUT_VARIABLE LIBSTDCXX_MODULES_JSON
	OUTPUT_STRIP_TRAILING_WHITESPACE
)
get_filename_component(LIBSTDCXX_MODULES_DIR "${LIBSTDCXX_MODULES_JSON}" DIRECTORY)
file(READ "${LIBSTDCXX_MODULES_JSON}" _std_modules_json)
string(REGEX MATCHALL "\"source-path\"[ \t]*:[ \t]*\"[^\"]+\"" _std_module_entries "${_std_modules_json}")

set(STD_MODULE_SOURCES "")
foreach(_entry IN LISTS _std_module_entries)
	string(REGEX REPLACE "\"source-path\"[ \t]*:[ \t]*\"([^\"]+)\"" "\\1" _src "${_entry}")
	get_filename_component(_abs "${LIBSTDCXX_MODULES_DIR}/${_src}" ABSOLUTE)
	list(APPEND STD_MODULE_SOURCES "${_abs}")
endforeach()

list(GET STD_MODULE_SOURCES 0 _std_first_src)
get_filename_component(STD_MODULES_BASE_DIR "${_std_first_src}" DIRECTORY)

add_library(std-modules STATIC)
target_sources(std-modules PUBLIC
	FILE_SET CXX_MODULES
	BASE_DIRS "${STD_MODULES_BASE_DIR}"
	FILES ${STD_MODULE_SOURCES}
)

add_subdirectory("engine")
add_subdirectory("sandbox")

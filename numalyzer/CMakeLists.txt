cmake_minimum_required(VERSION 3.16)

project(NumAlyzer
	VERSION
		0.0.1
	DESCRIPTION
		"A program that taskes a list of numbers from the user, sorts them in ascending order, and displays the smallest, largest, and average values."
	LANGUAGES
		C
	)

set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED ON)

## Source and Header Files for Front, Backend, and Testing
# Frontend Files
file(GLOB_RECURSE NUM_SOURCES
	"${CMAKE_SOURCE_DIR}/src/*.c"
)
file(GLOB_RECURSE NUM_HEADERS
	"${CMAKE_SOURCE_DIR}/include/*.h"
)

# Check & Test Files
file(GLOB_RECURSE TEST_SOURCES
	"${CMAKE_SOURCE_DIR}/tests/*.c"
)
file(GLOB_RECURSE TEST_HEADERS
	"${CMAKE_SOURCE_DIR}/tests/*.h"
)

set(ALL_C_FILES
	${NUM_SOURCES}
	${NUM_HEADERS}
	${TEST_SOURCES}
	${TEST_HEADERS}
)

# Separating the service from the library
# Frontend
add_executable(numalyzer
	${NUM_SOURCES}
	${NUM_HEADERS}
)
target_include_directories(numalyzer PRIVATE
	${NUM_HEADERS}
)
target_compile_options(numalyzer PRIVATE -Wall -Wextra -Werror)


# clang-format target
# Esures proper formatting of all code

find_program(CLANG_FORMAT_EXE NAMES clang-format)

if(CLANG_FORMAT_EXE AND ALL_C_FILES)
	add_custom_target(
		clang-format
		COMMAND ${CLANG_FORMAT_EXE} -i ${ALL_C_FILES}
		WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}
		COMMENT "Running clang-format on source files"
	)
else()
	message(STATUS "clang-format not found, 'clang-format' target will be skipped")
endif()

# doxygen target
# Ensures documentation is created on all code
find_package(Doxygen)

if(DOXYGEN_FOUND)
	add_custom_target(
		docs
		COMMAND ${DOXYGEN_EXECUTABLE} ${CMAKE_SOURCE_DIR}/Doxyfile
		WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}
		COMMENT "Generating Documentation with Dxygen"
		VERBATIM
	)
else()
	message(STATUS "Doxygen not found, 'docs' target willbe skipped")
endif()
# check target
# Ensures testing is performed
enable_testing()

if(TEST_SOURCES)
	add_executable(test_runner
		${TEST_SOURCES}
		${TEST_HEADERS}
	)

	target_include_directories(test_runner PRIVATE
		"${CMAKE_SOURCE_DIR}/include"
		"${CMAKE_SOURCE_DIR}/include"
	)

	target_link_libraries(test_runner PRIVATE hole_core)

	target_compile_options(test_runner PRIVATE
		-Wall -Wextra -Werror
	)

	add_test(NAME unit_tests COMMAND test_runner)

	add_custom_target(
		check
		COMMAND ${CMAKE_CTEST_COMMAND} --output-on-failure
		DEPENDS test_runner
		WORKING_DIRECTORY ${CMAKE_BINARY_DIR}
		COMMENT "Running unit tests (ctest)"
	)
else()
	message(STATUS "No tests found in tests/*.c. 'check' target will be skipped")
endif()

# rabbithole target
# Runs all targets
add_custom_target(numalyzer_all ALL
	COMMENT "Build all targets" 
)

add_dependencies(numalyzer)

if(TARGET clang-format)
	add_dependencies(numayzer clang-format)
endif()

if(TARGET docs)
	add_dependencies(numalyzer docs)
endif()

if(TARGET check)
	add_dependencies(numalyzer check)
endif()


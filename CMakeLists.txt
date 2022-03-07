cmake_minimum_required(VERSION 3.18)
project(chaac
	LANGUAGES C CXX ASM)

set_property(GLOBAL PROPERTY C_STANDARD 11)
set_property(GLOBAL PROPERTY CXX_STANDARD 17)

# If we're not a subproject, globally apply our warning flags
if(CMAKE_PROJECT_NAME STREQUAL PROJECT_NAME)
	add_compile_options(-Wall -Wextra)
endif()

# set the project name
project(CBORKVStore)

set(EXECUTABLE CBORKVStoreTest)

# add the executable
add_executable(${EXECUTABLE})

set(TINYCBOR_SRC_DIR tinycbor/src)

target_sources(${EXECUTABLE} PRIVATE
	${TINYCBOR_SRC_DIR}/cborencoder.c
	${TINYCBOR_SRC_DIR}/cborparser.c
	${TINYCBOR_SRC_DIR}/cborparser_float.c
	${TINYCBOR_SRC_DIR}/cborparser_dup_string.c
	${TINYCBOR_SRC_DIR}/cborerrorstrings.c
	main.c
)

target_include_directories(${EXECUTABLE} PRIVATE
	${TINYCBOR_SRC_DIR}
	)
cmake_minimum_required (VERSION 2.8)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set_property(GLOBAL PROPERTY USE_FOLDERS ON)

project (evpp C CXX)

if (UNIX)
    if(NOT CMAKE_BUILD_TYPE)
        set(CMAKE_BUILD_TYPE "Release")
    endif()

    set (CXX_FLAGS
         -g
         -fPIC
         -Wall
         -Wno-unused-parameter
         -Wno-unused-function
         -Wunused-variable
         -Wunused-value
         -Wshadow
         -Wcast-qual
         -Wcast-align
         -Wwrite-strings
         -Wsign-compare
         -Winvalid-pch
         -fms-extensions
         -Wfloat-equal
         -Wextra
         -std=c++11
    )
    include_directories(${LIBEVENT_DIR}/include)
    set(DEP_LIB_DIR ${LIBEVENT_LIB_DIR})

else (UNIX)
    set (CXX_FLAGS -DWIN32 -D_WIN32 -EHsc)
    set(DEP_LIB_DIR ${LIBEVENT_LIB_DIR})
    include_directories(${LIBEVENT_DIR}/include)
    include_directories(${LIBEVENT_DIR}/WIN32-code/nmake)
endif (UNIX)

link_directories(${DEP_LIB_DIR})

string (REPLACE ";" " " CMAKE_CXX_FLAGS "${CXX_FLAGS}")

if (UNIX)
    SET(CMAKE_CXX_FLAGS_DEBUG   "-O0 -g -ggdb -D_DEBUG")
    SET(CMAKE_CXX_FLAGS_RELEASE "-O3 -g -ggdb -DNDEBUG")
    SET(DEPENDENT_LIBRARIES event pthread)
else (UNIX)
    SET(DEPENDENT_LIBRARIES event)
endif (UNIX)

if (CMAKE_BENCHMARK_TESTING)
	SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -DH_BENCHMARK_TESTING=1")
endif (CMAKE_BENCHMARK_TESTING)

set (EXECUTABLE_OUTPUT_PATH ${PROJECT_BINARY_DIR}/bin)
set (LIBRARY_OUTPUT_PATH ${PROJECT_BINARY_DIR}/lib)

message (STATUS "This is DEP dir " ${DEP_LIB_DIR})
message (STATUS "This is BINARY dir " ${PROJECT_BINARY_DIR})
message (STATUS "This is SOURCE dir " ${PROJECT_SOURCE_DIR})
message (STATUS "CMAKE_CXX_FLAGS " ${CMAKE_CXX_FLAGS})
message (STATUS "EXECUTABLE_OUTPUT_PATH " ${EXECUTABLE_OUTPUT_PATH})
message (STATUS "LIBRARY_OUTPUT_PATH " ${LIBRARY_OUTPUT_PATH})

add_subdirectory (evpp)
#add_subdirectory (test)
#add_subdirectory (examples)
#add_subdirectory (benchmark)

#set (CMAKE_MODULE_PATH "${PROJECT_SOURCE_DIR}/cmake")

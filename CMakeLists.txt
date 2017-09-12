cmake_minimum_required(VERSION 3.0)

unset(BUILD_PLATFORM)
if(MINGW OR MSYS)
    message(STATUS "MinGW or MSYS build")
    set(BUILD_PLATFORM msys_mingw)
elseif(MSVC)
    message(STATUS "Microsoft Visual Studio build")
    set(BUILD_PLATFORM msvc)
else()
    message(STATUS "Linux build")
    set(BUILD_PLATFORM linux)
endif()

set(SYSROOT_LOCATION "3rdparty" CACHE STRING "Select a system root location")
set_property(CACHE SYSROOT_LOCATION PROPERTY STRINGS "3rdparty" "binary_dir")

if(SYSROOT_LOCATION STREQUAL "3rdparty")
    set(SYSROOT ${CMAKE_SOURCE_DIR}/3rdparty/sysroot-${BUILD_PLATFORM})
elseif(SYSROOT_LOCATION STREQUAL "binary_dir")
    set(SYSROOT ${CMAKE_BINARY_DIR}/sysroot-${BUILD_PLATFORM})
else()
    message(FATAL_ERROR "invalid system root location choise")
endif()

set(3RDPARTY_INSTALL ${SYSROOT})

add_subdirectory(3rdparty)


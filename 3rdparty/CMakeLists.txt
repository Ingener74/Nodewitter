cmake_minimum_required(VERSION 3.0)

include(ExternalProject)

option(ENABLE_DEPEND_BOOST "Enable boost dependency" ON)
if(ENABLE_DEPEND_BOOST)
    add_subdirectory(boost)
endif()

option(ENABLE_DEPEND_HGE "Enable HGE dependency" ON)
if(ENABLE_DEPEND_HGE)
    add_subdirectory(HGE)
endif()


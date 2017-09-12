cmake_minimum_required(VERSION 2.8.11)

set(EXT_HGE ext_hge)

ExternalProject_Add(
        ${EXT_HGE}
        URL                 https://downloads.sourceforge.net/project/hge/hge/hge-1.6/hge16.zip
        BINARY_DIR          ${CMAKE_BINARY_DIR}/3rdparty/HGE/${EXT_HGE}-prefix/src/${EXT_HGE}
        CONFIGURE_COMMAND   "" # ${CMAKE_BINARY_DIR}/3rdparty/HGE/${EXT_HGE}-prefix/src/${EXT_HGE}/bootstrap.sh
        BUILD_COMMAND       "" # ${CMAKE_BINARY_DIR}/3rdparty/HGE/${EXT_HGE}-prefix/src/${EXT_HGE}/b2 install variant=release link=static threading=multi --with-system --with-filesystem --with-program_options --prefix=${3RDPARTY_INSTALL} -d0
        INSTALL_COMMAND     ""
)

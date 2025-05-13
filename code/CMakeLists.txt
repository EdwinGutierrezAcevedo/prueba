cmake_minimum_required(VERSION 3.16)

project(code LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(code main.cpp
    administrador.h administrador.cpp
    usuario.h usuario.cpp
    banco.h banco.cpp)

include(GNUInstallDirs)
install(TARGETS code
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)

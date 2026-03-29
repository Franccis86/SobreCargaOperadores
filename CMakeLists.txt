cmake_minimum_required(VERSION 4.2)
project(Sobre_Carga_Operadores)

set(CMAKE_CXX_STANDARD 20)
add_library(SobreCargaOperadores STATIC Librerias/SobreCargaOperadores.cpp)
add_executable(Sobre_Carga_Operadores main.cpp
        Librerias/Utils.h
        Librerias/Funciones.cpp
        Librerias/Funciones.h
        Librerias/SobreCargaOperadores.cpp
        Librerias/SobreCargaOperadores.hpp)
target_link_libraries(Sobre_Carga_Operadores SobreCargaOperadores)
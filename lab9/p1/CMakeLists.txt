cmake_minimum_required(VERSION 3.17)
project(lab9)

set(CMAKE_CXX_STANDARD 14)

add_executable(lab9p1 main.cpp
        Ambulatorio.cpp
        Ambulatorio.h
        Paciente.cpp
        Paciente.h
        Emergencia.cpp
        Emergencia.h
        Urgencia.cpp
        Urgencia.h)
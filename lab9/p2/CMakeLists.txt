cmake_minimum_required(VERSION 3.17)
project(lab9)

set(CMAKE_CXX_STANDARD 14)

add_executable(lab9p2
        main.cpp
        ListaDePacientes.cpp
        ListaDePacientes.h
        NodoPaciente.cpp
        NodoPaciente.h
        Ambulatorio.cpp
        Ambulatorio.h
        Paciente.cpp
        Paciente.h
        Emergencia.cpp
        Emergencia.h
        Urgencia.cpp
        Urgencia.h)
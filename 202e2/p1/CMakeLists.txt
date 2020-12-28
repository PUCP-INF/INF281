cmake_minimum_required(VERSION 3.17)
project(202e2)

set(CMAKE_CXX_STANDARD 14)

add_executable(202e2 main.cpp
        Ambulatorio.cpp
        Ambulatorio.h
        Paciente.cpp
        Paciente.h
        Emergencia.cpp
        Emergencia.h
        Urgencia.cpp
        Urgencia.h NPaciente.cpp NPaciente.h Procesa.cpp Procesa.h)
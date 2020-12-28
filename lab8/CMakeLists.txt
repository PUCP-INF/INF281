cmake_minimum_required(VERSION 3.17)
project(lab8)

set(CMAKE_CXX_STANDARD 14)

add_executable(lab8 main.cpp Paciente.cpp Paciente.hpp Ambulatorio.cpp Ambulatorio.h Urgencia.cpp Urgencia.h Emergencia.cpp Emergencia.h ListaDePacientes.cpp ListaDePacientes.h)
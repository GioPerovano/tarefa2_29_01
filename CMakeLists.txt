cmake_minimum_required(VERSION 3.13)
include(pico_sdk_import.cmake)

project(Pico_Timers C CXX ASM)
set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)

pico_sdk_init()

# Adiciona Atividade 1 (Semáforo)
add_executable(atividade1
    Atividade_1/main.c
)
target_link_libraries(atividade1 pico_stdlib hardware_gpio hardware_timer)
pico_add_extra_outputs(atividade1)

# Adiciona Atividade 2 (One Shot)
add_executable(atividade2
    Atividade_2/main.c
)
target_link_libraries(atividade2 pico_stdlib hardware_gpio hardware_timer)
pico_add_extra_outputs(atividade2)

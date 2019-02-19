cmake_minimum_required(VERSION 3.13)
project(ProvaConListe C)

set(CMAKE_C_STANDARD 99)

add_executable(ProvaConListe main.c leggi_file.c lista.c scheduler_not_preemptive.c hrrn.c not_preemptive.c scheduler_preemptive.c preemptive.c srt.c stampa.c)
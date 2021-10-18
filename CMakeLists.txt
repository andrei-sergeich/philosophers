cmake_minimum_required(VERSION 3.19)
project(philosophers C)

set(CMAKE_C_STANDARD 99)
set(CMAKE_DL_LIBS -lpthread)

FILE(GLOB PHILO "philo/*.*")

add_executable(philo ${PHILO})

target_link_libraries(philo ${CMAKE_DL_LIBS})
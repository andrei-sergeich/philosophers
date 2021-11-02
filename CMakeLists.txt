cmake_minimum_required(VERSION 3.19)
project(philosophers C)

set(CMAKE_C_STANDARD 99)
set(CMAKE_DL_LIBS -lpthread)

FILE(GLOB PHILO "philo/srcs/*.*")
FILE(GLOB PHILO_BONUS "philo_bonus/srcs/*.*")

include_directories(philo/include)
include_directories(philophilo_bonus/include)

add_executable(philo ${PHILO})
add_executable(philo_bonus ${PHILO_BONUS})

target_link_libraries(philo ${CMAKE_DL_LIBS})
target_link_libraries(philo_bonus ${CMAKE_DL_LIBS})
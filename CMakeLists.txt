cmake_minimum_required(VERSION 3.16)

# Ustal nazwę projektu
project(main)

# Ustaw standard C++
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Dodaj wszystkie pliki źródłowe do projektu
add_executable(main main/main.cpp drivers/src/wifi_driver.cpp)

# Dodaj katalogi z plikami nagłówkowymi
target_include_directories(main PRIVATE drivers/incl)
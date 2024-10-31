file(GLOB SRCS "main.cpp" "../drivers/src/*.cpp")

idf_component_register(SRCS "${SRCS}"
                       INCLUDE_DIRS "../drivers/incl")

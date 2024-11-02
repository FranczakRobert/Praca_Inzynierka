file(GLOB SRCS "src/*.cpp")

idf_component_register(SRCS "${SRCS}"
                    INCLUDE_DIRS "incl")
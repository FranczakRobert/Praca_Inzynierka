file(GLOB SRCS "src/*.cpp")

idf_component_register(SRCS "${SRCS}" "../drivers/src/led_driver.cpp"
                    INCLUDE_DIRS "incl" "../drivers/incl")
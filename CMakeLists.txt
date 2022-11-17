add_library(hagl_galactic INTERFACE)

include(pimoroni_pico_import.cmake)
include(../pimoroni-pico/libraries/pico_graphics/pico_graphics.cmake)
include(../pimoroni-pico/libraries/galactic_unicorn/galactic_unicorn.cmake)
include(../pimoroni-pico/libraries/bitmap_fonts/bitmap_fonts.cmake)
include(../pimoroni-pico/libraries/hershey_fonts/hershey_fonts.cmake)

target_sources(hagl_galactic INTERFACE
        ${CMAKE_CURRENT_LIST_DIR}/galactic_hagl.cpp
        include/hagl_hal.h
        include/hagl_hal_color.h
        )

target_include_directories(hagl_galactic INTERFACE ${CMAKE_CURRENT_LIST_DIR}/include ${PIMORONI_PICO_PATH})

target_link_libraries(hagl_galactic INTERFACE hardware_pio hardware_adc hardware_dma pico_graphics galactic_unicorn hagl)

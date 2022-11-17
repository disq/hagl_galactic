add_library(hagl_hal INTERFACE)

include(pimoroni_pico_import.cmake)
include(${PIMORONI_PICO_PATH}/libraries/pico_graphics/pico_graphics.cmake)
include(${PIMORONI_PICO_PATH}/libraries/galactic_unicorn/galactic_unicorn.cmake)
include(${PIMORONI_PICO_PATH}/libraries/bitmap_fonts/bitmap_fonts.cmake)
include(${PIMORONI_PICO_PATH}/libraries/hershey_fonts/hershey_fonts.cmake)

target_sources(hagl_hal INTERFACE
        ${CMAKE_CURRENT_LIST_DIR}/galactic_hagl.cpp
        include/hagl_hal.h
        include/hagl_hal_color.h
        )

target_include_directories(hagl_hal INTERFACE ${CMAKE_CURRENT_LIST_DIR}/include ${PIMORONI_PICO_PATH})

target_link_libraries(hagl_hal INTERFACE hardware_pio hardware_adc hardware_dma pico_graphics galactic_unicorn hagl)

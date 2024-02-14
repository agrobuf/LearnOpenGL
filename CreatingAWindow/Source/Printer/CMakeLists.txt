project(Printer)

# Set the project name
add_library(Printer STATIC)

target_include_directories(Printer
    PUBLIC
        $<BUILD_INTERFACE:${CMAKE_CURRENT_LIST_DIR}/Include>
    PRIVATE
        ${CMAKE_CURRENT_LIST_DIR}/Src
)

target_sources(Printer
    PRIVATE
        ${CMAKE_CURRENT_LIST_DIR}/Src/Printer/printer.cpp
)

target_link_libraries(Printer

)

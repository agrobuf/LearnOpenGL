project(glad)

# Set the project name
add_library(glad)

target_include_directories(glad
    PUBLIC
        $<BUILD_INTERFACE:${CMAKE_CURRENT_LIST_DIR}/Include>
    PRIVATE
        ${CMAKE_CURRENT_LIST_DIR}/Src
)

target_sources(glad
    PRIVATE
        ${CMAKE_CURRENT_LIST_DIR}/Src/glad/glad.c
)

target_link_libraries(glad

)

set(SOURCES
    vector.cpp
)

add_library(VECTOR ${SOURCES})

target_include_directories(VECTOR PUBLIC ${CMAKE_SOURCE_DIR}/include)

add_executable(Exec main.cpp)
target_link_libraries(Exec PRIVATE VECTOR)
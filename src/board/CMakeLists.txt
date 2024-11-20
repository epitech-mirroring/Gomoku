add_subdirectory(brains)

target_sources(GomokuAI
        PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/board.hpp
        PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}/board.cpp
)
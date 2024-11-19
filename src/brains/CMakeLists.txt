target_sources(GomokuAI
        PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/ABrain.hpp
        ${CMAKE_CURRENT_SOURCE_DIR}/DumbBrain.hpp
        PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}/ABrain.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/DumbBrain.cpp
)
add_subdirectory(board)
add_subdirectory(brains)
add_subdirectory(playAnalysis)

target_sources(pbrain-gomoku-ai
        PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/Communication.hpp
        ${CMAKE_CURRENT_SOURCE_DIR}/ICommunication.hpp
        PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}/Communication.cpp
)
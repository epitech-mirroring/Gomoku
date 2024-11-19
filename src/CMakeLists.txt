add_subdirectory(brains)

target_sources(GomokuAI
        PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/Communication.hpp
        ${CMAKE_CURRENT_SOURCE_DIR}/ICommunication.hpp
        PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}/Communication.cpp
)
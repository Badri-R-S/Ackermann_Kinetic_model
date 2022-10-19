add_executable(shell-app main.cpp simulation.cpp userInput.cpp robot.cpp controller.cpp)
include_directories(
    ${CMAKE_SOURCE_DIR}/include
)
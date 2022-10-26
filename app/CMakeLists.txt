add_executable(shell-app main.cpp data_reader.cpp modelConfig.cpp Human_detector.cpp track.cpp transformation.cpp)
include_directories(
    ${CMAKE_SOURCE_DIR}/include ${OpenCV_INCLUDE_DIRS}
)
find_package( OpenCV REQUIRED)
target_link_libraries( shell-app ${OpenCV_LIBS} )
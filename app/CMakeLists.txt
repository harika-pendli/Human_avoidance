add_executable(shell-app main.cpp data_reader.cpp detect.cpp camera.cpp Human_detector.cpp track.cpp)
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} ${CMAKE_CURRENT_SOURCE_DIR}/cmake-modules)
include_directories(
    ${CMAKE_SOURCE_DIR}/include ${OpenCV_INCLUDE_DIRS}
)
find_package( OpenCV REQUIRED)
target_link_libraries( shell-app ${OpenCV_LIBS} )
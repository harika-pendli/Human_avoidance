set(GTEST_SHUFFLE 1)

find_package( OpenCV REQUIRED )

add_executable(cpp-test
    main.cpp
    detect_test.cpp
    track_test.cpp
    human_detect_test.cpp
    camera_test.cpp
    # test_data_read.cpp
    ../app/detect.cpp ../app/track.cpp ../app/Human_detector.cpp ../app/camera.cpp
    # ../app/data_reader.cpp
)

target_include_directories(cpp-test PUBLIC ../vendor/googletest/googletest/include 
                                           ${CMAKE_SOURCE_DIR}/include 
                                           ${OpenCV_INCLUDE_DIRS})

target_link_libraries(cpp-test PUBLIC gtest)
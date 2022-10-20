set(GTEST_SHUFFLE 1)

find_package( OpenCV REQUIRED )

add_executable(data-test
    main.cpp
    detect_test.cpp
    track_test.cpp
    human_detect_test.cpp
    ../app/detect.cpp ../app/track.cpp ../app/human_detector.cpp
)

target_include_directories(data-test PUBLIC ../vendor/googletest/googletest/include 
                                           ${CMAKE_SOURCE_DIR}/include 
                                           ${OpenCV_INCLUDE_DIRS})

target_link_libraries(data-test PUBLIC gtest)
set(GTEST_SHUFFLE 1)

find_package( OpenCV REQUIRED )

add_executable(cpp-test
    main.cpp
    # track_test.cpp
    human_detect_test.cpp
    data_read_test.cpp
    transformation_test.cpp
    modelConfig_test.cpp
    ../app/transformation.cpp ../app/track.cpp 
    ../app/Human_detector.cpp ../app/modelConfig.cpp
    ../app/data_reader.cpp 
    # ../app/track.cpp
)

target_include_directories(cpp-test PUBLIC ../vendor/googletest/googletest/include 
                                           ${CMAKE_SOURCE_DIR}/include 
                                           ${OpenCV_INCLUDE_DIRS})

target_link_libraries(cpp-test PUBLIC gtest ${OpenCV_LIBS})
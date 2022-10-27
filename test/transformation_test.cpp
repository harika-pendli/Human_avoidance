
/**
 * @file transformation_test.cpp
 * @author Shailesh Pranav Rajendran (spraj@umd.edu)
 * @brief 
 * @version 0.1
 * @date 2022-10-27
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include <gtest/gtest.h>
#include <vector>
# include <opencv2/opencv.hpp>

#include <../include/transformation.hpp>
Transform t;
TEST(TestSetGet, test_dist) {
    int box_h = 10;
    int frame_h = 15;
    EXPECT_EQ(t.calculate_distance(box_h, frame_h), 1.75);
}

TEST(TestSetGet, test_frame) {
    float z = 1.75;
    cv::Rect box;
    box = cv::Rect(10, 20, 15, 15);
    cv::Mat frame = cv::imread("../input/1.png");
    EXPECT_NO_FATAL_FAILURE(t.camera_robot_array(z, box, frame));
}


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

#include <../include/transformation.hpp>
Transform t;
TEST(TestSetGet, test_dist) {
    int box_h = 10;
    int frame_h = 15;
    EXPECT_EQ(t.calculate_distance(box_h, frame_h),1.75);
}

TEST(TestSetGet, test_frame) {
    float z = 1.75;
    cv::Rect box;
    cv::Mat frame;
    EXPECT_NO_FATAL_FAILURE(t.camera_robot_array(z, box,frame));
}
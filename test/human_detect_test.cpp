/**
 * @file test_human_detect.cpp
 * @author Shailesh Pranav Rajendran (spraj@umd.edu) and Harika Pendli
 * (hpendli@umd.edu)
 * @brief Test file for human_detect class
 * @version 0.1
 * @date 2022-10-19
 *
 * @copyright MIT License (c) 2022 Shailesh Pranav Rajendran and Harika Pendli
 *
 */
#include <gtest/gtest.h>

#include <vector>
#include <opencv2/opencv.hpp>
#include <../include/Human_detector.hpp>

HumanDetector ins;
const char* keys =
    "{image img||input image}"
    "{video vid||input video}";
int argc = 0;
const char* argv = "";
TEST(Driver, detect) {
  cv::CommandLineParser parser(argc, &argv, keys);
  EXPECT_NO_FATAL_FAILURE(ins.detect(parser));
}


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
const char* keys_img =
    "{image img|../input/1.png|input image}"
    "{video vid|<none>|input video}";
int argc = 0;
const char* argv = "";

TEST(Driver, detect_image) {
  cv::CommandLineParser parser(argc, &argv, keys_img);
  EXPECT_NO_FATAL_FAILURE(ins.detect(parser));
}

const char* keys_vid =
    "{image img|<none>|input image}"
    "{video vid|../input/video.mp4|input video}";

TEST(Driver, detect_video) {
  cv::CommandLineParser parser(argc, &argv, keys_vid);
  EXPECT_NO_FATAL_FAILURE(ins.detect(parser));
}

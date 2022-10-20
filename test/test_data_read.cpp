/**
 * @file test.cpp
 * @author Shailesh Pranav Rajendran (spraj@umd.edu) and Harika Pendli
 * (hpendli@umd.edu)
 * @brief Test file for data reader class
 * @version 0.1
 * @date 2022-10-19
 *
 * @copyright MIT License (c) 2022 Shailesh Pranav Rajendran and Harika Pendli
 *
 */
#include <gtest/gtest.h>

#include <string>
// #include <opencv2/opencv.hpp>
#include <../include/data_reader.hpp>

TEST(TestSetGet, testgetimgpath) {
  DataReader data;
  std::string st = "test";
  data.setImagepath(&st);
  EXPECT_EQ(data.getImagepath(), st);
}

TEST(TestSetGet, testgetvideopath) {
  DataReader data;
  std::string st = "test";
  data.setVideopath(st);
  EXPECT_EQ(data.getVideopath(), st);
}

TEST(testProcessor, testImgProcessor) {
  DataReader data;
  cv::Mat frame = cv::imread("1.png");
  EXPECT_NO_FATAL_FAILURE(data.imgprocessor(frame));
}

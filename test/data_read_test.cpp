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
#include <opencv2/opencv.hpp>
#include <../include/data_reader.hpp>

TEST(TestSetGet, test_output_height) {
  DataReader data;
  int test = 640;
  data.setOutputHeight(test);
  EXPECT_EQ(data.getOutputHeight(), test);
}

TEST(TestSetGet, test_output_width) {
  DataReader data;
  int test = 640;
  data.setOutputWidth(test);
  EXPECT_EQ(data.getOutputWidth(), test);
}

TEST(TestSetGet, testgetimgpath) {
  DataReader data;
  std::string st = "test_img";
  data.setImagepath(st);
  EXPECT_EQ(data.getImagepath(), st);
}

TEST(TestSetGet, testgetvideopath) {
  DataReader data;
  std::string st = "test_video";
  data.setVideopath(st);
  EXPECT_EQ(data.getVideopath(), st);
}

TEST(TestSetGet, test_Input) {
  DataReader data;
  const char* keys =
      "{image img|test_image|input image}"
      "{video vid|<none>>|input video}";
  int argc = 0;
  const char* argv = "";
  std::string inp = "";
  cv::CommandLineParser parser(argc, &argv, keys);
  EXPECT_EQ(data.getInput(parser, inp), "test_image");
}

TEST(TestSetGet, test_video_input) {
  DataReader data;
  const char* keys =
      "{image img|<none>| input image}"
      "{video vid|test_video|input video}";
  int argc = 0;
  const char* argv = "";
  std::string inp = "";
  cv::CommandLineParser parse(argc, &argv, keys);
  EXPECT_EQ(data.getInput(parse, inp), "test_video");
}

TEST(testProcessor, testImgProcessor) {
  DataReader data;
  data.setImagepath("../input/1.png");
  cv::Mat frame = cv::imread("../input/1.png");
  EXPECT_NO_FATAL_FAILURE(data.imgProcessor('r', frame));
  EXPECT_NO_FATAL_FAILURE(data.imgProcessor('w', frame));
  EXPECT_NO_FATAL_FAILURE(data.imgProcessor('x', frame));
}

TEST(testProcessor, testVideoProcessor) {
  DataReader data;
  data.setVideopath("../input/video.mp4");
  cv::Mat frame = cv::imread("../input/1.png");
  cv::VideoWriter video;
  data.setOutputHeight(480);
  data.setOutputWidth(640);
  EXPECT_NO_FATAL_FAILURE(data.videoProcessor('r', frame, video));
  EXPECT_NO_FATAL_FAILURE(data.videoProcessor('w', frame, video));
  EXPECT_NO_FATAL_FAILURE(data.videoProcessor('q', frame, video));
}

#include <gtest/gtest.h>
#include <string>
#include <../include/data_reader.hpp>
// #include <opencv2/opencv.hpp>

DataReader data;
int test = 123;
std::string st = "test";

TEST(TestSetGet, testgetimgpath){
  data.setImagepath(st);
  EXPECT_EQ(data.getImagepath(),st);
}

TEST(TestSetGet, testgetvideopath){
  data.setVideopath(st);
  EXPECT_EQ(data.getVideopath(),st);
}

TEST(testProcessor, testImgProcessor) {
  cv::Mat frame = cv::imread("1.png");
  EXPECT_NO_FATAL_FAILURE(data.imgprocessor(frame));
}


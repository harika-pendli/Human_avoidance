/**
 * @file test_human_detect.cpp
 * @author Shailesh Pranav Rajendran (spraj@umd.edu)
 * @brief
 * @version 0.1
 * @date 2022-10-19
 *
 * @copyright Copyright (c) 2022
 *
 */
#include <gtest/gtest.h>

#include <../include/Human_detector.hpp>
#include <vector>

HumanDetector ins;

TEST(Driver, coord_trans) {
  std::vector<std::vector<float>> out;
  std::vector<float> in_1;
  in_1.push_back(1.11);
  in_1.push_back(1.22);
  out.push_back(in_1);
  std::vector<std::vector<float>> a;

  EXPECT_EQ(ins.camera_robot_array(a), out);
}

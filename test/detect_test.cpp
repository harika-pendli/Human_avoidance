/**
 * @file detect_test.cpp
 * @author Shailesh Pranav Rajendran (spraj@umd.edu)
 * @brief
 * @version 0.1
 * @date 2022-10-19
 *
 * @copyright Copyright (c) 2022
 *
 */

#include <gtest/gtest.h>

#include <vector>
#include <../include/detect.hpp>

TEST(Detectingtest, detections) {
  Detector detect;
  std::vector<std::array<float, 4>> vec, res;
  std::array<float, 4> arr{0, 1, 2, 99.99};
  vec.push_back(arr);
  res = detect.detecting();
  EXPECT_TRUE(res == vec);
}

TEST(Detectingtest, filter) {
  Detector detect;
  std::vector<std::array<float, 3>> vec, res;
  std::array<float, 3> arr{0, 1, 2};
  vec.push_back(arr);
  res = detect.filter();
  EXPECT_TRUE(res == vec);
}

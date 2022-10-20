/**
 * @file track_test.cpp
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
#include <../include/track.hpp>

Tracker tracking;

TEST(Trackingtest, id) {
  std::vector<float> a{1.1};
  EXPECT_EQ(tracking.assign_id(a), 1);
}

TEST(Trackingtest, tracking) {
  std::vector<float> vec, res;
  res.push_back(1.11);
  res.push_back(1.21);
  EXPECT_EQ(tracking.track(vec), res);
}

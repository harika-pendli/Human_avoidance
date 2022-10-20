/**
 * @file track.cpp
 * @author Harika Pendli (hpendli@umd.edu) and Shailesh Pranav Rajendran
 * (spraj@umd.edu)
 * @brief Tracking class
 * @version 0.1
 * @date 2022-10-11
 *
 * @copyright MIT License (c) 2022 Shailesh Pranav Rajendran and Harika Pendli
 *
 */
#ifndef INCLUDE_TRACK_HPP_
#define INCLUDE_TRACK_HPP_

#include <array>
#include <iostream>
#include <string>
#include <vector>

/**
 * @brief class that tracks the objects from all frames of the video feed
 *
 */

class Tracker {
 private:
  int SIZE;
  int object_id;

 public:
  Tracker();
  int assign_id(std::vector<float>&);
  int frame_id;
  std::vector<float> track(std::vector<float>&);
};
#endif  // INCLUDE_TRACK_HPP_

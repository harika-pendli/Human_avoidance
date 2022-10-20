/**
 * @file track.hpp
 * @author Harika Pendli (hpendli@umd.edu) and Shailesh Pranav Rajendran
 * (spraj@umd.edu)
 * @brief Tracking class
 * @version 0.1
 * @date 2022-10-11
 *
 * @copyright MIT License (c) 2022 Shailesh Pranav Rajendran and Harika Pendli
 *
 */

#include "../include/track.hpp"

#include <array>
#include <iostream>
#include <string>
#include <vector>

Tracker::Tracker() {
  SIZE = 0;
  object_id = 0;
  frame_id = 0;
}
/**
 * @brief class that tracks the objects from all frames of the video feed
 *
 */

/**
 * @brief assigns id to track to that particular human instance
 *
 * @param human_instance a vector with (temp_id, x,y)
 * @return int with a specific id if the object was seen in previous frame else
 * assigned new id
 */

int Tracker::assign_id(std::vector<float> &human_instance) {
  // stub
  return 1;
}

/**
 * @brief keeps a record of all the coordinates of the same human_instance
 *
 * @param track_id_instance
 * @return std::vector<float>
 */
std::vector<float> Tracker::track(std::vector<float> &track_id_instance) {
  // stub
  std::vector<float> vec;
  vec.push_back(1.11);
  vec.push_back(1.21);
  return vec;
}

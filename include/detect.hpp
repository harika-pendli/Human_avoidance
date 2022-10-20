/**
 * @file detect.hpp
 * @author Harika Pendli (hpendli@umd.edu) and Shailesh Pranav Rajendran
 * (spraj@umd.edu)
 * @brief Detection class
 * @version 0.1
 * @date 2022-10-11
 *
 * @copyright MIT License (c) 2022 Shailesh Pranav Rajendran and Harika Pendli
 *
 */

// TO DO:

#ifndef INCLUDE_DETECT_HPP_
#define INCLUDE_DETECT_HPP_

#include <array>
#include <iostream>
#include <string>
#include <vector>

/**
 * @brief class that will contain implementation of the detection process for
 * each frame
 *
 */
class Detector {
 private:
  int num_humans;  // Total confident human objects detected

 public:
  Detector();
  std::vector<std::array<float, 4>>
  detecting();  // function that takes a frame and detects
  std::vector<std::array<float, 3>>
  filter();  // function that returns list of humans above certain confidence
             // level
};
#endif  // INCLUDE_DETECT_HPP_

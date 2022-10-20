/**
 * @file Human_detector.hpp
 * @author Harika Pendli (hpendli@umd.edu) and Shailesh Pranav Rajendran
 * (spraj@umd.edu)
 * @brief Driver class for the project
 * @version 0.1
 * @date 2022-10-18
 *
 * @copyright MIT License (c) 2022 Shailesh Pranav Rajendran and Harika Pendli
 *
 */
#ifndef INCLUDE_HUMAN_DETECTOR_HPP_
#define INCLUDE_HUMAN_DETECTOR_HPP_

#include <array>
#include <iostream>
#include <string>
#include <vector>

#include "../include/camera.hpp"
#include "../include/detect.hpp"
#include "../include/track.hpp"

/**
 * @brief This class will be the driver class for the project
 * 
 */
class HumanDetector {
  // private:
  // camera Camera;
  // detect Detector;
  // track Tracker;

 public:
  void initialise();
  std::vector<std::vector<float>> camera_robot_array(
      std::vector<std::vector<float>>);  // returns transformed coordinates and
                                         // distance of humans
};
#endif  // INCLUDE_HUMAN_DETECTOR_HPP_

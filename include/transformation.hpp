/**
 * @file transormation.hpp
 * @author  Harika Pendli (hpendli@umd.edu) and Shailesh Pranav Rajendran (spraj@umd.edu)
 * @brief Class for finding distance in z-axis and frame transformation
 * @version 0.1
 * @date 2022-10-26
 *
 * @copyright MIT License (c) 2022 Shailesh Pranav Rajendran and Harika Pendli
 *
 */

#ifndef INCLUDE_TRANSFORMATION_HPP_
#define INCLUDE_TRANSFORMATION_HPP_

#include <iostream>
#include <string>
#include <vector>
#include <opencv2/opencv.hpp>

class Transform {
 private:
  /**
   * @brief private variable for assumed height of a person
   *
   */
  unsigned int averageHeight;

 public:
  /**
   * @brief Constructor for Transform class
   *
   */
  Transform();
  /**
   * @brief Function to calculate the distance of the person
   * from the camera
   *
   * @return int distance from camera
   */
  float calculate_distance(int, int);

  /**
   * @brief Method for frame transformation from camera to robot frame
   *
   */
  void camera_robot_array(float, cv::Rect, cv::Mat);

  ~Transform();
};

#endif  // INCLUDE_TRANSFORMATION_HPP_

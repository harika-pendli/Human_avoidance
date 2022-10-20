/**
 * @file camera.hpp
 * @author Shailesh Pranav Rajendran (spraj@umd.edu)
 * @brief Camera class
 * @version 0.1
 * @date 2022-10-11
 *
 * @copyright MIT License (c) 2022 Shailesh Pranav Rajendran and Harika Pendli
 *
 */
#ifndef INCLUDE_CAMERA_HPP_
#define INCLUDE_CAMERA_HPP_

// TO DO :
// might need to replace arrays with eigen matrices
// find correct way to include opencv library
// add a function to start inputing frames or video  get_image()
//  i am not sure how to declare

#include <array>
#include <iostream>
#include <string>
#include <vector>
// #include<Eigen/Dense> //find correct way to include eigen library
// #include <opencv2/opencv.hpp> //find correct way to include opencv library

/**
 * @brief  Class to store camera parameters and to decode video and send frames
 *
 */
class Camera {
 private:
  std::array<float, 4> camera_parameters_intrinsic;
  std::array<float, 9> camera_parameters_rotation;
  std::array<float, 3> camera_parameters_translation;

 public:
  void set_intrinsic_camera_params(
      float, float, float, float,
      float);  // supposed to be the intrinsic matrix of the camera
  void set_rotation_camera_params(
      float, float, float, float, float, float, float, float,
      float);  // supposed to be rotation part of the extrinsic params matrix
  void set_translation_camera_params(
      float, float, float);  // translation part of the extrinsic params matrix

  // add a function to start inputing frames or video  get_image()
  //  i am not sure how to declare
};
#endif  // INCLUDE_CAMERA_HPP_

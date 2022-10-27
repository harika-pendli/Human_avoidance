/**
 * @file transformation.cpp
 * @author Shailesh Pranav Rajendran (spraj@umd.edu)
 * @brief
 * @version 0.1
 * @date 2022-10-26
 *
 * @copyright Copyright (c) 2022
 *
 */

#include <../include/transformation.hpp>

Transform::Transform() { averageHeight = 175; }

float Transform::calculate_distance(int box_h, int frame_h) {
  int focal_l = 16;
  int sensor_h = 25;
  // Conversion from pixels to milli-meter
  double height_mm = (sensor_h * box_h) / frame_h;
  // Calcuation to find distance of human from camera
  // D = (H * F) / P
  double z = (averageHeight * focal_l) / height_mm;
  return (z / 100);
}

/**
 * @brief transforms the detected human coordinates into robot coordinate system
 * and displays
 *
 * @return std::vector<std::vector<float>>
 */
void Transform::camera_robot_array(float z, cv::Rect box, cv::Mat frame) {
  std::vector<double> pos;
  int sensor_w = 24;
  int sensor_h = 35;
  double res = 0;
  double x =
      (sensor_w * ((box.x + box.width / 2) - (frame.cols / 2))) / frame.rows;
  double y =
      (sensor_h * ((box.y + box.height / 2) - (frame.rows / 2))) / frame.cols;
  std::vector<float> out;
  pos.push_back(x);
  pos.push_back(y);
  pos.push_back(z);
  pos.push_back(1.0);
  std::vector<std::vector<double>> T = {
      {1, 0, 0, 1}, {0, 1, 0, 1}, {0, 0, 1, -2}, {0, 0, 0, 1}};
  for (int i = 0; i <= 3; i++) {
    for (int j = 0; j <= 3; j++) {
      res += T[i][j] * pos[j];
    }
    out.push_back(res);
    res = 0;
  }
  out.pop_back();
}  // returns transformed coordinates and distance of humans

Transform::~Transform() {}

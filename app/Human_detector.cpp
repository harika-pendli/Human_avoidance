/**
 * @file Human_detector.hpp
 * @author Harika Pendli (hpendli@umd.edu) and Shailesh Pranav Rajendran
 * (spraj@umd.edu)
 * @brief Driver class for all classes
 * @version 0.1
 * @date 2022-10-18
 *
 * @copyright MIT License (c) 2022 Shailesh Pranav Rajendran and Harika Pendli
 *
 */

#include "../include/Human_detector.hpp"

/**
 * @brief Constructor for Human Detector class
 * 
 */
HumanDetector::HumanDetector() {
  inputHeight = 640;
  inputWidth = 640;
  nmsThreshold = 0.4;
  confidenceThreshold = 0.75;
  averageHeight = 175;
}

void HumanDetector::detect(cv::CommandLineParse parse)
{
  
  std::vector<std::string> classes;

  ModelConfig yolov3;
  classes = yolov3.getClasses();
  
  cv::dnn::Net net = cv::dnn::readNetFromDarknet(yolov3.getConfig(), yolov3.getWeights(),  
        net.setPreferableBackend(cv::dnn::DNN_BACKEND_OPENCV);
        net.setPreferableTarget(cv::dnn::DNN_TARGET_CPU);

  cv::VideoCapture cap;
  cv::Mat frame,blob;
}

/**
 * @brief transforms the detected human coordinates into robot coordinate system
 * and displays
 *
 * @return std::vector<std::vector<float>>
 */
std::vector<std::vector<float>> HumanDetector::camera_robot_array(
    std::vector<std::vector<float>>) {
  // stub
  std::vector<std::vector<float>> out;
  std::vector<float> in_1;
  in_1.push_back(1.11);
  in_1.push_back(1.22);
  out.push_back(in_1);
  return out;
}  // returns transformed coordinates and distance of humans

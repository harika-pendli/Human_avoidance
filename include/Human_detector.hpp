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
#include <opencv2/opencv.hpp>

#include "../include/data_reader.hpp"
#include "../include/modelConfig.hpp"
#include "../include/track.hpp"
#include "../include/transformation.hpp"

/**
 * @brief This class will be the driver class for the project
 *
 */
class HumanDetector {
 private:
  /**
   * @brief private variable for width of image
   *
   */
  unsigned int inputWidth;
  /**
   * @brief private variable for height of image
   *
   */
  unsigned int inputHeight;
  /**
   * @brief private variable for nmsThreshold
   *
   */
  float nmsThreshold;
  /**
   * @brief private variable for confidenceThreshold
   *
   */
  float confidenceThreshold;

 public:
  /**
   * @brief Constructor for Human Detector object
   *
   */
  HumanDetector();

  /**
   * @brief Method to remove overlap boxes with lower confidence
   *
   */
  void rmOverlap(cv::Mat&, const std::vector<cv::Mat>&,
                 const std::vector<std::string>&);

  /**
   * @brief Method to draw a bounding box around the person
   *
   */
  void drawBox(int, float, int, int, int, int, cv::Mat&,
               const std::vector<std::string>&, unsigned int, float);

  /**
   * @brief Get the Outputs Layer Names
   *
   * @return std::vector<std::string>
   */
  std::vector<std::string> getOutputsNames(const cv::dnn::Net&);
  /**
   * @brief Function to detect the humans
   *
   * @param parse input parser
   */
  void detect(cv::CommandLineParser);
};
#endif  // INCLUDE_HUMAN_DETECTOR_HPP_

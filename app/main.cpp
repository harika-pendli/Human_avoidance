/**
 * @file main.cpp
 * @author Shailesh Pranav Rajendran (spraj@umd.edu) and Harika Pendli
 * (hpendli@umd.edu)
 * @brief Main file for human tracking
 * @version 0.1
 * @date 2022-10-11
 *
 * @copyright MIT License (c) 2022 Shailesh Pranav Rajendran and Harika Pendli
 *
 */

#include <iostream>
#include <opencv2/opencv.hpp>
#include <Human_detector.hpp>

const char* keys =
    "{help h usage ? | | Usage examples: "
    "\n\t\t./detect.out --image=1.png"
    "\n\t\t./detect.out --video=video.mp4 }"
    "{image img||input image}"
    "{video vid||input video}";

int main(int argc, char** argv) {
  HumanDetector detection;

  cv::CommandLineParser parser(argc, argv, keys);
  if (parser.has("help")) {
    parser.printMessage();
    return 0;
  }
  /**
   * @brief Starting the detection algorithm
   *
   */
  detection.detect(parser);
  return 0;
}

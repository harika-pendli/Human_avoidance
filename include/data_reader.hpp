/**
 * @file data_reader.hpp
 * @author Harika Pendli (hpendli@umd.edu) and Shailesh Pranav Rajendran
 * (spraj@umd.edu)
 * @brief
 * @version 0.1
 * @date 2022-10-19
 *
 * @copyright MIT License (c) 2022 Shailesh Pranav Rajendran and Harika Pendli
 *
 */

#ifndef INCLUDE_DATA_READER_HPP_
#define INCLUDE_DATA_READER_HPP_

#include <iostream>
#include <string>
#include <opencv2/opencv.hpp>

/**
 * @brief The class for processing the input data before feeding to the detection process
 */
class DataReader {
 private:
  /**
   * @brief Path address for the image
   *
   */
  std::string img_path;

  /**
   * @brief Path address for the image
   *
   */
  std::string video_path;
  /**
   * @brief private variable to store output width of the image
   * 
   */
  int outputWidth;


  /**
  * @brief private variable to store output Height of the image  
  * 
  */
  int outputHeight;

 public:
  /**
   * @brief Construct a new Data Reader object
   *
   */
  DataReader();
  /**
   * @brief Set the Imagepath object
   *
   */
  void setImagepath(const std::string&);

  /**
   * @brief Set the Videopath object
   *
   */
  void setVideopath(const std::string&);
  /**
   * @brief Get the Imagepath object
   *
   * @return std::string
   */
  std::string getImagepath();

  /**
   * @brief Get the Videopath object
   *
   * @return std::string
   */
  std::string getVideopath();

  /**
   * @brief Get the Output Width object
   * 
   * @return int 
   */
  int getOutputWidth();

  /**
   * @brief Get the Output Height object
   * 
   * @return int 
   */

  int getOutputHeight();

  /**
   * @brief Set the Output Height object
   * 
   * @param height 
   */
  void setOutputHeight(int height);


  /**
   * @brief Set the Output Width object
   * 
   * @param width 
   */
  void setOutputWidth(int width);

  /**
   * @brief Get the Input dataType
   *
   * @param parser
   * @return std::string 'Image', 'Video' or 'Error'
   */
  std::string getInput(const cv::CommandLineParser parser);

  /**
   * @brief Get the Input dataType
   *
   * @param parser
   * @return std::string 'Image', 'Video' or 'Error'
   */
  std::string getInputType(const cv::CommandLineParser parser);

  /**
   * @brief A function for image preprocessing
   *
   * @param frame The input image
   * @return cv::VideoCapture
   */
  cv::VideoCapture imgProcessor(char, cv::Mat frame);

  /**
   * @brief A function for video preprocessing
   *
   * @param frame The current frame
   * @param video Resulting video for the image to be written onto
   * @return cv::VideoCapture
   */
  cv::VideoCapture videoProcessor(char, cv::Mat frame, cv::VideoWriter video);

  /**
   * @brief Get the Input object
   * 
   * @return std::string 
   */
  std::string getInput(cv::CommandLineParser, std::string&);
  /**
   * @brief Destroy the Data Reader object
   *
   */
  ~DataReader();
};
#endif  // INCLUDE_DATA_READER_HPP_

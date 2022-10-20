/**
 * @file data_reader.cpp
 * @author Harika Pendli (hpendli@umd.edu) and Shailesh Pranav Rajendran
 * (spraj@umd.edu)
 * @brief
 * @version 0.1
 * @date 2022-10-19
 *
 * @copyright MIT License (c) 2022 Shailesh Pranav Rajendran and Harika Pendli
 *
 */

#include "../include/data_reader.hpp"
/**
 * @brief Constructor for Data Reader
 *
 */
// DataReader::DataReader();

void DataReader::setImagepath(std::string path) { img_path = path; }
void DataReader::setVideopath(std::string path) {
  video_path = std::move(path);
}

std::string DataReader::getImagepath() { return img_path; }

std::string DataReader::getVideopath() { return video_path; }

cv::Mat DataReader::imgprocessor(cv::Mat frame) { return frame; }

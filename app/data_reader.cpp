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
DataReader::DataReader(){
}

void DataReader::setImagepath(std::string path) { img_path = path; }
void DataReader::setVideopath(std::string path) {
  video_path = path;
}

std::string DataReader::getInput(cv::CommandLineParser parser, std::string &input_Type){
  if(parser.has("image") || parser.has("img")){
    img_path = parser.get<std::string>("image");
    input_Type = "image";
    return img_path;
  }
  if(parser.has("video") || parser.has("vid")){
    img_path = parser.get<std::string>("video");
    input_Type = "video";
    return video_path;
  }
  else {
    std::cout<<"No input path is provided"<<std::endl;
    return "Error in path";
  }
}

int DataReader::getOutputWidth() {
  return outputWidth;
}

int DataReader::getOutputHeight() {
  return outputHeight;
}

void DataReader::setOutputHeight(int height) {
  outputHeight = height;
}

void DataReader::setOutputWidth(int width) {
  outputWidth = width;
}

std::string DataReader::getImagepath() { return img_path; }

std::string DataReader::getVideopath() { return video_path; }

cv::VideoCapture DataReader::imgProcessor(const char rw, cv::Mat frame) { 
  if (rw == 'r') {
    cv::VideoCapture cap;
    cap.open(img_path);
    return cap;
  }
  else if (rw == 'w') {
    cv::imwrite("../output/Result.jpg",frame);
    return cv::VideoCapture();
  }
  else {
    std::cout<<"Error in image processor"<<std::endl;
    return cv::VideoCapture();
  }
}

cv::VideoCapture DataReader::videoProcessor(char rw, cv::Mat frame, cv::VideoWriter out) {
  if (rw == 'r') {
    cv::VideoCapture capture;
    capture.open(video_path);
    return capture;
  } 
  else if (rw == 'w') {
    cv::Mat newFrame;
    cv::resize(frame, newFrame, cv::Size(getOutputWidth(), getOutputHeight()));
    out.write(newFrame);
    return cv::VideoCapture();
  }
  else
  {
    std::cout<<"Error in video processor"<<std::endl;
    return cv::VideoCapture();
  }
}
DataReader::~DataReader(){ 
}


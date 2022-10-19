/**
 * @file data_reader.hpp
 * @author Harika Pendli (hpendli@umd.edu) and Shailesh Pranav Rajendran (spraj@umd.edu)
 * @brief 
 * @version 0.1
 * @date 2022-10-19
 * 
 * @copyright MIT License (c) 2022 Shailesh Pranav Rajendran and Harika Pendli
 * 
 */

#ifndef INCLUDE_DATAREADER_HPP_
#define INCLUDE_DATAREADER_HPP_

#include <opencv2/opencv.hpp>
#include <iostream>

class DataReader{
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

    public:
        DataReader();
        /**
         * @brief Set the Imagepath object
         * 
         */
        void setImagepath(std::string);
        
        /**
         * @brief Set the Videopath object
         * 
         */
        void setVideopath(std::string);
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
         * @brief A function for image preprocessing
         * 
         * @param frame The input image
         * @return cv::VideoCapture 
         */
        cv::Mat imgprocessor(cv::Mat frame);

        /**
         * @brief A function for video preprocessing
         * 
         * @param frame The current frame
         * @param video Resulting video for the image to be written onto
         * @return cv::VideoCapture 
         */
        cv::VideoCapture videoprocessor(cv::Mat frame, cv::VideoWriter video);

        ~DataReader();

        
};
#endif //DATAREADER
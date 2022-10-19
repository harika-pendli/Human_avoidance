/**
 * @file detect.cpp
 * @author Harika Pendli (hpendli@umd.edu)
 * @brief 
 * @version 0.1
 * @date 2022-10-18
 * 
 * @copyright Copyright (c) 2022
 * 
 */
// TO DO:

    //add a function to start inputing frames or video  get_image()
    // i am not sure how to declare 
    //insert model in here to detect
    // add MIT license

#include <iostream>
#include <string>
#include <vector>
#include <array>
#include <iostream>
#include "include/detect.hpp"

/**
 * @brief detects humans in the frame with some confidence
 * 
 * @return std::vector<std::array<float,4>> comprising of arrays of form(id,x1,y1, confidence)
 */
std::vector<std::array<float,4>> Detector::detecting() {

    std::vector<std::array<float, 4>> detections;
    std::array <float, 4> arr={0,1,2,99.99};
    
    detections.push_back(arr);
    return detections;

}; // function that takes a frame and detects


/**
 * @brief filters humans with greater than 80% confidence
 * 
 * @return std::vector<std::array<float,3>> comprising of arrays of form(id,x1,y1)
 */
std::vector<std::array<float,3>> Detector::filter() {

    std::vector<std::array<float, 3>> filters;
    std::array <float, 3> arr={0,1,2};
    
    filters.push_back(arr);
    return filters;
} //function that returns list of humans above certain confidence level
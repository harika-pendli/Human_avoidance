/**
 * @file Human_detector.hpp
 * @author Harika Pendli (hpendli@umd.edu)
 * @brief Driver class for all classes
 * @version 0.1
 * @date 2022-10-18
 * 
 * @copyright Copyright (c) 2022
 * 
 */

//TO DO:: 
    // ADD mit liCENSE  
    // complete preprocess image stub
    // 

#include <iostream>
#include <string>
#include <vector>
#include <array>
#include <iostream>
#include "camera.hpp"
#include "detect.hpp"
#include "track.hpp"


/**
 * @brief initialises instances of all classes and sets the detector in motion
 * 
 */
void Human_detector::initialise() {

    std::cout<<("HUman detector and tracker initialised");
}

// return image   image_preprocess();



/**
 * @brief transforms the detected human coordinates into robot coordinate system and displays
 * 
 * @return std::vector<std::vector<float>> 
 */
std::vector<std::vector<float>> Human_Detector::camera_robot_array(std::vector<std::vector<float>>) {
    
    //stub
    std::vector<std::vector<float>> out;
    std::vector<float> in_1;
    in_1.push_back(1.11);
    in_1.push_back(1.22);
    out.push_back(in_1);
    return out;
} // returns transformed coordinates and distance of humans

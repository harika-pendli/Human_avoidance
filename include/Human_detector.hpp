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
#ifndef INCLUDE_HUMAN_AVOIDANCE_HPP_
#define INCLUDE_HUMAN_AVOIDANCE_HPP_

#include <iostream>
#include <string>
#include <vector>
#include <array>
#include <iostream>
#include "camera.hpp"
#include "detect.hpp"
#include "track.hpp"


class Human_detector{
    private:
    camera Camera;
    detect Detector;
    track Tracker;

    public:
    void initialise ();
    // return image   image_preprocess();
    std::vector<std::vector<float>> camera_robot_array(std::vector<std::vector<float>>); // returns transformed coordinates and distance of humans
};
#endif //HUMAN_AVOIDANCE_HPP
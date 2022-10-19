/**
 * @file track.hpp
 * @author Shailesh Pranav Rajendran (spraj@umd.edu)
 * @brief Tracking class
 * @version 0.1
 * @date 2022-10-11
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include <iostream>
#include <string>
#include <vector>
#include <array>
#include <iostream>
#include "track.hpp"
/**
 * @brief class that tracks the objects from all frames of the video feed
 * 
 */

/**
 * @brief assigns id to track to that particular human instance
 * 
 * @param human_instance a vector with (temp_id, x,y)
 * @return int with a specific id if the object was seen in previous frame else assigned new id
 */

int Tracker::assign_id(std::vector<float> human_instance) {
    //stub
    return 1;
}

/**
 * @brief keeps a record of all the coordinates of the same human_instance
 * 
 * @param track_id_instance 
 * @return std::vector<float> 
 */
std::vector<float> Tracker::track (std::vector<float> track_id_instance) {
    //stub
    std::vector<float> vec;
    vec.push_back(1.11);
    vec.push_back(1.21);
    return vec;
}

/**
 * @file camera.cpp
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
    // add doxygen comment to Camera::set_intrinsic_camera_params
    //add doxygen comment about class 
    // add MIT license


#include <iostream>
#include <string>
#include <vector>
#include <array>
#include <iostream>
//#include <Eigen/Dense>
//#include <opencv2/opencv.hpp> 

#include "include/camera.hpp"



void Camera::set_intrinsic_camera_params (float para1,float para2,float para3,float para4,float para5) {         
        
        std::cout<<"Set intrinsic parameter matrix";
};

/**
 * @brief Set the rotation camera params object
 * 

 * @param para1 rotation matrix r11 element
 * @param para2 rotation matrix r12 element
 * @param para3 rotation matrix r13 element
 * @param para4 rotation matrix r21 element
 * @param para5 rotation matrix r22 element
 * @param para6 rotation matrix r23 element
 * @param para7 rotation matrix r31 element
 * @param para8 rotation matrix r32 element
 * @param para9 rotation matrix r33 element
 */
void Camera::set_rotation_camera_params (float para1,float para2,float para3,float para4,float para5, float para6,float para7, float para8,float para9){
    
    std::cout<<"Set rotation parameters of extrinsic matrix";
} 

/**
 * @brief Set the translation camera params object
 * 
 * @param para1 translation vector t1 element
 * @param para2 translation vector t2 element
 * @param para3 translation vector t3 element
 */
void Camera::set_translation_camera_params (float para1,float para2,float para3) {

    std::cout<<"Set translation parameters of extrinsic matrix";
} //translation part of the extrinsic params matrix

    


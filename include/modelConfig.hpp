/**
 * @file modelConfig.hpp
 * @author Shailesh Pranav Rajendran (spraj@umd.edu)
 * @brief
 * @version 0.1
 * @date 2022-10-24
 *
 * @copyright Copyright (c) 2022
 *
 */

#ifndef INCLUDE_MODELCONFIG_HPP_
#define INCLUDE_MODELCONFIG_HPP_
#include <fstream>
#include <iostream>
#include <vector>
#include <string>
/**
 * @brief Contains all the model configuration paths and links
 * 
 */
class ModelConfig {
 private:
  /**
   * @brief path to the class location
   * 
   */
  std::string modelClassLoc = "../input/coco.names";
  /**
   * @brief path to configuration location
   * 
   */
  std::string modelConfigLoc = "../input/yolov3.cfg";
  /**
   * @brief path to model weights location
   * 
   */
  std::string modelWeightsLoc = "../input/yolov3.weights";
  /**
   * @brief contains all the class names
   * 
   */
  std::vector<std::string> class_names;

 public:
  
  ModelConfig();
  /**
   * @brief Get Classes from the above mentioned location
   * 
   * @return std::vector<std::string> 
   */
  std::vector<std::string> getClasses();
  /**
   * @brief Get the Config from the above mentioned location
   * 
   * @return std::string 
   */
  std::string getConfig();
  /**
   * @brief Get the Weights from the above mentioned location
   * 
   * @return std::string 
   */
  std::string getWeights();
  ~ModelConfig();
};

#endif  // INCLUDE_MODELCONFIG_HPP_

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
#include <iostream>
#include <vector>
#include <fstream>

class ModelConfig
{
    private:
        std::string modelClassLoc = "../input/coco.names";
        std::string modelConfigLoc = "../input/yolov3.cfg";
        std::string modelWeightsLoc = "../input/yolov3.weights";

        std::vector<std::string> class_names;
    public:
        ModelConfig();
        std::vector<std::string> getClasses();
        std::string getConfig();
        std::string getWeights();
        ~ModelConfig();
};
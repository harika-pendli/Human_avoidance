/**
 * @file modelConfig.cpp
 * @author Shailesh Pranav Rajendran (spraj@umd.edu)
 * @brief 
 * @version 0.1
 * @date 2022-10-24
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include <../include/modelConfig.hpp>

ModelConfig::ModelConfig(){
    std::ifstream ifs(modelClassLoc.c_str());
    std::string yoloClasses;

    while (std::getline(ifs,yoloClasses))
    {
        class_names.push_back(yoloClasses);
    }

}

std::vector<std::string> ModelConfig::getClasses(){
    return class_names;
}

std::string ModelConfig::getConfig(){
    return modelConfigLoc;
}

std::string ModelConfig::getWeights(){
    return modelWeightsLoc;
}

ModelConfig::~ModelConfig(){
}

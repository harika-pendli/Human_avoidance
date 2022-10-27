/**
 * @file modelConfig_test.cpp
 * @author Shailesh Pranav Rajendran (spraj@umd.edu)
 * @brief 
 * @version 0.1
 * @date 2022-10-27
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include <gtest/gtest.h>
#include <string>
#include <opencv2/opencv.hpp>
#include <../include/modelConfig.hpp>

ModelConfig model;
TEST(TestSetGet, test_classs) {
    std::string path = "../input/coco.names";
    std::ifstream ifs(path.c_str());
    std::string yolo_classes;

    std::vector<std::string> class_n;
    while (std::getline(ifs, yolo_classes)) {
        class_n.push_back(yolo_classes);
    }
    for (auto p:class_n)
        std::cout<<p;
    EXPECT_EQ(model.getClasses(), class_n);
}

TEST(TestSetGet, test_model_weights) {
    std::string path = "../input/yolov3.weights";
    EXPECT_EQ(model.getWeights(), path);
}

TEST(TestSetGet, test_model_cfg) {
    std::string path = "../input/yolov3.cfg";
    EXPECT_EQ(model.getConfig(), path);
}
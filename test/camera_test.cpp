/**
 * @file test_camera.cpp
 * @author Shailesh Pranav Rajendran (spraj@umd.edu)
 * @brief
 * @version 0.1
 * @date 2022-10-19
 *
 * @copyright Copyright (c) 2022
 *
 */

#include <gtest/gtest.h>

#include <vector>
#include <../include/camera.hpp>

Camera cam;
TEST(camera, init_intrinsic) {
  float p1(0), p2(0), p3(0), p4(0), p5(0);
  EXPECT_NO_FATAL_FAILURE(cam.set_intrinsic_camera_params(p1, p2, p3, p4, p5));
}

TEST(camera, init_rotation) {
  float p1(0), p2(0), p3(0), p4(0), p5(0), p6(0), p7(0), p8(0), p9(0);
  EXPECT_NO_FATAL_FAILURE(
      cam.set_rotation_camera_params(p1, p2, p3, p4, p5, p6, p7, p8, p9));
}

TEST(camera, init_translaction) {
  float p1(0), p2(0), p3(0);
  EXPECT_NO_FATAL_FAILURE(cam.set_translation_camera_params(p1, p2, p3));
}

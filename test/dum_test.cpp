#include <gtest/gtest.h>
// #include <../include/data_reader.hpp>

TEST(dummy, should_pass) { EXPECT_EQ(1, 1); }

DataReader data;

TEST(TestSetGet, testgetimgpath) {
  data.setImagepath("test");
  //   EXPECT_EQ(data.getImagepath(),"test");
  EXPECT_TRUE(data.getImagepath() == std::string("test"));
}
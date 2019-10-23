/// \copyright Copyright 2018 Apex.AI, Inc.
/// All rights reserved.
/// \file
/// \brief Unit tests for shared_ptr allocation

#include <gtest/gtest.h>

#include <apex_test_tools/apex_test_tools.hpp>

#include <array>
#include <memory>

template<typename T>
class SharedPtr : public ::testing::Test
{
};
// Instantiate tests for given types, add more types here as they are used
using Types = ::testing::Types<
  std::array<char, 1>,
  std::array<char, 2>,
  std::array<char, 4>,
  std::array<char, 8>,
  std::array<char, 16>,
  std::array<char, 32>,
  std::array<char, 64>,
  std::array<char, 128>,
  std::array<char, 256>,
  std::array<char, 512>,
  std::array<char, 1024>,
  std::array<char, 2048>
>;
TYPED_TEST_CASE(SharedPtr, Types);

TYPED_TEST(SharedPtr, AllocTest)
{
  auto p1 = std::make_shared<TypeParam>();
  apex_test_tools::memory_test::start();
  auto p2 = p1;
  auto p3 = p1;
  auto p4 = p2;
  auto p5 = p3;
  apex_test_tools::memory_test::stop();
}

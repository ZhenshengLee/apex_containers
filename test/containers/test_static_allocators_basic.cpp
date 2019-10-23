/// \copyright Copyright 2018 Apex.AI, Inc.
/// All rights reserved.
/// \file
/// \brief Unit tests for the single_allocator

#include <gtest/gtest.h>

#include <apex_test_tools/apex_test_tools.hpp>
#include <containers/static_vector.hpp>

#include <string>
#include <cmath>
#include <thread>
#include <utility>
#include <limits>

template<class T>
void test_allocate(T & alloc, std::size_t size)
{
  EXPECT_EQ(alloc.max_size(), size);

  EXPECT_THROW(alloc.allocate(size + 1), std::bad_alloc);
  EXPECT_THROW(alloc.allocate(0), std::bad_alloc);

  auto mem1 = alloc.allocate(size);
  EXPECT_THROW(alloc.allocate(size), std::bad_alloc);

  alloc.deallocate(mem1, size);
  EXPECT_THROW(alloc.allocate(size), std::bad_alloc);
}

TEST(single_allocator, allocate) {
  constexpr auto size = 3453;
  apex::_vector_impl::single_allocator<int> sa(size);
  test_allocate(sa, size);

  EXPECT_THROW(apex::_vector_impl::single_allocator<int>
    sa(std::numeric_limits<std::size_t>::max()), std::bad_alloc);
}

TEST(single_allocator, comparison_swap) {
  constexpr auto size = 3453;
  apex::_vector_impl::single_allocator<int> sa(size);
  apex::_vector_impl::single_allocator<int> sb(2 * size);
  ASSERT_EQ(sa, sb);
  ASSERT_EQ(sa != sb, false);
}

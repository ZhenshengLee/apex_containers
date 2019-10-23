/// \copyright Copyright 2018 Apex.AI, Inc.
/// All rights reserved.
/// \file
/// \brief Unit tests for the static_vector example snippets

#include <gtest/gtest.h>
#include <apex_containers/static_vector.hpp>

TEST(static_vector, documentation) {
  ASSERT_ANY_THROW({
    //! [Basic Static Vector]
    // Allocates all the memory on construction for 500 elements
    apex::static_vector<int> v(500);
    // Trying to allocate more than the initial amount of memory will throw an exception.
    v.resize(501);
    //! [Basic Static Vector]
  });
}

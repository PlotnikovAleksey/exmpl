#include <gtest/gtest.h>
#include <app.hpp>

TEST(very, simple) {
  EXPECT_EQ(square(2), 4);
  std::cout << "We are good!\n";
}

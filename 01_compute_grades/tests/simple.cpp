#include <gtest/gtest.h>

#include "../src/line.hpp"

// Demonstrate some basic assertions.
TEST(HelloTest, BasicAssertions)
{
    EXPECT_STRNE("hello", "world"); // Expect two strings not to be equal.
    EXPECT_EQ(7 * 6, 42); // Expect equality.
}

TEST(LineTest, Constructor)
{
    Line l("soccer", 2, 17.2);
    ASSERT_EQ(l.getGrades(), 17.2);
}

#include "gtest/gtest.h"
#include "myfile.h"

TEST(MyFileTest, Add_PositiveNumbers)
{
    EXPECT_EQ(add(2, 3), 5);
}

TEST(MyFileTest, Add_PositiveAndNegativeNumbers)
{
    EXPECT_EQ(add(-1, 1), 0);
}

TEST(MyFileTest, Add_ZeroNumbers)
{
    EXPECT_EQ(add(0, 0), 0);
}

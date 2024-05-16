#include <gtest/gtest.h>
#include <args/parsing.h>

TEST(ParsingTest, CapacitySizeKB) { 
    EXPECT_EQ(args::KB, 1024);
}

TEST(ParsingTest, CapacitySizeMB) { 
    EXPECT_EQ(args::MB, 1024 * 1024);
}

TEST(ParsingTest, CapacitySizeGB) { 
    EXPECT_EQ(args::GB, 1024LL * 1024LL * 1024LL);
}

TEST(ParsingTest, CapacitySizeTB) { 
    EXPECT_EQ(args::TB, 1024LL * 1024LL * 1024LL * 1024LL);
}

TEST(ParsingTest, Test4) {
  EXPECT_EQ(1 + 1, 2);
}

TEST(ParsingTest, Test5) {
  EXPECT_EQ(1 + 1, 2);
}

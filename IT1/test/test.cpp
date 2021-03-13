// Copyright 2021 Nagdimaev Ilyagu

#include <cstdio>
#include <fstream>

#include "gtest/gtest.h"

extern "C" {
    #include "func/func.h"
}


TEST(find_quality, find_quality1) {
    ASSERT_EQ(0, find_quality("Отличное"));
    ASSERT_EQ(20, find_quality("Хорошее"));
    ASSERT_EQ(35, find_quality("Плохое"));
    ASSERT_EQ(50, find_quality("Ужасное"));
    ASSERT_EQ(200, find_quality("паылвралоыва"));
}

// test decrypt

TEST(decrypt, decrypt1) {
    ASSERT_STREQ("Таких дорог нет", decrypt(0));
    ASSERT_STREQ("Ужасное", decrypt(50));
    ASSERT_STREQ("Плохое", decrypt(60));
    ASSERT_STREQ("Хорошее", decrypt(72));
    ASSERT_STREQ("Отличное", decrypt(95));
    ASSERT_STREQ("ERROR", decrypt(200));
}

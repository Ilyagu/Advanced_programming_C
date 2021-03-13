// Copyright 2021 Nagdimaev Ilyagu

#include <cstdio>
#include <fstream>

#include "gtest/gtest.h"

extern "C" {
    #include "func/func.h"
}

class FindQuality : public ::testing::Test {
protected:
    void SetUp() {
        test_result = new char*[5];
        for (int i = 0; i < 5; i++) {
            test_result[i] = new char[100];
        }

        strncpy(test_result[0], "Отличное", 100);
        strncpy(test_result[1], "Хорошее", 100);
        strncpy(test_result[2], "Плохое", 100);
        strncpy(test_result[3], "Ужасное", 100);
        strncpy(test_result[4], "Фейк", 100);

    }
    void TearDown() {
        for (int i = 0; i < 5; i++) {
            delete []test_result[i];
        }
        delete []test_result;
    }
    char **test_result;
};

TEST_F(FindQuality, find_quality1) {
    EXPECT_EQ(0, find_quality(test_result[0]));
}

TEST_F(FindQuality, find_quality2) {
    EXPECT_EQ(20, find_quality(test_result[1]));
}

TEST_F(FindQuality, find_quality3) {
    EXPECT_EQ(35, find_quality(test_result[2]));
}

TEST_F(FindQuality, find_quality4) {
    EXPECT_EQ(50, find_quality(test_result[3]));
}

TEST_F(FindQuality, invalid_quallity) {
    EXPECT_EQ(200, find_quality(test_result[4]));
}

//
// test decrypt
//

TEST(decrypt, decrypt1) {
    EXPECT_STREQ("Таких дорог нет!", decrypt(0));
}

TEST(decrypt, decrypt2) {
    EXPECT_STREQ("Ужасное", decrypt(50));
}

TEST(decrypt, decrypt3) {
    EXPECT_STREQ("Плохое", decrypt(60));
}

TEST(decrypt, decrypt4) {
    EXPECT_STREQ("Хорошее", decrypt(72));
}

TEST(decrypt, decrypt5) {
    EXPECT_STREQ("Отличное", decrypt(95));
}

TEST(decrypt, decrypt6) {
    EXPECT_STREQ("ERROR", decrypt(200));
}


//
// test qual
//
//
//class TestQual : public ::testing::Test {
//protected:
//    void SetUp() {
//        all_roads = reinterpret_cast<Road *>(malloc(sizeof(Road) * 6));
//
//        all_roads[0].length = 200;
//        strncpy(all_roads[0].type, "Грунт", 6);
//        strncpy(all_roads[0].quality, "Отличное", 9);
//        all_roads[0].lanes = 3;
//
//        all_roads[1].length = 200;
//        strncpy(all_roads[1].type, "Грунт", 6);
//        strncpy(all_roads[1].quality, "Отличное", 9);
//        all_roads[1].lanes = 3;
//
//        all_roads[2].length = 200;
//        strncpy(all_roads[2].type, "Грунт", 6);
//        strncpy(all_roads[2].quality, "Ужасное", 8);
//        all_roads[2].lanes = 3;
//
//        all_roads[3].length = 200;
//        strncpy(all_roads[3].type, "Грунт", 6);
//        strncpy(all_roads[3].quality, "Ужасное", 8);
//        all_roads[3].lanes = 3;
//
//        all_roads[4].length = 200;
//        strncpy(all_roads[4].type, "Асфальт", 9);
//        strncpy(all_roads[4].quality, "Отличное", 9);
//        all_roads[4].lanes = 5;
//
//        all_roads[5].length = 200;
//        strncpy(all_roads[5].type, "Асфальт", 9);
//        strncpy(all_roads[5].quality, "Ужасное", 8);
//        all_roads[5].lanes = 5;
//    }
//    void TearDown() {
//        free(all_roads);
//    }
//    Road *all_roads;
//};
//
//TEST_F(TestQual, qual1) {
//    ASSERT_STREQ("Хорошее", qual(all_roads, 4, "Грунт", 3));
//    ASSERT_STREQ("Хорошее", qual(all_roads, 4, "Асфальт", 5));
//    ASSERT_STREQ("Таких дорог нет!", qual(all_roads, 4, "Асфальт", 6));
// }
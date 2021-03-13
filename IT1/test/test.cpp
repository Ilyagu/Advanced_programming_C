// Copyright 2021 Nagdimaev Ilyagu

#include <cstdio>
#include <fstream>

#include "gtest/gtest.h"

extern "C" {
    #include "func/func.h"
}

// class TestSearchAuthor : public ::testing::Test {
// protected:
//    void SetUp() {
//        all_songs = reinterpret_cast<Song *>(malloc(sizeof(Song) * MIN_ARRAY_SIZE));
//        correct_right_songs = reinterpret_cast<Song *>(malloc(sizeof(Song) * MIN_ARRAY_SIZE));
//
//        strncpy(song1.author, "VTSS", MAX_FIELD_LENGTH);
//        strncpy(song1.singer, "VTSS", MAX_FIELD_LENGTH);
//        strncpy(song1.name, "Atlantyda", MAX_FIELD_LENGTH);
//        strncpy(song1.duration, "1:30", MAX_FIELD_LENGTH);
//
//        strncpy(song2.author, "Yaeji", MAX_FIELD_LENGTH);
//        strncpy(song2.singer, "Yaeji", MAX_FIELD_LENGTH);
//        strncpy(song2.name, "Raingirl", MAX_FIELD_LENGTH);
//        strncpy(song2.duration, "2:00", MAX_FIELD_LENGTH);
//
//        all_songs[0] = song1;
//        all_songs[1] = song2;
//        correct_right_songs[0] = song2;
//    }
//
//    void TearDown() {
//        if (right_songs != NULL) {
//            free(right_songs);
//        }
//        free(correct_right_songs);
//        free(all_songs);
//    }
//
//    Song song1, song2;
//    Song *right_songs = NULL, *all_songs, *correct_right_songs;
//    char my_author[10] = "Yaeji";
//    char another_author[10] = "VCL";
// };

// test find_quality

TEST(find_quality, find_quality) {
    ASSERT_EQ(0, find_quality("Отличное"));
    ASSERT_EQ(20, find_quality("Хорошее"));
    ASSERT_EQ(35, find_quality("Плохое"));
    ASSERT_EQ(50, find_quality("Ужасное"));
    ASSERT_EQ(200, find_quality("паылвралоыва"));
}

// test

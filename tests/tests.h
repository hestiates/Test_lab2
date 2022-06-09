#ifndef EQTEST_H
#define EQTEST_H
#include <gtest/gtest.h>
#include <gmock/gmock-matchers.h>
#include <iostream>
#include <fstream>

char* file = INPUTDIR "/sample.txt";
char* empty_file = INPUTDIR "/empty.txt";
char* nodigits = INPUTDIR "/no_digits.txt";

extern "C"{
#include "text.h"
#include "_text.h"
#include "common.h"
}

/*--load--*/
TEST(load, suite1) {
    text txt = create_text();

    testing::internal::CaptureStdout();
    load(txt, file);
    std::string output = testing::internal::GetCapturedStdout();

    ASSERT_EQ("Load file successeed!\n", output);

    remove_all(txt);
}

TEST(load, suite2) {
    text txt = create_text();

    testing::internal::CaptureStdout();
    load(txt, "nondsa.txt");
    std::string output = testing::internal::GetCapturedStdout();

    ASSERT_EQ("The file nondsa.txt cannot be opened\n", output);

    remove_all(txt);
}

TEST(load, suite3) {
    text txt = create_text();

    testing::internal::CaptureStdout();
    load(txt, "test.jpg");
    std::string output = testing::internal::GetCapturedStdout();

    ASSERT_EQ("The file test.jpg cannot be opened\n", output);

    remove_all(txt);
}

/*--move--*/
TEST(move, suite1) {
    text txt = create_text();
    load(txt, file);

    m(txt,0,0);

    testing::internal::CaptureStdout();
    show(txt);
    std::string output = testing::internal::GetCapturedStdout();

    ASSERT_EQ("|weq15h1c1\n"
              "13r3sag\n\n"

              "43vt24v1qwerwqr\n"
              "51523 asf 1 5 asd 3\n", output);

    remove_all(txt);
}

TEST(move, suite2) {
    text txt = create_text();
    load(txt, file);

    m(txt,2,4);

    testing::internal::CaptureStdout();
    show(txt);
    std::string output = testing::internal::GetCapturedStdout();

    ASSERT_EQ("weq15h1c1\n"
              "13r3|sag\n\n"

              "43vt24v1qwerwqr\n"
              "51523 asf 1 5 asd 3\n", output);

    remove_all(txt);
}

TEST(move, suite3) {
    text txt = create_text();
    load(txt, file);

    m(txt,-10, 0);

    testing::internal::CaptureStdout();
    show(txt);
    std::string output = testing::internal::GetCapturedStdout();

    ASSERT_EQ("|weq15h1c1\n"
              "13r3sag\n\n"

              "43vt24v1qwerwqr\n"
              "51523 asf 1 5 asd 3\n", output);

    remove_all(txt);
}

TEST(move, suite4) {
    text txt = create_text();
    load(txt, file);

    m(txt,15, 0);

    testing::internal::CaptureStdout();
    show(txt);
    std::string output = testing::internal::GetCapturedStdout();

    ASSERT_EQ("weq15h1c1\n"
              "13r3sag\n\n"

              "43vt24v1qwerwqr\n"
              "|51523 asf 1 5 asd 3\n", output);

    remove_all(txt);
}

TEST(move, suite5) {
    text txt = create_text();
    load(txt, file);

    m(txt,0, 20);

    testing::internal::CaptureStdout();
    show(txt);
    std::string output = testing::internal::GetCapturedStdout();

    ASSERT_EQ("weq15h1c1|\n"
              "13r3sag\n\n"

              "43vt24v1qwerwqr\n"
              "51523 asf 1 5 asd 3\n", output);

    remove_all(txt);
}

TEST(move, suite6) {
    text txt = create_text();
    load(txt, file);

    m(txt,0, -10);

    testing::internal::CaptureStdout();
    show(txt);
    std::string output = testing::internal::GetCapturedStdout();

    ASSERT_EQ("|weq15h1c1\n"
              "13r3sag\n\n"

              "43vt24v1qwerwqr\n"
              "51523 asf 1 5 asd 3\n", output);

    remove_all(txt);
}

TEST(move, suite7) {
    text txt = create_text();
    load(txt, empty_file);

    m(txt,0, 0);

    testing::internal::CaptureStderr();
    show(txt);
    std::string output = testing::internal::GetCapturedStderr();

    ASSERT_EQ("There are already no any lines in the text!\n", output);

    remove_all(txt);
}

/*--save--*/
TEST(save, suite1) {
    text txt = create_text();
    load(txt, file);
    append_line(txt, "aaa");

    testing::internal::CaptureStdout();
    save (txt, "text_test.txt");
    std::string output = testing::internal::GetCapturedStdout();

    ASSERT_EQ("File saved\n", output);

    remove_all(txt);
}

TEST(save, suite2) {
    text txt = create_text();
    load(txt, file);
    append_line(txt, "aaa.");

    testing::internal::CaptureStdout();
    save (txt, NULL);
    std::string output = testing::internal::GetCapturedStdout();

    ASSERT_EQ("The file (null) cannot be opened\n", output);

    remove_all(txt);
}

TEST(save, suite3) {
    text txt = create_text();
    load(txt, file);
    append_line(txt, file);

    testing::internal::CaptureStdout();
    save (NULL, "text_test2.txt");
    std::string output = testing::internal::GetCapturedStdout();

    ASSERT_EQ("There are already no any lines in the text!\n", output);

    remove_all(txt);
}

TEST(save, suite4) {
    text txt = create_text();
    load(txt, empty_file);

    testing::internal::CaptureStderr();
    save (txt, "empty1.txt");
    std::string output = testing::internal::GetCapturedStderr();

    ASSERT_EQ("", output);

    remove_all(txt);
}

/*--showdigitsonly--*/
TEST(showdigitsonly, suite1) {
    text txt = create_text();
    load(txt, file);
    m(txt, 1, 0);

    testing::internal::CaptureStdout();
    showdigitsonly(txt);
    std::string output = testing::internal::GetCapturedStdout();

    ASSERT_EQ("|   15 1 1\n"
              "13 3   \n\n"

              "43  24 1       \n"
              "51523     1 5     3\n", output);

    remove_all(txt);
}

TEST(showdigitsonly, suite2) {
    text txt = create_text();
    load(txt, nodigits);

    testing::internal::CaptureStdout();
    showdigitsonly(txt);
    std::string output = testing::internal::GetCapturedStdout();

    ASSERT_EQ("    \n"
              "    \n\n"

              "      |\n", output);

    remove_all(txt);
}

TEST(showdigitsonly, suit3) {
    text txt = create_text();

    testing::internal::CaptureStdout();
    showdigitsonly(txt);
    std::string output = testing::internal::GetCapturedStdout();

    ASSERT_EQ("", output);

    remove_all(txt);
}

TEST(showdigitsonly, suite4) {
    text txt = create_text();
    load(txt, empty_file);

    testing::internal::CaptureStderr();
    showdigitsonly(txt);
    std::string output = testing::internal::GetCapturedStderr();

    ASSERT_EQ("There are already no any lines in the text!\n", output);

    remove_all(txt);
}

/*--paste_new--*/
TEST(paste_n, suite1)
{
    text txt = create_text();
    load(txt, file);
    char *s;
    s = (char *)malloc(sizeof(char) * 256);
    for (int i = 0; i < MAXLINE + 1; i++)
    {
        s[i] = 'a';
    }
    s[256] = '\0';
    testing::internal::CaptureStderr();
    paste_n(txt, s);
    std::string output = testing::internal::GetCapturedStderr();
    ASSERT_EQ("", output);
}

TEST(paste_n, suite2)
{
    text txt = create_text();
    load(txt, file);
    testing::internal::CaptureStderr();
    paste_n(txt, "s2 ample");
    std::string output = testing::internal::GetCapturedStderr();
    ASSERT_EQ("", output);
}

/*--mklb--*/
TEST(mklb, suite1) {
    text txt = create_text();
    load(txt, file);

    mklb(txt,2);

    testing::internal::CaptureStdout();
    show(txt);
    std::string output = testing::internal::GetCapturedStdout();

    ASSERT_EQ("weq15h1c1\n"
              "|13r3sag\n\n"

              "43vt24v1qwerwqr\n"
              "51523 asf 1 5 asd 3\n", output);

    remove_all(txt);
}

TEST(mklb, suite2) {
    text txt = create_text();
    load(txt, file);

    mklb(txt,-10);

    testing::internal::CaptureStdout();
    show(txt);
    std::string output = testing::internal::GetCapturedStdout();

    ASSERT_EQ("|weq15h1c1\n"
              "13r3sag\n\n"

              "43vt24v1qwerwqr\n"
              "51523 asf 1 5 asd 3\n", output);

    remove_all(txt);
}

TEST(mklb, suite3) {
    text txt = create_text();
    load(txt, file);

    mklb(txt,15);

    testing::internal::CaptureStdout();
    show(txt);
    std::string output = testing::internal::GetCapturedStdout();

    ASSERT_EQ("weq15h1c1\n"
              "13r3sag\n\n"

              "43vt24v1qwerwqr\n"
              "|51523 asf 1 5 asd 3\n", output);

    remove_all(txt);
}

#endif // EQTEST_H

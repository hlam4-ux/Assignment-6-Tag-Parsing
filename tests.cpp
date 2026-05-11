//----------------------------------------------------------
// CS161 Assignment Starter Code
// Copyright Andrew Scholer (ascholer@chemeketa.edu)
// Neither this code, nor any works derived from it
//    may be republished without approval.
//----------------------------------------------------------

// Bring in unit testing code and tell it to build a main function
// If you have multiple unit test files, only one should have this define
#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN

#include "doctest.h"

// Use Approx from doctest without saying doctest::Approx
using doctest::Approx;

//-----------------------------------------------------------------------------------

#include <iostream>
#include <string>
using namespace std;

// Functions to write.
// You do NOT need to write doxygen comments for these. You may add extra helper
// functions if you want. Work on them one at a time.

string getImageSource(string tag)
{
  int start = tag.find("source=\"") + 8;
  int end = tag.find("\"", start);

  return tag.substr(start, end - start);
}

string underscoresToSpaces(string str)
{
  for (int i = 0; i < str.length(); i++) {
    if (str[i] == '_') {
      str[i] = ' ';
    }
  }

  return str;
}

int getImageWidth(string tag)
{
  int start = tag.find("width=\"") + 7;
  int end = tag.find("px", start);

  string number = tag.substr(start, end - start);

  return stoi(number);
}

int getImageHeight(string tag)
{
  int start = tag.find("height=\"") + 8;
  int end = tag.find("px", start);

  string number = tag.substr(start, end - start);

  return stoi(number);
}

int getVerticalPadding(string tag)
{
  int start = tag.find("padding=\"");

  if (start == -1) {
    return 0;
  }
  start = start + 9;
  int end = tag.find("px", start);

  string number = tag.substr(start, end - start);

  return stoi(number);
}

int getHorizontalPadding(string tag)
{
  int start = tag.find(" ");
  if (start == -1) {
    return 0;
  }
  start = start + 1;
  int end = tag.find("px", start);

  string number = tag.substr(start, end - start);

  return stoi(number);
}

//-----------------------------------------------------------------------------------
// Testing code

// The line "// clang-format off" below turns off auto-formatting
// That will keep the example strings from being reformatted to multiple lines
// clang-format off
const string EXAMPLE_1 = "<image source=\"puppy.jpg\" width=\"100px\" height=\"200px\">";
const string EXAMPLE_2 = "<image source=\"cat_pounce.gif\" height=\"400px\" width=\"300px\" padding=\"10px\">";
const string EXAMPLE_3 = "<image width=\"400px\" height=\"250px\" padding=\"10px 5px\" source=\"little_red_snake.mpeg\">";
// clang-format on
// "// clang-format on" turns auto-formatting back on

TEST_CASE("Testing getImageSource")
{
  cout << "1: getImageSource" << endl;
  CHECK(getImageSource(EXAMPLE_1) == "puppy.jpg");
  CHECK(getImageSource(EXAMPLE_2) == "cat_pounce.gif");
  CHECK(getImageSource(EXAMPLE_3) == "little_red_snake.mpeg");
}

TEST_CASE("Testing underscoresToSpaces")
{
  cout << "2: underscoresToSpaces" << endl;
  CHECK(underscoresToSpaces("puppy.jpg") == "puppy.jpg");
  CHECK(underscoresToSpaces("cat_pounce.gif") == "cat pounce.gif");
  CHECK(underscoresToSpaces("little_red_snake.mpeg")
        == "little red snake.mpeg");
}

TEST_CASE("Testing getImageWidth")
{
  cout << "3: getImageWidth" << endl;
  CHECK(getImageWidth(EXAMPLE_1) == 100);
  CHECK(getImageWidth(EXAMPLE_2) == 300);
  CHECK(getImageWidth(EXAMPLE_3) == 400);
}

TEST_CASE("Testing getImageHeight")
{
  cout << "4: getImageHeight" << endl;
  CHECK(getImageHeight(EXAMPLE_1) == 200);
  CHECK(getImageHeight(EXAMPLE_2) == 400);
  CHECK(getImageHeight(EXAMPLE_3) == 250);
}

TEST_CASE("Testing getVerticalPadding")
{
  cout << "5: getVerticalPadding" << endl;
  CHECK(getVerticalPadding(EXAMPLE_1) == 0);
  CHECK(getVerticalPadding(EXAMPLE_2) == 10);
  CHECK(getVerticalPadding(EXAMPLE_3) == 10);
}

TEST_CASE("Testing getHorizontalPadding")
{
  cout << "6: getHorizontalPadding" << endl;
  CHECK(getHorizontalPadding(EXAMPLE_1) == 0);
  CHECK(getHorizontalPadding(EXAMPLE_2) == 10);
  CHECK(getHorizontalPadding(EXAMPLE_3) == 5);
}
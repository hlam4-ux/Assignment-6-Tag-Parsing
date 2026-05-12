//----------------------------------------------------------
// CS161 Assignment Starter Code
// Copyright Andrew Scholer (ascholer@chemeketa.edu)
// Neither this code, nor any works derived from it
//    may be republished without approval.
//----------------------------------------------------------

#include <iostream>
#include <string>

using namespace std;

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
  int start = tag.find("padding=\"");
  if (start == -1) {
    return 0;
  }
  start = start + 9;
  int space = tag.find(" ", start);

  if (space == -1) {
    int end = tag.find("px", start);
    string number = tag.substr(start, end - start);
    return stoi(number);
  }

  start = space + 1;
  int end = tag.find("px", start);

  string number = tag.substr(start, end - start);

  return stoi(number);
}

int main()
{
  cout << "Enter a tag: ";
  string tag;
  getline(cin, tag); // read a full line of input including spaces

  // Some sample inputs you can copy-paste to test your main
  // <image source="puppy.jpg" width="100px" height="200px">
  // <image source="cat_pounce.gif" height="400px" width="300px" padding="10px">
  // <image width="400px" height="250px" padding="10px 5px"
  // source="little_red_snake.mpeg">

  cout << "Tag:" << tag << endl;
  cout << "Image file:" << getImageSource(tag) << endl;
  cout << "Image description:" << underscoresToSpaces(getImageSource(tag))
       << endl;
  cout << "width:" << getImageWidth(tag) << endl;
  cout << "height" << getImageHeight(tag) << endl;
  cout << "Vertical padding:" << getVerticalPadding(tag) << endl;
  cout << "Horizontal padding:" << getHorizontalPadding(tag) << endl;

  int finalWidth = getImageWidth(tag) + getHorizontalPadding(tag) * 2;
  int finalHeight = getImageHeight(tag) + getVerticalPadding(tag) * 2;

  cout << "final dimensions:" << finalWidth << "x" << finalHeight << endl;
}

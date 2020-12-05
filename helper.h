//helper.h
//Patrick Polcuch
//2348668
//CPSC350Assignment5

//The .h file for helper.cpp
#include <string>

using namespace std;

class helper{
public:
  helper();
  ~helper();
  static bool toFile(string s, string f);
};

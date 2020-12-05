//Student.h
//Patrick Polcuch
//2348668
//CPSC350Assignment5

//My .h file for Student.cpp
#include <iomanip>
#include <iostream>

using namespace std;

class Student{
public:
  int ID;
  string name;
  string year;
  string major;
  double GPA;
  int advisor;

  Student(int id, string n, string y, string m, double g, int a);
  Student();
  ~Student();
  bool operator <(Student* s);
  bool operator >(Student* s);
  bool operator ==(Student* s);
  bool operator >=(Student* s);
  bool operator <=(Student* s);
  string toString();
  string toStringUser();
};

//Faculty.h
#include <iomanip>
#include <iostream>

using namespace std;

class Faculty{
public:
  Faculty(int id, string n, string l, string d);
  Faculty();
  ~Faculty();
  string toString();
  string toStringUser();
  bool removeAdvissee(int idnum);
  bool addAdvisee(int adviseeID);



  int ID;
  string name;
  string level;
  string department;
  int advisees[300];
};

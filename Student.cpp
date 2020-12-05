//Student.cpp
//Patrick Polcuch
//2348668
//CPSC350Assignment5

//Allows for the creation of Student objects
#include "Student.h"

Student::Student(int id, string n, string y, string m, double g, int a){
  ID = id;
  name = n;
  year = y;
  major = m;
  GPA = g;
  advisor = a;
}

Student::Student(){
  ID = -1;
  name = "";
  year = "";
  major = "";
  GPA = -1;
  advisor = -1;
}

Student::~Student(){

}

bool Student::operator <(Student* s){
  return (ID<s->ID);
}

bool Student::operator >(Student* s){
  return (ID>s->ID);
}

bool Student::operator ==(Student* s){
  return (ID==s->ID);
}

bool Student::operator >=(Student* s){
  return (ID>=s->ID);
}

bool Student::operator <=(Student* s){
  return (ID<=s->ID);
}

string Student::toString(){
  ostringstream ret;
  ret<<fixed<<showpoint<<setprecision(3);
  ret<<ID<<"\n"<<name<<"\n"<<year<<"\n"<<major<<"\n"<<GPA<<"\n"<<advisor<<"\n";

  return ret.str();
}

string Student::toStringUser(){
  ostringstream ret;
  ret<<fixed<<showpoint<<setprecision(3);
  ret<<"ID: "<<ID<<"\nName: "<<name<<"\nYear: "<<year<<"\nMajor: "<<major<<"\nGPA: "<<GPA<<"\nAdvisor: "<<advisor<<"\n";

  return ret.str();
}

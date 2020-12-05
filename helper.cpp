//helper.cpp

#include <fstream>
#include <iostream>
#include "helper.h"

helper::helper(){

}

helper::~helper(){

}

bool helper::toFile(string s, string f){
  ofstream facultyTable;
  facultyTable.open("facultyTable.txt");
  facultyTable<<f;
  facultyTable.close();

  ofstream studentTable;
  studentTable.open("studentTable.txt");
  studentTable<<s;
  studentTable.close();

  return true;
}

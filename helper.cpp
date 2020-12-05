//helper.cpp
//Patrick Polcuch
//2348668
//CPSC350Assignment5

//I added this class in the hopes that moving a section of code from my main.cpp somewhere else whould fix the strange runtime error that I have been experienceing
#include <fstream>
#include <iostream>
#include "helper.h"
#include <cstdio>


helper::helper(){

}

helper::~helper(){

}

bool helper::toFile(string s, string f){
  remove("facultyTable.txt");
  remove("studentTable.txt");
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

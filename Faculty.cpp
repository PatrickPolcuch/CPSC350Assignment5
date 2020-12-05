//Faculty.cpp
//Patrick Polcuch
//2348668
//CPSC350Assignment5

//Allows for the creation of Faculty objects 

#include "Faculty.h"

Faculty::Faculty(int id, string n, string l, string d){
  ID = id;
  name = n;
  level = l;
  department = d;
  advisees[300] = { };
}

Faculty::Faculty(){
  ID = -1;
  name = "";
  level = "";
  department = "";
  advisees[300] = { };
}

Faculty::~Faculty(){

}

string Faculty::toString(){
  ostringstream ret;
  ret<<fixed<<showpoint<<setprecision(3);
  ret<<ID<<"\n"<<name<<"\n"<<level<<"\n"<<department<<"\n";

  for(int i = 0;i < 300; ++i){
    if(!(advisees[i]==0)){
      ret<<advisees[i]<<"\n";
    } else{
      break;
    }
  }

  ret<<"end"<<"\n";
  return ret.str();
}

string Faculty::toStringUser(){
  ostringstream ret;
  ret<<fixed<<showpoint<<setprecision(3);
  ret<<"ID: "<<ID<<"\nName: "<<name<<"\nLevel: "<<level<<"\nDepartment: "<<department<<"\nAdvisees:\n";

  for(int i = 0;i < 300; ++i){
    if(!(advisees[i]==0)){
      ret<<advisees[i]<<"\n";
    } else{
      break;
    }
  }

  ret<<"end"<<"\n";
  return ret.str();
}

bool Faculty::removeAdvissee(int idnum){
  int i;
  for(i = 0; i<300;++i){
    if(advisees[i] == idnum){
      break;
    } else if(advisees[i] == 0){
      return false;
    }
  }
  for(i;i<300;++i){
    if(advisees[i] == 0){
      break;
    }
    advisees[i] = advisees[i+1];
  }
  return true;
}

bool Faculty::addAdvisee(int adviseeID){
  for(int i = 0; i<300; ++i){
    if(advisees[i]==0){
      advisees[i]= adviseeID;
      return true;
    }
  }
  cout<<"This Faculty member is at maximum capasity(300), they cannot accept any more advisees. Please try a different advisor"<<endl;
  return false;
}

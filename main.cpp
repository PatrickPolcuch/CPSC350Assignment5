//to test my BST

#include "BST.h"
#include "Student.h"
#include "Faculty.h"
#include "helper.h"
#include <fstream>

int main(int argc,char** argv){
  BST <Student>*masterStudent = new BST<Student>();
  BST <Faculty>*masterFaculty = new BST<Faculty>();

  ifstream studentFile;
  studentFile.open("studentTable.txt");
  if(studentFile){//file was sucessfuly opened
    string curentLine;
    while(true){
      if(!getline(studentFile,curentLine)){
        break;
      }
      stringstream intID(curentLine);
      int id;
      intID>>id;

      if(!getline(studentFile,curentLine)){
        break;
      }
      string name = curentLine;

      if(!getline(studentFile,curentLine)){
        break;
      }
      string level =curentLine;

      if(!getline(studentFile,curentLine)){
        break;
      }
      string major =curentLine;

      if(!getline(studentFile,curentLine)){
        break;
      }
      stringstream doubleGPA(curentLine);
      double gpa;
      doubleGPA>>gpa;

      if(!getline(studentFile,curentLine)){
        break;
      }
      stringstream intAdvisor(curentLine);
      int advisor;
      intAdvisor>>advisor;

      Student *fromFile = new Student(id,name,level,major,gpa,advisor);
      masterStudent->insertNode(fromFile);
    }
  }
  studentFile.close();

  ifstream facultyFile;
  facultyFile.open("facultyTable.txt");
  if(facultyFile){//file was sucessfuly opened
    string curentLine;
    while(true){
      if(!getline(facultyFile,curentLine)){
        break;
      }
      stringstream intID(curentLine);
      int id;
      intID>>id;

      if(!getline(facultyFile,curentLine)){
        break;
      }
      string name = curentLine;

      if(!getline(facultyFile,curentLine)){
        break;
      }
      string level =curentLine;

      if(!getline(facultyFile,curentLine)){
        break;
      }
      string department =curentLine;

      Faculty *fromFile = new Faculty(id,name,level,department);

      int advisees[300] = { };
      for(int i = 0;i<300;++i){
        getline(facultyFile,curentLine);
        if(curentLine.compare("end") == 0){
          break;
        }
        stringstream intAdviseeID(curentLine);
        int adviseeid;
        intAdviseeID>>adviseeid;
        fromFile->addAdvisee(adviseeid);
      }

      masterFaculty->insertNode(fromFile);
    }
  }
  facultyFile.close();

  bool inWhile = true;
  while(inWhile){
    cout<<"Would you like to:\n1. Print all students and their information (sorted by ascending id #)\n2. Print all faculty and their information (sorted by ascending id #)\n3. Find and display student information given the students id\n4. Find and display faculty information given the faculty id\n5. Given a student’s id, print the name and info of their faculty advisor\n6. Given a faculty id, print ALL the names and info of his/her advisees.\n7. Add a new student\n8. Delete a student given theid\n9. Add a new faculty member\n10. Delete a faculty member given the id.\n11. Change a student’s advisor given the student id and the new faculty id.\n12. Remove an advisee from a faculty member given the ids\n13. Rollback\n14. Exit\n";

    string choice;
    cin>>choice;

    int s;
    stringstream intChoice(choice);
    intChoice>>s;

    switch(s){
      case 1://Print all students and their information (sorted by ascending id #)
        masterStudent->printTree();
        break;
      case 2://Print all faculty and their information (sorted by ascending id #)
        masterFaculty->printTree();
        break;
      case 3:{//Find and display student information given the students id
        cout<<"What is the student's ID number?"<<endl;
        string idnumS;
        cin>>idnumS;

        int idnum;
        stringstream intidnum(idnumS);
        intidnum>>idnum;
        if(!masterStudent->searchNode(idnum)){
          cout<<"Student not found"<<endl;
          break;
        }
        cout<<masterStudent->returnNode(idnum)->toStringUser();
      }
        break;
      case 4:{//Find and display faculty information given the faculty id
        cout<<"What is the faculty's ID number?"<<endl;
        string idnumS;
        cin>>idnumS;

        int idnum;
        stringstream intidnum(idnumS);
        intidnum>>idnum;
        if(!masterFaculty->searchNode(idnum)){
          cout<<"Faculty not found"<<endl;
          break;
        }
        cout<<masterFaculty->returnNode(idnum)->toStringUser();
      }
        break;
      case 5:{//Given a student’s id, print the name and info of their faculty advisor
        cout<<"What is the student's ID number?"<<endl;
        string idnumS;
        cin>>idnumS;

        int idnum;
        stringstream intidnum(idnumS);
        intidnum>>idnum;
        if(!masterStudent->searchNode(idnum)){
          cout<<"Student not found"<<endl;
          break;
        }
        if(!masterFaculty->searchNode(masterStudent->returnNode(idnum)->advisor)){
          cout<<"Faculty advisor not found"<<endl;
          break;
        }
        cout<<masterFaculty->returnNode(masterStudent->returnNode(idnum)->advisor)->toStringUser();
      }
        break;
      case 6:{//Given a faculty id, print ALL the names and info of his/her advisees.
        cout<<"What is the faculty's ID number?"<<endl;
        string idnumS;
        cin>>idnumS;

        int idnum;
        stringstream intidnum(idnumS);
        intidnum>>idnum;
        if(!masterFaculty->searchNode(idnum)){
          cout<<"Faculty not found"<<endl;
          break;
        }
        Faculty *current = masterFaculty->returnNode(idnum);
        if(current->advisees[0]==0){
          cout<<"Faculty has no advisees"<<endl;
        }
        for(int i = 0;i < 300; ++i){
          if(!(current->advisees[i]==0)){
            cout<<masterStudent->returnNode(current->advisees[i])->toStringUser()<<"\n";
          } else{
            break;
          }
        }
      }
        break;
      case 7:{//Add a new student
        bool quit = false;
        int idnum;
        while(true){
          cout<<"What is the student's ID number?"<<endl;
          string idnumS;
          cin>>idnumS;
          stringstream intidnum(idnumS);
          intidnum>>idnum;

          if(!masterStudent->searchNode(idnum)){
            break;
          }
          cout<<"This ID number is already taken, would you like to choose a different Id number?(Yes/No)"<<endl;
          string user ="";
          cin>>user;
          if(user.compare("No")==0){
            quit = true;
            break;
          }
        }
        if(quit){
          break;
        }

        cout<<"What is the student's name?"<<endl;
        string name;
        cin>>name;

        cout<<"What is the student's grade?"<<endl;
        string grade;
        cin>>grade;

        cout<<"what is the student's major?"<<endl;
        string major;
        cin>>major;

        cout<<"What is the student's GPA?"<<endl;
        string gpaS;
        cin>>gpaS;
        double gpa;
        stringstream doublegpa(gpaS);
        doublegpa>>gpa;

        int Aidnum;
        while(true){
          cout<<"What is the ID number of the student's advisor?"<<endl;
          string AidnumS;
          cin>>AidnumS;
          stringstream intAidnum(AidnumS);
          intAidnum>>Aidnum;

          if(masterFaculty->searchNode(Aidnum)){
            break;
          }
          cout<<"Faculty member does not exits, choose a valid ID number."<<endl;
        }


        Student *current = new Student(idnum, name, grade, major, gpa, Aidnum);
        masterStudent->insertNode(current);

        cout<<"Would you like to add the student to the faculty advisor's advisee list?(Yes/No)"<<endl;
        string user ="";
        cin>>user;
        if(user.compare("Yes")==0){
          Faculty *current = masterFaculty->returnNode(Aidnum);
          current->addAdvisee(idnum);
          cout<<"Done"<<endl;
        }
      }
        break;
      case 8:{//Delete a student given the id
        cout<<"What is the student's ID number?"<<endl;
        string idnumS;
        cin>>idnumS;

        int idnum;
        stringstream intidnum(idnumS);
        intidnum>>idnum;
        if(!masterStudent->searchNode(idnum)){
          cout<<"Student not found"<<endl;
          break;
        }
        Student *current = masterStudent->returnNode(idnum);

        masterFaculty->returnNode(current->advisor)->removeAdvissee(idnum);

      }
        break;
      case 9:{//Add a new faculty member
        bool quit = false;
        int idnum;
        while(true){
          cout<<"What is the faculty's ID number?"<<endl;
          string idnumS;
          cin>>idnumS;
          stringstream intidnum(idnumS);
          intidnum>>idnum;

          if(!masterFaculty->searchNode(idnum)){
            break;
          }
          cout<<"This ID number is already taken, would you like to choose a different Id number?(Yes/No)"<<endl;
          string user ="";
          cin>>user;
          if(user.compare("No")==0){
            quit = true;
            break;
          }
        }
        if(quit){
          break;
        }

        cout<<"What is the faculty's name?"<<endl;
        string name;
        cin>>name;

        cout<<"What is the faculty's level?"<<endl;
        string level;
        cin>>level;

        cout<<"what is the faculty's department?"<<endl;
        string department;
        cin>>department;

        Faculty *person = new Faculty(idnum, name, level, department);
        cout<<"check1"<<endl;
        person->addAdvisee(23);
        masterFaculty->insertNode(person);

      }
        break;
      case 10:{//Delete a faculty member given the id.
        cout<<"What is the faculty's ID number?"<<endl;
        string idnumS;
        cin>>idnumS;

        int idnum;
        stringstream intidnum(idnumS);
        intidnum>>idnum;
        if(!masterFaculty->searchNode(idnum)){
          cout<<"Faculty not found"<<endl;
          break;
        }

        masterFaculty->deleteNode(masterFaculty->returnNode(idnum));
      }
        break;
      case 11:{//Change a student’s advisor given the student id and the new faculty id
        cout<<"What is the student's ID number?"<<endl;
        string idnumS;
        cin>>idnumS;

        int idnum;
        stringstream intidnum(idnumS);
        intidnum>>idnum;
        if(!masterStudent->searchNode(idnum)){
          cout<<"Student not found"<<endl;
          break;
        }

        cout<<"What is the new faculty advisor's ID number?"<<endl;
        string AidnumS;
        cin>>AidnumS;

        int Aidnum;
        stringstream intAidnum(AidnumS);
        intAidnum>>Aidnum;
        if(!masterFaculty->searchNode(Aidnum)){
          cout<<"Faculty not found"<<endl;
          break;
        }

        masterFaculty->returnNode(masterStudent->returnNode(idnum)->advisor)->removeAdvissee(idnum);//remove student from old advisor's list
        masterFaculty->returnNode(Aidnum)->addAdvisee(idnum);//adds student to new advisor's list
        masterStudent->returnNode(idnum)->advisor = Aidnum;//changes student's advisor to new advisor
      }
        break;
      case 12:{//Remove an advisee from a faculty member given the ids
        cout<<"What is the new faculty advisor's ID number?"<<endl;
        string AidnumS;
        cin>>AidnumS;

        int Aidnum;
        stringstream intAidnum(AidnumS);
        intAidnum>>Aidnum;
        if(!masterFaculty->searchNode(Aidnum)){
          cout<<"Faculty not found"<<endl;
          break;
        }

        cout<<"What is the advisee's ID number?"<<endl;
        string idnumS;
        cin>>idnumS;

        int idnum;
        stringstream intidnum(idnumS);
        intidnum>>idnum;

        if(!masterFaculty->returnNode(Aidnum)->removeAdvissee(idnum)){
          cout<<"Student was not an advisee of the faculty."<<endl;
        }
      }
        break;
      case 13://Rollback
        cout<<"This function is not supported"<<endl;
        break;
      case 14://Exit
        inWhile = false;
        break;
      default:
        cout<<"Choice not recognized, please choose again"<<endl;
    }
  }



  string outputTofacultyTable = masterFaculty->printTreeRand();
  string outputTostudenTable = masterStudent->printTreeRand();

  helper::toFile(outputTostudenTable, outputTofacultyTable);



  delete masterStudent;
  delete masterFaculty;

  return 1;
}

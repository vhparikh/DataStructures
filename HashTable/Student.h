//Created by Vatsal Parikh
//Date: 11/17/20
//.h file for student class

//imports
#include <iostream>
#include <cstring>

using namespace std;

//start of header guard
#ifndef STUDENT_H
#define STUDENT_H

class Student {
public:
  char* getFirst(); //returns pointer to first name
  char* getLast(); //returns pointer to last name
  void setId(int newid); //sets id of the student
  int getId(); //gets the id
  void setGpa(float newgpa); //sets the gpa
  float getGpa(); //gets the gpa
private:
  char first[100]; //first name
  char last[100]; //last name 
  int id; //id 
  float gpa; //gpa
};

//end of header guard
#endif

//Created by Vatsal Parikh
//Date: 11/17/20
//.cpp file for student class comments are in .h file

#include <iostream>
#include <cstring>
#include "Student.h"

using namespace std;

char* Student::getFirst() {
  return first;
}

char* Student::getLast() {
  return last;
}

void Student::setId(int newid) {
  id = newid;
}

int Student::getId() {
  return id;
}

void Student::setGpa(float newgpa) {
  gpa = newgpa;
}

float Student::getGpa() {
  return gpa;
}

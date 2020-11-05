#include <iostream>
#include <cstring>

using namespace std;

#ifndef STUDENT_H
#define STUDENT_H

class Student {
public:
  char* getFirst();
  char* getLast();
  void setId(int newid);
  int getId();
  void setGpa(float newgpa);
  float getGpa();
private:
  char first[100];
  char last[100];
  int id;
  float gpa;
};

#endif

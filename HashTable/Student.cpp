#include <iostream>
#include <cstring>

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

//Created by Vatsal Parikh
//Date: 11/17/20
//.h file for node class

//imports
#include <istream>
#include <cstring>
#include "Student.h"

using namespace std;

//start of header guard
#ifndef NODE_H
#define NODE_H

class Node {
 public:
  Node(); //constructor if a student isn't given
  Node(Student* newstd); //constructor if a student is given
  Student* getStudent(); //returns pointer to student
  Node* getNext(); //returns pointer to the next node
  void setNext(Node* newnext); //sets the to pointer to the next node
  ~Node(); //destructor for the node
 private:
  Student* std; //student pointer
  Node* next; //next node pointer
};

//end of header guard
#endif

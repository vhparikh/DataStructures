#include <istream>
#include <cstring>
#include "Student.h"

using namespace std;

#ifndef NODE_H
#define NODE_H

class Node {
 public:
  Node();
  Node(Student* newstd);
  Student* getStudent();
  Node* getNext();
  void setNext(Node* newnext);
  ~Node();
 private:
  Student* std;
  Node* next;
};

#endif

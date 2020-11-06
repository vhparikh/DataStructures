#include <iostream>
#include <cstring>
#include "Node.h"

using namespace std;

Node::Node() {
  std = NULL;
  next = NULL;
}

Node::Node(Student* newstd) {
  std = newstd;
  next = NULL;
}

Student* Node::getStudent() {
  return std;
}

Node* Node::getNext() {
  return next;
}

void Node::setNext(Node* newnxt) {
  next = newnxt;
}

Node::~Node() {
  delete std;
  delete next;
}

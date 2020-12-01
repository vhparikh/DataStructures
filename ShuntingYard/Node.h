#include <iostream>
#include <cstring>

using namespace std;

#ifndef NODE_H
#define NODE_H

class Node {
 public:
  Node();
  Node* getLeft();
  Node* getRight();
  Node* getNext();
  void setLeft(Node* n);
  void setRight(Node* n);
  void setNext(Node* n);
  char* getCh();
  void setCh(char* c);
 private:
  Node* left;
  Node* right;
  Node* next;
  char* ch;
};

#endif

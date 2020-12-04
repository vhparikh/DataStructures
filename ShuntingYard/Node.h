#include <iostream>
#include <cstring>

using namespace std;

#ifndef NODE_H
#define NODE_H

class Node {
 public:
  Node();
  ~Node();
  Node* getLeft();
  Node* getRight();
  Node* getNext();
  void setLeft(Node* n);
  void setRight(Node* n);
  void setNext(Node* n);
  char getCh();
  void setCh(char c);
  int getPrecedence();
  void setPrecedence(int p);
  int getAssociate();
  void setAssociate(int a);
 private:
  Node* left;
  Node* right;
  Node* next;
  char ch;
  int precedence;
  int associate; //1 is left and 2 is right (0 is for operands)
};

#endif

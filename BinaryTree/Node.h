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
  void setLeft(Node* l);
  void setRight(Node* r);
  int getNum();
  void setNum(int n);
 private:
  Node* left;
  Node* right;
  int num;
};

#endif

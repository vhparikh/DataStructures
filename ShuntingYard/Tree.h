#include <iostream>
#include <cstring>
#include "List.h"
#include "Node.h"

using namespace std;

#ifndef TREE_H
#define TREE_H

class Tree {
 public:
  Tree(char* e);
  Node* build();
  void infix(Node* n);
  void postfix(Node* n);
  void prefix(Node* n);
 private:
  char* expression;
  List* stack;
};

#endif

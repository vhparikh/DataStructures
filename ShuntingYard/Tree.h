//Created by Vatsal Parikh
//Date: 12/1/20
//.h file for tree class

//imports
#include <iostream>
#include <cstring>
#include "List.h"
#include "Node.h"

using namespace std;

//start of header guard
#ifndef TREE_H
#define TREE_H

class Tree {
 public:
  Tree(Node* q); //constructor
  Node* build(); //builds tree
  void infix(Node* n); //traverses tree to get infix form
  void postfix(Node* n); //traveres tree to get postfix form
  void prefix(Node* n); //traverses tree to get prefix form
 private:
  Node* qh; //stores postfix expression needed to create tree
  List* stack; //list pointer to build tree
};

//end of header guard
#endif

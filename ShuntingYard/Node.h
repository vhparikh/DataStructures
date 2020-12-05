//Created by Vatasl Parikh
//Date: 12/1/20
//.h file for node class

//imports
#include <iostream>
#include <cstring>

using namespace std;

//start of header guard
#ifndef NODE_H
#define NODE_H

class Node {
 public:
  Node(); //constructor
  ~Node(); //destructor
  Node* getLeft(); //returns left node
  Node* getRight(); //returns right node
  Node* getNext(); //returns next node
  void setLeft(Node* n); //sets left node
  void setRight(Node* n); //sets right node
  void setNext(Node* n); //sets next node
  char getCh(); //returns char value stored in node
  void setCh(char c); //sets char value stored in node
  int getPrecedence(); //returns precedence value
  void setPrecedence(int p); //gets precedence value
  int getAssociate(); //returns associative value
  void setAssociate(int a); //sets associative value
 private:
  Node* left; //node pointer to left node (for tree)
  Node* right; //node pointer to right node (for tree)
  Node* next; //node pointer to next node (for stacks and queues)
  char ch; //char value for node
  int precedence; //precendence value of node
  int associate; //1 is left and 2 is right (0 is for operands)
};

//end of header guard
#endif

//Created by Vatsal Parikh
//Date: 12/9/20
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
  Node* getLeft(); //returns node pointer to left
  Node* getRight(); //returns node pointer to right
  void setLeft(Node* l); //set pointer to left
  void setRight(Node* r); //set pointer to right
  int getNum(); //returns number stored in node
  void setNum(int n); //set the number stored in node
private:
  Node* left; //node pointer to left node
  Node* right; //node pointer to right node
  int num; //value of number in node
};

//end of header guard
#endif

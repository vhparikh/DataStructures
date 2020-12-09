//Created by Vatsal Parikh
//Date: 12/9/20
//.cpp file for node class all comments are in .h file

//imports
#include "Node.h"

Node::Node() {
  left = NULL;
  right = NULL;
  num = 0;
}

Node* Node::getLeft() {
  return left;
}

Node* Node::getRight() {
  return right;
}

void Node::setLeft(Node* l) {
  left = l;
}

void Node::setRight(Node* r) {
  right = r;
}

int Node::getNum() {
  return num;
}

void Node::setNum(int n) {
  num = n;
}

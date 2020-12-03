#include "Node.h"

Node::Node() {
  left = NULL;
  right = NULL;
  next = NULL;
  ch = new char();
}

Node* Node::getLeft() {
  return left;
}

Node* Node::getRight() {
  return right;
}

Node* Node::getNext() {
  return next;
}

void Node::setLeft(Node* n) {
  left = n;
}

void Node::setRight(Node* n) {
  right = n;
}

void Node::setNext(Node* n) {
  next = n;
}

char* Node::getCh() {
  return ch;
}

void Node::setCh(char* c) {
  ch = c;
}

int Node::getPrecedence() {
  return precedence;
}

void Node::setPrecedence(int p) {
  precedence = p;
}

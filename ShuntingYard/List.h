#include <iostream>
#include <cstring>
#include "Node.h"

using namespace std;

#ifndef LIST_H
#define LIST_H

class List {
 public:
  List();
  Node* peek();
  Node* pop();
  void push(Node* n);
  void dequeue();
  void enqueue(Node* n);
 private:
  Node* stackHead;
  Node* queueHead;
};

#endif

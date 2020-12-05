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
  void push(Node* n, bool tree);
  void dequeue();
  void enqueue(Node* n);
  char* print();
 private:
  Node* stackHead;
  Node* queueHead;
};

#endif

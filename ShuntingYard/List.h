//Created by Vatsal Parikh
//Date: 12/1/20
//.h file for list class

//imports
#include <iostream>
#include <cstring>
#include "Node.h"

using namespace std;

//start of header guard
#ifndef LIST_H
#define LIST_H

class List {
 public:
  List(); //constructor
  Node* peek(); //return top node in stack
  Node* pop(); //pops top node in stack and returns it
  void push(Node* n, bool tree); //pushes node into stack
  void dequeue(); //removes top node in queue
  void enqueue(Node* n); //adds nodes to end of queue
  void print(); //prints out postfix and returns it by char*
  Node* getQueue();
 private:
  Node* stackHead; //head of stack
  Node* queueHead; //head of queue
};

//end of header guard
#endif

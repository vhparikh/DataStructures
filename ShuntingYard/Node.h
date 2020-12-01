#include <iostream>
#include <cstring>

using namespace std;

#ifndef NODE_H
#define NODE_H

class Node {
 public:
  Node();
    
 private:
  Node* left;
  Node* right;
  Node* next;
};

#endif

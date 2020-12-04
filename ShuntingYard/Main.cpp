#include <iostream>
#include <cstring>
#include "List.h"
#include "Node.h"

using namespace std;

int main() {
  cout << "enter an equation in infix form without spaces" << endl;
  List* list = new List();
  char* input = new char[80];
  cin.get(input, 80);
  cin.get();

  for (int i = 0; i < 3; i++) {
    char* val;
    val = &input[i];
    if (strcmp(val, "+") == 0 || strcmp(val, "-") == 0 ||
	strcmp(val, "*") == 0 || strcmp(val, "/") == 0 ||
	strcmp(val, "^") == 0 || strcmp(val, "(") == 0 ||
	strcmp(val, ")") == 0) {
      Node* n = new Node();
      n->setCh(val);
      list->push(n);
      cout << "pushed" << endl;
    }
    else {
      Node* n = new Node();
      n->setCh(val);
      list->enqueue(n);
      cout << "done" << endl;
    }
  }
  cout << "got out" << endl;
  list->print();
  
}

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

  for (int i = 0; i < strlen(input); i++) {
    char val;
    val = input[i];
    //cout << "broke here" << endl;
    if (val == '+' || val == '-' || val == '*' || val == '/' ||
	val == '^' || val == '(' || val == ')') {
      cout << "in" << endl;
      Node* n = new Node();
      cout << "a" << endl;
      n->setCh(val);
      cout << "b" << endl;
      list->push(n);
      cout << "c" << endl;
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

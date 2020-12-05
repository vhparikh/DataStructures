#include <iostream>
#include <cstring>
#include "List.h"
#include "Node.h"
#include "Tree.h"

using namespace std;

int main() {
  cout << "enter an equation in infix form without spaces" << endl;
  List* list = new List();
  char* input = new char[80];
  char* post = new char[80];
  cin.get(input, 80);
  cin.get();

  for (int i = 0; i < strlen(input); i++) {
    char val;
    val = input[i];
    if (val == '+' || val == '-' || val == '*' || val == '/' ||
	val == '^' || val == '(' || val == ')') {
      Node* n = new Node();
      n->setCh(val);
      list->push(n, false);
    }
    else {
      Node* n = new Node();
      n->setCh(val);
      list->enqueue(n);
    }
  }
  post = list->print();
    
  Tree* tree = new Tree(post);
  Node* t = tree->build();

  cout << "Would you like to convert to infix, postfix or prefix?" << endl;
  cin.get(input, 80);
  cin.get();

  if (strcmp(input, "infix") == 0) {
    cout << "Here is infix form" << endl;
    tree->infix(t);
    cout << endl;
  }
  else if (strcmp(input, "postfix") == 0) {
    cout << "Here is postfix form" << endl;
    tree->postfix(t);
    cout << endl;
  }
  else if (strcmp(input, "prefix") == 0) {
    cout << "Here is prefix form" << endl;
    tree->prefix(t);
    cout << endl;
  }
}

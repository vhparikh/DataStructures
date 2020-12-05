//Created by Vatsal Parikh
//Date: 12/1/20
//Uses Shunting yard algorithm to convert infix to postfix
//Creates binary expression tree with postfix
//Can print in infix, prefix or postfix using tree

//imports
#include <iostream>
#include <cstring>
#include "List.h"
#include "Node.h"
#include "Tree.h"

using namespace std;

int main() {

  //prompt user for an infix equation
  cout << "enter an equation in infix form without spaces" << endl;
  List* list = new List();
  char* input = new char[80];
  char* post = new char[80];
  cin.get(input, 80);
  cin.get();

  //goes through input and either pushes to stack or enqueues
  for (int i = 0; i < strlen(input); i++) {
    char val;
    val = input[i];

    //if and operator push
    if (val == '+' || val == '-' || val == '*' || val == '/' ||
	val == '^' || val == '(' || val == ')') {
      Node* n = new Node();
      n->setCh(val);
      list->push(n, false);
    }

    //else enqueue
    else {
      Node* n = new Node();
      n->setCh(val);
      list->enqueue(n);
    }
  }

  //print postfix
  post = list->print();

  //build the tree with postfix form
  Tree* tree = new Tree(post);
  Node* t = tree->build();

  //ask if user wants infix, postfix or prefix
  cout << "Would you like to convert to infix, postfix or prefix?" << endl;
  cin.get(input, 80);
  cin.get();

  //if user wants infix call infix
  if (strcmp(input, "infix") == 0) {
    cout << "Here is infix form" << endl;
    tree->infix(t);
    cout << endl;
  }

  //else if user wants postfix call postfix
  else if (strcmp(input, "postfix") == 0) {
    cout << "Here is postfix form" << endl;
    tree->postfix(t);
    cout << endl;
  }

  //else if user wants prefix call prefix
  else if (strcmp(input, "prefix") == 0) {
    cout << "Here is prefix form" << endl;
    tree->prefix(t);
    cout << endl;
  }
}

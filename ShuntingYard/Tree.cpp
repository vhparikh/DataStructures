//Created by Vatsal Parikh
//Date: 12/1/20
//.cpp file for tree class

//imports
#include "Tree.h"

//constructor requires a char*
Tree::Tree(char* e) {
  
  //set expression to e and create new list
  expression = e;
  stack = new List();
}

//builds tree
Node* Tree::build() {

  //loop through the postfix expression
  for (int i = 0; i < strlen(expression); i++) {

    //stores the one char we are looking at
    char val;
    val = expression[i];

    //if it is and operator create new node and pop twice from stack to create a left and right child and then push it back into the stack
    if (val == '+' || val == '-' || val == '*' ||
	val == '/' || val == '^') {
      Node* n = new Node();
      n->setCh(val);
      n->setRight(stack->pop());
      n->setLeft(stack->pop());
      stack->push(n, true);
    }

    //else create a new node and just push it onto the stack
    else {
      Node* n = new Node();
      n->setCh(val);
      stack->push(n, true);
    }
  }

  //return top node of stack
  return stack->peek();
}

//traverses tree to create infix form starts with top node
void Tree::infix(Node* n) {

  //if the node isn't null
  if (n != NULL) {

    //if the node is an operator add a (
    if (n->getCh() == '+' || n->getCh() == '-' || n->getCh() == '*' ||
	n->getCh() == '/' || n->getCh() == '^') {
      cout << "(";
    }

    //call infix on the nodes left subtree
    infix(n->getLeft());

    //print out the value in the node
    cout << n->getCh();

    //call infix on the nodes right subtree
    infix(n->getRight());

    //if the node is an operator add a )
    if (n->getCh() == '+' || n->getCh() == '-' || n->getCh() == '*' ||                                                              
	n->getCh() == '/' || n->getCh() == '^') {
      cout << ")";
    }
  }
}

//traverses tree to create postfix form starts with top node
void Tree::postfix(Node* n) {

  //if the node isn't null
  if (n != NULL) {

    //call postfix on the left subtree
    postfix(n->getLeft());

    //call postfix on the right subtree
    postfix(n->getRight());

    //print out the value in the node
    cout << n->getCh();
  }
}

//traverses tree to create prefix form starts with top node
void Tree::prefix(Node* n) {

  //if the node isn't null
  if (n != NULL) {

    //print out value of node
    cout << n->getCh();

    //call prefix on the left subtree
    prefix(n->getLeft());

    //call prefix on the right subree
    prefix(n->getRight());
  }
}

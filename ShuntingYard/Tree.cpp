#include "Tree.h"

Tree::Tree(char* e) {
  expression = e;
  stack = new List();
}

Node* Tree::build() {
  for (int i = 0; i < strlen(expression); i++) {
    char val;
    val = expression[i];

    if (val == '+' || val == '-' || val == '*' ||
	val == '/' || val == '^') {
      Node* n = new Node();
      n->setCh(val);
      n->setRight(stack->pop());
      n->setLeft(stack->pop());
      stack->push(n, true);
    }
    else {
      Node* n = new Node();
      n->setCh(val);
      stack->push(n, true);
    }
  }
  return stack->peek();
}

void Tree::infix(Node* n) {
  if (n != NULL) {
    if (n->getCh() == '+' || n->getCh() == '-' || n->getCh() == '*' ||
	n->getCh() == '/' || n->getCh() == '^') {
      cout << "(";
    }
  
    infix(n->getLeft());
    cout << n->getCh();
    infix(n->getRight());
    
    if (n->getCh() == '+' || n->getCh() == '-' || n->getCh() == '*' ||                                                              
	n->getCh() == '/' || n->getCh() == '^') {
      cout << ")";
    }
  }
}

void Tree::postfix(Node* n) {
  if (n != NULL) {
    postfix(n->getLeft());
    postfix(n->getRight());
    cout << n->getCh();
  }
}

void Tree::prefix(Node* n) {
  if (n != NULL) {
    cout << n->getCh();
    prefix(n->getLeft());
    prefix(n->getRight());
  }
}

#include "List.h"

List::List() {
  stackHead = NULL;
  queueHead = NULL;
}

Node* List::peek() {
  return stackHead;
}

Node* List::pop() {
  if (stackHead == NULL) {
    return NULL;
  }
  Node* temp = stackHead;
  stackHead = stackHead->getNext();
  temp->setNext(NULL);
  return temp;
}

void List::push(Node* n, bool tree) {

  if (n->getCh() == '+' || n->getCh() == '-') {
    n->setPrecedence(2);
    n->setAssociate(1);
  }
  else if (n->getCh() == '*' || n->getCh() == '/') {
    n->setPrecedence(3);
    n->setAssociate(1);
  }
  else if (n->getCh() == '^') {
    n->setPrecedence(4);
    n->setAssociate(2);
  }

  if (n->getCh() == ')') {
    while (stackHead->getCh() != '(' && stackHead != NULL) {
      enqueue(pop());
    }

    if (stackHead->getCh() == '(') {
      Node* temp = pop();
      temp->~Node();
      n->~Node();
    }
    else {
      cout << "there is a parenthesis mix up" << endl;
      return;
    }
    
    return;
  }

  while ((stackHead != NULL) && ((stackHead->getPrecedence() > n->getPrecedence()) ||
				 (stackHead->getPrecedence() == n->getPrecedence() && n->getAssociate() == 1)) &&
	 (stackHead->getCh() != '(') && (tree == false)) {
    enqueue(pop());
  }
  n->setNext(stackHead);
  stackHead = n;
}

void List::dequeue() {
  if (queueHead == NULL) {
    return;
  }

  Node* temp = queueHead->getNext();
  queueHead->~Node();
  queueHead = temp;

}

void List::enqueue(Node* n) {

  if (queueHead == NULL) {
    queueHead = n;
    return;
  }

  Node* current = queueHead;
  while(current->getNext() != NULL) {
    current = current->getNext();
  }
  current->setNext(n);
}

char* List::print() {
  Node* current = queueHead;
  char* post = new char[80];
  int counter = 0;
  
  while (current != NULL) {
    cout << current->getCh();
    post[counter] = current->getCh();
    counter++;
    current = current->getNext();
  }

  while (stackHead != NULL) {
    char ch = pop()->getCh();
    cout << ch;
    post[counter] = ch;
    counter++;
  }
  
  cout << endl;
  return post;
}
